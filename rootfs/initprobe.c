/*
 * initprobe.c -- /sbin/launchd fixture for the nio XNU port.
 *
 * The ladder so far: R61 proved userspace is real (a hand-encoded exit(42)
 * trapped through sleh_synchronous -> unix_syscall), R62 turned the exit status
 * into a bitmask because a panic was the only visible channel, R63-R65 added
 * fork/execve/wait4, R66 gave the kernel a boot console, R67 pointed
 * sysent[SYS_write] at it, and R68 split the screen so kprintf and this process
 * cannot bury each other.
 *
 * R69-R71 chased an argv that looked empty. R71 settled it: the kernel was
 * writing the initial stack correctly all along (copyout err=0, argc=1,
 * argv[0] pointing at the string) and this file was reading `sp` after its own
 * prologue, so it was inspecting unused zeroed stack below the arguments. The
 * entry is naked now -- `mov x0, sp; b nio_main` -- so what it reports is the
 * sp the kernel really set.
 *
 * R72 adds the two interfaces a real init needs next: a Mach trap (proof that
 * mach_trap_table is reachable by number, not just BSD syscalls) and the screen
 * as fd 3, so a process in EL0 can paint pixels instead of only text.
 *
 * R73 answered R72's panic: the panel is 1080x2520 and vc_info was right all
 * along -- R72's last stage ran off the bottom of the frame on its own. R74
 * dropped the fixture's 2400-row ceiling, drew the whole panel and timed one
 * fill: 206 ms, 51 MB/s. R75 times twenty fills in a row, because a UI lives
 * on the repeat rate, not on a single shot.
 *
 * Constraints imposed by the Mach-O wrapper:
 *   - __TEXT is R+X only, no writable segment, so NO writable globals: every
 *     buffer lives on the stack (the kernel sets sp via thread_setuserstack()).
 *     `const` tables are fine: they land in the same read-only segment.
 *   - freestanding, no libc, no TLS, no stack protector, no SIMD.
 */

#include "uio.h"

#define BATCH 8                         /* rects per write(3): 192 bytes */

static __attribute__((noinline)) void fb_flush(u32 *c, int *n)
{
	if (*n > 0) {
		nio_fb_send(c, (unsigned)(*n * 24));
		*n = 0;
	}
}

static __attribute__((noinline)) void fb_push(u32 *c, int *n, u32 colour,
                                              u32 x, u32 y, u32 w, u32 h)
{
	nio_fb_rect(c + *n * 6, colour, x, y, w, h);
	if (++(*n) == BATCH) {
		fb_flush(c, n);
	}
}

/* _start must be the first thing in the image: the Mach-O entry point is
 * __TEXT+0x1d0 and it is baked into LC_UNIXTHREAD. Naked matters here -- a C
 * prologue moves sp before the first statement runs, and then this file would
 * report its own frame instead of the kernel-set stack pointer (R71). */
__attribute__((section(".text.start"), naked, noreturn))
void _start(void)
{
	__asm__ volatile ("mov x0, sp\n\tb nio_main");
}

__attribute__((used, noreturn)) void nio_main(u64 entry_sp);

__attribute__((used, noreturn)) void nio_main(u64 entry_sp)
{
	/* volatile: without it clang merges small compares into `ldur d0` SIMD
	 * loads, and this fixture should not depend on FP/SIMD being live for
	 * the first EL0 process. */
	volatile char b[32];
	u32 cmds[BATCH * 6];
	int n = 0;
	u32 sw, sh, i, y0, bh, bw;
	i64 fd, child, got, is_child, pid, uid, self_port, dim;
	i64 ms = 0, mbs = 0;
	long st;

	nio_puts("nio: launchd fixture, write(1) -> console\n");

	pid = sys6(SYS_getpid, 0, 0, 0, 0, 0, 0);
	uid = sys6(SYS_getuid, 0, 0, 0, 0, 0, 0);
	nio_puts("nio: pid=");
	nio_dec(pid);
	nio_puts(" uid=");
	nio_dec(uid);
	nio_puts("\n");
	nio_kh("nio: sp=0x", entry_sp);

	fd = sys6(SYS_open, (i64)"/", 0, 0, 0, 0, 0);
	nio_puts("nio: open(/)=fd ");
	nio_dec(fd);

	fd = sys6(SYS_open, (i64)"/sbin/launchd", 0, 0, 0, 0, 0);
	if (fd >= 0 && sys6(SYS_read, fd, (i64)b, 4, 0, 0, 0) == 4) {
		unsigned m = (unsigned char)b[0] |
		             ((unsigned char)b[1] << 8) |
		             ((unsigned char)b[2] << 16) |
		             ((unsigned)b[3] << 24);
		nio_puts(" magic=0x");
		nio_hex(m);
		nio_puts("\n");
	} else {
		nio_puts(" cannot read /sbin/launchd\n");
	}

	/* A pid is not a valid mmap result, so the return value is an address;
	 * printing it also exercises the 64-bit formatter. */
	got = sys6(SYS_mmap, 0, 4096, NIO_PROT_RW, NIO_MAP_ANON, -1, 0);
	if (got > 0) {
		nio_kh("nio: mmap 4K at 0x", (u64)got);
	} else {
		nio_kv("nio: mmap failed ", got);
	}

	/* ---- fork: the child execs /probe.bin (stage2.c) ---- */
	child = sys_fork(&is_child);
	if (child < 0) {
		nio_kv("nio: fork failed ", child);
		goto park;
	}
	/* x1 == 1 is the kernel's child marker; getpid() == child is the second
	 * opinion in case the parent ever sees x1 set too. */
	if (is_child == 1 && sys6(SYS_getpid, 0, 0, 0, 0, 0, 0) == child) {
		char *argv[2];
		char *envp[1];

		argv[0] = (char *)"/probe.bin";
		argv[1] = 0;
		envp[0] = 0;
		got = sys6(SYS_execve, (i64)argv[0], (i64)argv, (i64)envp, 0, 0, 0);
		/* execve only returns on failure, with -errno */
		nio_kv("child: execve failed ", -got);
		sys6(SYS_exit, 1, 0, 0, 0, 0, 0);
		goto park;              /* unreachable: exit does not return */
	}

	nio_kv("nio: fork -> ", child);
	st = 0;
	got = sys6(SYS_wait4, child, (i64)&st, 0, 0, 0, 0);
	if (got != child) {
		nio_kv("nio: wait4 failed ", got);
		goto park;
	}
	if (((unsigned)st & 0x7f) != 0) {
		nio_kv("nio: child killed by signal ", (i64)((unsigned)st & 0x7f));
		goto park;
	}

	/* ---- Mach traps: task_self_trap -------------------------------------
	 * Every call so far went through unix_syscall(). A real init needs the
	 * other half of the trap table too (mach_msg, ports); this is the cheapest
	 * one to prove: it takes no arguments and hands back a port name. */
	self_port = nio_mach0(28);
	nio_puts("nio: mach task_self=0x");
	nio_hex((u64)self_port);
	nio_puts("\n");

	/* ---- the screen, as a file -----------------------------------------
	 * write(3, 0, 0) returns width<<32 | height, so userspace learns the panel
	 * size instead of assuming one. R72 faulted below the panel with this same
	 * call, R73 proved the numbers were never wrong: 1080x2520, rowbytes 4320.
	 * Both the raw word and the split numbers go on screen before anything is
	 * drawn, because later stages paint over them. */
	dim = nio_fb_size();
	nio_kh("nio: dim=0x", (u64)dim);
	sw = (u32)((u64)dim >> 32);
	sh = (u32)((u64)dim & 0xffffffffu);
	nio_puts("nio: fb ");
	nio_dec((i64)sw);
	nio_puts("x");
	nio_dec((i64)sh);
	nio_puts("\n");
	if (sw < 64 || sw > 8192 || sh < 64) {
		nio_kv("nio: fb unusable ", dim);
		goto park;
	}
	/* Give the camera time to record the numbers before pixels cover them. */
	for (volatile i64 spin = 0; spin < 300000000; spin++) {
		__asm__ volatile ("yield");
	}

	/* ---- how fast does this kernel paint? -------------------------------
	 * R73 stopped at 2400 rows because R72 had faulted and the geometry was
	 * still unproven. It is proven now, so this fills the whole panel: fb_exec
	 * clips every rectangle to h-2 on its own (the console keeps both cursors
	 * in the last row), so a wrong sh can no longer run off the mapping.
	 * The timing matters more than the pixels -- 10.9 MB per frame with no
	 * GPU says whether anything like a UI fits in a frame budget. */
	{
		i64 t0[2], t1[2];
		i64 px;

		t0[0] = 0; t0[1] = 0; t1[0] = 0; t1[1] = 0;
		sys6(SYS_gettimeofday, (i64)t0, 0, 0, 0, 0, 0);
		fb_push(cmds, &n, 0x00103060u, 0, 0, sw, sh);
		fb_flush(cmds, &n);
		sys6(SYS_gettimeofday, (i64)t1, 0, 0, 0, 0, 0);
		ms = (t1[0] - t0[0]) * 1000 + (t1[1] - t0[1]) / 1000;
		px = (i64)sw * (i64)sh;
		mbs = ms > 0 ? (px * 4) / ms / 1024 : 0;
	}

	/* The gradient, the colour bars and the frame were R73-R75's evidence
	 * that the panel is ours; R76 and R77 are about the touch chip, and
	 * their budget is spent on the probe. One dark fill keeps the screen
	 * alive without the code. */
	fb_push(cmds, &n, 0x00103060u, 0, 0, sw, sh);
	fb_flush(cmds, &n);
	nio_puts("nio: screen ok\n");

	/* ---- repeat rate was R75's question, answered: 4122 ms / 20 fills =
	 * 206.1 ms per frame, identical to the single shot. The loop is gone;
	 * its budget funds the touch probe below. */

	/* Every line printed before this one has been painted over, so the timing
	 * has to be reported last or it is lost. */
	nio_puts("nio: fullfill ");
	nio_dec(ms);
	nio_puts(" ms, ");
	nio_dec(mbs);
	nio_puts(" MB/s\n");
	/* ---- first device contact: read(4) = the Novatek touch bridge -----
	 * The kernel blob now drives the chip by bit-banging SPI over four
	 * GPIOs -- the same transport payload proved reads the true trim id
	 * from, where the GENI engine path (R76) mis-framed its short reads.
	 * The kernel copies back {magic "NVT2", trim[6], trim again[6], miso
	 * idle, irq, err(2), stage}; the trim id lives at 0x3F004 and the
	 * NT36672C signature is {0x0C, ??, ??, 0x72, 0x66, 0x03} -- bytes 1
	 * and 2 are don't-care, so the check masks them out.
	 *
	 * Printed after the draws, but BEFORE anything can hang: if the GPIO
	 * writes never take effect the last line on screen has to say that is
	 * where we are. */
	{
		unsigned char rec[32];
		i64 got = sys6(SYS_read, 4, (i64)rec, 32, 0, 0, 0);

		nio_puts("nio: touch rd=");
		nio_dec(got);
		/* Gate on the magic, not on the byte count. The kernel returns a
		 * 64-bit ssize_t, so the count is only meaningful if the copyout
		 * happened; rec[0..3] is set by the kernel itself and is a far
		 * sounder witness that the bridge answered. */
		if (rec[0] == 'N' && rec[1] == 'V' && rec[2] == 'T' && rec[3] == '2') {
			u32 k;
			int match;

			nio_puts(" id=");
			for (k = 4; k < 10; k++) {
				nio_hex((u64)rec[k]);
				nio_puts(" ");
			}
			/* The vendor check itself, so the screen says MATCH rather
			 * than making the reader do the mask arithmetic. */
			match = (rec[4] == 0x0c && rec[7] == 0x72 &&
			         rec[8] == 0x66 && rec[9] == 0x03);
			nio_puts(match ? "MATCH" : "no");
			nio_puts(" id2=");
			for (k = 10; k < 16; k++) {
				nio_hex((u64)rec[k]);
				nio_puts(" ");
			}
			nio_puts("miso=");
			nio_dec(rec[16]);
			nio_puts(" irq=");
			nio_dec(rec[17]);
			nio_puts(" err=");
			nio_hex((u64)rec[18] | (u64)rec[19] << 8);
			nio_puts(" st=");
			nio_dec(rec[20]);
		}
		nio_puts("\n");
	}
	nio_puts("nio: R77 touch bitbang probe ok, parking\n");

park:
	for (;;) {
		__asm__ volatile ("wfe");
	}
}
