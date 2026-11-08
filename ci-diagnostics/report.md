# Why the build failed

run: 41, commit 71f4e13af1aed12615bdcee35ed6ec7766196628

## kernel.log

### the errors

```
58544:_t log, os_log 1041 |         _handle, "%s    os_log_error: " for(necp_log_handle, "%s: %s\n", __FUNCTION__, type_t mat "\n", type,__FUNCT uint64_t ts,ION__, __VA_Amsg)RGS_;                 \
69781:(LOG_ERR, 5/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c"Parameters copyin error::674:70: note: expanded from macro 'NECP_DATA_TRACE_LOG_CONDITION'
239975:memorystatus_log_error:80: note: format string is defined here
360883:Undefined symbols for architecture arm64:
360913:ld: symbol(s) not found for architecture arm64
360914:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
360915:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
360916:make[2]: *** [build_all] Error 2
360917:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
360918:make: *** [build] Error 2
```

### around them

```
58538-ndInterfa  616 | _os_log_atce %d> <policer ay_id %d skip_polgenticy_id %d> not", \
58539-      |  fou                                                                                                                                      ^~_time(void *dnd")so, os_;
58540-log/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:50: note: expanded from macro 'NECPDATATRACELOG'
58541-
58542- 1049 |         os_log_error(necp_data_trace_log      |                 ^
58543-_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1041:6: note: expanded from macro 'NECPLOG0'
58544:_t log, os_log 1041 |         _handle, "%s    os_log_error: " for(necp_log_handle, "%s: %s\n", __FUNCTION__, type_t mat "\n", type,__FUNCT uint64_t ts,ION__, __VA_Amsg)RGS_;                 \
58545-      _); \
58546-       const char *| |                                                         ^~~~~~
58547-            ^
58548-messa/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396:5: note: expanded from macro 'os_log_error'
58549-  396 |    /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:397:83: note: expanded from macro 'os_log_error'
58550- _Static_asseg  397 |  e,    __attribute__((section("__TEXT,__os_log"))) static consrt(__builtin_ct char _os_log_fmt[] = foronstant_p(format), "format;       \
58551-      |                                                                                   ^~~~~~
58552-mat string mu...) __osloglike(5, 6);
58553-      | ^
58554-st be constant"/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c:7330:3: warning: format specifies type 'int' but the argument has type 'u_int32_t' (aka 'unsigned int') [-Wformat]
--
69775-      | al_log(O    ^
69776-S_LOG_DEFAse, "NECP_KERNEL_CONULT, "%s: %s/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp_client.cDITION_HAS_CLIENT", 0\n":8861:3: warning: , h'_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
69777-, __FUNCTION__, msg);                       \
69778-       as_cl8861 |                 |             ^
69779-NECi/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:292:ent);
69780-      PLOG|                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
69781:(LOG_ERR, 5/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c"Parameters copyin error::674:70: note: expanded from macro 'NECP_DATA_TRACE_LOG_CONDITION'
69782-  674 |   (%d)", err note: expanded from macro 'os_log'
69783-  or);
69784-      |                 ^
69785-   /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1033:6: NEC292 |     note: P_DAexpanded from macro 'NECPLOG'
69786-_Static_asTA_Tsert(__builtin_constan 1033 |         t_p(format), "format strRAC ingE_LO musG_CONDITIO   t be constN3(debug, os_log_ant");calle    rror(necp_log_handle, er, negat"%s: "e, name, v         \
69787-      |     ^
69788- format al, 0, 0, input, 0, 0)
69789-      |     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~"\n", 
69790-_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c:663:59: note: expanded from macro 'NECP_DATA_TRACE_LOG_CONDITION3'
69791-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.c:1736  662_FU:3 |   NC: warning:   TIO'_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
--
239969-  /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/kern_memorystatus_freeze.c:2465  507 |         SYSCTL_OID(parent, nbr, name, CTLTYPE_QUAD|access, \
239970-      |         ^
239971-257 | #define /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/sysctl.h:416:2: note: expanded from macro 'SYSCTL_OID'
239972-  416 |         __STARTUP_ARG(sysctl_##parent, _##name,                                 \
239973-      |         ^
239974-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/startup.h:736:2: note: expanded from macro '__STARTUP_ARG'
239975:memorystatus_log_error:80: note: format string is defined here
239976-  736 |  2465 |                 memorys(fo        _tat_STus_ARTUP1(log_infname, lo("rmat, ...) memorys_memorytatus: memostatus_inelog, subsystem, rank, func, arg, argrysta)
239977-      |         ^tus_f
239978-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/startup.h:727reeze:2: note: expanded from macro '__STARTUP1'
239979-_wi_daily_mb_max sth_tyet tope(OS %dMB_LOG_TYPE_ERROR, format, ##__VA_ARGS__)
239980-      |                                             ^
239981-\n", /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/kern_memorystatus_internal.h:253:56: note: expanded from macro '_memorystatus_log_with_type'
239982-    727 |         _253 | #de_starfine tup_ _memo## surystabsysttus_lem ##og_wi _entth_tyry_ #pe(ty# nampe, fe ## ormat_ ## , ...line ) os_= { \log_w
239983-      |         ^
239984-ithmemor_typeystat(memous_frrystaeeze_tus_ldailyog_ha_mb_mndle,ax);
239985- type, format, ##__VA_ARGS__)
--
360877-   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sun Nov  8 07:14:31 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
360878-      |            ^
360879-1 warning generated.
360880-             LD mach.development.bcm2837.unstripped
360881-ld: warning: -new_linker is obsolete
360882-ld: warning: search path '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot/usr/local/lib/kernel/platform' not found
360883:Undefined symbols for architecture arm64:
360884-  "IOUserBlockStorageDevice::DoAsyncUnmap(unsigned int, IOMemoryDescriptor*, unsigned int, int (*)(OSMetaClassBase*, IORPC))", referenced from:
360885-      IOUserBlockStorageDevice::doUnmap(IOBlockStorageDeviceExtent*, unsigned int, unsigned int) in libIOStorageFamily.a[15](IOUserBlockStorageDevice_kext.o)
360886-  "IOUserBlockStorageDevice::GetDeviceParams(DeviceParams*, int (*)(OSMetaClassBase*, IORPC))", referenced from:
360887-      IOUserBlockStorageDevice::start(IOService*) in libIOStorageFamily.a[15](IOUserBlockStorageDevice_kext.o)
360888-  "IOUserBlockStorageDevice::GetVendorString(DeviceString*, int (*)(OSMetaClassBase*, IORPC))", referenced from:
360889-      IOUserBlockStorageDevice::getVendorString() in libIOStorageFamily.a[15](IOUserBlockStorageDevice_kext.o)
360890-      IOUserBlockStorageDevice::getRevisionString() in libIOStorageFamily.a[15](IOUserBlockStorageDevice_kext.o)
360891-      IOUserBlockStorageDevice::getAdditionalDeviceInfoString() in libIOStorageFamily.a[15](IOUserBlockStorageDevice_kext.o)
360892-  "IOUserBlockStorageDevice::DoAsyncReadWrite(bool, unsigned int, unsigned long long, unsigned long long, unsigned long long, unsigned long long, unsigned int, int (*)(OSMetaClassBase*, IORPC))", referenced from:
360893-      IOUserBlockStorageDevice::doAsyncReadWrite(IOMemoryDescriptor*, unsigned long long, unsigned long long, IOStorageAttributes*, IOStorageCompletion*) in libIOStorageFamily.a[15](IOUserBlockStorageDevice_kext.o)
--
360908-      vtable for IOUserBlockStorageDevice in libIOStorageFamily.a[15](IOUserBlockStorageDevice_kext.o)
360909-  "IOUserBlockStorageDevice::StartDev(IOService*, DeviceParams const*, int (*)(OSMetaClassBase*, IORPC))", referenced from:
360910-      IOUserBlockStorageDevice::start(IOService*) in libIOStorageFamily.a[15](IOUserBlockStorageDevice_kext.o)
360911-  "IOUserBlockStorageDevice::MetaClass::Dispatch(IORPC)", referenced from:
360912-      vtable for IOUserBlockStorageDevice::MetaClass in libIOStorageFamily.a[15](IOUserBlockStorageDevice_kext.o)
360913-ld: symbol(s) not found for architecture arm64
360914:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
360915-make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
360916-make[2]: *** [build_all] Error 2
360917-make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
360918-make: *** [build] Error 2
360919-build-xnu-4k-baseline.sh: line 829: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

### the tail

```
             LD mach.development.bcm2837.unstripped
ld: warning: -new_linker is obsolete
ld: warning: search path '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot/usr/local/lib/kernel/platform' not found
Undefined symbols for architecture arm64:
  "IOUserBlockStorageDevice::DoAsyncUnmap(unsigned int, IOMemoryDescriptor*, unsigned int, int (*)(OSMetaClassBase*, IORPC))", referenced from:
      IOUserBlockStorageDevice::doUnmap(IOBlockStorageDeviceExtent*, unsigned int, unsigned int) in libIOStorageFamily.a[15](IOUserBlockStorageDevice_kext.o)
  "IOUserBlockStorageDevice::GetDeviceParams(DeviceParams*, int (*)(OSMetaClassBase*, IORPC))", referenced from:
      IOUserBlockStorageDevice::start(IOService*) in libIOStorageFamily.a[15](IOUserBlockStorageDevice_kext.o)
  "IOUserBlockStorageDevice::GetVendorString(DeviceString*, int (*)(OSMetaClassBase*, IORPC))", referenced from:
      IOUserBlockStorageDevice::getVendorString() in libIOStorageFamily.a[15](IOUserBlockStorageDevice_kext.o)
      IOUserBlockStorageDevice::getRevisionString() in libIOStorageFamily.a[15](IOUserBlockStorageDevice_kext.o)
      IOUserBlockStorageDevice::getAdditionalDeviceInfoString() in libIOStorageFamily.a[15](IOUserBlockStorageDevice_kext.o)
  "IOUserBlockStorageDevice::DoAsyncReadWrite(bool, unsigned int, unsigned long long, unsigned long long, unsigned long long, unsigned long long, unsigned int, int (*)(OSMetaClassBase*, IORPC))", referenced from:
      IOUserBlockStorageDevice::doAsyncReadWrite(IOMemoryDescriptor*, unsigned long long, unsigned long long, IOStorageAttributes*, IOStorageCompletion*) in libIOStorageFamily.a[15](IOUserBlockStorageDevice_kext.o)
  "IOUserBlockStorageDevice::GetProductString(DeviceString*, int (*)(OSMetaClassBase*, IORPC))", referenced from:
      IOUserBlockStorageDevice::getProductString() in libIOStorageFamily.a[15](IOUserBlockStorageDevice_kext.o)
  "IOUserBlockStorageDevice::DoAsyncEjectMedia(unsigned int, int (*)(OSMetaClassBase*, IORPC))", referenced from:
      IOUserBlockStorageDevice::doEjectMedia() in libIOStorageFamily.a[15](IOUserBlockStorageDevice_kext.o)
  "IOUserBlockStorageDevice::DoAsyncSynchronize(unsigned int, unsigned long long, unsigned long long, int (*)(OSMetaClassBase*, IORPC))", referenced from:
      IOUserBlockStorageDevice::doSynchronize(unsigned long long, unsigned long long, unsigned int) in libIOStorageFamily.a[15](IOUserBlockStorageDevice_kext.o)
  "IOUserBlockStorageDevice::ReportEjectability(bool*, int (*)(OSMetaClassBase*, IORPC))", referenced from:
      IOUserBlockStorageDevice::start(IOService*) in libIOStorageFamily.a[15](IOUserBlockStorageDevice_kext.o)
      IOUserBlockStorageDevice::reportEjectability(bool*) in libIOStorageFamily.a[15](IOUserBlockStorageDevice_kext.o)
  "IOUserBlockStorageDevice::ReportRemovability(bool*, int (*)(OSMetaClassBase*, IORPC))", referenced from:
      IOUserBlockStorageDevice::reportRemovability(bool*) in libIOStorageFamily.a[15](IOUserBlockStorageDevice_kext.o)
  "IOUserBlockStorageDevice::ReportWriteProtection(bool*, int (*)(OSMetaClassBase*, IORPC))", referenced from:
      IOUserBlockStorageDevice::reportWriteProtection(bool*) in libIOStorageFamily.a[15](IOUserBlockStorageDevice_kext.o)
  "IOUserBlockStorageDevice::Dispatch(IORPC)", referenced from:
      vtable for IOUserBlockStorageDevice in libIOStorageFamily.a[15](IOUserBlockStorageDevice_kext.o)
  "IOUserBlockStorageDevice::StartDev(IOService*, DeviceParams const*, int (*)(OSMetaClassBase*, IORPC))", referenced from:
      IOUserBlockStorageDevice::start(IOService*) in libIOStorageFamily.a[15](IOUserBlockStorageDevice_kext.o)
  "IOUserBlockStorageDevice::MetaClass::Dispatch(IORPC)", referenced from:
      vtable for IOUserBlockStorageDevice::MetaClass in libIOStorageFamily.a[15](IOUserBlockStorageDevice_kext.o)
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
PASS IOUserBlockStorageDevice_kext (0 warnings)
PASS: 14 members, 3072344 bytes -> build/storage-family/libIOStorageFamily.a
```

## archive-12-build-nio-ufs-archive.log

### the tail

```
nio-ufs: build/nio-ufs/libNioUfs.a -> build/sheng-ufs/libShengUfs.a (454264 bytes, sha256 4088312aa3d98e4b98eb712d79f5a469c84f50eba35f2539b1e6075cdb58d82d)
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
48759:        IOLog("IOPolledFilePold  lersSetu304 | #d_oveefinp for corefile failed with error: 0xe MAC_Prflow(in, (__typeof__(*out))PAGE_MASK, out); \%E
57454: 2310 |         } __Reply__task_get_state_t __a 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
57465: 1418 |                                  /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:2335:4   "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
605695: 1381 |         } __Rep/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h        os_log_error:879:4: warning: identifier '__Request__mach_port_insert_right_t' is reserved because it starts with '__' [-Wreserved-identifier]
608440:  158 |                 printf("buffer_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
627633: 3190 |                         os_log_error:1: warning: identifier '__kalloc_array_size' is reserved because it starts with '__' [-Wreserved-identifier]
627969:  268 |                 printf("(%s) Fail_krealled to handle availa/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if_ipsec.c:3490:7: bility of LZ4. Error 0x%x\n", __func__, ret);
649410:itialize failed to allocate mem __addory. Error 0x%x\n", ret);
660063: 1041 |             os_log_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/priority_queue.h:696:81error: note: expanded from macro 'PRIORITY_QUEUE_MAKE'
672599:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/bits.h:277:2og_error:37:
685573: 1049 |         os_log_error: warning: identifier '__Reply__mach_port_kobject_description_t' is reserved because it starts with '__' [-Wreserved-identifier]
746699:  168error: warning: identifier '__kfree_size' is reserved because it starts with '__' [-Wreserved-identifier]
746857:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_kmsg.c:1937error:3:(ne warning: identifier '__elem' is reserved because it starts with '__' [-Wreserved-identifier]cp_
752078: 1033 |             o/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/thread_act.h:617:4s_log_error: warning: identifier '__Request__thread_get_special_port_t' is reserved because it starts with '__' [-Wreserved-identifier]
752986:s_lo/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:1520:2g_error: note: (necp_dexpanded from macro '_KALLOC_TYPE_DEFINE'
791312:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h |         os_log_error:52:
799268: 1033 |             os_log_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/host_priv.h:420:4error: warning: identifier '__Request__host_get_boot_info_t' is reserved because it starts with '__' [-Wreserved-identifier]
969255: __pagei/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/san/san/memintrinsics.h:57n_error:1: warning: ;
1174765:_t;       /* byte count/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:1749 or error:1: warning: identifier '__krealloc_ext' is reserved because it starts with '__' [-Wreserved-identifier]
1190715: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
1190735: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
1190798:                    "| error: latency %d too big (> 1 sec)",
1190809: 1420 |                     "| error: jitter %dms too big (latency %dms)",
1190850: 1438 |                     "| error: loss recovery %In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/libkern/os/internal.c:24:
1190875:      | error: ^
1500348: 2626 |         /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdatomic.h:169:42        FDLOG(LOG_ERR, fd_cb, "failed to get the close error: %: warning: identifier '_Value' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]
1505570: 4398 |                                 FDLOG(LOG_DEBUG, &nil_pcb, "ctl_enqueuembuf returned an error: %d", error);
1554386:  202 |                 ipseclog((LOG_DEBUG, "ah4_outp int ut:    interna     l error: "
1570530: "esp4_output: internal error: "
1640874:  275 |         SASEL_LOG("Returned with error: %d", err);
1642639: |                     (ifp != NULL) ? if_name(ifp) : "/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/resource.h:674:8NONE", error:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSByteOrder.h:145:1:  warning: identifier '_iopol_param_t' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
1654520:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:72n_error:
1687303:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/kern_sysctl.h:34:16 byte count or error: warning:  */
1884296:ize_t;       /* byte cou/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/vm/vm_resident.c:9179nt or error:22: warning:  */
1926656:error:696:81: note: expanded from macro 'PRIORITY_QUEUE_MAKE'
2027408:d mig/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_fq_codel.h:94:1_reply_error: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
2082785:cted_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/kern_memorystatus_internal.h:253:56error: note: expanded from macro '_memorystatus_log_with_type'
2292101: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
2292107: 3383 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
2473648:pagein_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdatomic.h:128:9error: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
```

### around them

```
48753-      |             ^
48754-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_param.h:126:15: note: expanded from macro 'round_page_overflow'
48755-);   126 |                   :  \
48756-      |                 ^
48757-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:       bool __ovr = 304warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]o:
48758-s_42: note:  1364aexpanded from macro 'MAC_PERFORM_RSLT' |         d
48759:        IOLog("IOPolledFilePold  lersSetu304 | #d_oveefinp for corefile failed with error: 0xe MAC_Prflow(in, (__typeof__(*out))PAGE_MASK, out); \%E
48760-      xR|                      ^
48761-FORM_RSLT(operation, mpc) DTRACE_MACF2(mac__rslt__ ## /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_param.h:424:6: warning: identifier '__ovr' is reserved because it starts with '__' [-Wreserved-identifier]
48762-o\n",peratio  424 |         n, void *, err);
48763-      |                                                                                   ~~     ^~~
48764-      |                                                                                   %x
48765- mpc, int, 0)
48766-      |                                          ^
48767-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:162:2: note: expanded from macro 'DTRACE_MACF2'
48768-  162 |         DTRACE_PROBE2(__sdt_, name, arg1, arg2);
48769-      |         ^
--
57448-      |           ^
57449-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:2296:4: warning: identifier '__Reply__task_set_policy_t' is reserved because it starts with '__' [-Wreserved-identifier]
57450- 2296 |         } __Reply__task_set_policy_t __attribute__((unused));
57451-      |           ^
57452-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:2310:4: warning: identifier '__Reply__task_get_state_t' is reserved because it starts with '__' [-Wreserved-identifier]
57453-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
57454: 2310 |         } __Reply__task_get_state_t __a 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
57455-      |                                                                                ~~~
57456-      |                                                                                %zu
57457- 1414 |                                             path, mc_errottribute__((unused));
57458-      |           ^
57459-r, fatal_failure_desc_len);
57460-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
57461-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:2322:4: warning: identifier '__Reply__task_set_state_t' is reserved because it starts with '__' [-Wreserved-identifier]
57462- 2322 |         /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43} _: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
57463-_Reply__task_set_state_t __attribute__((unused));
57464-      |           ^
57465: 1418 |                                  /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:2335:4   "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
57466-      |                                                                                                   ~~~
57467-      |                                                                                                   %zu
57468- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
57469-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
57470-: warning: identifier '__Reply__task_set_phys_footprint_limit_t' is reserved because it starts with '__' [-Wreserved-identifier]
57471-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
57472- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
57473-      |                             ^
57474- 2335 |         } __Reply__task_set_phys_footprint_limit_t __attribute__((unused));
57475-      |           ^
--
605689- 1369 |         } __Reply__mach_port_allocate_t __attribute__((unused));
605690-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if_utun.c:1872:3      |           ^
605691-_request_notification_t /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]:1381:4: warning: __attribute__(
605692-identifier '__Reply__mach_port_destroy_t' is reserved because it starts with '__' [-Wreserved-identifier] 1872 |         
605693-(unused));
605694-      |           ^
605695: 1381 |         } __Rep/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h        os_log_error:879:4: warning: identifier '__Request__mach_port_insert_right_t' is reserved because it starts with '__' [-Wreserved-identifier]
605696-ly__mach_  879 |         } __Re(pquest__mach_port_iOort_nsSder_et_right_t __atLstrOtibGrut_oe_Dy_(E_(uFtnuA seU_d)L_);Ta
605697-      ,t|           ^ t
605698-"utun_ribute__((unused));
605699-      |           ^
605700-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:1393:4: warning: identifier '__Reply__mach_port_deallocate_t' is reserved because it starts with '__' [-Wreserved-identifier]
605701- 1393 |         } __Reply__mach_port_deallocate_t __attribute__((unused));
605702-      |           ^
605703-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:1406:4: warning: identifier '__Reply__mach_port_get_refs_t' is reserved because it starts with '__' [-Wreserved-identifier]
605704- 1406 |         } __Reply__mach_port_get_ref/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:892:s_t cleanup_family - utun_deta__attribute__((unused));
605705-      |           ^
--
627627-kfree_size);                \
627628-      |                     ^
627629-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h:64:2: note: expanded from macro 'os_ptr_load_and_erase'
627630-   64 |         _Static_assert(os_is_ptr_like(elem)y_decod/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if_ipsec.c:3190:4: e(
627631-      |                             ^
627632-,             /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:1210 warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
627633: 3190 |                         os_log_error:1: warning: identifier '__kalloc_array_size' is reserved because it starts with '__' [-Wreserved-identifier]
627634-(OS 1210 | __k_LOG_DE        \
627635-      |         ^
627636-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kdp/output_stages/out_lz4.c:209:2: warning: identifier '__eptr' is reserved because it starts with '__' [-Wreserved-identifier]
627637-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:522:2: note: expanded from macro 'kfree_data'
627638-FAULT, "%s  522 |         kheap_free(KHEAP_DATA_BUFFERS, elem, size);
627639-      |         ^
627640-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:1389:14: note: expanded from macro 'kheap_free'
627641- 1389 |          alloc_array_size(vm_address  _t arrIPSEay)
627642-      | ^
627643-C_OPT_SET_DELEGATE_INTERFACE %s to %s\n/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:1220:1",
--
660057- 5335 |                                         NECPLle exOG0(Ltern OG_ERvoid R, "F     ailed      to f     ind a fre     e agg     regat     e r   oute    rule        id.\n   \
660058-");
660059-            |                                                                                 ^
660060-|                                         ^
660061-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/priority_queue.h:7131041:6: :1:note: expanded from macro 'NECPLOG0'
660062- warning: identifier '_priority_queue_remove_root' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
660063: 1041 |             os_log_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/priority_queue.h:696:81error: note: expanded from macro 'PRIORITY_QUEUE_MAKE'
660064-(necp_log_handle, "%s:   696 |      %s\n", __FUNCTION__, msg);                                   \
660065-      |             ^
660066-      /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396:5: note: expanded from macro 'os_log_error'
660067-  396 |     _Static_ass     ert(__b             uilti     n_const             ant_p(format),          "format string      must  \
660068-      | be constant                                                                                ^
660069-");             \
660070-      /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/priority_queue.h:677:81: note: expanded from macro '\
660071-PRIORITY_QUEUE_MAKE_BASE'|     ^
660072-
660073-  677 | __pqueue_overload/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c:5335:6able extern pqelem_: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
--
672593-:
672594-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSCollection.h:33:
672595-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/thread.h:116:
672596-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/sched.h 1049 |         os_l:
672597-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSObject.h:37:
672598-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.h:77:
672599:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/bits.h:277:2og_error:37:
672600-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:72:
672601-: warning: identifier '__elem' is reserved because it starts with '__' [-Wreserved-identifier]
672602-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:522:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kern_types.h:36:
672603-(necp2: note: expanded from macro 'kfree_data'
672604-_da  522 |         kheaIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_types.h:80:
672605-ta_trp_free(KIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/host_info.h:66:
672606-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/message.h:824ace_log_HEAP_:6: warning: identifier '__ovr' is reserved because it starts with '__' [-Wreserved-identifier]
672607-  824DATA_handl |         if BUFFERS,e, "%( elem, rounds: " size)_msg_f;
672608-      |         ^
672609-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:1389:14overformat "\: note: expanded from macro 'kheap_free'
--
685567-      | T%d / 0x%X) (%d /E_KQ_          ^
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
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sun Nov  8 07:13:32 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
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
