/*
 * initprobe.c -- /sbin/launchd fixture for the nio XNU port (R62).
 *
 * R61 proved userspace is real: a hand-encoded `exit(42)` executed in EL0,
 * trapped through sleh_synchronous -> unix_syscall -> exit_with_reason, and
 * the kernel panicked because initproc exiting always panics. That channel is
 * the only visible one we have (the port has no console in the root image),
 * so this fixture turns it into a *register*: the exit status carries a
 * bitmask of syscalls that actually worked.
 *
 *   status = 42 + mask        (42 = nothing worked / old image)
 *
 *   bit 0  0x001  getpid() == 1                (we are initproc)
 *   bit 1  0x002  getuid() == 0                (cred is root)
 *   bit 2  0x004  gettimeofday(NULL,...) == 0  (non-VFS syscall path)
 *   bit 3  0x008  mmap(4K, RW, ANON) > 0       (VM map + pmap)
 *   bit 4  0x010  open("/") >= 0               (vfs lookup on mockfs root)
 *   bit 5  0x020  open("/sbin/launchd") >= 0   (our own image is a file)
 *   bit 6  0x040  read() == 4 && MH_MAGIC_64   (file I/O returns real bytes)
 *   bit 7  0x080  /probe.bin reads "NIO-PROBE" (second file, full path walk)
 *
 * So 297 means every layer a userspace needs is alive; a missing bit names
 * the layer that is not, without another round of guessing.
 *
 * Constraints imposed by the Mach-O we hand the kernel:
 *   - __TEXT is R+X only, no writable segment, so NO globals: every buffer
 *     lives on the stack (the kernel sets sp via thread_setuserstack()).
 *   - freestanding, no libc, no TLS, no stack protector.
 *   - arm64 XNU BSD syscall ABI: number in x16, args x0..x5, `svc #0x80`,
 *     result in x0 with the carry flag set on error (x0 = errno).
 */

typedef unsigned long u64;
typedef long i64;

#define SYS_exit         1
#define SYS_read         3
#define SYS_open         5
#define SYS_getpid       20
#define SYS_getuid       24
#define SYS_gettimeofday 116
#define SYS_mmap         197

#define PROT_READ_WRITE  3
#define MAP_PRIVATE_ANON 0x1002   /* MAP_PRIVATE | MAP_ANON */

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

/* _start must be the first thing in the image: the Mach-O entry point is
 * __TEXT+0x1d0 and it is baked into LC_UNIXTHREAD. */
__attribute__((section(".text.start"), noreturn))
void _start(void)
{
	/* volatile: without it clang merges the 9-byte probe.bin compare
	 * into an unaligned `ldur d0` SIMD load, and this fixture should not
	 * depend on FP/SIMD being live for the first EL0 process. */
	volatile char b[32];
	unsigned mask = 0;
	i64 fd;
	int i, ok;

	if (sys6(SYS_getpid, 0, 0, 0, 0, 0, 0) == 1) {
		mask |= 0x01;
	}
	if (sys6(SYS_getuid, 0, 0, 0, 0, 0, 0) == 0) {
		mask |= 0x02;
	}
	if (sys6(SYS_gettimeofday, 0, 0, 0, 0, 0, 0) == 0) {
		mask |= 0x04;
	}
	if (sys6(SYS_mmap, 0, 4096, PROT_READ_WRITE, MAP_PRIVATE_ANON, -1, 0) > 0) {
		mask |= 0x08;
	}

	if (sys6(SYS_open, (i64)"/", 0, 0, 0, 0, 0) >= 0) {
		mask |= 0x10;
	}

	fd = sys6(SYS_open, (i64)"/sbin/launchd", 0, 0, 0, 0, 0);
	if (fd >= 0) {
		mask |= 0x20;
		if (sys6(SYS_read, fd, (i64)b, 4, 0, 0, 0) == 4) {
			unsigned m = (unsigned char)b[0] |
			             ((unsigned char)b[1] << 8) |
			             ((unsigned char)b[2] << 16) |
			             ((unsigned)b[3] << 24);
			if (m == 0xfeedfacfU) {
				mask |= 0x40;
			}
		}
	}

	fd = sys6(SYS_open, (i64)"/probe.bin", 0, 0, 0, 0, 0);
	if (fd >= 0 && sys6(SYS_read, fd, (i64)b, 9, 0, 0, 0) == 9) {
		const char *want = "NIO-PROBE";
		ok = 1;
		for (i = 0; i < 9; i++) {
			if (b[i] != want[i]) {
				ok = 0;
			}
		}
		if (ok) {
			mask |= 0x80;
		}
	}

	sys6(SYS_exit, 42 + (i64)mask, 0, 0, 0, 0, 0);

	for (;;) {
		__asm__ volatile ("wfe");
	}
}
