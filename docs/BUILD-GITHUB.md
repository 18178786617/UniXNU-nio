# 编 nio 的内核：换一台电脑能不能跑

> **一句话**：**能。走 GitHub CI 的话，除了这台机器上的任何东西，一样都不需要。**
> 仓库里没有指向本机路径的构建配置（`E:\nio-unixnu-port\...` 只出现在注释和说明文字里），
> CI 会自己从 GitHub 把每一个依赖拉下来。

本文分三段：**CI 路线**（推荐，零本地依赖）、**本地路线**（要 clone 几个仓）、
**换机器时的检查清单**。

---

## 0. 现在这个仓库编的是哪个内核

| 项 | 值 |
|---|---|
| 目标系统 | iOS 16.5（build 20F66），Darwin 22.5.0 |
| XNU 源码 | `apple-oss-distributions/xnu` 的 tag `xnu-8796.101.5`，commit `aca3beaa3dfbd42498b42c5e5ce20a938e6554e5` |
| UniXNU 框架 | `UniXNU/UniXNU`，commit `04573c510c5fd4892ca6948739389141cc9e05f5` |
| 平台 | `UniXNU-sm8250-common` @ `a6e7e36caab58f5b9a5625dbdb8da2bf290fa5cc` |
| defconfig | `configs/nio_defconfig`（`nio_defconfig`） |
| 补丁 | `patches/xnu-8796/series`，168 条 |
| donor | 仓库内的 `donor/kernelcache.decompressed.gz`（16.5 的 kernelcache 切片），sha256 `e6fa7559…` |
| runner | `macos-15-intel`（x86_64，交叉编译出 arm64 内核） |

> ⚠️ 早期版本这份文档写的是 17.7.11 / `xnu-10063.141.1` / 18 个补丁，那已经过时了。
> 16.5 的切换记录见 `board.toml` 开头的注释。

---

## 1. CI 路线（推荐；换电脑只需要这三样）

### 1.1 需要准备的

| 项目 | 要求 |
|---|---|
| 账号 | 你的 GitHub 账号即可，不用付费 |
| 仓库 | 新建一个**空**仓库（不要勾 README / .gitignore） |
| 可见性 | **公开**最省事：macOS runner 不计费；私有仓库按 10 倍扣 macOS 分钟数 |
| Secrets | **一个都不需要** |
| 分支 | `main` |

### 1.2 把仓库推上去

```bash
git clone <你的账号>/UniXNU-nio.git        # 空仓库
cd UniXNU-nio
# 把本仓库 device/UniXNU-nio/ 下的内容复制到这里（board.toml、configs/、patches/、
# drivers/、dts/、donor/、os-profiles/、scripts/、package/、rootfs/、tools/、
# progress/、docs/、.github/、feeds.toml、.gitattributes、.gitmodules）
git add -A && git commit -m "nio device repository"
git push -u origin main
```

用网页上传也行：仓库首页 **Add file → Upload files**，把上面那些文件和文件夹整体拖进去。
**注意 `.github` 是隐藏目录**，文件管理器里要打开"显示隐藏文件"，否则工作流不会上传。

> **关键检查**：仓库根目录必须能直接看到 `board.toml` 和 `.github/workflows/kernel.yml`。
> 如果变成了 `UniXNU-nio/UniXNU-nio/board.toml`，工作流会报
> `the device repository has no board.toml`。

### 1.3 跑

Actions → **Build nio kernel** → **Run workflow**，参数保持默认：

| 参数 | 默认值 | 说明 |
|---|---|---|
| `unixnu_ref` | `04573c510c5fd4892ca6948739389141cc9e05f5` | 固定的 UniXNU 版本，**不要改成 `main`** |
| `defconfig` | `nio_defconfig` | `configs/` 里的名字 |
| `runner` | `macos-15-intel` | x86_64 的 macOS 15。这是 GitHub 现在唯一的 Intel macOS 标签（4 vCPU / 14 GB，公开仓库免费，2027 年 8 月下线）。`macos-15` / `macos-26` 是 arm64，两者不能混 |
| `xcode` | `auto` | 取镜像里最新的 `/Applications/Xcode*.app`。Intel 镜像上同时有 Xcode 16.x 和 26.x，`auto` 这次选中 26.3 |
| `ipsw_url` | 空 | 空 = 用仓库里的 `donor/kernelcache.decompressed.gz`。**不需要 IPSW** |
| `kernelcache_url` | 空 | 同上 |

等 25–90 分钟（第一次要下 XNU 源码）。

### 1.4 拿结果

成功后，页面底部 **Artifacts**：

| 包 | 内容 |
|---|---|
| `nio-kernel` | `kernel.macho` + `kernel.macho.json`（预链接记录） |
| `nio-kernel-logs` | `status.txt`、`kernel.log`、`kernel-bootstrap.log`、`archive-*.log` |

内核也可以直接从分支拿：`ci-kernel/run-<轮次>`（每次成功都会推一条）和 `ci-kernel/latest`。
`git fetch origin ci-kernel/latest` 就能拿到 `kernel.macho`，不需要 artifact 的下载界面。

### 1.5 CI 自己会做的事（所以本地什么都不用备）

- checkout UniXNU 框架仓（固定 commit）
- checkout 本 device 仓
- `unixnu fetch`：按 `feeds.toml` 从 GitHub clone XNU 源码、平台 feed、
  `ArmCpu` 驱动、corecrypto、libpthread，并更新 `package/adreno650` 子模块
- 从 `feeds.toml` 与 `os-profiles/ios-16.5-20F66/profile.toml` 解析出 16.5 的源码树
- 打 `patches/xnu-8796/series` 的 168 条补丁
- 用仓库里的 donor kernelcache 做预链接
- 编出 `kernel.macho`

---

## 2. 本地路线（要 clone 几个仓）

本地跑**也可以**不依赖这台机器的现成目录，代价是要多 clone 两个仓：

```bash
# 1) UniXNU 框架仓（CI 用的是同一个 commit）
git clone https://github.com/UniXNU/UniXNU.git
cd UniXNU && git checkout 04573c510c5fd4892ca6948739389141cc9e05f5

# 2) 本 device 仓
git clone <你的账号>/UniXNU-nio.git
# 把 device/UniXNU-nio/ 的内容放进 UniXNU/device/

# 3) 子模块（否则 package/adreno650 是空的，补丁会 apply 失败）
cd device && git submodule update --init --recursive
```

之后 `device/tools/ci-prepare.sh` 就是 CI 用的同一套准备脚本，可以在工作站上跑。

本地还需要：Python 3、一个 C/C++ 工具链（zig 的 clang 或 Xcode）、`fastboot`/`adb`
（只有上机那一步需要）、一台 Android 手机。

> 本地跑内核不省时间：CI 一轮 25 分钟，本地要自己解决 XNU 源码的下载、
> 预链接、镜像打包。**本地只值得用来做静态检查**（例如
> `tools/check-patch-scope.py`、`tools/check-patch-hunks.py`、
> `scripts/check-series.py`），编译还是交给 CI。

---

## 3. 换机器时的检查清单

| 问 | 怎么查 | 结论 |
|---|---|---|
| 仓库里有没有指向本机路径的配置？ | `grep -rIn -E "[Ee]:\\\\" board.toml configs scripts tools dts` | 只有注释与文档里有，**构建不读** |
| 有没有 secret 才能跑？ | workflow 里搜 `secrets.` | kernel 这一步**零 secret** |
| 外部依赖从哪来？ | `feeds.toml` | 全是 `git = "https://github.com/..."` + 固定 commit，CI 自己 clone |
| 大文件在哪？ | `donor/`（18.5 MB）、`package/adreno650`（子模块） | 都在 GitHub 上，CI 自己取 |
| 子模块会空吗？ | `.gitmodules` 只有一个 `package/adreno650` | `actions/checkout` 不会填它，但 `unixnu fetch` 会（`update_submodules()`） |
| `.gitignore` 会不会漏掉必需文件？ | `.gitignore` 只排除 `out/`、`build/`、`*.log` 等产物 | **不会**，321 个跟踪文件都在仓库里 |
| 补丁基线对不对？ | `patches/xnu-8796/series` 168 条 | CI 用 `git apply`，基线是 `aca3beaa3dfb`；**本地校验要在 LF 树上做**（见下） |

### 3.1 一条容易踩的坑：本地树是 CRLF，CI 的树是 LF

本地 `git show HEAD:<file> > x` 得到的文件带 CRLF（Windows 的 `core.autocrlf=true`），
而 CI 的 runner checkout 出的是 LF。**同一个补丁在本地 apply 失败、在 CI 成功，
往往就是这个原因**，不是补丁本身坏了。

本地校验补丁时先把树做成 LF：

```bash
git show HEAD:<file> | tr -d '\r' > <file>
```

### 3.2 一条容易踩的坑：`series` 的行尾

`patches/xnu-8796/series` 是 CRLF。用 Python 改它时，`splitlines()` 之后再用
`'\r\n'.join` 会写出 `\r\r\n`，那会让**所有**补丁静默跳过。改完检查：

```bash
python3 -c "print(open('patches/xnu-8796/series','rb').read().count(b'\r\r\n'))"
# 必须是 0
```

### 3.3 一条容易踩的坑：一次只推一轮

在飞轮次期间只做分析、不推新的；等上一轮落地（上机/照片）后再决定下一轮。
两轮同时在飞会让面板分不清是哪一轮的。

### 3.4 一个不在构建路径上、但带本机路径的脚本

`scripts/reference/make-startup-trace-patch.py` 是一次性诊断辅助（生成
startup trace 补丁用的），**没有任何东西调用它**，构建不会碰它。它里面的
`ROOT` 写的是某台机器的路径，所以从别的机器直接跑它会找不到源文件。
要用它的时候把那一行改成本机的检出树根即可，或者在仓库根设 `NIO_ROOT`。

---

## 4. 失败了给我什么

把 **`nio-kernel-logs`** 这个 artifact 原样发来（或贴 `kernel-bootstrap.log`
最后 100 行）。`kernel-bootstrap.log` 是第一次编译，它失败时 `kernel.log` 根本不会生成。

| 日志 | 含义 | 处理 |
|---|---|---|
| `error: unknown warning option '-Wno-...' [-Werror,-Wunknown-warning-option]` | 镜像的 clang 比写那串 `-Wno-*` 时用的旧 | **已自动处理**：构建前的 **Match the warning flags to this clang** 会拿当前 clang 逐个试，不认识的当场从 `scripts/` 里删掉。仍看到这条，说明那一步自己失败了 |
| `Xcode not found` | runner 镜像换了 Xcode | 一般不会有：`xcode=auto` 会挑最新的；报错行会列出实际版本 |
| `Undefined symbols: ... _corecrypto_kext_start` | 第一次 bootstrap pass 的正常结果（corecrypto 还没编） | 不用管，后面会重新链接 |
| `XNU patch ...: patch does not apply` | 补丁顺序/基线不符 | 把补丁名发来 |
| `error: ...` 在 `build/.../foo.c` | 编译错误 | 贴那条 `error:` 前后 20 行 |

### 为什么会有「warning option 不认识」这种事

UniXNU 的组件编译脚本把一长串 `-Wno-*` 直接跟 `-Werror` 摆在一起，其中
`-Wno-unnecessary-virtual-specifier` 只有很新的 clang 才认识。构建前那一步就是
按当前 clang 把这串选项校准一遍：它打印 `Apple clang version ...`，把不认识的
选项从 `scripts/build-*.py`、`scripts/*.sh` 里删掉，删掉的清单写进运行摘要。
每改一个文件都做语法自检（`.py` 用 `compile()`、`.sh` 用 `bash -n`），改坏了自动
`git checkout` 还原并打一条 warning。

`scripts/unixnu/` 不在它的管辖范围：框架把编译选项经 `CCC_OVERRIDE_OPTIONS` 传给
clang，而 XNU 本体编译不带 `-Werror`，那里出现不认识的选项只是一行 warning。

---

## 5. 这个仓库里什么是真的、什么是没启用的

- `board.toml` 的硬件值全部来自 nio 自己的 dump：GIC `0x17a00000`/`0x17a60000`、
  19.2 MHz 计时器、6 LUN UFS、userdata 在 LUN 4、屏幕 `0x9c000000` 1080×2520。
- `CONFIG_XNU_NATIVE_UFS=y`：**已开**。UFS 驱动是 `drivers/NioUfs/`，
  它移植自 umi（小米10，同 SM8250）的 `ShengUfs`。
- `CONFIG_XNU_NATIVE_LEGACY_DISPLAY=n`：没有 DPU，显示走的是 `GopFramebuffer`。
- `patches/xnu/device/` 里那 18 个补丁是 umi 的调试补丁副本，**没有**进 `series`：
  它们依赖 sheng 的 `sheng_pmgr_run()` 和 boot-progress 层，顺序不对会直接 apply 失败。
- `[payload.adt] unique_chip_id = "required"`：只编内核用不到；要打 payload 时才给 secret。

---

## 6. 官方打包模板(2026-11-02 起)

UniXNU 官方有设备仓库出包脚本：仓库根放 `scripts/package.sh`
（从 `refs/UniXNU/templates/package.sh` 原样复制，不得修改），配置只写在
`board.toml` 的 `[package]` 段，由官方 CLI `unixnu release` 跑
deps → preflight → patches → build → pack → verify 六步，产出
`boot.img`、`payload.img`、`kernel.macho`、`package.manifest.json`。
文档：<https://unixnu.com/zh/porting/packaging>。

本仓库已完成：

| 项 | 状态 |
|---|---|
| `board.toml` `[package]` 段(unixnu 路径 + defconfig 映射) | 已加 |
| `scripts/package.sh`(官方模板原样) | 已复制 |
| 官方验收:`scripts/package.sh --check --no-deps` | **通过** |

尚未接线的两处:

1. **UEFI 检出无 git 源**:`source-lock.json` 的 `uefi-umi`(48bc4121…)是本地
   `build/uefi-umi` 手动检出,feeds.toml 没有 URL。Actions 上跑 release 的
   firmware/pack 步骤需要它,得先把这棵树推上 GitHub,再在 package.yml 的
   `uefi_repository` 输入里填 `org/name`。官方没有 kona 固件包,sheng 的
   `UniXNU/uefi-sheng` 用法对 nio 不适用。
2. **nioPkg INF 未进设备仓库**:`package/Kit.toml` 目前只是 baseline 元数据
   (NioBoot 等仍由本地 bring-up 工具链接)。release 的 firmware 步骤要编
   nioPkg,得把 nioPkg 挪进设备仓库(或 submodule),`[firmware]` 的
   `{tree}` 路径才能解析。

另外注意:**secret `UNIXNU_UNIQUE_CHIP_ID` 官方限定 8 位十六进制**,而本机
`make-nio-adt.py` 首次生成用的是 12 位 `4E494F323530`("NIO250" ASCII)。启用
官方出包时选定一个 8 位值(如 `4E494F32`),secret 与本地 ADT 生成保持同一
值,不要混用。

`--check` 本地验证命令(源码已固定,跳过 fetch):

```bash
cd device/UniXNU-nio
bash scripts/package.sh --check --no-deps
```
