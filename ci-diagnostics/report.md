# Why the build failed

run: 718, commit 1be9bbd95336b3cd1a8d9e5ef4d8212696b49a7b

## ci-steps.log

### the tail

```
/Library/Frameworks/Python.framework/Versions/3.13/Resources/Python.app/Contents/MacOS/Python: can't open file '/Users/runner/work/UniXNU-nio/UniXNU-nio/tools/replay-compile.py': [Errno 2] No such file or directory
```

## kernel-bootstrap.log

### the tail

```
Restored 0 omitted public headers from Apple; blob hashes verified
NativeRamBlock requires the qualified original storage/AES prelink closure
```

## status.txt

```
patch    30 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/non-apple-cache-monitor.patch
patch    31 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/non-apple-iommu-bootstrap.patch
patch    32 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/non-apple-pmap-field.patch
patch    33 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/null-root-media.patch
patch    34 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/offline-component-load-probes.patch
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
refer    xnu                      git pinned d8b80295118e
refer    xnu-driverkit            git pinned 2c2f96dc2b9a
refer    xnu-trustcache           git pinned aca3beaa3dfb
soc      sm8250                   git pinned a6e7e36caab5
```

## patch scope

```
```
