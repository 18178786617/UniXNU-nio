# 刷入 iOS 之后的路线图

这份文档是「机器上已经跑着 iOS 16.5」之后的施工顺序。顺序不是按技术难度
排的，是按**依赖**和**用户要求**排的：

> 显示正常 → **WiFi** → 触摸 → 存储 → GPU 加速

WiFi 排在显示之后、其余之前，是明确要求。显示排第一，是因为后面每一项都要
在「看得见」的前提下调试 —— WiFi 的每一步、触摸的每一次点位、GPU 的每一条
PM4，读数都要有人能立刻看到。

---

## 阶段 0（前置）：16.5 内核切换 ✅ 已完成

这不是「刷完 iOS 之后」的事，而是「把 iOS 刷上去」这件事本身。之前树里的
内核是 17.7.11 / xnu-10063.141.1，而 16.5 的用户态必须配 xnu-8796 一类的
16.x 内核，两边不匹配。NX769J（红魔 9）已经把同一件事做完了，三步：

| 步 | 做什么 | 谁做的 |
|---|---|---|
| 0.1 | 设备仓自带 `os-profiles/ios-16.5-20F66/`，构建工作流把它 `cp -R` 进 `UniXNU/profiles/os/` | NX769J 的 `build.yml:148` |
| 0.2 | 共享补丁系列重基到 `xnu-8796.101.5`（67 个补丁文件）；**GPU 探针钩子补丁按 8796 的 `bsd/kern/bsd_init.c` 重做** | NX769J + 本仓 |
| 0.3 | donor kernelcache 换成 iPhone10,3 的 `e6fa7559…`，prelink 绑定、ADT 身份（`iPhone10,3` / D22AP）一起换 | 本仓 R123 |

**为什么必须排在显示之前**：显示组件（GopFramebuffer）要用 donor kernelcache
里原版 `IOMobileFramebuffer` 的三个绑定地址。先在 17.7.11 上把显示做通、
再切 16.5，这三个地址要重新导出、显示要重做一遍。先切 16.5 再做显示，只做
一次。

板级代码（GPU 驱动归档、探针、A650 冷启动、ADT 编码、UEFI 固件）不受影响，
只有「内核侧的钩子」和补丁系列要跟着换内核重做。

### 现在的状态

三步全部完成（commit `24f0fa8` = R123，`a7bd213` = R124）：

| 位置 | 内容 | 状态 |
|---|---|---|
| `board.toml` 的 `os_profile` | `ios-16.5-20F66` | 生效 |
| `board.toml` 的 `patch_series` | `device:patches/xnu-8796/series` | 生效 |
| `board.toml` 的 `config_fragments` | `os:configs/ios.config`（16.5 的 OS 片段） | 生效 |
| `board.toml` 的 `[kernel.prelink]` | 16.5 donor、`e6fa7559…`、本仓包装脚本、30 条 roots、`early_security_init` 留空 | 生效 |
| `board.toml` 的 `[ipsw]` | 16.5 成员名 + 6 个实测 pin | 生效 |
| `os-profiles/ios-16.5-20F66/` | 16.5 的 OS profile（`prelink.tool` 改成 nio 自己的包装脚本） | 就位 |
| `patches/xnu-8796/` | 67 个重基到 xnu-8796.101.5 的补丁 + series | 就位 |
| `patches/xnu-8796/xnu-8796-compile-records.patch` | 8796 缺的编译记录（`-MJ`），archive 构建器和 bootstrap 都要它 | 已验 |
| `patches/xnu-8796/gpu-probe-start.patch` | nio 自己的 GPU 探针钩子，按 8796 的 `offline-legacy-start.patch` 之后的锚点重写，插在 series 第 36 位 | 已验 |
| `patches/xnu-8796/native-smp-type-clusters.patch` | SM8250 特有的双集群调度补丁，本仓在 8796 上重做（NX769J 是 SM8550，没有这条） | 已验 |
| `tools/check-patch-scope.py` | 查补丁有没有把代码块甩到函数外面（rebase 损伤）；CI 每次构建都会跑 | 已验 |
| `scripts/emit-prelink-nio.py` | prelink 包装脚本（16.5 kernelcache 的 Libm 常量池表） | 就位 |
| `donor/kernelcache.decompressed.gz` | 16.5 kernelcache 的 arm64 切片（17.6 MB gzip），构建时按 board.toml 的 pin 校验 | 就位 |

**整套 67 条已经在真实的 xnu-8796.101.5 上按序 apply 过，零失败。**
验证方法（可复现）：从 Apple 的开源发行拿到 `xnu-8796.101.5.tar.gz`
（`codeload.github.com/apple-oss-distributions/xnu/tar.gz/refs/tags/xnu-8796.101.5`），
`git init` 后逐条 `git apply`，顺序照 series。结果：**67 条全部 ok**，
改动落在 82 个文件上（+2794 / -128）。

### 16.5 切换踩到的两个坑（R132 修掉）

「apply 干净」不等于「编译得过」。两个坑都在重基这一步：

1. **`native-smp-type-clusters.patch` 的代码块被甩到了函数外面。** 上游
   （xnu-10063）那一版的 hunk 把函数结尾的 `}` 当作**新增之后**的上下文行，
   所以代码块落在函数体内；手抄到 8796 时 `}` 变成了新增**之前**的上下文行，
   代码块就掉到了文件作用域 —— 一个 `for`、一个裸 `return;`、一个函数调用
   站在文件作用域上，任何 C 编译器都不会收。git 照样 apply 成功，因为 git 匹配
   的是上下文行，不是结构。
2. **xnu-8796 不写编译记录。** xnu-10063 的三条编译规则里有 `-MJ`，
   每个目标文件旁边都会落一份 JSON 编译记录；8796 没有。archive 构建器
   （mockfs fixture、GPU 归档、libpthread）要靠这份记录重放编译命令，
   构建驱动也要靠 `startup.o.json` 判断 bootstrap 那趟的编译部分成功了没有。
   缺了它，bootstrap 的链接必然失败（mockfs 的三个符号只在
   `libmockfs_fixture.a` 里，而 bootstrap 那一趟不链它），而且这个失败**吞不掉**，
   因为「编译部分成功了」的凭据不存在。

第 1 条是 8796 特有的重基损伤，第 2 条是 8796 与 10063 的机制差异。
`tools/check-patch-scope.py` 是为第 1 条写的：它读补丁树的 git diff，
把**新增行**逐行按大括号深度扫一遍，报出落在文件作用域上的语句。
CI 每次构建都会跑一遍这个检查，坏了会直接写进失败报告。

**donor 的哈希是实测的，不是抄的**：16.5 镜像里的 kernelcache 走
IMG4 → LZFSE → 取 arm64 切片，切片哈希
`e6fa75598f47b5a9460a60913e2ac8e4cd6cd60eb475bb31da65b68ffbcfdad5`，
与 profile 的 pin 一致；两个 dmg 与两个 trust cache 也是在本机
`E:\nio-unixnu-port\ios165\ipsw\` 上实测的。

**构建不再需要 IPSW**：内核阶段只需要 kernelcache 一个成员，
`UNIXNU_KERNELCACHE` 直接给它；restore image 不可再分发，这件事不再是障碍。

### 双集群补丁为什么必须重做

NX769J 是 SM8550，它的重基系列里没有 SM8250 的
`native-smp-type-clusters.patch`。这条补丁做三件事：
`board_config.h` 里给 BCM2837 放开 `MAX_CPU_CLUSTERS = 2` 与 `__ARM_AMP__`；
`sched_clutch.c` 里在没有性能控制器时给每个 bucket group 一个默认偏好簇；
`thread_group.c` 里加 `thread_group_set_default_preferred_clusters()`。

三个锚点在 8796 上都还在，但**上下文都变了**：

- `board_config.h`：8796 里 BCM2837 块在 VMAPPLE 块**之前**（10063 在之后），
  所以覆盖块要插到 VMAPPLE 的 `#endif` 之后、`#if MAX_CPU_CLUSTERS == 1` 之前 ——
  位置很关键，放晚了下面那句 `#undef __ARM_AMP__` 会把它清掉。
- `sched_clutch.c`：结构没变，锚点还在，只是行号变了。
- `thread_group.c`：8796 里 `sched_perfcontrol_edge_cpu_rotation_bitmasks_set()`
  **不存在了**（8796 那一支把它删了），所以新增函数后面接的是
  `#else /* CONFIG_SCHED_EDGE */` 而不是原来那个函数。新函数仍然落在
  `#if CONFIG_SCHED_EDGE` 分支里。

---

## 阶段 1：显示正常

### 已经有的

- **固件侧已经有 GOP**：`nioPkg/nio.dsc` 里 `USE_CUSTOM_DISPLAY_DRIVER = 0`，
  用通用 `SimpleFbDxe`，继承 ABL 已经点亮的 "Display Reserved"
  （`0x9C000000` + `0x2400000`）。`Include/DXE.inc` 里带
  `GraphicsConsoleDxe` + `SimpleFbDxe` + `DisplayReEnablerDxe`。
  参数：`PcdFrameBufferWidth|1080`、`PcdFrameBufferHeight|2520`、
  `PcdFrameBufferColorDepth|32`。
- **DarwinBoot 已经会交接**：`drivers/DarwinBoot/DarwinBootPkg/Driver/DarwinBoot.c`
  取 `gEfiGraphicsOutputProtocolGuid`，写进 `boot_args`。
- **framebuffer 的实测值**（`package/nio-hardware.json`）：base `0x9c000000`，
  1080×2520，pitch 4320，32 bpp。

### 缺的（四条，按修复顺序）

1. `GopFramebuffer` 组件**没有选中**（`board.toml` 的 `[components].include` 里没有它）。
2. **主仓没有显示归档构建器**：`scripts/compatibility.toml` 里
   `"build-native-mobile-display.py" = "build-gop-framebuffer.py"`，但
   `scripts/build-gop-framebuffer.py` **不存在** —— 它只存在于
   `refs/UniXNU-sheng/scripts/`（108 行）。
3. sheng 的 `build-gop-legacy-display.py`（349 行）开头有硬门
   `if ARCH != 'arm64' or IOS_VERSION.split('.')[0] != '17': raise SystemExit(...)`
   —— **只支持 iOS 17**，目标是 16.5。
4. `GopFramebuffer` 的 `os_abi` 只列 `ipados-17.7.11-21H461` 与
   `ipados-27.0.1-24A446`，**不含 `ios-16.5-20F66`**。

### 两条路线

| | A：mobile display | B：legacy display |
|---|---|---|
| 产出 | `build/gop-framebuffer/libGopFramebuffer.a` + `.late.a` | `build/native-legacy-display/libNativeLegacyDisplay.late.a` |
| 源 | `NativeMobileDisplay.cpp` | `NativeLegacyDisplay.cpp` |
| 依赖 | **原版 IOMobileFramebuffer 的三个绑定**（C2/D2/gMetaClass），要从 donor 里导 | 自带 `NativeGOPPresenter`，不依赖原版绑定；但也把 sheng 的整套 legacy 人格（HID/按键/背光/电池/音频/DPU/WiFi net）捆在一起 |
| nio 的代价 | 移植 `build-gop-framebuffer.py`，把它的三处 sheng pin 换成 nio 的 | 砍掉 sheng 的硬件服务，只留显示 —— 但那套 recipe 是写死的 |

**建议走 A**，理由是它的产物边界清楚（两个归档），且不拖进 sheng 的硬件服务。
B 的 `build-gop-legacy-display.py` 一口气编 20 多个 sheng 专属组件，nio 上
绝大多数不存在，砍到最后基本等于重写。

### A 路线的施工步骤

- **D1｜选组件**：`board.toml` 的 `[components].include` 加 `GopFramebuffer`。
  它是 `build_stage = "embedded"`、`build = []`，所以选它不产归档、不产第二份
  源码，只是把 `drivers/GopFramebuffer` 放进树里；归档要靠自己的 recipe 编。
  组件仓库 `https://github.com/UniXNU/GopFramebuffer.git` @ `19ef3a75…`
  （本地 `refs/UniXNU/drivers/GopFramebuffer` 是空目录，**子模块还没 checkout**）。
- **D2｜移植构建器**：把 sheng 的 `scripts/build-gop-framebuffer.py` 搬进本仓
  `scripts/`，改掉三处 sheng 的 pin：
  1. **donor 候选**。sheng 写死了
     `require(sha(candidate)=='aded28d3c61dafaf7b8a7c96b14427a798e9e95470ae6f287bcd038c07626798')`
     —— 那是 sheng 的 prelink candidate。nio 要用 16.5 的 donor 重新导出
     `native-owner-mobile-graphics-candidate.macho`，并把哈希换成自己的。
  2. **探针源码**。sheng 用 `kits/sheng/MobileDisplayProviderProbe.cpp`，
     nio 要写自己的（或先只用 original-bindings 那一半）。
  3. **原版绑定地址**。sheng 写死了三个地址
     （`0xfffffff00577b318` / `0xfffffff00577b364` / `0xfffffff006b313d8`），
     那是它 donor 里的。nio 要从 16.5 donor 里重新定位。

  **第 3 条已经做完了**，而且结论比预想的更重要：16.5 的 donor 符号表里
  **一个 kext 符号都没有**（5868 个导出名全是内核自己的），所以三个绑定
  只能从二进制结构反推。反推的办法写成了工具
  `tools/find-mobile-framebuffer-bindings.py`：它对任意 prelink 镜像都能
  重新算出这三个地址。

  定位链条（三步，每步都有可验证的证据）：

  1. **段归属**。`_PrelinkExecutableLoadAddr`（`0xfffffff004f67b40`）只是
     kext 的 Mach-O **头**，不是代码。kext 的四段分别落在：
     `__TEXT`（头 + cstring）在 `__PRELINK_TEXT`、`__TEXT_EXEC`（代码 +
     `__stubs`）在 `__PLK_TEXT_EXEC`、`__DATA` 在 `__PRELINK_DATA`、
     `__DATA_CONST`（`__got` + `__const`）在 `__PLK_DATA_CONST`。
     所以「142 对 stub」不能靠 kext 的 load addr 圈，要靠 kext 自己的
     `__stubs` 段。
  2. **类初始化器**。XNU 在运行时才填 metaclass 的名字，所以「类 ↔ 地址」
     的唯一静态联系是每个类自己的初始化器：它拿类名字符串和 metaclass
     去注册。`IOMobileFramebuffer` 的字符串在 `__cstring` 的
     `0xfffffff004f69113`，初始化器在 `0xfffffff005c03724`，它把
     metaclass `0xfffffff006ded568` 写进 `&gMetaClass`。
  3. **`this[0]` 是 vtable，不是 isa**。内核自己的
     `__ZN9IOServiceC2EPK11OSMetaClass`（`0xfffffff007758008`）写的是
     `str x8,[x0]`，x8 = vtable 地址。所以派生类的 C2 写进 `this[0]` 的
     是**它自己的 dispatch table**；而 dispatch table 里有一项会返回
     `&gMetaClass` —— 只有拥有那个 metaclass 的类才有这一项。

  结论，16.5 donor 上的四个绑定：

  | 符号 | 16.5 donor |
  |---|---|
  | `__ZN19IOMobileFramebufferC2EPK11OSMetaClass` | `0xfffffff005c03674` |
  | `__ZN19IOMobileFramebufferD2Ev` | `0xfffffff005c036c0` |
  | `__ZN19IOMobileFramebuffer10gMetaClassE` | `0xfffffff007a3bfd8` |
  | 父类 dispatch table | `0xfffffff006decd70`（**252 项**） |

  交叉验证：C2 在 `+0x30` 处 `bl` 到 `IOService::C2` 的 veneer
  （`0xfffffff005c29184` → `0xfffffff007758008`），D2 在 `+0x18` 处 `bl` 到
  `IOService::D2` 的 veneer（`0xfffffff005c29190` → `0xfffffff007758038`）——
  与 sheng 的 17.7.11 **偏移完全一致**（+0x30 / +0x18）。

  **但这三个地址是 donor 坐标，不能直接抄进 recipe。** prelink 会把 donor
  的 kext 段按 slide（`board.toml` 里 `-0x1000000`）重定址，而最终内核
  自己的段布局又不同。sheng 的做法是从**自己构建出的 prelink candidate**
  里读地址，nio 要照做：先出内核，再从内核里读，再编驱动，再重链。

  另一条更要紧的发现：**16.5 上该继承哪个类，变了。**

  | 类 | C2 | D2 | dispatch table | 表长 | 自有 |
  |---|---|---|---|---|---|
  | `IOMobileFramebuffer` | `0xfffffff005c03674` | `0xfffffff005c036c0` | `0xfffffff006decd70` | 252 | 10 |
  | `IOMobileFramebufferService` | `0xfffffff005c0386c` | `0xfffffff005c038b8` | `0xfffffff006ded600` | 252 | 10 |
  | `IOMobileFramebufferLegacy` | `0xfffffff005c0dbbc` | `0xfffffff005c0d668` | `0xfffffff006def260` | **338** | **174** |
  | `IOMobileFramebufferUserClient` | `0xfffffff005bff01c` | `0xfffffff005bff09c` | `0xfffffff006debde8` | 187 | 10 |

  `IOMobileFramebuffer` 在 16.5 只实现了 252 项里的 **10 项**（索引
  {0,1,7,168,172,225,248,249,250,251}），其余 165 项指向内核符号，其中
  77 项是 `___cxa_pure_virtual`。而 sheng 的 17.7.11 上 `IOMobileFramebuffer`
  实现了 262 项里的约 98 项。**所以 sheng 那份按 17.7.11 写的
  `NativeMobileDisplay` 不能只换地址就搬过来** —— 父类的 dispatch table
  形状完全不同；真正承载 16.5 显示逻辑的是 `IOMobileFramebufferLegacy`
  （338 项，多出 86 项），kext 里的源码路径
  `/Library/Caches/com.apple.xbs/Sources/IOMobileFramebuffer/Kernel/AppleDisplayPipe/…`
  也指向它。继承关系和实例大小见下面 D2 那段。

  需要的工具：`kits/XnuPrelink/native_prelink.py` 的
  `macho()` / `exports()` / `backed_offset()` / `unserialize_xml()`，
  全部现成；`__PRELINK_INFO` 是 **XML plist**（不是二进制 plist），
  `unserialize_xml()` 能直接解。

  **16.5 的继承链已经量出来了**（类初始化器里传给 metaclass 构造器的
  父类 gMetaClass，加上 `w3` 的实例大小）：

  ```
  IOService                                   136 字节
   └─ IOMobileFramebuffer                     144 字节   252 槽
       └─ IOMobileFramebufferService          144 字节   252 槽
           └─ IOMobileFramebufferLegacy     5728 字节   338 槽
  ```

  这条链是移植的根据，有三处和 sheng 的 17.7.11 不同：

  1. **要继承的是 `IOMobileFramebufferLegacy`**，不是
     `IOMobileFramebuffer`。它才实现 338 槽里的 174 槽（自有实现在
     168..337 之间连续排开），而 `IOMobileFramebuffer` 只实现 252 槽里的
     10 槽 —— 后者是抽象壳，屏走不通。
  2. **`IOMobileFramebufferLegacy` 的父类是
     `IOMobileFramebufferService`**，不是 `IOMobileFramebuffer`。
     派生类要一路继承下来，中间那层不能跳。
  3. **16.5 的 kext 里没有 `getDisplayDimensions`**（17.7.11 才有）。
     它的 `__cstring` 是旧式的 `iomfb_RuntimeProperty_*` 一套，
     和 17.7.11 的方法集不同，所以 sheng 的 `OriginalMobileFramebufferABI.h`
     那个 262 槽的声明**在 16.5 上整体不能用**。

  槽位地图由 `tools/dispatch-layout.py` 给出（自有 / 继承 / 纯虚，
  逐槽标注）；三个绑定由 `tools/find-mobile-framebuffer-bindings.py`
  给出（这两个工具都在本仓，R128/R129）。

  | 类 | C2 | D2 | gMetaClass | dispatch table | 槽数 | 自有 |
  |---|---|---|---|---|---|---|
  | `IOMobileFramebuffer` | `0xfffffff005c03674` | `0xfffffff005c036c0` | `0xfffffff007a3bfd8` | `0xfffffff006decd70` | 252 | 10 |
  | `IOMobileFramebufferService` | `0xfffffff005c0386c` | `0xfffffff005c038b8` | `0xfffffff007a3c000` | `0xfffffff006ded600` | 252 | 10 |
  | `IOMobileFramebufferLegacy` | `0xfffffff005c0dbbc` | `0xfffffff005c0d668` | `0xfffffff007a40540` | `0xfffffff006def260` | **338** | **174** |

  `IOMobileFramebufferLegacy` 的 9 个纯虚槽：211、212、242、243、292、
  293、321、322、329。

- **D3 的 ABI 底稿已经量出来了（R136）**：16.5 的 338 槽地图用
  `tools/dispatch-layout.py` 从 donor 重新核过，数字与上表逐项吻合；
  `tools/make-mobile-framebuffer-abi.py`（R136 新增）从同一份 donor 生成
  16.5 的镜像头 `package/OriginalMobileFramebufferABI16_5.h`，按真实继承链
  逐层声明各自**新增**的槽：`IOMobileFramebuffer` 168..251、
  `IOMobileFramebufferService` 不新增、`IOMobileFramebufferLegacy` 252..337。

  槽的**方法名**仍然拿不到：prelinked kext 在 kernelcache 里没有符号表
  （`LC_SYMTAB` 的 `nsyms` 是 0），自有槽指向的是 kext 内部函数，导出符号
  表里没有它们。镜像头因此照 sheng 的做法把不能识别的槽写成
  `unclassifiedNNN()` 纯虚函数（不许返回），具名的槽留到结构化匹配之后再填。

  **D3 剩下的活**：把 16.5 kext 的方法体与 17.7.11 kext 的做结构化匹配，
  把 `beforeExternalMethod` / `releaseClientState` / `setPixelFormat` 这一类
  名字落到确切的槽号上。17.7.11 的槽号对照表在生成器里
  （`I17_SLOTS`：182 / 193 / 249）。

- **16.5 没有 `getDisplayDimensions` —— 替代入口找到了（R136）**：
  16.5 的 kext 把显示状态放在 `IOMFB::RuntimeProperty` 上，而不是方法上。
  从 donor 里把 kext 自己的 `__cstring` 读出来，runtime property 的名字表是：

  ```
  width  height  format  rotation  allocateDefaultFramebuffer
  enableDither  enablePartialUpdate  enableGammaCorrection
  displayMaxRefreshInterval  displayMinRefreshInterval  displayRefreshStep
  overrideBacklight  backlightValue  totalSwaps  totalVBLs  swapId
  setActive  setParameter  isSetBlockEnumAllowed  ...
  ```

  kext 里的辅助函数名也在字符串里：
  `IOMFB::getRuntimePropertyName` / `getRuntimePropertyType` /
  `getRuntimePropertyType` / `getBitDepthValue` /
  `getGamutConversionLocationFromRTP` / `getIdleDetectorFromRTP` /
  `getIdleDetectorRTPTypeForIdleDetectorRTP` / `get_RTP_boot_arg_name`。

  **但方法名拿不到**：kext 没有把 `__FUNCTION__` 展开进字符串 ——
  `setPixelFormat` / `getDisplayDimensions` / `completeCurrentSwap` /
  `setPowerState` / `newUserClient` 在 16.5 的 `__cstring` 里一个都不在。
  所以槽名仍需靠方法体的结构化匹配来认。

  顺带拿到了 16.5 kext 的**源文件清单**（从字符串里的路径反推）：
  `IOMobileFramebufferLegacy.cpp`、`IOMobileFramebufferRuntimeProperties.cpp`、
  `IOMobileFramebufferUserClient.cpp`、`DriverCommonFunctions.cpp`、
  `DCPUtils.cpp`、`IOAVHandler.cpp`、`IOAVHandlerInternalDisplay.cpp`、
  `IOMFBBlockManager.cpp`、`InterruptSource.cpp`、`RefCounted.cpp`、
  `UPAAFProxy.cpp`、`UPAsynchronousScheduler.cpp`、`UPIOMemory.cpp`、
  `UPIOSvcProxy.cpp`。

- **D3｜先只做最小形态**：只编 `NativeMobileDisplay.cpp` + `original-bindings.o`，
  跳过 `MobileDisplayProviderProbe`（sheng recipe 的第 83 行起）。少一块就少
  一个失败点，先让 framebuffer 被接管住。
  **但 ABI 头文件要重写**：按上面 338 槽的地图重新声明
  `IOMobileFramebufferLegacy`（以及它继承的 `IOMobileFramebufferService`
  和 `IOMobileFramebuffer`），不能照抄 sheng 的 262 槽版本。
- **D4｜打开开关**：`CONFIG_XNU_NATIVE_MOBILE_DISPLAY=1`
  （`configs/nio_defconfig` 第 74 行现在是 `n`）。`build-xnu-4k-baseline.sh`
  第 652 行会 force_load `build/gop-framebuffer/libGopFramebuffer.late.a`。
- **D5｜交接校验**：用主仓的 `scripts/check-gop-handoff-checkpoints.py` 核对
  `boot_args` 里的值。sheng 的 QEMU fixture 期望
  `physical_base=2088370176, display=1, row_bytes=3200, width=800, height=600,
  depth=32`；nio 要对的是 **`physical_base=0x9c000000`、`width=1080`、
  `height=2520`、`row_bytes=4320`、`depth=32`**。
- **D6｜判定标准**：内核起来后 framebuffer 被 IOMobileFramebuffer 以正确的
  stride 接管；`dumpsys display` 报 1080×2520；屏幕上出现内核/用户态画面
  （不是白屏、不是花屏、不是错位）。
- **D7｜桩自动让位**：本轮刚加的 `package/LinkStubs.c` 里
  `native_gop_handoff_call` / `native_gop_handoff_memory` 是弱定义，但被
  `#if !XNU_NATIVE_LEGACY_DISPLAY && !XNU_NATIVE_MOBILE_DISPLAY` 包着 ——
  显示开关一开，桩自动让位给 GopFramebuffer 的真实定义，链接不会有两个定义。

### 风险

- ~~16.5 donor 里必须有 `IOMobileFramebuffer`。iPhone X 的 16.5 有，但要先解开
  IMG4/LZFSE 才能读到符号表~~ —— **这条已经排除**：donor 已解开
  （`donor/kernelcache.decompressed.gz`），符号表 5868 个导出名，
  `tools/prelink-kexts-16.5.json` 里有 239 个 kext 的地址表，
  `IOMobileGraphicsFamily` 在 `0xfffffff004f67b40`（size `0x8378`）。
  ~~剩下的是「挑出属于它的那一对 stub」这一步~~ —— **这一步也做完了**，
  三个原版绑定已经算出来（见 D2 第 3 条），并且写成了可复用的工具
  `tools/find-mobile-framebuffer-bindings.py`。
- **新风险：16.5 的 `IOMobileFramebuffer` 不是 17.7.11 的那个形状。**
  它的 dispatch table 只有 252 项且只实现 10 项（17.7.11 是 262 项、实现
  约 98 项），真正承载显示逻辑的 `IOMobileFramebufferLegacy` 是 338 项。
  sheng 的 `NativeMobileDisplay` 按 17.7.11 写死的那套继承关系与入口选择
  （`beforeExternalMethod` / `releaseClientState` / `getDisplayDimensions`
  在他那边落在 182 / 193 / 249）在 16.5 上**对不上**。D2 之前要先定
  「继承谁、接管哪几项」。
- `GopFramebuffer` 的 `os_abi` 没写 16.5。这是目录里的元数据声明，
  `scripts/unixnu/*.py` **完全不校验 `os_abi`**（grep 零命中），所以不会挡住
  构建；但要在 `porting.toml` 里记一笔「声明与事实不符」。

---

## 阶段 2：WiFi

### 先纠正一个事实：目录里的 `Ath12kWifi` 用不上

`nio-dump/vendor_modules.txt` 里，这台机器的无线模块是
**`qca_cld3_qca6390.ko` 和 `qca_cld3_qca6490.ko`** —— 也就是 **QCA6390 /
QCA6490，走 CNSS2 + q6v5 + MHI**。

而 UniXNU 目录里唯一的无线组件 `Ath12kWifi` 的
`hardware = ["ath12k PCI devices", "qcc2072, qcn9274, and wcn7850 build inputs"]`
对应的是 **SM8550 的 WCN7850（PCIe / ath12k）**，跟 nio 的 QCA6390 不是同一代；
它的 `os_abi = ["nw_abi platform interface"]` 也和 NX769J profile.toml 里记的
结论一致（「声明与事实不符」）。**这条线整个划掉。**

### 同款芯片 + 同款 OS 的现成参照

`ch1tmdgus/ios-v60`（LG V60，SM8250，Darwin 22.6.0 / xnu-8796.141.3）——
**同一个 SoC、同一个 QCA6390、同一个 16.x 内核**。它的 `docs/v60/WIRELESS.md`
写得非常清楚：WiFi 尚未实现；`compatible` 是 `qcom,cnss-qca6390`；
「Linux 驱动不能直接链进 XNU」；并给出了四阶段计划。它的 wireless1/2/3
分别走到「时钟与 UART 状态」「内部收发 2/2」「请求电源与查询 HCI 版本」。

### nio 手上的输入

| 来源 | 内容 |
|---|---|
| `modem_a` 分区 → `/vendor/firmware_mnt`（ext4，395 MB） | Qualcomm 固件与 WiFi board 文件 |
| `bluetooth_a` 分区 → `/vendor/bt_firmware`（ext4，1 MB） | BT 固件与 NVM（V60 当年从这里取的 `htbtfw20.tlv` 202300 B、`htnv20.bin` 5775 B） |
| `ArmSmmu4K` 组件 | SMMU/DMA 的一半已经在树里 |

### 阶段划分（每阶段一个镜像，一次只动一个变量）

| 阶段 | 做什么 | 通过标准 |
|---|---|---|
| **W0** | 只读采集 `modem_a` / `bluetooth_a` 里的固件与 board 文件，记 sha256。不开 radio、不写 flash | 拿到 QCA6390 的 WiFi 固件、board 文件、BT 固件与 NVM |
| **W1** | PCIe RC0 枚举 + **MHI firmware boot**（CNSS2 core） | 读到 MHI 的固件版本，不出网 |
| **W2** | **QMI / WMI handshake** | 拿到 firmware 版本、**board ID**、reg domain |
| **W3** | **HTT datapath**（RX/TX） | 内核侧能收发自收发的帧 |
| **W4.0** | 从 `096-04088-077.dmg` 取出 16.5 的 dyld shared cache 并 dump，列出 CoreWIFI / IO80211 的真实导出符号 | 拿到 CoreWIFI 的符号表，W4 不再靠猜 |
| **W4** | **Darwin 侧 Apple80211 ioctl 桥**（sheng `package/WifiNet.cpp` 模式：`SIOCSA80211`=0x802869c8、`SIOCGA80211`=0xc02869c9）+ 把 16.5 的 CoreWIFI 用户态栈接上 | iOS 侧能扫到 AP |
| **W5** | 与 iOS 网络栈联调：关联、DHCP、上网 | 能上网 |
| **BT** | 与 WiFi 共享电源与 CNSS，走 **GENI UART + HCI**，接 iOS `bluetoothd` | 能被 iOS 发现 |

### W4 的硬难点：16.5 的无线用户态是 CoreWIFI，而内核侧有 IO80211Family

先纠正一处：早先这里写的是「16.5 没有 IO80211 用户态栈」，那是查了用户态
文件系统得出的结论，**只对了一半**。16.5 切换完成后把 donor kernelcache 解开
查了 `__PRELINK_INFO`，真���是：

**内核侧有 IO80211Family。** 16.5 的 kernelcache 里有 239 个 kext，其中
`com.apple.iokit.IO80211Family` 在列：

| kext | `_PrelinkExecutableLoadAddr` | size |
|---|---|---|
| `com.apple.iokit.IO80211Family` | `0xfffffff005409780` | `0x72968` |
| `com.apple.iokit.IOMobileGraphicsFamily` | `0xfffffff004f67b40` | `0x8378` |
| `com.apple.iokit.IOSurface` | `0xfffffff004ed7400` | `0x5a05` |

完整的 239 条清单在 `tools/prelink-kexts-16.5.json`（31 KB），由 donor 的
`__PRELINK_INFO` 段反序列化而来。**board.toml 那 30 条 roots 全部在这份清单里
核实存在** —— 这条 pin 在本机镜像上完整验证过。

用户态那一半的结论仍然成立：

- `System/Library/Extensions/` 里**没有 IO80211Family.kext**（只有
  `IOHIDFamily.kext`、`IOUSBDeviceFamily.kext`、`AppleMultitouchSPI.kext`
  等 18 个）；
- `System/Library/PrivateFrameworks/IO80211.framework/` 和
  `PrivateFrameworks/CoreWiFi.framework/` 都**只有 `Info.plist` 和签名，
  没有二进制**。

原因是 **16.5 的用户态二进制全部在 dyld shared cache 里**，而本机
`E:\nio-unixnu-port\ios165\root\` 是从 IPSW 解出的文件系统，不含 cache ——
cache 在 `096-04088-077.dmg`（4.7 GB）里面。

所以 W4 的形状变了，而且变好了：

- **内核侧不是从零写 IO80211**，而是实现 Apple80211 的 ioctl 契约
  （`SIOCSA80211` = 0x802869c8、`SIOCGA80211` = 0xc02869c9），让 16.5 的
  IO80211Family（已经在 donor 里）能驱动它。sheng `package/WifiNet.cpp` 的
  路子正是这个，方向确定。
- **用户侧仍然要自己找栈**：CoreWIFI 的客户端在 dyld cache 里，root 里只剩
  骨架。要用它们就得把 cache 从 `096-04088-077.dmg` 里取出来 dump，拿到
  CoreWIFI 的真实导出符号。所以 W4 之前仍然要先做 **W4.0**。

两条路，代价不同：

- **自建 Apple80211 ioctl 桥**（sheng `WifiNet.cpp` 的路子）：内核侧实现
  Apple80211 的 ioctl 与接口注册，用户态侧用 16.5 的 CoreWIFI 家族驱动它。
  工作量大，但方向是确定的。
- **只做到 L2**：内核侧给出网卡与帧收发，不接 iOS 的无线服务栈。能测、能用
  自己写的工具验证，但不是「系统里的 WiFi」。

**判定标准要诚实**：不注册假的 WiFi/BT 服务（V60 的原则）。做不到系统集成的
时候，宁可只报「L2 可用」。

---

## 阶段 3：触摸 HID

Novatek NT36672C over SPI，RST GPIO50 / IRQ GPIO24。R77 已经把 GENI 引擎路径
换成 bit-bang 传输，两次读到同一签名 `0c 00 00 72 66 03`。**还差的是把它
变成 HID 设备** —— 走 IOHIDFamily，产出 `IOHIDEventDriver` 那样的事件，
让 iOS 把它认成触摸屏。

16.5 的 profile 里 `roots` 有 `com.apple.iokit.IOHIDFamily`（17.7.11 也有
`IOHIDEventDriver`），所以用户态这一侧是有位置的。

---

## 阶段 4：存储（UFS LUN 4 选择器）

nio 是 6 个 LUN 的 UFS，userdata 在 **LUN 4（sde）**，而 umi 继承来的单 LUN
UFS 路径只认 LUN 0。缺一个 LUN 选择器，Data 卷就挂不上。这项不动也能进
用户态（mockfs 挂 RAMDisk 当 root），但要真正用上设备上的空间就得有它。

---

## 阶段 5：GPU 加速

探针的 mode 逐级往上抬，每级一个镜像，失败可归因：

| mode | 内容 |
|---|---|
| 8（现在） | 读 GCC/GPUCC/SMMU 状态 → GMU 时钟 → A650 冷启动（用 AOP 命令库建 HFI 表）→ GX 上电 → 读回 GX GDSC / RBBM_STATUS / 两个 GBIF halt 寄存器 |
| 9 | **首条 PM4 命令** |
| 10 | zap shader + GPU 中断 |
| 11 | 发布设备、打开 user client |

UEFI 侧（R117）已经量到的基线：GX 域与 GX 时钟上电（`P0=000000c0 →
P1=00000000`）、`GD=f8222800`、`RB=00000001`、`OI=80000001`、`DB=0c0330db`。
mode 8 要对的就是这些数。

**Metal 另算**：`NativeAdrenoAccelerator.cpp` 需要原版 `IOAcceleratorES`
类，而**这棵 XNU 树里根本没有 IOAcceleratorFamily2**。所以 Metal 不是一个
「mode 13」，而是要么移植 IOAccelerator 家族、要么另找图形栈出口。这是
GPU 阶段里最大的一块，建议排在 WiFi 与触摸之后。

---

## 施工原则

1. **一次只动一个变量。** 每个镜像只带一个改动，失败才能归因。
2. **先量再改。** 每个阶段先定「通过的读数是什么」，再动手。GPU 的
   `GD/RB/OI/DB`、显示的 `physical_base/width/height/row_bytes/depth`、
   WiFi 的 `firmware version / board ID` 都是这样定的。
3. **不注册假的服务。** 做不到就如实说做不到。
4. **固件侧与内核侧分开记账。** `nioPkg` 是另一个仓库，有自己的镜像与构建。

---

## 需要你拍板的三件事

1. **16.5 切换放在显示之前**（我的建议，显示的原始绑定一次做对）还是
   先在 17.7.11 上把显示做通、之后再切（多花一遍工作量，但 bring-up 基线
   不动）。
2. **WiFi 的目标深度**：只到「能上网」，还是也要蓝牙（蓝牙与 WiFi 共享电源
   与 CNSS，但 UART/HCI 是另一条线）。
3. **16.5 的 IO80211 缺口**：走「自建 ioctl 桥」这条重路，还是接受「先只到
   L2、系统集成后置」。
