# 在 GitHub 上编 nio 的内核

这份仓库只做一件事：让 GitHub 的 macOS arm64 机器把 `xnu-10063.141.1` 编成
`kernel.macho`，给你下载回来。固件（`nioPkg`）仍然在本地编，不在这里。

## 1. 你需要准备的

| 项目 | 要求 |
|---|---|
| 账号 | 你自己的 GitHub 账号即可，不需要付费 |
| 仓库 | 新建一个空仓库，名字随意，建议 `UniXNU-nio` |
| 可见性 | **公开**最省事：macOS runner 不计费；私有仓库会按 10 倍扣 macOS 分钟数 |
| Secrets | **一个都不需要**（只有 `kernel` 这一步；`payload` 才要 `UNIXNU_UNIQUE_CHIP_ID`） |
| 分支 | `main` |

## 2. 把仓库内容传上去

### 方式 A：网页上传（不用装 git）

1. GitHub → New repository → 名字 `UniXNU-nio` → **不要**勾 README / .gitignore → Create。
2. 把 `UniXNU-nio-github.zip` 解压，得到 `board.toml`、`configs/`、`patches/`、
   `scripts/`、`package/`、`docs/`、`.github/` 等。
3. 在仓库首页点 **Add file → Upload files**，把这些**文件和文件夹**整体拖进去
   （注意 `.github` 是隐藏目录，要在文件管理器里打开“显示隐藏文件”，否则工作流不会上传）。
4. Commit。

> 关键检查：仓库根目录必须能直接看到 `board.toml` 和 `.github/workflows/kernel.yml`。
> 如果上传后变成 `UniXNU-nio/UniXNU-nio/board.toml`，工作流会报
> `the device repository has no board.toml`。

### 方式 B：git 命令行

```bash
git init -b main
git add .
git commit -m "nio device repository"
git remote add origin https://github.com/<你的账号>/UniXNU-nio.git
git push -u origin main
```

## 3. 运行

1. 仓库页面 → **Actions** → 左侧 **Build nio kernel** → 右侧 **Run workflow**。
2. 参数保持默认即可：

| 参数 | 默认值 | 说明 |
|---|---|---|
| `unixnu_ref` | `04573c510c5fd4892ca6948739389141cc9e05f5` | 固定的 UniXNU 版本，别改成 `main` |
| `defconfig` | `nio_defconfig` | `configs/` 里的名字 |
| `xcode` | `26.6` | 如果镜像里没有这个版本，报错行会列出实际安装的 `Xcode_*.app`，照它改 |
| `ipsw_url` | 空 | 空 = 用 `board.toml` 里 Apple 的 17.7.11 IPSW |

3. 点 **Run workflow**，等 40–90 分钟（第一次要下 XNU 源码和 17.7.11 的 kernelcache）。

## 4. 拿结果

成功后，这次运行的页面底部 **Artifacts** 里有两个包：

| 包 | 内容 |
|---|---|
| `nio-kernel` | `kernel.macho` + `kernel.macho.json`（预链接记录） |
| `nio-kernel-logs` | `status.txt`、`kernel.log`、`kernel-bootstrap.log`、`archive-*.log` |

把 `kernel.macho` 和 `kernel.macho.json` 解压到本机的
`E:\nio-unixnu-port\out\`，和 `nio.adt` 放一起。剩下的打包（payload FAT → boot.img）
在本地做，不需要再上 GitHub。

## 5. 失败了给我什么

只要把 **`nio-kernel-logs`** 这个 artifact 原样发我（或把 `kernel-bootstrap.log`
最后 100 行贴出来）。`kernel-bootstrap.log` 是第一次编译，它失败时 `kernel.log`
根本不会生成，所以先看它。

常见三类，日志里长这样：

| 日志 | 含义 | 处理 |
|---|---|---|
| `xcode-select: error` / `Xcode not found` | runner 镜像换了 Xcode 版本 | 按报错里列出的版本改 `xcode` |
| `XNU patch ...: patch does not apply` | 补丁顺序/基线不符 | 把补丁名发我，我调 `patches/` |
| `error: ...` 在 `build/.../foo.c` | 编译错误 | 贴那条 `error:` 前后 20 行 |

## 6. 这个仓库里什么是真的、什么是没启用的

- `board.toml` 的硬件值全部来自 nio 自己的 dump：GIC `0x17a00000`/`0x17a60000`、
  19.2 MHz 计时器、6 LUN UFS、userdata 在 LUN 4、屏幕 `0x9c000000` 1080×2520。
- `patches/xnu/device/` 里那 18 个补丁是 umi 的调试补丁副本，**没有**进
  `series`：它们依赖 sheng 的 `sheng_pmgr_run()` 和 boot-progress 层，顺序不对
  会直接 apply 失败。等内核能出 console 再一个一个加。
- `CONFIG_XNU_NATIVE_UFS=n`：继承来的 UFS 驱动只认 LUN 0，nio 的 userdata 在
  LUN 4，先开只会把“没盘”变成“读错盘”。
- `[payload.adt] unique_chip_id = "required"`：这一步只编内核，用不到；等要打
  payload 时再给 secret。
