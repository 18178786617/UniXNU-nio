/*
 * uio.h -- the only I/O the nio fixtures have.
 *
 * R66 gave the kernel a boot console (kprintf now draws on the frame buffer).
 * R67 routed sysent[SYS_write] to that console, so write(2) on fd 1 or 2 from a
 * process in EL0 appears on screen. That replaced the exit-status bitmask with
 * plain text: a fixture can now say what it saw instead of encoding it.
 *
 * Everything here is header-only and freestanding. No globals: the Mach-O these
 * fixtures are wrapped in has a single R+X segment, so any writable data would
 * fault on the first store.
 */
#ifndef NIO_UIO_H
#define NIO_UIO_H

typedef unsigned long u64;
typedef unsigned int u32;
typedef long i64;

#define SYS_exit         1
#define SYS_fork         2
#define SYS_read         3
#define SYS_write        4
#define SYS_open         5
#define SYS_wait4        7
#define SYS_getpid       20
#define SYS_getuid       24
#define SYS_execve       59
#define SYS_gettimeofday 116
#define SYS_mmap         197

/* fd 3 is the screen, served by the same sysent[4] hook that draws fd 1/2:
 * the buffer is a list of six-word rectangles {op, colour, x, y, w, h}, and
 * write(3, 0, 0) answers with the panel size packed as width<<32 | height. */
#define NIO_FB_RECT      1

#define NIO_PROT_RW      3
#define NIO_MAP_ANON     0x1002   /* MAP_PRIVATE | MAP_ANON */

/* Mach traps ride the same SVC as BSD calls: the number goes in x16 as a
 * negative value, and mach_syscall() (osfmk/arm64/bsd_arm64.c:193) negates it
 * back before indexing mach_trap_table. No carry flag: the result is a
 * kern_return_t. 28 is task_self_trap, the cheapest proof the table is live. */
static inline i64 nio_mach0(i64 trap)
{
	register i64 x0 __asm__("x0") = 0;
	register i64 x16 __asm__("x16") = -trap;

	__asm__ volatile ("svc #0x80" : "+r"(x0) : "r"(x16) : "memory");
	return x0;
}

/* arm64 XNU BSD syscall ABI: number in x16, arguments in x0..x5, `svc #0x80`,
 * result in x0 with the carry flag set on error (x0 = errno). */
static inline i64 sys6(i64 n, i64 a, i64 b, i64 c, i64 d, i64 e, i64 f)
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

/* fork() on arm64 XNU hands the child (x0 = pid, x1 = 1); libSystem's fork stub
 * is what folds that into "return 0 in the child". We have no libSystem. */
static inline i64 sys_fork(i64 *is_child)
{
	register i64 x0 __asm__("x0") = 0;
	register i64 x1 __asm__("x1") = 0;
	register i64 x16 __asm__("x16") = SYS_fork;
	i64 cf;

	__asm__ volatile ("svc #0x80\n\tcset %w2, cs"
	                  : "+r"(x0), "+r"(x1), "=&r"(cf)
	                  : "r"(x16)
	                  : "memory", "cc");
	*is_child = x1;
	return cf ? -x0 : x0;
}

static inline unsigned nio_len(const char *s)
{
	unsigned n = 0;

	while (s[n]) {
		n++;
	}
	return n;
}

static __attribute__((noinline)) void nio_raw(const char *s, unsigned n)
{
	sys6(SYS_write, 1, (i64)s, (i64)n, 0, 0, 0);
}

static __attribute__((noinline)) void nio_puts(const char *s)
{
	nio_raw(s, nio_len(s));
}

static __attribute__((noinline)) void nio_dec(i64 v)
{
	char b[24];
	unsigned i = sizeof b;
	u64 u = (u64)v;

	if (v < 0) {
		u = (u64)(-v);
	}
	do {
		b[--i] = (char)('0' + (u % 10));
		u /= 10;
	} while (u);
	if (v < 0) {
		b[--i] = '-';
	}
	nio_raw(b + i, (unsigned)(sizeof b - i));
}

static __attribute__((noinline)) void nio_hex(u64 v)
{
	char b[20];
	unsigned i = sizeof b;
	unsigned digits = 0;

	do {
		unsigned d = (unsigned)(v & 0xf);
		b[--i] = (char)(d < 10 ? '0' + d : 'a' + d - 10);
		v >>= 4;
		digits++;
	} while (v || digits < 8);
	nio_raw(b + i, (unsigned)(sizeof b - i));
}

/* "name=value\n", the shape most of these lines take */
static __attribute__((noinline)) void nio_kv(const char *k, i64 v)
{
	nio_puts(k);
	nio_dec(v);
	nio_puts("\n");
}

static __attribute__((noinline)) void nio_kh(const char *k, u64 v)
{
	nio_puts(k);
	nio_hex(v);
	nio_puts("\n");
}

static __attribute__((noinline)) i64 nio_fb_size(void)
{
	return sys6(SYS_write, 3, 0, 0, 0, 0, 0);
}

static __attribute__((noinline)) i64 nio_fb_send(const u32 *cmds, unsigned bytes)
{
	return sys6(SYS_write, 3, (i64)cmds, (i64)bytes, 0, 0, 0);
}

/* One command into a caller-owned array: the fixture keeps its command buffer
 * on the stack because the image has no writable segment. */
static inline void nio_fb_rect(u32 *c, u32 colour, u32 x, u32 y, u32 w, u32 h)
{
	c[0] = NIO_FB_RECT;
	c[1] = colour;
	c[2] = x;
	c[3] = y;
	c[4] = w;
	c[5] = h;
}

#endif
