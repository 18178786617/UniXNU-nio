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

### 1. LUN 4 选择器

`board.toml` 的 `[userdata]` 写的是 `lun = "sde"`，真机分区表确认
userdata 在 **LUN 4**（LBA 3178592 起，224.3 GiB）。UFSHCI 的
`UFSHCE` / `UP` 寄存器组里没有 LUN 号——LUN 是在 **UFS 配置描述符**里的
`bNumberLU` 之下，由设备自己报告。sheng 是单 LUN，nio 是 6 LUN。

⇒ 移植时要新增：**读设备描述符 → 找 target 的 LUN 4 → 让 UFS 配置描述符
指向它**。这是整个移植里**唯一需要新写**的硬件逻辑。

### 2. root image 的分区起点

sheng 的 persistent store 布局（`RootLayout.h`）假设 userdata 分区从 LBA 0
开始可用。nio 的 userdata 从 `first_lba = 0x308060` 起，SHNGROOT 镜像的
窗口偏移要减去这个起点。

### 3. 16.5 的 prelink 与 IOStorageFamily

ShengUfs 走的是 "public-source storage" 路径：运行时加载原版 IOStorageFamily
和 APFS（`RootPublication.h` / `RootCommands.h` / `RootDiagnostics.h`），
检查原版基类大小，认证 23F84 策略，注册 source 类。

⇒ 在 16.5 上，这套 **23F84 策略认证** 是 17.7.11 的东西，需要换成 16.5 的
策略版本（16.5 的 `kernelcache.release.iphone10b` 里 IOStorageFamily 的
版本号和策略表都要重取）。这是移植里第二块需要重做的部分。

## 移植工作分解

| 步骤 | 内容 | 难度 |
|---|---|---|
| U1 | 复制 ShengUfs 到 `device/UniXNU-nio/drivers/NioUfs`，改名为 `NativeUfs` → `NioUfs` | 低 |
| U2 | 删掉 DPU / 显示通路（`kDpuWindow` 及相关），保留纯 UFS 传输 | 低 |
| U3 | 加 LUN 4 选择器（读描述符、选 target） | **中** |
| U4 | 改 root image 布局起点（`first_lba = 0x308060`） | 低 |
| U5 | 换成 16.5 的 IOStorageFamily 策略版本 | **中** |
| U6 | 在 `components.toml` 注册 `NioUfs` 组件，`build-arm-driver.py` 入口 | 低 |
| U7 | `configs/nio_defconfig` 打开 `CONFIG_XNU_NATIVE_UFS=y` | 低 |
| U8 | 构建 7.7 GB 的 SHNGROOT userdata 镜像（`scripts/unixnu/userdata.py` 那一套） | 中 |

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
