# Why the build failed

run: 53, commit e337462408ed8a44110dbf97368060c177ca1f4a

## kernel.log

### the errors

```
8007:Undefined symbols for architecture arm64:
8011:ld: symbol(s) not found for architecture arm64
8012:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
8013:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
8014:make[2]: *** [build_all] Error 2
8015:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
8016:make: *** [build] Error 2
```

### around them

```
8001-   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sun Nov  8 14:02:56 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
8002-      |            ^
8003-1 warning generated.
8004-             LD mach.development.bcm2837.unstripped
8005-ld: warning: -new_linker is obsolete
8006-ld: warning: search path '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot/usr/local/lib/kernel/platform' not found
8007:Undefined symbols for architecture arm64:
8008-  "PE_boot_args_raw()", referenced from:
8009-      OSKext::loadKextWithIdentifier(OSString*, OSObject**, bool, bool, unsigned char, unsigned char, OSArray*) in OSKext.cpo
8010-   NOTE: found '_PE_boot_args_raw' in pe_bootargs.o, declaration possibly missing 'extern "C"'
8011-ld: symbol(s) not found for architecture arm64
8012:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
8013-make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
8014-make[2]: *** [build_all] Error 2
8015-make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
8016-make: *** [build] Error 2
8017-build-xnu-4k-baseline.sh: line 829: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

### the tail

```
  175 |                 struct _workq_park_data {
      |                        ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/user.h:186:10: warning: identifier '_ulock_wait_data' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
  186 |                 struct _ulock_wait_data {
      |                        ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/user.h:194:10: warning: identifier '_bsdthread_terminate' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
  194 |                 struct _bsdthread_terminate {
      |                        ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/user.h:199:10: warning: identifier '_exec_data' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
  199 |                 struct _exec_data {
      |                        ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/user.h:335:8: warning: identifier '__tdu' is reserved because it starts with '__' [-Wreserved-identifier]
  335 |         union __tdu {
      |               ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/user.h:336:10: warning: identifier '__tds' is reserved because it starts with '__' [-Wreserved-identifier]
  336 |                 struct __tds {
      |                        ^
349 warnings generated.
     LDFILELIST bsd
     LDFILELIST osfmk
             CC version.o
clang: warning: no such include directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa' [-Wmissing-include-dirs]
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/version.c:39:12: warning: identifier '__kernelVersionString' is reserved because it starts with '__' [-Wreserved-identifier]
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sun Nov  8 14:02:56 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
      |            ^
1 warning generated.
             LD mach.development.bcm2837.unstripped
ld: warning: -new_linker is obsolete
ld: warning: search path '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot/usr/local/lib/kernel/platform' not found
Undefined symbols for architecture arm64:
  "PE_boot_args_raw()", referenced from:
      OSKext::loadKextWithIdentifier(OSString*, OSObject**, bool, bool, unsigned char, unsigned char, OSArray*) in OSKext.cpo
   NOTE: found '_PE_boot_args_raw' in pe_bootargs.o, declaration possibly missing 'extern "C"'
ld: symbol(s) not found for architecture arm64
clang++: error: linker command failed with exit code 1 (use -v to see invocation)
make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
make[2]: *** [build_all] Error 2
make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
make: *** [build] Error 2
build-xnu-4k-baseline.sh: line 829: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

## archive-14-build-verified-root.log

### the tail

```
PASS: real VerifiedRoot crypto + empty policy table -> libVerifiedRoot.a
      root verification is disabled: no signed policy bundle exists for this board
```

## archive-13-build-storage-bindings.log

### the tail

```
PASS: libStorageBindings.a -> 18 absolute bindings over 14 kext-owned slots (com.apple.iokit.IOStorageFamily)
    __ZN20IOBlockStorageDevice10gMetaClassE -> 0xfffffff006a051d0
    __ZN20IOBlockStorageDevice11requestIdleEv -> 0xfffffff0045e2050
    __ZN20IOBlockStorageDevice13doSetPriorityEP26IOBlockStorageDeviceExtentjh -> 0xfffffff0045e2068
    __ZN20IOBlockStorageDevice13doSynchronizeEyyj -> 0xfffffff0045e2080
    __ZN20IOBlockStorageDevice13setPropertiesEP8OSObject -> 0xfffffff0045e1f38
    __ZN20IOBlockStorageDevice18doSynchronizeCacheEv -> 0xfffffff0045e2074
    __ZN20IOBlockStorageDevice18getWriteCacheStateEPb -> 0xfffffff0045e2038
    __ZN20IOBlockStorageDevice18setWriteCacheStateEb -> 0xfffffff0045e2044
    __ZN20IOBlockStorageDevice20doGetProvisionStatusEyyPjP35IOBlockStorageProvisionDeviceExtenty -> 0xfffffff0045e208c
    __ZN20IOBlockStorageDevice4initEP12OSDictionary -> 0xfffffff0045e1e30
    __ZN20IOBlockStorageDevice7doUnmapEP26IOBlockStorageDeviceExtentjj -> 0xfffffff0045e205c
    __ZN20IOBlockStorageDevice9metaClassE -> 0xfffffff005c73f40
    __ZN20IOBlockStorageDeviceC1EPK11OSMetaClass -> 0xfffffff0045e1d98
    __ZN20IOBlockStorageDeviceC2EPK11OSMetaClass -> 0xfffffff0045e1d98
    __ZN20IOBlockStorageDeviceD2Ev -> 0xfffffff0045e1db8
    __ZNK20IOBlockStorageDevice11getPropertyEPK8OSSymbol -> 0xfffffff0045e1e88
    __ZNK20IOBlockStorageDevice12getMetaClassEv -> 0xfffffff0045e1dc4
    __ZTV20IOBlockStorageDevice -> 0xfffffff005c73f50

original-bindings.o:
fffffff006a051d0 A __ZN20IOBlockStorageDevice10gMetaClassE
fffffff0045e2050 A __ZN20IOBlockStorageDevice11requestIdleEv
fffffff0045e2068 A __ZN20IOBlockStorageDevice13doSetPriorityEP26IOBlockStorageDeviceExtentjh
fffffff0045e2080 A __ZN20IOBlockStorageDevice13doSynchronizeEyyj
fffffff0045e1f38 A __ZN20IOBlockStorageDevice13setPropertiesEP8OSObject
fffffff0045e2074 A __ZN20IOBlockStorageDevice18doSynchronizeCacheEv
fffffff0045e2038 A __ZN20IOBlockStorageDevice18getWriteCacheStateEPb
fffffff0045e2044 A __ZN20IOBlockStorageDevice18setWriteCacheStateEb
fffffff0045e208c A __ZN20IOBlockStorageDevice20doGetProvisionStatusEyyPjP35IOBlockStorageProvisionDeviceExtenty
fffffff0045e1e30 A __ZN20IOBlockStorageDevice4initEP12OSDictionary
fffffff0045e205c A __ZN20IOBlockStorageDevice7doUnmapEP26IOBlockStorageDeviceExtentjj
fffffff005c73f40 A __ZN20IOBlockStorageDevice9metaClassE
fffffff0045e1d98 A __ZN20IOBlockStorageDeviceC1EPK11OSMetaClass
fffffff0045e1d98 A __ZN20IOBlockStorageDeviceC2EPK11OSMetaClass
fffffff0045e1db8 A __ZN20IOBlockStorageDeviceD2Ev
fffffff0045e1e88 A __ZNK20IOBlockStorageDevice11getPropertyEPK8OSSymbol
fffffff0045e1dc4 A __ZNK20IOBlockStorageDevice12getMetaClassEv
fffffff005c73f50 A __ZTV20IOBlockStorageDevice

```

## archive-12-build-nio-ufs-archive.log

### the tail

```
nio-ufs: build/nio-ufs/libNioUfs.a -> build/sheng-ufs/libShengUfs.a (499600 bytes, sha256 af8fc3cb4e72212de429109233dfa90c684e1dc041db88b5b4df6a4a9d6134be)
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
49870:        (OSAddAtomicLong(a e,1364r  |  _        u_        iSInAOtFLpEot_grC(_A"tSI TO__P_PodTltRlr(eavdce_a0 asm("x0")FilePollersSetup for cor = (uintptr_efit) le argfai0; led    wi   th    error:    0x   %x\n",    er \
58101: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
58107: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
531572:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/netinet/tcp.h count or error:258:18:  */warning: identifier '__pad1' is reserved because it starts with '__' [-Wreserved-identifier]
684059:intft 8260 |         ribute_        NECP_DATA_TRACE__((unused));("progress_notify_stage_initialize failed LOG_CONDITto allocate memory. Error 0x%x\n", ret);
707040:uct _OS./mach/upl.h |         os_log_error:171:4: warning: identifier '__Request__upl_abort_range_t' is reserved because it starts with '__' [-Wreserved-identifier]
769470:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/ipc_kobject.h        os_log_error:77:
773113:_log/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdatomic.h:120:9_error: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
892125:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/task.h739    os_log_error:138:8::4: warning: (OS_LOG_DEFAULT, identifier '__Request__host_set_atm_diagnostic_flag_t' is reserved because it starts with '__' [-Wreserved-identifier]
1078998:g_reply/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:1534_error:2:_t(__u note: expanded from macro 'KALLOC_TYPE_VAR_DEFINE_3'nus
1186065:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_space.h:155:10: NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
1186089: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
1186100: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
1186111: 1413 |                     "| error: latency %d too big (> 1 sec)",
1186162:error: jit}ter  1430 | %dm;s too big (latency %dms)",
1186204:TRY_KEY_ 1420 |                     "| error: BITS;
1186226: 1438 |                     "| error: loss recovery %dms too big",arg)
1186269:__ERR, "| error: reordering %d /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/priority_queue.h:707:81: note: expanded from macro 'PRIORITY_QUEUE_MAKE_CB'
1186293: 1463 |                     "| error: output in In file included from t /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/priority.cerval %dms too big",
1509030:  224 | nqueuembuf ret            _osurned an error: %d", error);
1542516:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/arm/_mcontext.h:36_error:
1561409:        ipseclog((LOG_DEBUG, "ah6_output: internal error:In file included from mach/clock_reply_user.c:9:
1570398:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
1645442:  275 |         SASEL_LOG("Returned with error: %d", err);
1743855:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/socket.h:82error:
2291924: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
2291930: 3383 |                     "(os_reason_alloc_buffer error: %d, \
2291967: 1284 |         kfree_type_impl(kt_view_var, os_ptr_load_an kcdata error: %d, length: %ld)\n",
2321345:_log_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/arm/_types.h:15:33error: warning: identifier '__int8_t' is reserved because it starts with '__' [-Wreserved-identifier]
2327230:  602 |         int __paIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/vm/vm_compressor_backing_file.cgein_error:31:
2772473:Undefined symbols for architecture arm64:
2772485:ld: symbol(s) not found for architecture arm64
2772486:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
2772487:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
2772488:make[2]: *** [build_all] Error 2
2772489:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
2772490:make: *** [build] Error 2
```

### around them

```
49864-      |            ^
49865-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSAtomic.h:177:9: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
49866-  177 |         return OSAddAtomicLong(-1L, address);
49867-      |                ^
49868-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSAtomic.h:148:22: note: expanded from macro 'OSAddAtomicLong'
49869-  148s/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp | t:1364:76: warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
49870:        (OSAddAtomicLong(a e,1364r  |  _        u_        iSInAOtFLpEot_grC(_A"tSI TO__P_PodTltRlr(eavdce_a0 asm("x0")FilePollersSetup for cor = (uintptr_efit) le argfai0; led    wi   th    error:    0x   %x\n",    er \
49871-r);      |                                    ^
49872-olatile long*,b)))
49873-      |                             ^
49874-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSAtomic.h:59:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:507:4: warning: identifier '__dtrace_a1' is reserved because it starts with '__' [-Wreserved-identifier]
49875-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:303:42: note: expanded from macro 'MAC_PERFORM_CALL'
49876-  303 | #define MAC_PERFORM_CALL(operation, mpc) DTRACE_MACF3(mac__call__ ## operation, void *, mpc, int, 0, int, MAC_ITERATE_PERFORM)
49877-      |                                          ^
49878-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:165:2: note: expanded from macro 'DTRACE_MACF3'
49879-  165 |         DTRACE_PROBE3(__sdt_, name, arg1, arg2, arg3);
49880-      |         ^
--
58095- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
58096-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
58097-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
58098-  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
58099-      |                 ~~               ^~~~~~~~~~~
58100-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
58101: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
58102-      |                                                                                ~~~
58103-      |                                                                                %zu
58104- 1414 |                                             path, mc_error, fatal_failure_desc_len);
58105-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
58106-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
58107: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
58108-      |                                                                                                   ~~~
58109-      |                                                                                                   %zu
58110- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
58111-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
58112-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
58113- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
58114-      |                             ^
58115-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
58116- 1426 |                 zfree(ZV_NAMEI, vn_path);
58117-      |                 ^
--
531566-  608 | __zat; llo      /* byIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if_ports_used.c:51:
531567-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/netinet/in_pcb.hc_te:94ro(
531568-      | ^
531569-:
531570-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:41:
531571-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/skywalk/os_nexus_private.h:37:
531572:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/netinet/tcp.h count or error:258:18:  */warning: identifier '__pad1' is reserved because it starts with '__' [-Wreserved-identifier]
531573-
531574-      |   258 |         u_int8_t                                ^
531575-      /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/arm/_types.h:98:33: warning: identifier '__darwin_time_t' is reserved because it starts with '__' [-Wreserved-identifier]
531576-  __   98 | pad1;
531577-      |                         ^
531578-typedef long         /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/netinet/tcp.h:293:6: warning: identifier '__pad2' is reserved because it starts with '__' [-Wreserved-identifier]
531579-  293 |             __pad2:17;           __darwin_time_t;        /
531580-      | * t            ^
531581-ime() */
531582-      |                                 ^
--
707034-SSwaute__((unuspInt64(
707035-      | ^
707036-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:77: note: expanded from macro 'NECPDATATRACELOG'
707037-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/arm/OSByteOrder.h:64:8e 1049: warning: identifier '_OSUnalignedU16' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]
707038-   64 | strd));
707039-      |           ^
707040:uct _OS./mach/upl.h |         os_log_error:171:4: warning: identifier '__Request__upl_abort_range_t' is reserved because it starts with '__' [-Wreserved-identifier]
707041-  171 |         } __RequUnali(necpest__gnedU_data_trace_log_handle, "%s: " format "\n", __FUNCTION__, __VAupl_a16 {
707042-      |        ^
707043-bort_ARGS_range_t __attribute__((unused));
707044-      |           ^
707045-__); \
707046-      |                                                         ~~~~~~                     ^~~~~~~~~~~
707047-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/arm/OSByteOrder.h:65:./mach/upl.h/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:398::184:4: warning: identifier '__Request__upl_commit_t' is reserved because it starts with '__' [-Wreserved-identifier]
707048-  184 |         41: note: expanded from macro 'os_log_error'20: warning: identifier '__val' is reserved because it starts with '__' [-Wreserved-identifier]} __Reques
707049-   65 |         volatile uint16_t __val;
707050-      |                           ^
--
769464-icy_search_array[27
769465- i]-      | ^
769466->cond_policy_id : 0, ski1086 | p_session_order,        } skip_order); \
769467-      |                                                                                                                                                                                                                                                                                                                             ^~~~~~~~~~
769468- /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:77: note: expanded from macro 'NECPDATATRACELOG'
769469- 1049 | _In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_init.c:83:
769470:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/ipc_kobject.h        os_log_error:77:
769471-_(necpReque_datast_In file included from _tr_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_port.h:91:
769472-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_space.h:92:
769473-thra/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_entry.h:127ead_create:1: warning: cast from 'void (*)(vm_allocation_site_t *)' (aka 'void (*)(struct vm_allocation_site *)') to 'typeof (__zone_site_register(&site)) (*)(const void *)' (aka 'void (*)(const void *)') converts to incompatible function type [-Wcast-function-type-strict]ce__t __attribute_log_han
769474-_(  127 | KA(unusLLOdle, "%s: " format "C_ARRAY_TYPE_DECL(ip\n", c_entry_table, __FUNCTIONstruct ipc__, __entry);
769475-      | ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
769476-_VA_ARGSe__); /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:966:2: note: expanded from macro 'KALLOC_ARRAY_TYPE_DECL'
769477-  966 |         KAL\
769478-      |                                                         ~~~~~~                     ^~~~~~~~~~~
769479-dLOC));_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:398:
769480-      |           ^
--
773107-  119 | typedef _Atomic(uint_least64      |                 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
773108-_t)     0a/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:ULL// force enum to be 64 bits
773109-      |         ^1049:77: 
773110-note: expanded from macro 'NECPDATATRACELOG'
773111-tomic_ 1049uint_l |         east6os4_t;
773112-      |         ^
773113:_log/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdatomic.h:120:9_error: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
773114-  120 | typede(necp_data_trace_log_handf _Atomic(int_fast8_le, t)        atomic_int_f"%s: ast8_t;
773115-      |         ^
773116-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdatomic.h:121:9: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
773117-" format "\n", __FUNCTION__, __VA_AR  GS__)In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOInterruptController.cpp:31:
773118-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOService.h:46:
773119-; \
773120-      |         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~
773121-In file included from 121/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:399:76:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IODeviceMemory.h:38:
773122-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOMemoryDescriptor.h:50:7: warning: identifier '_IOMemoryDescriptorMixedData' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]
773123-   50 | class _IOMemoryDescr | typedef _Atomic(uint_fast8_t)       atomic_uint_fast8_t;
--
892119-      |           ^
892120-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.c:1971:3: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
892121- 1971 |                 NETAGENTLOG0(LOG_ERR, "Failed to find session");
892122-      |                 ^
892123-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.c:74:6: note: expanded from macro 'NETAGENTLOG0'
892124-   74 | In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/mach_port.c:        /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_host.h:80:
```

### the tail

```
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
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sun Nov  8 14:01:49 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
      |            ^
1 warning generated.
             LD mach.development.bcm2837.unstripped
ld: warning: -new_linker is obsolete
ld: warning: search path '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot/usr/local/lib/kernel/platform' not found
Undefined symbols for architecture arm64:
  "PE_boot_args_raw()", referenced from:
      OSKext::loadKextWithIdentifier(OSString*, OSObject**, bool, bool, unsigned char, unsigned char, OSArray*) in OSKext.cpo
   NOTE: found '_PE_boot_args_raw' in pe_bootargs.o, declaration possibly missing 'extern "C"'
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
patch    68 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-security-extensions.patch
patch    69 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-trust-cache-without-security-extensions.patch
patch    70 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kext-data-const-stays-writable.patch
patch    71 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kernel-data-const-stays-writable.patch
patch    72 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-image4-kext.patch
patch    73 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-port-command-line.patch
patch    74 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-boot-args-fallback.patch
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

## patch scope

```
out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work: every added line is inside a function
```
