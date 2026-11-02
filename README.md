# UniXNU-nio

MOTO Edge S（XT2125-4，SM8250 / kona）跑 XNU 的设备仓库，供
[UniXNU](https://github.com/UniXNU/UniXNU) 的构建流水线使用。

目标系统固定为 **iPadOS 17.7.11 / 21H461 / Darwin 23.6.0**，源码内核
`xnu-10063.141.1`，与同 SoC 的 umi 已验证版本一致。

## 编内核（不需要 Mac）

推到 GitHub，跑 **Actions → Build nio kernel**，下 `nio-kernel` artifact。
完整步骤与失败排查见 [docs/BUILD-GITHUB.md](docs/BUILD-GITHUB.md)。

构建用的版本全部钉死：

| 件 | 版本 |
|---|---|
| UniXNU | `04573c510c5fd4892ca6948739389141cc9e05f5` |
| xnu | `d8b80295118ef25ac3a784134bcf95cd8e88109f`（xnu-10063.141.1） |
| SM8250 公共层 | `a6e7e36caab58f5b9a5625dbdb8da2bf290fa5cc` |
| ArmCpu（SM8250 fork） | `a9c4585dbb1b75b8594dd0ae54962cc59969d98f` |

## 仓库里是什么

| 路径 | 内容 |
|---|---|
| `board.toml` | 板级参数、组件选择、补丁序列、IPSW 与 prelink donor |
| `configs/nio_defconfig` | 内核配置（第一版只求进内核、出 console） |
| `feeds.toml` | 所有上游源码的 commit 钉 |
| `patches/xnu/series` | 设备层补丁序列（当前为空，原因写在文件里） |
| `patches/xnu/device/` | 从 umi 继承的 18 个调试补丁，存档未启用 |
| `patches/xnu-prelink/series` | XnuPrelink 的两个必需补丁 |
| `scripts/nio_adt.py` | ADT 编码器 |
| `docs/STATUS.md` | 每一轮的判决、踩过的坑、还缺的实测值 |
| `docs/BUILD-GITHUB.md` | GitHub 构建步骤 |

## 当前进度

- UEFI 固件（另一个仓库，`nioPkg`）已能出 GOP 菜单、读卷内 `unixnu.toml`、
  内置 DarwinBoot；助手键（TLMM GPIO14）已做成第一个 SimpleTextIn 设备。
- 内核尚未产出：本仓库的 GitHub 工作流就是为这一步准备的。
- 触摸（Novatek NT36672C / GENI SPI）、音量加（PM8150 GPIO6 / SPMI）、
  UFS LUN 4、显示都还没接。

## 声明

非官方项目，与 Apple、Motorola、Qualcomm 无关。仓库不含 Apple 的
IPSW、kernelcache、trust cache 或任何厂商固件；构建时从 Apple 的公开
CDN 按 `board.toml` 的哈希校验后读取。
