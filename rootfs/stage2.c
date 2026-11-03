/*
 * stage2.c -- /probe.bin, the execve target for the nio XNU port.
 *
 * initprobe forks and the child execve()s this image. Reaching _start at all
 * means the kernel parsed a Mach-O for a process it did not create, gave it a
 * fresh address space and built the entry state -- that is the headline. The
 * checks below then report how much of the exec'd environment is right, as
 * text on the boot console (R67) instead of an exit-status code.
 *
 * The kernel's initial stack, from kern_exec.c:5590:
 *     sp -> [argc][arg0]..[argN-1][NULL][env0]..[envN-1][NULL][apple]
 * argc is a 32-bit value in a pointer-sized slot.
 *
 * Exit codes, still used by initprobe as a fallback:
 *   0  every check passed                  4  envp[0] != NULL
 *   1  getpid() <= 1                       5  open("/") failed in the new image
 *   2  argc != 1                           6  image not linked at 0x100000000
 *   3  argv[0] != "/probe.bin"
 *
 * Same Mach-O constraints as initprobe: R+X __TEXT only, no globals, no
 * libcalls, general registers only (no FP/SIMD).
 */

#include "uio.h"

static int streq(const char *a, const char *b)
{
	while (*a != '\0' && *a == *b) {
		a++;
		b++;
	}
	return *a == *b;
}

/*
 * R70 lesson: reading sp inside a C function body reads the prologue's own
 * frame, not what the kernel set up. Capture it in a naked entry point that
 * hands the register straight to the body before any frame exists.
 */
void stage2_main(u64 entry_sp) __attribute__((noreturn));

__attribute__((section(".text.start"), naked, noreturn))
void _start(void)
{
	__asm__ volatile ("mov x0, sp\n\t"
	                  "b stage2_main\n\t");
}

__attribute__((used, noreturn)) void stage2_main(u64 entry_sp)
{
	i64 sp, argc, pid, fd, base;
	char **argv;
	char **envp;

	sp = (i64)entry_sp;

	pid = sys6(SYS_getpid, 0, 0, 0, 0, 0, 0);
	if (pid <= 1) {
		nio_puts("child: FAIL getpid <= 1\n");
		sys6(SYS_exit, 1, 0, 0, 0, 0, 0);
	}
	nio_kv("child: stage2 pid=", pid);

	/* argc is an int32 in a pointer-sized slot: kern_exec.c:5789 uses
	 * copyoutptr(), which writes 4 bytes, so the upper half of the slot is
	 * stale stack. Reading it as 64 bits would compare garbage against 1. */
	argc = *(int *)sp;
	argv = (char **)(sp + 8);
	envp = argv + argc + 1;

	/* One line carries what took four rounds to explain: the sp the kernel
	 * set, the argc it wrote there, and this image's own copy of the string
	 * address (if argv[0] matches it, the kernel copied the string, not the
	 * parent's pointer). The 16-slot dump that proved the layout in R71 is
	 * gone -- the layout is no longer in question. */
	nio_puts("child: pid=");
	nio_dec(pid);
	nio_puts(" argc=");
	nio_dec(argc);
	nio_puts(" esp=0x");
	nio_hex((u64)sp);
	nio_puts("\n");
	nio_kh("child: ours=0x", (u64)"/probe.bin");

	if (argc != 1) {
		nio_kv("child: FAIL argc=", argc);
		sys6(SYS_exit, 2, 0, 0, 0, 0, 0);
	}
	if (!streq(argv[0], "/probe.bin")) {
		nio_kh("child: FAIL argv0 ptr=0x", (u64)argv[0]);
		nio_puts("child: FAIL argv0 text=[");
		if ((u64)argv[0] > 0x1000 && (u64)argv[0] < 0x10000000000ULL) {
			nio_puts(argv[0]);
		} else {
			nio_puts("<outside user map>");
		}
		nio_puts("]\n");
		sys6(SYS_exit, 3, 0, 0, 0, 0, 0);
	}
	nio_puts("child: argv0=/probe.bin argc=1\n");
	if (envp[0] != 0) {
		nio_puts("child: FAIL envp0 not null\n");
		sys6(SYS_exit, 4, 0, 0, 0, 0, 0);
	}

	/* fresh process image, fresh fd table: prove VFS is reachable here too */
	fd = sys6(SYS_open, (i64)"/", 0, 0, 0, 0, 0);
	if (fd < 0) {
		nio_kv("child: FAIL open(/) ", fd);
		sys6(SYS_exit, 5, 0, 0, 0, 0, 0);
	}
	nio_kv("child: open(/) fd=", fd);

	/* the segment must sit where it was linked (no slide), otherwise a real
	 * dyld would have to fix up every pointer we baked in. A local label,
	 * not &_start: under -fpie a function symbol is preemptible, so taking
	 * its address pulls in a writable .got and the image loses R+X-only. */
	base = (i64)&&linked_here;
	if ((u64)base >> 32 != 1) {
		nio_kh("child: FAIL link base=0x", (u64)base);
		sys6(SYS_exit, 6, 0, 0, 0, 0, 0);
	}
	nio_kh("child: link base=0x", (u64)base);

linked_here:
	nio_puts("child: all checks passed, exit 0\n");
	sys6(SYS_exit, 0, 0, 0, 0, 0, 0);
	for (;;) {
		__asm__ volatile ("wfe");
	}
}
