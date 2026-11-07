/*
 * el0probe.c -- the smallest fixture that can answer "did userland run?"
 *
 * R152. The 16.5 kernel's boot console blob (scripts/console/xnu-panic-screen.c)
 * splits the panel: zone0 is the top 55% and carries kprintf (the kernel's own
 * log), zone1 is the bottom 45% and carries write(2) from an EL0 process,
 * because install-console-blob.py re-points sysent[4].sy_call at console_write.
 *
 * So a fixture that only writes to fd 1 is a two-answer instrument: if the
 * kernel never reaches mockfs_mountroot and never execs /sbin/launchd, zone1
 * stays empty and zone0 keeps the last kernel line. If it does, zone1 lights
 * up with the lines below while zone0 still shows the kernel log underneath
 * its own cursor. Neither region is cleared by this fixture, unlike
 * initprobe.c, which paints the whole panel 0x00103060 as its first act and
 * therefore destroys the kernel log that a diagnosis needs.
 *
 * What each line proves:
 *
 *   EL0 ALIVE R152   exec of the N4KROOT launch Mach-O completed and the
 *                    sysent[4] hook delivers EL0 output to the panel
 *   sp=              the kernel set a user stack (start_threadstack), and the
 *                    value is the frame the Mach-O's LC_UNIXTHREAD did not
 *                    have to invent
 *   pid=             proc_find/initproc wiring: 1 means this really is the
 *                    process bsd_init cloned in bsd_utaskbootstrap()
 *   task_self=       a Mach trap (28) went through mach_trap_table, so the
 *                    Mach side of the syscall switch, not only the BSD side,
 *                    is live
 *   open /probe.bin  mockfs's MOCKFS_TEST_FILE node resolves and open(2)
 *                    reaches it (the header's second entry)
 *
 * Then it parks. R61 established that exiting PID 1 makes the kernel call
 * panic_with_options(DEBUGGING_OPTION_INITPROC_PANIC); that would replace the
 * panel with the panic screen and throw away the very evidence being
 * collected. A wfe loop leaves the picture standing still, which is also what
 * a camera needs.
 */
#include "uio.h"

/* _start must be the first thing in the image: the Mach-O entry point is
 * __TEXT+0x1d0 and it is baked into LC_UNIXTHREAD. Naked matters -- a C
 * prologue moves sp before the first statement runs, and then this file
 * reports its own frame instead of the kernel-set stack pointer. */
__attribute__((section(".text.start"), naked, noreturn))
void _start(void)
{
	__asm__ volatile ("mov x0, sp\n\tb el0_main");
}

__attribute__((noinline, noreturn)) static void park(void)
{
	for (;;) {
		__asm__ volatile ("wfe");
	}
}

/* R164. One syscall, nothing else.
 *
 * The previous build wrote five lines to fd 1 before exiting, so "no panic on
 * screen" could mean either of two very different things: exec never returned
 * to EL0, or exec returned and the first write(2) never came back. Those two
 * have opposite fixes and the panel cannot tell them apart.
 *
 * exit(42) as the *first* instruction removes the ambiguity: PID 1 exiting is
 * the one event the kernel turns into panic_with_options(INITPROC_PANIC) no
 * matter what, and the panic screen prints the status. Panic on screen means
 * EL0 ran; a still panel means the kernel never got here. */
/* R166. The same three calls, with the answer now readable instead of guessed.
 *
 * The blob marks every step of write(1) on the kernel log's region of the
 * screen ('A' hook entered .. 'G' first chunk drawn), and it copies the bytes
 * into the frame buffer's last row, which the panic screen prints back as
 * "R166 out:". So one boot answers:
 *
 *   no marks at all          the hook never reached the panel
 *   A..C, then a fixed panel the fd 3 query returned; the fd 1 path is stuck
 *   A..F, then a fixed panel copyin returned and the glyph path is stuck
 *   A..G + out + status 42   the channel works and the text is on the screen
 *
 * The text lives on the stack, not in .rodata, so a copyin failure can only be
 * about write() itself.
 */
__attribute__((used, noreturn)) void el0_main(u64 entry_sp)
{
	/* volatile: without it the compiler folds the sixteen stores into one
	 * 16-byte load from .rodata, and the launch image carries .text only --
	 * the bytes would come from a page that is not in the file. Volatile
	 * keeps them as stores into this frame. */
	volatile char b[24];
	i64 r;

	(void)entry_sp;
	b[0] = 'R'; b[1] = '1'; b[2] = '7'; b[3] = '1'; b[4] = ' ';
	b[5] = 'E'; b[6] = 'L'; b[7] = '0'; b[8] = ' ';
	b[9] = 'W'; b[10] = 'R'; b[11] = 'T'; b[12] = ' ';
	b[13] = 'O'; b[14] = 'K'; b[15] = '\n'; b[16] = 0;

	r = sys6(SYS_write, 3, 0, 0, 0, 0, 0);
	if (r <= 0) {
		sys6(SYS_exit, 43, 0, 0, 0, 0, 0);
	}
	r = sys6(SYS_write, 1, (i64)b, 0, 0, 0, 0);
	if (r != 0) {
		sys6(SYS_exit, 44, 0, 0, 0, 0, 0);
	}
	r = sys6(SYS_write, 1, (i64)b, 16, 0, 0, 0);
	sys6(SYS_exit, (r == 16) ? 42 : 45, 0, 0, 0, 0, 0);
	park();
}
