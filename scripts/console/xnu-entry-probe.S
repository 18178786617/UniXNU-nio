/* R182: entry probe, MMU-off ladder, and the frame buffer mapping that lets
 * the ladder continue past the MMU switch.
 *
 * DarwinEnter() (refs/UniXNU/drivers/DarwinBoot/.../Entry.S) ends with
 *
 *     mrs   x4, sctlr_el1
 *     bic   x4, x4, #1          ; SCTLR_EL1.M  -- the MMU goes OFF
 *     bic   x4, x4, #4          ; SCTLR_EL1.C  -- the data cache goes OFF
 *     bic   x4, x4, #0x1000     ; SCTLR_EL1.I  -- the instruction cache goes OFF
 *     msr   sctlr_el1, x4
 *     tlbi  vmalle1
 *     br    x1                  ; x1 = the kernel entry, PHYSICAL
 *
 * so the first instruction of the kernel runs with the MMU off, with the
 * caches off, and with the PC holding a *physical* address.  A store to
 * 0x9C000000 therefore lands in the frame buffer itself: no translation, no
 * mapping, no cache to worry about.  That is the only channel that can report
 * boot progress in this window -- everything else needs a VM that does not
 * exist yet.
 *
 * ---------------------------------------------------------------------------
 * R180 RESULT
 *
 * All six MMU-off checkpoints (C1..C6) lit up.  _start builds both bootstrap
 * mappings, loads TCR from sysreg_restore, programs TTBR0 through
 * pinst_set_ttbr0 (0x73EF254), TTBR1, MAIR and VBAR, and reaches 0x73EB340 --
 * four instructions before "msr sctlr_el1".  Nothing after that has ever been
 * observed, because from 0x73EB354 on the PC is a virtual address and the
 * frame buffer's physical address 0x9C000000 has no virtual alias.
 *
 * ---------------------------------------------------------------------------
 * R181: MAP THE FRAME BUFFER, THEN KEEP STAMPING
 *
 * _start's own bootstrap tables map exactly two ranges:
 *
 *     TTBR0  V=P   [kernel physical base, + MemorySize)   <- identity
 *     TTBR1  KVA   [kernel virtual base,  + MemorySize)
 *
 * and nothing else, so device memory is unreachable once the MMU is on.
 * FB_MAP_INSTALL below adds one 2 MiB identity block to the V=P table, taken
 * from the same free-page pool _start itself allocates its L2 tables from
 * (x2).  After that a store to 0x9C000000 works with the MMU on *and* off,
 * because in both cases the address resolves to the same physical block.
 *
 * Geometry: 0x9C000000 >> 30 == 2, so the L1 slot is 2; the remaining
 * 0x1C000000 puts it at L2 index 224 (0x9C000000 is not 2 MiB aligned).  Two
 * consecutive blocks are installed (rows 0..~970 of the 4320 byte stride)
 * because the C7/C8 row at 420 runs past the first 2 MiB at row 485.
 *
 * The block uses AttrIndx 3, which MAIR programs to 0x00 = Device-nGnRnE:
 * uncached, no reordering, non-executable.  Exactly what a frame buffer wants.
 *
 * ---------------------------------------------------------------------------
 * R181 RESULT (this is what R182 fixes)
 *
 * Six red bars and C1..C5 lit up; C6 went dark.  R180 had shown C6, and the
 * only change to that stub was the new FB_MAP_INSTALL -- so the mapping code
 * itself was killing the stub.  Cause: the L2 table address was taken as
 * bits[47:0] of the L1 descriptor, which still carries the 0b11 type field,
 * making every L2 store land three bytes off.  With the MMU off all accesses
 * are Device-nGnRnE, and unaligned Device accesses always fault regardless of
 * SCTLR.A -- so the store raised an alignment fault before the square was
 * painted.  Fixed by shifting the address down to bits[47:12] and back up.
 *
 * R182 also paints before installing, so the square itself is never a
 * casualty of the code that follows it.
 *
 * ---------------------------------------------------------------------------
 * WHAT IS PAINTED
 *
 * Row 170, eight solid red bars 120 px wide with a 16 px gap: the build stamp.
 * The count is the build number, so a blurry frame can never be mistaken for
 * the previous round's.
 *
 * Row 280, seven 96 x 96 squares, painted with the MMU off:
 *
 *   C1 0x73EB0F8  magenta  the 64 KB page-table zero fill finished
 *   C2 0x73EB12C  cyan     the Mach-O header check passed (first LC is
 *                          LC_SEGMENT_64, the 0x73EB108 hang was not taken)
 *   C3 0x73EB174  orange   the first bootstrap mapping loop was entered
 *   C4 0x73EB1EC  yellow   the second bootstrap mapping loop was entered
 *   C5 0x73EB298  violet   both loops finished, the TCR is being loaded
 *                          (so the 0x73EB284 "out of page tables" hang was
 *                          not taken)
 *   C6 0x73EB340  white    the SCTLR value is being built
 *   C6b           green    FB_MAP_INSTALL finished -- 0x9C000000 is now
 *                          identity mapped in the V=P table
 *
 * Row 420, two 96 x 96 squares, painted with the MMU ON:
 *
 *   C7 0x73EB354  blue     the first instruction fetched through the new
 *                          translation -- proves TTBR0/TCR/MAIR/SCTLR are a
 *                          working set and the V=P map is live
 *   C8 0x79C27CC  red      arm_init was entered through the KVA map -- proves
 *                          TTBR1 works and the "ret" across the address space
 *                          boundary landed
 *
 * Row 560, six 96 x 96 squares, the ladder inside arm_init:
 *
 *   S1 0x7930648  magenta  PE_init_platform
 *   S2 0x73E25C0  cyan     arm_vm_init
 *   S3 0x73C7B08  orange   pmap_bootstrap (inside arm_vm_init)
 *   S4 0x79309F8  yellow   PE_create_console  -- arm_vm_init returned
 *   S5 0x73BC960  violet   initialize_screen  -- the frame buffer is being
 *                          mapped for the kernel's own video console
 *   S6 0x792EC2C  white    PE_init_printf     -- PE_create_console returned
 *
 * S1..S3 still run under the bootstrap tables, so they use the physical
 * address.  From S4 on the tables have been swapped and the panel is only
 * reachable through a fresh ml_io_map_unmappable(), which is exactly what
 * STAMP_IO does.
 *
 * A missing square localises the failure to the span between it and the
 * previous one.
 *
 * ---------------------------------------------------------------------------
 * MECHANICS
 *
 * Each checkpoint replaces one instruction with "b stub".  The stub paints,
 * replays the displaced instruction, and branches back to site + 4.  A plain b
 * is used in both directions: bl would clobber x30, which holds the return
 * address to arm_init through the whole of the second half of _start.
 *
 * Only x9..x16 are touched.  Every site was checked to be outside the live
 * range of those registers, to sit on an instruction boundary that no branch
 * targets, and to be a non-PC-relative instruction (replaying an adrp or a
 * literal load at a different address would produce a different value).
 *
 * The sentinel words are rewritten by tools/patch-xnu-console-blob.py:
 * 0xdead0001 becomes the displaced instruction, 0xdead0002 the branch back.
 *
 * x0 holds the boot arguments on entry and the SCTLR value at C6, so it is
 * never touched here.
 */

	.text
	.global entry_probe
	.global entry_probe_tail

/* Paint a rows x cols rectangle at byte offset xoff from <base>.  The store
 * advances the pointer, so the pitch added at the end of a row is
 * 4320 - cols * 4 -- adding the full row would smear the block sideways.
 * Clobbers x10..x13, leaves <base> alone. */
	.macro	PAINT_AT base, xoff, colour, rows, cols
	movz	x10, #(\xoff & 0xffff)
	movk	x10, #((\xoff >> 16) & 0xffff), lsl #16
	add	x10, x10, \base
	movz	x11, #(\colour & 0xffff)
	movk	x11, #((\colour >> 16) & 0xffff), lsl #16
	movz	x12, #\rows
1:
	movz	x13, #\cols
2:
	str	w11, [x10], #4
	subs	x13, x13, #1
	b.ne	2b
	/* add-immediate tops out at 4095, and 4320 - cols*4 is above that for any
	 * block narrower than 57 px, so pay the row pitch in two steps. */
	.if	(4320 - \cols * 4) > 4095
	add	x10, x10, #4080
	add	x10, x10, #(4320 - 4080 - \cols * 4)
	.else
	add	x10, x10, #(4320 - \cols * 4)
	.endif
	subs	x12, x12, #1
	b.ne	1b
	.endm

/* R212: same as PAINT_AT, but the colour arrives in \reg instead of as an
 * immediate.  Needed because the answer of an AT probe is only known at run
 * time: white = the MMU translates it, red = it does not.  Clobbers x10,
 * x12, x13 and leaves \reg and \base alone. */
	.macro	PAINT_AT_R base, xoff, reg, rows, cols
	movz	x10, #(\xoff & 0xffff)
	movk	x10, #((\xoff >> 16) & 0xffff), lsl #16
	add	x10, x10, \base
	movz	x12, #\rows
1:
	movz	x13, #\cols
2:
	str	\reg, [x10], #4
	subs	x13, x13, #1
	b.ne	2b
	.if	(4320 - \cols * 4) > 4095
	add	x10, x10, #4080
	add	x10, x10, #(4320 - 4080 - \cols * 4)
	.else
	add	x10, x10, #(4320 - \cols * 4)
	.endif
	subs	x12, x12, #1
	b.ne	1b
	.endm

/* R212: paint bits 0..7 of x15 as a barcode -- 8 blocks, pitch 48 rows,
 * 60 px apart, 40 wide.  A white block means the bit is set, so the pattern
 * on the panel reads left-to-right as bit 0 .. bit 7.  Used to put the
 * FST out of PAR_EL1 on the panel.  Clobbers x10..x13, x16; x17 must already
 * hold the colour. */
	.macro	BAR8 base, xoff
	movz	x10, #(\xoff & 0xffff)
	movk	x10, #((\xoff >> 16) & 0xffff), lsl #16
	add	x10, x10, \base
	movz	x12, #8
3:
	tbz	x15, #0, 5f
	mov	x11, x10
	movz	x13, #48
4:
	movz	x16, #40
6:
	str	w17, [x11], #4
	subs	x16, x16, #1
	b.ne	6b
	add	x11, x11, #4080
	add	x11, x11, #(4320 - 4080 - 160)
	subs	x13, x13, #1
	b.ne	4b
5:
	add	x10, x10, #240
	lsr	x15, x15, #1
	subs	x12, x12, #1
	b.ne	3b
	.endm

/* Same, straight at the frame buffer's physical address.  Only valid while
 * that address is mapped: with the MMU off, or through the identity block
 * FB_MAP_INSTALL adds.  Clobbers x9..x13. */
	.macro	PAINT_RECT xoff, colour, rows, cols
	movz	x9, #0x0000
	movk	x9, #0x9C00, lsl #16
	PAINT_AT x9, \xoff, \colour, \rows, \cols
	.endm

/* R200: stamp through the kernel's *physmap* alias of the frame buffer.
 *
 * R199 proved arm_vm_init() runs all the way to 0x73E30FC and then goes
 * quiet.  The very next instruction is `bl set_mmu_ttb_alternate`, i.e.
 * TTBR1 is pointed at the freshly built cpu_ttep.  From that instant
 * 0x9C000000 has no mapping at all, so a PAINT_RECT there is a data abort,
 * not a dark square -- which is exactly why R198's V2/V3 said nothing.
 *
 * The new tables do carry the physmap, so the panel is still reachable at
 *
 *     phystokv(0x9C000000) = gVirtBase + (0x9C000000 - gPhysBase)
 *
 * gVirtBase/gPhysBase are ordinary __DATA globals and survive the switch.
 * Their addresses are baked into movz/movk because a stub cannot use adrp:
 * adrp would resolve against the stub's own PC, not the hooked site's.
 *
 *     _gPhysBase = 0xFFFFFFF007178100
 *     _gVirtBase = 0xFFFFFFF007178110
 *
 * Clobbers x9..x15 (PAINT_AT owns x9..x13). */
	.macro	STAMP_PHYS xoff, colour, rows, cols
	movz	x14, #0x8100
	movk	x14, #0x0717, lsl 16		/* R200 wrote #0x0771: the two */
	movk	x14, #0xfff0, lsl 32		/* halfwords swapped, the load  */
	movk	x14, #0xffff, lsl 48		/* then missed __DATA by 5.9 MB */
	ldr	x14, [x14]			/* gPhysBase */
	movz	x15, #0x8110
	movk	x15, #0x0717, lsl 16
	movk	x15, #0xfff0, lsl 32
	movk	x15, #0xffff, lsl 48
	ldr	x15, [x15]			/* gVirtBase */
	movz	x9, #0x0000
	movk	x9, #0x9C00, lsl 16		/* frame buffer physical */
	sub	x9, x9, x14
	add	x9, x9, x15			/* its physmap alias */
	PAINT_AT x9, \xoff, \colour, \rows, \cols
	.endm

/* Stamp one square through a *freshly created* I/O mapping of the frame
 * buffer.  Needed once arm_vm_init() has replaced the bootstrap tables: from
 * then on 0x9C000000 has no virtual alias at all, and the only way back to
 * the panel is the kernel's own mapper.
 *
 * The call is the exact one initialize_screen() makes:
 *
 *     ml_io_map_unmappable(0x9C000000, size, 7)  ->  kernel VA
 *
 * so it is already known to work on this board.  Only the argument registers
 * and x30 are live at a function entry, and blr clobbers both, so exactly
 * those are spilled.  x17 carries the callee's absolute address because the
 * probe is assembled with no idea where it will be linked. */
	.macro	STAMP_IO xoff, colour
	stp	x0, x1, [sp, #-80]!
	stp	x2, x3, [sp, #16]
	stp	x4, x5, [sp, #32]
	stp	x6, x7, [sp, #48]
	stp	x8, x30, [sp, #64]
	movz	x0, #0x0000
	movk	x0, #0x9C00, lsl #16
	/* R198: 0x400000 stopped 108 KB short of row 900.  A 96 px stamp at
	 * row 900 ends at (900+96)*4320 = 4,302,720 bytes, so the old size
	 * covered the first 900 rows and nothing else -- every H-row stamp
	 * after R196 wrote past the end of its own mapping.  Use the same
	 * extent fb_lazy_map() uses. */
	movz	x1, #0x2000
	movk	x1, #0x00a6, lsl #16		/* 0xA62000 = round_page(2520*4320) */
	mov	w2, #7
	movz	x17, #0xe1b0
	movk	x17, #0x073e, lsl #16
	movk	x17, #0xffff, lsl #32
	movk	x17, #0xfff0, lsl #48		/* kernel VA base is 0xFFFFFFF0_..., not ...FFFF */
	blr	x17
	cbz	x0, 7f
	mov	x9, x0
	PAINT_AT x9, \xoff, \colour, 96, 96
7:
	ldp	x8, x30, [sp, #64]
	ldp	x6, x7, [sp, #48]
	ldp	x4, x5, [sp, #32]
	ldp	x2, x3, [sp, #16]
	ldp	x0, x1, [sp], #80
	.endm

/* Stamp a square at a *call* site.  Planting a branch over a `bl` means the
 * stub must hand control to the callee exactly as the original instruction
 * would, and a `bl` cannot be replayed from a different address.  The patcher
 * therefore fills the the sentinels below with
 *
 *   movz x30, #lo(site+4) ; movk x30, #l1, lsl 16
 *   movk x30, #l2, lsl 32 ; movk x30, #l3, lsl 48 ; b <original target>
 *
 * x30 is free at a call site: the original `bl` was about to overwrite it
 * with its own return address, so building the same value early is invisible.
 * x9..x13 are caller-saved, so the callee may trash them anyway. */
	.macro	STAMP_CALL xoff, colour
	PAINT_RECT \xoff, \colour, 48, 48
	.word	0xdead0003
	.word	0xdead0004
	.word	0xdead0005
	.word	0xdead0006
	.word	0xdead0007
	.endm

/* Add two 2 MiB identity blocks covering 0x9C000000 so the frame buffer stays
 * writable after the MMU comes on.
 *
 * in   x25 = physical address of the bootstrap L1 table (TTBR0)
 *      x2  = free page pointer inside the 64 KiB bootstrap table arena
 * out  the V=P map covers 0x9C000000..0x9C3FFFFF, or nothing changed if the
 *      arena is full.
 * Clobbers x9..x16.  Preserves x0..x8, x17..x30.
 *
 * Written as a macro, not a subroutine: x30 already holds the return address
 * to arm_init at the only call site, so "bl" is not available. */
	.macro	FB_MAP_INSTALL
	add	x9, x25, #16		/* &L1[(0x9C000000 >> 30) & 0x1ff] = &L1[2] */
	ldr	x10, [x9]
	and	x11, x10, #3
	cmp	x11, #3
	b.eq	8f			/* slot already points at an L2 table */
	cbnz	x11, 9f			/* slot already a block: nothing to add */
	/* The slot is empty.  Carve one L2 page out of the arena, refusing to
	 * run past its end (x25 + 0x10000) so a full arena cannot corrupt the
	 * tables _start has just built. */
	add	x12, x2, #1, lsl #12	/* candidate = free + 4 KiB */
	add	x13, x25, #0x10, lsl #12	/* arena end = x25 + 64 KiB */
	cmp	x12, x13
	b.hi	9f
	mov	x14, x2			/* the arena hands out 4 KiB aligned pages */
	orr	x15, x14, #3		/* table descriptor */
	str	x15, [x9]
	mov	x10, x15
8:
	/* The descriptor's low two bits are the type field (11 = table), so the
	 * table address has to be stripped of them before it is used as a base.
	 * R182: the previous version kept bits[47:0] intact and therefore stored
	 * at table+0x703 -- three bytes off -- and unaligned stores to Device
	 * memory (which is what every access is while the MMU is off) take an
	 * alignment fault.  That killed the C6 stub before it could paint. */
	lsl	x14, x10, #16
	lsr	x14, x14, #28
	lsl	x14, x14, #12		/* L2 table address, bits[11:0] cleared */
	/* valid | block | AttrIndx 3 (Device-nGnRnE) | AF, plus PXN|UXN */
	movz	x15, #0x040d
	movk	x15, #0x9c00, lsl #16
	movk	x15, #0x0060, lsl #48	/* 0x006000009C00040D */
	str	x15, [x14, #0x700]	/* L2[224] -> 0x9C000000 */
	add	x16, x15, #0x200000
	str	x16, [x14, #0x708]	/* L2[225] -> 0x9C200000 */
	dsb	sy
9:
	.endm

entry_probe:
	/* Build stamp: twelve red bars, pitch 90 px (360 bytes), width 78 px,
	 * so the last one starts at x = 990 and ends at 1068 -- still on the
	 * 1080 px panel.  0x9C000000 + 170 * 4320 = 0x9C0B34C0. */
PAINT_RECT 734400, 0x00ffffff, 70, 78		/* R233 build stamp A: tile 0 white */
PAINT_RECT 734760, 0x00ffffff, 70, 78		/* R233 build stamp B: tile 1 white */
PAINT_RECT 735120, 0x00ff0000, 70, 78
PAINT_RECT 735480, 0x00ff0000, 70, 78
PAINT_RECT 735840, 0x00ff0000, 70, 78
PAINT_RECT 736200, 0x00ff0000, 70, 78
PAINT_RECT 736560, 0x00ff0000, 70, 78
PAINT_RECT 736920, 0x00ff0000, 70, 78
PAINT_RECT 737280, 0x00ff0000, 70, 78
PAINT_RECT 737640, 0x00ff0000, 70, 78
PAINT_RECT 738000, 0x00ff0000, 70, 78
PAINT_RECT 738360, 0x00ff0000, 70, 78

	dsb	sy

entry_probe_tail:
	/* placeholder: the patch script replaces this with a branch to the
	 * kernel's entry stub. */
	.word	0x14000000

/* ------------------------------------------------------------------ *
 * The ladder.  C1..C6 run with the MMU off; C6 also installs the frame
 * buffer mapping; C7..C8 run with it on.
 * ------------------------------------------------------------------ */

	/* C1: 0x9C000000 + 280 * 4320 + 0 * 4 = 0x9C127500 */
	.global stage_probe_1
	.global stage_probe_1_end
stage_probe_1:
	PAINT_RECT 1209600, 0x00ff00ff, 96, 96		/* magenta */
	.word	0xdead0001
	.word	0xdead0002
stage_probe_1_end:

	/* C2: + 144 * 4 */
	.global stage_probe_2
	.global stage_probe_2_end
stage_probe_2:
	PAINT_RECT 1210176, 0x0000ffff, 96, 96		/* cyan */
	.word	0xdead0001
	.word	0xdead0002
stage_probe_2_end:

	/* C3: + 288 * 4 */
	.global stage_probe_3
	.global stage_probe_3_end
stage_probe_3:
	PAINT_RECT 1210752, 0x00ff8000, 96, 96		/* orange */
	.word	0xdead0001
	.word	0xdead0002
stage_probe_3_end:

	/* C4: + 432 * 4 */
	.global stage_probe_4
	.global stage_probe_4_end
stage_probe_4:
	PAINT_RECT 1211328, 0x00ffff00, 96, 96		/* yellow */
	.word	0xdead0001
	.word	0xdead0002
stage_probe_4_end:

	/* C5: + 576 * 4 */
	.global stage_probe_5
	.global stage_probe_5_end
stage_probe_5:
	PAINT_RECT 1211904, 0x00800080, 96, 96		/* violet */
	.word	0xdead0001
	.word	0xdead0002
stage_probe_5_end:

	/* C6: + 720 * 4.  Last stop before the MMU.
	 *
	 * R182 order matters: paint FIRST, then install the frame buffer
	 * mapping.  R181 did it the other way round, so when the mapping code
	 * faulted the square never appeared and the failure looked like "the
	 * kernel never reached C6".  Now white means "reached C6", green means
	 * "the mapping install finished". */
	.global stage_probe_6
	.global stage_probe_6_end
stage_probe_6:
	PAINT_RECT 1212480, 0x00ffffff, 96, 96		/* white */
	FB_MAP_INSTALL
	PAINT_RECT 1213056, 0x0000ff00, 96, 96		/* green: mapping installed */
	.word	0xdead0001
	.word	0xdead0002
stage_probe_6_end:

	/* C7: 0x9C000000 + 420 * 4320 = 0x9C1BAE00.  First fetch with the MMU
	 * on -- everything below this line is new evidence. */
	/* C8: + 144 * 4 */
/* ------------------------------------------------------------------ *
 * Row 560: the ladder inside arm_init.  Same palette order as row 280,
 * so slot 1 is always magenta, slot 2 cyan, and so on.  Slots 1..3 are
 * still under the bootstrap tables and use the physical address; from
 * slot 4 on arm_vm_init has swapped the tables and the only way back to
 * the panel is a fresh ml_io_map_unmappable().
 * ------------------------------------------------------------------ */

	/* S1: 0x9C000000 + 560 * 4320 = 0x9C24E400 */

/* ------------------------------------------------------------------ *
 * R187: inside do_cacheid(), which R186 proved never returns (row 700
 * reached C7 = `bl do_cacheid` and stopped there).
 *
 * do_cacheid is the first function in the boot that calls kprintf(), and
 * kprintf only emits bytes because of the R175 gate patches, so "my own
 * patch is what hangs" is a live suspect.  D4 sits immediately after the
 * first kprintf: D3 (the call, cyan) lit but D4 dark means kprintf hangs.
 *
 * Row 760, six 48 x 48 squares, x = 0, 100, ... 500.
 * ------------------------------------------------------------------ */

	/* D1..D6: 0x9C000000 + 760 * 4320 = 0x9C321800, +400 bytes (100 px) each. */






/* ------------------------------------------------------------------ *
 * R194: the F row (row 210) -- cpu_init() after do_cacheid().
 *
 *   F1 white  bl do_debugid issued
 *   F2 white  bl cpuid_info issued
 *   F3 green  the arm_arch switch took the OK path (subtype stored)
 *   F4 red    the switch took the DEFAULT path -- bl panic("Unknown
 *             CPU subtype").  If this is the only lit F block, the
 *             death is the CPU subtype panic, nothing else.
 *
 * Four 48 x 48 squares at panel x = 104, 156, 208, 260.
 * ------------------------------------------------------------------ */

/* ------------------------------------------------------------------ *
 * R195: the two gaps R194 left open.  Its F row (row 210) stamps "bl
 * cpuid_info was issued" but nothing recorded the return, so a lit F2
 * could not separate a hang inside cpuid_info from a later one.  These
 * two squares extend the D row (row 760) at x = 600 and 700, so the
 * whole cpu_init answer reads off one line:
 *
 *   P1  x=600  white  cpuid_info RETURNED -- x0 held its result and the
 *                     load of that result was reached
 *   P2  x=700  green  cpu_init ran to its epilogue and tail-branched out
 *
 * Row 760, so: 0x9C000000 + 760 * 4320 = 0x9C321800, + 600 * 4 = 0x9C321D60.
 * ------------------------------------------------------------------ */






/* ------------------------------------------------------------------ *
 * R196: arm_init() after cpu_init().
 *
 * R195 answered its own question: cpuid_info came back (row 760 x=600
 * white) and cpu_init ran to its epilogue (row 760 x=700 green).  So the
 * death is not in cpu_init any more, it is in whoever called it.  That
 * function is arm_init(), and the three squares below separate its
 * remaining steps:
 *
 *   G1 x=0    white  cpu_init returned -- the caller's next instruction
 *                    (0x73E166C) ran, so the "cpu_init never returns"
 *                    reading from R186 is finally dead
 *   G2 x=100  white  arm_init issued bl processor_bootstrap (0x79C2EC8)
 *   G3 x=200  white  arm_init finished the boot-arg parses and built
 *                    arm_vm_init's arguments (0x79C2F4C)
 *
 * Row 820, 48 px squares: 0x9C000000 + 820 * 4320 = 0x9C360C00.
 * ------------------------------------------------------------------ */


/* ------------------------------------------------------------------ *
 * R196, second row (900): everything past arm_vm_init.
 *
 * The call itself (0x79C2F50) is already redirected to blob_stage1, so the
 * first square sits on the load three instructions later -- lit means
 * arm_vm_init RETURNED, dark means the death is inside it.
 *
 * These run after arm_vm_init has replaced the bootstrap tables, so the
 * frame buffer's physical address is no longer reachable by a plain store:
 * each square is painted through a fresh ml_io_map_unmappable(), the same
 * call initialize_screen() makes.
 *
 *   H1 x=0    white  arm_vm_init returned              (0x79C2F5C)
 *   H2 x=120  cyan   bl 0x792f1b4                      (0x79C2F68)
 *   H3 x=240  cyan   bl 0x79313a4                      (0x79C2F6C)
 *   H4 x=360  cyan   bl 0x799a174                      (0x79C2F78)
 *   H5 x=480  green  bl kprintf("kprintf initialized") (0x79C2F84)
 *
 * Row 900, 96 px squares: 0x9C000000 + 900 * 4320 = 0x9C3B5200.
 * ------------------------------------------------------------------ */



/* ------------------------------------------------------------------ *
 * R197: bisecting arm_init()'s straight run after processor_bootstrap.
 *
 * R196 lit row 820 x=100, so arm_init DID issue `bl processor_bootstrap`
 * (0x79C2EC8 -> 0x72A4364).  Nothing after it could be confirmed: the two
 * STAMP_IO sites at row 900 were planted with a broken constant -- the
 * stub built 0xFFFFFFFF_073EE1B0 instead of 0xFFFFFFF0_073EE1B0 -- so they
 * jumped 60 GB past the kernel and faulted (or were never reached, which
 * the panel cannot distinguish).  That is fixed in the macro this round.
 *
 * So the straight run is split in two with cheap stores that still work:
 * the bootstrap tables are alive until 0x79C2F50, so both marks are plain
 * frame-buffer writes.
 *
 *   G3 x=200  white  processor_bootstrap RETURNED -- 0x79C2ED8 (`mov w2,#4`)
 *                     is the third instruction of the next statement
 *   G4 x=300  white  arm_vm_init's arguments are ready -- 0x79C2F4C is
 *                     `mov x0, x19`, the last instruction before the call
 *
 * Row 820, 48 px squares: 0x9C000000 + 820 * 4320 = 0x9C360C00.
 * ------------------------------------------------------------------ */

	.global stage_probe_9
	.global stage_probe_9_end
stage_probe_9:
	PAINT_RECT 2419200, 0x00ff00ff, 96, 96		/* PE_init_platform: magenta from R193 */
	.word	0xdead0001
	.word	0xdead0002
stage_probe_9_end:

/* ------------------------------------------------------------------ *
 * R198: inside arm_vm_init().
 *
 * R197 answered the caller question and raised a new one.  Its four
 * squares read:
 *
 *   row 820 x=0    DARK    arm_init_cpu's cpu_init never ran (expected:
 *                          the boot CPU comes through arm_init)
 *   row 820 x=100  WHITE   arm_init issued bl processor_bootstrap
 *   row 820 x=200  WHITE   processor_bootstrap RETURNED (0x79C2ED8 ran)
 *   row 820 x=300  WHITE   arm_vm_init's arguments were ready (0x79C2F4C)
 *
 * and then nothing: row 900 and the green stage_mark(1) at row 170 x=320
 * are both dark, and blob_stage1 calls stage_mark(1) immediately after
 * arm_vm_init returns.  Two independent marks for "arm_vm_init returned"
 * are dark, so the death is inside arm_vm_init itself.
 *
 * These three split it:
 *
 *   V1 row 560 x=144  cyan    arm_vm_init ENTERED -- 0x73E25C0 is the
 *                             function's first instruction, so this also
 *                             proves the blob_stage1 redirect landed
 *   V2 row 560 x=288  orange  reached the pmap_bootstrap call -- 0x73E34DC
 *                             is the `mov x0, x20` right before it
 *   V3 row 940 x=0    white   pmap_bootstrap AND __disable_preemption both
 *                             returned -- 0x73E34E8 is the first
 *                             instruction after the two back-to-back calls
 *                             (`bl pmap_bootstrap` at 0x73E34E0, `bl
 *                             __disable_preemption` at 0x73E34E4), stamped
 *                             through a fresh I/O mapping because by then
 *                             the bootstrap tables may be gone
 *
 * Offsets: row 560 -> 560*4320 = 2419200, +144*4 = 2419776, +288*4 = 2420352.
 *         row 940 -> 940*4320 = 4060800.
 * ------------------------------------------------------------------ */

	.global stage_probe_46
	.global stage_probe_46_end
stage_probe_46:
	PAINT_RECT 2419776, 0x0000ffff, 96, 96		/* arm_vm_init entered */
	.word	0xdead0001
	.word	0xdead0002
stage_probe_46_end:

/* ------------------------------------------------------------------ *
 * R199: the ladder that R198 should have used.
 *
 * R198 lit V1 (arm_vm_init entered) and left V2 dark, which naively
 * reads as "died between 0x73E25C0 and 0x73E34DC".  That reading is
 * wrong: 0x73E3114 is `bl set_mmu_ttb`, and everything after it runs
 * on the brand-new kernel page tables where the frame buffer has no
 * identity mapping.  PAINT_RECT writes a raw physical address, so a
 * dark square past 0x73E3114 proves nothing at all -- the store simply
 * went somewhere else.
 *
 * So all four stops below sit BEFORE the table switch, where the
 * identity block is still alive.  Together with stage_probe_46 they cut
 * 0x73E25C0..0x73E3114 into five pieces:
 *
 *   P1 row 560 x=288  orange  0x73E2884  mov  x20, x0   (after phystokv)
 *   P2 row 560 x=432  yellow  0x73E2E44  ldr  x8,[x8,#0x158] (after
 *                                       vm_set_page_size returned)
 *   P3 row 560 x=576  white   0x73E2F60  mov  x22, x0   (after
 *                                       arm_vm_prot_init returned)
 *   P4 row 560 x=720  green   0x73E30FC  and  x0,x8,#0xffffffffffff
 *                                       (last instruction before the
 *                                        set_mmu_ttb_alternate call)
 *
 * Offsets: row 560 -> 2419200, +288*4 = 2420352, +432*4 = 2420928,
 *         +576*4 = 2421504, +720*4 = 2422080.
 * ------------------------------------------------------------------ */





/* ------------------------------------------------------------------ *
 * R200: the three stops past the TTBR1 switch.
 *
 * R199 lit every square up to 0x73E30FC and then nothing, and the panel
 * never reset -- so the machine did not triple-fault, it just went quiet.
 * The first instruction after that last square is
 *
 *   0x73E3100  bl set_mmu_ttb_alternate   <- TTBR1 = cpu_ttep (the switch)
 *   0x73E3114  bl set_mmu_ttb             <- TTBR0 = invalid_ttep
 *
 * and from 0x73E3100 on there is no identity mapping for 0x9C000000 any
 * more, which is why every PAINT_RECT after it in R198 came back dark.
 * These three use STAMP_PHYS instead: they write through the physmap alias
 * that the new tables are guaranteed to carry, so a dark square here really
 * does mean "never got there".
 *
 *   W1 row 660 x=0    white  0x73E3118  tlbi vmalle1is  (first instruction
 *                             that runs on the new tables)
 *   W2 row 660 x=144  green  0x73E31D4  ldr x9,[x23,#0x108] (arm_auxkc_init
 *                             returned)
 *   W3 row 660 x=288  cyan   0x73E34DC  mov x0, x20  (pmap_bootstrap args
 *                             ready -- the old R198 V2 site, now readable)
 *
 * Offsets: row 660 -> 660*4320 = 2851200, +144*4 = 2851776, +288*4 = 2852352.
 * ------------------------------------------------------------------ */

/* ------------------------------------------------------------------ *
 * R219: the ladder past the TTBR1 switch, on two virgin bands.
 *
 * R218 died on the first touch of __DATA_CONST after the switch.  The
 * cause was not the switch: tools/patch-dataconst-align.py had rounded
 * segDATACONSTB down to a 2 MB boundary before handing it to
 * arm_vm_page_granular_prot(), which moved the whole protected range
 * from __DATA_CONST (0xfffffff007168000..0xfffffff007240000) down into
 * __TEXT (0xfffffff007000000..0xfffffff0070d8000).  __DATA_CONST was
 * therefore never given an L3 mapping at all, and the first access to it
 * under the new TTBR1 -- the _kva_active store, then *cpu_ttep, then
 * phystokv() reading ptov_table[0].len -- aborted.  R219 undoes that
 * patch (tools/patch-dataconst-unalign.py).
 *
 * The probe now has one extra stop, between phystokv() and the cpu_tte
 * store, because that is the first instruction that is only reachable if
 * the page 0xfffffff007178000 -- the one holding _kva_active, ptov_table,
 * gPhysBase and gVirtBase -- is mapped again.  A blue square there is the
 * proof that the fix took.
 *
 * Rows.  `fastboot boot` does not clear the framebuffer, and every block
 * painted by an earlier round is still there.  The blocks in this ladder
 * are 96 px tall, so a row 600 block covers rows 600..695 and a row 620
 * block covers 620..715: R218's own row 600/620 blocks sit on top of
 * everything below row 690.  Below row 690 the only bands no earlier
 * round has ever painted are
 *
 *     376..419   (between the row 280 ladder's last row and row 420)
 *     516..559   (between row 420's last row and row 560)
 *
 * so R219 uses two 40 px tall blocks in those bands.  40 px is enough to
 * read off a phone camera and it keeps the two bands clear of everything.
 *
 *     row 378 x=0    violet   0x73E30FC  last instruction before the switch
 *     row 378 x=144  orange   0x73E311C  dsb ish
 *     row 378 x=288  yellow   0x73E3120  isb -- first fetch on the new TTBR1
 *     row 378 x=432  green    0x73E3128  _kva_active store -- SKIPPED
 *     row 378 x=576  cyan     0x73E312C  ldr x0,[x27] -- *cpu_ttep
 *     row 378 x=720  blue     0x73E3140  phystokv() RETURNED -- 0x7178000
 *     row 518 x=0    magenta  0x73E3144  cpu_tte store
 *     row 518 x=144  red      0x73E3158  invalid_tte store
 *     row 518 x=288  white    0x73E34E8  pmap_bootstrap returned
 *
 * Offsets: row 378 -> 378*4320 = 1632960, +144*4 = 1633536, +288*4 = 1634112,
 *          +432*4 = 1634688, +576*4 = 1635264, +720*4 = 1635840.
 *          row 518 -> 518*4320 = 2237760, +144*4 = 2238336, +288*4 = 2238912.
 * ------------------------------------------------------------------ */

	.global stage_probe_70
	.global stage_probe_70_end
stage_probe_70:
	PAINT_RECT 1632960, 0x00800080, 40, 96		/* R219 row 378 x=0 violet: 0x73E30FC, last insn before the TTBR1 switch */
	.word	0xdead0001
	.word	0xdead0002
stage_probe_70_end:

	.global stage_probe_66
	.global stage_probe_66_end
stage_probe_66:
	PAINT_RECT 1633536, 0x00ff8000, 40, 96		/* R219 row 378 x=144 orange: 0x73E311C dsb ish */
	.word	0xdead0001
	.word	0xdead0002
stage_probe_66_end:

	.global stage_probe_76
	.global stage_probe_76_end
stage_probe_76:
	PAINT_RECT 1634112, 0x00ffff00, 40, 96		/* R219 row 378 x=288 yellow: 0x73E3120 isb -- first fetch on the new TTBR1 */
	.word	0xdead0001
	.word	0xdead0002
stage_probe_76_end:

	.global stage_probe_71
	.global stage_probe_71_end
stage_probe_71:
	PAINT_RECT 1634688, 0x0000ff00, 40, 96		/* R219 row 378 x=432 green: 0x73E3128 _kva_active store -- SKIPPED */
	dsb	ish
	.word	0xdead0007
stage_probe_71_end:

	.global stage_probe_72
	.global stage_probe_72_end
stage_probe_72:
	PAINT_RECT 1635264, 0x0000ffff, 40, 96		/* R219 row 378 x=576 cyan: 0x73E312C ldr x0,[x27] -- *cpu_ttep */
	.word	0xdead0001
	.word	0xdead0002
stage_probe_72_end:

	.global stage_probe_77
	.global stage_probe_77_end
stage_probe_77:
	PAINT_RECT 1635840, 0x000000ff, 40, 96		/* R219 row 378 x=720 blue: 0x73E3140 -- phystokv() returned, 0x7178000 readable */
	.word	0xdead0001
	.word	0xdead0002
stage_probe_77_end:

	.global stage_probe_73
	.global stage_probe_73_end
stage_probe_73:
	PAINT_RECT 2237760, 0x00ff00ff, 40, 96		/* R219 row 518 x=0 magenta: 0x73E3144 cpu_tte store */
	.word	0xdead0001
	.word	0xdead0002
stage_probe_73_end:

	.global stage_probe_74
	.global stage_probe_74_end
stage_probe_74:
	PAINT_RECT 2238336, 0x00ff0000, 40, 96		/* R219 row 518 x=144 red: 0x73E3158 invalid_tte store */
	.word	0xdead0001
	.word	0xdead0002
stage_probe_74_end:

	.global stage_probe_75
	.global stage_probe_75_end
stage_probe_75:
	PAINT_RECT 2238912, 0x00ffffff, 40, 96		/* R219 row 518 x=288 white: 0x73E34E8 pmap_bootstrap returned */
	.word	0xdead0001
	.word	0xdead0002
stage_probe_75_end:
/* C7 / C8 belong to STAGE_SITES, not to the optional call ladder: they are
 * the only proof that the first fetch with the MMU on happened at all.
 * R198 briefly retired them by accident and the patcher refused to build;
 * restored here so the list in patch-xnu-console-blob.py stays complete. */
	.global stage_probe_7
	.global stage_probe_7_end
stage_probe_7:
	PAINT_RECT 1814400, 0x000000ff, 96, 96		/* first fetch, MMU on */
	.word	0xdead0001
	.word	0xdead0002
stage_probe_7_end:

	.global stage_probe_8
	.global stage_probe_8_end
stage_probe_8:
	PAINT_RECT 1814976, 0x00ff0000, 96, 96		/* arm_init entered */
	.word	0xdead0001
	.word	0xdead0002
stage_probe_8_end:
