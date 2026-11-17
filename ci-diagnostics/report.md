# Why the build failed

run: 454, commit 8ee1508a85a3b8a694fa42751e4c00d3e7c0e576

## qemu-run.log

### the tail

```
[32m==>[0m [1mFetching downloads for: [32mqemu[39m[0m
✔︎ Bottle Manifest capstone (5.0.9)
✔︎ Bottle Manifest libssh (0.12.2_1)
✔︎ Bottle Manifest libslirp (4.9.7)
✔︎ Bottle Manifest ncurses (6.6)
✔︎ Bottle Manifest snappy (1.3.1)
✔︎ Bottle Manifest vde (2.3.3)
✔︎ Bottle libslirp (4.9.7)
✔︎ Bottle capstone (5.0.9)
✔︎ Bottle libssh (0.12.2_1)
✔︎ Bottle snappy (1.3.1)
✔︎ Bottle vde (2.3.3)
✔︎ Bottle ncurses (6.6)
✔︎ Bottle qemu (11.1.3)
[32m==>[0m [1mInstalling dependencies for qemu:[0m [32mcapstone[39m, [32mlibslirp[39m, [32mlibssh[39m, [32mncurses[39m, [32msnappy[39m and [32mvde[39m[0m
[32m==>[0m [1mInstalling qemu dependency: [32mcapstone[39m (5.0.9)[0m
[34m==>[0m [1mPouring capstone--5.0.9.arm64_sequoia.bottle.tar.gz[0m
🍺  /opt/homebrew/Cellar/capstone/5.0.9: 31 files, 23.4MB
[32m==>[0m [1mInstalling qemu dependency: [32mlibslirp[39m (4.9.7)[0m
[34m==>[0m [1mPouring libslirp--4.9.7.arm64_sequoia.bottle.tar.gz[0m
🍺  /opt/homebrew/Cellar/libslirp/4.9.7: 13 files, 433.4KB
[32m==>[0m [1mInstalling qemu dependency: [32mlibssh[39m (0.12.2_1)[0m
[34m==>[0m [1mPouring libssh--0.12.2_1.arm64_sequoia.bottle.tar.gz[0m
🍺  /opt/homebrew/Cellar/libssh/0.12.2_1: 25 files, 1.7MB
[32m==>[0m [1mInstalling qemu dependency: [32mncurses[39m (6.6)[0m
[34m==>[0m [1mPouring ncurses--6.6.arm64_sequoia.bottle.tar.gz[0m
🍺  /opt/homebrew/Cellar/ncurses/6.6: 4,086 files, 10.3MB
[32m==>[0m [1mInstalling qemu dependency: [32msnappy[39m (1.3.1)[0m
[34m==>[0m [1mPouring snappy--1.3.1.arm64_sequoia.bottle.tar.gz[0m
🍺  /opt/homebrew/Cellar/snappy/1.3.1: 20 files, 171.6KB
[32m==>[0m [1mInstalling qemu dependency: [32mvde[39m (2.3.3)[0m
[34m==>[0m [1mPouring vde--2.3.3.arm64_sequoia.bottle.tar.gz[0m
🍺  /opt/homebrew/Cellar/vde/2.3.3: 67 files, 1.2MB
[32m==>[0m [1mInstalling [32mqemu[39m[0m
[34m==>[0m [1mPouring qemu--11.1.3.arm64_sequoia.bottle.tar.gz[0m
🍺  /opt/homebrew/Cellar/qemu/11.1.3: 170 files, 729MB
QEMU emulator version 11.1.3
wrote out/qemu/kernel.adt (12444 bytes) from nio-qemu-hardware.json
cmdline: -v keepsyms=1 kt_fixed_zones=120 nio-gpu=8 native-ufs-root=1 native-ufs-probe=12 native-ufs-diagnostics=1 nio_skip_security_extensions=1 unentitled_ios_sim_launch=1 ignition_level=1 launchd_unsecure_cache=1 -wdt_no_pmu wdt=-1 wdt_test=no_user_checkin amfi_get_out_of_my_way=1 amfi_allow_any_signature=1
no kernel.macho to boot in QEMU
```

## ci-steps.log

### the tail

```
08:34:10 prepare: started in /Users/runner/work/UniXNU-nio/UniXNU-nio
08:34:10 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/mach.development.bcm2837.unstripped
08:34:10 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/link.filelist
08:34:10 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o
08:34:10 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/iokit/DEVELOPMENT/IOService.o
traced script start: scripts/build-xnu-4k-baseline.sh
traced before/after make: scripts/build-xnu-4k-baseline.sh
08:34:10 syntax ok: scripts/build-xnu-4k-baseline.sh
08:34:10 script absent: out/nio/ios-16.5-20F66/nio/tree/scripts/build-xnu-4k-baseline.sh
08:34:10 prepare: done
base=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio
record=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o.json exists=False
tree object=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o exists=False
no decodable compile record; nothing to replay
replay object missing=True
```

## replay.log

### the tail

```
base=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio
record=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o.json exists=False
tree object=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o exists=False
no decodable compile record; nothing to replay
replay object missing=True
```

## build-console.log

### the errors

```
172:unixnu: XNU patch /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-path-probe.patch: git failed (128): error: patch fragment without header at /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-path-probe.patch:50: @@ -5326,6 +5326,8 @@
```

### around them

```
164-== kernel: patch nio-name-six-and-match-rounds.patch
165-== kernel: patch nio-arbitration-out-of-path.patch
166-== kernel: patch nio-probe-entry-marks.patch
167-== kernel: patch nio-skip-unmatched-classes.patch
168-== kernel: patch nio-busy-beacon.patch
169-== kernel: patch nio-static-kext-personalities.patch
170-== kernel: patch nio-device-tree-slide-fix.patch
171-== kernel: patch nio-match-path-probe.patch
172:unixnu: XNU patch /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-path-probe.patch: git failed (128): error: patch fragment without header at /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-path-probe.patch:50: @@ -5326,6 +5326,8 @@
```

## status.txt

```
patch    135 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-manifest-properties-shim.patch
patch    136 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-probe-candidates-exit.patch
patch    137 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-startmatching-probe.patch
patch    138 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-doservicematch-probe.patch
patch    139 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-startmatching-steps.patch
patch    140 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-arbitration-recursive.patch
patch    141 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-probe-result.patch
patch    142 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-no-class-candidate.patch
patch    143 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-cpuic-matching.patch
patch    144 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-async-match-name.patch
patch    145 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-drop-reasons.patch
patch    146 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-loop-driver.patch
patch    147 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-iokit-match-return.patch
patch    148 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-stall-watchdog.patch
patch    149 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-direct-console-heartbeat.patch
patch    150 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-stall-framebuffer-message.patch
patch    151 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-heartbeat-noinline.patch
patch    152 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-arbitration-probe-decl.patch
patch    153 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-arbitration-unlock-probe.patch
patch    154 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-arbitration-probe-u3.patch
patch    155 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-start-name-direct.patch
patch    156 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-arbitration-lock-probe.patch
patch    157 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-mark-service-seq.patch
patch    158 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-name-six-and-match-rounds.patch
patch    159 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-arbitration-out-of-path.patch
patch    160 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-probe-entry-marks.patch
patch    161 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-unmatched-classes.patch
patch    162 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-busy-beacon.patch
patch    163 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-static-kext-personalities.patch
patch    164 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-device-tree-slide-fix.patch
patch    165 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-path-probe.patch
driver   ArmCpu                   base
driver   ArmDTPlatform            base
driver   NioUfs                   device
driver   SoftwareAES              base
kit      AdrenoFirmware           base
kit      AdrenoPM4                base
kit      ArmSmmu4K                base
kit      VerifiedRoot             base
kit      XnuPrelink               base
package  device                   device
package  main                     base
patch    darwinboot               device
patch    libpthread               base
patch    mesa                     base
patch    xnu                      device
patch    xnu-12377                base
patch    xnu-8796                 device
patch    xnu-prelink              device
refer    AvailabilityVersions     git pinned 933f9360f1b7
refer    IOStorageFamily          git pinned e45fbe30a787
refer    corecrypto-2023          git pinned 11fba65b12d8
refer    edk2                     git pinned cfb93724a06f
refer    libdispatch              git pinned 30fe6a7d9453
refer    libplatform              git pinned a00a4cc36da2
refer    libpthread               git pinned c0e60fb5ecfc
refer    xnu                      git pinned aca3beaa3dfb
refer    xnu-driverkit            git pinned 2c2f96dc2b9a
refer    xnu-trustcache           git pinned aca3beaa3dfb
soc      sm8250                   git pinned a6e7e36caab5
```
