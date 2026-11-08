# Why the build failed

run: 64, commit 3b13c24403e387c7ef113ebdcb14e4c27b5567ce

## component-NioUfs.log

### the errors

```
29:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:931:13: error: unused function 'cacheCivac' [-Werror,-Wunused-function]
32:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:943:13: error: unused function 'cacheInvalidate' [-Werror,-Wunused-function]
```

### around them

```
23-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:141:34: note: expanded from macro 'kIOReturnError'
24-  141 | #define kIOReturnError           iokit_common_err(0x2bc) // general error
25-      |                                  ^~~~~~~~~~~~~~~~~~~~~~~
26-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:136:71: note: expanded from macro 'iokit_common_err'
27-  136 | #define iokit_common_err(return )          (sys_iokit|sub_iokit_common|return)
28-      |                                             ~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~
29:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:931:13: error: unused function 'cacheCivac' [-Werror,-Wunused-function]
30-  931 | static void cacheCivac (const void *start, size_t length)
31-      |             ^~~~~~~~~~
32:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:943:13: error: unused function 'cacheInvalidate' [-Werror,-Wunused-function]
33-  943 | static void cacheInvalidate (const void *start, size_t length)
34-      |             ^~~~~~~~~~~~~~~
35-13 warnings and 2 errors generated.
36-
```

### the tail

```
6:34: note: expanded from macro 'kIOReturnNotPrivileged'
  146 | #define kIOReturnNotPrivileged   iokit_common_err(0x2c1) // privilege violation
      |                                  ^~~~~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:136:71: note: expanded from macro 'iokit_common_err'
  136 | #define iokit_common_err(return )          (sys_iokit|sub_iokit_common|return)
      |                                             ~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:2521:48: warning: operand of ? changes signedness: 'int' to 'uint32_t' (aka 'unsigned int') [-Wsign-conversion]
 2520 |     gRootDiagnostic.result = result.phase == UfsRootPhase::Identity ? kIOReturnNotPrivileged :
      |                            ~
 2521 |       result.phase == UfsRootPhase::Schedule ? kIOReturnNoResources : kIOReturnError;
      |                                                ^~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:143:34: note: expanded from macro 'kIOReturnNoResources'
  143 | #define kIOReturnNoResources     iokit_common_err(0x2be) // resource shortage
      |                                  ^~~~~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:136:71: note: expanded from macro 'iokit_common_err'
  136 | #define iokit_common_err(return )          (sys_iokit|sub_iokit_common|return)
      |                                             ~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:2521:71: warning: operand of ? changes signedness: 'int' to 'uint32_t' (aka 'unsigned int') [-Wsign-conversion]
 2520 |     gRootDiagnostic.result = result.phase == UfsRootPhase::Identity ? kIOReturnNotPrivileged :
      |                            ~
 2521 |       result.phase == UfsRootPhase::Schedule ? kIOReturnNoResources : kIOReturnError;
      |                                                                       ^~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:141:34: note: expanded from macro 'kIOReturnError'
  141 | #define kIOReturnError           iokit_common_err(0x2bc) // general error
      |                                  ^~~~~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:136:71: note: expanded from macro 'iokit_common_err'
  136 | #define iokit_common_err(return )          (sys_iokit|sub_iokit_common|return)
      |                                             ~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:931:13: error: unused function 'cacheCivac' [-Werror,-Wunused-function]
  931 | static void cacheCivac (const void *start, size_t length)
      |             ^~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:943:13: error: unused function 'cacheInvalidate' [-Werror,-Wunused-function]
  943 | static void cacheInvalidate (const void *start, size_t length)
      |             ^~~~~~~~~~~~~~~
13 warnings and 2 errors generated.

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
51377:eode_notify_setextdattr, /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:1589:2: with error: 0x%x\n", err);
56597:e_mac 1413 |                                          h_v   "(ouckcdherata_memcpy error: %d, length: %ld)\n_t __attribute_",
64480:_call__ ## check, void *, mpc, In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/pthread/workqueue_internal.h:70int, error:
68649:void *, mpc, int, /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/vfs/vfs_cache.c:3036:3error: warning: identifier '__it' is reserved because it starts with '__' [-Wreserved-identifier]
566185:ttribute__((uount or /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/net_api_stats.h:159:12error: note: expanded from macro 'INC_ATOMIC_INT64_LIM'
613589:to allocate memory. Error 0x%x\n", ret);
631265:availability of LZ4. Error 0x%x\n", __func__, ret);
654056:  102 |                 printf("progress_notify_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
677888:  272 |                 printf("zlib_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
690700:  143 |                 printf("%s failed to allocate memory. Error 0x%x\n", __func__, retIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOGuardPageMemoryDescriptor.cpp:29:
703770: 1049 |         os_log/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_host.h:1064:4_error: warning: identifier '__Reply__host_lockgroup_info_t' is reserved because it starts with '__' [-Wreserved-identifier]
714829: 1049 |         os_logIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_eventlink.c_error:37:
745825:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSCollectionIterator.h_error:117:12: warning: identifier '__padding' is reserved because it starts with '__' [-Wreserved-identifier]
776180:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/host_priv.h:432 1049 |         os_log_error:4: warning: identifier '__Request__host_reboot_t' is reserved because it starts with '__' [-Wreserved-identifier]
1104079:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/host_info.hexc_subsystemig_reply_error:278:_t(__unused mig 8: warning: {
1176832:6_t)     atomic_u 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalint_least16_t;
1176857:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdatomic.h:120:9 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
1176987:"   55| error:fla jitter %dmsg { at too big (laten |         char            __omic_bool _Vacy lue; %dms)",
1177031: 1438 |                     "| error: loss recovery %dms too big",
1177090:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/arm/thread_status.h   "| ti error: output interval %dms tme() */
1463771:t;STARTUP_AR/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h       /* byte count or error:G(sysc64:2: note: expanded from macro 'os_ptr_load_and_erase' */
1492244: 2626 |                 FDLOG(LOG_ERR, fd_cb, "failed to get the close error: %d", error);
1495766: 4398 |                                 FDLOG(LOG_DEBUG, &nil_pcb, "ctl_enqueuembuf returned an error: %d", error);
1541588:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
1541926:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
1552502:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
1552514:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
1574598:  202 |     _firehose_tracepoint_type_trace_error:1: warning: identifier '__arm_pagein_state' is reserved because it starts with '__' [-Wreserved-identifier]
1641893:  275 |         SASEL_LOG("Returned with error: %d", err);
2292061: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
2292102:n_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
2772467:Undefined symbols for architecture arm64:
2772476:ld: symbol(s) not found for architecture arm64
2772477:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
2772478:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
2772479:make[2]: *** [build_all] Error 2
2772480:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
2772481:make: *** [build] Error 2
```

### around them

```
51371-      |                                                                                          %x
51372- 1355 |                             (corefile_fallback_size_bytes / (1024ULL * 1024ULL)), err);
51373-      |                                                                                   ^~~
51374-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1364:76: warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
51375- /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/vfs/vfs_bio.c1364 |                 IOLog("IOPolledFilePollersSetup for c/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:634:2: warning: identifier '__dtrace_a0' is reserved because it starts with '__' [-Wreserved-identifier]
51376-:  634 |         MAC_PERFO141:orefil8e failRM(vn: warning: identifier '__zalloc__buf_hdr_zone__type_name' is reserved because it starts with '__' [-Wreserved-identifier]
51377:eode_notify_setextdattr, /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:1589:2: with error: 0x%x\n", err);
51378-      |                                                                                   ~~     ^~~
51379-      cred, vp, m|                                                                                   %x
51380- note: expanded from macro 'ZONE_DEFINE_TYPE'
51381-ac_vnode_ 1589 |         __ZONE_DECLARE_TYPE(var, type_t)
51382-      |         ^
51383-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:927:42: note: expanded from macro '__ZONE_DECLARE_TYPE'
51384-label(vp), name, uio);
51385-      |   927 |         ^
51386-#define __ZO/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:313:10:NE_ note: expanded from macro 'MAC_PERFORM'
51387-  313 |            DEC   LAR  ME_TYPE(vaAC_r, PERtypFORM_Ce_tALL(operation, mpc);       )    \
--
56591-      |           ^
56592-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_host.h:681:4: warning: identifier '__Request__mach_zone_force_gc_t' is reserved because it starts with '__' [-Wreserved-identifier]
56593-  681 |         } __Request__mach_zone_force_gc_t __attribute__((unused));
56594-      |           ^
56595-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_host.h:694:4: warning: identifier '__Request__host_create_mach_voucher_t' is reserved because it starts with '__' [-Wreserved-identifier]
56596-  694 |         } __Request__h/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26ost_creat: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
56597:e_mac 1413 |                                          h_v   "(ouckcdherata_memcpy error: %d, length: %ld)\n_t __attribute_",
56598-      |                                                                                ~~~
56599-      |                                                                                %zu
56600-_(( 1414 | unu                                            sedpat));h, 
56601-      | mc_          ^
56602-error, fatal_failure_desc_len);
56603-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
56604-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_host.h:710:4: warning: identifier '__Request__host_register_mach_voucher_attr_manager_t' is reserved because it starts with '__' [-Wreserved-identifier]
56605-  710 |         } __Request__host_reg/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
56606-i 1418 |                                     "(os_reason_alster_mach_voucherloc_attr__bumanffeager er_trror:  __attrib%d,ute kc__(da(unta erruseor:d)) %d;
56607-      , l|           ^
--
64474-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/mount_internal.h:85:
64475-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/vfs_context.h/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:2119:2: warning: identifier '__dtrace_a2' is reserved because it starts with '__' [-Wreserved-identifier]
64476-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:265:14: note: expanded from macro 'MAC_CHECK':9
64477-  265 | :
64478-In file included from                     DT/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/user.h:RACE_MACF3(mac_89:
64479-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/eventvar.h:71:
64480:_call__ ## check, void *, mpc, In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/pthread/workqueue_internal.h:70int, error:
64481-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/mpsc_queue.h, int, MAC:217:_ITERATE_CHECK)2:; \
64482-      |                     ^
64483-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h warning: :165:2: note: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
64484-expanded from macro 'DTRACE_MACF3'
64485-  165 |         /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic_private.h:345:DTRACE_P39: note: expanded from macro 'os_atomic_store'
64486-R  345OBE3(__sdt_ | In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/RootDomainUserClient.cpp:34:
64487-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:49:
64488-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/system.h:36:
64489-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/thread.h:88:
64490-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_types.h:80:
--
68643-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:265:14: note: expanded from macro 'MAC_CHECK'
68644-  265 |                     DTRACE_MACF3(mac__call__ #In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/RootDomainUserClient.cpp:34:
68645-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:49# c:
68646-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/system.hhec:41:
68647-k, In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_interface.h:45:
68648-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:955:4: warning: identifier '__Request__task_create_t' is reserved because it starts with '__' [-Wreserved-identifier]
68649:void *, mpc, int, /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/vfs/vfs_cache.c:3036:3error: warning: identifier '__it' is reserved because it starts with '__' [-Wreserved-identifier]
68650-, 3036 |                  int,smrq_ MAC_ITERAserialized_f  955TEoreach_ |         } _safe(_Requentryest__, oldtask__headcreat, nc_e_t _hash)_attr {
68651-      | ibute                ^
68652-_CHECK); \
68653-      /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/smr.h:395:19: __((note: |                     ^
68654-expanded from macro 'smrq_serialized_foreach_safe'
68655-unused  395 |         for )/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:165:2: note: expanded from macro 'DTRACE_MACF3'
68656-();
68657-        165 |         |           ^
68658-DTRACE_PROBE3(___/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:sdt_,965:4:  namewarning: identifier '__Request__task_terminate_t' is reserved because it starts with '__' [-Wreserved-identifier]
68659-  965 |         } , arg__Re1, arquestg2, a__tasrg3);k_ter
--
566179-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/arm/_types.h);
566180-      |           ^
566181-  558 | :97:33:                         warning: identifier '__darwin_ssize_t' is reserved because it starts with '__' [-Wreserved-identifier]
566182-I   97/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:1870: | ty4: pedwarning: identifier '__Reply__mach_port_assert_attributes_t' is reserved because it starts with '__' [-Wreserved-identifier]
566183-ef NC_long                    __darwin_ssize_t;       /* ATObytMI 1870 |         } _e c_RC_Ieply__machNT64_LI_port_assert_attributes_t __aM(
566184-      |                         ^
566185:ttribute__((uount or /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/net_api_stats.h:159:12error: note: expanded from macro 'INC_ATOMIC_INT64_LIM'
566186-nused));
566187-      |           ^
566188- */  /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:1880:7: warning: 
566189-      | 159 |         } while (!OSCompareAndSwap64(videntifier '__ReplyUnion__mach_port_subsystem' is reserved because it starts with '__' [-Wreserved-identifier]
566190-                                ^
566191- 1880 | unio/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/arm/_types.h:98n _:33: warning: identifier '__darwin_time_t' is reserved because it starts with '__' [-Wreserved-identifier]
566192-al, va_ReplyUni   98 | typon__mach_port_sl +ubedesysf ltem {
566193-      |       ^
566194-ong    1,    &(      cou   nte   r))  _); _da   rwi   n_t \
566195-ime      |                   ^_t;
--
703764-      |                                                                                            ^~~~~~
703765-nused/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h(OS_ATOMIC_STD memory_order ord)
703766-      | ^
703767-));
703768-      |           ^
703769-:1049:77: note: expanded from macro 'NECPDATATRACELOG'
703770: 1049 |         os_log/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_host.h:1064:4_error: warning: identifier '__Reply__host_lockgroup_info_t' is reserved because it starts with '__' [-Wreserved-identifier]
703771- 1064 |         } __Reply__host_lockgroup_info_t __attribute__((unused));
703772-      |           ^
703773-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_host.h:1078:4: warning: identifier '__Reply__host_statistics64_t' is reserved because it starts with '__' [-Wreserved-identifier]
703774- 1078 |         } __Reply(necp_data_trace_log_handle, "%s: " format "\n", __FUNCTION__, __VA_AIn file included from RGS__); \
703775-      |                                                         ~~~~~~                     ^~~~~~~~~~~
703776-__host_statistics64_t __attribute__((unused));
703777-      |           ^
703778-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:398:41: note: expanded from macro 'os_log_error'
703779-  398 |     _os_log_verif/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_host.h:1096:4y_format_str(format, ##__VA_ARGS__);                                     : warning: identifier '__Reply__mach_zone_info_t' is reserved because it starts with '__' [-Wreserved-identifier]
703780- 1096 |         }/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_entry.c __Reply__mach_zone_info:69:
--
714823-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c:663:117: note: expanded from macro 'NECP_DATA_TRACE_LOG_CONDITION3'
714824-  662 |     NECPDATATRACELOG(LOG_ERR, "DATA-TRACE <%s>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>", \
714825-      |     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
714826-  663 |                 caller, negate ? "!":"", name, val1, val1, val2, val2, val3, val3, input1, input1, input2, input2, input3, input3); \
714827-      |                 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~
714828-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:77: note: expanded from macro 'NECPDATATRACELOG'
714829: 1049 |         os_logIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_eventlink.c_error:37:
714830-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/ipc_tt.h:66:
714831-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/ipc_kobject.h:77:
714832-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_port.h:91:
714833-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_space.h(necp_data_trace_log_handle, "%s: " format "\n", __FUNCTION__, __VA_ARGS__); \
714834-      |         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~
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
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sun Nov  8 17:53:11 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
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

## build-nio-ufs_compile.log

### the errors

```
74:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:931:13: error: unused function 'cacheCivac' [-Werror,-Wunused-function]
77:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:943:13: error: unused function 'cacheInvalidate' [-Werror,-Wunused-function]
```

### around them

```
66- 2521 |       result.phase == UfsRootPhase::Schedule ? kIOReturnNoResources : kIOReturnError;
67-      |                                                                       ^~~~~~~~~~~~~~
68-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:141:34: note: expanded from macro 'kIOReturnError'
69-  141 | #define kIOReturnError           iokit_common_err(0x2bc) // general error
70-      |                                  ^~~~~~~~~~~~~~~~~~~~~~~
71-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:136:71: note: expanded from macro 'iokit_common_err'
72-  136 | #define iokit_common_err(return )          (sys_iokit|sub_iokit_common|return)
73-      |                                             ~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~
74:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:931:13: error: unused function 'cacheCivac' [-Werror,-Wunused-function]
75-  931 | static void cacheCivac (const void *start, size_t length)
76-      |             ^~~~~~~~~~
77:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:943:13: error: unused function 'cacheInvalidate' [-Werror,-Wunused-function]
78-  943 | static void cacheInvalidate (const void *start, size_t length)
79-      |             ^~~~~~~~~~~~~~~
80-13 warnings and 2 errors generated.
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
