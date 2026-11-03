/*
 * stage2.c -- /probe.bin, the execve target for the nio XNU port (R65).
 *
 * initprobe forks and the child execve()s this image. Reaching _start at all
 * means the kernel parsed a Mach-O for a process it did not create, gave it a
 * fresh address space and built the entry state -- that is the headline. The
 * checks below then say how much of the exec'd environment is right.
 *
 * R64 read 4001 because this file used to test `getpid() == 1`: the execve
 * target is the forked child, so its pid is 2, not 1. The kernel had done
 * everything right and the fixture called it a failure -- the same class of
 * mistake as R63's fork test, so the exit codes are now unambiguous and the
 * checks are about the *exec'd* state, not about being init.
 *
 * Exit codes (parent maps them to 4000+n):
 *   0  every check below passed            4  envp[0] != NULL
 *   1  getpid() <= 1                       5  open("/") failed in the new image
 *   2  argc != 1                           6  image not linked at 0x100000000
 *   3  argv[0] != "/probe.bin"
 *
 * A failed execve() never reaches this code: the child exits 128+errno there,
 * and the parent reports 5128+errno, so the two can never be confused.
 *
 * Same Mach-O constraints as initprobe: R+X __TEXT only, no globals, no
 * libcalls, general registers only (no FP/SIMD).
 */

typedef long i64;
typedef unsigned long u64;

#define SYS_exit   1
#define SYS_open   5
#define SYS_getpid 20

static i64 sys6(i64 n, i64 a, i64 b, i64 c, i64 d, i64 e, i64 f)
{
	register i64 x0 __asm__("x0") = a;
	register i64 x1 __asm__("x1") = b;
	register i64 x2 __asm__("x2") = c;
	register i64 x3 __asm__("x3") = d;
	register i64 x4 __asm__("x4") = e;
	register i64 x5 __asm__("x5") = f;
	register i64 x16 __asm__("x16") = n;
	i64 cf;

	__asm__ volatile ("svc #0x80\n\tcset %w1, cs"
	                  : "+r"(x0), "=&r"(cf)
	                  : "r"(x1), "r"(x2), "r"(x3), "r"(x4), "r"(x5), "r"(x16)
	                  : "memory", "cc");
	return cf ? -x0 : x0;
}

static int streq(const char *a, const char *b)
{
	while (*a != '\0' && *a == *b) {
		a++;
		b++;
	}
	return *a == *b;
}

__attribute__((section(".text.start"), noreturn))
void _start(void)
{
	i64 sp, argc, pid, fd, base;
	char **argv;
	char **envp;

	/* kern_exec.c:5590 -- the strings segment is laid out backward and the
	 * returned sp points at the argc slot:
	 *     sp -> [argc][arg0]..[argN-1][NULL][env0]..[envN-1][NULL][apple]
	 * argc is a 32-bit value in a pointer-sized slot. */
	__asm__ volatile ("mov %0, sp" : "=r"(sp));

	pid = sys6(SYS_getpid, 0, 0, 0, 0, 0, 0);
	if (pid <= 1) {
		sys6(SYS_exit, 1, 0, 0, 0, 0, 0);
	}

	argc = *(i64 *)sp;
	argv = (char **)(sp + 8);
	envp = argv + argc + 1;

	if (argc != 1) {
		sys6(SYS_exit, 2, 0, 0, 0, 0, 0);
	}
	if (!streq(argv[0], "/probe.bin")) {
		sys6(SYS_exit, 3, 0, 0, 0, 0, 0);
	}
	if (envp[0] != 0) {
		sys6(SYS_exit, 4, 0, 0, 0, 0, 0);
	}

	/* fresh process image, fresh fd table: prove VFS is reachable here too */
	fd = sys6(SYS_open, (i64)"/", 0, 0, 0, 0, 0);
	if (fd < 0) {
		sys6(SYS_exit, 5, 0, 0, 0, 0, 0);
	}

	/* the segment must sit where it was linked (no slide), otherwise a real
	 * dyld would have to fix up every pointer we baked in. A local label,
	 * not &_start: under -fpie a function symbol is preemptible, so taking
	 * its address pulls in a writable .got and the image loses R+X-only. */
	base = (i64)&&linked_here;
	if ((u64)base >> 32 != 1) {
		sys6(SYS_exit, 6, 0, 0, 0, 0, 0);
	}

linked_here:
	sys6(SYS_exit, 0, 0, 0, 0, 0, 0);
	for (;;) {
		__asm__ volatile ("wfe");
	}
}
