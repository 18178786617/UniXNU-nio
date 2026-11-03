/* Minimal /sbin/launchd fixture: enter userland, park forever.
 * mockfs serves this Mach-O as the executable frontend of the root device;
 * bsd_init execs it once the root is mounted. */
typedef unsigned long u64;

__attribute__((noreturn)) void _start(void)
{
    for (;;) {
        __asm__ volatile ("wfe");
    }
}
