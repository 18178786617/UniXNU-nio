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
	i64 ms = 0, mbs = 0, flips = 0;
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

	/* Stage 1: one small rectangle, then straight on. The one-second pose it
	 * used to strike for the camera is gone: R74-R75's interesting output is
	 * the timing block at the end, and the camera has eleven seconds of
	 * parking text to read instead. */
	fb_push(cmds, &n, 0x0080FF80u, 0, 0, 200, 200);
	fb_flush(cmds, &n);
	nio_puts("nio: stage1 ok\n");

	/* Stage 2: the gradient. */
	for (i = 0; i < 48; i++) {
		u32 r = 4 + (i * 8) / 48;
		u32 g = 8 + (i * 24) / 48;
		u32 bl = 64 - (i * 52) / 48;

		fb_push(cmds, &n, (r << 16) | (g << 8) | bl,
		        0, (u32)((u64)i * sh / 48), sw, sh / 48 + 1);
	}
	fb_flush(cmds, &n);
	nio_puts("nio: stage2 gradient ok\n");

	/* Stage 3: colour bars. */
	y0 = sh * 20 / 100;
	bh = sh * 28 / 100;
	bw = sw / 8;
	for (i = 0; i < 8; i++) {
		static const u32 bars[8] = {
			0x00FFFFFFu, 0x00FFFF00u, 0x0000FFFFu, 0x0000FF00u,
			0x00FF00FFu, 0x00FF0000u, 0x000000FFu, 0x00000000u
		};

		fb_push(cmds, &n, bars[i], i * bw, y0, bw, bh);
	}
	fb_flush(cmds, &n);
	nio_puts("nio: stage3 bars ok\n");

	/* Stage 4: the frame. R72 died here, on the full-height side bars. */
	fb_push(cmds, &n, 0x00FFFFFFu, 0, 0, sw, 4);            /* frame */
	fb_push(cmds, &n, 0x00FFFFFFu, 0, sh - 6, sw, 6);
	fb_push(cmds, &n, 0x00FFFFFFu, 0, 0, 4, sh);
	fb_push(cmds, &n, 0x00FFFFFFu, sw - 4, 0, 4, sh);
	fb_flush(cmds, &n);

	/* ---- repeat rate: the number a UI actually lives on ------------------
	 * One fill is a data point; a UI redraws twenty times a second. Twenty
	 * alternating full-screen fills timed as one block give ms per frame
	 * with no timer inside the loop, and the two colours make the flicker
	 * visible on camera so the count cannot silently stop early. */
	{
		i64 t0[2], t1[2];
		u32 k;

		t0[0] = 0; t0[1] = 0; t1[0] = 0; t1[1] = 0;
		for (k = 0; k < 20; k++) {
			if (k == 0) {
				sys6(SYS_gettimeofday, (i64)t0, 0, 0, 0, 0, 0);
			}
			fb_push(cmds, &n, (k & 1) ? 0x00103060u : 0x00101028u,
			        0, 0, sw, sh);
			fb_flush(cmds, &n);
		}
		sys6(SYS_gettimeofday, (i64)t1, 0, 0, 0, 0, 0);
		flips = (t1[0] - t0[0]) * 1000 + (t1[1] - t0[1]) / 1000;
	}

	nio_puts("nio: stage4 frame ok, screen is ours\n");
	/* Every line printed before this one has been painted over, so the timing
	 * has to be reported last or it is lost. */
	nio_puts("nio: fullfill ");
	nio_dec(ms);
	nio_puts(" ms, ");
	nio_dec(mbs);
	nio_puts(" MB/s\n");
	nio_puts("nio: 20fill ");
	nio_dec(flips);
	nio_puts(" ms, ");
	nio_dec(flips * 1000 / 20);
	nio_puts(" us/frame\n");
	nio_puts("nio: R75 full-height fill ok, parking\n");

park:
	for (;;) {
		__asm__ volatile ("wfe");
	}
}
