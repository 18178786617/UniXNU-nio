/* Draw a kernel panic message, with its arguments, on the frame buffer, then stop.
 *
 * Built freestanding by patch-xnu-entry-probe.py and placed in unused padding
 * of a COPY of the kernel; panic() and its common panic funnel are redirected
 * here. It runs on the kernel's
 * own mapping of the frame buffer. With the board observer it uses the retained
 * GOP mapping prefix; otherwise it uses vinfo.v_baseaddr.
 *
 * panic(fmt, ...) is variadic and the Darwin arm64 ABI passes every variadic
 * argument in an 8-byte stack slot, starting at the stack pointer on entry.
 * A small printf walks the format string over those slots (%s %x %p, with
 * 0-flag, width, precision and l/ll/z). Kernel strings are checked with an
 * active hardware translation query before reading each byte;
 * unmapped/device/user pointers print as pointers. VINFO names that mapping prefix.
 */
typedef unsigned long u64;
typedef unsigned int u32;
typedef unsigned char u8;

struct vc_info {
  u32 v_height, v_width, v_depth, v_rowbytes;
  u64 v_baseaddr;
};

/* ---- the GOP framebuffer DarwinBoot handed over ------------------------
 *
 * DarwinBoot passes the GOP framebuffer's *physical* address (0x9C000000 on
 * nio) in boot_args.Video.v_baseAddr and XNU maps it in initialize_screen(),
 * which only runs from PE_create_console() near the end of arm_init.  Until
 * that happens vinfo.v_baseaddr is 0 and there is nothing to draw on, so a
 * kernel that dies before that point leaves the phone showing DarwinBoot's
 * picture with no explanation whatsoever.
 *
 * The blob therefore maps the buffer itself the first time it needs it.
 * ml_io_map_unmappable() is exactly the call the kernel would have made; it
 * is only safe once the VM exists, which is what the kernel_map test checks.
 * The geometry is the one DarwinBoot printed:
 *
 *   video  base 0x9C000000  1080x2520  row 4320 bytes  32 bpp
 *
 * round_page(2520 * 4320) = 0xA62000 covers all 2520 rows of the panel, so
 * nothing the blob draws can reach past the end of the mapping. */
#define FB_PHYS        0x9C000000UL
#define FB_COLS        1080u
#define FB_ROWS        2520u
#define FB_ROWBYTES    4320u
#define FB_DEPTH       32u
#define FB_MAPSIZE     0xA62000UL      /* round_page(2520 * 4320) */
#define FB_PROT        0x7u           /* VM_WIMG_IO, osfmk/arm/memory_types.h */

/* Defined further down, next to the R187 diagnostic ladder. */
static u32 va_mapped (u64 a);

static u64 fb_lazy_map (void)
{
  /* R222: the blob no longer maps the panel, and no longer writes vinfo.
   *
   * R221 mapped it with ml_io_map_unmappable() and stored the result in
   * vinfo.v_baseaddr.  That address was wrong in a way that looks right:
   * the mapping went into the bootstrap pmap while the live cpu_ttep was
   * built out of a different one, so the page was reachable (its L1 entry
   * was there) but had no L2 entry.  Every store into it raised a level-2
   * translation fault, and the panic dump the blob happened to be drawing
   * at the time died half-way through its own last line:
   *
   *   far = 0x0000000000000968   esr = 0x0000000096000004
   *   pc  = 0xfffffff007a2245c   (cell(): str w17, [x18, w4, uxtw #2])
   *
   * Mapping the panel is the kernel's business: initialize_screen() does
   * it with the live VM and publishes the result in vinfo.v_baseaddr.  The
   * blob only reads that, and asks the hardware (at s1e1r) whether the
   * address translates right now. */
  volatile struct vc_info *v = (volatile struct vc_info *)VINFO;

  return (u64)v->v_baseaddr;
}

/* ---- where the pixels go -----------------------------------------------
 *
 * Up to 0x73e3100 the frame buffer is reachable at its physical address
 * 0x9c000000: that low address is covered by the bootstrap tables' identity
 * block.  At 0x73e3100 arm_vm_init() executes `msr ttbr1_el1, cpu_ttep` and
 * from the very next instruction the identity block is gone -- the same
 * store is now a data abort, which is why every panic raised from inside
 * arm_vm_init() so far has produced a completely blank screen instead of the
 * text this file is here to draw.
 *
 * The tables it switched to do carry the physmap, so the panel is still
 * reachable at
 *
 *     gVirtBase + (0x9c000000 - gPhysBase)
 *
 * and phystokv() (arm_vm_init.c:387) is literally that expression.  Both
 * globals are set near the top of arm_vm_init() (arm_vm_init.c:1836), long
 * before anything here can run, so two loads is all it takes.  Before that
 * they are zero, and then the plain physical address is the right answer.
 *
 * _gPhysBase = 0xfffffff007178100
 * _gVirtBase = 0xfffffff007178110   (checked with llvm-nm on this build)
 */
#define GVPHYS_ADDR  0xFFFFFFF007178100UL

#define KVA_ACTIVE_ADDR  0xFFFFFFF007178038UL   /* _kva_active */

/* R210: always the identity address.
 *
 * The old rule was "if _kva_active is set, use the physmap alias", on the
 * theory that the bootstrap tables (and with them the 0x9c000000 identity
 * block) are gone once TTBR1 is switched to cpu_ttep.  Two rounds of
 * measurements say otherwise:
 *
 *   - R205/R206 proved the physmap does *not* cover the frame buffer at all
 *     (all four stamps drawn through gVirtBase + 0x9c000000 - gPhysBase came
 *     back dark), so the alias is not a fallback, it is a hole.
 *   - R208..R210 run with the TTBR0 gate at 0x73e3114 NOPed, so 0x9c000000
 *     keeps its identity mapping for the whole of arm_vm_init.
 *
 * The consequence of the old rule: the moment 0x73e3128 set _kva_active = 1,
 * every later byte the blob drew went into unmapped memory, which is why the
 * R209 screen showed the diag ladder but never a panic message.  The panic we
 * are chasing happens *at* that store, i.e. exactly where the old rule
 * flipped the screen off.
 *
 * Restore the kva_active test if the TTBR0 gate is ever un-NOPed again; until
 * then the identity address is the only one that is mapped. */

/* R221: the base is picked at run time, because there are two of them.
 *
 * arm_init.c:555 says it outright:
 *
 *     // arm_vm_init removes TTBR0. Use the established kernel I/O mapping now.
 *
 * arm_vm_init() drops the bootstrap tables (pmap.c's set_mmu_ttb(invalid_ttep)
 * and the TTBR0 switch it gates), and with them the identity block the entry
 * probe installed over the panel.  From that moment on the panel's *physical*
 * address 0x9c000000 is a hole: a load from it is a level-1 translation fault.
 *
 * R220 died exactly there.  It kept its state in the panel's row 0 and reached
 * it through the physical address, and the first read after arm_vm_init()
 * came back as
 *
 *     far=0x000000009c00001c  esr=0x0000000096000005  pc=0xfffffff007a22778
 *
 * -- an L1 translation fault (FSC 0x05) on the state word itself, with x20
 * holding 0x9c00001c and the faulting instruction being "ldr w8, [x20]".
 *
 * After the switch there is exactly one way to reach the panel: the kernel's
 * own mapping, which initialize_screen() publishes in vinfo.v_baseaddr.
 * R220 never looked at it, even though panic_screen_main() drew the whole
 * panic dump through it.
 *
 * So the base is chosen per call:
 *
 *   - the kernel's mapping, when it has published one;
 *   - the physical address, while the identity block is still alive -- AT
 *     S1E1R says the address still translates;
 *   - nothing at all in the window between arm_vm_init() and
 *     PE_create_console(), where neither route works.  Drawing is skipped
 *     there rather than taking the kernel down for a panel.
 */
static u32 va_mapped (u64 a);

static u64 fb_base (void){
  volatile struct vc_info *v = (volatile struct vc_info *)VINFO;
  u64 m = (u64)v->v_baseaddr;

  /* R222: the kernel's mapping is only usable if the hardware still
   * translates it.  vinfo.v_baseaddr can name a page the live tables do
   * not cover -- R221 proved exactly that (L1 entry present, L2 entry
   * missing) -- and the first store into it then takes the kernel down
   * over a panel.  at s1e1r is the hardware's own verdict, so ask it. */
  if (m != 0 && va_mapped (m)) {
    return m;
  }
  /* The identity block covers the panel's physical address for as long as
   * the bootstrap tables are in place. */
  if (va_mapped (FB_PHYS)) {
    return FB_PHYS;
  }
  /* No writable panel right now.  Draw nothing rather than fault. */
  return 0;
}

/* ---- where the blob keeps its state -------------------------------------
 *
 * R220: the blob is linked into __TEXT_EXEC, and the kernel maps that
 * segment read-only (arm_vm_page_granular_ROX, arm_vm_init.c:1418).  So
 * the moment arm_vm_init() switches TTBR1 to the new cpu_ttep, every store
 * into the blob's own .data raises a level-3 permission fault.
 *
 * R219 died exactly there.  The blob's _kprintf hook routes every kernel
 * printf through blob_printf(), and blob_vprintf() opens with
 *
 *     calls++;                       // .data
 *     blob_xbase = (calls & 1) * 460;
 *
 * The first word is a store into the blob's own .data at
 * 0xfffffff007a228dc (the symbol is blob_vprintf.calls, blob+6340), so the
 * very first kprintf after the table switch took a permission fault on a
 * read-only page.  XNU caught it, saw the fault address inside the kernel
 * static region and printed "Unexpected fault in kernel static region" --
 * which is why R219's screen showed a panic dump with no kernel log under
 * it: the log stopped exactly at the switch.
 *
 * The blob was always written on the assumption that it keeps no writable
 * state ("Zero-initialised on purpose ... 0 therefore means 'not started
 * yet'"), and R193's calls/busy/blob_xbase/blob_first counters quietly broke
 * that assumption.  The state therefore moved into the frame buffer's row 0.
 *
 * R221: the state stays there, but it is reached through fb_base() instead
 * of through the panel's physical address.  Row 0 is at offset 0 of the
 * panel, and both the identity mapping and the kernel's own mapping cover
 * the same physical page, so the words are the same bytes before and after
 * arm_vm_init() drops TTBR0 -- the state survives the switch.
 *
 * The magic word guards the reset: the frame buffer is not zeroed when the
 * kernel boots, so the first access has to know whether the counters hold
 * anything.  When there is no usable panel at all (the window between
 * arm_vm_init() and PE_create_console()) the accessors return zero and
 * store nothing: a counter that cannot be read is worth less than a
 * kernel that keeps running. */
#define STATE_ROW    0u
#define ST_CALLS     0u
#define ST_BUSY      1u
#define ST_XBASE     2u
#define ST_FIRST     3u
#define ST_IDENT_X   4u
#define ST_IDENT_Y   5u
#define ST_MAGIC     7u
#define ST_MAGIC_V   0xB10B0020u
/* R233: the last fd 1 write, in two words.
 *
 * The early blob has about fifty spare bytes in __TEXT_EXEC's tail, and a
 * plain text line about the fd 1 path costs three hundred and twenty eight:
 * a second caller of tp_text() forces the compiler to stop inlining it and
 * keep the whole body twice.  So the early blob only records the numbers
 * here, in the frame buffer's state row, and the channel blob -- which has
 * room to spare -- prints them as a line of text.
 *
 * The frame buffer's state row is the one piece of memory both blobs can
 * agree on: it is the same bytes before and after arm_vm_init() drops
 * TTBR0, and the touch bridge's own stash lives in the last row, not here.
 * Slot 8 holds n and v packed together, slot 9 the number of bytes copied. */
#define ST_FD1_N     8u
#define ST_FD1_C     9u

static volatile u32 *st_ptr (u32 i)
{
  u64 base = fb_base ();
  volatile u32 *s;

  if (base == 0) {
    return 0;
  }
  s = (volatile u32 *)(base + (u64)STATE_ROW * FB_ROWBYTES);

  if (s[ST_MAGIC] != ST_MAGIC_V) {
    s[ST_CALLS] = 0u;
    s[ST_BUSY] = 0u;
    s[ST_XBASE] = 0u;
    s[ST_FIRST] = 0u;
    s[ST_IDENT_X] = 0u;
    s[ST_IDENT_Y] = 0u;
    s[ST_FD1_N] = 0u;
    s[ST_FD1_C] = 0u;
    s[ST_MAGIC] = ST_MAGIC_V;
  }
  return s + i;
}

static u32 st_get (u32 i)
{
  volatile u32 *s = st_ptr (i);

  return s != 0 ? *s : 0u;
}

static void st_set (u32 i, u32 v)
{
  volatile u32 *s = st_ptr (i);

  if (s != 0) {
    *s = v;
  }
}

#define BLOB_CALLS  (st_get (ST_CALLS))
#define BLOB_BUSY   (st_get (ST_BUSY))
#define BLOB_XBASE  (st_get (ST_XBASE))
#define BLOB_FIRST  (st_get (ST_FIRST))
#define IDENT_X     (st_get (ST_IDENT_X))
#define IDENT_Y     (st_get (ST_IDENT_Y))

/* ---- stage markers ------------------------------------------------------
 *
 * The kernel leaves nothing on the screen until it owns a framebuffer, so a
 * failure before that point looks exactly like a success: the phone keeps
 * showing DarwinBoot's picture.  These paint one coloured square per
 * milestone, so a recording says exactly how far the boot got:
 *
 *   1 green -- arm_vm_init() has returned, the VM is up
 *   2 blue  -- PE_create_console() ran but left no framebuffer mapping
 *   3 magenta -- PE_create_console() ran and vinfo holds the kernel's own
 *               mapping
 *   4 cyan  -- PE_init_printf() has run, so every kprintf() from here on
 *               reaches the screen through this blob
 *
 * R177: the squares used to sit at row 2400 of the 2520 row panel, and the
 * recordings are filmed with a camera held over the top of the phone -- the
 * bottom third of the panel never appears in frame.  A marker down there is
 * indistinguishable from a marker that was never drawn, which is what
 * happened for several rounds.  Row 1100 is in the middle of the panel and
 * inside every frame we have.  The letter next to the square survives a
 * camera that cannot tell green from magenta.
 *
 * R178: row 1100 is still below the frame.  The recordings only ever cover
 * the top of the panel -- the enhanced crop of the R177 video shows the
 * camera losing focus on the phone's own body below video row 680 -- so the
 * marks now sit on row 170, right under the green band DarwinBoot paints
 * (that band is rows 0..157), and the kernel log starts below them at row
 * 336 so the two cannot overlap.  The entry probe writes its four colour
 * bands into x 0..255 of the same row; the stage squares start at x 320,
 * so the probe and the stages never share a pixel. */
#define STAGE_ROW   170u
#define STAGE_X0    320u
#define STAGE_SIZE  96u
#define STAGE_PITCH 128u

static void cell (u8 *base, u32 rb, u32 x, u32 y, u8 c);

__attribute__((used)) void stage_mark (u64 stage)
{
  volatile struct vc_info *v = (volatile struct vc_info *)VINFO;
  u8 *base;
  u32 rb, w, x, y, i, c;
  u32 colour;

  fb_lazy_map ();
  /* R222: fb_base() checks with at s1e1r that the address really translates
   * now; vinfo.v_baseaddr on its own can name a page the live tables do not
   * cover, and R221 proved that the store then faults. */
  base = (u8 *)fb_base ();
  rb   = v->v_rowbytes;
  w    = v->v_width;
  /* R222: before initialize_screen() the kernel has not published the
   * geometry yet, but DarwinBoot printed it and it has not changed. */
  if (rb == 0) {
    rb = FB_ROWBYTES;
  }
  if (w == 0) {
    w = FB_COLS;
  }
  if (base == 0 || rb == 0 || w == 0) {
    return;
  }
  switch (stage) {
  case 1:  colour = 0x0000ff00u; break;   /* green   */
  case 2:  colour = 0x00ff0000u; break;   /* blue    */
  case 3:  colour = 0x00ff00ffu; break;   /* magenta */
  default: colour = 0x00ffff00u; break;   /* cyan    */
  }
  x = STAGE_X0 + STAGE_PITCH * ((u32)stage - 1u);
  y = STAGE_ROW;
  for (i = 0; i < STAGE_SIZE; i++) {
    volatile u32 *row = (volatile u32 *)(base + (u64)(y + i) * rb + (u64)x * 4);
    for (c = 0; c < STAGE_SIZE; c++) {
      row[c] = colour;
    }
  }
  /* "K1".."K4" in the block's own colour, so the stage is readable even in
   * a photograph whose colours are off. */
  cell (base, rb, x + 8u, y + 24u, 'K');
  cell (base, rb, x + 40u, y + 24u, (u8)('0' + (u32)stage));
}

#define SCALE   3

extern const u64 gFont[];

/* All state lives on the stack: this code sits in the kernel's read-only text,
 * so a writable global would fault on its first store. */
struct ctx {
  u8  *base;
  u32 rb, w, h, x, y;
  u8  *log;   /* kernel buffer that also receives the formatted message (PANIC_TEXT), 0 = none */
  u32 logn;
  u32 maxy;   /* last pixel row the drawing may touch, 0 = no limit known */
};

#ifndef PANIC_TEXT
#define PANIC_TEXT 0UL
#endif
#define PANIC_TEXT_BYTES 2048   /* boot_progress_panic_text: a data abort's message with every register, then the frames */

/* How many pixel rows of the frame buffer may be touched.
 *
 * The kernel maps the frame buffer itself: initialize_screen() calls
 * ml_io_map_unmappable() and remembers the extent of that mapping in
 * lastVideoMapSize, with lastVideoVirt as its start; vinfo.v_baseaddr is that
 * mapping plus the bootloader's offset.  R104 died in a pixel store inside
 * the buffer, so both the drawing code and the panic screen stop at the end
 * of the mapping instead of aborting the kernel over it.
 *
 * The answer is the smaller of the panel height and the extent of the
 * mapping: the panel is 1080x2520 but the mapping is a page multiple short
 * of that, so the last rows of the panel are not addressable and everything
 * that touches the bottom of the screen -- the console cursor, the panic
 * marker -- has to be moved off it.
 *
 * R107: the comparison was `<=`, and vinfo.v_baseaddr is lastVideoVirt
 * exactly on this board (the bootloader's offset is zero), so the guard
 * answered "no limit known" on every single call -- the R105 protection was
 * dead from the day it was written.  `<` gives the extent of the mapping when
 * the frame buffer starts where the kernel's mapping starts, which is the
 * case that matters. */
static u32 fb_rows (u8 *base, u32 rb, u32 h)
{
  u32 rows = h;

#ifdef LAST_VIDEO_SIZE
  u64 vbase = *(volatile const u64 *)LAST_VIDEO_VIRT;
  u64 sz = *(volatile const u64 *)LAST_VIDEO_SIZE;

  if (sz != 0 && (u64)base >= vbase && rb != 0) {
    u32 mr = (u32)((sz - ((u64)base - vbase)) / rb);

    if (mr != 0 && mr < rows) {
      rows = mr;
    }
  }
#endif
  return rows;
}

/* R227: how many rows of the panel the live tables actually reach.
 *
 * fb_rows() knows the extent of the kernel's own mapping, but that mapping
 * only exists after PE_create_console().  Before that the panel is reached
 * through the bootloader's identity block, which is two 2 MiB entries over
 * the panel's physical address -- rows 0..969 -- and the kernel does not
 * know that.  The panic screen believed the panel was 2520 rows tall and
 * wiped rows 840..1176, which runs off the end of that block at row 970, so
 * the panic handler faulted inside its own first line: the round ended with
 * a silent screen and no far/esr/lv to read.
 *
 * Ask the hardware instead.  at s1e1r translates the address without raising
 * an exception, so the last reachable row can be found by bisection. */
static u32 fb_mapped_rows (u8 *base, u32 rb, u32 h)
{
  u32 lo = 0, hi = h;

  if (base == 0 || rb == 0) {
    return h;
  }
  while (lo < hi) {
    u32 mid = lo + (hi - lo + 1) / 2;

    /* The last address of the row, not its first: a row is 4320 bytes and
     * the mapping ends on a page boundary, so the last row a mapping
     * reaches is usually only partly covered. */
    if (va_mapped ((u64)base + (u64)(mid + 1) * rb - 4u)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  return lo;
}

__attribute__((noreturn)) static void park (void)
{
  for (;;) {
    __asm__ volatile ("wfe");
  }
}

static void put (struct ctx *g, u8 c)
{
  const u32 cell = 6 * SCALE, line = 14 * SCALE;
  u32 row, col, dy, dx;

  if (g->log && g->logn < PANIC_TEXT_BYTES - 1 && c >= 9 && c <= 126) {
    g->log[g->logn++] = (c < 32) ? ' ' : c;
    g->log[g->logn] = 0;
  }

  if (c == '\n') {
    g->x = 0;
    g->y += line;
    return;
  }
  if (c == '\t') {
    g->x += 4 * cell;
    return;
  }
  if (c < 32 || c > 126) {
    return;
  }
  if (g->x + cell > g->w) {
    g->x = 0;
    g->y += line;
  }
  if (g->y > g->h - line) {
    return;
  }
#ifdef LAST_VIDEO_SIZE
  if (g->maxy != 0 && g->y + 12 * SCALE > g->maxy) {
    return;
  }
#endif
  u64 glyph = gFont[c - 32];
  u32 top = (u32)(glyph >> 32), bottom = (u32)glyph;
  for (row = 0; row < 12; row++) {
    u32 data = (row < 6) ? (top >> (row * 5)) : (bottom >> ((row - 6) * 5));
    for (col = 0; col < 5; col++) {
      if ((data >> col) & 1) {
        for (dy = 0; dy < SCALE; dy++) {
          for (dx = 0; dx < SCALE; dx++) {
            *(volatile u32 *)(g->base + (u64)(g->y + row * SCALE + dy) * g->rb + (u64)(g->x + col * SCALE + dx) * 4) = 0xFFFFFFFFu;
          }
        }
      }
    }
  }
  g->x += cell;
}

/* ---- boot console -------------------------------------------------------
 *
 * The kernel's own video console returns before it draws: vcputc_options loads
 * two flags (gc_enabled and the progress state) and bails out when they are
 * clear, so every kprintf byte disappears. Rather than reconstruct that state
 * machine, the patch script branches vcputc_options here and this routine draws
 * the characters itself, with the same font the panic screen uses.
 *
 * Two constraints shape the code:
 *   - the blob lives in the kernel's read-only text, so there is no writable
 *     global to keep a cursor in. The cursor lives in the framebuffer instead:
 *     the last row's last three pixels hold a magic, the column and the row,
 *     and the last text line is never drawn into, so a glyph cannot erase it.
 *   - it is called from every context that can kprintf, including while a
 *     panic is being formatted, so it must not call back into the console and
 *     must give up as soon as the panic screen has claimed the screen.
 */
#define CONS_MAGIC 0x534E4F43u          /* "CONS" -- kernel log cursor */
#define USER_MAGIC 0x55534552u          /* "USER" -- userspace write(1) cursor */
#define CONS_CELL  (5 * SCALE)          /* glyph width in pixels */
#define CONS_LINE  (14 * SCALE)         /* row pitch in pixels */
#define CONS_GLYPH (12 * SCALE)
#define CONS_SPLIT_PCT 55               /* kernel log gets the top 55% */

static int panic_drew (u8 *base, u32 rb, u32 h)
{
  u32 lim = fb_rows (base, rb, h);
  volatile u32 *mark;

  /* R107: the marker used to sit in the panel's last row, which is past the
   * end of the kernel's mapping of the frame buffer -- the read there is what
   * turned every panic into a second panic.  It lives in the last row the
   * mapping actually covers now. */
  if (lim == 0) {
    return 0;
  }
  mark = (volatile u32 *)(base + (u64)(lim - 1) * rb);
  return mark[0] == 0xC0FFEE11u && mark[1] == 0x5CEEDA7Au;
}

/* One cell: background and glyph in a single pass, so a character replaces
 * whatever was there before it. */
static void cell (u8 *base, u32 rb, u32 x, u32 y, u8 c)
{
  u64 glyph = gFont[(u32)c - 32];
  u32 top = (u32)(glyph >> 32), bottom = (u32)glyph;
  u32 row, col, dy, dx;

  /* R222: no panel, no drawing. */
  if (base == 0 || rb == 0) {
    return;
  }
  for (row = 0; row < 12; row++) {
    u32 data = (row < 6) ? (top >> (row * 5)) : (bottom >> ((row - 6) * 5));
    for (col = 0; col < 5; col++) {
      u32 lit = (data >> col) & 1;
      for (dy = 0; dy < SCALE; dy++) {
        for (dx = 0; dx < SCALE; dx++) {
          u64 off = (u64)(y + row * SCALE + dy) * rb
                  + (u64)(x + col * SCALE + dx) * 4;

          /* R222: stay inside the mapping.  The panel's last rows are not
           * always addressable, and a store past the end is a store into
           * whatever the next mapping happens to be. */
          if (off + 4u > FB_MAPSIZE) {
            continue;
          }
          *(volatile u32 *)(base + off) = lit ? 0xFFFFFFFFu : 0;
        }
      }
    }
  }
}

/* Text at a cell the caller names, with no state of its own: the console's
 * cursor lives in the framebuffer and its zone arithmetic is the part that
 * aborted in R81, so a bring-up probe must not borrow it. Returns 0 when it
 * drew, and a small code when it refused -- vc_info is checked before use
 * rather than trusted. */
static u32 tp_text (u32 cx, u32 cy, const char *s)
{
  volatile struct vc_info *v = (volatile struct vc_info *)VINFO;
  u8 *base;
  u32 rb, w, h, x, y;
#ifdef LAST_VIDEO_SIZE
  u32 maxy = 0;                         /* last pixel row the drawing may touch */
#endif

  if (v == 0) {
    return 1;
  }
  base = (u8 *)fb_base ();
  rb = v->v_rowbytes;
  w = v->v_width;
  h = v->v_height;
  if (base == 0 || v->v_depth != 32u || w < 64u || h < CONS_LINE + CONS_GLYPH
      || (u64)rb < (u64)w * 4u) {
    return 2;
  }
  x = cx * CONS_CELL;
  y = cy * CONS_LINE;
  if (x + CONS_CELL > w || y + CONS_GLYPH > h) {
    return 3;
  }
  /* R105: the drawing stops at the end of the kernel's mapping of the frame
   * buffer.  R104 died in the store below, four bytes into a run whose two
   * previous stores had worked. */
  maxy = fb_rows (base, rb, h);
  if (y + CONS_GLYPH > maxy) {
    return 4;
  }
  while (*s != 0) {
    if (x + CONS_CELL > w) {
      break;
    }
    cell (base, rb, x, y, (u8)*s);
    s++;
    x += CONS_CELL + SCALE;          /* glyph plus its one-pixel gap */
  }
  return 0;
}

/* Next row, wrapping to this zone's first row instead of scrolling: no memmove
 * of a 10 MB framebuffer per line, and the newest screenful of each zone is
 * always what is on screen. */
static u32 zone_next (u8 *base, u32 rb, u32 w, u32 y, u32 y0, u32 y1)
{
  (void)base;
  (void)rb;
  (void)w;
  y += CONS_LINE;
  if (y + CONS_GLYPH > y1) {
    y = y0;
  }
  return y;
}

/* Two zones, because two writers share this screen and they were stepping on
 * each other: every kprintf byte lands in the top zone, every userspace
 * write(1) byte in the bottom one. They keep separate cursors, so neither can
 * move the other's text, and each zone wraps inside its own band instead of
 * scrolling.
 *
 * Each cursor lives in the framebuffer (no writable globals allowed here): the
 * last row's final six pixels hold two magics with their column and row.
 *   zone 0: pixels w-3, w-2, w-1   zone 1: pixels w-6, w-5, w-4
 * The last text row is never drawn into, so a glyph cannot erase a cursor. */
static void cons_putc_zone (char ch, u32 zone)
{
  volatile struct vc_info *v = (volatile struct vc_info *)VINFO;
  u8 *base;
  u32 rb, w, h;
  u32 x, y, i, rows, split, y0, y1, magic, lim;
  u32 *st;
  u8 c = (u8)ch;

  fb_lazy_map ();             /* map the GOP buffer ourselves if the kernel has not */
  base = (u8 *)fb_base ();
  rb = v->v_rowbytes;
  w = v->v_width;
  h = v->v_height;

  if (base == 0 || v->v_depth != 32 || w < 64 || h < 4 * CONS_LINE
      || (u64)rb < (u64)w * 4u) {
    return;
  }
  if (panic_drew (base, rb, h)) {
    return;
  }

  /* R107: the panel reports more rows than the kernel's mapping of it
   * covers, and the cursor used to live in the panel's last row -- past the
   * end of the mapping.  The read and the write of the cursor there took the
   * kernel down, so the cursor now lives in the last row the mapping reaches
   * and every zone is sized against that, not against the panel. */
  lim = fb_rows (base, rb, h);
  if (lim < CONS_LINE + CONS_GLYPH) {
    return;
  }

  rows = lim / CONS_LINE;
  split = (rows * CONS_SPLIT_PCT / 100) * CONS_LINE;
  if (zone == 0) {
    /* R177: the top of the panel is behind the phone's notch and the punch
     * hole, so the first few lines of the kernel log were never readable.
     * R178: the log also has to start below the stage squares on row 170,
     * or the first line of kernel output wipes out the marks that say how
     * far the boot got.  Seven rows down clears both. */
    /* R225: the top of zone 0 moves down.  `fastboot boot` does not clear
     * the frame buffer, so every block an earlier round painted is still
     * there: R219's regression sites sit on rows 378 and 518, and R220's
     * on row 640, and they land in the middle of the log and cut every
     * line in two.  Nothing can erase them -- they are baked into the
     * panel -- so the log moves out of their way instead. */
    /* R227: one row further down.  The diagnostic ladder moved to row 600
     * (it has to stay inside the 2 x 2 MiB the bootloader's identity block
     * covers over the panel), and the ladder is 40 rows tall, so zone 0 has
     * to start below row 640 or the ladder paints over the first line of
     * kernel output.  16 * CONS_LINE = 672. */
    y0 = 16u * CONS_LINE;
    y1 = split;
    magic = CONS_MAGIC;
  } else {
    y0 = split + 6;                 /* below the separator rule */
    y1 = (rows - 1) * CONS_LINE;    /* last row is the cursor's */
    magic = USER_MAGIC;
  }
  if (y1 <= y0 + CONS_GLYPH) {
    return;
  }

  st = (u32 *)(base + (u64)(lim - 1) * rb) + (w - 3 - 3 * zone);
  if (st[0] != magic) {
    st[0] = magic;
    st[1] = 0;
    st[2] = y0;
    if (zone == 0) {
      /* nio: the panel keeps whatever the previous boot wrote, and that is
       * what made the last few photos unreadable -- two boots interleaved in
       * one band, with no way to tell which line came from which.  The first
       * byte of this boot wipes the whole log zone. */
      u32 yy, px;
      for (yy = y0; yy < y1; yy++) {
        u32 *row = (u32 *)(base + (u64)yy * rb);
        for (px = 0; px < w; px++) {
          row[px] = 0;
        }
      }
    }
    if (zone == 0) {
      /* First byte we ever see: leave a red bar in the second row. Its presence
       * without text means the routine runs but the glyph path does not. */
      for (i = 0; i < 8 * CONS_CELL && i < w; i++) {
        *(volatile u32 *)(base + (u64)rb + (u64)i * 4) = 0x00D00000u;
      }
    } else {
      /* Mark the boundary once, so a glance tells the two zones apart. */
      for (i = 0; i < w; i++) {
        *(volatile u32 *)(base + (u64)split * rb + (u64)i * 4) = 0x00505050u;
        *(volatile u32 *)(base + (u64)(split + 1) * rb + (u64)i * 4) = 0x00505050u;
      }
    }
  }
  x = st[1];
  y = st[2];
  /* Overflow-free range checks: `y + CONS_GLYPH > h` passes for a y near
   * UINT_MAX because the sum wraps, and R81 died in cell() on exactly such a
   * coordinate (far=0x188). Compare against the top of the zone instead. */
  if (x > w - CONS_CELL || y < y0 || y > y1 - CONS_GLYPH) {
    x = 0;
    y = y0;
  }

  if (c == '\r') {
    st[1] = 0;
    return;
  }
  if (c == '\n') {
    /* nio: blank the rest of the line.  A shorter line used to leave the tail
     * of a longer one behind, so a photo showed two messages sharing a row
     * and the log could not be read. */
    u32 yy, px;
    for (yy = y; yy < y + CONS_GLYPH && yy < y1; yy++) {
      u32 *row = (u32 *)(base + (u64)yy * rb);
      for (px = x; px < w; px++) {
        row[px] = 0;
      }
    }
    /* nio: stamp the line number on the line that just ended, after the blank
     * above (a stamp drawn on the *next* line would be wiped by that line's own
     * blank when it ends).  The band wraps, so a photo cannot tell which row is
     * newest by position -- but the highest number on the panel is always the
     * last line finished. */
    {
      u32 *lc = (u32 *)(base + (u64)(lim - 1) * rb);
      u32 n, d;
      if (lc[0] != 0x4C4E4F43u) {          /* "CNOL" */
        lc[0] = 0x4C4E4F43u;
        lc[1] = 0;
      }
      lc[1]++;
      n = lc[1] % 10000u;
      for (d = 0; d < 4; d++) {
        u32 digit = (n / (d == 0 ? 1000u : d == 1 ? 100u : d == 2 ? 10u : 1u)) % 10u;
        cell (base, rb, w - (4 - d) * CONS_CELL - CONS_CELL / 2, y,
              (u8)('0' + digit));
      }
    }
    st[1] = 0;
    st[2] = zone_next (base, rb, w, y, y0, y1);
    return;
  }
  if (c < 32 || c > 126) {
    return;
  }
  if (x + CONS_CELL > w) {
    x = 0;
    y = zone_next (base, rb, w, y, y0, y1);
  }
  cell (base, rb, x, y, c);
  st[1] = x + CONS_CELL;
  st[2] = y;
}

/* ---- entry points the kernel is redirected to ---------------------------
 *
 * The kernel's own call sites are patched to come here instead.  Each one
 * paints its stage square and then does the original work, so the boot
 * behaves exactly as before and only leaves a mark behind.
 *
 *   blob_stage1  wraps arm_vm_init(): after it returns the VM is up, so the
 *                framebuffer can be mapped for the first time.
 *   blob_stage2  wraps PE_create_console(): after it returns, vinfo either
 *                holds the kernel's own mapping (stage 3, magenta) or not
 *                (stage 2, blue) -- in which case the blob maps it itself.
 *   blob_stage4  wraps PE_init_printf(): from here on the kernel's console
 *                output goes through this blob, so a kprintf() is the
 *                proof of life that the stage squares cannot give.
 */
#if defined(ARM_VM_INIT)
__attribute__((used)) void blob_stage1 (u64 xmaxmem, void *args)
{
  ((void (*)(u64, void *))ARM_VM_INIT)(xmaxmem, args);
  stage_mark (1);
}
#endif

#if defined(PE_INIT_PRINTF)
__attribute__((used)) void blob_stage4 (int foo)
{
  ((void (*)(int))PE_INIT_PRINTF)(foo);
  stage_mark (4);
}
#endif

#if defined(PE_CREATE_CONSOLE)
__attribute__((used)) void blob_stage2 (void)
{
  volatile struct vc_info *v = (volatile struct vc_info *)VINFO;
  u64 mapped;

  ((void (*)(void))PE_CREATE_CONSOLE)();
  mapped = (u64)v->v_baseaddr;
  stage_mark (mapped != 0 ? 3 : 2);
}
#endif

/* Matches struct console_ops.putc: void (*)(char, bool). Kernel log goes to the
 * top zone. */
__attribute__((used)) void console_putc (char ch, unsigned int poll)
{
  (void)poll;
  cons_putc_zone (ch, 0);
}

/* ---- R187: a console that works before initialize_screen() --------------
 *
 * Everything the kernel printed before arm_vm_init() used to go nowhere:
 * console_putc() draws through vinfo, and vinfo is only filled in by
 * initialize_screen() near the end of arm_init().  But the entry probe leaves
 * two 2 MiB identity blocks over the panel at 0x9C000000, so until
 * arm_vm_init() swaps the translation tables the frame buffer is writable at
 * its physical address with the geometry DarwinBoot reported.  That window is
 * exactly where the boot dies now (cpu_init -> do_cacheid), so this variant
 * draws there and never looks at vinfo.
 *
 * The zone is rows 250..690: below the version bars at row 170 and above the
 * two ladders at rows 700/760.  Ten lines at SCALE 3.
 *
 * Once arm_vm_init() has run the identity blocks are gone and at s1e1r
 * reports a translation fault for 0x9C000000, so this goes quiet again; the
 * normal path takes over as soon as vinfo is filled in. */
static u32 va_mapped (u64 a)
{
  u64 par;
  __asm__ volatile ("at s1e1r, %1; isb; mrs %0, par_el1"
                    : "=r" (par) : "r" (a) : "memory");
  return (u32)(par & 1u) == 0u;
}

/* R229: can this address actually be read?
 *
 * PAR_EL1 says more than va_mapped() does:
 *
 *   bit 0   F   1 = the translation faulted
 *   bit 10  AF  1 = the access is permitted and the page is really there
 *   bit 11  nG  the address is in the lower (user) half
 *   bits[51:12]  the output physical address
 *   bits[63:56]  the attributes
 *
 * F == 0 alone is not enough.  A page whose mapping exists but whose
 * physical page is not there translates perfectly well, so F is 0, and
 * reading it is a data abort.  That is exactly what __bcopyin() does to the
 * kernel when it copies a user buffer.
 *
 * The old test looked at bits[63:60], which are the memory type: 0xE is
 * Device, and 0x0 is Normal.  The attributes of an ordinary kernel or user
 * page are 0x00, so "the address is normal memory" was never true and the
 * R228 fallback branch never ran -- which is why R228 behaved exactly like
 * R227.
 *
 * R230: the query is gone.  arm_vm_init removes TTBR0, so at s1e1r can only
 * see whatever table the kernel left there, and that table does not have the
 * user half of the address space in it.  Every user address comes back
 * faulting, which is what R229's 'U' was reporting.
 */
/* R230: readable() below now trusts the kernel's own map and does not need
 * the query, so va_readable() has no callers left and is not built. */

#define IDENT_Y0  250u
#define IDENT_Y1  590u

/* R189: the diagnostic ladder.  Five 40 x 40 squares on panel row 640, at
 * x = 40, 130, 220, 310, 400, painted by the blob itself with raw stores and
 * no guard of any kind.  R188 redirected _kprintf's first instruction to
 * blob_printf and the panel stayed exactly as it was, so the question is no
 * longer "does kprintf hang" but "how far into blob_printf did it get".
 *
 *   M0 magenta  blob_printf entered, and at s1e1r says 0x9C000000 translates
 *   M0 red      blob_printf entered, and at s1e1r says it does not
 *   M1 cyan     format pointer is not NULL
 *   M2 yellow   recursion guard is clear
 *   M3 green    ident_out reached its first cell (pixels actually written)
 *   M4 blue     the whole format string was walked
 *
 * Row 640 sits below the text zone (which now wraps at 590) and above the two
 * ladders at rows 700/760, so nothing overwrites it. */
/* R223: the ladder was on row 640, which is inside the kernel log's zone 0
 * (zone 0 runs from 7 * CONS_LINE = 294 down to split = 1386).  It painted
 * 40-pixel colour blocks straight through the log text, and R222's screen
 * came out with the log lines cut in half where the blocks landed -- the
 * two halves read as if they were different lines.  Row 700 is below the
 * part of the log a camera pointed at the top of the phone can see, so the
 * ladder no longer sits on top of anything that matters. */
/* R225: row 700 is inside zone 0 (the log runs from row 630 to row 1386
 * now), so the ladder painted its colours straight through the text.
 * Row 1400 is the first row of the lower half of the panel. */
/* R227: row 1400 was fatal, and the way it was fatal is worth writing down.
 * The ladder is painted by blob_vprintf(), and blob_vprintf() is the very
 * first thing every kernel printf goes through -- it calls diag(0) before it
 * looks at the format string.  So the ladder's row decides whether the
 * kernel can print at all.
 *
 * The panel is 2520 rows tall, but until PE_create_console() publishes the
 * kernel's own mapping there is only ONE route to it: the bootloader's
 * identity block over the panel's physical address, and that block is two
 * 2 MiB entries -- rows 0..969, nothing beyond.  A ladder on row 1400 is a
 * store 6,048,000 bytes into a 4,194,304-byte window: a store into a hole.
 * On ARM64 that is a data abort, and a data abort inside the first printf of
 * the boot is a kernel that never gets past arm_vm_init.
 *
 * That is exactly what R225 and R226 did, and the screen proved it: the
 * bootloader's own text was on the panel, the kernel had printed not one
 * line, and the stage squares (K1/K3/K4) that mark arm_vm_init's return,
 * PE_create_console and PE_init_printf were all dark.
 *
 * Row 600 is inside the identity window (600 * 4320 = 2,592,000), clear of
 * the ident text (250..590) and clear of zone 0 (which starts at 672), and
 * it is on the panel in the recordings -- the camera sees rows 0..1260.
 */
#define DIAG_ROW  600u
#define DIAG_PITCH 90u

/* R220: blob_xbase and blob_first used to be static variables here.  They
 * are now frame buffer state -- see the st() block above: the blob lives in
 * a read-only segment and cannot keep writable globals of its own. */

static void diag (u32 slot, u32 colour)
{
  u64 base = fb_base ();
  volatile u32 *p;
  u32 r, c;

  /* R221: no panel, no ladder. */
  if (base == 0) {
    return;
  }
  /* R227: the ladder is drawn from the first line of blob_vprintf(), so a
   * ladder row the panel cannot reach takes the kernel down before it has
   * printed anything.  The identity block that stands in for the panel until
   * PE_create_console() runs covers 2 x 2 MiB -- rows 0..969 -- and nothing
   * beyond, so ask the hardware whether the row is there before touching it.
   * at s1e1r does not raise an exception, so this check is itself safe. */
  if (!va_mapped (base + (u64)DIAG_ROW * FB_ROWBYTES
                  + (u64)(BLOB_XBASE + slot * DIAG_PITCH) * 4u)) {
    return;
  }
  p = (volatile u32 *)(base + (u64)DIAG_ROW * FB_ROWBYTES);
  p += BLOB_XBASE + slot * DIAG_PITCH;
  for (r = 0; r < 40u; r++) {
    for (c = 0; c < 40u; c++) {
      p[(u64)r * (FB_ROWBYTES / 4u) + c] = colour;
    }
  }
}

/* R191: a 40 x 40 square at an arbitrary panel row.  Same store sequence as
 * diag(), but the row is a parameter, so the same code can prove that a given
 * row accepts writes.  Used to bracket the cell() call at the text origin. */
static void diag_at (u32 row, u32 x, u32 colour)
{
  u64 base = fb_base ();
  volatile u32 *p;
  u32 r, c;

  if (base == 0) {
    return;
  }
  /* R227: same guard as diag() -- an unmapped row is a store into a hole,
   * and a store into a hole is an abort. */
  if (!va_mapped (base + (u64)row * FB_ROWBYTES + (u64)x * 4u)) {
    return;
  }
  p = (volatile u32 *)(base + (u64)row * FB_ROWBYTES) + x;
  for (r = 0; r < 40u; r++) {
    for (c = 0; c < 40u; c++) {
      p[(u64)r * (FB_ROWBYTES / 4u) + c] = colour;
    }
  }
}

/* R220: IDENT_Y/IDENT_X used to be static variables zeroed by the loader.
 * They are frame buffer state now (see st() above): 0 still means "not
 * started yet", because st() clears them when the magic word is missing. */

static void ident_out (char ch)
{
  u64 base = fb_base ();

  /* R221: there is no panel to draw on in the window between arm_vm_init()
   * and PE_create_console(): the identity block is gone and the kernel has
   * not published its own mapping yet.  Say nothing rather than fault. */
  if (base == 0) {
    return;
  }
  /* R191: the vinfo test is gone.  The address the compiler emits for VINFO
   * decodes to 0xfffff00707abbbb8 -- not _vinfo (0xfffffff007abbc10) -- so it
   * lands in the physmap and the value it returns means nothing.  Worse, a
   * stray non-zero there silently reroutes every byte into console_putc(),
   * whose own gates drop it.  Blind writes are the reliable path: that is
   * exactly how the row 640 ladder gets on screen. */
  /* R189: the guard that called at s1e1r is gone.  R188 proved nothing gets
   * drawn with it in the way, and the entry probe demonstrably still stores
   * into 0x9C000000 at exactly this point in the boot, so blind writes are
   * the honest test.  If this faults after arm_vm_init() swaps the tables the
   * text printed before that point is still on the panel. */
  if (IDENT_Y == 0u) {
    st_set (ST_IDENT_Y, IDENT_Y0);
    st_set (ST_IDENT_X, 0u);
  }
  if (ch == '\n') {
    st_set (ST_IDENT_X, 0u);
    st_set (ST_IDENT_Y, IDENT_Y + CONS_LINE);
  } else if (ch == '\r') {
    st_set (ST_IDENT_X, 0u);
    return;
  } else if (ch == '\t') {
    st_set (ST_IDENT_X, (IDENT_X + 8u * (CONS_CELL + SCALE)) & ~31u);
  } else if ((u8)ch >= 32u && (u8)ch < 127u) {
    if (IDENT_X + CONS_CELL <= FB_COLS) {
      /* R193: M3 now means "the first character of THIS call drew", not
       * "the first character of the first line".  The R191 bracket is gone;
       * it had served its purpose. */
      if (BLOB_FIRST != 0u) {
        diag (3, 0x0000FF00u);
        st_set (ST_FIRST, 0u);
      }
      cell ((u8 *)base, FB_ROWBYTES, IDENT_X, IDENT_Y, (u8)ch);
      st_set (ST_IDENT_X, IDENT_X + CONS_CELL + SCALE);
    }
    if (IDENT_X + CONS_CELL > FB_COLS) {
      st_set (ST_IDENT_X, 0u);
      st_set (ST_IDENT_Y, IDENT_Y + CONS_LINE);
    }
  } else {
    return;
  }
  if (IDENT_Y + CONS_GLYPH > IDENT_Y1) {
    st_set (ST_IDENT_Y, IDENT_Y0);
  }
}

__attribute__((used)) void console_putc_ident (char ch, unsigned int poll)
{
  (void)poll;
  ident_out (ch);
}

/* ---- R188: the kernel's own printf, replaced ----------------------------
 *
 * R187 hooked cons_ops[0]/[1].putc and the first kprintf() in the boot (from
 * do_cacheid()) still never returned: the square planted on the `bl kprintf`
 * lit up and the one behind it did not, and not one character reached the
 * panel.  So the stall is inside kprintf() itself -- the simple-lock spin, the
 * cpu_number() call, or _doprnt_log(), which in this build is instrumented
 * with UBSAN handlers and a stack canary.  None of that is worth debugging
 * from a photograph.
 *
 * Instead _kprintf's first instruction is redirected here, so the kernel's
 * printf is replaced outright: no lock, no _doprnt_log, no console_ops.  The
 * format string is walked here and painted through ident_out(), which needs
 * nothing but the identity block the entry probe installs.
 *
 * The recursion guard is a zero-initialised static for the same reason as
 * IDENT_Y: it lives in the tail of .text and is guaranteed to start at 0. */
static void pr_uint (u64 v, u32 base, u32 upper)
{
  char tmp[24];
  u32 n = 0;
  const char *digits = upper ? "0123456789ABCDEF" : "0123456789abcdef";

  if (v == 0u) {
    ident_out ('0');
    return;
  }
  while (v != 0u) {
    tmp[n++] = digits[(u32)(v % base)];
    v /= base;
  }
  while (n != 0u) {
    ident_out (tmp[--n]);
  }
}

/* R194: the ABI seam.  The base kernel calls kprintf with the Windows ARM64
 * convention -- every vararg is an 8-byte stack slot starting at [sp] -- but
 * this blob is compiled with a target whose va_list saves x1-x7 and reads
 * them back, which is why R193 printed garbage.  A naked shim hands the C
 * body the caller's sp directly: args[0] is the first stack slot, full stop. */
__attribute__((naked, used)) void blob_printf (void)
{
  __asm__ volatile (
    "mov x1, sp\n"
    "b blob_vprintf\n"
  );
}

__attribute__((used)) void blob_vprintf (const char *fmt, const u64 *args)
{
  /* R220: busy and calls used to be function-static variables.  They are
   * frame buffer state now (see st() above) because the blob sits in a
   * read-only segment: a store into the blob's own .data faults as soon as
   * the kernel switches to the new TTBR1. */

  /* R189: record how far this function gets even if it never draws a glyph.
   * M0 doubles as the at s1e1r verdict: magenta when the walker still has
   * 0x9C000000, red when it does not.
   *
   * R220: the counter updates come after diag(0) on purpose.  diag() reads
   * the frame buffer state, so it is the first thing in this function that
   * touches the panel; keeping the counter updates behind it means the
   * earliest point at which the blob can fault is still exactly the same as
   * it was before the counters moved out of .data. */
  diag (0, va_mapped (FB_PHYS) ? 0x00FF00FFu : 0x00FF0000u);
  st_set (ST_CALLS, BLOB_CALLS + 1u);
  st_set (ST_XBASE, (BLOB_CALLS & 1u) * 460u);   /* R193: each call paints its own ladder */
  if (fmt == 0) {
    diag (1, 0x00FF0000u);
    return;
  }
  if ((u64)fmt < 0xfffffff007004000ull || (u64)fmt > 0xfffffff007c00000ull) {
    diag (1, 0x00FF0000u);
    return;
  }
  diag (1, 0x0000FFFFu);
  if (BLOB_BUSY != 0u) {
    diag (2, 0x00FF0000u);
    return;
  }
  diag (2, 0x00FFFF00u);
  st_set (ST_BUSY, 1u);
  st_set (ST_FIRST, 1u);
  /* R194: for the "cache info:" call, dump the eight raw stack slots first.
   * Whatever the layout really is, this line shows it verbatim. */
  if (fmt[0] == 'c') {
    u32 i;
    for (i = 0; i < 8u; i++) {
      ident_out ('S');
      pr_uint (i, 10u, 0u);
      ident_out ('=');
      ident_out ('0');
      ident_out ('x');
      pr_uint (args[i], 16u, 0u);
      ident_out (' ');
    }
    ident_out ('\n');
  }
  u32 n = 0;
  while (*fmt != 0) {
    char c = *fmt++;
    u32 longs = 0;
    long sv;
    u64 uv;

    if (c != '%') {
      ident_out (c);
      continue;
    }
    c = *fmt++;
    while (c == '0' || c == '-' || c == '+' || c == ' ' || c == '#') {
      c = *fmt++;
    }
    while (c >= '0' && c <= '9') {
      c = *fmt++;
    }
    if (c == '.') {
      c = *fmt++;
      while (c >= '0' && c <= '9') {
        c = *fmt++;
      }
    }
    while (c == 'l') {
      longs++;
      c = *fmt++;
    }
    if (c == 'z' || c == 'j' || c == 't') {
      longs = 2;
      c = *fmt++;
    }
    switch (c) {
    case 's': {
      /* R193: read every argument as u64.  The caller pushes all varargs as
       * 8-byte stack slots (Windows ARM64 convention -- proven by the stp
       * chain in do_cacheid), so stepping ap by 8 per argument keeps it in
       * lockstep no matter what va_arg(T) does for narrow T. */
      const char *s = (const char *)args[n++];
      if ((u64)s < 0xfffffff007004000ull || (u64)s > 0xfffffff007c00000ull) {
        s = "(bad %s)";
      }
      {
        u32 n = 0;
        while (*s != 0 && n < 96u) {
          ident_out (*s++);
          n++;
        }
      }
      break;
    }
    case 'c':
      ident_out ((char)args[n++]);
      break;
    case 'd':
    case 'i':
      sv = (long)args[n++];
      if (sv < 0) {
        ident_out ('-');
        pr_uint ((u64)(-sv), 10u, 0u);
      } else {
        pr_uint ((u64)sv, 10u, 0u);
      }
      break;
    case 'u':
      uv = args[n++];
      pr_uint (uv, 10u, 0u);
      break;
    case 'x':
      uv = args[n++];
      pr_uint (uv, 16u, 0u);
      break;
    case 'X':
      uv = args[n++];
      pr_uint (uv, 16u, 1u);
      break;
    case 'p':
      uv = args[n++];
      ident_out ('0');
      ident_out ('x');
      pr_uint (uv, 16u, 0u);
      break;
    case '%':
      ident_out ('%');
      break;
    case 0:
      ident_out ('%');
      st_set (ST_BUSY, 0u);
      return;
    default:
      ident_out ('%');
      ident_out (c);
      break;
    }
  }
  diag (4, 0x000000FFu);
  st_set (ST_BUSY, 0u);
}

/* ---- userspace graphics --------------------------------------------------
 *
 * R71 closed the exec question: copyout_probe printed err=0, ap=0x16fdffe90,
 * a0=1 and a1 pointing at the string, and setuserstack_probe got the same ap.
 * The kernel had been right all along -- the fixture was reading sp after its
 * own prologue, so it looked at unused zeroed stack. The two probes are gone.
 *
 * The same sysent[4] hook now carries pixels as well as text: write(3, cmds, n)
 * treats the buffer as six-word commands {op, colour, x, y, w, h} and fills
 * rectangles. Rectangles only, because that is all a bring-up UI needs (bands,
 * gradients, borders, and blocks standing in for glyphs) and because the pixel
 * loop then stays in the kernel, where the frame buffer is already mapped.
 *
 * write(3, 0, 0) is the query: it returns width<<32 | height, so userspace
 * never has to hardcode a panel size it cannot see.
 */
#define FB_OP_RECT 1u
#define FB_BAND    240u                 /* command bytes per copyin */

static u32 fb_fill (u8 *base, u32 rb, u32 w, u32 h,
                    u32 x0, u32 y0, u32 rw, u32 rh, u32 colour)
{
  u32 x, y;
  u64 end;

  /* Every bound is checked before the first store, and the row loop checks
   * again: R72 faulted 638 rows past the panel, so a bad y0
h pair has to be
   * stopped here rather than trusted to the clamp above it. */
  if (base == 0 || rb < w * 4u || x0 >= w || y0 >= h || rw == 0 || rh == 0) {
    return 0;
  }
  end = (u64)h * rb;
  if (rw > w - x0) {
    rw = w - x0;
  }
  if (rh > h - y0) {
    rh = h - y0;
  }
  for (y = 0; y < rh; y++) {
    u64 off = (u64)(y0 + y) * rb + (u64)x0 * 4;
    volatile u32 *row;

    if (off + (u64)rw * 4 > end) {
      break;
    }
    row = (volatile u32 *)(base + off);
    for (x = 0; x < rw; x++) {
      row[x] = colour;
    }
  }
  return rw * rh;
}

static u32 fb_exec (const u32 *c, u32 words)
{
  volatile struct vc_info *v = (volatile struct vc_info *)VINFO;
  u8 *base = (u8 *)fb_base ();
  u32 rb = v->v_rowbytes, w = v->v_width, h = v->v_height, done = 0;

  if (base == 0 || v->v_depth != 32 || w < 64 || h < 16) {
    return 0;
  }
  /* The console keeps both cursors in the last row of pixels and the panic
   * marker in the last two pixels of that row; keep them out of reach. */
  h -= 2;
  while (words >= 6) {
    if (c[0] == FB_OP_RECT) {
      fb_fill (base, rb, w, h, c[2], c[3], c[4], c[5], c[1]);
    } else if (c[0] == 0) {
      break;
    }
    c += 6;
    words -= 6;
    done++;
  }
  return done;
}


/* ---- touch bridge (R77) --------------------------------------------------
 *
 * fd 4 = the Novatek NT36672C, now driven by bit-banged SPI over four
 * GPIOs instead of the GENI serial engine.
 *
 * R76 put the GENI engine on the wire and it worked: the transport came up
 * (stage 3, no error bits) and the chip answered. What came back was the
 * wrong bytes -- and the same bytes payload/spi.c's engine path returned in
 * November: R76 read 24 19 58 54 4d .., payload's 19:10 boot read
 * 24 19 9b 74 44 ed. Byte for byte on the first two. The engine's short
 * read drops its last word in the wrong place, a defect payload already
 * found and routed around the same way: the bit-bang transport, where every
 * clock edge is ours and every byte on the wire is deterministic. payload's
 * tpbb read the true NT36672C signature 0c 00 00 72 66 03 twice in a row.
 * That is what this reproduces.
 *
 * Bit-banging needs no serial engine at all, so no SE mapping and no clock
 * gating -- TLMM is always on. That hands the blob its budget back for the
 * firmware download and the point frames, which is where the next rounds go.
 *
 * The pin roles are the ones payload proved on this board, not the ones the
 * qup13 comment guessed: MISO on 36, MOSI on 37, CLK on 38, CS on 39.
 *
 * read(4, buf, 32) copies back
 *   {magic "NVT2", trim[6], trim again[6], miso idle, irq, err(2), stage}
 * so one call shows whether the identity repeats -- payload's rule, since
 * trim is static OTP and a live firmware would rewrite it.
 */
#if defined(ML_IO_MAP) && defined(COPYOUT) && defined(ORIG_READ) && defined(COPYIN) \
    && !defined(NO_TOUCH_BRIDGE)
/* R78: the fd4 command channel needs copyin as well as copyout -- userspace
   hands the kernel a command and the kernel answers in the same buffer. */
/* R224: NO_TOUCH_BRIDGE turns the bridge off without turning the console off.
   The bridge is a large piece of code (the bit-banged SPI transport, the
   trim reader, the SMMU window bookkeeping) and the blob has to fit in the
   tail of one segment: the console half is a few hundred bytes, the bridge
   is several thousand, and a kernel that cannot hold both has to choose
   which one it wants to be able to reach.  The console half is the one
   that lets a process in EL0 be heard at all, so it wins. */
#define TP_CHANNEL   1
#endif

#if defined(TP_CHANNEL)
#define TP_MAGIC     0x4E565432u      /* "NVT2" */
#define TP_TLMM_PHYS 0x0F500000UL

/* R101: how a read gets its window.
 *
 * _ml_io_map takes the page from a permanent 8 MiB submap (io_map() with
 * unmappable=false does kmem_alloc(io_submap, KMA_PERMANENT)), and nothing
 * ever gives it back: the submap holds 2048 pages, so 2048 reads and the
 * next one hangs the kernel on a failed allocation. A poll loop of a few
 * thousand rounds (the GMU's FW_INIT_RESULT wait alone is 800) walks right
 * into that wall, which is what the R99/R100 run looked like: the screen
 * stopped at the last marker and the board never came back.
 *
 * _ml_io_map_unmappable takes the same page from the kernel map with
 * KMA_DATA, and _ml_io_unmap gives it back (pmap_remove + kmem_free), so a
 * read costs nothing once it is over. Same device mapping (VM_WIMG_IO),
 * same 4 KiB window, same access.
 *
 * The writes keep the permanent mapping on purpose: a store into a device
 * window may still be in flight when the mapping is torn down, and there
 * are only a few hundred of them. */
#if defined(ML_IO_MAP_UNMAPPABLE) && defined(ML_IO_UNMAP)
#define TP_MAP(pg)    ((u64 (*)(u64, u64, u32))ML_IO_MAP_UNMAPPABLE)((pg), 0x1000u, 0x7u)
#define TP_UNMAP(m)   ((void (*)(u64, u64))ML_IO_UNMAP)((m), 0x1000u)
#else
#define TP_MAP(pg)    ((u64 (*)(u64, u64))ML_IO_MAP)((pg), 0x1000u)
#define TP_UNMAP(m)   ((void)0)
#endif

/* bit-bang pin roles, proven by payload/spi.c tpbb on this board */
#define TP_BB_MISO   36u
#define TP_BB_MOSI   37u
#define TP_BB_CLK    38u
#define TP_BB_CS     39u
#define TP_BB_IRQ    24u
#define TP_RST       50u

/* TLMM: one 4 KB page per pin, cfg at +0 and in/out at +4 */
#define TLMM_CFG(n)  (*(volatile u32 *)(tl + (n) * 0x400u))
#define TLMM_IO(n)   (*(volatile u32 *)(tl + (n) * 0x400u + 1u))

static volatile u32 *tp_row (void)
{
  volatile struct vc_info *v = (volatile struct vc_info *)VINFO;
  u64 base = fb_base ();

  /* R222: no panel, no touch stash. */
  if (base == 0 || v->v_height == 0 || v->v_rowbytes == 0) {
    return 0;
  }
  return (volatile u32 *)(base + (u64)(v->v_height - 1) * v->v_rowbytes);
}

/* stash layout, pixels of the last row from x=2:
   0 magic | 1-2 TLMM va | 3 stage | 4 last err | 5-6 trim six bytes
   | 7 irq level */
static u32 tpx (u32 i)
{
  volatile u32 *r = tp_row ();

  /* R222: no panel means no stash. */
  if (r == 0) {
    return 0u;
  }
  return (r[2 + i] ^ 0x5A5A0000u);
}

static void tpx_set (u32 i, u32 v)
{
  volatile u32 *r = tp_row ();

  /* R222: no panel means no stash. */
  if (r == 0) {
    return;
  }
  r[2 + i] = v ^ 0x5A5A0000u;
}

static u64 tpx64 (u32 i)
{
  return (u64)tpx (i) | ((u64)tpx (i + 1) << 32);
}

static void tpx64_set (u32 i, u64 v)
{
  tpx_set (i, (u32)v);
  tpx_set (i + 1, (u32)(v >> 32));
}

static u64 tp_cntfrq (void)
{
  u64 v;
  __asm__ volatile ("mrs %0, cntfrq_el0" : "=r" (v));
  return v;
}

static u64 tp_cntpct (void)
{
  u64 v;
  __asm__ volatile ("isb\n\tmrs %0, cntpct_el0" : "=r" (v));
  return v;
}

static void tp_mdelay (u32 ms)
{
  u64 f = tp_cntfrq (), t = tp_cntpct ();
  while (tp_cntpct () - t < f * ms / 1000u) {
  }
}

/* the mapped TLMM window, read back out of the stash */
static volatile u32 *tp_tlmm (void)
{
  return (volatile u32 *)tpx64 (1);
}

/* ---- bit-bang SPI -------------------------------------------------------
 *
 * Mode 0: the clock idles low, the chip samples MOSI on the rising edge,
 * and MISO is sampled while the clock is high. ~1.6 us per half bit puts
 * the line at roughly 300 kHz, slow enough for pull-up-terminated wires
 * and fast enough that a 10-byte frame still takes well under a
 * millisecond.
 */
static void bb_half (void)
{
  u64 f = tp_cntfrq (), t = tp_cntpct ();

  while (tp_cntpct () - t < f * 16u / 10000000u) {   /* 1.6 us */
  }
}

static void bb_level (volatile u32 *tl, u32 gpio, u32 on)
{
  u32 r = TLMM_IO (gpio);

  TLMM_IO (gpio) = (r & ~2u) | (on != 0u ? 2u : 0u);
}

static u32 bb_sample (volatile u32 *tl, u32 gpio)
{
  return TLMM_IO (gpio) & 1u;
}

/* one byte, both directions: MOSI out, MISO sampled at the end of the
   high phase */
static u8 bb_send_byte (volatile u32 *tl, u8 b)
{
  u8 r = 0;
  int bit;

  for (bit = 7; bit >= 0; bit--) {
    bb_level (tl, TP_BB_MOSI, (u32)((b >> bit) & 1u));
    bb_half ();
    bb_level (tl, TP_BB_CLK, 1);     /* rising edge: the chip samples mosi */
    bb_half ();
    r = (u8)((r << 1) | (bb_sample (tl, TP_BB_MISO) != 0u ? 1u : 0u));
    bb_level (tl, TP_BB_CLK, 0);
  }
  return r;
}

/* one CS frame: tx bytes out, rx bytes in (rx may be null) */
static void bb_frame (volatile u32 *tl, const u8 *tx, u8 *rx, u32 n)
{
  u32 i;

  bb_level (tl, TP_BB_CS, 0);        /* select */
  bb_half ();
  for (i = 0; i < n; i++) {
    u8 r = bb_send_byte (tl, tx[i]);

    if (rx != 0) {
      rx[i] = r;
    }
  }
  bb_level (tl, TP_BB_MOSI, 0);
  bb_half ();
  bb_level (tl, TP_BB_CS, 1);        /* deassert: the chip flushes its shiftreg */
  bb_half ();
}

/* vendor nvt_set_page: ONE cs-low frame of three bytes. The chip resets
   its shift register on every cs edge, so three separate one-byte frames
   would be three invalid commands and the page select would never land. */
static void bb_set_page (volatile u32 *tl, u32 addr)
{
  u8 b[3];

  b[0] = 0xFF;
  b[1] = (u8)(addr >> 15);
  b[2] = (u8)(addr >> 7);
  bb_frame (tl, b, 0, 3);
}

/* vendor CTP_SPI_READ, bit-banged: one CS frame of n+4 bytes
   ([addr & 0x7F] with bit7 clear = the read flag, then the answer), with
   the data starting at rx[2]. The trailing margin bytes just clock the
   chip deeper into its address space, which is harmless. */
static void bb_read (volatile u32 *tl, u32 addr, u8 *data, u32 n)
{
  u8 tx[84], rx[84];
  u32 wire = n + 4u, i;

  if (n > 80u) {
    n = 80u;
  }
  bb_set_page (tl, addr);
  tx[0] = (u8)(addr & 0x7Fu);
  for (i = 1u; i < wire; i++) {
    tx[i] = 0;
  }
  bb_frame (tl, tx, rx, wire);
  for (i = 0; i < n; i++) {
    data[i] = rx[2u + i];
  }
}

/* vendor CTP_SPI_WRITE, bit-banged: set page, then one CS frame of two
   bytes [addr | 0x80 (write flag), value]. */
static void bb_write_addr (volatile u32 *tl, u32 addr, u8 v)
{
  u8 b[2];

  bb_set_page (tl, addr);
  b[0] = (u8)((addr & 0x7Fu) | 0x80u);
  b[1] = v;
  bb_frame (tl, b, 0, 2);
}

/* vendor nvt_write_sram, bit-banged: set page, then ONE cs frame of
   [offset | write-flag, n payload bytes]. The chip auto-increments across
   page boundaries inside the frame, so a fresh set_page per chunk is only
   needed because the frame is re-opened for every chunk. */
static void bb_write_sram (volatile u32 *tl, u32 addr, const u8 *data, u32 n)
{
  u32 i;

  bb_set_page (tl, addr);
  bb_level (tl, TP_BB_CS, 0);
  bb_half ();
  (void)bb_send_byte (tl, (u8)((addr & 0x7Fu) | 0x80u));
  for (i = 0; i < n; i++) {
    (void)bb_send_byte (tl, data[i]);
  }
  bb_level (tl, TP_BB_MOSI, 0);
  bb_half ();
  bb_level (tl, TP_BB_CS, 1);
  bb_half ();
}

/* vendor nvt_set_bld_crc_bank, hw_crc==2 form (3-byte length). One set_page,
   then three write frames inside the same 0x3F000 page: the destination SRAM
   address (3B), the length (3B) and the golden checksum (4B). */
static void bb_crc_bank (volatile u32 *tl, u32 des_addr, u32 sram,
                         u32 len_addr, u32 size, u32 g_ck_addr, u32 crc)
{
  u8 b[5];

  bb_set_page (tl, des_addr);
  b[0] = (u8)((des_addr & 0x7Fu) | 0x80u);
  b[1] = (u8)(sram & 0xFFu);
  b[2] = (u8)((sram >> 8) & 0xFFu);
  b[3] = (u8)((sram >> 16) & 0xFFu);
  bb_frame (tl, b, 0, 4);
  b[0] = (u8)((len_addr & 0x7Fu) | 0x80u);
  b[1] = (u8)(size & 0xFFu);
  b[2] = (u8)((size >> 8) & 0xFFu);
  b[3] = (u8)((size >> 16) & 0xFFu);
  bb_frame (tl, b, 0, 4);
  b[0] = (u8)((g_ck_addr & 0x7Fu) | 0x80u);
  b[1] = (u8)(crc & 0xFFu);
  b[2] = (u8)((crc >> 8) & 0xFFu);
  b[3] = (u8)((crc >> 16) & 0xFFu);
  b[4] = (u8)((crc >> 24) & 0xFFu);
  bb_frame (tl, b, 0, 5);
}

/* ---- fd4 command channel (R78) -------------------------------------------
 *
 * write(4, buf, n) is a small RPC into the touch bridge:
 *
 *   buf[0]  u32 op
 *   buf[1]  u32 addr
 *   buf[2]  u32 len
 *   buf[3..] len payload bytes
 *
 * The answer comes back into the same buffer: 128 bytes of result written
 * over the command header, once the payload has been consumed. Nothing is
 * kept between calls -- the blob has no writable globals (the kernel's
 * __TEXT_EXEC is read only), so every operation has to be self contained.
 *
 *   op 1  push len bytes into the chip's SRAM at addr
 *   op 2  write one register (addr, payload[0])
 *   op 3  bootloader reset (SWRST 0x69) and SPI_RD_FAST off
 *   op 4  the whole post-download sequence: BLD CRC banks, bld crc enable,
 *         fw crc enable, boot ready, poll the fw reset status, read fw info
 *   op 5  read len bytes of registers at addr
 *   op 6  sample the event buffer until it changes (addr = budget in ms)
 */
#define TP_OP_SRAM   1u
#define TP_OP_REGW   2u
#define TP_OP_RESET  3u
#define TP_OP_BOOT   4u
#define TP_OP_REGR   5u
/* R84: two primitives the GPU bring-up needs and the console cannot give it.
 * TP_OP_TEXT draws at a cell the caller names and keeps no state; TP_OP_MR
 * reads device registers once, read only, and reports a failed map instead
 * of faulting. Neither shares anything with cons_putc_zone, whose cursor
 * path took the R81 data abort. */
#define TP_OP_MR     7u
#define TP_OP_TEXT   8u
/* R86: the same page mapping as op 7, but a 32-bit store. The GPU bring-up
 * is a sequence of read-modify-writes (branch enables, GDSC collapse), and
 * without a write primitive the ladder cannot leave the observation stage. */
#define TP_OP_MW     9u
/* R90: the GMU's instruction memory is 15 KB, and op 9 costs one fd4 round
 * trip per dword. This writes a run of dwords that stays inside one page:
 * `len` is a dword count, the words follow the header. */
#define TP_OP_MWB    10u
/* R101: the GMU's SMMU context needs a real page table, and a page table
 * needs physical pages. EL0 cannot allocate them, so the blob does it:
 * op 11 allocates one 4 KiB kernel page, optionally fills it with the
 * payload that follows the header, and answers with the page's physical
 * address. The caller sends the table level that only becomes known once
 * the level below it has been allocated, so the payload and the address
 * come out of the same call. */
#define TP_OP_ALLOC  11u
/* R101: the page tables of the GMU's SMMU context live in kernel memory and
 * the SMMU walks them out of DRAM, while the CPU writes them through its own
 * cached alias. op 12 writes a run of dwords into such a page through the
 * kernel's alias and cleans the cache, so both views agree. The address is 64
 * bits and comes first in the payload: a kernel virtual address does not fit
 * in 32 bits, and neither does a physical address above 4 GB. The words
 * written come back in the result, read back from the page. */
#define TP_OP_WVA    12u
#define TP_OP_WAIT   6u

/* R101: the kernel map, its allocator and the virtual-to-physical walk.
 * The two struct shapes are copied from osfmk/vm/vm_kern.h so that the
 * call matches the ABI the kernel was built with: kmem_return_t is an
 * eight byte status word followed by the address at offset 8, and
 * kmem_guard_t is {u16 tag, u16 hash, u32 bits}. */
#if defined(KERNEL_MAP) && defined(KMEM_ALLOC) && defined(KVTOPHYS)
typedef struct {
  int ret;
  u64 address;
} tp_kmem_return_t;
typedef struct {
  unsigned short tag;
  unsigned short hash;
  unsigned int bits;
} tp_kmem_guard_t;
#endif

#define TP_RES_WORDS 40u                    /* 160 bytes of result */
#define TP_SRAM_CHUNK 512u                  /* bytes per SPI frame */

#define TP_R_MAGIC   0u
#define TP_R_STATUS  1u
#define TP_R_OP      2u
#define TP_R_ALIVE   3u
#define TP_R_VER     4u
#define TP_R_XNUM    5u
#define TP_R_YNUM    6u
#define TP_R_ABSX    7u
#define TP_R_ABSY    8u
#define TP_R_POLL    9u
#define TP_R_POLLC   10u
#define TP_R_BLDCRC  11u
#define TP_R_BYTES   12u
#define TP_R_IRQ     13u                   /* irq line at entry (op 6) */
#define TP_R_IRQ2    14u                   /* irq line when the frame changed */
#define TP_R_RAW     16u                   /* 16 words of raw bytes */

static u32 tp_ensure_init (void);       /* defined below, with the state stash */

/* R101: the SMMU reads the page tables from DRAM while the CPU writes them
 * through its own cached alias, so the two views have to agree: every write
 * to a table page is followed by a clean of that page's cache lines. dc civac
 * pushes the data to memory and drops the lines, so a device walk and a later
 * CPU read both see what was written. */
static void tp_clean (u64 va, u64 bytes)
{
  u64 a = va & ~63ULL, e = (va + bytes + 63ULL) & ~63ULL;

  for (; a < e; a += 64ULL) {
    __asm__ volatile ("dc civac, %0" :: "r" (a) : "memory");
  }
  __asm__ volatile ("dsb ish" ::: "memory");
}

static int tp_fd4 (u64 src, u64 n, void *retval)
{
  u32 res[TP_RES_WORDS], hdr[3];
  u8 tmp[TP_SRAM_CHUNK];
  volatile u32 *tl;
  u32 op, addr, len, done = 0, i, err;

  if (n < TP_RES_WORDS * 4u) {
    *(u64 *)retval = (u64)-1;
    return 22;                                  /* EINVAL */
  }
  if (((int (*)(u64, void *, u64))COPYIN)(src, hdr, 12) != 0) {
    *(u64 *)retval = (u64)-1;
    return 14;                                  /* EFAULT */
  }
  op = hdr[0];
  addr = hdr[1];
  len = hdr[2];
  for (i = 0; i < TP_RES_WORDS; i++) {
    res[i] = 0;
  }
  res[TP_R_MAGIC] = 0x3354564Eu;                /* "NVT3" */
  res[TP_R_OP] = op;

  /* R85: op 7 and op 8 never touch the touch chip, so they must not bring
   * its transport up. That keeps a register probe independent of the panel
   * and removes one whole subsystem from the experiment. */
  if (op == TP_OP_MR || op == TP_OP_TEXT || op == TP_OP_MW || op == TP_OP_MWB ||
      op == TP_OP_ALLOC || op == TP_OP_WVA) {
    err = 0u;
  } else {
    err = tp_ensure_init ();
  }
  res[TP_R_STATUS] = err;
  if (err == 0) {
    tl = tp_tlmm ();
    if (op == TP_OP_RESET) {
      bb_write_addr (tl, 0x3F0FEu, 0x69u);      /* bootloader reset */
      tp_mdelay (35);
      bb_write_addr (tl, 0x3F310u, 0x00u);      /* spi fast read off */
    } else if (op == TP_OP_SRAM) {
      while (done < len) {
        u32 chunk = len - done;
        u32 room;

        if (chunk > TP_SRAM_CHUNK) {
          chunk = TP_SRAM_CHUNK;
        }
        /* The chip's offset is 15 bits wide, so a frame may not run past the
           end of its 32 KB page or the auto-increment would wrap inside the
           frame. Split there, exactly like payload's 8 KB chunks. */
        room = 0x8000u - ((addr + done) & 0x7FFFu);
        if (chunk > room) {
          chunk = room;
        }
        if (((int (*)(u64, void *, u64))COPYIN)(src + 12 + done, tmp, chunk) != 0) {
          res[TP_R_STATUS] = 14;
          break;
        }
        bb_write_sram (tl, addr + done, tmp, chunk);
        done += chunk;
      }
      res[TP_R_BYTES] = done;
    } else if (op == TP_OP_MR) {
      /* read `len` dwords of device registers at `addr`, each in its own
         result word so the caller reads back exactly what the bus returned */
      u32 j, pg = addr & ~0xFFFu;
      u64 m;

      if (len == 0u) {
        res[TP_R_STATUS] = 6;
      } else {
        /* Two independent limits, both unsigned-safe: the result block only
           has TP_RES_WORDS - TP_R_RAW words to put values in, and the frame
           must not run past the mapped page. R84 clamped only the second one
           and computed it as 1024u - off, which underflows to ~4e9 whenever
           off > 1024 -- a write of four billion dwords into a 40-word array
           on the kernel stack. */
        if (len > TP_RES_WORDS - TP_R_RAW) {
          len = TP_RES_WORDS - TP_R_RAW;
        }
        if (((addr & 0xFFFu) >> 2) + len > 1024u) {
          len = 1024u - ((addr & 0xFFFu) >> 2);
        }
        m = TP_MAP(pg);
        if (m == 0) {
          res[TP_R_STATUS] = 7;
        } else {
          for (j = 0; j < len; j++) {
            res[TP_R_RAW + j] =
              *(volatile u32 *)(m + (u64)(((addr & 0xFFFu) >> 2) + j) * 4u);
          }
          TP_UNMAP(m);
          res[TP_R_BYTES] = len;
        }
      }
    } else if (op == TP_OP_MW) {
      /* write one dword of device registers at `addr`. Read-modify-write is
         the caller's job: this primitive must stay one store wide, because a
         masked write would need a read that can fault on a gated block. */
      u32 pg = addr & ~0xFFFu;
      /* R89: the value has to be loaded as a dword. R86 through R88 stored
         `tmp[0]`, which is a u8 -- so regardless of how many bytes COPYIN
         brought in, the store took only the low byte. That is why every
         read-back showed the low byte of the intended value and nothing
         else (0x0001807f -> 0x7f, 0x00000602 -> 0x02, 0x80000ff0 -> 0xf0),
         and why R86's GDSC enable looked like it worked: 0x00222000's low
         byte is 0 and GDSCR powers on as soon as bit 0 is clear.
         R101: a 64-bit register (the SMMU's TTBR0/TTBR1) needs one 64-bit
         store, not two 32-bit ones: the register file is 64 bits wide and a
         half write is not a write of the other half. So len 2 means one
         64-bit store of the eight payload bytes, little endian. */
      u64 val = 0u;
      u64 m;

      if (len != 1u && len != 2u) {
        res[TP_R_STATUS] = 22;
      } else if (((int (*)(u64, void *, u64))COPYIN)(src + 12, &val, len * 4u) != 0) {
        res[TP_R_STATUS] = 14;
      } else if ((m = ((u64 (*)(u64, u64))ML_IO_MAP)(pg, 0x1000)) == 0) {
        res[TP_R_STATUS] = 7;
      } else {
        if (len == 1u) {
          *(volatile u32 *)(m + (u64)((addr & 0xFFFu) >> 2) * 4u) = (u32)val;
        } else {
          /* an eight byte store has to be eight byte aligned */
          if ((addr & 7u) != 0u) {
            res[TP_R_STATUS] = 22;
          } else {
            *(volatile u64 *)(m + (u64)((addr & 0xFFFu) >> 2) * 4u) = val;
          }
        }
        res[TP_R_BYTES] = len;
      }
    } else if (op == TP_OP_ALLOC) {
      /* R101: one 4 KiB kernel page, optionally filled with the payload that
         follows the header, answered with its physical address. The page
         comes out of the kernel map, so it is a real physical page an SMMU
         can translate to; the address comes from kvtophys, which walks the
         kernel's own mapping (this kernel has no SPTM, so kvtophys is the
         plain pmap walk and not a secure-world call).
         kmem_alloc_guard returns {kern_return_t, vm_address_t}: two words
         in x0 and x1, and the guard is {u16,u16,u32}, one word in x4. */
#if defined(KERNEL_MAP) && defined(KMEM_ALLOC) && defined(KVTOPHYS)
      u64 va = 0u, pa;
      u32 n = len;
      tp_kmem_return_t kr;
      tp_kmem_guard_t kg;

      if (n > 4096u) {
        n = 4096u;
      }
      kg.tag = 3u;                 /* VM_KERN_MEMORY_IOKIT, see below */
      kg.hash = 0u;
      kg.bits = 0u;
      /* R103: the guard's tag must not be VM_KERN_MEMORY_NONE (0).  The page
         this asks for is wired and shared, and vm_resident.c:1804 asserts
         !VM_PAGE_WIRED(mem) || mem->vmp_private || mem->vmp_fictitious ||
         (tag != VM_KERN_MEMORY_NONE) -- a zero tag kills the kernel there.
         The kernel's own kmem_alloc() wrapper sets .kmg_tag = tag, and
         io_map.c hands its device pages VM_KERN_MEMORY_IOKIT (3), which is
         exactly what this page is: a page a device will read. */
      /* KMEM_NOFAIL | KMEM_DATA | KMEM_ZERO: the page comes back zeroed. The
         zeroing is a cached write, so the page is cleaned below before
         anybody reads it from DRAM. */
      /* R101 fix: KERNEL_MAP is the ADDRESS of the kernel's `vm_map_t
         kernel_map` variable, not the map itself. kmem_alloc_guard wants
         the map (vm_map_t), and kmem_alloc_guard_internal asserts
         `kernel_map && map->pmap == kernel_pmap`; passing the address of
         the variable made map->pmap read whatever sits next to the
         pointer, and the kernel panicked in vm_kern.c:778. The kernel's
         own callers pass the VALUE (io_map.c: `kmem_alloc(kernel_map,
         ...)`), so the value is what has to go in: *(void **)KERNEL_MAP
         is the vm_map_t, and its pmap is kernel_pmap because kernel_map
         was created with pmap_kernel(). */
      kr = ((tp_kmem_return_t (*)(void *, u64, u64, u32, tp_kmem_guard_t))KMEM_ALLOC)
        (*(void **)KERNEL_MAP, 4096u, 0xfffu, 0x00008041u, kg);
      va = kr.address;
      if (va == 0u) {
        res[TP_R_STATUS] = 12;
      } else if (n != 0u &&
                 ((int (*)(u64, void *, u64))COPYIN)(src + 12, (void *)va, n) != 0) {
        res[TP_R_STATUS] = 14;
      } else {
        tp_clean (va, 4096u);
        pa = ((u64 (*)(u64))KVTOPHYS)(va);
        res[TP_R_RAW + 0] = (u32)pa;
        res[TP_R_RAW + 1] = (u32)(pa >> 32);
        res[TP_R_RAW + 2] = (u32)va;
        res[TP_R_RAW + 3] = (u32)(va >> 32);
        res[TP_R_RAW + 4] = n;
        res[TP_R_BYTES] = n;
      }
#else
      res[TP_R_STATUS] = 12;
#endif
    } else if (op == TP_OP_WVA) {
      /* R101: write dwords into a page of kernel memory at a byte offset,
         through the kernel's own alias, then clean the cache so that the
         SMMU's walk of the page sees the same bytes. `addr` is the offset
         inside the page, `len` the dword count; the payload is the 64 bit
         address followed by the words. The words come back in the result,
         read back from the page.
         R101: one call now carries up to 120 words, so a page of firmware
         goes in nine calls instead of forty-three. The result area holds
         only 24 words (TP_RES_WORDS minus the 16 word header), so a long
         write reads back its first 24 words and says how many it wrote.
         The run must stay inside the page: the old check only bounded the
         first word, and 4088 + 96 words ran past the end of the page. */
      u32 n = len, j, rb;
      u64 va = 0u;

      if (n > 120u) {
        n = 120u;
      }
      if (n == 0u || addr > 4096u - n * 4u) {
        res[TP_R_STATUS] = 22;
      } else if (((int (*)(u64, void *, u64))COPYIN)(src + 12, tmp, 8u + (u64)n * 4u) != 0) {
        res[TP_R_STATUS] = 14;
      } else {
        for (j = 0; j < 8u; j++) {
          va |= ((u64)tmp[j]) << (8u * j);
        }
        for (j = 0; j < n; j++) {
          u32 w = (u32)tmp[8u + j * 4u] | ((u32)tmp[9u + j * 4u] << 8) |
                  ((u32)tmp[10u + j * 4u] << 16) | ((u32)tmp[11u + j * 4u] << 24);
          *(volatile u32 *)(va + addr + (u64)j * 4u) = w;
        }
        tp_clean (va + addr, (u64)n * 4u);
        rb = n > 24u ? 24u : n;
        for (j = 0; j < rb; j++) {
          res[TP_R_RAW + j] = *(volatile u32 *)(va + addr + (u64)j * 4u);
        }
        res[TP_R_BYTES] = n;
      }
    } else if (op == TP_OP_MWB) {
      /* A run of dwords inside one page. Bytes are assembled one at a time
         because `tmp` is a u8 buffer of unknown alignment -- reading it as
         u32 would be an unaligned alias of an array the compiler may pack
         (R86's lesson was the opposite mistake: taking a byte where a dword
         was meant). */
      u32 pg = addr & ~0xFFFu;
      u32 off = (addr & 0xFFFu) >> 2, j;
      u64 m;

      if (len == 0u || len > 128u) {
        len = 128u;
      }
      if (off + len > 1024u) {
        len = 1024u - off;
      }
      if (((int (*)(u64, void *, u64))COPYIN)(src + 12, tmp, (u64)len * 4u) != 0) {
        res[TP_R_STATUS] = 14;
      } else if ((m = ((u64 (*)(u64, u64))ML_IO_MAP)(pg, 0x1000)) == 0) {
        res[TP_R_STATUS] = 7;
      } else {
        for (j = 0; j < len; j++) {
          u32 w = (u32)tmp[j * 4u] | ((u32)tmp[j * 4u + 1u] << 8) |
                  ((u32)tmp[j * 4u + 2u] << 16) | ((u32)tmp[j * 4u + 3u] << 24);
          *(volatile u32 *)(m + (u64)(off + j) * 4u) = w;
        }
        res[TP_R_BYTES] = len;
      }
    } else if (op == TP_OP_TEXT) {
      u8 s[96];
      u32 n2 = len;

      if (n2 == 0u || n2 > 95u) {
        n2 = 95u;
      }
      if (((int (*)(u64, void *, u64))COPYIN)(src + 12, s, n2) != 0) {
        res[TP_R_STATUS] = 8;
      } else {
        s[n2] = 0;
        res[TP_R_STATUS] = tp_text ((addr >> 16) & 0xFFFFu, addr & 0xFFFFu,
                                    (const char *)s);
        res[TP_R_BYTES] = n2;
      }
    } else if (op == TP_OP_BOOT) {
      u8 d[8];
      u32 j, pv = 0, pc = 0;

      /* hw_crc == 2: the bootloader checks the two CRC banks itself */
      bb_crc_bank (tl, 0x3F128u, 0x000000u, 0x3F118u, 0x1167Bu,
                   0x3F100u, 0x8974118Bu);
      bb_crc_bank (tl, 0x3F12Cu, 0x27140u, 0x3F130u, 0x04177u,
                   0x3F104u, 0xAFC39EFAu);

      /* enable the bld crc: set bit7 of 0x3F30E (read-modify-write) */
      bb_read (tl, 0x3F30Eu, d, 1);
      res[TP_R_BLDCRC] = d[0];
      bb_write_addr (tl, 0x3F30Eu, (u8)(d[0] | 0x80u));

      /* fw crc enable, then boot ready */
      bb_write_addr (tl, 0x22D60u, 0x00u);
      bb_write_addr (tl, 0x22D50u, 0xAEu);
      bb_write_addr (tl, 0x3F10Du, 0x01u);
      tp_mdelay (5);

      /* poll the fw reset status: the first byte lands in 0xA0..0xAF */
      for (j = 0; j < 20u; j++) {
        tp_mdelay (10);
        bb_read (tl, 0x22D60u, d, 6);
        pv = d[0];
        if ((d[0] >= 0xA0u) && (d[0] <= 0xAFu)) {
          pc = j + 1u;
          break;
        }
      }
      res[TP_R_POLL] = pv;
      res[TP_R_POLLC] = pc;

      /* fw info: fw_ver and its complement prove the MCU is running */
      bb_read (tl, 0x22D78u, d, 8);
      for (j = 0; j < 8u; j++) {
        res[TP_R_RAW + (j >> 2)] |= ((u32)d[j]) << ((j & 3u) * 8u);
      }
      res[TP_R_VER] = d[0];
      res[TP_R_XNUM] = d[2];
      res[TP_R_YNUM] = d[3];
      res[TP_R_ABSX] = ((u32)d[4] << 8) | d[5];
      res[TP_R_ABSY] = ((u32)d[6] << 8) | d[7];
      res[TP_R_ALIVE] = (((u32)d[0] + (u32)d[1]) == 0xFFu) ? 1u : 0u;
    } else {
      res[TP_R_STATUS] = 22;
    }
  }
  if (((int (*)(const void *, u64, u64))COPYOUT)(res, src, TP_RES_WORDS * 4u) != 0) {
    *(u64 *)retval = (u64)-1;
    return 14;
  }
  *(u64 *)retval = (u64)TP_RES_WORDS * 4u;
  return 0;
}

/* bring the transport up once per boot; one stage per stash pixel */
static u32 tp_ensure_init (void)
{
  u32 stage;

  if (tpx (0) != TP_MAGIC) {
    u64 tlm = ((u64 (*)(u64, u64))ML_IO_MAP)(TP_TLMM_PHYS, 0x40000);

    tpx64_set (1, tlm);
    tpx_set (3, 0);
    tpx_set (4, 0);
    tpx_set (0, TP_MAGIC);
    if (tlm == 0) {
      tpx_set (4, 0x400u);          /* mapping failed; never touch MMIO */
      return 0x400u;
    }
  }
  stage = tpx (3);
  if (stage < 1) {
    volatile u32 *tl = tp_tlmm ();

    /* plain GPIO with pull-up on every line: a floating MISO picks up
       MOSI crosstalk and manufactures deterministic-looking garbage */
    TLMM_CFG (TP_BB_MISO) = (2u << 6) | 3u;                   /* in,  pull-up */
    TLMM_CFG (TP_BB_MOSI) = (2u << 6) | 3u | (1u << 9);       /* out, pull-up */
    TLMM_CFG (TP_BB_CLK)  = (2u << 6) | 3u | (1u << 9);       /* out, pull-up */
    TLMM_CFG (TP_BB_CS)   = (2u << 6) | 3u | (1u << 9);       /* out, pull-up */
    TLMM_CFG (TP_BB_IRQ)  = (1u << 6) | 3u;                   /* in,  pull-up */
    TLMM_CFG (TP_RST)     = (1u << 6) | (1u << 9);            /* out */
    TLMM_IO (TP_RST) &= ~2u;                                   /* hold reset low */
    tpx_set (3, 1);
    stage = 1;
  }
  if (stage < 2) {
    volatile u32 *tl = tp_tlmm ();

    /* vendor power-on order: release the reset line FIRST (the MCU has to
       be running before it can accept the software resets), then the
       bootloader reset with the full 35 ms boot time, then fast read off */
    tp_mdelay (10);
    bb_level (tl, TP_RST, 1);        /* release reset */
    tp_mdelay (20);
    bb_write_addr (tl, 0x3F0FEu, 0x69u);    /* bootloader reset */
    tp_mdelay (35);
    bb_write_addr (tl, 0x3F310u, 0x00u);    /* spi fast read off */
    tpx_set (3, 2);
  }
  return 0;
}
/* read(4, buf, 32): {magic "NVT2", trim[6], trim again[6], miso idle,
   irq, err(2), stage}. The trim id lives at 0x3F004 and the NT36672C
   signature is {0x0C, ??, ??, 0x72, 0x66, 0x03}. */
__attribute__((used)) int console_read (void *p, const u64 *uap, void *retval)
{
#if !defined(TP_CHANNEL)
  /* R224: the touch bridge is not in this build (see NO_TOUCH_BRIDGE), so the
     read syscall keeps its native behaviour and only exists here so that the
     syscall table slot can be pointed at it without a second build. */
  (void)p;
  return ((int (*)(void *, void *, void *))ORIG_READ)(p, (void *)uap, retval);
#else
  u8 rec[32];
  u32 fd = (u32)uap[0];
  u64 dst = uap[1], n = uap[2], len = n < 32 ? n : 32;
  u32 i, err;

  (void)p;
  if (fd != 4) {
    return ((int (*)(void *, void *, void *))ORIG_READ)(p, (void *)uap, retval);
  }
  err = tp_ensure_init ();
  for (i = 0; i < 32; i++) {
    rec[i] = 0;
  }
  rec[0] = 'N'; rec[1] = 'V'; rec[2] = 'T'; rec[3] = '2';
  if (err == 0) {
    volatile u32 *tl = tp_tlmm ();
    u8 id[6], id2[6];

    rec[16] = (u8)bb_sample (tl, TP_BB_MISO);      /* idle level */
    bb_read (tl, 0x3F004u, id, 6);
    bb_read (tl, 0x3F004u, id2, 6);
    for (i = 0; i < 6; i++) {
      rec[4 + i] = id[i];
      rec[10 + i] = id2[i];
    }
    rec[17] = (u8)(TLMM_IO (TP_BB_IRQ) & 1u);       /* irq line level */
  }
  rec[18] = (u8)(err & 0xFFu);
  rec[19] = (u8)((err >> 8) & 0xFFu);
  rec[20] = (u8)tpx (3);
  if (((int (*)(const void *, u64, u64))COPYOUT)(rec, dst, len) != 0) {
    *(u64 *)retval = (u64)-1;
    return 14;
  }
  /* read() returns user_ssize_t -- 64 bits wide. The kernel copies the whole
   * eight bytes out to x0, so writing only four would leave the top half as
   * whatever the kernel stack held: userspace would see a garbage count and
   * the caller could not tell a short read from a long one. (The fd3 write
   * path already proved the slot is eight bytes wide: it returns
   * width<<32|height and userspace reads back dim=0x438000009D8.) */
  *(u64 *)retval = (u64)len;
  return 0;
#endif
}
#endif  /* touch bridge */


/* ---- userspace console ---------------------------------------------------
 *
 * The mockfs root has no /dev/console, no tty and no logd, so a process in EL0
 * has no way to say anything: every result so far had to travel in an exit
 * status. This replaces sysent[SYS_write].sy_call, so `write(1, buf, n)` from
 * userspace is copied in and drawn on the boot console. Other descriptors go
 * to the original write(), so files still work.
 *
 * sy_call_t is int32_t (*)(struct proc *, void *uap, int *retval). Arguments
 * arrive in the thread's 8-byte slots (bsd/dev/arm/systemcalls.c:181 passes
 * &uthread->uu_arg[0]), so write_args is {int fd; pad; user_addr_t cbuf;
 * user_size_t nbyte}. retval points into uu_rval[0], which unix_syscall zeroes
 * before the call, so a whole 64-bit result can be written there.
 *
 * fd 3 is the screen: commands go in, pixel counts come back, and
 * write(3, 0, 0) returns the panel size. Any other descriptor still reaches
 * the real write(), so files keep working.
 */
/* ---- R230: an absolute place for the progress marks --------------------
 *
 * The marks used to go into zone 0 through cons_putc_zone(), which shares
 * its cursor with the text and inherits the cursor the previous boot left on
 * the panel: fastboot boot does not clear the frame buffer, so the marks
 * could land anywhere inside the zone, and the text that followed them was
 * indistinguishable from the marks.
 *
 * They now go to bands that nothing else uses, one letter per slot:
 *
 *   row 630, x 480 + 18*k   A hook ran / B fd3 / C size / D pixels
 *                           E fd1 / F about to copy / V the copy worked
 *                           G bytes in hand / T text drawn / U the copy failed
 *                           X copy_validate said EXDEV / P kernel ptr / Q user
 *   row 630, x 700          the byte count the caller asked for, in hex
 *   row 630, x 860          what copy_validate() said, in hex
 *   row 588, x 480          the caller's buffer address, low 32 bits
 *   row 588, x 660          how many bytes the blob copied, in hex
 *
 * R229 put the byte count at x 700 and the copied bytes at x 780, and a hex
 * byte is 36 pixels wide, so the two fields overlapped and neither could be
 * read.  Every field now has its own 144 pixel slot, and the second one moved
 * to row 588 -- a glyph is 36 pixels tall, so row 630 (630..665) and row 636
 * (636..671) would have drawn over each other.
 *
 * The text drawer's answer is not a field of its own: the 'T' mark only goes
 * up when the drawer said it drew, so the letter says the same thing in two
 * bytes instead of eight, and the blob still fits in the segment tail.
 *
 * Row 630 is between the kernel log (rows 250..590) and zone 0 (row 672),
 * and to the right of the diagnostic ladder (rows 600..639 at x 0..400), so it
 * is the only free space on the panel.
 *
 * R231: the text itself moved from row 210 to row 672.  Row 210 is inside
 * the build stamp (rows 170..239), so the userspace text painted over the
 * very tiles that say which round is on the screen.  Row 672 is the first
 * row of console zone 0, which R230 measured to be completely empty.
 */
#define MARK_ROW 630u
#define MARK_X0  480u
#define MARK_DX  18u
#define MARK_NX  700u
#define MARK_VX  860u
#define SRC_ROW  588u
#define SRC_X    480u
#define RC_X     660u
/* The user's own text goes to a fixed place well below the log: row 672 is
 * the first row of console zone 0, which R230 measured to be completely
 * empty, and it is clear of the build stamp (rows 170..239), of the ident
 * log (rows 250..590) and of the diagnostic ladder (rows 600..639).
 * Row 210, which R230 used, sat inside the build stamp and would have
 * painted over the very tiles that say which round is on the screen. */
#define TXT_ROW  672u

static void mark_at (u32 slot, char c)
{
  volatile struct vc_info *v = (volatile struct vc_info *)VINFO;
  u8 *base = (u8 *)fb_base ();
  u32 rb = v->v_rowbytes;

  if (base == 0 || rb == 0) {
    return;
  }
  cell (base, rb, MARK_X0 + slot * MARK_DX, MARK_ROW, (u8)c);
}

static void mark_hex (u32 x, u32 row, const u8 *b, u32 n)
{
  volatile struct vc_info *v = (volatile struct vc_info *)VINFO;
  u8 *base = (u8 *)fb_base ();
  u32 rb = v->v_rowbytes;
  u32 i;

  if (base == 0 || rb == 0) {
    return;
  }
  for (i = 0; i < n; i++) {
    cell (base, rb, x + i * 36u, row, (u8)"0123456789abcdef"[b[i] >> 4]);
    cell (base, rb, x + i * 36u + MARK_DX, row,
          (u8)"0123456789abcdef"[b[i] & 15u]);
  }
}

static void mark_num (u32 x, u32 row, u32 v)
{
  u8 t[4];

  t[0] = (u8)(v >> 24);
  t[1] = (u8)(v >> 16);
  t[2] = (u8)(v >> 8);
  t[3] = (u8)v;
  mark_hex (x, row, t, 4);
}

/* R232: a plain text summary of the two paths a process in EL0 reaches the
 * panel through.  The marker band carries the same numbers as hex fields,
 * and a hex field has to be read pixel by pixel; a sentence can be read off
 * a photograph.  The two lines sit on the first two free text rows of the
 * panel, row 42 and row 84 -- above the ident log (250..590), above the
 * build stamp (170..239) and above the marker band (630).
 *
 * row 42: the fd 1 path, the text channel.
 * row 84: the fd 3 path, the pixel channel.
 */
#define ROUND_TAG "R235"

static char *put_hex8 (char *p, u32 v)
{
  u32 i;

  for (i = 28u; i < 32u; i -= 4u) {
    *p++ = (char)"0123456789abcdef"[(v >> i) & 15u];
  }
  return p;
}

/* R233: one helper for "label" plus eight hex digits.
 *
 * The early blob has about fifty bytes to spare in __TEXT_EXEC's tail, and
 * the R232 version of this line -- four put_str calls and four put_hex8
 * calls -- cost three hundred and twenty eight bytes.  Folding the two
 * helpers into one and the strings into the labels is what makes the line
 * fit at all. */
static char *put_kv (char *p, const char *label, u32 v)
{
  while (*label != 0) {
    *p++ = *label++;
  }
  return put_hex8 (p, v);
}

#if !defined(NO_FB_CHANNEL)
#if defined(FB_CHANNEL_HOOK)
/* The early blob.  The pixel path is not compiled here at all: it lives in
 * the channel blob and is reached through this one call.  Keeping the two
 * apart at the source level means the early blob cannot pick up the pixel
 * path by accident, and the linker cannot decide on its own to keep it. */
static int fb_channel_dispatch (u64 src, u64 n, void *retval)
{
  return ((int (*)(u64, u64, void *))FB_CHANNEL_HOOK)(src, n, retval);
}
#else
/* The channel blob.  The pixel path itself. */
__attribute__((used, section(".text.fb_channel")))
int fb_channel_write (u64 src, u64 n, void *retval)
{
  volatile struct vc_info *v = (volatile struct vc_info *)VINFO;
  u32 fb[FB_BAND / 4];
  u64 done = 0, chunk, done_cmds = 0;

  mark_at (1, 'B');
  if (n == 0) {
    *(u64 *)retval = ((u64)v->v_width << 32) | (v->v_height & 0xFFFFFFFFu);
    mark_at (2, 'C');              /* the panel-size query answered */
    return 0;
  }
  while (done < n) {
    chunk = n - done;
    if (chunk > FB_BAND) {
      chunk = FB_BAND;
    }
    chunk -= chunk % 24;              /* whole commands only */
    if (chunk == 0) {
      break;
    }
    if (((int (*)(u64, void *, u64))COPYIN)(src + done, fb, chunk) != 0) {
      *(int *)retval = (int)done_cmds;
      return 14;
    }
    done_cmds += fb_exec (fb, (u32)chunk / 4);
    done += chunk;
  }
  *(int *)retval = (int)done_cmds;
  mark_at (3, 'D');                  /* the pixel path survived a copyin + draw */
  {
    char d[64];
    char *p = d;

    p = put_kv (p, ROUND_TAG " fd1 n=", st_get (ST_FD1_N) & 0xffffu);
    p = put_kv (p, " v=", (st_get (ST_FD1_N) >> 16) & 0xffu);
    p = put_kv (p, " c=", st_get (ST_FD1_C));
    *p = 0;
    tp_text (0, 1, d);              /* row 42: the fd 1 path, as text */
  }
  {
    char d[64];
    char *p = d;

    p = put_kv (p, ROUND_TAG " fd3 n=", (u32)n);
    p = put_kv (p, " cmds=", (u32)done_cmds);
    *p = 0;
    tp_text (0, 2, d);              /* row 84 */
  }
  return 0;
}

static int fb_channel_dispatch (u64 src, u64 n, void *retval)
{
  return fb_channel_write (src, n, retval);
}
#endif
#endif

#if defined(COPYIN) && defined(ORIG_WRITE)
__attribute__((used)) int console_write (void *p, const u64 *uap, void *retval)
{
  char buf[256];
  u32 fd = (u32)uap[0];
  u64 src = uap[1], n = uap[2], done = 0, chunk;
  int vrc = 0;
  u32 dr = 0;

  mark_at (0, 'A');                  /* the hook ran; this store reached the panel */
#if !defined(NO_FB_CHANNEL)
  if (fd == 3) {
    return fb_channel_dispatch (src, n, retval);
  }
#endif
#if defined(TP_CHANNEL)
  /* fd 4 is the Novatek touch bridge. R77 used it to read the trim id back;
     R78 turns it into a command channel so userspace can push the 88 KB
     firmware into the chip's SRAM (the blob has no room for it) and then run
     the vendor's post-download sequence. */
  if (fd == 4) {
    return tp_fd4 (src, n, retval);
  }
#endif
  if (fd != 1 && fd != 2) {
    return ((int (*)(void *, void *, void *))ORIG_WRITE)(p, (void *)uap, retval);
  }
  mark_at (4, 'E');                  /* fd 1/2 path reached */
  mark_num (MARK_NX, MARK_ROW, (u32)n);   /* how many bytes the caller wants */
  mark_num (SRC_X, SRC_ROW, (u32)src);     /* and from where */
  mark_at (11, ((src >> 56) != 0u) ? 'P' : 'Q');   /* P kernel pointer, Q user */

  /* R230: the copy is the kernel's own, and the kernel's own answer is the
   * diagnosis.
   *
   * R227 and R228 stopped between the "about to copy" mark and the "copied"
   * mark and could not say why.  R229 replaced the copy with a hand written
   * byte loop guarded by at s1e1r, and the guard said the address could not
   * be read.  That answer was meaningless: arm_vm_init removes TTBR0, so the
   * address translation register cannot see the user half of the address
   * space at all, and every user address comes back faulting.  The 'U' R229
   * painted was the hardware agreeing that TTBR0 is empty, not that the page
   * is missing.
   *
   * So the copy goes back to copyin(), and the question "can this address be
   * read" is put to the code that actually answers it:
   *
   *   copy_validate(user_addr, kernel_addr, len, COPYIO_IN |
   *                COPYIO_ALLOW_KERNEL_TO_KERNEL)
   *     0   the address is inside the current thread's map: copy it
   *     14  EFAULT, it is outside the map
   *     18  EXDEV, the thread runs in the kernel context
   *     22  EINVAL, the top byte of the address is set
   *
   * copy_validate() only looks at numbers, so it cannot fault.  copyin() is
   * called only after it has said yes, and __bcopyin() is inside the copyio
   * recovery table, so a page that is not there comes back as an error
   * instead of taking the kernel down.
   */
  while (done < n) {
    chunk = n - done;
    if (chunk > sizeof buf - 1) {
      chunk = sizeof buf - 1;
    }
    if (chunk == 0) {
      break;
    }
    vrc = 0;
#if defined(COPY_VALIDATE)
    vrc = ((int (*)(u64, u64, u64, u32))COPY_VALIDATE)(src + done,
                                                       (u64)(void *)buf,
                                                       chunk, 5u);
#endif
    mark_num (MARK_VX, MARK_ROW, (u32)vrc);
    if (vrc != 0) {
      mark_at (9, 'U');              /* the kernel refused the address */
      if (vrc == 18) {
        mark_at (10, 'X');          /* EXDEV: the thread is in the kernel */
      }
      *(int *)retval = (int)done;
      return 14;                     /* EFAULT */
    }
    mark_at (5, 'F');                /* about to copy */
    /* R231: the copy is the blob's own.
     *
     * copyin() hung in R227..R230 and the reason is now known: the kernel
     * runs with SCTLR_EL1.SPAN == 0, so an EL1 load of a user page raises a
     * permission fault, and the copyio recovery path turns that into an
     * endless retry loop instead of an error return (see
     * tools/patch-xnu-span.py for the whole chain).
     *
     * The load below is NOT inside copyio_recover_table[], so if it faults
     * the kernel panics instead of spinning, and the panic screen prints the
     * fault address, the ESR and the PC.  That is the difference between
     * "the phone hung" and "the phone told us why".
     *
     * If it does not fault, the bytes are in hand and the userspace text
     * goes on the panel -- which is the whole point of the exercise.
     */
    {
      u32 i, m = (u32)chunk;
      const volatile u8 *s = (const volatile u8 *)(src + done);

      for (i = 0; i < m; i++) {
        buf[i] = (char)s[i];
      }
    }
    mark_num (RC_X, SRC_ROW, (u32)(done + chunk));   /* how many bytes we got */
    mark_at (6, 'V');                /* the bytes are in hand */
    {
      u32 i, m = (u32)chunk;

      /* Only the first line, and only printable characters: cell() indexes
       * the font with (c - 32) and a newline would take it off the end. */
      for (i = 0; i < m; i++) {
        u8 c = (u8)buf[i];

        if (c == '\n') {
          break;
        }
        buf[i] = (char)((c >= 32u && c <= 126u) ? c : '.');
      }
      buf[i] = 0;
    }
    mark_at (7, 'G');                /* and about to be drawn */
    dr = tp_text (0, TXT_ROW / CONS_LINE, buf);
    if (dr == 0) {
      mark_at (8, 'T');              /* the text is on the panel */
    }
    done += chunk;
  }
#if !defined(NO_FD1_DIAG)
  /* R233: record the numbers for the channel blob, which prints them as a
   * line of text (row 42).  Two words is what fits: n and v packed
   * together, and the number of bytes copied. */
  st_set (ST_FD1_N, (u32)((n & 0xffffu) | ((u64)vrc & 0xffu) << 16));
  st_set (ST_FD1_C, (u32)done);
#endif
  *(int *)retval = (int)done;
  return 0;
}
#endif

static void number (struct ctx *g, u64 value, u32 base, u32 width, int zero)
{
  u8  digits[24];
  u32 n = 0, i;

  do {
    u32 d = (u32)(value % base);
    digits[n++] = (u8)(d < 10 ? '0' + d : 'a' + d - 10);
    value /= base;
  } while (value && n < 24);
  for (i = n; i < width; i++) {
    put (g, zero ? '0' : ' ');
  }
  while (n) {
    put (g, digits[--n]);
  }
}

/* Probe each string byte before dereferencing it. Heap strings (process name
 * and exit reason) live outside the linked image. AT performs a hardware
 * translation query only: no table edits, mappings, or exception bypass.
 * Refuse user pointers, translation faults and device-memory attributes. */
static int readable (const char *s, const u64 *args)
{
  u64 a = (u64)s;
  (void)args;
  /* R230: the kernel's own map is live in TTBR1 and never changes, so a
   * kernel address is readable without asking the MMU.  R229 asked the MMU
   * and the MMU answered "no" for everything, because arm_vm_init removes
   * TTBR0; the result was a panic screen with the message left out of it. */
  if (a < 0xffff000000000000UL) return 0;   /* a user address: not ours to read */
  return 1;
}

static void format (struct ctx *g, const char *fmt, const u64 *args)
{
  u32 i, used = 0;

  for (i = 0; i < 2000 && fmt[i]; i++) {
    u8 c = (u8)fmt[i];
    if (c != '%') {
      put (g, c);
      continue;
    }
    u32 width = 0;
    int zero = 0, longs = 0;
    c = (u8)fmt[++i];
    if (c == '0') {
      zero = 1;
      c = (u8)fmt[++i];
    }
    while (c >= '0' && c <= '9') {
      width = width * 10 + (c - '0');
      c = (u8)fmt[++i];
    }
    u32 precision = 4000;
    if (c == '.') {
      precision = 0;
      c = (u8)fmt[++i];
      if (c == '*') {
        precision = (u32)args[used++];
        c = (u8)fmt[++i];
      } else {
        while (c >= '0' && c <= '9') {
          if (precision < 4000) precision = precision * 10 + (c - '0');
          c = (u8)fmt[++i];
        }
      }
      if (precision > 4000) precision = 4000;
    }
    if (width > 256) width = 256;
    while (c == 'l' || c == 'z' || c == 'h') {
      longs += (c != 'h');
      c = (u8)fmt[++i];
    }
    if (c == '%') {
      put (g, '%');
      continue;
    }
    if (c == 0) {
      break;
    }
    u64 v = args[used++];
    if (c == 's') {
      const char *s = (const char *)v;
      u32 k;
      for (k = 0; k < precision; k++) {
        if (!readable (s + k, args)) {
          put (g, '<');
          number (g, (u64)(s + k), 16, 0, 0);
          put (g, '>');
          break;
        }
        u8 ch = (u8)s[k];
        if (!ch) break;
        put (g, ch);
      }
    } else if (c == 'x' || c == 'X') {
      number (g, longs ? v : (v & 0xFFFFFFFFu), 16, width, zero);
    } else if (c == 'u' || c == 'd') {
      number (g, longs ? v : (v & 0xFFFFFFFFu), 10, width, zero);
    } else if (c == 'p') {
      put (g, '0');
      put (g, 'x');
      number (g, v, 16, width, zero);
    }
  }
}

static void text (struct ctx *g, const char *s)
{
  while (*s) {
    put (g, (u8)*s++);
  }
}

static void hex (struct ctx *g, const char *label, u64 v)
{
  text (g, label);
  put (g, '0');
  put (g, 'x');
  number (g, v, 16, 16, 1);
}

/* R167: the panic handler names the kind of fault ("kernel static region",
 * "unaligned data abort", ...) but not the address that faulted, and the two
 * cases need opposite fixes: a permission fault means the page is mapped
 * read-only (fix the protection), a translation fault means it is not mapped
 * at all (fix the mapping). FAR_EL1/ESR_EL1 still hold the last data abort
 * when panic() runs, so printing them here turns every future panic into a
 * readable verdict instead of another guess. */
static u64 read_far (void)
{
  u64 v;
  __asm__ volatile ("mrs %0, far_el1" : "=r" (v));
  return v;
}

static u64 read_esr (void)
{
  u64 v;
  __asm__ volatile ("mrs %0, esr_el1" : "=r" (v));
  return v;
}

/* x0 = fmt as for panic(); x1 is set by the stub to the entry stack pointer. */
__attribute__((noreturn, used, section(".text.b_main"))) void panic_screen_main (const char *fmt, const u64 *args)
{
  volatile struct vc_info *v = (volatile struct vc_info *)VINFO;
  struct ctx g;
  u32 row, col, lim;

  fb_lazy_map ();             /* map the GOP buffer ourselves if the kernel has not */
  __asm__ volatile ("msr daifset, #15");
  g.base = (u8 *)fb_base ();
  g.rb   = v->v_rowbytes;
  g.w    = v->v_width;
  g.h    = v->v_height;
  if (g.base == 0 || v->v_depth != 32 || fmt == 0) {
    park ();
  }

  /* R107: the panel reports 2520 rows but the kernel's mapping of it is
   * shorter, so the panel's last row is not addressable.  The marker used to
   * live there: the panic screen wrote into unmapped memory on the way out,
   * which is why every round ended with a second panic and the message that
   * was actually wanted was never the one on the screen.  The drawing height
   * is clamped to the mapping as well, so no store can reach past it. */
  lim = fb_rows (g.base, g.rb, g.h);
  if (lim != 0) {
    g.h = lim;
  }
  /* R227: clamp to what the live tables really reach, not just to what the
   * kernel says it mapped.  Before PE_create_console() the panel is reached
   * through the bootloader's identity block, which ends at row 969, and a
   * panic screen that believed in 2520 rows wiped straight through the end
   * of it -- and died there, so the message never reached the panel. */
  {
    u32 mr = fb_mapped_rows (g.base, g.rb, g.h);

    if (mr != 0 && mr < g.h) {
      g.h = mr;
    }
  }
  g.maxy = g.h;

  /* First panic wins: a marker in the last row's first two pixels means a panic already drew
   * the screen; a later panic (another thread or exception) must not overwrite it. */
  volatile u32 *mark = (volatile u32 *)(g.base + (u64)(g.h - 1) * g.rb);
  if (mark[0] == 0xC0FFEE11u && mark[1] == 0x5CEEDA7Au) {
    park ();
  }
  g.x = 0;
  /* R103: the screen used to be wiped from 1/8 of the panel down, which
     destroyed the fixture's readings (they live in rows 6..43) the moment
     the kernel panicked -- one title row was all that survived, and the
     readings are the whole point of the round.  The panic text needs about
     13 lines, so the bottom 16 rows are enough for it and everything above
     survives: the kernel log, the readings and the progress marker.
   *
   * R105: the bottom 16 rows are off the bottom of the panel the recordings
   * show, so the esr/far line was never visible and every round ended in a
   * guess.  Rows 30..45 are inside the panel and still below the fixture's
   * readings (rows 5..29), so the same text is visible now. */
  g.y = 20u * CONS_LINE;
  {
    u32 ybot = 28u * CONS_LINE;
    if (ybot > g.h) {
      ybot = g.h;
    }
    g.log = 0;
    g.logn = 0;
    for (row = g.y; row < ybot; row++) {
      for (col = 0; col < g.w; col++) {
        *(volatile u32 *)(g.base + (u64)row * g.rb + (u64)col * 4) = 0;
      }
    }
  }
  g.y += 8;
  /* R211: the window starts at row 840 now, which the recordings do cover
   * (the camera only ever sees the top ~1260 rows of the panel).  far/esr
   * goes on the very first line: the capture dump below can run to nine
   * lines on its own and would otherwise push the only copy of the fault
   * address off the bottom. */
  hex (&g, "far=", read_far ());
  hex (&g, " esr=", read_esr ());
#if 1
  /* R229: the userspace text is no longer captured into the frame buffer's
   * last row.  That store sat at the very end of the kernel's mapping of the
   * panel, and the read-back was one more way for the panic handler to die
   * in its own second line.  The build tag takes its place: the mark band
   * on row 630 survives the panic screen, which starts at row 840, so the
   * state of the fd1 path is still on the panel when the kernel goes. */
  text (&g, "R229 out:");
#endif
  /* The board's live banner keeps showing this text after the next swap paints over the screen (BootProgress.c,
   * boot_progress_panic_text). The first panic's text is kept: a buffer that already holds one is left alone. */
  if (PANIC_TEXT && *(volatile u8 *)PANIC_TEXT == 0) {
    g.log = (u8 *)PANIC_TEXT;
  }
  /* R105: the extent of the kernel's mapping of the frame buffer, first of
   * all, before the message and the register dump: R104's abort happened in a
   * store into that buffer, so the size of the mapping and the address it
   * starts at are the first things to compare against the faulting address. */
#ifdef LAST_VIDEO_SIZE
  hex (&g, "\nlv=", *(volatile const u64 *)LAST_VIDEO_VIRT);
  hex (&g, "\nls=", *(volatile const u64 *)LAST_VIDEO_SIZE);
#endif
  format (&g, fmt, args);
  /* The return addresses up the frame pointer chain: the exception entry links the panic's frames to the code that faulted, so this
   * names the callers the message leaves out. Stops at a pointer outside the kernel's range, a misaligned one or one that does not
   * move up the stack. */
  {
    const u64 *fp = (const u64 *)__builtin_frame_address (0);
    text (&g, "\nframes");
    /* R103: 16 addresses, not 24: the interesting frame (the one in the blob)
       is always among the first four, and every address costs a line of the
       16 the panic region has. */
    for (unsigned i = 0; i < 16; i++) {
      const u64 at = (u64)fp;
      if (at < 0xfffffff000000000UL || (at & 15)) break;
      const u64 next = fp[0], lr = fp[1] & 0x0000007fffffffffUL;   /* the return address without its pointer authentication bits */
      put (&g, ' ');
      number (&g, lr | 0xffffff8000000000UL, 16, 16, 1);
      if (next <= at) break;
      fp = (const u64 *)next;
    }
  }
  g.log = 0;
  __asm__ volatile ("dsb sy");
  /* The eight words at VINFO, verbatim. R72 died writing pixels 638 rows below
   * the panel, so the geometry the drawing code acts on is the thing to check,
   * not the code that reads it: if v_height here is not the panel height, the
   * struct in the kernel differs from the one this blob was compiled against. */
  {
    volatile const u32 *vi = (volatile const u32 *)VINFO;
    text (&g, "\nvi");
    for (unsigned i = 0; i < 8; i++) {
      put (&g, ' ');
      number (&g, vi[i], 16, 8, 0);
    }
  }
  /* The raw argument slots are not dumped: the formatted message above already carries them (room for the PANIC_TEXT copy). */
  mark[0] = 0xC0FFEE11u;
  mark[1] = 0x5CEEDA7Au;
  __asm__ volatile ("dsb sy");
  park ();
}

/* Entry from panic(): keep the stack pointer, which addresses the variadic arguments. */
__attribute__((naked, noreturn, section(".text.a_entry"))) void panic_screen (const char *fmt)
{
  __asm__ volatile ("mov x1, sp\n\tb panic_screen_main");
}

/* The real panic_trap_to_debugger signature takes (fmt, va_list *, ...).
 * Darwin ARM64 va_list is a stack pointer; its address is passed in x1.
 * The wrapper has already established its frame, so SP is NOT the argument
 * list here. Follow exactly the one pointer supplied by the real wrapper.
 */
__attribute__((naked, noreturn, section(".text.a_common"))) void panic_screen_common (void)
{
  __asm__ volatile ("ldr x1, [x1]\n\tb panic_screen_main");
}

#include "Font.h"
__attribute__((section(".text.z_font"))) const u64 gFont[] = GLYPH_FONT;
