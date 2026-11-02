# UniXNU-nio — 17.7.11 基线状态

**目标 OS 固定**：iPadOS `17.7.11` / build `21H461` / Darwin `23.6.0` /
源码内核 `xnu-10063.141.1`。这个选择不做讨论，它就是 umi 已验证的那一版
（Hello/Setup + 触摸 + UFS + 持久 Data）。改用其他版本等于把 umi 已经打通
的符号绑定、prelink donor 和补丁系列全部作废重来。

## 为什么这一版对 nio 有利

| 项 | 值 | 复用理由 |
|---|---|---|
| SoC | SM8250 / kona | nio 与 umi 是同一颗，GIC / 定时器 / PSCI / CPU 亲和性完全一致 |
| 源码内核 | xnu-10063.141.1 | `patches/nio-xnu/` 的 18 个补丁原样继承 |
| Prelink donor | kernelcache `f18b4df8…`，slide `-0x1000000` | 与 umi 同一份 donor，`early_security_init` 地址直接可用 |
| ABI | IOGPUFamily / IOHIDFamily-2031.120.4 / IOMobileGraphicsFamily | 用户态兼容层不需要重算 |

## 目录（2026-11-02 改成 schema_version 2）

```
board.toml                  nio 板级 + 组件选择 + 补丁序列（17.7.11 钉死）
configs/nio_defconfig       源码内核配置（第一版只求进内核/出 console）
feeds.toml                  XNU、SM8250 公共层、ArmCpu(SM8250 fork) 全部钉 commit
package/nio-hardware.json   唯一需要 nio 实测数值的输入
package/unixnu.toml         卷内菜单（\EFI\UniXNU\unixnu.toml）
package/Kit.toml            EFI 基线元数据（fdt_compatible = qcom,kona）
scripts/nio_adt.py          ADT 编码器（源自 umi_adt.py，路径/身份改为 nio）
scripts/make-nio-adt.py     ADT 生成入口（UniXNU payload ADT CLI）
patches/xnu/series          设备层补丁序列（当前为空，见文件内说明）
patches/xnu/device/         18 个 umi 调试补丁，仅存档，未启用
patches/xnu-prelink/series  两个 XnuPrelink 补丁（预链接必需）
.github/workflows/kernel.yml  GitHub macOS 构建（产物 kernel.macho）
docs/BUILD-GITHUB.md        上传/运行/取产物的完整步骤
```

为什么必须改 schema 2：共享流水线只在 `schema_version = 2` 时读
`[kernel] patch_series`（`scripts/unixnu/kernel.py:186`），格式 1 根本不打补丁。
格式 2 的层次是 arch → soc → os → device，四层各自带 profile.toml / series。

补丁来源：`reAAAq/UniXNU-umi` @ `3eb7257`（2026-10-23，第 80 轮，机主确认触摸可用）。
`patches/xnu/device/` 里保留 umi 文件名是刻意的——它们是从 umi 原样继承的，
改名会掩盖出处；nio 自己改的补丁将来单独加 `nio-` 前缀。

## 已通过的校验（2026-11-02 重做，schema 2）

`unixnu defconfig nio_defconfig` + `unixnu status` 在本机跑通：

```
device   device\UniXNU-nio (nio)
profile  arch   ...\profiles\arch\arm64
profile  soc    ...\out\feeds\UniXNU-sm8250-common-e8b46722
profile  os     ...\profiles\os\ipados-17.7.11-21H461
component ArmCpu / ArmDTPlatform / SoftwareAES / XnuPrelink
patch    01..60
```

`xnu` 钉在 `d8b8029`（xnu-10063.141.1 / Darwin 23.6.0），与 17.7.11 档案一致。
ADT 编码器冒烟测试通过：13064 字节、8 核 `0/0x100/…/0x700`、GIC
`0x17a00000` / `0x17a60000` / stride `0x20000`、往返解码一致。

### 60 个补丁在干净源码上全部应用成功

把 `d8b8029` 拉下来，按 `status` 给出的顺序逐个 `git apply`，结果
**applied=60 fail=0**：

| 层 | 数量 | 结果 |
|---|---|---|
| `profiles/arch/arm64/patches/xnu/series` | 56 | 全清洁 |
| `soc:patches/xnu/series`（native-smp-secondary / type-clusters） | 2 | 全清洁 |
| `patches/xnu-prelink/series`（XnuPrelink 两个） | 2 | 全清洁 |

**OS profile 的 `zzz-boot-progress.patch` 被刻意排除**：它改的是
`bsd_init.c` 里 `#if XNU_SHENG_PMGR` 那块的 `sheng_pmgr_run()`，而
`sheng_pmgr_run()` 来自 sheng 的 platform-power 补丁，nio 不编 sheng 硬件。
实测在本基线上 58 个补丁之后就失败在 `@@ -773`。排除它不影响本配置：
`CONFIG_XNU_BOOT_PROGRESS=n`，它插的调用全被编掉。

注意：本机验证树在 Windows 上被 CRLF 污染过，**只能用来看补丁是否应用，
不能拿去做真正的内核构建**。构建在 GitHub 的 macOS runner 上重新 `unixnu tree` 组装。

## R25 判决：UniXNU 菜单出来了，但吃的是内置配置

苹果 Logo + `UniXNU / version 0.1.0 / built-in configuration`，四条菜单项
（Return to firmware / Restart / Power off / Tools），倒计时 6s 走完选了第一项。

这一屏同时证明了三件此前没验证过的事：GOP 图形控制台可用、EnhancedFat
绑上了我们发布的卷、`\EFI\UniXNU\unixnu.toml` 被找到并打开。
但底部那行 `config error: unixnu.toml line 1: expected a key` 说明解析失败，
于是回落到内置配置 —— `built-in configuration` 这行字就是证据。

### 根因：`tools/mkfat.py` 不给子目录文件写内容

从卷里读回来的 toml 是 **272 字节全 `0x00`**。`build()` 里只有 `root.files`
调了 `put_cluster`，子目录（`EFI/UniXNU/`）的文件分配了簇、写了目录项，
**簇里一个字节都没写**。解析器读到 NUL，自然在第 1 行报 `expected a key`。

修复是加一个 `put_contents(node)` 递归，把所有层级的文件内容写进各自簇。
验证方法（每次改 mkfat 都要跑）：从 `PayloadVolumeBlob.c` 反解十六进制数组，
sha256 必须等于 `out/payload.fat`；再从卷里按 FAT 链读回文件、比 sha。

### 配置 schema（`Config.c` 实测，写错就 ConfigError）

- `type` 只认 `efi` / `linux` / `xnu` / `action`
- `action` 只认 `reset` / `shutdown` / `exit` / `tools`
- `path` 相对 `\EFI\UniXNU\`，所以内核要落在 `EFI/UniXNU/Payloads/kernel.macho`
- 顶层：`[boot] timeout/default/connect_all`、`[ui] title`、`[kits] autoload`

## DarwinBoot 已接进固件（R27）

`DarwinBoot` 在 `components.toml` 里是 `build_stage = firmware`，也就是标准
EDK2 模块，**在这台 Windows 机器上就能编**，不需要 macOS。实测 45 KB。

接线方式：`nio.dsc [Components]` + `nio.fdf INF DarwinBootPkg/Driver/DarwinBoot.inf`，
包根由 `build-nio.sh` 自动追加 `refs/UniXNU/drivers/DarwinBoot` 与
`refs/UniXNU/package`（后者提供 `UniXNUPkg.dec`，DarwinBoot.inf 依赖它）。

它的入口点只做一件事：`LocateProtocol` 查重 → `InstallMultipleProtocolInterfaces`
装上 `gUniXNULoaderProtocolGuid` → 返回。菜单里的 `type = "xnu"` 条目就是去
`LocateProtocol` 找它，然后把内核路径、boot args、设备树和 ramdisk 交过去。

**一个必须保留的补丁**：`patches/darwinboot/console-guard.patch`。
原代码在入口里直接 `Print()`，而 `Print()` 在 `gST->ConOut == NULL` 时会
`ASSERT`（本平台的 DebugLib 把它变成死循环）。DXE 调度期 ConOut 不保证就绪，
这正是 AcpiPlatform 那一轮的教训。改成先判空，无控制台时退回 `DEBUG()`。

DarwinBoot 的输入校验（`DarwinBoot.c` 的 `Boot`）有两条容易踩的：
`Request->DeviceTree` 必须为 **NULL**，且 `DarwinCurrentEl() == 4`（即 EL1）。
我们的固件就在 EL1，但菜单条目**不要**配 `dtb`，否则会直接
`unsupported inputs or exception level; firmware retained`。

## R28：第一个输入设备（2026-11-02）

R26 的菜单能画、能倒计时、能高亮，但**一个键都读不到**。原因不是配置：
固件里唯一那个 SimpleTextIn 是 `EmbeddedPkg/SimpleTextInOutSerial`（`DXE.inc`
第 20 行，挂在串口设备路径上的桩），它永远不会出字。真正的硬件一路都没有驱动
——没键盘、没触摸、没 PMIC 按键。UniXNU 底栏之所以显示「Up/Down: select」而不是
「No input device」，正是因为这个桩让它数到了 1 个输入设备。

BdsDxe 更早一步就把结论写在了屏幕上：`[Bds] Connect ConIn failed - Not Found!!!`
——它拿 `PcdConInDevicePath` 去连控制台输入，返回 `Not Found`。这一行是本轮把
截图放大到 1720 px 后逐字读出来的，不是猜的。

三路输入的现状与代价：

| 输入 | 硬件 | UEFI 侧代价 |
|---|---|---|
| 触摸 | Novatek NT36672C，**GENI SPI** 9.6 MHz，reset GPIO50 / irq GPIO24 | 要 SPI 控制器 + 触摸协议 + 上电时序，另开一轮 |
| 音量加 | **PM8150 GPIO6**（SPMI） | 要 PMIC arbiter + PMIC GPIO |
| 电源 | PM8150 PON | 同上 |
| **助手键** | **TLMM GPIO14**，低有效、上拉 | **纯 MMIO，已实现** |

`nioPkg/Driver/NioKey/NioKeyDxe.inf` 就是第四行：写 `0x0f90e000 = 0x83`，
10 ms 轮询 `0x0f90e004` bit0，短按发 `SCAN_DOWN`、按住 800 ms 发回车
（在阈值处就发，不等松手）。它安装 `SimpleTextIn` + VenHw 设备路径，
ConSplitter 通过协议通知把它并进 `gST->ConIn`，UniXNU 的菜单因此可操作。

地址推导与 tile/位域表见 `nio-config/DT-CONSTANTS.md` §9 —— 顺手纠正了一条旧结论：
**音量加不在 TLMM 上**，`gpios = <0xa7 0x6 0x1>` 里的 `0xa7` 是 `pm8150_gpios`。

镜像：`out/Mu-nio-0-raw.img` sha256 `70e6d246…` / gz `b1fc5baa…`。

## 还缺的实测值（只有两处）

1. **memory_banks** —— `package/nio-hardware.json` 里故意留空。
   umi 的三个 bank 是从它自己被 ABL 打过补丁的 DTB 里读的；nio 是 8 GiB、
   切分不同，照抄等于撒谎。填法：在 payload 的 `>= 64 MiB` Conventional
   区段输出里，把每条 `<物理地址>  <MiB>  Conventional` 记成
   `{"base": …, "size": …}`，按 base 升序。生成器在列表为空时会直接拒绝运行。
2. **dram_size** —— 必须等于上面各 bank 之和。`board.toml` 现在写的
   `0x200000000` 只是焊上去的容量，不是可用总量（umi 的 12 GiB 机型报的是
   `0x2f9900000`）。

## nio 独有、umi 没有的坑

| 子系统 | umi | nio | 影响 |
|---|---|---|---|
| 触摸 | ST FTS（I²C） | **Novatek NT36672C（SPI，GPIO50/24）** | 驱动必须新写，`package/touch` 一行都用不了 |
| 槽位 | 单槽 | **A/B，当前 _a** | boot_a / dtbo_a / vbmeta_a 处理不同 |
| LUN | 单 LUN | **6 LUN，userdata 在 LUN 4** | UFS 驱动要有 LUN 选择，否则 Data 无解 |
| 按键 | 两路 SPMI | **Vol+ 走 GPIO，Vol-/Power 走 PON** | UEFI 菜单输入与 XNU 按键驱动都要改 |
| 内存 | 12 GiB | **8 GiB** | owned-memory 窗口更紧，起点只能小步试 |

## 下一步顺序

1. ~~UEFI 侧读通 `\EFI\UniXNU\unixnu.toml`~~ —— R25 已出菜单（内置配置），
   R26 修掉 mkfat 写空，R27 起 DarwinBoot 也在卷里等着。
2. ~~菜单可操作~~ —— R28 加了 `NioKeyDxe`（助手键）。待上机判决：
   按一下高亮下移 / 按住 0.8 s 选中。
3. 输入的第二、三路，按性价比排：**音量加（PM8150 GPIO6）要写 SPMI PMIC
   arbiter**（kona 的 chnls 窗口在 `0xc600000`），先做只读的
   `pm8150_gpios 6` 就够两个键用；触摸（GENI SPI + Novatek NT36672C）最贵，
   放到 XNU 显示/UFS 之后。
4. 填 `memory_banks` → 跑 `make-nio-adt.py`，得到 `nio.adt` + 校验 JSON。
   取数路径：菜单选第 4 项（`action = "exit"`）回 NioBoot → 跳 payload →
   payload 打出 Conventional 区段。R28 之后这条路按键可达。
5. ~~内核必须在 macOS 上编~~ → 已改成 GitHub 构建：
   `docs/BUILD-GITHUB.md`。把本仓库推到 GitHub，跑 **Build nio kernel**，
   产物 `kernel.macho` 下载回 `out/`。不需要自己有 Mac。
6. 首次交接：`DarwinBoot` + 8 GiB 板子的 `owned_memory_size` 小步试。
   顺序是先让 kernel 打印第一行（`-v` 已带），再谈 UFS / 显示。
