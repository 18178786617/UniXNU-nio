# Why the build failed

run: 792, commit 94dd86b8c3b98b9c8b0a569734b95e8c7c3cf215

## ci-steps.log

### the tail

```
20:01:04 prepare: started in /Users/runner/work/UniXNU-nio/UniXNU-nio
20:01:04 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/mach.development.bcm2837.unstripped
20:01:04 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/link.filelist
20:01:04 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o
20:01:04 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/iokit/DEVELOPMENT/IOService.o
20:01:04 no build tree yet: out/nio/*/nio/tree/scripts/build-xnu-4k-baseline.sh absent
traced script start: scripts/build-xnu-4k-baseline.sh
traced before/after make: scripts/build-xnu-4k-baseline.sh
20:01:04 syntax ok: scripts/build-xnu-4k-baseline.sh
20:01:04 prepare: done
base=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio
record=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o.json exists=False
tree object=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o exists=False
no decodable compile record; nothing to replay
replay object missing=True
```

## replay.log

### the tail

```
base=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio
record=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o.json exists=False
tree object=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o exists=False
no decodable compile record; nothing to replay
replay object missing=True
```

## build-console.log

### the errors

```
69:unixnu: XNU patch /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu/exec-progress.patch: git failed (1): error: patch failed: bsd/kern/bsd_init.c:1349
70:error: bsd/kern/bsd_init.c: patch does not apply
```

### around them

```
61-== kernel: patch zzyb-native-cryptex-os-view.patch
62-== kernel: patch zzyc-owner-skip-launch-constraints.patch
63-== kernel: patch native-smp-secondary.patch
64-== kernel: patch native-smp-type-clusters.patch
65-== kernel: patch xnu-10063.141.1-security-init.patch
66-== kernel: patch xnu-10063.141.1-sparse-index.patch
67-== kernel: patch gpu-probe-start.patch
68-== kernel: patch exec-progress.patch
69:unixnu: XNU patch /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu/exec-progress.patch: git failed (1): error: patch failed: bsd/kern/bsd_init.c:1349
70:error: bsd/kern/bsd_init.c: patch does not apply
```

## status.txt

```
patch    35 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/offline-legacy-start.patch
patch    36 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/offline-native-gpu-broker.patch
patch    37 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/offline-owner-boot-manifest.patch
patch    38 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/offline-owner-cache-carrier.patch
patch    39 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/offline-owner-root-binding-audit.patch
patch    40 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/offline-owner-root-crypto-probe.patch
patch    41 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/offline-owner-systemos-mount.patch
patch    42 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/offline-owner-z-air-init.patch
patch    43 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/offline-pgz-alignment-probe.patch
patch    44 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/pgz-aligned-validation.patch
patch    45 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/public-entitlements-header.patch
patch    46 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/published-freezer-condition.patch
patch    47 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/source-corecrypto14-bootstrap.patch
patch    48 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/source-machine-layer.patch
patch    49 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/source-pthread-bootstrap.patch
patch    50 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/zzw-native-adreno-sandbox-grant.patch
patch    51 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/zzwb-native-sandbox-grant-set-properties.patch
patch    52 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/zzx-pmap-sync-64bit-pa.patch
patch    53 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/zzy-native-gpu-addon-mount.patch
patch    54 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/zzy-staged-system-apps.patch
patch    55 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/zzyb-native-cryptex-os-view.patch
patch    56 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/zzyc-owner-skip-launch-constraints.patch
patch    57 /Users/runner/work/UniXNU-nio/UniXNU-nio/out/feeds/UniXNU-sm8250-common-e8b46722/patches/xnu/native-smp-secondary.patch
patch    58 /Users/runner/work/UniXNU-nio/UniXNU-nio/out/feeds/UniXNU-sm8250-common-e8b46722/patches/xnu/native-smp-type-clusters.patch
patch    59 /Users/runner/work/UniXNU-nio/UniXNU-nio/kits/XnuPrelink/patches/xnu-10063.141.1-security-init.patch
patch    60 /Users/runner/work/UniXNU-nio/UniXNU-nio/kits/XnuPrelink/patches/xnu-10063.141.1-sparse-index.patch
patch    61 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu/gpu/gpu-probe-start.patch
patch    62 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu/exec-progress.patch
driver   AppleKeyStoreState       base
driver   ArmCpu                   base
driver   ArmDTPlatform            base
driver   GopFramebuffer           base
driver   NioUfs                   device
driver   RamBlock                 base
driver   SoftwareAES              base
driver   VirtioMmioBlock          base
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
patch    xnu-prelink              device
refer    AvailabilityVersions     git pinned 933f9360f1b7
refer    IOStorageFamily          git pinned e45fbe30a787
refer    corecrypto-2023          git pinned 11fba65b12d8
refer    edk2                     git pinned cfb93724a06f
refer    libdispatch              git pinned 30fe6a7d9453
refer    libplatform              git pinned a00a4cc36da2
refer    libpthread               git pinned c0e60fb5ecfc
refer    xnu                      git pinned d8b80295118e
refer    xnu-driverkit            git pinned 2c2f96dc2b9a
refer    xnu-trustcache           git pinned aca3beaa3dfb
soc      sm8250                   git pinned a6e7e36caab5
```
