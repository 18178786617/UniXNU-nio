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

  for (row = 0; row < 12; row++) {
    u32 data = (row < 6) ? (top >> (row * 5)) : (bottom >> ((row - 6) * 5));
    for (col = 0; col < 5; col++) {
      u32 lit = (data >> col) & 1;
      for (dy = 0; dy < SCALE; dy++) {
        for (dx = 0; dx < SCALE; dx++) {
          *(volatile u32 *)(base + (u64)(y + row * SCALE + dy) * rb
                            + (u64)(x + col * SCALE + dx) * 4) = lit ? 0xFFFFFFFFu : 0;
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
  base = (u8 *)v->v_baseaddr;
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
static u32 zone_next (u32 y, u32 y0, u32 y1)
{
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
  u8 *base = (u8 *)v->v_baseaddr;
  u32 rb = v->v_rowbytes, w = v->v_width, h = v->v_height;
  u32 x, y, i, rows, split, y0, y1, magic, lim;
  u32 *st;
  u8 c = (u8)ch;

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
    y0 = 0;
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
    st[1] = 0;
    st[2] = zone_next (y, y0, y1);
    return;
  }
  if (c < 32 || c > 126) {
    return;
  }
  if (x + CONS_CELL > w) {
    x = 0;
    y = zone_next (y, y0, y1);
  }
  cell (base, rb, x, y, c);
  st[1] = x + CONS_CELL;
  st[2] = y;
}

/* Matches struct console_ops.putc: void (*)(char, bool). Kernel log goes to the
 * top zone. */
__attribute__((used)) void console_putc (char ch, unsigned int poll)
{
  (void)poll;
  cons_putc_zone (ch, 0);
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
   * again: R72 faulted 638 rows past the panel, so a bad y0/rh pair has to be
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
  u8 *base = (u8 *)v->v_baseaddr;
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
#if defined(ML_IO_MAP) && defined(COPYOUT) && defined(ORIG_READ) && defined(COPYIN)
/* R78: the fd4 command channel needs copyin as well as copyout -- userspace
   hands the kernel a command and the kernel answers in the same buffer. */
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
  return (volatile u32 *)((u8 *)v->v_baseaddr + (u64)(v->v_height - 1) * v->v_rowbytes);
}

/* stash layout, pixels of the last row from x=2:
   0 magic | 1-2 TLMM va | 3 stage | 4 last err | 5-6 trim six bytes
   | 7 irq level */
static u32 tpx (u32 i)
{
  return (tp_row ()[2 + i] ^ 0x5A5A0000u);
}

static void tpx_set (u32 i, u32 v)
{
  tp_row ()[2 + i] = v ^ 0x5A5A0000u;
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
#if defined(COPYIN) && defined(ORIG_WRITE)
__attribute__((used)) int console_write (void *p, const u64 *uap, void *retval)
{
  char buf[256];
  u32 fb[FB_BAND / 4];
  u32 fd = (u32)uap[0];
  u64 src = uap[1], n = uap[2], done = 0, chunk, done_cmds = 0;

  if (fd == 3) {
    volatile struct vc_info *v = (volatile struct vc_info *)VINFO;

    if (n == 0) {
      *(u64 *)retval = ((u64)v->v_width << 32) | (v->v_height & 0xFFFFFFFFu);
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
    return 0;
  }
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
  while (done < n) {
    int err;

    chunk = n - done;
    if (chunk > sizeof buf) {
      chunk = sizeof buf;
    }
    err = ((int (*)(u64, void *, u64))COPYIN)(src + done, buf, chunk);
    if (err) {
      *(int *)retval = (int)done;
      return 14;                    /* EFAULT if copyin refused the buffer */
    }
    for (u32 i = 0; i < (u32)chunk; i++) {
      cons_putc_zone (buf[i], 1);
    }
    done += chunk;
  }
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
  u64 a = (u64)s, par;
  (void)args;
  if (a < 0xffff000000000000UL) return 0;
  __asm__ volatile ("at s1e1r, %1; isb; mrs %0, par_el1" : "=r" (par) : "r" (a) : "memory");
  return !(par & 1) && ((par >> 60) != 0);
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

/* x0 = fmt as for panic(); x1 is set by the stub to the entry stack pointer. */
__attribute__((noreturn, used, section(".text.b_main"))) void panic_screen_main (const char *fmt, const u64 *args)
{
  volatile struct vc_info *v = (volatile struct vc_info *)VINFO;
  struct ctx g;
  u32 row, col, lim;

  __asm__ volatile ("msr daifset, #15");
  g.base = (u8 *)v->v_baseaddr;
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
  g.y = 30u * CONS_LINE;
  {
    u32 ybot = 46u * CONS_LINE;
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
