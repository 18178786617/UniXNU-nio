# Why the build failed

run: 719, commit 33fb2cd1f62cc4b50407a92f7ff48b04e4492b70

## replay.log

### the tail

```
base=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio
record=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o.json exists=False
tree object=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o exists=False
no decodable compile record; nothing to replay
replay object missing=True
```

## ci-steps.log

### the tail

```
16:54:09 prepare: started in /Users/runner/work/UniXNU-nio/UniXNU-nio
16:54:09 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/mach.development.bcm2837.unstripped
16:54:09 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/link.filelist
16:54:09 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o
16:54:09 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/iokit/DEVELOPMENT/IOService.o
16:54:09 no build tree yet: out/nio/*/nio/tree/scripts/build-xnu-4k-baseline.sh absent
traced script start: scripts/build-xnu-4k-baseline.sh
traced before/after make: scripts/build-xnu-4k-baseline.sh
16:54:09 syntax ok: scripts/build-xnu-4k-baseline.sh
16:54:09 prepare: done
base=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio
record=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o.json exists=False
tree object=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o exists=False
no decodable compile record; nothing to replay
replay object missing=True
```

## kernel-bootstrap.log

### the tail

```
Restored 0 omitted public headers from Apple; blob hashes verified
Set XNU_OWNER_DATA_VOLUME_UUID to the actual observed scratch APFS volume UUID
build-xnu-4k-baseline.sh: line 480: python3 - "$OWNER_DATA_HEADER" "$OWNER_DATA_MOUNT" "$NATIVE_RAM_BLOCK" "${XNU_OWNER_DATA_VOLUME_UUID:-}" "${XNU_OWNER_CACHE_VOLUME_UUID:-}" "${XNU_OWNER_ROOT_VOLUME_UUID:-}" "$OWNER_BOOT_MANIFEST"  <<'PY_DATA_UUID'
from pathlib import Path
import sys
import uuid
path = Path(sys.argv[1])
text = '/* Scratch Data IOKit selection disabled. */\n'
if sys.argv[2:4] == ['1', '1']:
    try:
        value = str(uuid.UUID(sys.argv[4])).upper()
    except ValueError:
        raise SystemExit('Set XNU_OWNER_DATA_VOLUME_UUID to the actual observed scratch APFS volume UUID')
    text = '#define XNU_OWNER_DATA_VOLUME_UUID "' + value + '"\n'
# The SystemOS cryptex volume of this image; the sheng value stays the default of the patch.
cache = '8846FE78-2910-4297-AF97-D59BB6F8FC16'
if len(sys.argv) > 5 and sys.argv[5]:
    try:
        cache = str(uuid.UUID(sys.argv[5])).upper()
    except ValueError:
        raise SystemExit('Set XNU_OWNER_CACHE_VOLUME_UUID to the SystemOS volume UUID of the signed policy')
text += '#define XNU_OWNER_CACHE_VOLUME_UUID "' + cache + '"\n'
# The OS root volume of the boot manifest comes from the OS profile ([root] os_volume_uuid).
if len(sys.argv) > 6 and sys.argv[6]:
    try:
        text += '#define XNU_OWNER_ROOT_VOLUME_UUID "' + str(uuid.UUID(sys.argv[6])).upper() + '"\n'
    except ValueError:
        raise SystemExit('Set XNU_OWNER_ROOT_VOLUME_UUID to the OS volume UUID of the signed policy')
elif len(sys.argv) > 7 and sys.argv[7] == '1':
    raise SystemExit('The owner boot manifest needs XNU_OWNER_ROOT_VOLUME_UUID (OS profile [root] os_volume_uuid)')
path.parent.mkdir(parents=True, exist_ok=True)
if not path.exists() or path.read_text() != text:
    path.write_text(text)
PY_DATA_UUID
 failed
```

## xnu-trace.log

### the tail

```
[16:54:26] script start (bootstrap=1 jobs=4)
  object MISSING
  source sha 80c4cc3b5db23f09
[16:57:15] script start (bootstrap=1 jobs=4)
  object MISSING
  source sha 80c4cc3b5db23f09
[16:57:39] script start (bootstrap=1 jobs=4)
  object MISSING
  source sha 80c4cc3b5db23f09
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
