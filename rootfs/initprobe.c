/*
 * initprobe.c -- /sbin/launchd fixture for the nio XNU port.
 *
 * History, in one paragraph: R61 proved userspace is real (a hand-encoded
 * exit(42) trapped through sleh_synchronous -> unix_syscall), R62 turned the
 * exit status into a bitmask because a panic was the only visible channel,
 * R63-R65 added fork/execve/wait4 and gave every failure its own number, and
 * R65 read 2089 = 42|255|0x100|0x200|0x400: the whole process-creation path
 * works, from a process the kernel did not create itself.
 *
 * R66 gave the kernel a boot console and R67 pointed sysent[SYS_write] at it,
 * so fd 1 now draws on screen and the exit status no longer has to carry
 * information. This file is the text version: it reports what it sees, line by
 * line, and then parks instead of exiting, because initproc exiting always
 * panics (kern_exit.c: proc_should_trigger_panic() is true for initproc) and
 * that panic screen would paint over everything printed here.
 *
 * Constraints imposed by the Mach-O wrapper:
 *   - __TEXT is R+X only, no writable segment, so NO globals: every buffer
 *     lives on the stack (the kernel sets sp via thread_setuserstack()).
 *   - freestanding, no libc, no TLS, no stack protector, no SIMD.
 */

#include "uio.h"

/* _start must be the first thing in the image: the Mach-O entry point is
 * __TEXT+0x1d0 and it is baked into LC_UNIXTHREAD. */
__attribute__((section(".text.start"), noreturn))
void _start(void)
{
	/* volatile: without it clang merges small compares into `ldur d0` SIMD
	 * loads, and this fixture should not depend on FP/SIMD being live for
	 * the first EL0 process. */
	volatile char b[32];
	long tv[2];
	i64 fd, child, got, is_child;
	long st;

	nio_puts("nio: launchd fixture, write(1) is the boot console\n");

	nio_kv("nio: pid=", sys6(SYS_getpid, 0, 0, 0, 0, 0, 0));
	nio_kv("nio: uid=", sys6(SYS_getuid, 0, 0, 0, 0, 0, 0));

	tv[0] = 0;
	tv[1] = 0;
	if (sys6(SYS_gettimeofday, (i64)tv, 0, 0, 0, 0, 0) == 0) {
		nio_kv("nio: tv_sec=", (i64)tv[0]);
	} else {
		nio_puts("nio: gettimeofday failed\n");
	}

	fd = sys6(SYS_open, (i64)"/", 0, 0, 0, 0, 0);
	nio_kv("nio: open(/) fd=", fd);

	fd = sys6(SYS_open, (i64)"/sbin/launchd", 0, 0, 0, 0, 0);
	if (fd >= 0 && sys6(SYS_read, fd, (i64)b, 4, 0, 0, 0) == 4) {
		unsigned m = (unsigned char)b[0] |
		             ((unsigned char)b[1] << 8) |
		             ((unsigned char)b[2] << 16) |
		             ((unsigned)b[3] << 24);
		nio_kh("nio: launchd magic=0x", m);
	} else {
		nio_puts("nio: cannot read /sbin/launchd\n");
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
	nio_kv("nio: child exit status ", (i64)(((unsigned)st >> 8) & 0xff));
	nio_puts("nio: exec pipeline OK, parking\n");

park:
	for (;;) {
		__asm__ volatile ("wfe");
	}
}
