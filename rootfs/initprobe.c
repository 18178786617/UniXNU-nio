/*
 * initprobe.c -- /sbin/launchd fixture for the nio XNU port.
 *
 * R100 proved where the GMU bring-up stops and why. The firmware load
 * completed: 32 op 10 writes of 512 bytes each went into the ITCM and DTCM
 * windows with no error, and the file was read whole. The version word in
 * the DTCM read 0x20010008 and the ITCM's vector table read 0x10007f80,
 * 0x11, 0x71, 0x99 -- the firmware is in the TCM, byte for byte the a650's
 * image. The run then stopped at the release of the CM3: the last progress
 * mark was 0x0a, the write of GMU_CM3_SYSRESET = 0, and the mark for 0x0b
 * never came.
 *
 * R100 also showed that the SMMU is not what R99 guessed: from EL0 the GPU
 * SMMU takes writes. The SMR words read back what was written, and the S2CR
 * normalisation took. So the SMMU is usable from this process.
 *
 * What R99 guessed wrong was the missing piece. The GMU is a master on that
 * SMMU: every address it uses is translated, and with no context bank
 * programmed for it the transactions fault and the firmware waits for a
 * response that never comes. That is what R101 builds.
 *
 * The context is built the way UniXNU-alioth's GpuProbe.cpp built it, with
 * the same kit (ArmSmmu4K) and the same numbers:
 *
 *   - bank 1, ASID 1. The bank's register file sits at (pages + bank) *
 *     stride inside the SMMU window, which is 0x9000 for this part.
 *   - the context image ArmSmmu4KContext.c encodes for a 32 bit input
 *     address space, a 36 bit output address space, a coherent walk, no
 *     stall on fault and continue after fault: CBAR 0x1f300, CBA2R 1,
 *     TCR 0x80803520, TCR2 0x38011, MAIR0 0xff44, SCTLR 0x1167.
 *   - the GMU's two streams in the slots 2 and 3, with the SIDs 5 and
 *     0x405. nio's device tree agrees: the GMU's kernel context is the
 *     stream 5 under the mask 0x400, so the two stream ids are 5 and
 *     0x405.
 *   - a three level page table: the root covers 4 GiB, the level 2 tables
 *     2 MiB each and the leaves 4 KiB each, which is the geometry
 *     ArmSmmu4KLive.c walks with a 32 bit input address space.
 *
 * Six regions are mapped, the ones UniXNU-alioth's A650Gmu.c and
 * NativeAdrenoGmuMemory.cpp lay out for this family:
 *
 *   0x00004000  the icache, the firmware's own code (the block there ends
 *               at 0x95d0; the first word is 0x2de9f843, "stp x29, x30,
 *               [sp, #-16]!", so it is AArch64 and not the CM3's Thumb)
 *   0x00144000  the firmware's declared scratch, 0x13000 bytes
 *   0x00157000  the debug block, 0x398 bytes of tables
 *   0x60000000  the dummy page
 *   0x60004000  the log, the buffer PWR_COL_CP_MSG names
 *   0x60008000  the HFI queue table and its three rings, 16 KiB
 *
 * The first two of those carry firmware bytes, and they are the reason
 * this round exists: R100 put zeroes there and would have released the
 * CM3 into an icache with no code in it. The bytes come from the
 * container's own blocks, the CPU writes them into kernel pages through
 * op 12, and the SMMU translates the GMU's accesses to those pages.
 *
 * A page table needs physical pages, and an EL0 process cannot get them:
 * op 11 asks the kernel for a page (zeroed, and cleaned to memory), and op
 * 12 writes the descriptors through the kernel's own alias and cleans them
 * too, so the CPU's cache and the SMMU's walk of the same bytes agree.
 *
 * The bring-up itself is unchanged from R99 and follows Linux v6.6's
 * a6xx_gmu.c for the a650 family, as UniXNU-alioth's package/pipa/A650Gmu.c
 * spells it out:
 *
 *   phase 1  the GMU is held in reset, the RSC sequencer is idle, no stale
 *            HFI readiness
 *   phase 2  the interrupt clear and mask, the RSC sequencer's own setup
 *            (the a650's sleep and wake microcode, the PDC sequence pointer,
 *            the PDC), then a6xx_rpmh_stop
 *   phase 3  a6xx_gmu_fw_start (cold): the FAL retention interfaces,
 *            GENERAL_7, the RSC wake request and its acknowledge
 *   phase 4  the firmware into the CM3's TCM
 *   phase 5  the boot registers, each read back, and a6xx_gmu_power_config
 *   phase 6  a6xx_gmu_start: reset, the power-collapse response, the
 *            release, and the firmware's own ready value in FW_INIT_RESULT
 *   phase 7  a6xx_gmu_hfi_start
 *
 * The release is guarded twice: the context bank has to read back exactly
 * what was written, and the streams have to be attached, or the CM3 is left
 * in reset with everything on the screen. R99's guess that the CM3 would
 * boot without a context cost a round; this one does not guess.
 *
 * Constraints imposed by the Mach-O wrapper:
 *   - __TEXT is R+X only, no writable segment, so NO writable globals: every
 *     buffer lives on the stack (the kernel sets sp via thread_setuserstack()).
 *   - freestanding, no libc, no TLS, no stack protector, no SIMD.
 */

#include "uio.h"

#define CHUNK       512u                /* bytes per write(4) frame */
#define CMD_WORDS   (3u + CHUNK / 4u)   /* op + addr + len + payload */
#define RES_BYTES   160u                /* the kernel's answer, in bytes */

/* fd4 opcodes, the same ones the kernel blob implements */
#define OP_MR       7u
#define OP_TEXT     8u
#define OP_MW       9u
#define OP_MWB      10u                /* a run of dwords inside one page */
#define OP_ALLOC    11u                /* one 4 KiB kernel page */
#define OP_WVA      12u                /* dwords into a kernel page, by VA */

/* fd4 result words */
#define R_STATUS    1u
#define R_RAW       16u
#define MR_MAX      24u                /* 40 result words, 16 of them header */

/* The flattened firmware image: 16 KB of ITCM then 16 KB of DTCM */
#define FW_BYTES    0x8000u
#define FW_CHUNKS   (FW_BYTES / CHUNK)

/* GCC: the GPU's branches, and the separate GPLL0 vote page */
#define G_CFG_AHB     0x00171004u
#define G_MEMNOC      0x0017100Cu
#define G_AXI         0x00171154u
#define G_PLL_VOTE    0x00152000u
/* GPUCC, base 0x03d90000 */
#define C_CX_GDSCR    0x03D9106Cu
#define C_AHB_CLK     0x03D91078u
#define C_CX_GMU_CLK  0x03D91098u
#define C_CXO_CLK     0x03D9109Cu
#define C_SMMU_VOTE   0x03D95000u
#define C_GDS_HWCTRL  0x03D91540u
#define C_GMU_RCGR    0x03D91120u
/* R116: the GX branch's own power register and the GPU core's register
 * window.  The GPU window is the DTS kgsl_3d0_reg_memory at 0x03d00000;
 * RBBM_STATUS is dword 0x210 of it, so 0x03d00000 + 0x210 * 4.  A non-zero
 * RBBM_STATUS is the GPU's own answer: the register bank is running. */
#define C_GX_GDSCR    0x03D9100Cu
#define G_RBBM_STATUS 0x03D00840u
/* R117: the AOP command database, in ordinary memory.  GpuPowerBoard.h
 * names it GPB_CMD_DB_BASE with a 0x20000 byte window and the magic
 * 0x0c0330db in its second word; the data area starts 144 bytes in. */
#define CMDB_BASE     0x80860000u
#define CMDB_MAGIC    0x0C0330DBu
#define CMDB_DATA     144u
#define CMDB_BYTES    0x20000u

/* The GMU's own register blocks, as the alioth A650Gmu.c numbers them
 * (a6xx_gmu.xml.h dword offsets from the GMU base 0x03d6a000; 4 * dword is
 * the byte offset). The dword offsets are the chip's, not the board's: the
 * nio device tree agrees with the alioth tree on every window this touches. */
#define M_ITCM        0x03D6D000u      /* CM3_ITCM_START,  dword 0x0c00 */
#define M_DTCM        0x03D71000u      /* CM3_DTCM_START,  dword 0x1c00 */
#define M_CM3_SYSRESET 0x03D7E000u     /* dword 0x5000 */
#define M_CM3_BOOTCFG 0x03D7E004u      /* dword 0x5001 */
#define M_CM3_FW_INIT 0x03D7E070u      /* dword 0x501c */
#define M_CM3_CFG     0x03D7E0B4u      /* dword 0x502d */
#define M_ICACHE_CFG  0x03D7D000u      /* dword 0x4c00 */
#define M_DCACHE_CFG  0x03D7D004u      /* dword 0x4c01 */
#define M_SYS_BUS_CFG 0x03D7D03Cu      /* dword 0x4c0f */
#define M_HFI_STATUS  0x03D7E600u      /* dword 0x5180 */
#define M_HFI_SFR     0x03D7E608u      /* dword 0x5182 */
#define M_HFI_QINFO   0x03D7E610u      /* dword 0x5184 */
#define M_HFI_QADDR   0x03D7E614u      /* dword 0x5185 */
#define M_HFI_INIT    0x03D7E618u      /* dword 0x5186 */
#define M_CP_MSG      0x03D7E400u      /* dword 0x5100 */
#define M_CP_RESP     0x03D7E404u      /* dword 0x5101 */
#define M_IFPC        0x03D7E300u      /* dword 0x50c0 */
#define M_RPMH        0x03D7E3A0u      /* dword 0x50e8 */
#define M_FAL         0x03D7E3C0u      /* dword 0x50f0 */
#define M_FALNEXT     0x03D7E3C4u      /* dword 0x50f1 */
#define M_GEN7        0x03D7E730u      /* dword 0x51cc */
/* R97 had these two one bank low: 0x03d7e244/0x03d7e248 are dword 0x5091
 * and 0x5092, but a6xx_gmu.xml.h puts GMU2HOST at 0x5191/0x5192. */
#define M_GM2CLR      0x03D7E644u      /* dword 0x5191 */
#define M_GM2INFO     0x03D7E648u      /* dword 0x5192 */
#define M_GM2MASK     0x03D7E64Cu      /* dword 0x5193 */
/* R114: the host-to-GMU interrupt. The official writes bit 0 here to tell
 * the CM3 that a message is waiting in the HFI queue, and bit 30 to ask it
 * to apply a GX power vote; the CM3 answers on GMU2HOST bit 31. */
#define M_H2G_SET     0x03D7E650u      /* dword 0x5194 */
#define M_AO_CLR      0x03D8EC10u      /* dword 0x9304 */
#define M_AO_STATUS   0x03D8EC14u      /* dword 0x9305 */
#define M_AO_MASK     0x03D8EC18u      /* dword 0x9306 */
#define M_RSCC_REQ    0x03D8EC1Cu      /* dword 0x9307 */
#define M_RSCC_ACK    0x03D8EC20u      /* dword 0x9308 */
#define M_FENCE       0x03D8EC44u      /* dword 0x9311 */
/* R114: the SPTPRAC power/clock status. GX is on when neither
 * GX_HM_GDSC_POWER_OFF (bit 6) nor GX_HM_CLK_OFF (bit 7) is set. */
#define M_SPTC_PWR    0x03D7E340u      /* dword 0x50d0 */
/* The RSCC block, 0x3de0000, and the PDC block, 0xb290000. */
#define R_SC_STATUS0  0x03DE0010u
#define R_SEQ_BUSY    0x03DE0404u

/* The GPU SMMU: the whole 64 KB window the nio device tree gives
 * (kgsl-smmu@3da0000, size 0x10000). This is the Qualcomm qsmmu-v500
 * variant: the identity registers sit at 0x20/0x24/0x28 and the stream
 * match and context descriptor registers are 32 bits apart, not 64. */
#define S_BASE        0x03DA0000u
#define S_CR0         (S_BASE + 0x000u)
#define S_IDR0        (S_BASE + 0x020u)
#define S_IDR1        (S_BASE + 0x024u)
#define S_IDR2        (S_BASE + 0x028u)
#define S_GFSR        (S_BASE + 0x048u)
#define S_GFSY0       (S_BASE + 0x050u)
#define S_GFSY1       (S_BASE + 0x054u)
#define S_GFSY2       (S_BASE + 0x058u)
#define S_SMR0        (S_BASE + 0x800u)
#define S_S2CR0       (S_BASE + 0xc00u)
#define S_WINDOW      0x10000u
/* R99: the SMMUv3 global registers that name the context banks. Their exact
 * offsets are the thing R98 got wrong, so R99 reads the candidates and
 * prints them rather than trusting one. */
#define S_CBAR0       (S_BASE + 0x1000u)
#define S_CBA2R0      (S_BASE + 0x1800u)

/* R101: the GMU's SMMU context. The context bank's register file sits at
 * (pages + bank) * stride inside the SMMU window, and its own registers are
 * at the offsets ArmSmmu4KProgram.c uses. The bank's own attributes are the
 * two global registers that name it: CBARn at stride + 4n and CBA2Rn at
 * stride + 0x800 + 4n, so bank 1 is at 0x1004 and 0x1804. R100 read bank 0's
 * (0x1000 and 0x1800) and saw zeros, which is what an unused bank holds. */
#define CB_CTL      0x000u              /* SCTLR */
#define CB_TCR2     0x010u
#define CB_TTBR0    0x020u              /* 64 bit */
#define CB_TTBR1    0x028u              /* 64 bit */
#define CB_TCR      0x030u
#define CB_MAIR0    0x038u
#define CB_MAIR1    0x03Cu
#define CB_FSR      0x058u
#define CB_FAR      0x200u              /* the address that was refused */
#define CB_IFSR     0x208u              /* what kind of fault it was */
#define CB_TLBIASID 0x610u
#define CB_TLBSYNC  0x7F0u
#define CB_TLBSTAT  0x7F4u

/* The context image ArmSmmu4KContext.c encodes for a 32 bit input address
 * space, a 36 bit output address space, a coherent walk, no stall on fault
 * and continue after fault: exactly what UniXNU-alioth programmed. */
#define CTX_CBAR    0x0001F300u
#define CTX_CBA2R   0x00000001u
#define CTX_TCR     0x80803520u
#define CTX_TCR2    0x00038011u
#define CTX_MAIR0   0x0000FF44u
#define CTX_MAIR1   0x00000000u
#define CTX_SCTLR   0x00001167u
#define CTX_ASID    1u

/* The leaf descriptors ArmSmmu4KLive.c builds, for the two classes the
 * GMU's buffers fall into. The kit's descriptor() is
 *   (1<<11)|(1<<10)|3|(shareability<<8), plus 3<<53 when the range is not
 * executable, plus 1<<6 when it is not privileged, plus 1<<2 when it is
 * write-back; UniXNU-alioth maps the GMU's buffers with writeback 0 (Normal
 * non-cacheable) and shareability 2 (outer shareable), so the share bits are
 * 2<<8 = 0x200 and bit 2 stays clear.
 *
 * The icache is the one region the GMU executes from, so it is executable
 * and privileged; the rest are data. Both leave bit 6 clear, which allows
 * privileged accesses: the GMU's kernel stream is a privileged master and a
 * page that only allowed unprivileged accesses would fault it. */
/* A leaf descriptor, from ArmSmmu4KLive.c's descriptor():
 *   (1<<11) | (1<<10) | 3 | (shareability << 8), plus 3<<53 when the range is
 *   not executable, plus 1<<6 when it is not privileged, plus 1<<7 when it is
 *   not writable, plus 1<<2 when it is write-back.
 *
 * alioth's NativeAdrenoGmuAllocator maps the icache with permissions 15
 * (read, write, execute, privileged) and every other buffer with 3 (read,
 * write), both with writeback 0 and shareability 2 (outer). That is what the
 * kit turns into these two words, and they are the words the real driver
 * put in this SMMU's tables. */
#define DESC_ICACHE 0x0000000000000E03u
#define DESC_DATA   0x0060000000000E43u

/* The GMU's streams, as UniXNU-alioth's GpuProbe.cpp programmed them: the
 * stream slots 2 and 3 with the SIDs 5 and 0x405, the slots 0, 1, 4 and 5
 * left to the GPU. */
#define GMU_SLOT_A  2u
#define GMU_SLOT_B  3u
#define GMU_SID_A   5u
#define GMU_SID_B   0x405u
#define SMR_VALID   0x80000000u
#define S2CR_FAULT  0x00020000u
#define S2CR_BANK   0x00000001u

/* The GMU's own memory, as iovas.
 *
 * The firmware container declares its regions itself: the icache region at
 * 0x4000 (0x8000 bytes, the payload filling 0x4000..0x95cf), the scratch at
 * 0x144000 (0x13000 bytes), the debug block at 0x157000 (0x9000 bytes, the
 * payload filling 0x157000..0x157397) and the dummy page at 0x60000000.
 * UniXNU-alioth maps the first three as one buffer: its icache mapping runs
 * from 0x4000 for 16 MiB minus 16 KiB, so the scratch and the debug block
 * are inside it and the payload at 0x157000 lands at its own address. The
 * log (0x60004000) and the HFI queues (0x60008000) sit right after the
 * dummy page, the way a6xx_gmu.c puts them.
 *
 * R107: the dummy and the log are 16 KiB each, not one page.  The sizes are
 * fixed by arithmetic, not by a guess: the log is at 0x60004000 and the HFI
 * queues at 0x60008000, so the dummy holds everything from 0x60000000 up to
 * the log -- 0x4000 bytes -- and the log itself is 0x4000 bytes.  That is
 * the same triple the a650's own driver uses (Adreno650's
 * NativeAdrenoGmuConfig.cpp: DummyBytes = LogBytes = HfiBytes = 0x4000, with
 * the three iovas computed as base, base + dummy, base + dummy + log).
 *
 * R106 had this wrong in a way that could not work: the boot register
 * PWR_COL_CP_MSG was written as LOG_IOVA | 3, which tells the firmware the
 * log buffer is four pages long, but only one page of it was mapped.  The
 * moment the firmware wrote past 0x60005000 it would have taken an SMMU
 * translation fault.  The firmware never got that far, but the layout was
 * inconsistent, and it has to be right before the fault registers can be
 * read at all. */
#define ICACHE_IOVA 0x00004000u
#define ICACHE_PGS  8u                    /* the declared region is 0x8000 */
#define SCRATCH_IOVA 0x00144000u
#define SCRATCH_PGS 19u
#define DEBUG_IOVA  0x00157000u
#define DEBUG_PGS   9u
#define DUMMY_IOVA  0x60000000u
#define DUMMY_PGS   4u                    /* R107: 16 KiB, see below */
#define LOG_IOVA    0x60004000u
#define LOG_PGS     4u                    /* R107: 16 KiB, see below */
#define HFI_IOVA    0x60008000u
#define HFI_PGS     4u
#define DATA_PAGES  (ICACHE_PGS + SCRATCH_PGS + DEBUG_PGS + DUMMY_PGS + \
		     LOG_PGS + HFI_PGS)
#define DP_ICACHE   0u
#define DP_SCRATCH  (DP_ICACHE + ICACHE_PGS)
#define DP_DEBUG    (DP_SCRATCH + SCRATCH_PGS)
#define DP_DUMMY    (DP_DEBUG + DEBUG_PGS)
/* R108: the dummy and the log buffer are four pages each, and the HFI
 * queue table four pages after that.  The offsets here still counted one
 * page each, so DP_LOG landed inside the dummy block and DP_HFI inside the
 * log block: the zeroing of the log buffer wiped the dummy pages, the HFI
 * queue table was written into a log page, and the SMMU descriptors named
 * the same physical page for three different IOVAs.  Each region starts
 * where the one before it ends. */
#define DP_LOG      (DP_DUMMY + DUMMY_PGS)
#define DP_HFI      (DP_LOG + LOG_PGS)
#define TBL_PAGES   5u
#define TB_ROOT     0u
#define TB_L2A      1u
#define TB_LEA      2u
#define TB_L2B      3u
#define TB_LEB      4u

/* The SMMU's output address size, from IDR2's OAS field: 36 bits. A page
 * above that cannot be named in a descriptor, so the fixture checks every
 * physical address it was given before it builds a table out of them. */
#define SMMU_PA_BITS 36u

/* The two versions of the firmware's ready value. Linux picks between them
 * from the version word in the DTCM, which R99 cannot read; R99 waits for
 * any non-zero FW_INIT_RESULT and then decides from the value itself. */
#define READY_NEW     0x00000100u     /* mask 0x1ff, the a650 firmware */
#define READY_OLD     0xBABEFACEu     /* mask 0xffffffff, the older ones */

#define BIT31         0x80000000u
#define CBCR_ENABLE   0x00000001u
#define CBCR_CLK_OFF  BIT31
#define GDSC_COLLAPSE 0x00000001u
#define RCG_UPDATE    0x00000001u
#define RCG_ROOT_EN   0x00000002u
#define RCG_ROOT_OFF  BIT31
#define RCG_CFG_CLEAR 0x0010171Fu
#define GMU_SEL       6u
#define GMU_HID       2u
#define GMU_WAKE_SLEEP 0x00000FF0u
#define RPMH_VOTES    0x00000F11u

/* The a650's chip id, packed the way a6xx_gmu.c packs it: the upper 16 bits
 * are the same, minor and patch go into four bits each with the low 8 bits
 * unused.
 *
 * A650_GMU_CHIP_ID is 0x06050002, so the packed form is
 *
 *     (0x06050002 & 0xffff0000) | ((0x06050002 << 4) & 0xf000)
 *                                | ((0x06050002 << 8) & 0x0f00)
 *   = 0x06050000 | 0x0000 | 0x0200
 *   = 0x06050200
 *
 * R113: this table used to hold 0x60500200, with the "0605" written as
 * "6050".  The CM3 reads the chip id back out of GMU_HFI_SFR_ADDR and
 * unpacks it itself (ITCM+0x28cc): it takes the value apart into four
 * bytes, puts them back the other way round, and then insists that
 *
 *     (value >> 24) & 0xff == 6            the Adreno 6xx family
 *     (value >> 16) & 0xff == 2 or 5       the a640 or the a650
 *
 * With 0x60500200 the first byte comes back as 0x60 instead of 0x06 and
 * the second as 0x50 instead of 0x05, so the check failed and the init
 * chain gave up with error code 3.  That is what stopped the CM3: its
 * stage counter stopped at 0x0b, it wrote two log entries (0x00010074
 * and 0x000200e0) and never reached the ready state. --- */
#define CHIPID        0x06050200u
/* The log and the HFI queues have no iovas of their own: A650Gmu.c puts
 * them right behind the dummy page, which is where the icache region ends
 * and the uncached range begins, and the boot registers name them. */

/* Phase 2: a6xx_gmu_resume's interrupt clear and mask, then the RSC
 * sequencer's own setup: the a650's sleep and wake-up microcode, the PDC
 * sequence pointer and the PDC itself. R96 skipped this block entirely, so
 * the RSCC had never been programmed and never answered the wake request.
 *
 * R109: the hidden TCS command's data and address are back the way Linux
 * has them.  a6xx_gmu_rpmh_init (Linux v6.6, drivers/gpu/drm/msm/adreno/
 * a6xx_gmu.c) writes, in this order:
 *
 *     gmu_write_rscc(gmu, REG_A6XX_RSCC_HIDDEN_TCS_CMD0_DATA, 0);
 *     gmu_write_rscc(gmu, REG_A6XX_RSCC_HIDDEN_TCS_CMD0_ADDR, 0);
 *     gmu_write_rscc(gmu, REG_A6XX_RSCC_HIDDEN_TCS_CMD0_DATA + 2, 0);
 *     gmu_write_rscc(gmu, REG_A6XX_RSCC_HIDDEN_TCS_CMD0_ADDR + 2, 0);
 *     gmu_write_rscc(gmu, REG_A6XX_RSCC_HIDDEN_TCS_CMD0_DATA + 4, 0x80000000);
 *     gmu_write_rscc(gmu, REG_A6XX_RSCC_HIDDEN_TCS_CMD0_ADDR + 4, 0);
 *
 * and the RSCC block's enumeration puts DATA at dword 0x00e and ADDR at
 * dword 0x00d, so DATA+4 is dword 0x012 and ADDR+4 is dword 0x011.  The
 * official SM8250 A650Gmu.c agrees on both the enumeration and the values.
 * R108 read the pair the other way round and put 0x80000000 into the
 * address word; this table has 0x03de0044 (dword 0x011, ADDR+4) = 0 and
 * 0x03de0048 (dword 0x012, DATA+4) = 0x80000000, which is what R106 had
 * and what both references do. */
static const u32 g_rsc[44] = {
	0x03D8EC10u, 0xFFFFFFFFu,	/* AO_HOST_INTERRUPT_CLR */
	0x03D8EC18u, 0xFFFFFFD6u,	/* AO_HOST_INTERRUPT_MASK, ~0x29 */
	0x03D7E644u, 0xFFFFFFFFu,	/* GMU2HOST_INTR_CLR */
	0x03DE0010u, 0x01000000u,	/* RSC_STATUS0_DRV0: no SDE clock gating */
	0x03DE002Cu, 0x00000001u,	/* PDC_SLAVE_ID_DRV0 */
	0x03DE0034u, 0x00000000u,	/* HIDDEN_TCS_CMD0_ADDR (0x00d) */
	0x03DE0038u, 0x00000000u,	/* HIDDEN_TCS_CMD0_DATA (0x00e) */
	0x03DE003Cu, 0x00000000u,	/* HIDDEN_TCS_CMD0_ADDR + 2 (0x00f) */
	0x03DE0040u, 0x00000000u,	/* HIDDEN_TCS_CMD0_DATA + 2 (0x010) */
	0x03DE0044u, 0x00000000u,	/* HIDDEN_TCS_CMD0_ADDR + 4 (0x011) */
	0x03DE0048u, 0x80000000u,	/* HIDDEN_TCS_CMD0_DATA + 4 (0x012) */
	0x03DE0400u, 0x00000000u,	/* OVERRIDE_START_ADDR */
	0x03DE0020u, 0x00004520u,	/* PDC_SEQ_START_ADDR */
	0x03DE0024u, 0x00004510u,	/* PDC_MATCH_VALUE_LO */
	0x03DE0028u, 0x00004514u,	/* PDC_MATCH_VALUE_HI */
	0x03DE0600u, 0xEAAAE5A0u,	/* SEQ_MEM_0_DRV0: the a650's RSC microcode */
	0x03DE0604u, 0xE1A1EBABu,
	0x03DE0608u, 0xA2E0A581u,
	0x03DE060Cu, 0xECAC82E2u,
	0x03DE0610u, 0x0020EDADu,
	0x0B294520u, 0x00000000u,	/* PDC GPU_SEQ_START_ADDR */
	0x0B294500u, 0x80000001u	/* PDC GPU_ENABLE_PDC */
};

/* Phase 5: the boot registers, in the order a6xx_gmu_fw_start writes them,
 * each one read back.
 *
 * R108: the order of the SFR/CP_MSG pair was checked against the official
 * SM8250 A650Gmu.c (kits/Sm8250Platform/A650Gmu.c, phase 5), which pairs
 * the register list and the value list by position:
 *
 *     regs[]   = {..., GMU_HFI_SFR_ADDR,   GMU_PWR_COL_CP_MSG, ...}
 *     values[] = {..., chipid, log.iova | (log.bytes / 4096 - 1), ...}
 *
 * so HFI_SFR_ADDR carries the chip id and PWR_COL_CP_MSG carries the log
 * buffer's address and size -- which is what this table does.  The pairing
 * reads like it could be the other way round; it is recorded here so nobody
 * reverses it again.
 *
 * The chip id is the A650's: the upper 16 bits of the DTS chipid, then the
 * minor and patch ids in four bits each, which is what the official code
 * computes from c->chip_id (0x06050002 -> 0x06050200). */
static const u32 g_p5[24] = {
	0x03D7E070u, 0x00000000u,	/* CM3_FW_INIT_RESULT */
	0x03D7E004u, 0x00000002u,	/* CM3_BOOT_CONFIG */
	0x03D7E614u, HFI_IOVA,		/* HFI_QTBL_ADDR */
	0x03D7E610u, 0x00000001u,	/* HFI_QTBL_INFO */
	0x03D8EC44u, 0x802800A0u,	/* AHB_FENCE_RANGE_0 */
	0x03D7E0B4u, 0x00004052u,	/* CM3_CFG */
	0x03D7E608u, CHIPID,		/* HFI_SFR_ADDR: the chip id */
	0x03D7E400u, LOG_IOVA | 3u,	/* PWR_COL_CP_MSG: log iova | pages-1 */
	0x03D7D03Cu, 0x00000001u,	/* SYS_BUS_CONFIG */
	0x03D7D000u, 0x00000001u,	/* ICACHE_CONFIG */
	0x03D7D004u, 0x00000001u,	/* DCACHE_CONFIG */
	0x03D7E300u, 0x09C40400u	/* PWR_COL_INTER_FRAME_CTRL */
};

static const char g_hex[] = "0123456789abcdef";

/* _start must be the first thing in the image: the Mach-O entry point is
 * __TEXT+0x1d0 and it is baked into LC_UNIXTHREAD. Naked matters here -- a C
 * prologue moves sp before the first statement runs, and then this file would
 * report its own frame instead of the kernel-set stack pointer (R71). */
__attribute__((section(".text.start"), naked, noreturn))
void _start(void)
{
	__asm__ volatile ("mov x0, sp\n\tb nio_main");
}

/* One fd4 round trip. Returns the kernel's retval (the result length). */
static __attribute__((noinline)) i64 call(u32 *c, u32 nwords)
{
	return sys6(SYS_write, 4, (i64)c, (i64)(nwords * 4u), 0, 0, 0);
}

/* op 7: read one dword. `st` is 0 when the bus returned a value. */
static __attribute__((noinline)) u32 rd(u32 *c, u32 addr, u32 *st)
{
	i64 got;

	c[0] = OP_MR;
	c[1] = addr;
	c[2] = 1u;
	got = call(c, CMD_WORDS);
	if (got != (i64)RES_BYTES) {
		*st = 14u;
		return 0u;
	}
	if (c[R_STATUS] != 0u) {
		*st = c[R_STATUS];
		return 0u;
	}
	*st = 0u;
	return c[R_RAW];
}

/* op 7 with up to MR_MAX dwords: the result words come back in the same
 * buffer the command went out in, so they are copied out before the next
 * command overwrites them. */
static __attribute__((noinline)) u32 rdm(u32 *c, u32 addr, u32 n, u32 *out)
{
	u32 i;
	i64 got;

	c[0] = OP_MR;
	c[1] = addr;
	c[2] = n;
	got = call(c, CMD_WORDS);
	if (got != (i64)RES_BYTES) {
		return 14u;
	}
	if (c[R_STATUS] != 0u) {
		return c[R_STATUS];
	}
	for (i = 0; i < n && i < 24u; i++) {
		out[i] = c[R_RAW + i];
	}
	return 0u;
}

/* R117: read `n` dwords out of the command database at `off` bytes from its
 * base.  op 7 reads at most 24 dwords per call and the kernel's own check
 * stops a read at a page boundary, so a run is split into page-sized pieces
 * of at most 24 words each.
 *
 * The reads are of ordinary memory through the device window, and the
 * window is unmapped again after every call, so this costs no permanent
 * mapping. */
static __attribute__((noinline)) u32 cmdb_rd(u32 *c, u32 off, u32 n, u32 *out)
{
	u32 done = 0u;
	u32 w[24];
	u32 i;

	while (done < n) {
		u32 at = off + done * 4u;
		u32 room = (0x1000u - (at & 0xFFFu)) / 4u;
		u32 take = n - done;

		if (room > 24u) {
			room = 24u;
		}
		if (take > room) {
			take = room;
		}
		if (rdm(c, CMDB_BASE + at, take, w) != 0u) {
			return 1u;
		}
		for (i = 0u; i < take; i++) {
			out[done + i] = w[i];
		}
		done += take;
	}
	return 0u;
}

/* R117: read `n` 16-bit little-endian words at byte offset `off` from the
 * database's base.  The payload of an ARC level list is a run of 16-bit
 * words, and it does not have to be four-byte aligned, so the words are
 * read out of the dwords that cover them.
 *
 * The values come back one per word, in the low half. */
static __attribute__((noinline)) u32 cmdb_rd16(u32 *c, u32 off, u32 n,
                                                u32 *out)
{
	u32 buf[20];
	u32 start = off & ~3u;
	u32 need = ((off + n * 2u + 3u) - start + 3u) / 4u;
	u32 i;

	if (n == 0u || n > 16u || need > 20u) {
		return 1u;
	}
	if (cmdb_rd(c, start, need, buf) != 0u) {
		return 1u;
	}
	for (i = 0u; i < n; i++) {
		u32 at = off + i * 2u;
		u32 w = buf[(at - start) >> 2];

		out[i] = (w >> (((at - start) & 2u) * 8u)) & 0xffffu;
	}
	return 0u;
}

/* R117: find the entry named `name` in the command database and copy its
 * payload into `out` (up to `cap` bytes).  This is the lookup in
 * A650GpuCommandDbParse, from the sm8250-common kit's A650GmuPower.c, in
 * the probe's own words:
 *
 *   the header is a version, the magic, and eight slave records of sixteen
 *   bytes each: {u16 slv_id, u16 header_offset, u16 data_offset, u16 count,
 *   u16 version, six reserved bytes};
 *   a slave's entry table sits at CMDB_DATA + header_offset and holds
 *   `count` entries of 24 bytes:
 *       {u8 id[8], u16 priority, u32 address, u16 len, u16 offset};
 *   the payload of an entry is at CMDB_DATA + data_offset + offset and is
 *   `len` bytes long.
 *
 * `addr_out` and `slave_out` get the entry's own address field (the BCM
 * registers are named by it) and the slave the name was found under.
 * `aux_out` gets the byte offset of the payload inside the database and
 * `len_out` its length; the payload itself is read afterwards, because it
 * is a run of 16-bit words that need not be four-byte aligned.
 *
 * Returns 0 when the name was found, 1 when it is not in the database and
 * 2 when the header does not make sense. */
static __attribute__((noinline)) u32 cmdb_find(u32 *c, const char *name,
                                               u32 *aux_out, u32 *len_out,
                                               u32 *addr_out, u32 *slave_out)
{
	u32 hdr[36];
	u32 s, i, j;

	*aux_out = 0u;
	*len_out = 0u;
	*addr_out = 0u;
	*slave_out = 0u;
	if (cmdb_rd(c, 0u, 36u, hdr) != 0u) {
		return 2u;
	}
	if (hdr[1] != CMDB_MAGIC) {
		return 2u;
	}
	for (s = 0u; s < 8u; s++) {
		u32 rec = 2u + s * 4u;         /* the slave record is 16 bytes */
		u32 slv_id = hdr[rec] & 0xffffu;
		u32 heads = (hdr[rec] >> 16) & 0xffffu;
		u32 dofs = hdr[rec + 1u] & 0xffffu;
		u32 cnt = (hdr[rec + 1u] >> 16) & 0xffffu;
		u32 base = CMDB_DATA + heads;
		u32 nlen = 0u;

		if (slv_id == 0u) {
			break;                     /* the end of the slave table */
		}
		while (name[nlen] != 0u && nlen < 8u) {
			nlen++;
		}
		if (name[nlen] != 0u) {
			continue;               /* the name is longer than an id */
		}
		if ((base + cnt * 24u) > CMDB_BYTES) {
			return 2u;
		}
		for (i = 0u; i < cnt; i++) {
			u32 ent[6];
			u32 aux, elen;

			if (cmdb_rd(c, base + i * 24u, 6u, ent) != 0u) {
				return 2u;
			}
			/* the id is the first eight bytes, as characters, and the
			 * byte at the name's end has to be the terminator: a
			 * prefix is not a match. */
			for (j = 0u; j <= nlen; j++) {
				u32 ch = (ent[j / 4u] >> ((j % 4u) * 8u)) & 0xffu;

				if (ch != (u32)(j < nlen ? name[j] : 0)) {
					break;
				}
			}
			if (j != nlen + 1u) {
				continue;
			}
			/* len is at +20 and offset at +22 of the entry */
			elen = ent[5u] & 0xffffu;
			aux = CMDB_DATA + dofs + ((ent[5u] >> 16) & 0xffffu);
			if ((aux + elen) > CMDB_BYTES) {
				return 2u;
			}
			*aux_out = aux;
			*len_out = elen;
			*addr_out = ent[4u];
			*slave_out = slv_id;
			return 0u;
		}
	}
	return 1u;
}

/* op 9: write one dword. Same page mapping as op 7, one 32-bit store. */
static __attribute__((noinline)) u32 wr(u32 *c, u32 addr, u32 val)
{
	i64 got;

	c[0] = OP_MW;
	c[1] = addr;
	c[2] = 1u;
	c[3] = val;
	got = call(c, CMD_WORDS);
	if (got != (i64)RES_BYTES) {
		return 14u;
	}
	return c[R_STATUS];
}

/* op 10: write `n` consecutive dwords, all inside one page. */
static __attribute__((noinline)) u32 wrb(u32 *c, u32 addr, u32 n, const u32 *src)
{
	i64 got;
	u32 i, *d = (u32 *)((char *)c + 12);

	for (i = 0; i < n; i++) {
		d[i] = src[i];
	}
	c[0] = OP_MWB;
	c[1] = addr;
	c[2] = n;
	got = call(c, CMD_WORDS);
	if (got != (i64)RES_BYTES) {
		return 14u;
	}
	return c[R_STATUS];
}

/* op 9 with a 64 bit value: the context bank's TTBR0 and TTBR1. */
static __attribute__((noinline)) u32 wr64(u32 *c, u32 addr, u64 val)
{
	i64 got;

	c[0] = OP_MW;
	c[1] = addr;
	c[2] = 2u;
	c[3] = (u32)val;
	c[4] = (u32)(val >> 32);
	got = call(c, CMD_WORDS);
	if (got != (i64)RES_BYTES) {
		return 14u;
	}
	return c[R_STATUS];
}

/* op 11: one 4 KiB kernel page, zeroed and cleaned to memory by the blob.
 * The answer is the page's physical address and its kernel virtual address,
 * four words in all. */
static __attribute__((noinline)) u32 alloc(u32 *c, u64 *pa, u64 *va)
{
	i64 got;

	c[0] = OP_ALLOC;
	c[1] = 0u;
	c[2] = 0u;
	got = call(c, CMD_WORDS);
	if (got != (i64)RES_BYTES) {
		return 14u;
	}
	if (c[R_STATUS] != 0u) {
		return c[R_STATUS];
	}
	*pa = (u64)c[R_RAW + 0] | ((u64)c[R_RAW + 1] << 32);
	*va = (u64)c[R_RAW + 2] | ((u64)c[R_RAW + 3] << 32);
	return 0u;
}

/* op 12: dwords into a page of kernel memory at a byte offset, through the
 * kernel's own alias, and the cache cleaned so the SMMU's walk of the page
 * sees the same bytes. The words written come back in `out`, read from the
 * page after the clean.
 *
 * The result area of the kernel's answer holds 24 words, so a write longer
 * than that reads back only its first 24; `out` must have room for 24. */
static __attribute__((noinline)) u32 wva(u32 *c, u64 va, u32 off, u32 n,
                                         const u32 *src, u32 *out)
{
	u32 i, *d = (u32 *)((char *)c + 12);
	i64 got;

	if (n > 120u) {
		n = 120u;
	}
	d[0] = (u32)va;
	d[1] = (u32)(va >> 32);
	for (i = 0; i < n; i++) {
		d[2 + i] = src[i];
	}
	c[0] = OP_WVA;
	c[1] = off;
	c[2] = n;
	got = call(c, CMD_WORDS);
	if (got != (i64)RES_BYTES) {
		return 14u;
	}
	if (c[R_STATUS] != 0u) {
		return c[R_STATUS];
	}
	for (i = 0; i < n && i < 24u; i++) {
		out[i] = c[R_RAW + i];
	}
	return 0u;
}

/* The firmware file, as tools/gmu-fw.py writes it: a 512-byte header and
 * then the payloads, each at a 512-byte aligned file offset (the mockfs
 * hands out 512-byte blocks, so a read that starts anywhere else would come
 * back from the wrong place).
 *
 *   word 0    the magic 'GFW1'
 *   word 1    how many pieces
 *   word 2+   three words per piece: the iova, the byte count and the kind
 *             (1 = the GMU's TCM, a register window; 2 = system memory, an
 *             SMMU mapped page)
 *
 * The byte counts are multiples of 512, so every read in the file lands on
 * a block boundary and the payload of one piece never runs into the next.
 */
#define FW_MAGIC     0x31465747u
#define FW_KIND_TCM  1u
#define FW_KIND_MEM  2u

/* Which data page an iova belongs to, or 0xffffffff for one we do not map. */
static __attribute__((noinline)) u32 fw_page(u32 iova)
{
	if (iova >= ICACHE_IOVA && iova < ICACHE_IOVA + ICACHE_PGS * 0x1000u) {
		return DP_ICACHE + ((iova - ICACHE_IOVA) >> 12);
	}
	if (iova >= SCRATCH_IOVA && iova < SCRATCH_IOVA + SCRATCH_PGS * 0x1000u) {
		return DP_SCRATCH + ((iova - SCRATCH_IOVA) >> 12);
	}
	if (iova >= DEBUG_IOVA && iova < DEBUG_IOVA + DEBUG_PGS * 0x1000u) {
		return DP_DEBUG + ((iova - DEBUG_IOVA) >> 12);
	}
	if (iova >= DUMMY_IOVA && iova < DUMMY_IOVA + DUMMY_PGS * 0x1000u) {
		return DP_DUMMY + ((iova - DUMMY_IOVA) >> 12);
	}
	if (iova >= LOG_IOVA && iova < LOG_IOVA + LOG_PGS * 0x1000u) {
		return DP_LOG + ((iova - LOG_IOVA) >> 12);
	}
	if (iova >= HFI_IOVA && iova < HFI_IOVA + HFI_PGS * 0x1000u) {
		return DP_HFI + ((iova - HFI_IOVA) >> 12);
	}
	return 0xffffffffu;
}

/* What the loader needs to reach: the command buffer, the staging buffer,
 * the pages, and the counters it fills in. */
struct fwctx {
	u32 *cmd;
	u32 *chunk;
	u32 *out;
	u64 *va_data;
	i64 fd;
	u32 errs;
	u32 nread;
	u32 sum;
	/* R107: 0 = not checked, 1 = the first words of the icache payload
	 * came back as they went in, 2 = they did not. */
	u32 chk;
};

/* R107: the first four words of the payload the container puts at 0x4000.
 * alioth's phase 4 reads every single word of every block back after it
 * copies it and refuses to release the CM3 if one of them is wrong: a
 * firmware that runs out of a half-written icache fails in a way that no
 * register can explain.  R106 read back the version word in the DTCM and
 * the vector table in the ITCM -- both of them are TCM, not memory -- and
 * never checked the system memory at all, so a memory write that silently
 * failed would have looked exactly like the failure it was.
 *
 * These four words are what the container holds at the head of the payload
 * that lands at 0x4000 (out/a650_gmu.bin, the record at file 0x39dc). */
static const u32 g_fw_head[4] = {
	0x43f8e92du, 0x4d162400u, 0x28006be8u, 0x4f15d025u
};

/* Read the firmware file and put every piece where it belongs: the TCM
 * pieces through the GMU's register windows, the memory pieces into the
 * kernel pages the SMMU maps for the GMU. Returns 0 when the whole file
 * went in, and a number that says where it stopped when it did not. */
static __attribute__((noinline)) u32 fw_load(struct fwctx *f)
{
	i64 n;
	u32 npieces, p, magic;
	/* R103: the header and the payloads used to share one buffer, so the
	 * first payload read overwrote the piece table and the second piece's
	 * kind came from the firmware's own bytes -- fw_load bailed out with 5
	 * and the cold start never happened.  The payloads now go into their
	 * own buffer and the header stays where it was read. */
	u32 buf[CHUNK / 4u];

	n = sys6(SYS_read, f->fd, (i64)f->chunk, (i64)CHUNK, 0, 0, 0);
	if (n != (i64)CHUNK) {
		return 1u;
	}
	magic = f->chunk[0];
	npieces = f->chunk[1];
	if (magic != FW_MAGIC || npieces == 0u || npieces > 8u) {
		return 2u;
	}
	for (p = 0; p < npieces; p++) {
		u32 iova = f->chunk[2u + p * 3u];
		u32 bytes = f->chunk[3u + p * 3u];
		u32 kind = f->chunk[4u + p * 3u];
		u32 left = bytes;

		if (kind == FW_KIND_TCM) {
			/* the two TCM regions are register windows: the ITCM at
			 * iova 0 and the DTCM at iova 0x10004000 */
			u32 dst = (iova < 0x10000000u) ? (M_ITCM + iova)
			                               : (M_DTCM + (iova - 0x10004000u));

			while (left) {
				u32 want = (left > CHUNK) ? CHUNK : left;
				u32 k;

				n = sys6(SYS_read, f->fd, (i64)buf, (i64)want,
				         0, 0, 0);
				if (n != (i64)want) {
					f->errs++;
					return 3u;
				}
				if (wrb(f->cmd, dst, want >> 2, buf) != 0u) {
					f->errs++;
				}
				for (k = 0; k < (want >> 2); k++) {
					f->sum += buf[k];
				}
				f->nread += want;
				dst += want;
				left -= want;
			}
		} else if (kind == FW_KIND_MEM) {
			u32 at = iova;

			while (left) {
				u32 want = (left > CHUNK) ? CHUNK : left;
				u32 done = 0u;

				n = sys6(SYS_read, f->fd, (i64)buf, (i64)want,
				         0, 0, 0);
				if (n != (i64)want) {
					f->errs++;
					return 3u;
				}
				/* a write stays inside one page, and op 12 takes at
				 * most 120 words at a time */
				while (done < want) {
					u32 idx = fw_page(at + done);
					u32 poff = (at + done) & 0xfffu;
					u32 dw = (want - done) >> 2;
					u32 k;

					if (idx == 0xffffffffu) {
						f->errs++;
						return 4u;
					}
					if (dw * 4u > 0x1000u - poff) {
						dw = (0x1000u - poff) >> 2;
					}
					if (dw > 120u) {
						dw = 120u;
					}
					if (wva(f->cmd, f->va_data[idx], poff, dw,
					        &buf[done >> 2], f->out) != 0u) {
						f->errs++;
					}
					/* R107: the first memory block is the
					 * icache, and op 12 hands back the
					 * first 24 words it wrote, read
					 * from the page after the clean.
					 * If those four words are not the
					 * ones the container holds, the
					 * firmware would have run out of
					 * a half-written icache. */
					if (f->chk == 0u && at == 0x4000u &&
					    done == 0u) {
						u32 h = 0u;

						for (k = 0; k < 4u; k++) {
							if (f->out[k] != g_fw_head[k]) {
								h = 1u;
							}
						}
						f->chk = h ? 2u : 1u;
					}
					for (k = 0; k < dw; k++) {
						f->sum += buf[(done >> 2) + k];
					}
					done += dw * 4u;
				}
				f->nread += want;
				at += want;
				left -= want;
			}
		} else {
			f->errs++;
			return 5u;
		}
	}
	return 0u;
}

/* One entry of a page table: a leaf descriptor (the data page) or a table
 * descriptor (the level below). Both are 64 bit and sit at an 8 byte aligned
 * offset, so one call writes both halves. */
static __attribute__((noinline)) u32 put(u32 *c, u64 va, u32 index, u64 value,
                                         u32 *out)
{
	u32 w[2];

	w[0] = (u32)value;
	w[1] = (u32)(value >> 32);
	return wva(c, va, index * 8u, 2u, w, out);
}

/* --- R114: the HFI transport.
 *
 * R113 proved that the CM3 boots: the chip id check passed, FW_INIT_RESULT
 * came back as the ready value and the HFI status bit came up.  What has
 * not been shown yet is whether the CM3 and the host can actually talk over
 * the HFI queues, which is the one thing between a running GMU and a running
 * GPU.
 *
 * The wire protocol is the one AdrenoHfi.c implements:
 *
 *   - the host writes a packet into the command ring (queue 0), where the
 *     first word is the header (sequence << 20 | count << 8 | id) and the
 *     payload follows, padded to four words with 0xfafafafa;
 *   - the host then publishes the new write pointer in the queue header
 *     (word 11) and rings the GMU's doorbell (HOST2GMU bit 0);
 *   - the CM3 answers in the response ring (queue 1): the header, then the
 *     return header (whose sequence must match), then the error code, then
 *     the payload.
 *
 * The rings live in system memory, so they are read and written through the
 * page's own physical address: op 7 maps a device page, which is the same
 * memory the SMMU shows the CM3, and op 12 writes through the kernel's
 * cached alias and cleans it so the CM3 sees the same bytes.
 *
 * The queue header is twelve words per queue and the header itself is six
 * words, so queue q's header is at word 6 + 12 * q.  Word 10 is the read
 * pointer and word 11 the write pointer; the queue's ring is at
 * HFI_IOVA + (q + 1) * 4096, which is the page one after the table. */

/* The queue header of queue q, read back: the read pointer, the write
 * pointer, the status word and the ring's iova.
 *
 * The table's own header is six words and every queue header is twelve,
 * so queue q's header starts at word 6 + 12 * q.  Word 10 of it is the
 * read pointer and word 11 the write pointer.  The read covers twelve
 * words from the queue's own start, which is inside the twenty-four the
 * answer holds. */
static __attribute__((noinline)) u32 hfi_head(u32 *c, const u64 *pa, u32 q,
                                              u32 *out)
{
	u32 w[24];
	u32 off = (6u + 12u * q) * 4u;

	if (rdm(c, (u32)pa[0] + off, 12u, w) != 0u) {
		return 20u;
	}
	out[0] = w[10u];
	out[1] = w[11u];
	out[2] = w[0u];
	out[3] = w[1u];
	return 0u;
}

/* Publish the read pointer (which = 10) or the write pointer (which = 11)
 * of queue q in its header.  R115: the read pointer has to be published
 * too, or the next poll reads the same answer again -- AdrenoHfiPoll
 * moves v[10] past the packet it consumed. */
static __attribute__((noinline)) u32 hfi_publish(u32 *c, const u64 *va, u32 q,
                                                 u32 which, u32 value)
{
	u32 w[1];
	u32 off = (6u + 12u * q) * 4u + which * 4u;

	w[0] = value;
	return wva(c, va[0], off, 1u, w, w);
}

/* the pause between two polls: spin() is defined further down */
static __attribute__((noinline)) void spin(u32 n);

/* Write `n` words into the ring at word offset `off`.
 *
 * The ring is one page of 1024 words, so a run may wrap around its end,
 * and op 12 takes at most 120 words at a time and the run has to stay
 * inside the page.  The performance table is 59 words and the bandwidth
 * table 160, so the packet is written in pieces. */
static __attribute__((noinline)) u32 ring_put(u32 *c, u64 va, u32 off,
                                              const u32 *src, u32 n)
{
	u32 done = 0u;
	u32 w[120];

	while (done < n) {
		u32 pos = (off + done) & 1023u;
		u32 room = 1024u - pos;
		u32 k;

		if (room > n - done) {
			room = n - done;
		}
		if (room > 120u) {
			room = 120u;
		}
		for (k = 0u; k < room; k++) {
			w[k] = src[done + k];
		}
		if (wva(c, va, pos * 4u, room, w, w) != 0u) {
			return 30u;
		}
		done += room;
	}
	return 0u;
}

/* Write one packet into the command ring (queue 0) and ring the doorbell.
 * `id` is the HFI message id, `payload` holds `words` payload words and
 * `seq` is the sequence number of this packet.
 *
 * R115: the sequence number is the caller's, not a constant.  AdrenoHfiSend
 * counts h->sequence up by one for every packet and the answer is matched
 * on it, so two packets that both claim sequence 1 leave the second one
 * unmatched and the host waits for an answer that will never come. */
static __attribute__((noinline)) u32 hfi_send(u32 *c, const u64 *pa,
                                               const u64 *va, u32 id,
                                               const u32 *payload, u32 words,
                                               u32 seq, u32 *header_out)
{
	u32 pack[164];
	u32 count = words + 1u;
	u32 padded = (count + 3u) & ~3u;
	u32 read = 0u, write = 0u;
	u32 h[4];
	u32 hdr;
	u32 i;

	if (words > 160u) {
		return 21u;
	}
	if (hfi_head(c, pa, 0u, h) != 0u) {
		return 23u;
	}
	read = h[0];
	write = h[1];
	/* the free room in the ring, the way AdrenoHfiSend counts it */
	if (((read - write - 1u) & 1023u) < padded) {
		return 24u;
	}
	hdr = ((seq & 0xfffu) << 20) | (count << 8) | (id & 0xffu);
	pack[0] = hdr;
	for (i = 0u; i < words; i++) {
		pack[i + 1u] = payload[i];
	}
	for (i = count; i < padded; i++) {
		pack[i] = 0xfafafafau;
	}
	/* the command ring is the page after the table */
	if (ring_put(c, va[1u], write, pack, padded) != 0u) {
		return 26u;
	}
	if (hfi_publish(c, va, 0u, 11u, (write + padded) & 1023u) != 0u) {
		return 27u;
	}
	/* the doorbell: HOST2GMU bit 0 means "a message is waiting" */
	(void)wr(c, M_H2G_SET, 1u);
	*header_out = hdr;
	return 0u;
}

/* Poll the response ring (queue 1) for the answer to `header`.
 * Returns 0 when a matching answer arrives, 1 when the ring is empty,
 * 2 when the firmware answered with an error and 6 when the answer is
 * not the one that was asked for.
 *
 * R115: three things were wrong here in R114.  The answer sits at
 * data[read] and not at data[0], the read pointer has to move past the
 * packet that was consumed, and the packet may wrap around the end of
 * the ring.  AdrenoHfiPoll does all three.
 *
 * R116: the scan follows AdrenoHfiPoll exactly now.  A packet that is
 * not the answer is not an error: the ring can hold an answer to an
 * earlier packet that the host has not read yet, and the firmware is
 * in no way obliged to answer in the order the host asked.  The official
 * code walks the ring, skips every packet whose sequence does not
 * match, moves the read pointer past each one and keeps looking:
 *
 *     for (pass = 0; pass < WORDS / 4; ++pass) {
 *         if (read == write) return Empty;
 *         ... read the packet ...
 *         if (!match) { read = (read + padded) & (WORDS - 1);
 *                       v[10] = read; publish(); continue; }
 *         ... the answer ...
 *     }
 *
 * R115 stopped at the first packet that did not match and reported
 * error 8, so the answer to the GX vote was never seen: the ring still
 * held the answer to the start message (id 10) and the answer to the
 * vote (id 30) sat behind it. */
static __attribute__((noinline)) u32 hfi_poll(u32 *c, const u64 *pa,
                                               const u64 *va, u32 header,
                                               u32 *out, u32 *nout)
{
	u32 h[4];
	u32 w[24];
	u32 read, write, count, padded, pos, room, done;
	u32 i, pass;

	*nout = 0u;
	if (hfi_head(c, pa, 1u, h) != 0u) {
		return 3u;
	}
	read = h[0];
	write = h[1];
	/* the ring holds at most WORDS / 4 packets and each pass takes
	 * one of them */
	for (pass = 0u; pass < 256u; pass++) {
		if (read == write) {
			return 1u;
		}
		/* the answer is at the read pointer, and it may wrap */
		done = 0u;
		while (done < 4u) {
			pos = (read + done) & 1023u;
			room = 1024u - pos;
			if (room > 4u - done) {
				room = 4u - done;
			}
			if (rdm(c, (u32)pa[2u] + pos * 4u, room, w + done) != 0u) {
				return 4u;
			}
			done += room;
		}
		count = (w[0] >> 8) & 0xffu;
		padded = (count + 3u) & ~3u;
		if (count == 0u || count > 19u) {
			return 5u;
		}
		if (count > 4u) {
			done = 0u;
			while (done < count) {
				pos = (read + done) & 1023u;
				room = 1024u - pos;
				if (room > count - done) {
					room = count - done;
				}
				if (rdm(c, (u32)pa[2u] + pos * 4u, room, w + done) != 0u) {
					return 4u;
				}
				done += room;
			}
		}
		/* a response whose id is 100 is the firmware's error reply */
		if ((w[0] & 0xffu) == 100u) {
			for (i = 0u; i < count; i++) {
				out[i] = w[i];
			}
			*nout = count;
			if (hfi_publish(c, va, 1u, 10u,
			                (read + padded) & 1023u) != 0u) {
				return 7u;
			}
			return 2u;
		}
		if (count < 3u) {
			return 6u;
		}
		/* the return header's sequence must match the command's */
		if ((w[1] >> 20) != (header >> 20)) {
			/* not the answer: step over it and keep looking */
			read = (read + padded) & 1023u;
			if (hfi_publish(c, va, 1u, 10u, read) != 0u) {
				return 7u;
			}
			continue;
		}
		for (i = 0u; i < count; i++) {
			out[i] = w[i];
		}
		*nout = count;
		/* the packet is consumed: the read pointer moves past it */
		if (hfi_publish(c, va, 1u, 10u, (read + padded) & 1023u) != 0u) {
			return 7u;
		}
		if (w[2] != 0u) {
			return 2u;
		}
		return 0u;
	}
	return 5u;
}

/* Wait for the answer to `header`, with a bounded number of polls.
 *
 * The pause between two polls is a spin and not a poll of a register: a
 * poll of a register that cannot change would spend one of the kernel's
 * 2048 device mappings per round, and the mapping is never given back.
 *
 * R116: the budget was far too small.  The official exchange is
 * AdrenoHfiExchange(.., budget = 1000, hfi_wait, ..) and its hfi_wait
 * sleeps 100 us, so the host gives the firmware a hundred milliseconds
 * to answer.  R115 waited twenty rounds of spin(400), which is about
 * sixteen microseconds in all -- four thousand times too short, and
 * short enough that the answers to the startup messages were still in
 * the ring when the next question was asked.  The spin is a volatile
 * loop of about five cycles per iteration on a 2.5 GHz core, so
 * spin(125000) is roughly 250 us and sixty rounds are about fifteen
 * milliseconds; the rounds keep the answer fresh while they wait. */
static __attribute__((noinline)) u32 hfi_wait(u32 *c, const u64 *pa,
                                              const u64 *va, u32 header,
                                              u32 *out, u32 *nout)
{
	u32 rc = 1u;
	u32 i;

	for (i = 0u; i < 60u; i++) {
		spin(125000u);
		rc = hfi_poll(c, pa, va, header, out, nout);
		if (rc != 1u) {
			return rc;
		}
	}
	return rc;
}

/* --- R115: the two startup tables.
 *
 * a6xx_hfi_start sends four stages and waits for each of them: the
 * performance table (message 4), the bandwidth table (message 3), the
 * core start (message 14) and the start (message 10).  Only after those
 * does A650GmuPowerGx send the GX_BW_PERF_VOTE (message 30) and ring
 * HOST2GMU bit 30, and only then does the CM3 answer on GMU2HOST bit
 * 31.  R114 sent message 10 alone, so the GMU's own GX management was
 * never set up.
 *
 * The performance table's votes come out of the gfx, mx and cx rail
 * lists of the AOP command database.  nio has no copy of that database
 * in its own tree, but the lists are the SoC's, not the board's, and the
 * real pipa (sm8250) lists are the ones A650GmuPowerTests.c carries:
 *
 *   gfx.lvl  0 48 64 128 144 192 224 256 320 384 416
 *   mx.lvl   0 16 128 192 224 256 320 384 416
 *   cx.lvl   0 16 64 128 192 256 320 384 416
 *
 * The GPU's eight levels are 0, 64, 128, 144, 192, 224, 256 and 320
 * and the GMU's two are 0 and 48, as A650GmuBuildStartup has them.
 * AdrenoHfiArcVotes puts the level's own list value in the high half,
 * the index of the last lower value of the second list in the middle
 * byte and the index of the level in its own list in the low byte, so
 * the votes are worked out here and hard coded:
 *
 *   gpu  0 00400202 00800203 00900304 00c00305 00e00406 01000507 01400608
 *   gmu  0 00400202
 *
 * The bandwidth table is a650_build_bw_table's one "off" level: the
 * three DDR commands MC0, SH0 and ACV, and the CNOC command CN0, with
 * their addresses as the command database gives them. */

/* The performance table, 58 words. */
static __attribute__((noinline)) u32 hfi_perf(u32 *p)
{
	static const u32 gvote[8] = {
		0x00000000u, 0x00400202u, 0x00800203u, 0x00900304u,
		0x00c00305u, 0x00e00406u, 0x01000507u, 0x01400608u
	};
	static const u32 ghz[8] = {
		0u, 305000u, 400000u, 441600u, 490000u, 525000u, 587000u, 670000u
	};
	u32 i;

	for (i = 0u; i < 58u; i++) {
		p[i] = 0u;
	}
	p[0] = 8u;              /* the GPU's levels */
	p[1] = 2u;              /* the GMU's levels */
	for (i = 0u; i < 8u; i++) {
		p[2u + 3u * i] = gvote[i];
		p[3u + 3u * i] = 0xffffffffu;
		p[4u + 3u * i] = ghz[i];
	}
	/* the GMU's two levels: the off level and 200 MHz at level 48 */
	p[50] = 0x00000000u;
	p[51] = 0u;
	p[52] = 0x00400202u;
	p[53] = 200000u;
	return 58u;
}

/* The bandwidth table, 159 words. */
static __attribute__((noinline)) u32 hfi_bw(u32 *p)
{
	u32 i;

	for (i = 0u; i < 159u; i++) {
		p[i] = 0u;
	}
	p[0] = 1u;              /* the bandwidth levels */
	p[1] = 1u;              /* the CNOC commands */
	p[2] = 3u;              /* the DDR commands */
	p[3] = 1u;              /* the CNOC wait mask */
	p[4] = 1u;              /* the DDR wait mask */
	/* the CNOC command CN0 */
	p[5] = 0x00050074u;
	p[11] = 0x40000000u;
	p[17] = 0x60000001u;
	/* the DDR commands MC0, SH0 and ACV */
	p[23] = 0x00050000u;
	p[24] = 0x00050004u;
	p[25] = 0x0005007cu;
	p[31] = 0x40000000u;
	p[32] = 0x40000000u;
	p[33] = 0x40000000u;
	return 159u;
}

/* R107: zero a run of GMU pages before the firmware goes in.
 *
 * alioth's phase 4 (A650Gmu.c, "a6xx_gmu_fw_load: zero the GMU's memory
 * (the GMU is still in reset)") clears the icache, the dummy and the log
 * before it copies anything, and AdrenoHfiInitializeStopped clears the
 * whole 16 KiB of the HFI queues before it writes the table header.  The
 * kernel's own allocator hands out zeroed pages, so this is belt and
 * braces -- but the scratch region at 0x144000 carries no payload at all
 * (the container declares it, nothing is stored in it), so its contents
 * are whatever the allocator gave, and the firmware is entitled to expect
 * zeros.
 *
 * op 12 takes at most 120 words at a time and does not cross a page, so
 * each page is walked on its own, 120 words per call: eight full calls and
 * a short one for the last 64 words.
 *
 * The pages are NOT contiguous: every one of them is its own allocation,
 * with its own virtual address, so the run is driven off the page table
 * array and not off an address that walks. */
static __attribute__((noinline)) u32 zero_pages(u32 *c, const u64 *va,
                                                 u32 first, u32 count,
                                                 u32 *out)
{
	u32 p, off, n, rc = 0u;
	u32 z[120];

	for (n = 0; n < 120u; n++) {
		z[n] = 0u;
	}
	for (p = 0; p < count; p++) {
		for (off = 0; off < 1024u; off += 120u) {
			n = (1024u - off < 120u) ? (1024u - off) : 120u;
			if (wva(c, va[first + p], off * 4u, n, z, out) != 0u) {
				rc = 1u;
			}
		}
	}
	return rc;
}

/* Branch enable if bit 0 is clear; returns the value read back. */
static __attribute__((noinline)) u32 branch(u32 *c, u32 addr)
{
	u32 st, v;

	v = rd(c, addr, &st);
	if (st == 0u && (v & CBCR_ENABLE) == 0u) {
		(void)wr(c, addr, v | CBCR_ENABLE);
		v = rd(c, addr, &st);
	}
	return v;
}

/* Busy wait; volatile so the loop is not folded away. */
static __attribute__((noinline)) void spin(u32 n)
{
	volatile u32 i;

	for (i = 0; i < n; i++) {
	}
}

/* Read a register until (value & mask) == want, or the budget runs out.
 * Every wait in the bring-up is this shape, and six copies of the loop cost
 * more than the rest of the sequence put together. */
static __attribute__((noinline)) u32 poll(u32 *c, u32 addr, u32 mask, u32 want,
                                          u32 rounds, u32 *st)
{
	u32 i, v = 0u;

	*st = 0u;
	for (i = 0; i < rounds; i++) {
		spin(200u);
		v = rd(c, addr, st);
		if (*st != 0u || (v & mask) == want) {
			break;
		}
	}
	return v;
}

/* One line of text at a cell row: "L=xxxxxxxx L=xxxxxxxx". The string is
 * built straight into the command buffer, because a second copy through a
 * stack buffer cost more than the whole GMU sequence. */
static __attribute__((noinline)) void txv(u32 *c, u32 row, const char *l1,
                                          u32 v1, const char *l2, u32 v2)
{
	u32 i;
	char *d = (char *)c + 12;

	for (i = 0; l1[i] != 0; i++) {
		d[i] = l1[i];
	}
	d += i;
	for (i = 0; i < 8u; i++) {
		d[i] = g_hex[(v1 >> (28u - 4u * i)) & 0xFu];
	}
	d += 8;
	if (l2 != 0) {
		*d++ = ' ';
		for (i = 0; l2[i] != 0; i++) {
			d[i] = l2[i];
		}
		d += i;
		for (i = 0; i < 8u; i++) {
			d[i] = g_hex[(v2 >> (28u - 4u * i)) & 0xFu];
		}
		d += 8;
	}
	*d = 0;
	c[0] = OP_TEXT;
	c[1] = row & 0xffffu;
	/* The length is the number of bytes from byte 12 to the terminator.
	 * R99 wrote (d - (char *)(c + 12)) here, and c is a u32 pointer, so
	 * (c + 12) is 48 bytes past c while d is 12 bytes past it: every line
	 * lost exactly 36 bytes, and every line under 36 bytes underflowed
	 * into a huge length that made the kernel copy 95 bytes and stop at
	 * the terminator. That is why R99's four-value lines showed only
	 * their first eight characters and never showed IDR1, IDR2, CR0, the
	 * SMRs or the S2CRs at all. */
	c[2] = (u32)(d - (char *)c) - 12u;
	(void)call(c, CMD_WORDS);
}

/* One line of text with 64 bit values: the physical addresses of the pages
 * do not fit in 32 bits. */
static __attribute__((noinline)) void txh(u32 *c, u32 row, const char *l1,
                                          u64 v1, const char *l2, u64 v2)
{
	u32 i;
	char *d = (char *)c + 12;

	for (i = 0; l1[i] != 0; i++) {
		d[i] = l1[i];
	}
	d += i;
	for (i = 0; i < 16u; i++) {
		d[i] = g_hex[(v1 >> (60u - 4u * i)) & 0xFu];
	}
	d += 16;
	if (l2 != 0) {
		*d++ = ' ';
		for (i = 0; l2[i] != 0; i++) {
			d[i] = l2[i];
		}
		d += i;
		for (i = 0; i < 16u; i++) {
			d[i] = g_hex[(v2 >> (60u - 4u * i)) & 0xFu];
		}
		d += 16;
	}
	*d = 0;
	c[0] = OP_TEXT;
	c[1] = row & 0xffffu;
	c[2] = (u32)(d - (char *)c) - 12u;
	(void)call(c, CMD_WORDS);
}

/* R112: a row of hex words, for the CM3's stack.  Eight words of eight
 * digits and seven spaces is 71 characters, which is what a cell row
 * holds. */
static __attribute__((noinline)) void txw(u32 *c, u32 row, const u32 *v, u32 n)
{
	u32 i, j;
	char *d = (char *)c + 12;

	for (i = 0; i < n; i++) {
		for (j = 0; j < 8u; j++) {
			d[j] = g_hex[(v[i] >> (28u - 4u * j)) & 0xFu];
		}
		d += 8;
		if (i + 1u < n) {
			*d++ = ' ';
		}
	}
	*d = 0;
	c[0] = OP_TEXT;
	c[1] = row & 0xffffu;
	c[2] = (u32)(d - (char *)c) - 12u;
	(void)call(c, CMD_WORDS);
}

/* R111: a run of bytes at a physical address, printed as text with
 * everything unprintable shown as a dot.
 *
 * The GMU firmware is REX (Qualcomm's GPU firmware framework -- the ITCM
 * holds "REX Idle Task", "rex_leave_crit_sect_internals", "GmuPwrStart",
 * "InvalidateICache" and a whole table of event names).  Its log record is
 * four words: {flags, timestamp, kind, code}, and the R110 reading of the
 * log page was
 *
 *     {0, 0x772a7, 3, 0x00010074}   {0, 0x7730a, 3, 0x000200e0}
 *
 * Two records, the timestamps 99 apart, both kind 3, and the low half of
 * each code word -- 0x74 and 0xe0 -- looks like a byte offset into the log
 * buffer itself: a string pool that follows the records.  R110 read the
 * first sixteen words only, and 0x74 is word 29, so the text was never in
 * the picture.  This reads the first 576 bytes of the page and puts them
 * on the panel, which covers both offsets.
 *
 * The kernel's text op takes 95 bytes, and a cell row is 72 of them. */
static __attribute__((noinline, unused)) void txtp(u32 *c, u32 row, u32 pa,
                                           u32 nbytes)
{
	u32 w[24];
	u32 i;
	char *d = (char *)c + 12;
	const unsigned char *b;

	if (nbytes > 72u) {
		nbytes = 72u;
	}
	if (rdm(c, pa, (nbytes + 3u) / 4u, w) != 0u) {
		/* the read failed: say so on the row itself (txs is defined
		 * further down, so the message is written by hand) */
		const char *m = "LOG READ FAILED";
		u32 j = 0u;

		while (m[j] != 0) {
			d[j] = m[j];
			j++;
		}
		d[j] = 0;
		c[0] = OP_TEXT;
		c[1] = row & 0xffffu;
		c[2] = j;
		(void)call(c, CMD_WORDS);
		return;
	}
	b = (const unsigned char *)w;
	for (i = 0; i < nbytes; i++) {
		d[i] = (b[i] >= 0x20u && b[i] < 0x7fu) ? (char)b[i] : '.';
	}
	d[nbytes] = 0;
	c[0] = OP_TEXT;
	c[1] = row & 0xffffu;
	c[2] = nbytes;
	(void)call(c, CMD_WORDS);
}

/* A title line, in the same buffer. */
static __attribute__((noinline)) void txs(u32 *c, u32 row, const char *s)
{
	u32 i = 0u;
	char *d = (char *)c + 12;

	while (s[i] != 0) {
		d[i] = s[i];
		i++;
	}
	d[i] = 0;
	c[0] = OP_TEXT;
	c[1] = row & 0xffffu;
	c[2] = i;
	(void)call(c, CMD_WORDS);
}

/* Raw bytes as a line of text, with everything unprintable shown as a dot.
 *
 * R106 used this to print the log page as text, and the result on the panel
 * was two rows of boxes: the a650 firmware is REX, and its log is a packed
 * structure, not a string.  R107 prints the log as words instead, which is
 * what the header of that structure looks like.  The function stays because
 * the strings in the image are still worth reading once the header is
 * understood. */
static __attribute__((noinline)) void txtl(u32 *c, u32 row, const u32 *src,
                                           u32 from, u32 n)
__attribute__((used));
static __attribute__((noinline)) void txtl(u32 *c, u32 row, const u32 *src,
                                           u32 from, u32 n)
{
	u32 i;
	char *d = (char *)c + 12;
	const unsigned char *b = (const unsigned char *)src + from;

	if (n > 36u) {
		n = 36u;
	}
	for (i = 0; i < n; i++) {
		d[i] = (b[i] >= 0x20u && b[i] < 0x7fu) ? (char)b[i] : '.';
	}
	d[n] = 0;
	c[0] = OP_TEXT;
	c[1] = row & 0xffffu;
	c[2] = n;
	(void)call(c, CMD_WORDS);
}

/* One 64 bit value on a line of its own: "L=xxxxxxxxxxxxxxxx".
 *
 * R105: the lines are kept short on purpose.  R104 aborted the kernel in the
 * middle of a 39 character line (row 20, the 31st character), four bytes into
 * a run whose two previous stores had worked, so the extent of what a line
 * touches matters more than how much it says. */
static __attribute__((noinline)) void tx1(u32 *c, u32 row, const char *l1, u64 v1)
{
	u32 i;
	char *d = (char *)c + 12;

	for (i = 0; l1[i] != 0; i++) {
		d[i] = l1[i];
	}
	d += i;
	for (i = 0; i < 16u; i++) {
		d[i] = g_hex[(v1 >> (60u - 4u * i)) & 0xFu];
	}
	d += 16;
	*d = 0;
	c[0] = OP_TEXT;
	c[1] = row & 0xffffu;
	c[2] = (u32)(d - (char *)c) - 12u;
	(void)call(c, CMD_WORDS);
}

/* A single progress cell, repainted in place. Whatever hangs leaves the last
 * value that reached the screen.
 *
 * R105: row 30 is inside the panic region's rows now (the panic screen draws
 * rows 30..45 so that the esr/far line is inside the panel), so the marker
 * moved up to row 5, above the title: it has to survive the panic to say how
 * far the round got. */
static __attribute__((noinline)) void mark(u32 *c, u32 v)
{
	txv(c, 5u, "P=", v, 0, 0);
}

__attribute__((used, noreturn)) void nio_main(u64 entry_sp)
{
	/* volatile: without it clang merges small compares into `ldur d0` SIMD
	 * loads, and this fixture should not depend on FP/SIMD being live for
	 * the first EL0 process. */
	volatile char pad[16];
	u32 cmd[CMD_WORDS];
	u32 chunk[CHUNK / 4u];           /* the 512 bytes the file hands us */
	u32 bk[8];                       /* a context bank, 8 dwords at a time */
	u32 out[24];                     /* what op 12 read back: 24 words fit */
	u64 pa_data[DATA_PAGES], va_data[DATA_PAGES];
	u64 pa_tbl[TBL_PAGES], va_tbl[TBL_PAGES];
	u32 sw, sh, st, i;
	u32 cx, ahb, pv, rcmd, rcfg, cgm;
	u32 step;
	u32 v = 0u, fw = 0u, want = 0u, mask = 0u, ready = 0u;
	u32 rsc = 0u, ack = 0u, vmask = 0u, hfi = 0u, seqb = 0u;
	/* R114: the HFI conversation and the GX power vote. */
	u32 hq[12] = {0u};
	u32 hst = 0u, hst2 = 0u, hsend = 0u, hsend2 = 0u;
	u32 hdr = 0u, hdr2 = 0u, hrc = 0u, hn = 0u, hn2 = 0u;
	u32 gx0 = 0u, gx1 = 0u, gxi = 0u;
	/* R116: the wait status of each of the five startup messages, so a
	 * run says which one did not get its answer. */
	u32 w4 = 0u, w3 = 0u, w1 = 0u, w0 = 0u, wv = 0u;
	/* R115: the payload of the two startup tables (the bandwidth table
	 * is 159 words) and the packet's sequence number. */
	u32 pl[164];
	u32 seq = 0u, nw = 0u;
	u32 j = 0u;
	u32 idr0 = 0u, idr1 = 0u, idr2 = 0u, pages = 0u, banks = 0u;
	u32 stride = 0u, cb0 = 0u, cb1 = 0u, cr0 = 0u, gfsr = 0u;
	u32 smr[6];
	u32 s2cr[6];
	u32 cbar0 = 0u, cbar1 = 0u, cba20 = 0u, cba21 = 0u;
	u32 cbase = 0u, bad = 0u;
	u32 rb_cbar = 0u, rb_cba2r = 0u, rb_tcr = 0u, rb_tcr2 = 0u;
	u32 rb_mair0 = 0u, rb_mair1 = 0u, rb_sctlr = 0u, rb_fsr = 0u;
	u32 rb_smra = 0u, rb_s2cra = 0u, rb_smrb = 0u, rb_s2crb = 0u;
	u32 leaf_lo = 0u, leaf_hi = 0u, root_lo = 0u, root_hi = 0u;
	u64 rb_ttbr0 = 0u, rb_ttbr1 = 0u;
	u32 fd = -1, errs = 0u, rc = 0u;
	u32 ver = 0u, ver2 = 0u;
	u32 it0 = 0u, it1 = 0u, it2 = 0u, it3 = 0u;
	u32 gfsr2 = 0u, ao = 0u, icfg = 0u, vt = 0u;
	/* R107: the context bank's own fault registers. */
	u32 cfsr = 0u, cfar = 0u, cifsr = 0u;
	/* R107: how many of the zeroing calls did not go through. */
	u32 zerr = 0u;
	/* R107: the power controller's answer to the firmware. */
	u32 cpres = 0u, cpmsg = 0u;
	/* R106: the firmware's own side of the handshake. */
	u32 qb[4];
	u32 lg[16];
	/* R112: the CM3's boot-stage counter and the top of its stack. */
	u32 dt[8];
	u32 sk[32];
	u32 si = 0u, sj = 0u;
	u32 mcfg = 0u, icf2 = 0u, gxr = 0u, iinf = 0u;
	struct fwctx fx;
	i64 dim;

	(void)pad;
	(void)entry_sp;

	dim = nio_fb_size();
	sw = (u32)((u64)dim >> 32);
	sh = (u32)((u64)dim & 0xffffffffu);
	if (sw < 64u || sw > 8192u || sh < 64u) {
		goto park;
	}
	/* One rectangle clears the panel: the kernel's own log would otherwise
	 * sit under the readings. */
	nio_fb_rect(cmd, 0x00103060u, 0u, 0u, sw, sh);
	(void)nio_fb_send(cmd, 24u);

	txs(cmd, 6u, "R107 gmu mem + fault");

	/* --- rung 1, mode 2: the GPU's AHB branch --- */
	(void)branch(cmd, G_CFG_AHB);

	/* --- rung 2, mode 3: CX out of collapse, then wait for the handshake.
	 * Writing the clock tree below while this rail is down is the one way to
	 * hang the interconnect instead of getting an error back. --- */
	cx = rd(cmd, C_CX_GDSCR, &st);
	if (st == 0u && (cx & BIT31) == 0u) {
		(void)wr(cmd, C_CX_GDSCR, cx & ~GDSC_COLLAPSE);
		(void)poll(cmd, C_GDS_HWCTRL, BIT31, BIT31, 200u, &st);
	}
	cx = rd(cmd, C_CX_GDSCR, &st);

	step = 0u;
	cgm = 0u;
	rcfg = 0u;
	rcmd = 0u;
	pv = 0u;
	ahb = 0u;
	if (st == 0u && (cx & BIT31) != 0u) {
		ahb = branch(cmd, C_AHB_CLK);
		(void)branch(cmd, C_SMMU_VOTE);

		/* --- rung 3, mode 6 step 1: vote GPLL0, the GMU source's parent --- */
		pv = rd(cmd, G_PLL_VOTE, &st);
		if (st == 0u) {
			if ((pv & 0x00018000u) != 0x00018000u) {
				(void)wr(cmd, G_PLL_VOTE, pv | 0x00018000u);
			}
			spin(60u);
			pv = rd(cmd, G_PLL_VOTE, &st);
			if (st == 0u) {
				step = 1u;
			}
		}
		/* --- step 2: gmu_clk_src to GPLL0/1.5 = 200 MHz. The root has to be
		 * held on and waited for; switching the source under a stopped root
		 * leaves the branch without a parent clock. --- */
		if (step == 1u) {
			rcmd = rd(cmd, C_GMU_RCGR, &st);
			if (st == 0u) {
				(void)wr(cmd, C_GMU_RCGR, rcmd | RCG_ROOT_EN);
				rcmd = poll(cmd, C_GMU_RCGR, RCG_ROOT_OFF, 0u, 200u, &st);
				if (st == 0u && (rcmd & RCG_ROOT_OFF) == 0u) {
					rcfg = rd(cmd, C_GMU_RCGR + 4u, &st);
					(void)wr(cmd, C_GMU_RCGR + 4u,
					         (rcfg & ~RCG_CFG_CLEAR) | (GMU_SEL << 8) | GMU_HID);
					rcmd = rd(cmd, C_GMU_RCGR, &st);
					(void)wr(cmd, C_GMU_RCGR, rcmd | RCG_UPDATE);
					rcmd = poll(cmd, C_GMU_RCGR, RCG_UPDATE, 0u, 200u, &st);
					rcmd = rd(cmd, C_GMU_RCGR, &st);
					(void)wr(cmd, C_GMU_RCGR, rcmd & ~RCG_ROOT_EN);
					step = 2u;
				}
			}
		}
		/* --- step 3: the wake/sleep handshake fields --- */
		cgm = rd(cmd, C_CX_GMU_CLK, &st);
		if (step == 2u) {
			if (st == 0u && (cgm & GMU_WAKE_SLEEP) != GMU_WAKE_SLEEP) {
				(void)wr(cmd, C_CX_GMU_CLK, cgm | GMU_WAKE_SLEEP);
				cgm = rd(cmd, C_CX_GMU_CLK, &st);
			}
			if (st == 0u && (cgm & GMU_WAKE_SLEEP) == GMU_WAKE_SLEEP) {
				step = 3u;
			}
		}
		/* --- step 4: the five branches the GMU hangs from --- */
		if (step == 3u) {
			(void)branch(cmd, C_AHB_CLK);
			(void)branch(cmd, C_CX_GMU_CLK);
			(void)branch(cmd, C_CXO_CLK);
			(void)branch(cmd, G_AXI);
			(void)branch(cmd, G_MEMNOC);
			cgm = poll(cmd, C_CX_GMU_CLK, CBCR_CLK_OFF, 0u, 200u, &st);
			if (st == 0u && (cgm & CBCR_CLK_OFF) == 0u) {
				step = 4u;
			}
		}
	}
	if (step != 4u) {
		/* The clock ladder did not come up: say what it did see, and say
		 * so in the progress cell too (P=99 means the ladder, not the GMU). */
		txv(cmd, 7u, "E=", cgm, "F=", ahb);
		mark(cmd, 99u);
		goto park;
	}
	mark(cmd, 1u);

/* --- the GPU SMMU, before the GMU is released.
	 *
	 * The GMU is a master on this SMMU: every address it uses is
	 * translated, and with no context bank programmed for it the
	 * transactions fault while the firmware waits for a response that
	 * never comes. R100 stopped at the release of the CM3, which is
	 * exactly where that shows. R101 builds the context.
	 *
	 * The survey first: the shape of the register file comes out of the
	 * identity registers, and the stream slots are read before they are
	 * touched. --- */
	idr0 = rd(cmd, S_IDR0, &st);
	idr1 = rd(cmd, S_IDR1, &st);
	idr2 = rd(cmd, S_IDR2, &st);
	/* IDR1: bit 31 is PAGESIZE, bits 30:28 are NUMPAGENDXB, bits 7:0 are
	 * NUMCBANK. The context banks start after 2^(NUMPAGENDXB+1) pages,
	 * and the bank's own register file sits at (pages + bank) * stride. */
	stride = (idr1 & BIT31) ? 0x10000u : 0x1000u;
	pages = 1u << (((idr1 >> 28) & 7u) + 1u);
	banks = idr1 & 0xffu;
	cb0 = pages * stride;
	cb1 = cb0 + stride;               /* the GMU's bank: the one alioth used */
	cbase = S_BASE + cb1;
	cr0 = rd(cmd, S_CR0, &st);
	gfsr = rd(cmd, S_GFSR, &st);
	txv(cmd, 7u, "I=", idr0, "J=", idr1);
	txv(cmd, 8u, "K=", idr2, "P=", pages);
	txv(cmd, 9u, "B=", banks, "Q=", cb1);
	txv(cmd, 10u, "X=", cr0, "Y=", gfsr);
	if (idr1 == 0u || banks == 0u || banks > pages) {
		/* the identity registers did not read as this SMMU: every
		 * conclusion drawn from the shape would be void */
		mark(cmd, 89u);
		goto park;
	}
	for (i = 0; i < 6u; i++) {
		smr[i] = rd(cmd, S_SMR0 + i * 4u, &st);
	}
	for (i = 0; i < 6u; i++) {
		s2cr[i] = rd(cmd, S_S2CR0 + i * 4u, &st);
	}
	txv(cmd, 11u, "M0=", smr[0], "M1=", smr[1]);
	txv(cmd, 12u, "M2=", smr[2], "M3=", smr[3]);
	txv(cmd, 13u, "M4=", smr[4], "M5=", smr[5]);
	txv(cmd, 14u, "C0=", s2cr[0], "C1=", s2cr[1]);
	txv(cmd, 15u, "C2=", s2cr[2], "C3=", s2cr[3]);
	txv(cmd, 16u, "C4=", s2cr[4], "C5=", s2cr[5]);
	cbar0 = rd(cmd, S_CBAR0 + 0u, &st);
	cbar1 = rd(cmd, S_CBAR0 + 4u, &st);
	cba20 = rd(cmd, S_CBA2R0 + 0u, &st);
	cba21 = rd(cmd, S_CBA2R0 + 4u, &st);
	txv(cmd, 17u, "E0=", cbar0, "E1=", cbar1);
	txv(cmd, 18u, "E2=", cba20, "E3=", cba21);
	mark(cmd, 2u);

	/* --- the pages: the GMU's own memory and the five table pages. --- */
	for (i = 0; i < DATA_PAGES; i++) {
		if (alloc(cmd, &pa_data[i], &va_data[i]) != 0u) {
			txv(cmd, 19u, "A0=", i, "A1=", 1u);
			mark(cmd, 90u);
			goto park;
		}
	}
	/* The tables, leaves first: a table names the pages below it, so
	 * those have to be allocated before it. */
	{
		const u32 order[5] = { TB_LEA, TB_L2A, TB_LEB, TB_L2B, TB_ROOT };

		for (i = 0; i < TBL_PAGES; i++) {
			if (alloc(cmd, &pa_tbl[order[i]], &va_tbl[order[i]]) != 0u) {
				txv(cmd, 19u, "A0=", i, "A1=", 2u);
				mark(cmd, 90u);
				goto park;
			}
		}
	}
	/* The SMMU names physical addresses with 36 bits (IDR2's OAS field).
	 * A page above that cannot go into a descriptor, and the walk would
	 * fault in a way nothing on the screen could explain. */
	bad = 0u;
	for (i = 0; i < DATA_PAGES; i++) {
		if ((pa_data[i] >> SMMU_PA_BITS) != 0u) {
			bad = pa_data[i];
		}
	}
	for (i = 0; i < TBL_PAGES; i++) {
		if ((pa_tbl[i] >> SMMU_PA_BITS) != 0u) {
			bad = pa_tbl[i];
		}
	}
	if (bad != 0u) {
		txv(cmd, 19u, "PH=", (u32)bad, "PB=", 1u);
		mark(cmd, 96u);
		goto park;
	}
	/* R105: one value per line, and short lines: R104 aborted the kernel
	 * while drawing the 31st character of a 39 character line at row 20. */
	tx1(cmd, 19u, "PA=", pa_data[DP_ICACHE]);
	tx1(cmd, 20u, "PB=", pa_tbl[TB_ROOT]);
	tx1(cmd, 21u, "PC=", pa_tbl[TB_LEA]);
	tx1(cmd, 22u, "PD=", pa_tbl[TB_LEB]);
	mark(cmd, 3u);

	/* --- the tables themselves. The geometry is the one ArmSmmu4KLive.c
	 * walks with a 32 bit input address space: the root covers 1 GiB per
	 * entry, a level 2 table 2 MiB per entry and a leaf 4 KiB per entry.
	 *
	 * The icache (0x4000), the scratch (0x144000) and the debug block
	 * (0x157000) all lie in the first GiB and in its first 2 MiB, so they
	 * share one leaf. The dummy page, the log and the HFI queues lie in
	 * the second GiB, at the 256th entry of the second level 2 table,
	 * and share the other leaf. --- */
	for (i = 0; i < ICACHE_PGS; i++) {
		if (put(cmd, va_tbl[TB_LEA], 4u + i,
		        pa_data[DP_ICACHE + i] | DESC_ICACHE, out) != 0u) {
			errs++;
		}
	}
	for (i = 0; i < SCRATCH_PGS; i++) {
		if (put(cmd, va_tbl[TB_LEA], 324u + i,
		        pa_data[DP_SCRATCH + i] | DESC_DATA, out) != 0u) {
			errs++;
		}
	}
	for (i = 0; i < DEBUG_PGS; i++) {
		if (put(cmd, va_tbl[TB_LEA], 343u + i,
		        pa_data[DP_DEBUG + i] | DESC_DATA, out) != 0u) {
			errs++;
		}
	}
	/* R107: the dummy is four pages (0x60000000..0x60003fff) and the log
	 * is four pages (0x60004000..0x60007fff), so the leaf entries run
	 * 0..3, 4..7 and 8..11 in order.  The indices are the same as R106's
	 * (the level 2 table walks 4 KiB at a time); only the count changed. */
	for (i = 0; i < DUMMY_PGS; i++) {
		if (put(cmd, va_tbl[TB_LEB], 0u + i,
		        pa_data[DP_DUMMY + i] | DESC_DATA, out) != 0u) {
			errs++;
		}
	}
	for (i = 0; i < LOG_PGS; i++) {
		if (put(cmd, va_tbl[TB_LEB], 4u + i,
		        pa_data[DP_LOG + i] | DESC_DATA, out) != 0u) {
			errs++;
		}
	}
	for (i = 0; i < HFI_PGS; i++) {
		if (put(cmd, va_tbl[TB_LEB], 8u + i,
		        pa_data[DP_HFI + i] | DESC_DATA, out) != 0u) {
			errs++;
		}
	}
	if (put(cmd, va_tbl[TB_L2A], 0u, pa_tbl[TB_LEA] | 3ULL, out) != 0u) {
		errs++;
	}
	if (put(cmd, va_tbl[TB_L2B], 256u, pa_tbl[TB_LEB] | 3ULL, out) != 0u) {
		errs++;
	}
	if (put(cmd, va_tbl[TB_ROOT], 0u, pa_tbl[TB_L2A] | 3ULL, out) != 0u) {
		errs++;
	}
	if (put(cmd, va_tbl[TB_ROOT], 1u, pa_tbl[TB_L2B] | 3ULL, out) != 0u) {
		errs++;
	}
	/* the read back of one icache leaf entry and of the root's second entry */
	if (put(cmd, va_tbl[TB_LEA], 4u,
	        pa_data[DP_ICACHE] | DESC_ICACHE, out) != 0u) {
		errs++;
	}
	leaf_lo = out[0];
	leaf_hi = out[1];
	if (put(cmd, va_tbl[TB_ROOT], 1u, pa_tbl[TB_L2B] | 3ULL, out) != 0u) {
		errs++;
	}
	root_lo = out[0];
	root_hi = out[1];
	/* R107: rows 26 and 27 belong to the context bank read back (the
	 * context's own TTBR0 and TTBR1), so the leaf and the root read back
	 * move to row 30, which nothing else uses. */
	txv(cmd, 48u, "Y0=", leaf_lo, "Y1=", leaf_hi);
	txv(cmd, 43u, "Y2=", root_lo, "Y3=", root_hi);
	mark(cmd, 4u);

	/* --- the context bank, exactly as ArmSmmu4KProgram.c programs it:
	 * the bank is disabled first, then the attributes, then the
	 * translation registers, then the fault status, then the TLB, and
	 * only then the read back. A granule is never enabled before it has
	 * been read back. --- */
	rb_sctlr = rd(cmd, cbase + CB_CTL, &st);
	if (st == 0u && (rb_sctlr & CBCR_ENABLE) != 0u) {
		/* The bank is already enabled: it is not ours to take.
		 *
		 * The kit looks at the enable bit alone
		 * (ArmSmmu4KProgram.c: `if (sctlr & 1) return Busy`), and so
		 * does this. A granule that is disabled but still holds a
		 * stale SCTLR is ours to program, and the write below clears
		 * it; refusing to continue because of leftover bits would
		 * throw the round away for nothing. */
		txv(cmd, 59u, "Y0=", rb_sctlr, "Y1=", cbase);
		mark(cmd, 91u);
		goto park;
	}
	(void)wr(cmd, cbase + CB_CTL, 0u);
	(void)wr(cmd, S_CBA2R0 + 4u, CTX_CBA2R);
	(void)wr(cmd, S_CBAR0 + 4u, CTX_CBAR);
	(void)wr(cmd, cbase + CB_TCR2, CTX_TCR2);
	(void)wr(cmd, cbase + CB_TCR, CTX_TCR);
	(void)wr64(cmd, cbase + CB_TTBR0, ((u64)CTX_ASID << 48) | pa_tbl[TB_ROOT]);
	(void)wr64(cmd, cbase + CB_TTBR1, (u64)CTX_ASID << 48);
	(void)wr(cmd, cbase + CB_MAIR0, CTX_MAIR0);
	(void)wr(cmd, cbase + CB_MAIR1, CTX_MAIR1);
	(void)wr(cmd, cbase + CB_FSR, 0xffffffffu);
	/* invalidate this ASID and wait for the SMMU to say it is done */
	(void)wr(cmd, cbase + CB_TLBIASID, CTX_ASID);
	(void)wr(cmd, cbase + CB_TLBSYNC, 0xffffffffu);
	(void)poll(cmd, cbase + CB_TLBSTAT, 1u, 0u, 200u, &st);
	mark(cmd, 5u);

	/* The read back, with the tolerances the kit documents: TCR2's TBI
	 * bits may read 1 where they were written 0, SCTLR's ASIDPNE may
	 * read 0 where it was written 1, and TCR's EPD1 may read 0. */
	rb_cbar = rd(cmd, S_CBAR0 + 4u, &st);
	rb_cba2r = rd(cmd, S_CBA2R0 + 4u, &st);
	rb_tcr = rd(cmd, cbase + CB_TCR, &st);
	rb_tcr2 = rd(cmd, cbase + CB_TCR2, &st);
	rb_mair0 = rd(cmd, cbase + CB_MAIR0, &st);
	rb_mair1 = rd(cmd, cbase + CB_MAIR1, &st);
	rb_sctlr = rd(cmd, cbase + CB_CTL, &st);
	rb_ttbr0 = rd(cmd, cbase + CB_TTBR0, &st);
	rb_ttbr0 |= ((u64)rd(cmd, cbase + CB_TTBR0 + 4u, &st) << 32);
	rb_ttbr1 = rd(cmd, cbase + CB_TTBR1, &st);
	rb_ttbr1 |= ((u64)rd(cmd, cbase + CB_TTBR1 + 4u, &st) << 32);
	rb_fsr = rd(cmd, cbase + CB_FSR, &st);
	txv(cmd, 61u, "F0=", rb_cbar, "F1=", rb_cba2r);
	txv(cmd, 62u, "F2=", rb_tcr, "F3=", rb_tcr2);
	txv(cmd, 63u, "F4=", rb_mair0, "F5=", rb_sctlr);
	txv(cmd, 64u, "G0=", (u32)rb_ttbr0, "G1=", (u32)(rb_ttbr0 >> 32));
	txv(cmd, 65u, "G2=", (u32)rb_ttbr1, "G3=", rb_fsr);
	bad = 0u;
	if (rb_cbar != CTX_CBAR) {
		bad |= 1u;
	}
	if (rb_cba2r != CTX_CBA2R) {
		bad |= 2u;
	}
	if ((rb_tcr ^ CTX_TCR) & ~0x00800000u) {
		bad |= 4u;
	}
	if ((rb_tcr2 ^ CTX_TCR2) & ~0x00000060u) {
		bad |= 8u;
	}
	if (rb_mair0 != CTX_MAIR0) {
		bad |= 16u;
	}
	if (rb_mair1 != CTX_MAIR1) {
		bad |= 32u;
	}
	if (rb_sctlr != 0u) {
		bad |= 64u;
	}
	if (rb_ttbr0 != (((u64)CTX_ASID << 48) | pa_tbl[TB_ROOT])) {
		bad |= 128u;
	}
	if (rb_ttbr1 != ((u64)CTX_ASID << 48)) {
		bad |= 256u;
	}
	if (errs != 0u) {
		bad |= 512u;
	}
	if (bad != 0u) {
		/* The granule is not what was asked for. Leave it disabled,
		 * leave the CM3 in reset, and let the screen say why: a
		 * release into a context that is not there is the one way to
		 * hang the interconnect. */
		txv(cmd, 42u, "BD=", bad, "ER=", errs);
		mark(cmd, 92u);
		goto park;
	}
	(void)wr(cmd, cbase + CB_CTL, CTX_SCTLR);
	rb_sctlr = rd(cmd, cbase + CB_CTL, &st);
	if (st != 0u || (rb_sctlr & CBCR_ENABLE) == 0u) {
		txv(cmd, 42u, "EN=", rb_sctlr, "ER=", errs);
		mark(cmd, 92u);
		goto park;
	}
	/* The fault status of the bank, now that it runs. Nothing has
	 * translated yet -- the GMU is in reset and the GPU is off -- so
	 * anything here is left over from before the clear. It is printed
	 * rather than used to stop: the cold start below is what this round
	 * is for, and the fault registers are read again at the end. */
	rb_fsr = rd(cmd, cbase + CB_FSR, &st);
	if ((rb_fsr & 0xc00001feu) != 0u) {
		txv(cmd, 42u, "FS=", rb_fsr, "ER=", errs);
	}
	mark(cmd, 6u);

	/* --- the GMU's two streams, as alioth programmed them. The kit calls
	 * a slot free only when its S2CR reads exactly the FAULT word; this
	 * part's unused slots read zero, which is TRANSLATE and not free, so
	 * the two slots are rewritten to the canonical FAULT word first. The
	 * GMU is in reset and the GPU is off, so no slot carries a live
	 * route. The context goes in before the stream id: a slot with a
	 * valid SMR and no context behind it would fault. --- */
	(void)wr(cmd, S_S2CR0 + GMU_SLOT_A * 4u, S2CR_FAULT);
	(void)wr(cmd, S_S2CR0 + GMU_SLOT_B * 4u, S2CR_FAULT);
	(void)wr(cmd, S_S2CR0 + GMU_SLOT_A * 4u, S2CR_BANK);
	rb_s2cra = rd(cmd, S_S2CR0 + GMU_SLOT_A * 4u, &st);
	(void)wr(cmd, S_SMR0 + GMU_SLOT_A * 4u, SMR_VALID | GMU_SID_A);
	rb_smra = rd(cmd, S_SMR0 + GMU_SLOT_A * 4u, &st);
	(void)wr(cmd, S_S2CR0 + GMU_SLOT_B * 4u, S2CR_BANK);
	rb_s2crb = rd(cmd, S_S2CR0 + GMU_SLOT_B * 4u, &st);
	(void)wr(cmd, S_SMR0 + GMU_SLOT_B * 4u, SMR_VALID | GMU_SID_B);
	rb_smrb = rd(cmd, S_SMR0 + GMU_SLOT_B * 4u, &st);
	if (rb_smra != (SMR_VALID | GMU_SID_A) || rb_s2cra != S2CR_BANK ||
	    rb_smrb != (SMR_VALID | GMU_SID_B) || rb_s2crb != S2CR_BANK) {
		/* The stream did not take.
		 *
		 * alioth saw exactly this on this silicon: an SMR write that
		 * reads back its old value while the S2CR write does land
		 * (so the context is behind the slot, but the stream id is
		 * not matched). The context bank is programmed either way, and
		 * the cold start is the thing worth measuring, so this is
		 * recorded and the run goes on. Row 43 says out loud that the
		 * result below is not conclusive -- a GMU that cannot reach
		 * its icache would fail for a reason that has nothing to do
		 * with the firmware. */
		txv(cmd, 42u, "H4=", rb_smra, "H5=", rb_s2cra);
		txs(cmd, 59u, "STREAMS NOT ATTACHED - the cold start below is NOT conclusive");
	}
	mark(cmd, 7u);

	/* --- phase 1, read only: the GMU must be held in reset before a cold
	 * start, the RSC sequencer must be idle, and no stale HFI readiness. --- */
	v = rd(cmd, M_CM3_SYSRESET, &st);
	rsc = rd(cmd, R_SEQ_BUSY, &st);
	txv(cmd, 66u, "R0=", v, "R1=", rsc);
	mark(cmd, 8u);

	/* --- phase 2: the interrupt clear and mask, the RSC sequencer's
	 * microcode and the PDC, then a6xx_rpmh_stop. --- */
	for (i = 0; i < 44u; i += 2u) {
		(void)wr(cmd, g_rsc[i], g_rsc[i + 1u]);
	}
	(void)wr(cmd, M_RSCC_REQ, 1u);
	rsc = poll(cmd, R_SC_STATUS0, 0x00010000u, 0x00010000u, 200u, &st);
	(void)wr(cmd, M_RSCC_REQ, 0u);
	mark(cmd, 9u);

	/* --- phase 3: a6xx_gmu_fw_start (cold): the FAL retention
	 * interfaces, GENERAL_7, then the RSC wake request. --- */
	(void)wr(cmd, M_FALNEXT, 1u);
	(void)wr(cmd, M_FAL, 1u);
	(void)wr(cmd, M_GEN7, 1u);
	(void)wr(cmd, M_RSCC_REQ, 2u);
	ack = poll(cmd, M_RSCC_ACK, 2u, 2u, 200u, &st);
	/* R109: the official's phase 3 waits for the RSC sequencer to go
	 * idle before it drops the request again, and so does Linux's
	 * a6xx_rpmh_start ("GPU RSC sequence stuck while waking up the GPU").
	 * The probe never did this: it read the acknowledgement and wrote
	 * RSCC_CONTROL_REQ back to zero straight away, so the sequencer was
	 * never known to have finished the wake it had just been told to
	 * start.  The value it leaves behind is printed on row 50. --- */
	seqb = poll(cmd, R_SEQ_BUSY, ~0u, 0u, 200u, &st);
	(void)wr(cmd, M_RSCC_REQ, 0u);
	txv(cmd, 36u, "Z=", vt, "A=", ack);
	txv(cmd, 56u, "SB=", seqb, "RS=", rd(cmd, R_SC_STATUS0, &st));
	mark(cmd, 10u);

	/* --- phase 4: the firmware. The two TCM blocks go through the GMU's
	 * register windows; the icache and the debug block go into the
	 * kernel pages the SMMU maps for the GMU, which is the part R100
	 * left as zeroes.
	 *
	 * R107, and it follows alioth's phase 4 to the letter: the GMU's
	 * memory is zeroed first, the HFI queue table is set up second, and
	 * only then does the firmware go in.  R106 copied the firmware in
	 * first and wrote the queue table afterwards, which works only as
	 * long as nothing reads the table in between. */
	fx.cmd = cmd;
	fx.chunk = chunk;
	fx.out = out;
	fx.va_data = va_data;
	fx.errs = 0u;
	fx.nread = 0u;
	fx.sum = 0u;
	fx.chk = 0u;

	/* the GMU's memory, zeroed, before a single byte of firmware
	 * goes in (alioth's phase 4)
	 *
	 * R107: the failures are counted and not fatal.  The kernel's
	 * allocator hands out zeroed pages already, so a zeroing call that
	 * does not go through is a curiosity, not a reason to throw the
	 * round away -- the cold start and the fault registers that follow
	 * are the thing worth measuring. */
	zerr = zero_pages(cmd, va_data, DP_ICACHE, ICACHE_PGS, out) + zerr;
	zerr = zero_pages(cmd, va_data, DP_SCRATCH, SCRATCH_PGS, out) + zerr;
	zerr = zero_pages(cmd, va_data, DP_DEBUG, DEBUG_PGS, out) + zerr;
	zerr = zero_pages(cmd, va_data, DP_DUMMY, DUMMY_PGS, out) + zerr;
	zerr = zero_pages(cmd, va_data, DP_LOG, LOG_PGS, out) + zerr;
	zerr = zero_pages(cmd, va_data, DP_HFI, HFI_PGS, out) + zerr;
	mark(cmd, 60u);

	/* the HFI queue table, exactly as AdrenoHfiInitializeStopped writes
	 * it: the header, then three queue headers that each name their ring
	 * on the page after their own.  The sixteen kilobytes around the
	 * header are already zero; AdrenoHfiInitializeStopped clears them
	 * again before it writes the header, and so does this. */
	{
		u32 h[40];

		for (i = 0; i < 40u; i++) {
			h[i] = 0u;
		}
		h[1] = 168u;
		h[2] = 6u;
		h[3] = 12u;
		h[4] = 3u;
		h[5] = 3u;
		for (i = 0; i < 3u; i++) {
			u32 v0 = 6u + 12u * i;

			h[v0 + 0u] = 1u;
			h[v0 + 1u] = HFI_IOVA + (i + 1u) * 4096u;
			h[v0 + 2u] = 0xa00u | i;
			h[v0 + 3u] = 1024u;
			h[v0 + 6u] = 1u;
			h[v0 + 7u] = 1u;
			h[v0 + 8u] = 1u;
		}
		if (wva(cmd, va_data[DP_HFI], 0u, 40u, h, out) != 0u) {
			errs++;
		}
	}

	/* --- and now the firmware itself goes in, into the memory that was
	 * zeroed and with the queue table already standing. --- */
	fd = (int)sys6(SYS_open, (i64)"/probe.bin", 0, 0, 0, 0, 0);
	fx.fd = (i64)fd;
	if (fd < 0) {
		txv(cmd, 32u, "FD=", 0u, "ER=", 1u);
		mark(cmd, 89u);
		goto park;
	}
	rc = fw_load(&fx);
	if (rc != 0u) {
		txv(cmd, 32u, "FD=", rc, "ER=", fx.errs);
		mark(cmd, 89u);
		goto park;
	}
	errs += fx.errs;
	txv(cmd, 32u, "N=", fx.nread, "E=", fx.errs);
	txv(cmd, 33u, "Z=", fx.sum, "Q=", (u32)fd);
	mark(cmd, 11u);

	/* --- the proof that the bytes landed. The firmware's own version word
	 * sits in the DTCM and its vector table at the top of the ITCM, and
	 * alioth reads the same word (GMU_CM3_DTCM_START + 0xff8 in dwords,
	 * which is 0x3fe8 in bytes) before it releases the CM3, to choose
	 * between the two ready conventions. For this firmware the word is
	 * 0x20010008 and the vector table starts with the stack pointer
	 * 0x10007f80 and the reset vector 0x11. The write's own success cannot
	 * say any of this; only the bytes themselves can. --- */
	(void)rdm(cmd, M_DTCM + 0x3FE8u, 1u, bk);
	ver = bk[0];
	(void)rdm(cmd, M_ITCM, 4u, bk);
	it0 = bk[0];
	it1 = bk[1];
	it2 = bk[2];
	it3 = bk[3];
	txv(cmd, 34u, "V=", ver, "T=", it0);
	txv(cmd, 35u, "U=", it1, "W=", it2);
	/* the vector table is the proof that the CM3's code is really there:
	 * the stack pointer, the reset vector, NMI and HardFault */
	vt = (it0 == 0x10007f80u && it1 == 0x11u && it2 == 0x71u &&
	      it3 == 0x99u) ? 1u : 0u;
	/* R110: the table the CM3 actually uses is not this one.  The
	 * bootstrap at ITCM+0x10 copies 0x200 into VTOR (0xe000ed08), so
	 * the vector table the firmware's own exceptions go through is the
	 * one at ITCM+0x200 -- the container has a block there, 0x140
	 * bytes of it -- while the table at ITCM+0 is only the bootstrap's.
	 * Both are read now: the bootstrap's fourth word (it3) has never
	 * been shown on the panel, because the vector table check itself
	 * was printed on row 36, which runs before the table is read. */
	(void)rdm(cmd, M_ITCM + 0x200u, 4u, bk);
	txv(cmd, 2u, "A0=", bk[0], "A1=", bk[1]);
	txv(cmd, 3u, "A2=", bk[2], "A3=", bk[3]);
	mark(cmd, 12u);

	/* --- phase 5: the boot registers, each one read back, and the RPMh
	 * votes. --- */
	for (i = 0; i < 24u; i += 2u) {
		(void)wr(cmd, g_p5[i], g_p5[i + 1u]);
	}
	v = rd(cmd, M_RPMH, &st);
	(void)wr(cmd, M_RPMH, v | RPMH_VOTES);
	vmask = 0u;
	for (i = 0; i < 24u; i += 2u) {
		v = rd(cmd, g_p5[i], &st);
		if (st != 0u || v != g_p5[i + 1u]) {
			vmask |= 1u << (i >> 1);
		}
	}
	mark(cmd, 13u);

	/* R113: the chip id register, read back so that the panel shows the
	 * value the CM3 itself will read.
	 *
	 * This is the one register whose contents the CM3 validates, and
	 * the validation is what stopped it.  The CM3's own view of the
	 * GMU register block starts at 0x1807e000, which is the same block
	 * the host sees at 0x03d7e000: 0x1807e0b4 is CM3_CFG, 0x1807e404
	 * is CP_RESP and 0x1807e600 is HFI_CTRL_STATUS, all three at the
	 * same offset from their two bases.  So the address the firmware
	 * reads at ITCM+0x28d6, 0x1807e608, is this register:
	 * GMU_HFI_SFR_ADDR, the chip id.
	 *
	 * The check the firmware runs on it (ITCM+0x28cc) takes the value
	 * apart into four bytes and puts them back the other way round,
	 * then insists that the top byte is 6 -- the Adreno 6xx family --
	 * and that the second byte is 2 or 5, the a640 and the a650.  The
	 * official writes 0x06050200 there, which unpacks to 0x06050002:
	 * 6 and 5.  This table used to write 0x60500200, which unpacks to
	 * 0x60500002: 0x60 and 0x50, and the check failed with error
	 * code 3.  That is the whole reason the CM3 never reached its
	 * ready state: it took an NMI, wrote two log entries and stopped.
	 *
	 * Printing the value that is actually in the register, rather
	 * than the constant, is what proves the fix landed. --- */
	/* R115: the chip id's read back is not printed any more.  R113
	 * proved it is 0x06050200 and that the CM3 accepted it, and rows
	 * 20 to 31 now carry the startup sequence's results, which is
	 * what this round is about. */

	/* --- phase 6: a6xx_gmu_start. This is the step R99 stopped in, so it
	 * is now the last thing that happens and everything that could be
	 * learned has already been printed.
	 *
	 * alioth's order is: reset, clear the power controller's response,
	 * release, then poll FW_INIT_RESULT for the ready value that the
	 * version word chose. R99 also wrote FW_INIT_RESULT to zero first,
	 * which is harmless but not needed: phase 5 already wrote it as zero.
	 *
	 * The release is guarded. The version word in the DTCM says whether the
	 * firmware is really in the TCM, and if it is not, the CM3 would jump
	 * into whatever the ITCM happens to hold and hang the interconnect --
	 * which is the most likely reason R99 never got past mark(7). So the
	 * release only happens when the version word is the a650's, and
	 * otherwise the run stops here with everything on the screen. --- */
	if ((ver & 0xffff0000u) != 0x20010000u) {
		txv(cmd, 42u, "NR=", ver, "MX=", 0u);
		mark(cmd, 98u);
		goto park;
	}
	mask = (ver <= 0x20010004u) ? 0xffffffffu : 0x1ffu;
	want = (mask == 0xffffffffu) ? READY_OLD : READY_NEW;
	(void)wr(cmd, M_CM3_SYSRESET, 1u);
	mark(cmd, 14u);
	(void)wr(cmd, M_CP_RESP, 0u);
	mark(cmd, 15u);
	(void)wr(cmd, M_CM3_SYSRESET, 0u);
	mark(cmd, 16u);
	fw = poll(cmd, M_CM3_FW_INIT, mask, want, 800u, &st);
	ready = ((fw & mask) == want) ? 1u : 0u;
	txv(cmd, 37u, "F=", fw, "R=", ready);
	mark(cmd, 17u);

	/* --- phase 7: a6xx_gmu_hfi_start. --- */
	(void)wr(cmd, M_HFI_INIT, 1u);
	hfi = poll(cmd, M_HFI_STATUS, 1u, 1u, 300u, &st);
	mark(cmd, 18u);

	/* R109: the two fault registers are read BEFORE the clear that
	 * follows, because the clear is exactly what makes them useless.
	 * The official's check_faults() reads them on every round of the
	 * phase 6 and phase 7 polls, so a CM3 or AO fault that happens
	 * during the cold start is caught there; the probe had been
	 * clearing them first and reading them afterwards, which means a
	 * fault during the cold start was erased before anybody looked at
	 * it.  Row 51 now carries what was there before the clear, and
	 * row 48's W= carries the same value. --- */
	iinf = rd(cmd, M_GM2INFO, &st);
	ao = rd(cmd, M_AO_STATUS, &st);
	txv(cmd, 57u, "FI=", iinf, "AO=", ao);

	/* --- R114: the HFI conversation, and then the GX power vote.
	 *
	 * R113 ended with a running GMU: the chip id check passed, the
	 * firmware reported the ready value and the HFI status bit came up.
	 * Everything the cold start is supposed to achieve is achieved.
	 *
	 * What is left is the part that turns a running GMU into a running
	 * GPU, and it starts with a conversation over the HFI queues.  The
	 * official does it in two stages: a6xx_hfi_start sends the
	 * performance table (message 4), the bandwidth table (message 3),
	 * the core firmware start (message 14) and the start (message 10),
	 * each waiting for its acknowledgement; then A650GmuPowerGx sends
	 * the GX_BW_PERF_VOTE (message 30) and rings HOST2GMU bit 30, and
	 * the CM3 answers on GMU2HOST bit 31.
	 *
	 * The performance and the bandwidth tables need the gfx, mx and cx
	 * rail tables, which come out of the command database that nio does
	 * not have.  So R114 does the part that does not need them and
	 * reads everything back:
	 *
	 *   - the three queue headers, before anything is sent.  If the CM3
	 *     is running the HFI task it has moved the read and write
	 *     pointers of the response queue; if they are still zero the
	 *     queues were never touched and the whole idea is wrong.
	 *   - message 10, the start, with no payload.  It is the last
	 *     message of the startup sequence and the one that needs no
	 *     table.
	 *   - the answer, if there is one.
	 *   - the GX power status register before and after the vote.
	 *
	 * The votes and the tables come later, once the command database
	 * is in hand.  What R114 establishes is the transport. */
	hq[0] = hq[1] = hq[2] = hq[3] = 0u;
	hq[4] = hq[5] = hq[6] = hq[7] = 0u;
	hst = hfi_head(cmd, pa_data + DP_HFI, 0u, hq);
	hst2 = hfi_head(cmd, pa_data + DP_HFI, 1u, hq + 4u);
	txv(cmd, 73u, "H0=", hq[0], "H1=", hq[1]);
	txv(cmd, 51u, "H2=", hq[4], "H3=", hq[5]);
	txv(cmd, 60u, "Q0=", hst, "Q1=", hst2);

	/* the GX power status before anything is asked of it */
	gx0 = rd(cmd, M_SPTC_PWR, &st);
	txv(cmd, 46u, "P0=", gx0, "S=", st);

	/* --- R115: the startup sequence.
	 *
	 * a6xx_hfi_start sends four stages and waits for each of them: the
	 * performance table (message 4), the bandwidth table (message 3),
	 * the core start (message 14) and the start (message 10).  Only
	 * then does A650GmuPowerGx send the GX_BW_PERF_VOTE (message 30)
	 * and ring HOST2GMU bit 30.
	 *
	 * Every stage's outcome is printed, so one run says which stage
	 * stopped and what the firmware answered:
	 *
	 *   row 20  the performance table, sent
	 *   row 21  its answer: the header and the returned header
	 *   row 22  its error code and the answer's word count
	 *   row 23  the bandwidth table, sent
	 *   row 24  its answer
	 *   row 25  its error code
	 *   row 26  the core start and the start, sent
	 *   row 27  their answers
	 *   row 48  their error codes
	 *   row 28  the GX vote, sent
	 *   row 29  its answer: the status and the word count
	 *   row 30  its header and its error code
	 *   row 31  the GX power status, before and after
	 *   row 49  the out of band interrupt and the GX status
	 *   row 47  the wait status of each of the five messages
	 *   row 44  the GX branch's power register and the GPU's RBBM status
	 *
	 * The sequence number goes up by one per packet, as AdrenoHfiSend
	 * does, and each packet is waited for before the next one is sent,
	 * as AdrenoHfiStartupRun does. */
	seq = 0u;

	/* message 4: the performance table */
	nw = hfi_perf(pl);
	seq = seq + 1u;
	hdr = 0u;
	hsend = hfi_send(cmd, pa_data + DP_HFI, va_data + DP_HFI, 4u, pl, nw,
	                 seq, &hdr);
	txv(cmd, 20u, "S4=", hsend, "W=", hdr);
	hrc = hfi_wait(cmd, pa_data + DP_HFI, va_data + DP_HFI, hdr, hq + 8u, &hn);
	w4 = hrc;
	txv(cmd, 21u, "H4=", hq[8], "R4=", hq[9]);
	txv(cmd, 22u, "E4=", hq[10], "N4=", hn);

	/* message 3: the bandwidth table */
	nw = hfi_bw(pl);
	seq = seq + 1u;
	hdr = 0u;
	hsend = hfi_send(cmd, pa_data + DP_HFI, va_data + DP_HFI, 3u, pl, nw,
	                 seq, &hdr);
	txv(cmd, 23u, "S3=", hsend, "W=", hdr);
	hrc = hfi_wait(cmd, pa_data + DP_HFI, va_data + DP_HFI, hdr, hq + 8u, &hn);
	w3 = hrc;
	txv(cmd, 24u, "H3=", hq[8], "R3=", hq[9]);
	txv(cmd, 25u, "E3=", hq[10], "N3=", hn);

	/* message 14: the core start, and message 10: the start */
	pl[0] = 0u;
	seq = seq + 1u;
	hdr = 0u;
	hsend = hfi_send(cmd, pa_data + DP_HFI, va_data + DP_HFI, 14u, pl, 1u,
	                 seq, &hdr);
	hrc = hfi_wait(cmd, pa_data + DP_HFI, va_data + DP_HFI, hdr, hq + 8u, &hn);
	w1 = hrc;
	txv(cmd, 26u, "S1=", hsend, "E1=", hq[10]);
	seq = seq + 1u;
	hdr = 0u;
	hsend = hfi_send(cmd, pa_data + DP_HFI, va_data + DP_HFI, 10u,
	                 (const u32 *)0, 0u, seq, &hdr);
	hrc = hfi_wait(cmd, pa_data + DP_HFI, va_data + DP_HFI, hdr, hq + 8u, &hn);
	w0 = hrc;
	txv(cmd, 27u, "S0=", hsend, "E0=", hq[10]);

	/* message 30: the GX bandwidth and performance vote.  The official
	 * exchanges the message first and only then rings the doorbell, so
	 * the answer is waited for here too. */
	{
		u32 vote[3];

		vote[0] = 1u;          /* blocking acknowledgement */
		vote[1] = 1u;          /* perf index 1: the lowest GPU level */
		vote[2] = 0u;          /* no DDR bandwidth vote */
		seq = seq + 1u;
		hdr2 = 0u;
		hsend2 = hfi_send(cmd, pa_data + DP_HFI, va_data + DP_HFI, 30u,
		                  vote, 3u, seq, &hdr2);
		txv(cmd, 28u, "V0=", hsend2, "V1=", hdr2);
	}
	hrc = hfi_wait(cmd, pa_data + DP_HFI, va_data + DP_HFI, hdr2, hq + 8u, &hn2);
	wv = hrc;
	txv(cmd, 29u, "VR=", hrc, "VN=", hn2);
	txv(cmd, 30u, "VH=", hq[8], "VE=", hq[10]);

	/* the wait status of every message, so that a run says which one
	 * did not get its answer: 0 is the answer, 1 is the ring stayed
	 * empty, 2 is the firmware's error reply */
	txv(cmd, 47u, "W4=", w4, "W3=", w3);
	txv(cmd, 53u, "W1=", w1, "W0=", w0);
	txv(cmd, 44u, "WV=", wv, "E=", hq[10]);

	/* the out of band request, and a long enough wait for it.
	 *
	 * R114 waited 100 rounds of spin(200), which is about twenty
	 * microseconds in all: far too short for a GPU domain to come up.
	 * A GPU power on takes milliseconds, so the wait here is a
	 * million spin iterations per round and twenty rounds. */
	(void)wr(cmd, M_H2G_SET, 1u << 30);
	gxi = 0u;
	for (i = 0; i < 20u; i++) {
		for (j = 0; j < 500u; j++) {
			spin(2000u);
		}
		gxi = rd(cmd, M_GM2INFO, &st);
		if ((gxi & (1u << 31)) != 0u) {
			break;
		}
	}
	(void)wr(cmd, M_GM2CLR, 1u << 31);
	gx1 = rd(cmd, M_SPTC_PWR, &st);
	txv(cmd, 31u, "P1=", gx1, "P2=", gxi);
	txv(cmd, 49u, "OI=", gxi, "GX=", ((gx1 & 0xc0u) == 0u) ? 1u : 0u);

	/* R116: is the GPU core itself alive?  The GX branch's power
	 * register says the branch is powered, and the GPU's own register
	 * bank answers: a non-zero RBBM_STATUS is the register bank
	 * running, which is what the alioth probe reads for the same
	 * purpose (its "rbbm 00000001" next to "gx 000000c0>00000000"). */
	{
		u32 gxgd = rd(cmd, C_GX_GDSCR, &st);
		u32 rbbm = rd(cmd, G_RBBM_STATUS, &st);

		txv(cmd, 45u, "GD=", gxgd, "RB=", rbbm);
	}

	/* --- R108: a6xx_gmu_resume's last two words, the ones the official
	 * A650Gmu.c writes after the HFI protocol has come up (its phase 8:
	 * "a6xx_gmu_resume after a6xx_hfi_start: clear GMU2HOST and unmask
	 * only the CM3 fault").  The clear alone is in phase 2's g_rsc, as
	 * the official does; the mask belongs here, because until the queues
	 * are up the CM3's own fatal interrupt (GM2HOST_INTR_MASK bit 23,
	 * CM3_FATAL) has to stay masked or a stale bit in GMU2HOST_INTR_INFO
	 * reads as a CM3 fault and the cold start never completes.
	 *
	 * R109 also moved the two fault register reads in front of the
	 * clear (see the note above the phase 7 poll) and put the hidden
	 * TCS command's data and address back the way Linux writes them. */
	(void)wr(cmd, M_GM2CLR, 0xffffffffu);
	(void)wr(cmd, M_GM2MASK, ~0x00800000u);

	/* --- R107: the firmware's own side of the handshake, and the SMMU's
	 * account of it.
	 *
	 * R106 read F=00000901 out of FW_INIT_RESULT: the low nine bits are
	 * 0x101 where a happy a650 reports 0x100, so the ready test failed on
	 * bit 0 alone, and HFI came up zero as a consequence.  Both readings
	 * fit two very different states -- a firmware that is running and
	 * reporting something extra, or one that stopped at its first check.
	 *
	 * The question R106 could not answer is whether the firmware ever
	 * reached the GMU's memory at all, and if it did and the transaction
	 * was refused, the SMMU would say so.  The context bank that the GMU
	 * is routed through keeps the fault status register (FSR) at +0x058,
	 * the fault address register (FAR) at +0x200 and the invalid fault
	 * status register (IFSR) at +0x208.  FAR is the address that was
	 * refused: one read of it would name the hole the firmware ran into.
	 * R106 never read any of them -- it read the global GFSR, which stays
	 * zero for a fault that belongs to a context.
	 *
	 * The rows R106 borrowed are given back: the SMMU context read back
	 * and the two stream slots are on rows 24 to 29 again, and R106's own
	 * readings move down to rows 44 and up.
	 *
	 * Every rd() is one io_submap and the blob's budget for those is 2048
	 * for the whole run; phase 6's 800 rounds and phase 7's 500 already
	 * spend most of it, so the reads below are few and deliberate. --- */

	/* the context bank's fault registers, after the cold start */
	cfsr = rd(cmd, cbase + CB_FSR, &st);
	cfar = rd(cmd, cbase + CB_FAR, &st);
	cifsr = rd(cmd, cbase + CB_IFSR, &st);
	gfsr2 = rd(cmd, S_GFSR, &st);
	txv(cmd, 0u, "FS=", cfsr, "FA=", cfar);
	txv(cmd, 1u, "IS=", cifsr, "GM=", gfsr2);

	/* the log page, where phase 5 points the firmware, as words rather
	 * than as text: R106 printed it as text and the result was a row of
	 * unprintable boxes.  As words the header is readable.
	 *
	 * R109: sixteen words instead of four.  PWR_COL_CP_RESP came back as
	 * 2, which reads like "two entries in the log", so the header alone
	 * does not say where the CM3 stopped; the first sixteen words might.
	 * One op 7 round trip reads all of them (MR_MAX is 24). --- */
	if (rdm(cmd, (u32)pa_data[DP_LOG], 16u, lg) == 0u) {
		txv(cmd, 52u, "L0=", lg[0], "L1=", lg[1]);
		/* R116: row 53 carries the message 14 and message 10 wait
		 * statuses now, so the second pair of log words moves to
		 * row 72. */
		txv(cmd, 72u, "L2=", lg[2], "L3=", lg[3]);
	}

	/* R111 printed the log page as text, in rows 44 to 51, on the theory
	 * that the low half of each log code was a byte offset into the log
	 * buffer where the message text would be.  The recording came back
	 * with all eight rows showing the same unprintable glyph in every
	 * cell: the page holds the two records and then nothing at all, so
	 * the text is not in the log buffer.  Those rows are free again.
	 *
	 * R112 puts the CM3's own boot-stage counter there instead, and its
	 * stack below it. --- */

	/* --- R112: the CM3's boot-stage counter and its stack.
	 *
	 * The GMU firmware's ITCM bootstrap shifts a stage code into the low
	 * byte of the word at DTCM+0x3fdc: 1 when it starts, 2 once the
	 * vector table and the stack are set up, 3 if an NMI is taken, 4 if
	 * a hard fault is taken, and 0x12 and 0x13 on the two fatal paths
	 * out of the init chain (ITCM+0x4c0 and ITCM+0x4a0).  The word
	 * starts at 0xffffffff and each stage shifts the previous value up
	 * by eight bits before adding its own code, so the low byte is the
	 * last stage and the byte above it is the one before that.
	 *
	 * Nothing else in the image writes that word, which makes it the one
	 * place the firmware records how far it got.
	 *
	 * The stack pointer starts at the top of the DTCM (0x10007f80) and
	 * the bootstrap fills the 0xf80 bytes below it with 0xaaaaaaaa, so
	 * the words that are not 0xaaaaaaaa are the ones the firmware
	 * actually pushed -- the call chain it was in when it stopped. --- */
	(void)rdm(cmd, M_DTCM + 0x3FDCu, 8u, dt);
	/* R116: rows 44, 45 and 47 carry the HFI wait statuses and the GPU
	 * register bank's answer now, so the stage counter moves down to
	 * rows 68 to 71.  It says how far the CM3 got, which is what the
	 * earlier rounds needed it for. */
	txv(cmd, 68u, "SG=", dt[0], "D0=", dt[1]);
	txv(cmd, 69u, "D1=", dt[2], "D2=", dt[3]);
	txv(cmd, 70u, "D3=", dt[4], "D4=", dt[5]);
	txv(cmd, 71u, "D5=", dt[6], "D6=", dt[7]);
	(void)rdm(cmd, M_DTCM + 0x3F00u, 24u, sk);
	(void)rdm(cmd, M_DTCM + 0x3F60u, 8u, sk + 24);
	/* the top of the stack first: that is where the first frames are */
	for (si = 0; si < 4u; si++) {
		u32 w[8];
		for (sj = 0; sj < 8u; sj++) {
			w[sj] = sk[31u - si * 8u - sj];
		}
		txw(cmd, 61u + si, w, 8u);
	}

	/* R110: the vector table check, printed where it means something.
	 * Row 36 has carried a "T=" that was this variable read before the
	 * table had been read at all, so it was the variable's initial
	 * value and not the result of the check.  The check itself never
	 * reached the panel; it does now, next to the fourth word of the
	 * bootstrap's table. --- */
	txv(cmd, 55u, "VT=", vt, "D=", rd(cmd, M_DCACHE_CFG, &st));

	/* whether the first words of the icache payload came back out of
	 * the page they went into, and how many of the zeroing calls did
	 * not go through */
	txv(cmd, 4u, "Y0=", fx.chk, "Y1=", zerr);

	/* the power controller's pair: PWR_COL_CP_MSG is where phase 5 points
	 * the firmware (the log), and PWR_COL_CP_RESP is the answer to it.
	 * R106 cleared CP_RESP before the release and never read it back, so
	 * whatever the firmware had to say about the release went unread.
	 * The two reads are separate statements on purpose: one expression
	 * with both of them would modify the same status word twice with
	 * nothing in between, which is undefined behaviour. */
	cpres = rd(cmd, M_CP_RESP, &st);
	cpmsg = rd(cmd, M_CP_MSG, &st);
	txv(cmd, 42u, "CR=", cpres, "CM=", cpmsg);

	/* R110: the HFI queue table's header, the CM3's own registers and
	 * the sequencer's state all move down to rows 52 and up, because
	 * rows 44 to 51 now carry the firmware's log, which is worth more
	 * than the queue table's first two words (R108 and R109 both read
	 * them back exactly as AdrenoHfiInitializeStopped writes them:
	 * shared[0] = 0, shared[1] = 0xa8). --- */
	mcfg = rd(cmd, M_CM3_CFG, &st);
	icf2 = rd(cmd, M_ICACHE_CFG, &st);
	txv(cmd, 54u, "C=", mcfg, "I=", icf2);
	gxr = rd(cmd, 0x03D7E340u, &st);         /* dword 0x50d0, GX power */
	txv(cmd, 58u, "X=", gxr, "W=", iinf);

	/* R109: the boot registers, read again now that the cold start is
	 * over.  Phase 5 wrote them and read them back and all twelve
	 * matched, so whatever is different now was changed by the firmware
	 * or by the hardware after the release.  Two of them are already
	 * known to differ: CM3_CFG came back as 0x4012 where phase 5 wrote
	 * 0x4052 (bit 6 gone), and ICACHE_CONFIG came back as 0 where phase
	 * 5 wrote 1. --- */
	mark(cmd, 21u);

	/* --- the fault registers, after the run. --- */
	ao = rd(cmd, M_AO_STATUS, &st);
	icfg = rd(cmd, M_ICACHE_CFG, &st);
	txv(cmd, 38u, "H=", hfi, "R=", rsc);
	txv(cmd, 39u, "O=", ao, "G=", gfsr2);
	txv(cmd, 40u, "I=", icfg, "K=", vmask);
	mark(cmd, 19u);

	/* --- and last, because the CM3 may have overwritten them: the version
	 * word and the vector table once more. --- */
	(void)rdm(cmd, M_DTCM + 0x3FE8u, 1u, bk);
	ver2 = bk[0];
	txv(cmd, 41u, "V0=", ver2, "T0=", it0);
	mark(cmd, 20u);

	/* --- R115: the AOP command database, the last thing this round does.
	 *
	 * The database is in ordinary memory at 0x80860000, 0x20000 bytes,
	 * with the magic 0x0c0330db in its second word.  It holds the gfx,
	 * mx and cx rail lists the performance table's votes come out of
	 * and the BCM addresses the bandwidth table names, so if it can be
	 * read out of memory the hard coded votes above can be replaced by
	 * the real thing.
	 *
	 * This read is deliberately the last thing the probe does: op 7
	 * maps the address as a device window, and a window over ordinary
	 * memory on a kernel that never mapped it that way may fault.
	 * Everything this round has to say is on the screen by the time
	 * this runs. --- */
	{
		u32 cm[4];
		u32 cst;

		cm[0] = 0u;
		cm[1] = 0u;
		cm[2] = 0u;
		cm[3] = 0u;
		cst = rdm(cmd, CMDB_BASE, 2u, cm);
		txv(cmd, 50u, "DB=", cm[1], "DS=", cst);
	}

	/* --- R117: the command database's real contents.
	 *
	 * R116 proved the database is there: the magic reads back as
	 * 0x0c0330db from 0x80860000.  The question now is what is in it,
	 * because the performance table's votes come out of the gfx, mx and
	 * cx rail lists and the bandwidth table's BCM addresses come out of
	 * the same place.  R115 used the tables from the alioth test file
	 * ("the real pipa command DB's level lists"); those are the SoC's
	 * tables and the firmware accepted them, but the device's own copy
	 * is the authority.
	 *
	 * The three rail lists are read and printed word by word, so they can
	 * be compared against the ones the votes were computed from:
	 *
	 *   gfx.lvl  0 48 64 128 144 192 224 256 320 384 416
	 *   mx.lvl   0 16 128 192 224 256 320 384 416
	 *   cx.lvl   0 16 64 128 192 256 320 384 416
	 *
	 * The BCM entries are read too: MC0, SH0, ACV and CN0, whose
	 * addresses the bandwidth table names.
	 *
	 * This is the last thing the probe does: op 7 maps the address as a
	 * device window, and a window over ordinary memory on a kernel that
	 * never mapped it that way may fault.  Everything this round has to
	 * say is on the screen by the time this runs. --- */
	{
		u32 lvl[32];
		u32 words[8];
		u32 len = 0u;
		u32 addr = 0u;
		u32 slave = 0u;
		u32 aux = 0u;
		u32 rc;
		u32 i;
		u32 sh0 = 0xffffffffu, mc0 = 0xffffffffu;
		u32 acv = 0xffffffffu, cn0 = 0xffffffffu;

		/* --- the eight slave records.  A console row holds sixty
		 * characters and a word is nine, so a row holds six words:
		 * the first six slaves here, the last two and the first
		 * slaves' offsets below.  A word is {slv_id, header_offset}
		 * and then {data_offset, count}. --- */
		{
			u32 h[36];
			u32 w2[8];

			if (cmdb_rd(cmd, 0u, 36u, h) == 0u) {
				for (i = 0u; i < 8u; i++) {
					words[i] = h[2u + i * 4u];
					w2[i] = h[3u + i * 4u];
				}
				txw(cmd, 57u, words, 6u);
				words[0] = w2[6];
				words[1] = w2[7];
				for (i = 0u; i < 4u; i++) {
					words[2u + i] = h[3u + i * 4u];
				}
				txw(cmd, 58u, words, 6u);
			} else {
				txv(cmd, 57u, "H=", 0xffffffffu, "E=", 0xffffffffu);
			}
		}

		/* --- the three level lists.  Each is a run of 16-bit words,
		 * two to a printed word, little endian: the low half is the
		 * first level. --- */
		rc = cmdb_find(cmd, "gfx.lvl", &aux, &len, &addr, &slave);
		txv(cmd, 52u, "GF=", rc, "N=", len / 2u);
		if (rc == 0u) {
			u32 nlv = len / 2u;

			txv(cmd, 44u, "AG=", addr, "SL=", slave);
			if (nlv > 12u) {
				nlv = 12u;
			}
			if (cmdb_rd16(cmd, aux, nlv, lvl) == 0u) {
				for (i = 0u; i < 6u; i++) {
					u32 a = (i * 2u) < nlv ? lvl[i * 2u] : 0u;
					u32 b = (i * 2u + 1u) < nlv ? lvl[i * 2u + 1u] : 0u;

					words[i] = a | (b << 16);
				}
				txw(cmd, 47u, words, 6u);
			}
		}
		rc = cmdb_find(cmd, "mx.lvl", &aux, &len, &addr, &slave);
		txv(cmd, 53u, "MX=", rc, "N=", len / 2u);
		if (rc == 0u) {
			u32 nlv = len / 2u;

			if (nlv > 10u) {
				nlv = 10u;
			}
			if (cmdb_rd16(cmd, aux, nlv, lvl) == 0u) {
				for (i = 0u; i < 5u; i++) {
					u32 a = (i * 2u) < nlv ? lvl[i * 2u] : 0u;
					u32 b = (i * 2u + 1u) < nlv ? lvl[i * 2u + 1u] : 0u;

					words[i] = a | (b << 16);
				}
				txw(cmd, 48u, words, 5u);
			}
		}
		rc = cmdb_find(cmd, "cx.lvl", &aux, &len, &addr, &slave);
		txv(cmd, 54u, "CX=", rc, "N=", len / 2u);
		if (rc == 0u) {
			u32 nlv = len / 2u;

			if (nlv > 10u) {
				nlv = 10u;
			}
			if (cmdb_rd16(cmd, aux, nlv, lvl) == 0u) {
				for (i = 0u; i < 5u; i++) {
					u32 a = (i * 2u) < nlv ? lvl[i * 2u] : 0u;
					u32 b = (i * 2u + 1u) < nlv ? lvl[i * 2u + 1u] : 0u;

					words[i] = a | (b << 16);
				}
				txw(cmd, 51u, words, 5u);
			}
		}

		/* --- the four BCM addresses.  The address is the entry's own
		 * address field, not its payload: the bandwidth table names
		 * the registers by it. --- */
		rc = cmdb_find(cmd, "SH0", &aux, &len, &addr, &slave);
		if (rc == 0u) {
			sh0 = addr;
		}
		rc = cmdb_find(cmd, "MC0", &aux, &len, &addr, &slave);
		if (rc == 0u) {
			mc0 = addr;
		}
		rc = cmdb_find(cmd, "ACV", &aux, &len, &addr, &slave);
		if (rc == 0u) {
			acv = addr;
		}
		rc = cmdb_find(cmd, "CN0", &aux, &len, &addr, &slave);
		if (rc == 0u) {
			cn0 = addr;
		}
		txv(cmd, 55u, "SH=", sh0, "MC=", mc0);
		txv(cmd, 56u, "AC=", acv, "CN=", cn0);

		/* --- the panel's own size, which is also the limit on the
		 * console rows: the last row that fits is
		 * (height - 36) / 42. --- */
		txv(cmd, 59u, "PX=", sw, "PY=", sh);
	}

	/* R107: the bar at the bottom of the panel moved down, because rows 44 to
	 * 49 now carry readings and the bar used to sit on top of them. */
	nio_fb_rect(cmd, 0xFFFFFFu, 0u, sh - 30u, sw, 30u);
	(void)nio_fb_send(cmd, 24u);

park:
	for (;;) {
		__asm__ volatile ("wfe");
	}
}
