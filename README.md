# UniXNU-nio

MOTO Edge S（XT2125-4，SM8250-AC / kona，骁龙 870，Adreno 650）跑 Apple
XNU 的设备仓库，供 [UniXNU](https://github.com/UniXNU/UniXNU) 的构建流水线
使用。

> **目标系统是 iOS 16.5（build 20F66），不是 iPadOS。**
> ADT 伪造的是 **iPhone X（`iPhone10,3` / D22AP）** 的身份，用户态取自
> iPhone X 的 16.5 Restore IPSW，内核是 XNU **8796.101.5**（Darwin 22.5.0）。
> 这台机器本身是 Android 手机，UnixNU 走 UEFI 把 Apple 的系统跑在非 Apple
> 硬件上。

| | |
|---|---|
| 板子 | MOTO Edge S（XT2125-4） |
| SoC | Qualcomm SM8250-AC "kona"，Adreno 650 |
| 目标 OS | **iOS 16.5 / 20F66**，Darwin 22.5.0，XNU 8796.101.5 |
| 伪造身份 | iPhone X（`iPhone10,3` / D22AP） |
| 显示 | 1080×2520，pitch 4320，framebuffer 在 0x9c000000 |
| 存储 | UFS，6 个 LUN，userdata 在 LUN 4（sde） |
| 触摸 | Novatek NT36672C，SPI（bit-bang），RST GPIO50 / IRQ GPIO24 |
| 键 | Vol+ 在 gpio-keys，Vol-/Power 在 PMIC PON |

## 目标为什么是 iOS 16.5

iOS 16.5 的用户态和 IPSW 已经在本机准备好：`E:\nio-unixnu-port\ios165\`
（`20F66.ipsw`、解出来的完整用户态 root、16.5 的 kernelcache / DeviceTree /
trust cache）。这份用户态是 **未修改的 iPhone X 16.5 用户态**，必须搭配
**xnu-8796** 一类的 16.x 内核使用，与 17.x 内核（xnu-100xx）不匹配。

同族参考：[`UniXNU-NX769J`](https://github.com/UniXNU-NX769J)（红魔 9）已经把
同一件事做完了——自带 `ios-16.5-20F66` OS profile、把它装进 UniXNU 检出、
把共享补丁系列重基到 xnu-8796.101.5。nio 走同一条路。

## 现在仓库里的内核是哪一个（重要）

**树里的内核目前仍是 17.7.11 / xnu-10063.141.1 那一版**，因为它是已经跑通到
console 的 bring-up 基线：donor、prelink 符号绑定、补丁系列都在这一版上验证
过。切换到 16.5 会换掉：

| 项 | 现在（17.7.11） | 目标（16.5） |
|---|---|---|
| OS profile | `ipados-17.7.11-21H461`（UniXNU 主仓自带） | `ios-16.5-20F66`（**设备仓自带**，构建时装进 UniXNU 检出） |
| 源码内核 | `xnu-10063.141.1` | `xnu-8796.101.5` |
| donor kernelcache | iPad7,1 的 `f18b4df8…` | iPhone10,3 的 `e6fa7559…` |
| 补丁系列 | arch(56)+soc(2)+prelink(2)+设备层 | 需要重基到 8796（NX769J 有一份可复用） |
| ADT 身份 | iPad7,1 / j120ap | iPhone10,3 / D22AP |

**板级代码不受影响**：GPU 驱动归档、探针、A650 冷启动、ADT 编码、UEFI 固件
都是板级的，只有"内核侧的钩子"和"补丁系列"要跟着换内核重做一遍。

## 编内核（不需要 Mac）

推到 GitHub，跑 **Actions → Build nio kernel**，下 `nio-kernel` artifact。
`main` 上的内核相关改动也会自动触发（路径过滤见工作流里的说明）。
完整步骤与失败排查见 [docs/BUILD-GITHUB.md](docs/BUILD-GITHUB.md)。

构建用的版本全部钉死：

| 件 | 版本 |
|---|---|
| UniXNU | `04573c510c5fd4892ca6948739389141cc9e05f5` |
| xnu（当前 bring-up 基线） | `d8b80295118ef25ac3a784134bcf95cd8e88109f`（xnu-10063.141.1） |
| SM8250 公共层 | `a6e7e36caab58f5b9a5625dbdb8da2bf290fa5cc` |
| ArmCpu（SM8250 fork） | `a9c4585dbb1b75b8594dd0ae54962cc59969d98f` |
| GPU 驱动（Adreno650 fork） | `70771a71795d7e1a78afdb82badd7943adb0a3a0`（子模块 `package/adreno650`） |

## 仓库里是什么

| 路径 | 内容 |
|---|---|
| `board.toml` | 板级参数、组件选择、补丁序列、IPSW 与 prelink donor |
| `configs/nio_defconfig` | 内核配置 |
| `feeds.toml` | 所有上游源码的 commit 钉 |
| `package/` | 板级代码：GPU 探针、A650 冷启动、固件数组、ADT 编码 |
| `package/adreno650/` | GPU 驱动子模块（Adreno650 fork） |
| `patches/xnu/series` | 设备层补丁序列（当前为空，原因写在文件里） |
| `patches/xnu/device/` | 从 umi 继承的 18 个调试补丁，存档未启用 |
| `patches/xnu/gpu/` | GPU 探针的内核启动钩子（device 层补丁） |
| `patches/xnu-prelink/series` | XnuPrelink 的两个必需补丁 |
| `scripts/build-adreno650.py` | GPU 归档 `build/adreno740/libAdreno740.a` 的构建脚本 |
| `scripts/nio_adt.py` | ADT 编码器 |
| `docs/STATUS.md` | 每一轮的判决、踩过的坑、还缺的实测值 |
| `docs/BUILD-GITHUB.md` | GitHub 构建步骤 |

## 当前进度

- **UEFI 固件**（另一个仓库，`nioPkg`）已能出 GOP 菜单、读卷内 `unixnu.toml`、
  内置 DarwinBoot；助手键（TLMM GPIO14）已做成第一个 SimpleTextIn 设备。
- **GPU（UEFI 侧，R100–R117）已通**：GMU 的 SMMU context（bank 1 / ASID 1）、
  A650 冷启动、HFI 表、GMU 的时钟与 GPIO 投票、GX 上电，AOP 命令库里的
  gfx/mx/cx 三级 rail 表和 SH0/MC0/ACV/CN0 四个 BCM 地址与参考板逐项吻合。
  实测：GX 域与 GX 时钟已上电（`P0=000000c0 → P1=00000000`），
  `GD=f8222800`、`RB=00000001`、`OI=80000001`、`DB=0c0330db`。
- **GPU（内核侧，R118）**：同一个探针搬进 XNU 内核。驱动归档
  `libAdreno740.a`（15 个驱动文件 + 三个 kit + 板级探针 + A650 冷启动）、
  内核启动钩子补丁、`nio-gpu=8` 启动参数。第一次内核侧读数正在 CI 里跑。
- **触摸**：Novatek NT36672C 的 SPI 读通了（R77 用 bit-bang 换掉 GENI 引擎，
  两次读到同一签名 `0c 00 00 72 66 03`），但还没接成 HID 设备。
- **显示、存储（UFS LUN 4 选择器）**：还没接。

## 声明

非官方项目，与 Apple、Motorola、Qualcomm 无关。仓库不含 Apple 的
IPSW、kernelcache、trust cache 或任何厂商固件；构建时从 Apple 的公开
CDN 按 `board.toml` 的哈希校验后读取。
