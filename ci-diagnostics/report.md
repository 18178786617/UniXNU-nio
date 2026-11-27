# Why the build failed

run: 828, commit cafb9e5668c7170b85e720ec8d94f1cb93ad1906

## replay.log

### the tail

```
base=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio
record=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o.json exists=True
tree object=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o exists=True
recorded file=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/osfmk/kern/startup.c output=startup.o
replaying 452 arguments in /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT
replay rc=0
preprocess rc=0
preprocessed bytes=1410883 has HB=False
preprocessed bytes=1410883 has hb-started=False
replay bytes=113304 tree bytes=113304 identical=True
replay has HB=False tree has HB=False
object magic=cffaedfe
object nio contexts (12): [b'work/UniXNU-nio/UniXNU-nio/out/nio/i', b'-nio/UniXNU-nio/out/nio/ipados-17.7.', b'XNU-nio/out/nio/ipados-17.7.11-21H46', b'7.11-21H461/nio/tree/.cache/xnu-work', b'work/UniXNU-nio/UniXNU-nio/out/nio/i', b'-nio/UniXNU-nio/out/nio/ipados-17.7.', b'XNU-nio/out/nio/ipados-17.7.11-21H46', b'7.11-21H461/nio/tree/build/xnu/ios-o', b'work/UniXNU-nio/UniXNU-nio/out/nio/i', b'-nio/UniXNU-nio/out/nio/ipados-17.7.', b'XNU-nio/out/nio/ipados-17.7.11-21H46', b'7.11-21H461/nio/tree/build/xnu/ios-o']
object has leading-newline form=False
replay sha=df3530a2a04917b4 tree sha=df3530a2a04917b4
assembly rc=0
assembly lines=28499 has HB=False
assembly calls to nio_dc_puts=0
  asm: no _nio_heartbeat_thread label
```

## ci-steps.log

### the tail

```
12:25:11 prepare: started in /Users/runner/work/UniXNU-nio/UniXNU-nio
12:25:11 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/mach.development.bcm2837.unstripped
12:25:11 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/link.filelist
12:25:11 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o
12:25:11 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/iokit/DEVELOPMENT/IOService.o
12:25:11 no build tree yet: out/nio/*/nio/tree/scripts/build-xnu-4k-baseline.sh absent
traced script start: scripts/build-xnu-4k-baseline.sh
traced before/after make: scripts/build-xnu-4k-baseline.sh
12:25:11 syntax ok: scripts/build-xnu-4k-baseline.sh
12:25:11 prepare: done
base=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio
record=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o.json exists=True
tree object=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o exists=True
recorded file=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/osfmk/kern/startup.c output=startup.o
replaying 452 arguments in /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT
replay rc=0
preprocess rc=0
preprocessed bytes=1410883 has HB=False
preprocessed bytes=1410883 has hb-started=False
replay bytes=113304 tree bytes=113304 identical=True
replay has HB=False tree has HB=False
object magic=cffaedfe
object nio contexts (12): [b'work/UniXNU-nio/UniXNU-nio/out/nio/i', b'-nio/UniXNU-nio/out/nio/ipados-17.7.', b'XNU-nio/out/nio/ipados-17.7.11-21H46', b'7.11-21H461/nio/tree/.cache/xnu-work', b'work/UniXNU-nio/UniXNU-nio/out/nio/i', b'-nio/UniXNU-nio/out/nio/ipados-17.7.', b'XNU-nio/out/nio/ipados-17.7.11-21H46', b'7.11-21H461/nio/tree/build/xnu/ios-o', b'work/UniXNU-nio/UniXNU-nio/out/nio/i', b'-nio/UniXNU-nio/out/nio/ipados-17.7.', b'XNU-nio/out/nio/ipados-17.7.11-21H46', b'7.11-21H461/nio/tree/build/xnu/ios-o']
object has leading-newline form=False
replay sha=df3530a2a04917b4 tree sha=df3530a2a04917b4
assembly rc=0
assembly lines=28499 has HB=False
assembly calls to nio_dc_puts=0
  asm: no _nio_heartbeat_thread label
```

## archive-09-build-adreno650.log

### the tail

```
PASS: 32 NativeAdreno a650 objects archived
NativeAdreno symbols used but not built here: __GLOBAL__sub_I_NativeAdrenoAccelerator.cpp
```

## archive-08-build-libpthread-kernel.log

### the tail

```
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

## archive-01-build-corecrypto-14.log

### the tail

```
529 kernel C sources; 0 failures
Internal unregistered provider archive: libcorecrypto_kernel_noasm.a
External names absent from kernel: []
Globals shared with kernel: 63; initialization and intact selftests are still required
```

## storage-headers.log

### the tail

```
PASS: 19 public IOStorageFamily headers prepared at e45fbe30a7879e0b16e26dddb78538f1b00e0bff
```

## kernel-bootstrap.log

### the errors

```
4835: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
4841: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
96493: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
96504: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
96515: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
96526: 1413 |                     "| error: latency %d too big (> 1 sec)",
96537: 1420 |                     "| error: jitter %dms too big (latency %dms)",
96548: 1420 |                     "| error: jitter %dms too big (latency %dms)",
96559: 1438 |                     "| error: loss recovery %dms too big",
96570: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
96581: 1463 |                     "| error: output interval %dms too big",
169733: 3406 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
169739: 3411 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
255890: 1384 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
268322:  158 |                 printf("buffer_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
268833:  268 |                 printf("(%s) Failed to handle availability of LZ4. Error 0x%x\n", __func__, ret);
269299:  102 |                 printf("progress_notify_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
269787:  272 |                 printf("zlib_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
270022:  143 |                 printf("%s failed to allocate memory. Error 0x%x\n", __func__, ret);
346962:Undefined symbols for architecture arm64:
346987:ld: symbol(s) not found for architecture arm64
346988:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
346989:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped.noctf] Error 1
346990:make[2]: *** [build_all] Error 2
346991:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
346992:make: *** [build] Error 2
```

### around them

```
4829- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
4830-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
4831-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:597:27: note: expanded from macro 'panic'
4832-  597 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
4833-      |                 ~~               ^~~~~~~~~~~
4834-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
4835: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
4836-      |                                                                                ~~~
4837-      |                                                                                %zu
4838- 1414 |                                             path, mc_error, fatal_failure_desc_len);
4839-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
4840-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
4841: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
4842-      |                                                                                                   ~~~
4843-      |                                                                                                   %zu
4844- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
4845-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
4846-4 warnings generated.
4847-             CC mac_vfs_subr.o
4848-clang: warning: no such include directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa' [-Wmissing-include-dirs]
4849-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/security/mac_vfs_subr.c:29:
4850-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/vnode.h:893:
4851-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/vnode_if.h:85:
--
96487- 1302 |         _CASSERT(IF_NETEM_MODEL_NULL == NETEM_MODEL_NULL);
96488-      |                  ~~~~~~~~~~~~~~~~~~~ ^  ~~~~~~~~~~~~~~~~
96489-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1303:30: warning: comparison of different enumeration types ('if_netem_model_t' and 'netem_model_t') [-Wenum-compare]
96490- 1303 |         _CASSERT(IF_NETEM_MODEL_NLC == NETEM_MODEL_NLC);
96491-      |                  ~~~~~~~~~~~~~~~~~~ ^  ~~~~~~~~~~~~~~~
96492-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1387:7: warning: format specifies type 'int' but the argument has underlying type 'unsigned int' [-Wformat]
96493: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
96494-      |                                                                      ~~
96495-      |                                                                      %u
96496- 1387 |                     p->ifnetem_model);
96497-      |                     ^~~~~~~~~~~~~~~~
96498-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
96499-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
96500-      |                                                    ~~~~
96501-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
96502-      |                                             ^~~~~~~~~~~
96503-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1393:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
96504: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
96505-      |                                                           ~~
96506-      |                                                           %u
96507- 1393 |                     p->ifnetem_corruption_p, NETEM_PSCALE);
96508-      |                     ^~~~~~~~~~~~~~~~~~~~~~~
96509-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
96510-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
96511-      |                                                    ~~~~
96512-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
96513-      |                                             ^~~~~~~~~~~
96514-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1399:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
96515: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
96516-      |                                                            ~~
96517-      |                                                            %u
96518- 1399 |                     p->ifnetem_duplication_p, NETEM_PSCALE);
96519-      |                     ^~~~~~~~~~~~~~~~~~~~~~~~
96520-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
96521-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
96522-      |                                                    ~~~~
96523-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
96524-      |                                             ^~~~~~~~~~~
96525-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1414:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
96526: 1413 |                     "| error: latency %d too big (> 1 sec)",
96527-      |                                       ~~
96528-      |                                       %u
96529- 1414 |                     p->ifnetem_latency_ms);
96530-      |                     ^~~~~~~~~~~~~~~~~~~~~
96531-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
96532-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
96533-      |                                                    ~~~~
96534-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
96535-      |                                             ^~~~~~~~~~~
96536-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1421:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
96537: 1420 |                     "| error: jitter %dms too big (latency %dms)",
96538-      |                                      ~~
96539-      |                                      %u
96540- 1421 |                     p->ifnetem_jitter_ms, p->ifnetem_latency_ms);
96541-      |                     ^~~~~~~~~~~~~~~~~~~~
96542-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
96543-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
96544-      |                                                    ~~~~
96545-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
96546-      |                                             ^~~~~~~~~~~
96547-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1421:29: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
96548: 1420 |                     "| error: jitter %dms too big (latency %dms)",
96549-      |                                                            ~~
96550-      |                                                            %u
96551- 1421 |                     p->ifnetem_jitter_ms, p->ifnetem_latency_ms);
96552-      |                                           ^~~~~~~~~~~~~~~~~~~~~
96553-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
96554-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
96555-      |                                                    ~~~~
96556-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
96557-      |                                             ^~~~~~~~~~~
96558-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1439:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
96559: 1438 |                     "| error: loss recovery %dms too big",
96560-      |                                             ~~
96561-      |                                             %u
96562- 1439 |                     p->ifnetem_loss_recovery_ms);
96563-      |                     ^~~~~~~~~~~~~~~~~~~~~~~~~~~
96564-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
96565-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
96566-      |                                                    ~~~~
96567-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
96568-      |                                             ^~~~~~~~~~~
96569-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1457:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
96570: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
96571-      |                                                         ~~
96572-      |                                                         %u
96573- 1457 |                     p->ifnetem_reordering_p, NETEM_PSCALE);
96574-      |                     ^~~~~~~~~~~~~~~~~~~~~~~
96575-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
96576-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
96577-      |                                                    ~~~~
96578-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
96579-      |                                             ^~~~~~~~~~~
96580-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1464:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
96581: 1463 |                     "| error: output interval %dms too big",
96582-      |                                               ~~
```

### undefined symbols (kernel link)

```
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

### the tail

```
1 warning generated.
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

## xnu-trace.log

### the tail

```
[12:25:26] script start (bootstrap=1 jobs=3)
  object MISSING
  source sha 80c4cc3b5db23f09
[12:27:38] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha 80c4cc3b5db23f09
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
patch    62 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu/exec-wakeup-order.patch
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
