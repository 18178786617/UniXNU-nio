# nio 的 UFS 驱动方案（kona / SM8250）

**判决：ShengUfs 可以移植到 nio，硬件前提全部成立。**
板级差异只有三处，而且其中两处的地址与 sheng 完全相同。

## 为什么这件事是上机的必要条件

iOS 16.5 的用户态有 7.7 GB，装不进 mockfs（`bsd/miscfs/mockfs/mockfs_vfsops.c:146`
硬编码 `bytes > 32 * 1024 * 1024` 就拒绝）。所以 16.5 用户态必须落到 UFS 的
userdata 分区上，也就是官方 SHNGROOT 路径（umi 走的就是这条）。

当前 `configs/nio_defconfig` 里 `CONFIG_XNU_NATIVE_UFS=n`：UFS 驱动是关的，
所以 16.5 用户态**没有落地路径**。这是"手机进 iOS 16.5 用户态"的唯一硬缺口。

## 硬件事实：kona 和 sheng 的三个关键地址

来源：`refs/linux/sm8250.dtsi`（LineageOS 的 kona 设备树）和
`refs/ShengUfs/`（sheng 的驱动源码）。

| 资源 | sheng (SM8550) | kona (SM8250) | 差异 |
|---|---|---|---|
| UFS host 控制器 | `0x1d84000`，长 `0x3000` | `0x01d84000`，长 `0x3000` | **完全相同** |
| GCC（时钟/复位/电源域） | `0x100000` | `0x00100000`，长 `0x1f0000` | **完全相同** |
| apps_smmu | `0x15000000`，长 `0xd0000` | `0x15000000`，长 `0x100000` | 基址同，窗口更大 |

UFS 控制器的地址一致不是巧合：Qualcomm 把 UFS host 放在 `0x1d8xxxx` 是跨
SoC 代的固定布局，sm8550 和 sm8250 都是 `ufs_mem_hc@1d84000`，寄存器偏移
按 UFSHCI 标准走。**所以驱动的寄存器层完全不用改。**

SMMU 那一项：ShengUfs 映射 `0x15000000` 长度 `0xd0000`（SMMU 全局寄存器 +
context banks）。kona 的窗口是 `0x100000`，比 `0xd0000` 还大，**映射长度
不用改**，反而是 sheng 更紧。

### kona 的设备树原文

```
ufs_mem_hc: ufshc@1d84000 {
    compatible = "qcom,sm8250-ufshc", "qcom,ufshc", "jedec,ufs-2.0";
    reg = <0 0x01d84000 0 0x3000>;
    interrupts = <GIC_SPI 265 IRQ_TYPE_LEVEL_HIGH>;
    phys = <&ufs_mem_phy>;
    lanes-per-direction = <2>;
    resets = <&gcc GCC_UFS_PHY_BCR>;
    power-domains = <&gcc UFS_PHY_GDSC>;
    iommus = <&apps_smmu 0x0e0 0>, <&apps_smmu 0x4e0 0>;
    clocks = <&gcc GCC_UFS_PHY_AXI_CLK>, <&gcc GCC_AGGRE_UFS_PHY_AXI_CLK>,
              <&gcc GCC_UFS_PHY_AHB_CLK>, <&gcc GCC_UFS_PHY_UNIPRO_CORE_CLK>,
              <&rpmhcc RPMH_CXO_CLK>, <&gcc GCC_UFS_PHY_TX_SYMBOL_0_CLK>,
              <&gcc GCC_UFS_PHY_RX_SYMBOL_0_CLK>, <&gcc GCC_UFS_PHY_RX_SYMBOL_1_CLK>;
};

gcc: clock-controller@100000 { reg = <0x0 0x00100000 0x0 0x1f0000>; };
apps_smmu: iommu@15000000 { reg = <0 0x15000000 0 0x100000>; };
```

## ShengUfs 的分层

`refs/ShengUfs/` 共 3395 行，三层：

| 层 | 文件 | 可移植性 |
|---|---|---|
| UFSHCI 寄存器 / 命令 / 队列 | `NativeUfs.cpp` 主体 | **通用**，寄存器偏移是 UFSHCI 标准 |
| 板级：GCC / SMMU / DPU | `GccUfs.h` + `NativeUfs.cpp` 里的常量 | **要改**，但只有 3 个基址 |
| root-image 解析（GPT + manifest） | `RootLayout.h` / `RootPublication.h` / `RootCommands.h` | **通用**，与板无关 |

### 板级常量只有这些（`GccUfs.h` + 内联）

```c
#define GCC_BASE                      0x00100000ULL   // kona: 相同
// UFS host: 0x1d84000, len 0x3000      // kona: 相同
// apps_smmu: 0x15000000, len 0xd0000   // kona: 相同基址，窗口更大
```

其余硬编码里，`0x10000000`（DPU window）、`0xb8000000`/`0xb90f7500`（显示
framebuffer）是 **sheng 的显示通路**，nio 没有显示 personality，移植时整段
去掉。`0x9c900000` 是 DPU 扩展 IOVA 窗口，同上。

## nio 特有的三个额外要求

ShengUfs 是为 sheng 写的，它假设了三件 nio 不成立的事：

### 1. LUN 4 —— 驱动已经支持，不用新写

一开始以为要写 LUN 选择器，核过源码之后发现**已经有了**：

```c
// RootCommands.h:171  —— UFS Command UPIU 的 byte 2 就是 LUN 字段
ucd[2] = lun;

// RootCommands.h:241  —— 读接口直接带 LUN
static IOReturn hostRead4k (uint8_t lun, uint64_t lba, uint32_t blocks, void *dst)

// NativeUfs.cpp:1384 —— 分区扫描已经在遍历 6 个 LUN
extern "C" int native_ufs_part_find (const char *name, uint32_t *lun, uint64_t *first, uint64_t *blocks)
{
  for (uint32_t l = 0; l < 6 && !found; ++l) {
    if (hostRead4k (l, 1, 1, buffer) != kIOReturnSuccess || memcmp (buffer, "EFI PART", 8)) continue;
    ...
```

`native_ufs_part_find` 会**遍历 LUN 0..5**，找到带 "EFI PART" 签名的那个，
把 LUN 号和 LBA 一起返回。nio 的 userdata 在 LUN 4，
所以这条路径**直接就能找到它**。

⇒ nio 要做的只是**调用层**：把 `board.toml` 的 `[userdata]`（`lun = "sde"`、
`first_lba = 0x308060`）喂给 `native_ufs_part_find`，并把返回的 LUN 号
与 board.toml 声明的一致性**验一下**（不是 4 就要报错，不要静默跑偏）。

要注意的是：**store / log 两个写窗口目前硬编码在 LUN 0**
（`RootCommands.h:263` 注释："At most two windows of 4096-byte LBAs on LUN 0"，
`hostStoreOpen` / `hostLogOpen` 不带 lun 参数）。nio 的持久化区在 LUN 4，
所以这两处要加一个 LUN 参数 —— 这是**小改**，不是新功能。

### 2. root image 的分区起点

sheng 的 persistent store 布局（`RootLayout.h`）里，
`hostRead4k (0, 1, 1, ...)` 和 `hostRead4k (0, layout->userdataFirst, ...)`
都写死 LUN 0。nio 的 userdata 在 LUN 4 且从 `first_lba = 0x308060` 起，
这几处要跟着改。

### 3. 16.5 的 IOStorageFamily 策略版本（U6，唯一需要真新写的部分）

ShengUfs 走的是 "public-source storage" 路径：运行时加载**原版** IOStorageFamily
和 APFS，检查原版基类大小，认证 23F84 策略，注册 source 类。

16.5 上这套要换。从 16.5 的 donor（`out/donor16.5.bin`）里读出来的事实：

| 事实 | 值 | 出处 |
|---|---|---|
| SDK | `iphoneos16.5.internal` | IOStorageFamily 的 `DTSDKName` |
| bundle id | `com.apple.iokit.IOStorageFamily` | 同上 |
| 依赖方声明的版本 | `1.5` / `1.5.6` | `OSBundleLibraries` 里 `com.apple.iokit.IOStorageFamily` |
| 本体 `OSBundleRequired` | `Local-Root` | 同上 |
| `_PrelinkExecutableLoadAddr` | `0xfffffff004dd7280` | 同上 |
| `_PrelinkExecutableSize` | `0x1fc0` | 同上 |
| `_PrelinkKmodInfo` | `0xfffffff007a05000` | 同上 |

⇒ U6 要做的是：**按 16.5 的 IOStorageFamily 重新做一次"原版基类大小检查 +
策略认证"**，策略来源换成 16.5 的（不是 sheng 的 23F84）。这一项没法照抄，
必须对着 16.5 的 donor 量。

⇒ **在 U6 之前，NioUfs 是可以先编进去的**：驱动的完整性校验整段都在
`#if defined(NATIVE_VERIFIED_BLOCK) && NATIVE_VERIFIED_BLOCK` 里
（`NioUfs.cpp` 的 1590–1764 行），不带这个宏时走 `return true`，
也就是"读了但不校验"。对第一版上机（先证明 UFS 传输通、7.7 GB 能落盘）
来说这是可以接受的，**但要在日志里写明这条是未校验的**。

## 移植工作分解

| 步骤 | 内容 | 状态 |
|---|---|---|
| U1 | 复制 ShengUfs 到 `drivers/NioUfs`，类名 `NativeUfs`→`NioUfs` | ✅ R135 |
| U2 | 删掉 DPU / 显示通路（`dpuEnable` / `dpuClean` / `dpuTlbFlush` / `native_ufs_dpu_map` / `native_ufs_dpu_live`） | ✅ R135 |
| U3 | 引导参数改名 `sheng-*` → `nio-*`；`Info.plist` 改成 nio 身份 | ✅ R135 |
| U4 | **GCC 寄存器偏移改成 kona 的**（见下） | ✅ R135 |
| U5 | 写窗口与 GPT 解析的 LUN 从写死 0 改成 `NIO_UFS_USERDATA_LUN`（4） | ✅ R135 |
| U6 | 换成 16.5 的 IOStorageFamily 策略版本（23F84 → 16.5 的） | ⬜ 未做 |
| U7 | 在 `components.toml` 注册 `NioUfs` 组件，`build-arm-driver.py` 入口 | ⬜ 未做 |
| U8 | `configs/nio_defconfig` 打开 `CONFIG_XNU_NATIVE_UFS=y` | ⬜ 未做 |
| U9 | 构建 7.7 GB 的 SHNGROOT userdata 镜像（`scripts/unixnu/userdata.py` 那一套） | ⬜ 未做 |

### U4：GCC 寄存器偏移在两代之间不同（这是移植里最要命的一处）

**物理地址相同，寄存器布局不同。** SM8550 把 UFS PHY 的时钟分支摆得更开，
SM8250 挤得更紧，所以照抄 sheng 的偏移会读到**别的寄存器**：

| 寄存器 | sheng (SM8550) | kona (SM8250) | 差 |
|---|---|---|---|
| UFS PHY GDSC | `0x77004` | `0x77004` | — |
| PHY AXI | `0x77018` | `0x77010` | −8 |
| PHY AHB | `0x77024` | `0x77018` | −12 |
| PHY TX_SYMBOL0 | `0x77028` | `0x7701c` | −12 |
| PHY RX_SYMBOL0 | `0x7702c` | `0x77020` | −12 |
| PHY UNIPRO_CORE | `0x77068` | `0x7705c` | −12 |
| PHY ICE_CORE | `0x77074` | `0x77064` | −16 |
| PHY PHY_AUX | `0x770b0` | `0x7709c` | −20 |
| PHY RX_SYMBOL1 | `0x770cc` | `0x770b8` | −20 |
| AGGRE PHY AXI | `0x770e4` | `0x770cc` | −24 |

kona 的每一个值都是从 `refs/linux/gcc-sm8250.c` 的
`clk_branch.enable_reg` 读出来的（`gcc_ufs_phy_axi_clk`、`gcc_ufs_phy_ahb_clk`、
`gcc_aggre_ufs_phy_axi_clk` 等），GDSC 则来自 `ufs_phy_gdsc.gdscr`。
`GccUfs.h` 现在带的是 kona 的值，每个都注明了 kona 侧的来源。

### U5：LUN

驱动**本来就支持任意 LUN**（UFS Command UPIU 的 byte 2 就是 LUN 字段，
`native_ufs_part_find` 已经在扫 LUN 0..5）。要改的只有三处写死的 0：

- `RootLayout.h` 的 GPT 解析 —— 原来在 LUN 0 找 "userdata"，现在在
  `NIO_UFS_USERDATA_LUN`（4）找；
- `RootCommands.h` 的 `hostWrite4k` —— 原来 `lun != 0` 就拒绝；
- `hostScsiDir (0, ...)` 的写命令与 SYNCHRONIZE CACHE。

⇒ 改动比原估计小很多。**不需要新写 LUN 选择器。**

## 顺序上的取舍

用户态要 7.7 GB 落进 UFS，是 iOS 上机的必要条件；显示（338 槽 ABI 重写）
是进内核之后的下一件事。**两者都要 16.5 内核先编出来**（CI run #19 在跑
libpthread 归档的最后一个编译错误）。

所以真实顺序是：

```
16.5 内核编出来  ──→  U1..U7（UFS 驱动）──→  U8（7.7 GB 镜像）──→  刷 userdata
                                                          ↓
                                              显示（338 槽 ABI）──→ 有画面
```

## 参考

- `refs/ShengUfs/` — 上游驱动源码，revision `99d8bcd3`
- `refs/linux/sm8250.dtsi` — kona 设备树（LineageOS）
- `refs/UniXNU-umi/` — 官方跑通的同 SoC 移植，SHNGROOT → userdata 的刷写流程
- `device/UniXNU-nio/board.toml` 的 `[userdata]` 段 — LUN 与 LBA 契约
