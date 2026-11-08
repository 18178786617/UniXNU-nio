# Why the build failed

run: 40, commit 7045e842853a6dba61ce2bfb03982a8fa45009ed

## kernel.log

### the errors

```
8007:Undefined symbols for architecture arm64:
8026:ld: symbol(s) not found for architecture arm64
8027:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
8028:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
8029:make[2]: *** [build_all] Error 2
8030:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
8031:make: *** [build] Error 2
```

### around them

```
8001-   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sun Nov  8 07:03:44 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
8002-      |            ^
8003-1 warning generated.
8004-             LD mach.development.bcm2837.unstripped
8005-ld: warning: -new_linker is obsolete
8006-ld: warning: search path '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot/usr/local/lib/kernel/platform' not found
8007:Undefined symbols for architecture arm64:
8008-  "IOUserBlockStorageDevice::Start_Impl(IOService*)", referenced from:
8009-      IOUserBlockStorageDevice::_Dispatch(IOUserBlockStorageDevice*, IORPC) in libIOStorageFamily.a[15](IOUserBlockStorageDevice.o)
8010-  "IOUserBlockStorageDevice::Complete_Impl(unsigned int, int)", referenced from:
8011-      IOUserBlockStorageDevice::_Dispatch(IOUserBlockStorageDevice*, IORPC) in libIOStorageFamily.a[15](IOUserBlockStorageDevice.o)
8012-  "IOUserBlockStorageDevice::StartDev_Impl(IOService*, DeviceParams const*)", referenced from:
8013-      IOUserBlockStorageDevice::_Dispatch(IOUserBlockStorageDevice*, IORPC) in libIOStorageFamily.a[15](IOUserBlockStorageDevice.o)
8014-  "IOUserBlockStorageDevice::CompleteIO_Impl(unsigned int, unsigned long long, int)", referenced from:
8015-      IOUserBlockStorageDevice::_Dispatch(IOUserBlockStorageDevice*, IORPC) in libIOStorageFamily.a[15](IOUserBlockStorageDevice.o)
8016-  "IOUserBlockStorageDevice::DoAsyncUnmap_Impl(unsigned int, IOMemoryDescriptor*, unsigned int)", referenced from:
8017-      IOUserBlockStorageDevice::_Dispatch(IOUserBlockStorageDevice*, IORPC) in libIOStorageFamily.a[15](IOUserBlockStorageDevice.o)
--
8021-      IOBlockStorageDriver::handleStart(IOService*) in libIOStorageFamily.a[5](IOBlockStorageDriver.o)
8022-  "IOUserBlockStorageDevice::Stop_Impl(IOService*)", referenced from:
8023-      IOUserBlockStorageDevice::_Dispatch(IOUserBlockStorageDevice*, IORPC) in libIOStorageFamily.a[15](IOUserBlockStorageDevice.o)
8024-  "IOUserBlockStorageDevice::metaClass", referenced from:
8025-      IOBlockStorageDriver::handleStart(IOService*) in libIOStorageFamily.a[5](IOBlockStorageDriver.o)
8026-ld: symbol(s) not found for architecture arm64
8027:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
8028-make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
8029-make[2]: *** [build_all] Error 2
8030-make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
8031-make: *** [build] Error 2
8032-build-xnu-4k-baseline.sh: line 829: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

### the tail

```
  336 |                 struct __tds {
      |                        ^
349 warnings generated.
     LDFILELIST bsd
     LDFILELIST osfmk
             CC version.o
clang: warning: no such include directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa' [-Wmissing-include-dirs]
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/version.c:39:12: warning: identifier '__kernelVersionString' is reserved because it starts with '__' [-Wreserved-identifier]
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sun Nov  8 07:03:44 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
      |            ^
1 warning generated.
             LD mach.development.bcm2837.unstripped
ld: warning: -new_linker is obsolete
ld: warning: search path '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot/usr/local/lib/kernel/platform' not found
Undefined symbols for architecture arm64:
  "IOUserBlockStorageDevice::Start_Impl(IOService*)", referenced from:
      IOUserBlockStorageDevice::_Dispatch(IOUserBlockStorageDevice*, IORPC) in libIOStorageFamily.a[15](IOUserBlockStorageDevice.o)
  "IOUserBlockStorageDevice::Complete_Impl(unsigned int, int)", referenced from:
      IOUserBlockStorageDevice::_Dispatch(IOUserBlockStorageDevice*, IORPC) in libIOStorageFamily.a[15](IOUserBlockStorageDevice.o)
  "IOUserBlockStorageDevice::StartDev_Impl(IOService*, DeviceParams const*)", referenced from:
      IOUserBlockStorageDevice::_Dispatch(IOUserBlockStorageDevice*, IORPC) in libIOStorageFamily.a[15](IOUserBlockStorageDevice.o)
  "IOUserBlockStorageDevice::CompleteIO_Impl(unsigned int, unsigned long long, int)", referenced from:
      IOUserBlockStorageDevice::_Dispatch(IOUserBlockStorageDevice*, IORPC) in libIOStorageFamily.a[15](IOUserBlockStorageDevice.o)
  "IOUserBlockStorageDevice::DoAsyncUnmap_Impl(unsigned int, IOMemoryDescriptor*, unsigned int)", referenced from:
      IOUserBlockStorageDevice::_Dispatch(IOUserBlockStorageDevice*, IORPC) in libIOStorageFamily.a[15](IOUserBlockStorageDevice.o)
  "IOUserBlockStorageDevice::RegisterDext_Impl()", referenced from:
      IOUserBlockStorageDevice::_Dispatch(IOUserBlockStorageDevice*, IORPC) in libIOStorageFamily.a[15](IOUserBlockStorageDevice.o)
  "IOUserBlockStorageDevice::getPerfControlClient()", referenced from:
      IOBlockStorageDriver::handleStart(IOService*) in libIOStorageFamily.a[5](IOBlockStorageDriver.o)
  "IOUserBlockStorageDevice::Stop_Impl(IOService*)", referenced from:
      IOUserBlockStorageDevice::_Dispatch(IOUserBlockStorageDevice*, IORPC) in libIOStorageFamily.a[15](IOUserBlockStorageDevice.o)
  "IOUserBlockStorageDevice::metaClass", referenced from:
      IOBlockStorageDriver::handleStart(IOService*) in libIOStorageFamily.a[5](IOBlockStorageDriver.o)
ld: symbol(s) not found for architecture arm64
clang++: error: linker command failed with exit code 1 (use -v to see invocation)
make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
make[2]: *** [build_all] Error 2
make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
make: *** [build] Error 2
build-xnu-4k-baseline.sh: line 829: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

## archive-13-build-storage-family.log

### the tail

```
PASS iig generated IOUserBlockStorageDevice.h (19416 bytes) and its implementation (101746 bytes)
PASS IOAppleLabelScheme (2 warnings)
PASS IOApplePartitionScheme (0 warnings)
PASS IOBlockStorageDevice (0 warnings)
PASS IOBlockStorageDriver (12 warnings)
PASS IOFDiskPartitionScheme (0 warnings)
PASS IOFilterScheme (0 warnings)
PASS IOGUIDPartitionScheme (0 warnings)
PASS IOMedia (0 warnings)
PASS IOMediaBSDClient (96 warnings)
PASS IOPartitionScheme (0 warnings)
PASS IORequest (0 warnings)
PASS IORequestsPool (0 warnings)
PASS IOStorage (1 warnings)
PASS IOUserBlockStorageDevice.iig (0 warnings)
PASS: 14 members, 3042392 bytes -> build/storage-family/libIOStorageFamily.a
```

## archive-12-build-nio-ufs-archive.log

### the tail

```
nio-ufs: build/nio-ufs/libNioUfs.a -> build/sheng-ufs/libShengUfs.a (454264 bytes, sha256 715731fa87e1f5b06d3637ee95a8d552f2691f278c3e776700df1d02e8176a90)
```

## component-NioUfs.log

### the tail

```
NioUfs: -Werror build and arm64-apple-ios17.0 object audit passed
```

## archive-10-build-link-stubs.log

### the tail

```
compiled LinkStubs.c (legacy display 0, mobile display 0, deployment 17.0)
  _boot_log_export_put         T
  _native_gop_handoff_call     T
  _native_gop_handoff_memory   T
  _native_gpu_dcvs             D
  _native_pmap_user_mappings   T
  _qcom_usb_debug_write        T
PASS: 6 link stubs archived in /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/link-stubs/libLinkStubs.a
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
Cloning into '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work'...
this XNU tree calls proc_get_pthread_jit_allowlist what the sources call proc_get_jit_entitled
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
Globals shared with kernel: 26; initialization and intact selftests are still required
```

## storage-headers.log

### the tail

```
PASS: 19 public IOStorageFamily headers prepared at e45fbe30a7879e0b16e26dddb78538f1b00e0bff
```

## kernel-bootstrap.log

### the errors

```
47000: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
58999: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
59005: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
630004:  158 |                 printf("buffer_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
673976:  NECPDATATRAitialize f 1902 | ailed tCELo allocate m        } __Reply__mach_portsOG(LOemory. Error 0x%xG_ERR, "DATA_regist-TRACE er_t __<\n", ret);
684459: 1492 |         } _/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h |         _Requestos_log_error:2572:4: warning: identifier '__Reply__task_set_exc_guard_behavior_t' is reserved because it starts with '__' [-Wreserved-identifier]
686614:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/libsa/types.h:os_log_error:29:
697227:  272 |                 printf("zlib_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
709136:  143 |                 prif/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/notify_server.h:212:4y_fonrm:att_stf("%s failed to allocate memory. Error 0x%x\n", __func__, ret);
728748:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/priority_queue.h:696 1049 |         os_log_error:81: note: (expanded from macro 'PRIORITY_QUEUE_MAKE'
764485:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/ticket_lock.h:36     error:
776660:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:2714:7 1049 |         os_log_error: warning: identifier '__ReplyUnion__task_subsystem' is reserved because it starts with '__' [-Wreserved-identifier](ne
804917: 1049 | n_str        os_llen(cons/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/cdefs.h:1090:12t char *og_error: note: expanded from macro '__container_of'
863540:host_get_io_m/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/arm/_types.hg_error:24(necp_log_handle,:33: warning: identifier '__int64_t' is reserved because it starts with '__' [-Wreserved-identifier]
908372:   74 |         /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic.h:80:65    o/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/thread_act.h:886s_l:4:og_ warning: identifier '__Request__thread_get_exception_ports_info_t' is reserved because it starts with '__' [-Wreserved-identifier]error: note: expanded from macro 'os_atomic_basetypeof'
1193127: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
1193138: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
1193152: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
1193163: 1413 |                     "| error: latency %d too big (> 1 sec)",
1193174: 1420 |                     "| error: jitter %dms too big (latency %dms)",
1193191: 1420 |                     "| error: jitter %dms too big (latency %dms)",
1193244: 1438 |                     "| error: loss recovery %dms too big",
1193255: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
1193266: 1463 |                     "| error: output interval %dms too big",
1489366: 2626 |                 FDLOG(LOG_ERR, fd_cb, "failed to get the close error: %d", error);
1492628: 3702 |                         FDLOG(LOG_ERR, fd_cb, "Failed to attach cfil: %d", error:49:
1494431:mbuf returned  486 | stru an error: %d", erct ror);__ke
1552914:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
1553053:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
1558233:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
1558245:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
1640205:  275 |         SASEL_LOG("Returned with error: %d", err);
2284497:  591 |         uint32_t                __msfr_alIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/posix_shm.c:ign52used mig_reply_error:
2292101: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
2292107: 3383 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
2323212:  602 |         int __pagein_error: note: expanded from macro 'os_log'
2772466:Undefined symbols for architecture arm64:
2772475:ld: symbol(s) not found for architecture arm64
2772476:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
2772477:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
```

### around them

```
46994- 1354 |                         IOLog("Failed to open corefile of size %llu MB (returned error 0x%x)\n",
46995-      |                                                                                          ~~
46996-      |                                                                                          %x
46997- 1355 |                             (corefile_fallback_size_bytes / (1024ULL * 1024ULL)), err);
46998-      |                                                                                   ^~~
46999-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1364:76: warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
47000: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
47001-      |                                                                                   ~~     ^~~
47002-      |                                                                                   %x
47003-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:203:2: warning: identifier '__dtrace_a0' is reserved because it starts with '__' [-Wreserved-identifier]
47004-  203 |         MAC_PERFORM(vnode_label_destroy, label);
47005-      |         ^
47006-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:313:10: note: expanded from macro 'MAC_PERFORM'
47007-  313 |                 MAC_PERFORM_CALL(operation, mpc);           \
47008-      |                 ^
47009-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:303:42: note: expanded from macro 'MAC_PERFORM_CALL'
47010-  303 | #define MAC_PERFORM_CALL(operation, mpc) DTRACE_MACF3(mac__call__ ## operation, void *, mpc, int, 0, int, MAC_ITERATE_PERFORM)
--
58993- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
58994-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
58995-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
58996-  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
58997-      |                 ~~               ^~~~~~~~~~~
58998-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
58999: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
59000-      |                                                                                ~~~
59001-      |                                                                                %zu
59002- 1414 |                                             path, mc_error, fatal_failure_desc_len);
59003-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
59004-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
59005: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
59006-      |                                                                                                   ~~~
59007-      |                                                                                                   %zu
59008- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
59009-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
59010-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
59011- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
59012-      |                             ^
59013-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
59014- 1426 |                 zfree(ZV_NAMEI, vn_path);
59015-      |                 ^
--
684453-bute__(((%d //Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.hunused :1492:4: ));
684454-      |           ^0x%X)>", \
684455-      |                                                                                                                                      ^~
684456-
684457-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:50: note: expanded from macro 'NECPDATATRACELOG'
684458- 1049warning: identifier '__Request__task_swap_mach_voucher_t' is reserved because it starts with '__' [-Wreserved-identifier]
684459: 1492 |         } _/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h |         _Requestos_log_error:2572:4: warning: identifier '__Reply__task_set_exc_guard_behavior_t' is reserved because it starts with '__' [-Wreserved-identifier]
684460- 2572 |         } __task_swap_ma__Reply__tas(necp_dk_set_eata_traxc_guarce_log_d_behavhandle, "%s:ch_vouc " formher_t _at "\n"_attribute__ior_t __attr, __FUNibute__C((unused));TION__,
684461-      |           ^
684462-((unused));
684463-      |           ^ __VA_ARGS__
684464-); \
684465-      |                                                         ^~~~~~
684466-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1502:4: warning: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:2585:4: warning: identifier '__Reply__mach_task_is_self_t' is reserved because it starts with '__' [-Wreserved-identifier]
684467-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:397:83: note: expanded from macro 'os_log_error'
684468-   397 |     identifier '__Request__task_generate_corpse_t' is reserved because it starts with '__' [-Wreserved-identifier]
684469- 1502 |         __attribute__(} __Request_2585 |         } (section("___task__Reply__macTEXT,__h_task_os_log"is_self_t __attri)_gen)) static erate_cconst corpse_thbutear _os___((unulog_fmtsed));
--
686608-
686609-      |                                                                                                                            ^~~~~~
686610-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/debug.h:32:
686611-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kcdata.h:246:
686612-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:77: note: expanded from macro 'NECPDATATRACELOG'
686613- 1049 | In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/string.h:        In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOPlatformExpert.cpp42:
686614:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/libsa/types.h:os_log_error:29:
686615-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOCPU.h51:
686616-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/libsa/machine/types.h:34:
686617-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/libsa/arm/types.h:71:22: warning: identifier '__val' is reserved because it starts with '__' [-Wreserved-identifier]
686618-(ne   71 | typecp_data_trace_logdef str_handleuct { i, "%s: " format "nt __va\n", __l[2]; }FUNCTION__, : bit43:
686619-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOService.h:44:
686620-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IORegistryEntry.h:39:
686621-__VA_ARGS__)64_t;  ; \
686622-      |                                                         ~~~~~~                     ^~~~~~~~~~~
686623-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOTypes.h:40/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:398:41: note: expanded from macro 'os_log_error':
686624-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/system.h:
--
728742-y_); \
728743-      |                 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
728744-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/lock_group.h:67:16/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.hqu: warning: identifier '_lck_grp_attr_' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
728745-   67 | typedef seue_entry_deadlt:1049:77: note: expanded from macro 'NECPDATATRACELOG'
728746-ruct _lck_grp_attr_   lck_grp_attr_t;ine_t);
728747-      | ^
728748:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/priority_queue.h:696 1049 |         os_log_error:81: note: (expanded from macro 'PRIORITY_QUEUE_MAKE'
728749-
728750-  696 |       |                ^
728751-necp_data_t/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/lock_group.h:139:16: warning: race_identifier '_lck_grp_stat_' is reserved because it starts with '_' at global scope [-Wreserved-identifier]log
728752-  139 | ty_h anpde        le, "%s: " def struct _lck_gr p_fstat_ {
728753-      |                ^
728754-ormat "\n", __FUNCTION__, __VA_ARGS__); \
728755-      |         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~
728756-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/lock_group.h  :/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:398:41149                          : note: expanded from macro 'os_log_error'
728757-   398 |     _os_log_v                                  er:16: warning: identifier '_lck_grp_stats_' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
728758-ify_fo  149 | typrmat_stredef       \
--
764479- In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOInterruptController.cpp:30:
764480-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:49:
764481-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/system.h:36:
764482-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/thread.h:98:
764483-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/vm/vm_kern.h 1049 |         os         _log_:74:
764484-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/locks.h:45:
764485:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/ticket_lock.h:36     error:
764486-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/counter.h   \
764487-      |                                                                                 ^
764488-(:103:
764489-necp_data_trace_log_handle, "%s: " fo/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:247:2rmat "\n", __FUNCTION__, __VA_ARGS__); \
764490-      |         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~
764491-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:399:76: note: expanded from macro 'os_log_error'
764492-  399 |     _os_log_internal(&__: warning: identifier 'ZC_RO_ID__LAST' is reserved because it contains '__' [-Wreserved-identifier]
764493-dso_handle,  247 |         ZC_RO_ID lo__Lg, ASTOS_ = ZC_RO_ID_ALOGMFI_OSENTI_TYTLEMENPE_ERROR, _os_log_fmt, TS,##__VA_ARGS__);    
764494-      |         ^
764495-    \
--
776654-al1, val1, val2,/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:2704:4: warning: identifier '__Reply__task_map_kcdata_object_64_t' is reserved because it starts with '__' [-Wreserved-identifier]
776655- 2704 |         } __Reply_ val2,_ta vask_l3,map val3, input1, i_kcdatnpua_objet1,ct_ in64_putt _2, _atinptriut2but, ie__npu((ut3,nus ined)put);
776656-      |           ^
776657-3); \
776658-      |                 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~
776659-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:77: note: expanded from macro 'NECPDATATRACELOG'
```

### the tail

```
  442 |         if (round_page_overflow(x, &x)) {
      |             ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_param.h:126:15: note: expanded from macro 'round_page_overflow'
  126 |                 bool __ovr = os_add_overflow(in, (__typeof__(*out))PAGE_MASK, out); \
      |                      ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_param.h:607:14: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
  607 |         vm_offset_t ptr = params.vmpp_base +
      |                     ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/libsa/lastkerneldataconst.c:49:65: warning: identifier '_lastkerneldataconst' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
   49 | const vm_offset_t    __attribute__((section("__DATA,__data")))  _lastkerneldataconst         = (vm_offset_t)&data_const_padding[0];
      |                                                                 ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/libsa/lastkerneldataconst.c:50:65: warning: identifier '_lastkerneldataconst_padsize' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
   50 | const vm_size_t      __attribute__((section("__DATA,__data")))  _lastkerneldataconst_padsize = sizeof(data_const_padding);
      |                                                                 ^
83 warnings generated.
             CC version.o
clang: warning: no such include directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa' [-Wmissing-include-dirs]
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/version.c:39:12: warning: identifier '__kernelVersionString' is reserved because it starts with '__' [-Wreserved-identifier]
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sun Nov  8 07:02:32 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
      |            ^
1 warning generated.
             LD mach.development.bcm2837.unstripped
ld: warning: -new_linker is obsolete
ld: warning: search path '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot/usr/local/lib/kernel/platform' not found
Undefined symbols for architecture arm64:
  "_mockfs_mountroot", referenced from:
      _vfstbllist in vfs_conf.o
  "_mockfs_vfsops", referenced from:
      _vfstbllist in vfs_conf.o
  "_mockfs_vnodeop_opv_desc", referenced from:
      _vfs_opv_descs in vfs_conf.o
  "_native_verified_block_root_authorized", referenced from:
      _bsd_init in bsd_init.o
ld: symbol(s) not found for architecture arm64
clang++: error: linker command failed with exit code 1 (use -v to see invocation)
make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
make[2]: *** [build_all] Error 2
make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
make: *** [build] Error 2
build-xnu-4k-baseline.sh: line 829: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

## status.txt

```
patch    36 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-legacy-start.patch
patch    37 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/gpu-probe-start.patch
patch    38 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-native-gpu-broker.patch
patch    39 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-owner-boot-manifest.patch
patch    40 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-owner-cache-carrier.patch
patch    41 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-owner-root-binding-audit.patch
patch    42 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-owner-root-crypto-probe.patch
patch    43 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-owner-systemos-mount.patch
patch    44 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-owner-z-air-init.patch
patch    45 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-pgz-alignment-probe.patch
patch    46 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/public-entitlements-header.patch
patch    47 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/source-corecrypto14-bootstrap.patch
patch    48 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/source-machine-layer.patch
patch    49 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/source-pthread-bootstrap.patch
patch    50 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/zzw-native-adreno-sandbox-grant.patch
patch    51 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/zzwb-native-sandbox-grant-set-properties.patch
patch    52 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/zzx-pmap-sync-64bit-pa.patch
patch    53 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/zzy-native-gpu-addon-mount.patch
patch    54 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/zzy-staged-system-apps.patch
patch    55 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/zzyb-native-cryptex-os-view.patch
patch    56 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/zzyc-owner-skip-launch-constraints.patch
patch    57 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/native-smp-secondary.patch
patch    58 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/native-smp-type-clusters.patch
patch    59 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/sheng-platform-power.patch
patch    60 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/zzz-boot-progress.patch
patch    61 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/xnu-8796.101.5-security-init.patch
patch    62 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/xnu-8796.101.5-sparse-index.patch
patch    63 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/linux-clang-auto-var-init.patch
patch    64 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/linux-clang-uio-stackbuf-align.patch
patch    65 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/linux-clang-kalloc-pointee-type.patch
patch    66 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/linux-clang-iorpc-kernel-content.patch
patch    67 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/xnu-8796-arm64-kpc-backend.patch
driver   ArmCpu                   base
driver   ArmDTPlatform            base
driver   NioUfs                   device
driver   SoftwareAES              base
kit      AdrenoFirmware           base
kit      AdrenoPM4                base
kit      ArmSmmu4K                base
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

## patch scope

```
out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work: every added line is inside a function
```
