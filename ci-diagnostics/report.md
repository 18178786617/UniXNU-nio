# Why the build failed

run: 777, commit 1ebed603d955f57588cd881c1974f41faaa25aa7

## replay.log

### the tail

```
base=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio
record=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o.json exists=True
tree object=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o exists=False
recorded file=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/osfmk/kern/startup.c output=startup.o
replaying 459 arguments in /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT
replay rc=0
preprocess rc=0
preprocessed bytes=1410883 has HB=False
preprocessed bytes=1410883 has hb-started=False
replay object missing=False
assembly rc=0
assembly lines=28569 has HB=False
assembly calls to nio_dc_puts=0
  asm: no _nio_heartbeat_thread label
```

## ci-steps.log

### the tail

```
13:04:23 prepare: started in /Users/runner/work/UniXNU-nio/UniXNU-nio
13:04:23 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/mach.development.bcm2837.unstripped
13:04:23 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/link.filelist
13:04:23 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o
13:04:23 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/iokit/DEVELOPMENT/IOService.o
13:04:23 no build tree yet: out/nio/*/nio/tree/scripts/build-xnu-4k-baseline.sh absent
traced script start: scripts/build-xnu-4k-baseline.sh
traced before/after make: scripts/build-xnu-4k-baseline.sh
13:04:23 syntax ok: scripts/build-xnu-4k-baseline.sh
13:04:23 prepare: done
base=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio
record=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o.json exists=True
tree object=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o exists=False
recorded file=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/osfmk/kern/startup.c output=startup.o
replaying 459 arguments in /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT
replay rc=0
preprocess rc=0
preprocessed bytes=1410883 has HB=False
preprocessed bytes=1410883 has hb-started=False
replay object missing=False
assembly rc=0
assembly lines=28569 has HB=False
assembly calls to nio_dc_puts=0
  asm: no _nio_heartbeat_thread label
```

## archive-01-build-corecrypto-14.log

### the tail

```
529 kernel C sources; 0 failures
No XNU symbol names: run a kernel pass first (it writes link.filelist)
```

## storage-headers.log

### the tail

```
PASS: 19 public IOStorageFamily headers prepared at e45fbe30a7879e0b16e26dddb78538f1b00e0bff
```

## kernel.log

### the tail

```
Restored 0 omitted public headers from Apple; blob hashes verified
Traceback (most recent call last):
  File "<stdin>", line 3, in <module>
  File "/Library/Frameworks/Python.framework/Versions/3.13/lib/python3.13/pathlib/_local.py", line 546, in read_text
    return PathBase.read_text(self, encoding, errors, newline)
           ~~~~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/Library/Frameworks/Python.framework/Versions/3.13/lib/python3.13/pathlib/_abc.py", line 632, in read_text
    with self.open(mode='r', encoding=encoding, errors=errors, newline=newline) as f:
         ~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/Library/Frameworks/Python.framework/Versions/3.13/lib/python3.13/pathlib/_local.py", line 537, in open
    return io.open(self, mode, buffering, encoding, errors, newline)
           ~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
FileNotFoundError: [Errno 2] No such file or directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/native-legacy-display/build-report.json'
build-xnu-4k-baseline.sh: line 802: python3 - "$LEGACY_DISPLAY_ARCHIVE" "$ROOT"  <<'PY_LEGACY_DISPLAY'
import hashlib, json, sys
from pathlib import Path
archive=Path(sys.argv[1]);root=Path(sys.argv[2]);report=json.loads(archive.with_name('build-report.json').read_text())
if hashlib.sha256(archive.read_bytes()).hexdigest()!=report['archive_sha256']:
    raise SystemExit('Rebuild and qualify the exact owned Legacy archive before linking')
for name,digest in report['source_sha256'].items():
    if hashlib.sha256((root/name).read_bytes()).hexdigest()!=digest:
        raise SystemExit('Rebuild the owned Legacy archive after changing '+name)
PY_LEGACY_DISPLAY
 failed
```

## xnu-trace.log

### the tail

```
[13:04:44] script start (bootstrap=1 jobs=4)
  object MISSING
  source sha 80c4cc3b5db23f09
[13:07:23] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha 80c4cc3b5db23f09
[13:18:19] script start (bootstrap=0 jobs=4)
  object MISSING
  source sha 80c4cc3b5db23f09
```

## archive-21-build-usb-debug.log

### the tail

```
PASS: 2 USB debug objects archived at /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/usbdebug/libUsbDebug.a
PASS: libUsbDebug.a symbols resolved
```

## archive-20-build-verified-root.log

### the tail

```
PASS: real VerifiedRoot crypto + empty policy table -> libVerifiedRoot.a
      root verification is disabled: no signed policy bundle exists for this board
PASS: DEVELOPMENT_ARM64_BCM2837 holds 888 .o, 123 .cpo, 0 archives, 9 file lists, core absent
PASS: DEVELOPMENT_ARM64_BCM2837 holds 0 .o, 0 .cpo, 0 archives, 0 file lists, core absent
PASS: removed the core image, the file lists and 1021 build products
PASS: 86 patched sources carry a fresh mtime (1 named by git but not on disk)
  bsd/kern/bsd_init.c: mtime 13:18:16, does NOT carry 'nio: bsd_init:'
  iokit/Kernel/IOService.cpp: mtime 13:18:16, does NOT carry 'nio: S1'
  bsd/kern/kern_exec.c: mtime 13:18:16, does NOT carry 'nio: exec: load_init_program enter'
```

## archive-19-build-storage-bindings.log

### the tail

```
0000000000002bb8 T _native_ram_block_gpu_addon
0000000000040850 S _native_ram_block_reads
0000000000040840 S _native_ram_block_ready
0000000000040868 S _native_ram_block_resident_bytes
0000000000040874 S _native_ram_block_seed_sha256
0000000000040870 S _native_ram_block_sparse
000000000000269c T _native_ram_block_volume_device
0000000000002d20 T _native_ram_block_volume_seed
0000000000040858 S _native_ram_block_writes
                 U _native_ufs_store_gpt_check
                 U _native_ufs_store_mode
                 U _native_ufs_store_open
                 U _native_ufs_store_read
                 U _native_ufs_store_sync
                 U _native_ufs_store_write
                 U _snprintf
                 U _strcmp
                 U _strlcpy
                 U _strlen

original-bindings.o:
fffffff006add1d0 A __ZN20IOBlockStorageDevice10gMetaClassE
fffffff00496f050 A __ZN20IOBlockStorageDevice11requestIdleEv
fffffff00496f068 A __ZN20IOBlockStorageDevice13doSetPriorityEP26IOBlockStorageDeviceExtentjh
fffffff00496f080 A __ZN20IOBlockStorageDevice13doSynchronizeEyyj
fffffff00496ef38 A __ZN20IOBlockStorageDevice13setPropertiesEP8OSObject
fffffff00496f074 A __ZN20IOBlockStorageDevice18doSynchronizeCacheEv
fffffff00496f038 A __ZN20IOBlockStorageDevice18getWriteCacheStateEPb
fffffff00496f044 A __ZN20IOBlockStorageDevice18setWriteCacheStateEb
fffffff00496f08c A __ZN20IOBlockStorageDevice20doGetProvisionStatusEyyPjP35IOBlockStorageProvisionDeviceExtenty
fffffff00496ee30 A __ZN20IOBlockStorageDevice4initEP12OSDictionary
fffffff00496f05c A __ZN20IOBlockStorageDevice7doUnmapEP26IOBlockStorageDeviceExtentjj
fffffff005cb44b0 A __ZN20IOBlockStorageDevice9metaClassE
fffffff00496ed98 A __ZN20IOBlockStorageDeviceC1EPK11OSMetaClass
fffffff00496ed98 A __ZN20IOBlockStorageDeviceC2EPK11OSMetaClass
fffffff00496edb8 A __ZN20IOBlockStorageDeviceD2Ev
fffffff00496ee88 A __ZNK20IOBlockStorageDevice11getPropertyEPK8OSSymbol
fffffff00496edc4 A __ZNK20IOBlockStorageDevice12getMetaClassEv
fffffff005cb44c0 A __ZTV20IOBlockStorageDevice

```

## component-RamBlock.log

### the tail

```
RamBlock: -Werror build and arm64-apple-ios17.0 object audit passed
```

## archive-17-build-storage-bindings.log

### the tail

```
                 U __ZNK9IOService9getClientEv
00000000000010b8 S __ZTV17NativeVirtioBlock
                 U __ZTV20IOBlockStorageDevice
00000000000016c0 S __ZTVN17NativeVirtioBlock9MetaClassE
                 U _bzero
                 U _clock_interval_to_deadline
                 U _kernel_task
                 U _lck_mtx_lock
                 U _lck_mtx_unlock
                 U _mach_absolute_time
                 U _memcmp
000000000002c158 S _native_virtio_first_sector_sha256
000000000002c150 S _native_virtio_mmio_physical
0000000000000000 T _native_virtio_read_checkpoint
000000000002c140 S _native_virtio_read_failures
000000000002c13c S _native_virtio_read_requests
000000000002c138 S _native_virtio_ready
000000000002c148 S _native_virtio_sectors
                 U _panic

original-bindings.o:
fffffff006add1d0 A __ZN20IOBlockStorageDevice10gMetaClassE
fffffff00496f050 A __ZN20IOBlockStorageDevice11requestIdleEv
fffffff00496f068 A __ZN20IOBlockStorageDevice13doSetPriorityEP26IOBlockStorageDeviceExtentjh
fffffff00496f080 A __ZN20IOBlockStorageDevice13doSynchronizeEyyj
fffffff00496ef38 A __ZN20IOBlockStorageDevice13setPropertiesEP8OSObject
fffffff00496f074 A __ZN20IOBlockStorageDevice18doSynchronizeCacheEv
fffffff00496f038 A __ZN20IOBlockStorageDevice18getWriteCacheStateEPb
fffffff00496f044 A __ZN20IOBlockStorageDevice18setWriteCacheStateEb
fffffff00496f08c A __ZN20IOBlockStorageDevice20doGetProvisionStatusEyyPjP35IOBlockStorageProvisionDeviceExtenty
fffffff00496ee30 A __ZN20IOBlockStorageDevice4initEP12OSDictionary
fffffff00496f05c A __ZN20IOBlockStorageDevice7doUnmapEP26IOBlockStorageDeviceExtentjj
fffffff005cb44b0 A __ZN20IOBlockStorageDevice9metaClassE
fffffff00496ed98 A __ZN20IOBlockStorageDeviceC1EPK11OSMetaClass
fffffff00496ed98 A __ZN20IOBlockStorageDeviceC2EPK11OSMetaClass
fffffff00496edb8 A __ZN20IOBlockStorageDeviceD2Ev
fffffff00496ee88 A __ZNK20IOBlockStorageDevice11getPropertyEPK8OSSymbol
fffffff00496edc4 A __ZNK20IOBlockStorageDevice12getMetaClassEv
fffffff005cb44c0 A __ZTV20IOBlockStorageDevice

```

## component-VirtioMmioBlock.log

### the tail

```
VirtioMmioBlock: -Werror build and arm64-apple-ios17.0 object audit passed
```

## archive-15-build-storage-bindings.log

### the tail

```
PASS: libStorageBindings.a -> 18 absolute bindings over 14 kext-owned slots (com.apple.iokit.IOStorageFamily)
    __ZN20IOBlockStorageDevice10gMetaClassE -> 0xfffffff006add1d0
    __ZN20IOBlockStorageDevice11requestIdleEv -> 0xfffffff00496f050
    __ZN20IOBlockStorageDevice13doSetPriorityEP26IOBlockStorageDeviceExtentjh -> 0xfffffff00496f068
    __ZN20IOBlockStorageDevice13doSynchronizeEyyj -> 0xfffffff00496f080
    __ZN20IOBlockStorageDevice13setPropertiesEP8OSObject -> 0xfffffff00496ef38
    __ZN20IOBlockStorageDevice18doSynchronizeCacheEv -> 0xfffffff00496f074
    __ZN20IOBlockStorageDevice18getWriteCacheStateEPb -> 0xfffffff00496f038
    __ZN20IOBlockStorageDevice18setWriteCacheStateEb -> 0xfffffff00496f044
    __ZN20IOBlockStorageDevice20doGetProvisionStatusEyyPjP35IOBlockStorageProvisionDeviceExtenty -> 0xfffffff00496f08c
    __ZN20IOBlockStorageDevice4initEP12OSDictionary -> 0xfffffff00496ee30
    __ZN20IOBlockStorageDevice7doUnmapEP26IOBlockStorageDeviceExtentjj -> 0xfffffff00496f05c
    __ZN20IOBlockStorageDevice9metaClassE -> 0xfffffff005cb44b0
    __ZN20IOBlockStorageDeviceC1EPK11OSMetaClass -> 0xfffffff00496ed98
    __ZN20IOBlockStorageDeviceC2EPK11OSMetaClass -> 0xfffffff00496ed98
    __ZN20IOBlockStorageDeviceD2Ev -> 0xfffffff00496edb8
    __ZNK20IOBlockStorageDevice11getPropertyEPK8OSSymbol -> 0xfffffff00496ee88
    __ZNK20IOBlockStorageDevice12getMetaClassEv -> 0xfffffff00496edc4
    __ZTV20IOBlockStorageDevice -> 0xfffffff005cb44c0

original-bindings.o:
fffffff006add1d0 A __ZN20IOBlockStorageDevice10gMetaClassE
fffffff00496f050 A __ZN20IOBlockStorageDevice11requestIdleEv
fffffff00496f068 A __ZN20IOBlockStorageDevice13doSetPriorityEP26IOBlockStorageDeviceExtentjh
fffffff00496f080 A __ZN20IOBlockStorageDevice13doSynchronizeEyyj
fffffff00496ef38 A __ZN20IOBlockStorageDevice13setPropertiesEP8OSObject
fffffff00496f074 A __ZN20IOBlockStorageDevice18doSynchronizeCacheEv
fffffff00496f038 A __ZN20IOBlockStorageDevice18getWriteCacheStateEPb
fffffff00496f044 A __ZN20IOBlockStorageDevice18setWriteCacheStateEb
fffffff00496f08c A __ZN20IOBlockStorageDevice20doGetProvisionStatusEyyPjP35IOBlockStorageProvisionDeviceExtenty
fffffff00496ee30 A __ZN20IOBlockStorageDevice4initEP12OSDictionary
fffffff00496f05c A __ZN20IOBlockStorageDevice7doUnmapEP26IOBlockStorageDeviceExtentjj
fffffff005cb44b0 A __ZN20IOBlockStorageDevice9metaClassE
fffffff00496ed98 A __ZN20IOBlockStorageDeviceC1EPK11OSMetaClass
fffffff00496ed98 A __ZN20IOBlockStorageDeviceC2EPK11OSMetaClass
fffffff00496edb8 A __ZN20IOBlockStorageDeviceD2Ev
fffffff00496ee88 A __ZNK20IOBlockStorageDevice11getPropertyEPK8OSSymbol
fffffff00496edc4 A __ZNK20IOBlockStorageDevice12getMetaClassEv
fffffff005cb44c0 A __ZTV20IOBlockStorageDevice

```

## archive-14-build-nio-ufs-archive.log

### the tail

```
nio-ufs: build/nio-ufs/libNioUfs.a -> build/sheng-ufs/libShengUfs.a (505272 bytes, sha256 e13b40bb8b9d51d22c2b89115f54120bbc6a9baed625c21dff3226b65c9af404)
```

## component-NioUfs.log

### the tail

```
NioUfs: -Werror build and arm64-apple-ios17.0 object audit passed
```

## archive-12-build-link-stubs.log

### the tail

```
compiled LinkStubs.c (legacy display 1, mobile display 0, deployment 17.0)
  _boot_log_export_put         T
  _native_gpu_dcvs             D
  _native_pmap_user_mappings   T
  _qcom_usb_debug_write        T
PASS: 4 link stubs archived in /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/link-stubs/libLinkStubs.a
```

## archive-11-build-gop-legacy-display.log

### the tail

```
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/kits/nio/LegacyDisplayProbe.cpp:629:78: warning: implicit conversion loses integer precision: 'uint64_t' (aka 'unsigned long long') to 'uint32_t' (aka 'unsigned int') [-Wshorten-64-to-32]
  629 |         native_legacy_reached_geometry = ((uint64_t)rowbytes << 32) | (width << 16) | (height & 0xFFFF);
      |                                        ~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/kits/nio/LegacyDisplayProbe.cpp:1173:12: warning: declaration shadows a local variable [-Wshadow]
 1173 |                                                 bool attached = false;
      |                                                      ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/kits/nio/LegacyDisplayProbe.cpp:1094:48: note: previous declaration is here
 1094 |         bool nubAttached = false, nubStarted = false, attached = false, started = false;
      |                                                       ^
2 warnings generated.
NativeLegacyDisplay: -Werror build and arm64-apple-ios17.0 object audit passed
NativeGOPPresenter: -Werror build and arm64-apple-ios17.0 object audit passed
PASS: built nio display archive /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/native-legacy-display/libNativeLegacyDisplay.late.a (964648 bytes)
```

## component-AppleKeyStoreState.log

### the tail

```
AppleKeyStoreState: -Werror build and arm64-apple-ios17.0 object audit passed
```

## archive-09-build-adreno650.log

### the tail

```
note: -Wno-unnecessary-virtual-specifier is not known to this clang, not passing it
PASS: 31 NativeAdreno a650 objects archived
PASS: archive verified with 31 objects
```

## archive-08-build-libpthread-kernel.log

### the tail

```
Cloning into '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/libpthread-work'...
every callback the sources call has the name this XNU tree uses
Matching libpthread: 3 real C sources + bootstrap, ARM64/iOS 17 audit, no unavailable kernel names
```

## archive-07-build-mockfs-fixture.log

### the tail

```
3 XNU mockfs sources compiled (typed-allocation correction retained); ordinary ARM64 / iOS 17 audited
Offline minimal-root fixture only; not an APFS driver or iPadOS filesystem
```

## archive-06-build-software-aes-bindings.log

### the tail

```
PASS: native AES bound with the recorded original-kernelcache addresses
```

## component-SoftwareAES.log

### the tail

```
SoftwareAES: -Werror build and arm64-apple-ios17.0 object audit passed
```

## component-ArmCpu.log

### the tail

```
ArmCpu: -Werror build and arm64-apple-ios17.0 object audit passed
```

## component-ArmDTPlatform.log

### the tail

```
ArmDTPlatform: -Werror build and arm64-apple-ios17.0 object audit passed
```

## archive-02-build-corecrypto-14.log

### the tail

```
529 kernel C sources; 0 failures
Internal unregistered provider archive: libcorecrypto_kernel_noasm-namespaced.a
External names absent from kernel: []
Globals shared with kernel: 0; initialization and intact selftests are still required
```

## kernel-bootstrap.log

### the errors

```
4581: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
4587: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
94445: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
94456: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
94467: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
94478: 1413 |                     "| error: latency %d too big (> 1 sec)",
94489: 1420 |                     "| error: jitter %dms too big (latency %dms)",
94500: 1420 |                     "| error: jitter %dms too big (latency %dms)",
94511: 1438 |                     "| error: loss recovery %dms too big",
94522: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
94533: 1463 |                     "| error: output interval %dms too big",
165134: 3406 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
165140: 3411 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
196611: 1384 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
201143:  158 |                 printf("buffer_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
201616:  268 |                 printf("(%s) Failed to handle availability of LZ4. Error 0x%x\n", __func__, ret);
202040:  102 |                 printf("progress_notify_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
202486:  272 |                 printf("zlib_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
202700:  143 |                 printf("%s failed to allocate memory. Error 0x%x\n", __func__, ret);
264327:Undefined symbols for architecture arm64:
264352:ld: symbol(s) not found for architecture arm64
264353:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
264354:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped.noctf] Error 1
264355:make[2]: *** [build_all] Error 2
264356:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
264357:make: *** [build] Error 2
```

### around them

```
4575- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
4576-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
4577-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:597:27: note: expanded from macro 'panic'
4578-  597 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
4579-      |                 ~~               ^~~~~~~~~~~
4580-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
4581: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
4582-      |                                                                                ~~~
4583-      |                                                                                %zu
4584- 1414 |                                             path, mc_error, fatal_failure_desc_len);
4585-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
4586-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
4587: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
4588-      |                                                                                                   ~~~
4589-      |                                                                                                   %zu
4590- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
4591-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
4592-3 warnings generated.
4593-             CC mac_vfs_subr.o
4594-clang: warning: no such include directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa' [-Wmissing-include-dirs]
4595-             CC mac_skywalk.o
4596-clang: warning: no such include directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa' [-Wmissing-include-dirs]
4597-             CC mac_system.o
--
94439- 1303 |         _CASSERT(IF_NETEM_MODEL_NLC == NETEM_MODEL_NLC);
94440-      |                  ~~~~~~~~~~~~~~~~~~ ^  ~~~~~~~~~~~~~~~
94441-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/sys/mcache.h:65:40: note: expanded from macro '_CASSERT'
94442-   65 | #define _CASSERT(x)     _Static_assert(x, "compile-time assertion failed")
94443-      |                                        ^
94444-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1387:7: warning: format specifies type 'int' but the argument has underlying type 'unsigned int' [-Wformat]
94445: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
94446-      |                                                                      ~~
94447-      |                                                                      %u
94448- 1387 |                     p->ifnetem_model);
94449-      |                     ^~~~~~~~~~~~~~~~
94450-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
94451-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
94452-      |                                                    ~~~~
94453-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
94454-      |                                             ^~~~~~~~~~~
94455-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1393:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
94456: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
94457-      |                                                           ~~
94458-      |                                                           %u
94459- 1393 |                     p->ifnetem_corruption_p, NETEM_PSCALE);
94460-      |                     ^~~~~~~~~~~~~~~~~~~~~~~
94461-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
94462-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
94463-      |                                                    ~~~~
94464-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
94465-      |                                             ^~~~~~~~~~~
94466-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1399:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
94467: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
94468-      |                                                            ~~
94469-      |                                                            %u
94470- 1399 |                     p->ifnetem_duplication_p, NETEM_PSCALE);
94471-      |                     ^~~~~~~~~~~~~~~~~~~~~~~~
94472-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
94473-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
94474-      |                                                    ~~~~
94475-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
94476-      |                                             ^~~~~~~~~~~
94477-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1414:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
94478: 1413 |                     "| error: latency %d too big (> 1 sec)",
94479-      |                                       ~~
94480-      |                                       %u
94481- 1414 |                     p->ifnetem_latency_ms);
94482-      |                     ^~~~~~~~~~~~~~~~~~~~~
94483-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
94484-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
94485-      |                                                    ~~~~
94486-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
94487-      |                                             ^~~~~~~~~~~
94488-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1421:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
94489: 1420 |                     "| error: jitter %dms too big (latency %dms)",
94490-      |                                      ~~
94491-      |                                      %u
94492- 1421 |                     p->ifnetem_jitter_ms, p->ifnetem_latency_ms);
94493-      |                     ^~~~~~~~~~~~~~~~~~~~
94494-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
94495-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
94496-      |                                                    ~~~~
94497-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
94498-      |                                             ^~~~~~~~~~~
94499-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1421:29: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
94500: 1420 |                     "| error: jitter %dms too big (latency %dms)",
94501-      |                                                            ~~
94502-      |                                                            %u
94503- 1421 |                     p->ifnetem_jitter_ms, p->ifnetem_latency_ms);
94504-      |                                           ^~~~~~~~~~~~~~~~~~~~~
94505-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
94506-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
94507-      |                                                    ~~~~
94508-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
94509-      |                                             ^~~~~~~~~~~
94510-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1439:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
94511: 1438 |                     "| error: loss recovery %dms too big",
94512-      |                                             ~~
94513-      |                                             %u
94514- 1439 |                     p->ifnetem_loss_recovery_ms);
94515-      |                     ^~~~~~~~~~~~~~~~~~~~~~~~~~~
94516-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
94517-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
94518-      |                                                    ~~~~
94519-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
94520-      |                                             ^~~~~~~~~~~
94521-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1457:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
94522: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
94523-      |                                                         ~~
94524-      |                                                         %u
94525- 1457 |                     p->ifnetem_reordering_p, NETEM_PSCALE);
94526-      |                     ^~~~~~~~~~~~~~~~~~~~~~~
94527-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
94528-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
94529-      |                                                    ~~~~
94530-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
94531-      |                                             ^~~~~~~~~~~
94532-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1464:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
94533: 1463 |                     "| error: output interval %dms too big",
94534-      |                                               ~~
```

### the tail

```
clang: warning: no such include directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa' [-Wmissing-include-dirs]
             CC nonlto.o
clang: warning: no such include directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa' [-Wmissing-include-dirs]
             CC version.o
clang: warning: no such include directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa' [-Wmissing-include-dirs]
             LD mach.development.bcm2837.unstripped.noctf
ld: warning: -new_linker is obsolete
ld: warning: search path '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/fakeroot/usr/local/lib/kernel/platform' not found
Undefined symbols for architecture arm64:
  "_native_gpu_probe", referenced from:
      _bsd_init in bsd_init.o
      _bsd_autoconf in bsd_init.o
  "_native_legacy_display_late_probe", referenced from:
      _bsd_init in bsd_init.o
      _bsd_autoconf in bsd_init.o
  "_native_legacy_display_probe", referenced from:
      _bsd_init in bsd_init.o
      _native_mobile_graphics_client_probe in IOUserClient.cpo
  "_native_ram_block_gpu_addon", referenced from:
      _native_gpu_addon_prepare in kern_exec.o
      _native_gpu_addon_prepare in kern_exec.o
  "_native_ram_block_volume_seed", referenced from:
      _load_init_program in kern_exec.o
  "_native_verified_block_manifest_sha384", referenced from:
      _native_owner_publish_boot_manifest in IOKitBSDInit.cpo
      _native_owner_publish_boot_manifest in IOKitBSDInit.cpo
  "_native_verified_block_root_authorized", referenced from:
      _bsd_init in bsd_init.o
      _load_init_program in kern_exec.o
      _load_init_program in kern_exec.o
      _load_init_program in kern_exec.o
  "_native_verified_block_volume_device", referenced from:
      _load_init_program in kern_exec.o
ld: symbol(s) not found for architecture arm64
clang++: error: linker command failed with exit code 1 (use -v to see invocation)
make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped.noctf] Error 1
make[2]: *** [build_all] Error 2
make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
make: *** [build] Error 2
build-xnu-4k-baseline.sh: line 887: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

## status.txt

```
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
patch    61 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu/gpu/gpu-probe-start.patch
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

## patch scope

```
```
