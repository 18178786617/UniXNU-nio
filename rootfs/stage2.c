/*
 * stage2.c -- /probe.bin, the execve target for the nio XNU port (R63).
 *
 * init (initprobe) forks and the child execve()s this image. If the kernel
 * really replaced the address space, this code runs as pid 1 with a fresh
 * Mach-O and exits 0; the parent's wait4() then sees WIFEXITED/WEXITSTATUS==0.
 *
 * Exiting 0 here is the entire report: the parent turns "child exited 0"
 * into a single success number, and "child exited errno" means execve()
 * failed before we ever got to run.
 *
 * Same Mach-O constraints as initprobe: R+X __TEXT only, no globals.
 */

typedef long i64;

#define SYS_exit   1
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

__attribute__((section(".text.start"), noreturn))
void _start(void)
{
	i64 pid = sys6(SYS_getpid, 0, 0, 0, 0, 0, 0);

	/* 0 = execve landed and this is still initproc; 1 = we run, but the
	 * exec lost the pid (would mean the kernel made a new process). */
	sys6(SYS_exit, pid == 1 ? 0 : 1, 0, 0, 0, 0, 0);
	for (;;) {
		__asm__ volatile ("wfe");
	}
}
