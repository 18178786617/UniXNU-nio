# Why the build failed

run: 95, commit eaa626cdc7387dafd71092185af02299faed218b

## component-NioUfs.log

### the errors

```
1:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:35:10: fatal error: 'verified_root.h' file not found
```

### around them

```
1:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:35:10: fatal error: 'verified_root.h' file not found
2-   35 | #include "verified_root.h"
3-      |          ^~~~~~~~~~~~~~~~~
4-1 error generated.
5-
```

### the tail

```
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:35:10: fatal error: 'verified_root.h' file not found
   35 | #include "verified_root.h"
      |          ^~~~~~~~~~~~~~~~~
1 error generated.

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
53572:ailed with error: 0x%x\n", err);
55385: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
55391: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
66583:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/RootDomainUserClient.cpp:34/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/vfs/vfs_cache.c  265 |                     DTRACE_MACF3(mac__call__ ## check, void *, mpc, int, error::
166983:eply_error: :154:2: warning: identifier '__step_err' is reserved because it starts with '__' [-Wreserved-identifier]
491875:  158 |                 printf("buffer_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
512551:  268 |                 printf("(%s) Failed to handle availability of LZ4. Error 0x%x\n", __func__, ret);
541399:ry. Error 0x%x\n", ret);
565396:  272 |                 printf("zlib_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
573950:  143 |                 printf("%s failed to allocate memory. Error 0x%x\n", __func__, ret);
849552:  932 |                 NECPLOG(LOG_ERR, "necp_session_add_policy tlv copyin eIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/compact_id.cemwairror (%d)", error:t)29:
937171: 1049 |         os_log_error:130:9: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
1022679:  839 | typedef struct { unsigned lon/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_map.h:936g 1049 |         os_log_error:4: warning: identifier '__Request__vm_purgable_control_t' is reserved because it starts with '__' [-Wreserved-identifier]
1035301: 1049 |         os_log_error:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.c:1468:27: warning: '_Alignof' is incompatible with C standards before C11 [-Wpre-c11-compat]
1297710:      ETEM_LOG(LOG_ERR, "| error: co|                     ^
1297784: 1771 | __kheERR, "| error: dupli  ap_realloc(
1297863: 1413 |                     "| error: latency %d too big (> 1 sec)",o_atomic_pointer(p)))
1297931: 1420 |    73 | __nosan_strlcpy(char *__sized_by(sz)dst, const ch(                    "| error: jittev); ___v; })
1297963:   881438 |                     "| error: loss recovery %dms too big",
1297994: In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/sched_multiq.c:1456 |                 NETEM_LOG(LOG_ERR, "| error: rem29ord:
1546632: 2626 |                 FDLOG(LOG_ERR, fd_cb, "failed to get the close error: %d", error);
1595817:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
1596313:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
1605323:rnal error: "
1667357:   /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.h:729:12: note: expanded from macro '__STARTUP1'64 | L_LOG("Returned with error: %d"
1985771::nt __#/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/kern_mman.c warning:  pagein:nam1445identifier '_os_atomic_mo_has_acquire' is reserved because it starts with '_' at global scope [-Wreserved-identifier]_error:2:e; warning: identifier '__kfree_size' is reserved because it starts with '__' [-Wreserved-identifier]
2079026:startup_SYSCTL_en736 | try_sysctl__kern__memorystatus_freezer_error:2: note: expanded from macro '__STARTUP_ARG'
2242173:  113 | __NDR_convert__mig_rep_ref_at/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:1749:1oly_error:m_t(_ icwarning: identifier '__krealloc_ext' is reserved because it starts with '__' [-Wreserved-identifier]
2295772:545 |           1432 |         KALLOC_DISPATCH1(base, KALLOC_COUNT_ARGS(__VA_ARGS599:41:            "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n__),    __vmnekf_unused:28;
2658113:n/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/skywalk/os_packet.hject_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/skywalk/os_stats_private.h2error::, 0, _t  982"Du 486:8: warning: midentifier '__kern_buflet' is reserved because it starts with '__' [-Wreserved-identifier]          :1: 
2772470:Undefined symbols for architecture arm64:
2772479:ld: symbol(s) not found for architecture arm64
2772480:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
2772481:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
2772482:make[2]: *** [build_all] Error 2
2772483:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
2772484:make: *** [build] Error 2
```

### around them

```
53566-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:162:2: note: expanded from macro 'DTRACE_MACF2'
53567-  162 |         DTRACE_PROBE2(__sdt_, name, arg1, arg2);
53568-      |         ^
53569-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:128:29: note: expanded from macro 'DTRACE_PROBE2'
53570-  128 |                 register uintptr_t __dtrace_a1 asm("x1") = (uintptr_t) arg1;                    \
53571-      |                                    ^
53572:ailed with error: 0x%x\n", err);
53573-      |                                                                                   ~~     ^~~
53574-      |                                                                                   %x
53575-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:760:2: warning: identifier '__dtrace_a0' is reserved because it starts with '__' [-Wreserved-identifier]
53576-  760 |         MAC_PERFORM(vnode_label_update_extattr, mp, mac_mount_label(mp), vp,
53577-      |         ^
53578-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:313:10: note: expanded from macro 'MAC_PERFORM'
53579-  313 |                 MAC_PERFORM_CALL(operation, mpc);           \
53580-      |                 ^
53581-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:303:42: note: expanded from macro 'MAC_PERFORM_CALL'
53582-  303 | #define MAC_PERFORM_CALL(operation, mpc) DTRACE_MACF3(mac__call__ ## operation, void *, mpc, int, 0, int, MAC_ITERATE_PERFORM)
--
55379- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
55380-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
55381-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
55382-  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
55383-      |                 ~~               ^~~~~~~~~~~
55384-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
55385: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
55386-      |                                                                                ~~~
55387-      |                                                                                %zu
55388- 1414 |                                             path, mc_error, fatal_failure_desc_len);
55389-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
55390-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
55391: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
55392-      |                                                                                                   ~~~
55393-      |                                                                                                   %zu
55394- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
55395-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
55396-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
55397- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
55398-      |                             ^
55399-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
55400- 1426 |                 zfree(ZV_NAMEI, vn_path);
55401-      |                 ^
--
66577-      |         ^
66578-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:139:29: note: expanded from macro 'DTRACE_PROBE3'
66579-  139 |                 register uintptr_t __dtrace_a0 asm("x0") = (uintptr_t) arg0;                    \
66580-      |                                    ^
66581-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:2366:2: warning: identifier '__dtrace_a1' is reserved because it starts with '__' [-Wreserved-identifier]
66582-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:265:14: note: expanded from macro 'MAC_CHECK'
66583:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/RootDomainUserClient.cpp:34/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/vfs/vfs_cache.c  265 |                     DTRACE_MACF3(mac__call__ ## check, void *, mpc, int, error::
66584-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:44:
66585-2883:3: warning: ,/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/overflow.h:49:1: warning: identifier '__os_warn_unused' is reserved because it starts with '__' [-Wreserved-identifier]
66586-format specifies type 'unsigned int' but the argument has type 'int' [-Wformat]
66587-    49 | __os_warn_unus ed(__conint,2883st bool x)
66588-      | ^
66589- |                 TAILQ_INSERT_HEAD(&dvp->v_ncchildren, ncp, nc_child);
66590-      |                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
66591-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/queue.h:737:2: note: expanded from macro 'TAILQ_INSERT_HEAD'
66592-  737 |         TAILQ_CHE MAC_ITERATE_CHECK); \
66593-      |                     ^
--
166977-   73 |         volm116atile uint64_ti:
166978-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/sched.hg __val;
166979-      _:77:
166980-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/bits.h:36:
166981-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:1573:2: warning: identifier '__elem' is reserved because it starts with '__' [-Wreserved-identifier]
166982-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/zalloc.h:874:|                           ^r32
166983:eply_error: :154:2: warning: identifier '__step_err' is reserved because it starts with '__' [-Wreserved-identifier]
166984-_t(__unused mig_rnote: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:266:18: expanded from macro 'zfree'
166985-  874 |         (zfree)(_eply_error_t *x)
166986-      | ^note: expanded from macro 'MAC_CHECK'
166987-
166988-_zfree_zone, (void *)os_ptr_load_and_erase(elem)); \
166989-      |                                       ^
166990-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h:67:14: note: expanded from macro 'os_ptr_load_and_erase'
166991-   67 |         __auto_type __elem = *__eptr;   In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOPMrootDomain.cpp:31:
166992-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSAllocation.h:42:
166993-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:49:
--
849546-  501 |         __kheap_alloc(kalloc_heap, size, __zone_flags_mix_tagproc *, struc(flags, itag), NULL/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c:t __sigwait_nocancel_args *, int *);
849547-      |     ^
849548-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/sysproto.h:2907:5: warning: identifier '__semwait_signal_nocancel' is reserved because it starts with '__' [-Wreserved-identifier]
849549- 2907 | int __semwait_signal_nocancel(struct proc *, struct __s)
849550-      |                                                                      ^~~~
849551-932:3: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
849552:  932 |                 NECPLOG(LOG_ERR, "necp_session_add_policy tlv copyin eIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/compact_id.cemwairror (%d)", error:t)29:
849553-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/compact_id.h:34:
849554-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/bits.h:277:2: warning: _;
849555-      |                 ^
849556-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1033:6: note: expanded from macro 'NECPLOG'
849557-signal_nocancel_args 1033 |             os_log_error(neidentifier '__kfree_heap' is reserved because it starts with '__' [-Wreserved-identifier] *, int *);
849558-      |     ^
849559-
849560-  277 |         kfree_data(map, BITMAP_SIZEcp_log_handle, "%s: " format "\n", __FUNCTION__, __VA_A(nbits));
849561-      |         ^
849562-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:522:2: note: expanded from macro 'kfree_data'
--
937165-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSAtomic.h:59:5: note: expanded from macro '__SAFE_CAST_PTR'
937166-   59 |         ({ _Static_assert(sizeof(*(var)) == sizeof(*(type)NULL), "size mismatch"); ((type)(var)); })
937167-      |            ^
937168-%s>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>", \
937169-      |     ^
937170-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSAtomic.h/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:2: note: expanded from macro 'NECPDATATRACELOG'
937171: 1049 |         os_log_error:130:9: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
937172-  130 |         return OSAddAtomic64(-1LL, address);
937173-      |                ^
937174-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSAtomic.h:101:20: note: expanded from macro 'OSAddAtomic64'
937175-  101 |         (OSAddAtomic64(a, __SAFE_CAST_PTR(volatile SInt64*,b)))
937176-      |                           ^
937177-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSAtomic.h:59:5: note: expanded from macro '__SAFE_CAST_PTR'
937178-   59 |         ({ _Static_assert(sizeof(*(var)) == sizeof(*(type)NULL), "size mismatch"); ((type)(var)); })
937179-      |            ^
937180-(necp_data_trace_log_handle, "%s: " format "\n", __FUNCTION__, __VA_ARGS__); \
937181-      |         ^
--
1022673-_order       :
1022674-%d skip_order %d)", \
1022675-      |                                                                                                                                                      ^~
1022676-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic_private.h:839:32: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:50: note: expanded from macro 'NECPDATATRACELOG'
1022677-warning: |           ^
1022678-identifier '__opaque_zero' is reserved because it starts with '__' [-Wreserved-identifier]
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
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Mon Nov  9 17:50:43 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
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
1:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:35:10: fatal error: 'verified_root.h' file not found
```

### around them

```
1:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:35:10: fatal error: 'verified_root.h' file not found
2-   35 | #include "verified_root.h"
3-      |          ^~~~~~~~~~~~~~~~~
4-1 error generated.
```

## status.txt

```
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
patch    70 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-amfi-less-blob-acceleration.patch
patch    71 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-amfi-less-entitlement-queries.patch
patch    72 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kext-data-const-stays-writable.patch
patch    73 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kernel-data-const-stays-writable.patch
patch    74 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-image4-kext.patch
patch    75 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-port-command-line.patch
patch    76 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-boot-args-fallback.patch
patch    77 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kmem-range-landmarks.patch
patch    78 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kmem-scramble-landmarks.patch
patch    79 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kalloc-init-landmarks.patch
patch    80 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-sysctl-walk-guard.patch
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
