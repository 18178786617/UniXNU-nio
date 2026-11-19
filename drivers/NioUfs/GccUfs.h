// SPDX-License-Identifier: BSD-2-Clause-Patent
// SM8250 (kona) GCC registers used by UFS, transcribed as facts from the
// public Linux gcc-sm8250.c clock driver. No write is performed by NioUfs yet.
//
// The offsets are kona's own, not sheng's. The two generations disagree:
// SM8550 places the UFS PHY clock branches further apart, SM8250 packs them
// closer, so a sheng address read on this board lands on the wrong register.
// Every value below was read out of refs/linux/gcc-sm8250.c.
#ifndef NIO_UFS_GCC_UFS_H
#define NIO_UFS_GCC_UFS_H

// The board's round number: this driver's own count of the revisions that
// changed it.  The driver prints it when it starts, so a screen says which
// revision produced it.
//
// The build numbers its rounds on GitHub's run counter, and that counter
// counts every workflow on the repository, not only the ones that changed
// this driver.  Two rounds once carried the same code under two different
// numbers, and the two were told apart by the shape of their probe lines
// rather than by anything on the screen that said so.  The number here
// belongs to the driver, so it moves only when the driver does.
#define NIO_UFS_ROUND                  522

// Physical windows from the kona device tree
// (clock-controller@100000, ufshc@1d84000). The UFS host controller and the
// GCC sit at the same addresses they do on SM8550 -- only the register
// layout inside the GCC differs.
#define GCC_BASE                      0x00100000ULL
#define UFS_HC_BASE                   0x01d84000ULL
#define UFS_HC_SIZE                   0x3000ULL

// The vendor-specific window of the host controller.
//
// The EDK2 driver that runs on this board family puts it at the base of
// the controller plus 0x1100 (Samsung's own package writes
// EXYNOS9810_UFS_VS_BASE = EXYNOS9810_UFS_BASE + 0x1100), and its
// register offsets inside it run from 0x000 to 0x108 -- which is why
// they cannot be inside the controller's own 0x000..0x100 window.
//
// The window is inside the 0x3000 bytes this driver maps, so the
// offsets below are offsets into the mapping.
//
// Two of them matter to a command:
//
//   VS_UTRL_NEXUS_TYPE   what the controller is told the descriptors in
//                        the request list are.  EDK2 writes 0xffffffff
//                        before it sends a command and 0 before it sends
//                        a NOP OUT or a query -- the two are not the same
//                        thing to the controller, and this port never
//                        wrote it at all.
//
//   VS_CLKSTOP_CTRL      bit 4 stops the controller's clock.  EDK2 clears
//                        that bit while it brings the controller up.
#define UFS_HC_VS_BASE                 (UFS_HC_BASE + 0x1100ULL)
#define UFS_HC_VS_IS                   (UFS_HC_VS_BASE + 0x038)
#define UFS_HC_VS_UTRL_NEXUS_TYPE      (UFS_HC_VS_BASE + 0x040)
#define UFS_HC_VS_UMTRL_NEXUS_TYPE     (UFS_HC_VS_BASE + 0x044)
#define UFS_HC_VS_SW_RST               (UFS_HC_VS_BASE + 0x050)
#define UFS_HC_VS_CLKSTOP_CTRL         (UFS_HC_VS_BASE + 0x0b0)
#define UFS_HC_VS_FORCE_HCS            (UFS_HC_VS_BASE + 0x0b4)

// The LUN that carries nio's userdata partition.
//
// sheng is single-LUN and used LUN 0 for everything. nio has six LUNs and
// the userdata partition lives on LUN 4 (the "sde" LUN: the device's
// partition table puts userdata at LBA 3178592 of LUN 4, 224.3 GiB).
//
// The UFS Command UPIU carries the LUN in byte 2, so the transport already
// speaks to any LUN the device has; what has to be right is which one the
// root image and the persistent windows live on. native_ufs_part_find()
// scans LUN 0..5 for the "EFI PART" signature and returns the number it
// found, and the boot-time check below refuses to continue if that number
// is not the one named here.
#define NIO_UFS_USERDATA_LUN           4U

#define GCC_UFS_PHY_GDSCR             0x77004
#define GCC_UFS_MEM_PHY_GDSCR         0x9e000

// kona: gcc_ufs_phy_axi_clk.enable_reg
#define GCC_UFS_PHY_AXI_ENABLE        0x77010
// kona: gcc_ufs_phy_ahb_clk.enable_reg
#define GCC_UFS_PHY_AHB_ENABLE        0x77018
// kona: gcc_ufs_phy_tx_symbol_0_clk.enable_reg
#define GCC_UFS_PHY_TX_SYMBOL0_ENABLE 0x7701c
// kona: gcc_ufs_phy_rx_symbol_0_clk.enable_reg
#define GCC_UFS_PHY_RX_SYMBOL0_ENABLE 0x77020
// kona: gcc_ufs_phy_unipro_core_clk.enable_reg
#define GCC_UFS_PHY_UNIPRO_CORE_ENABLE 0x7705c
// kona: gcc_ufs_phy_ice_core_clk.enable_reg
#define GCC_UFS_PHY_ICE_CORE_ENABLE   0x77064
// kona: gcc_ufs_phy_phy_aux_clk.enable_reg
#define GCC_UFS_PHY_PHY_AUX_ENABLE    0x7709c
// kona: gcc_ufs_phy_rx_symbol_1_clk.enable_reg
#define GCC_UFS_PHY_RX_SYMBOL1_ENABLE 0x770b8
// bus_aggr_clk in the board DT: gcc_aggre_ufs_phy_axi_clk, halt/enable
// 0x770cc, HW clock gating bit1
#define GCC_AGGRE_UFS_PHY_AXI_ENABLE  0x770cc

#define GCC_UFS_BRANCH_ENABLE_BIT     0x1U

// gcc_ufs_phy_ahb_clk and gcc_aggre_ufs_phy_axi_clk set hwcg_bit=1 in
// gcc-sm8250.c, so CLK_OFF=1 on an idle branch is normal.
// The reset and RPMh/TCSR/QMP-PHY programming are not represented here: their
// semantics are not qualified and NioUfs must not write them speculatively.
#endif
