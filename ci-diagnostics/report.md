# Why the build failed

run: 35, commit 3e50eae224003de5aedde7a0a93b0d53fbc56f42

## kernel.log

### the errors

```
8007:Undefined symbols for architecture arm64:
8041:ld: symbol(s) not found for architecture arm64
8042:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
8043:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
8044:make[2]: *** [build_all] Error 2
8045:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
8046:make: *** [build] Error 2
```

### around them

```
8001-   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sun Nov  8 05:14:03 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
8002-      |            ^
8003-1 warning generated.
8004-             LD mach.development.bcm2837.unstripped
8005-ld: warning: -new_linker is obsolete
8006-ld: warning: search path '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot/usr/local/lib/kernel/platform' not found
8007:Undefined symbols for architecture arm64:
8008-  "IOBlockStorageDevice::gMetaClass", referenced from:
8009-      NioUfsBlock::MetaClass::MetaClass() in libShengUfs.a[2](NioUfs.o)
8010-      NioUfsBlock::MetaClass::MetaClass() in libShengUfs.a[2](NioUfs.o)
8011-      __GLOBAL__sub_I_NioUfs.cpp in libShengUfs.a[2](NioUfs.o)
8012-      NioUfsBlock::superClass in libShengUfs.a[2](NioUfs.o)
8013-  "IOBlockStorageDevice::requestIdle()", referenced from:
8014-      vtable for NioUfsBlock in libShengUfs.a[2](NioUfs.o)
8015-  "IOBlockStorageDevice::doSetPriority(IOBlockStorageDeviceExtent*, unsigned int, unsigned char)", referenced from:
8016-      vtable for NioUfsBlock in libShengUfs.a[2](NioUfs.o)
8017-  "IOBlockStorageDevice::setProperties(OSObject*)", referenced from:
--
8036-      vtable for NioUfsBlock in libShengUfs.a[2](NioUfs.o)
8037-  "vtable for IOBlockStorageDevice", referenced from:
8038-      NioUfsBlock::start(IOService*) in libShengUfs.a[2](NioUfs.o)
8039-      NioUfsBlock::free() in libShengUfs.a[2](NioUfs.o)
8040-   NOTE: a missing vtable usually means the first non-inline virtual member function has no definition.
8041-ld: symbol(s) not found for architecture arm64
8042:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
8043-make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
8044-make[2]: *** [build_all] Error 2
8045-make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
8046-make: *** [build] Error 2
8047-build-xnu-4k-baseline.sh: line 829: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

### the tail

```
  "IOBlockStorageDevice::gMetaClass", referenced from:
      NioUfsBlock::MetaClass::MetaClass() in libShengUfs.a[2](NioUfs.o)
      NioUfsBlock::MetaClass::MetaClass() in libShengUfs.a[2](NioUfs.o)
      __GLOBAL__sub_I_NioUfs.cpp in libShengUfs.a[2](NioUfs.o)
      NioUfsBlock::superClass in libShengUfs.a[2](NioUfs.o)
  "IOBlockStorageDevice::requestIdle()", referenced from:
      vtable for NioUfsBlock in libShengUfs.a[2](NioUfs.o)
  "IOBlockStorageDevice::doSetPriority(IOBlockStorageDeviceExtent*, unsigned int, unsigned char)", referenced from:
      vtable for NioUfsBlock in libShengUfs.a[2](NioUfs.o)
  "IOBlockStorageDevice::setProperties(OSObject*)", referenced from:
      vtable for NioUfsBlock in libShengUfs.a[2](NioUfs.o)
  "IOBlockStorageDevice::doGetProvisionStatus(unsigned long long, unsigned long long, unsigned int*, IOBlockStorageProvisionDeviceExtent*, unsigned long long)", referenced from:
      vtable for NioUfsBlock in libShengUfs.a[2](NioUfs.o)
  "IOBlockStorageDevice::init(OSDictionary*)", referenced from:
      vtable for NioUfsBlock in libShengUfs.a[2](NioUfs.o)
  "IOBlockStorageDevice::doUnmap(IOBlockStorageDeviceExtent*, unsigned int, unsigned int)", referenced from:
      vtable for NioUfsBlock in libShengUfs.a[2](NioUfs.o)
  "IOBlockStorageDevice::IOBlockStorageDevice(OSMetaClass const*)", referenced from:
      NioUfsBlock::NioUfsBlock(OSMetaClass const*) in libShengUfs.a[2](NioUfs.o)
      NioUfsBlock::NioUfsBlock(OSMetaClass const*) in libShengUfs.a[2](NioUfs.o)
      NioUfsBlock::MetaClass::alloc() const in libShengUfs.a[2](NioUfs.o)
      NioUfsBlock::NioUfsBlock() in libShengUfs.a[2](NioUfs.o)
      NioUfsBlock::NioUfsBlock() in libShengUfs.a[2](NioUfs.o)
  "IOBlockStorageDevice::~IOBlockStorageDevice()", referenced from:
      NioUfsBlock::~NioUfsBlock() in libShengUfs.a[2](NioUfs.o)
      NioUfsBlock::~NioUfsBlock() in libShengUfs.a[2](NioUfs.o)
      NioUfsBlock::~NioUfsBlock() in libShengUfs.a[2](NioUfs.o)
  "IOBlockStorageDevice::getProperty(OSSymbol const*) const", referenced from:
      vtable for NioUfsBlock in libShengUfs.a[2](NioUfs.o)
  "vtable for IOBlockStorageDevice", referenced from:
      NioUfsBlock::start(IOService*) in libShengUfs.a[2](NioUfs.o)
      NioUfsBlock::free() in libShengUfs.a[2](NioUfs.o)
   NOTE: a missing vtable usually means the first non-inline virtual member function has no definition.
ld: symbol(s) not found for architecture arm64
clang++: error: linker command failed with exit code 1 (use -v to see invocation)
make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
make[2]: *** [build_all] Error 2
make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
make: *** [build] Error 2
build-xnu-4k-baseline.sh: line 829: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

## archive-12-build-nio-ufs-archive.log

### the tail

```
nio-ufs: build/nio-ufs/libNioUfs.a -> build/sheng-ufs/libShengUfs.a (454264 bytes, sha256 1a22c5d9cb2f116adbc2f6203e641162a83dfcaa8ab20abe96d00e92bbac5a6a)
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
47580:th error: 0x%x\n", err);
57486:a_memcpy error: %d, length: %ld)\n",
57495:rror: %d, kcdata error: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_map.h:588:%d, length: %ld)\n",
574139:  602 |         int __page/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/smr_types.h:62: i32_Static_assert(sizeof(n_error: note: expanded from macro 'SMR_POINTER_DECL'
653455:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kern_types.h 1049 |         os_lcesog_error:259:16:sor_s(necp_data_tra warning: identifier '_wait_queue_link' is reserved because it starts with '_' at global scope [-Wreserved-identifier]ce_log_handle, "%et_st
682118:Error 0x%x\n", ret);
705116:y. Error 0x%  663 |          x\n", ret       caller);
717790:iled to allocate memory. Error 0x%x\n", _orma_func__, ret);
720873:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.h:736:2 1447 |         } __s_log_error: (necp_data_trace_log_handle, "%s: " fornote: expanded from macro '__STARTUP_ARG'
742173: 1049 |         os_log_error:getNVRAMProperties(), exit, DEBUG_ERROR("parent getNVRAMProperties failed\n"));
743616:nter 1323 |                 #defineface %d requi/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/vm_statistics.h:461re_noerr_action(> <policy_id %error:7: warning: identifier '__unused_bit_22' is reserved because it starts with '__' [-Wreserved-identifier]
744934:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/simple_lock.h, "SOCKEon(error:81:
748756:s_lo/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic.h:81:43g_error: note: expanded from macro 'os_cast_to_nonatomic_pointer'
851011:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic_private.h:342 9947 |                         NECPLOG(LOG_ERR, "necp_client_update_cache copyin tfo cache buffer error:2: (% note: expanded from macro 'os_atomic_store'
1177535:    1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
1177565:    "| error: latency %d too big (> 1 sec)",
1177588: 1420 |                     "| error: jitter %dms too big (late/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/libkern/libkern/arm/OSByteOrder.h:25:1: warning: identifier '_OSSwapInt32' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]
1177634: 1438 |                     "| error: loss recovery %dms too big",
1177645: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
1177664: 1463 |                     "| error: output interval %d/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/_types/_fd_def.h:119:1: warning: identifier '__darwin_fd_set' is reserved because it starts with '__' [-Wreserved-identifier]
1473837: 2626 |                 FDLOG(LOG_ERR, fd_cb, "failed to get the close error: %d", error);
1478698: 4398 |                                 FDLOG(LOG_DEBUG, &nil_pcb, "ctl_enqueuembuf returned an error: %d", error);
1526701:      ranal error: "
1527026:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
1539765:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
1675613:  638 | ZONE_DECLA/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/queue.h:776:2        nd6log(error: note: expanded from macro 'TAILQ_REMOVE'
2292101: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
2292107: 3383 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
2555562:agein_error:1   84 | : warning: identifier '_pthread_priority_make_from_thread_qos_and_override' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
2772466:Undefined symbols for architecture arm64:
2772475:ld: symbol(s) not found for architecture arm64
2772476:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
2772477:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
2772478:make[2]: *** [build_all] Error 2
2772479:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
2772480:make: *** [build] Error 2
```

### around them

```
47574-dFilePo/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:165:2: note: expanded from macro 'DTRACE_MACF3'
47575-  165 |         DllersSetup TRACE_PROfor BE3(__sdt_, name, arg1, arg2, arg3);
47576-      |         ^
47577-cor/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:141:29: note: expanded from macro 'DTRACE_PROBE3'
47578-  141 |                 register uintptr_t __dtrace_a2 asefile m("x2") = (uintptr_t) arg2;  failed wi                  \
47579-      |                                    ^
47580:th error: 0x%x\n", err);
47581-      |                                                                                   ~~     ^~~
47582-      |                                                                                   %x
47583-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:341:2: warning: identifier '__dtrace_a0' is reserved because it starts with '__' [-Wreserved-identifier]
47584-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:315:10: note: expanded from macro 'MAC_PERFORM'
47585-  315 |                 MAC_PERFORM_RSLT(operation, mpc);           \
47586-      |                 ^
47587-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:304:42: note: expanded from macro 'MAC_PERFORM_RSLT'
47588-  304 | #define MAC_PERFORM_RSLT(operation, mpc) DTRACE_MACF2(mac__rslt__ ## operation, void *, mpc, int, 0)
47589-      |                                          ^
47590-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:162:2: note: expanded from macro 'DTRACE_MACF2'
--
57480-_VA_ARGS__, __FILE_NAME__, __/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_map.h:560:4:LINE__); \
57481-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:      |  warning: identifier '__Request__vm_allocate_t' is reserved because it starts with '__' [-Wreserved-identifier]
57482-  560 |         } __Request__vm_allocate_t __attribute__((unuse1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
57483- 1413d) |                                         ~~               ^~~~~~~~~~~
57484-);
57485-      |           ^                    "(kcdat
57486:a_memcpy error: %d, length: %ld)\n",
57487-      |                                                                                ~~~
57488-      |                                                                                %zu
57489- 1414 |                                             path, mc_error, fatal_failure_desc_l/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_map.h:573:4:en);
57490-       warning: |                                                             ^~~~~~~~~~~~~~~~~~~~~~
57491-identifier '__Request__vm_deallocate_t' is reserved because it starts with '__' [-Wreserved-identifier]
57492-  573 |         } __Requ/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
57493-est__vm_deallo 1418 |                                     "(os_reason_alloc_buffer ecate_t __attribute__((unused));
57494-      |           ^
57495:rror: %d, kcdata error: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_map.h:588:%d, length: %ld)\n",
57496-      |                                                                                                   ~~~
57497-      |                                                                                                   %zu
57498-4:  1419 |                                     pathwarning: identifier '__Request__vm_protect_t' is reserved because it starts with '__' [-Wreserved-identifier]
57499-  588 |         } __Reque, reason_error, kcst__vm_protect_t __attribute__dat((unused));
57500-      |           ^
57501-a_error, fatal_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_map.h:602:4: warning: identifier '__Request__vm_inherit_t' is reserved because it starts with '__' [-Wreserved-identifier]
57502-failure_desc_le  602 |         } __Request__vm_inherit_t __attrn);
57503-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~ib
57504-ute_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
57505- _((unused));
--
574133-e _/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSAtomic.h:59:5: note: expanded from macro '__SAFE_CAST_PTR'
574134-71 | STRUCT_ARM_PAGEIN_STATE struct __arm_pagein_state
574135-      |                                         ^
574136-   59 |         ({/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/_structs.h        SM:602:R_P6: OINTER_DECL(, type_t)
574137-      |         ^
574138-warning: identifier '__pagein_error' is reserved because it starts with '__' [-Wreserved-identifier]
574139:  602 |         int __page/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/smr_types.h:62: i32_Static_assert(sizeof(n_error: note: expanded from macro 'SMR_POINTER_DECL'
574140-;
574141-         62 |         *(var)) == sizeof(*(type)NUL| sL            ^
574142-), "size mismatch"); ((type)(var)); })
574143-      |            ^
574144-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/kpi_interfacefilter.c:34:
574145-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/kern_event.h:41:
574146-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/sys_domain.h:38:
574147-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/sysctl.h:1014:
574148-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/proc_internal.h:147:8: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
574149-  147 |         dev_t _Atomic           s_ttydev;            /* (SL) tty's device     */
--
653449-  247ongjmp(
653450-      |            ^
653451-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h: |         }1049:77 __Re: note: expanded from macro 'NECPDATATRACELOG'
653452-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kdp/output_stages/out_lz4.c:34:
653453-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:quest__pro65:
653454-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/zalloc.h:72:
653455:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kern_types.h 1049 |         os_lcesog_error:259:16:sor_s(necp_data_tra warning: identifier '_wait_queue_link' is reserved because it starts with '_' at global scope [-Wreserved-identifier]ce_log_handle, "%et_st
653456-  259 | s: " foratistics_t typedef mat "\n", __FU__attribstruct _waiNCTION__, _ute_VA_ARGSt_queue___((u__); \
653457-      |                                                         ~~~~~~                     ^~~~~~~~~~~
653458-link *n/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:wai398:41: note: expanded from macro 'os_log_error'
653459-tused));
653460-      | _queue_l  398 |     _os_log          ^
653461-_verif/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/processor_set.h:257:4:y_forink_t;
653462-       warning: identifier '__Request__processor_set_destroy_t' is reserved because it starts with '__' [-Wreserved-identifier]
653463-mat_str(for|                ^
653464-mat, ##__VA_ARGS__);                                           \
653465-      |                               ~~~~~~    ^~~~~~~~~~~
--
720867-unused)/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h
720868-note: :1049:77:);
720869- note: expanded from macro 'NECPDATATRACELOG'
720870-(skipping 1 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)
720871-      |           ^
720872- 1049 |         o/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:1447:4: warning: identifier '__Reply__mach_port_set_mscount_t' is reserved because it starts with '__' [-Wreserved-identifier]
720873:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.h:736:2 1447 |         } __s_log_error: (necp_data_trace_log_handle, "%s: " fornote: expanded from macro '__STARTUP_ARG'
720874-  736 |         __STARTUP1(nameReply__macmat "\n", linh_port_sete, subsyst_mscount, __FUNCTION__, __em, rank_t __VA_ARGS_, funattribut_); \c, are__((unused));
720875-
720876-      |         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~
720877-      | g,           ^
720878-arg)
720879-      |         ^
720880-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.h/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:1463:727:2: :4: warning: identifier '__Reply__mach_port_get_set_status_t' is reserved because it starts with '__' [-Wreserved-identifier]
720881-note: expanded from macro '__STARTUP1'
720882- 1463/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:399 |         } _  727 |         __start_Reply__mach_port:76: note: expanded from macro 'os_log_error'
720883-  up_ ## sub399 |     _os_log_internal(&__ds_get_set_status_t __atystem ## _entryso_handltribu_ ## name, lote__(e ## _ (unusg, OS## line ed));
--
742167-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IONVRAMV3Handler.cpp:317:69olicy_id): warning: format specifies type 'unsigned int' but the argument has type 'int' [-Wformat]
742168-; \q);
742169-      |   317 |         require_action(IODTNVRAMFormatHandler:
742170-                                   ^
742171-      |                                                                                                                                                                                                       ^~~~~~~~~~~~~~~~~~~
742172-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:77: note: expanded from macro 'NECPDATATRACELOG'
742173: 1049 |         os_log_error:getNVRAMProperties(), exit, DEBUG_ERROR("parent getNVRAMProperties failed\n"));
742174-      |                                                                            ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
742175-(necp_data/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IONVRAM.cpp:_trace_log_handle, "92:21: note: expanded from macro 'DEBUG_ERROR'
742176-   92 | #define D%s: " format "\n", __FUNCTION__, __VA_AREBUG_ERROR DEBUG_ALWAYS
742177-      |                     ^
742178-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IONVRAM.cpp:84:56: note: expanded from macro 'DEBUG_ALWAYS'
742179-   84 |         IOLog("%s:%s:%u - " fmt, __FILE_NAME__, __FUNCTION__, __LINE__, ##args); \
742180-      |                      ~~                                       ^~~~~~~~
742181-GS__); \
742182-      |                                                         ~~~~~~                     ^~~~~~~~~~~
742183-<scratch space>:77:1: note: expanded from here/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:398:41: note: expanded from macro 'os_log_error'
--
743610-<pUNCi/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/vm_statistics.h:460:7: warning: identifier '__unused_bit_21' is reserved because it starts with '__' [-Wreserved-identifier]
743611-  460d=%d TIOAppli |                     __unN__, __LINE__, ##args); \
743612-      cat|                             ~~~                                           ^~~~
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
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sun Nov  8 05:13:03 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
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
