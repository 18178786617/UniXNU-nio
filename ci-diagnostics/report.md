# Why the build failed

run: 23, commit 4a618d34f46b24b41561830593cb927103c21f6a

## archive-08-build-libpthread-kernel.log

### the tail

```
      |                                            ~
  843 |                         .pc = (int)wqstart_fnptr,
  844 |                         .r[0] = (unsigned int)addrs->self,
  845 |                         .r[1] = (unsigned int)kport,
  846 |                         .r[2] = (unsigned int)addrs->stack_bottom,
  847 |                         .r[3] = (unsigned int)kevent_list,
  848 |                         // will be pushed onto the stack as arg4/5
  849 |                         .r[4] = (unsigned int)upcall_flags,
  850 |                         .r[5] = (unsigned int)kevent_count,
  851 | 
  852 |                         .sp = (int)(addrs->stack_top)
      |                               ^~~~~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:901:4: warning: implicit conversion changes signedness: 'int' to 'unsigned int' [-Wsign-conversion]
  898 |         ret = pthread_kern->kevent_workq_internal(p, eventlist, nevents,
      |               ~~~~~~~~~~~~
  899 |                         kevent_list, WQ_KEVENT_LIST_LEN,
  900 |                         data_buf, &data_available,
  901 |                         kevent_flags, kevent_count_out);
      |                         ^~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:979:36: warning: implicit conversion changes signedness: 'unsigned int' to 'int' [-Wsign-conversion]
  979 |                 workq_kevent(p, &th_addrs, 0, 0, flags, &kevent_list, &kevent_count);
      |                 ~~~~~~~~~~~~                     ^~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:983:17: warning: implicit conversion changes signedness: 'int' to 'uint32_t' (aka 'unsigned int') [-Wsign-conversion]
  982 |         workq_set_register_state(p, th, &th_addrs, kport,
      |         ~~~~~~~~~~~~~~~~~~~~~~~~
  983 |                         kevent_list, upcall_flags, kevent_count);
      |                                      ^~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:1007:54: warning: implicit conversion changes signedness: 'unsigned int' to 'int' [-Wsign-conversion]
 1007 |         error = workq_kevent(p, &th_addrs, events, nevents, flags,
      |                 ~~~~~~~~~~~~                                ^~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:1018:17: warning: implicit conversion changes signedness: 'int' to 'uint32_t' (aka 'unsigned int') [-Wsign-conversion]
 1017 |         workq_set_register_state(p, th, &th_addrs, kport,
      |         ~~~~~~~~~~~~~~~~~~~~~~~~
 1018 |                         kevent_list, upcall_flags, kevent_count);
      |                                      ^~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work/kern/kern_support.c:1049:34: warning: implicit conversion changes signedness: 'int' to 'uint32_t' (aka 'unsigned int') [-Wsign-conversion]
 1049 |                 pthread_mutex_default_policy = policy_bootarg;
      |                                              ~ ^~~~~~~~~~~~~~
22 warnings and 1 error generated.

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
51848: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
57178: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
57184: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
336648:em_t l/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/skywalk/os_packet_private.hy_error: _d ERESTARTt416:26: warning: identifier '__q_len' is reserved because it starts with '__' [-Wreserved-identifier]
456547:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/iokit/IOKit/IOService.h:399:2_error: warning: identifier '_ClaimSystemWakeEvent_Invoke' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]AS
530602:      (bility of LZ4. :p)  Error 0x%x\n   "warning:  (__ty| ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
553966:  102 |                 printf("progress_notify_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
569005:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/mig_errors.h:113107unt or error:
575633:  272 |                 printf("zlib_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
590429:  143 |                 printf("%s failed to allocate memory. Error 0x%x\n", __func__, ret);
624246:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/priority_queue.h:677:81: note: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.ht or error:expanded from macro '\
783481: copyin error (%d)", error:45: note: expanded from macro '__container_of'
805665: 6031 |                                                 NECPLOG0(LOG_DEBUG, "Error 209In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IODMAEventSource.cpp:31:
823729:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/cdefs.h:1089os_lo    g_error:45: note: expanded from macro '__container_of'
844162:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/processor_set.h:247:4: warning: :%X) (%d / 0x%X) input (%79 |             osd / 0_:69xlog_error:%X( note: expanded from macro 'os_cast_to_atomic_pointer'
873923: 1049 |         os_log_error:
980200:error:875:_address_t arr(/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/priority_queue.h:anecp_data_trace_log_handly2:)
1270180: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
1270191: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
1270211: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
1270222: 1413 |                     "| error: latency %d too big (> 1 sec)",
1270233: 1420 |                     "| error: jitter %dms too big (latency %dms)",
1270250: 1420 |                     "| error: jitter %dms too big (latency %dms)",
1270261: 1438 |                     "| error: loss recovery %dms too big",
1270272: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
1270283: 1463 |                     "| error: output interval %dms too big",
1331912:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic_private.hount or/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_param.h: error:433:6: warning: identifier '__ovr' is reserved because it starts with '__' [-Wreserved-identifier]
1345606:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/arm/OSByteOrder.h:73 long                    __darwin_ssize_t;       /* byte count or error:20: warning: identifier '__val' is reserved because it starts with '__' [-Wreserved-identifier]
1434270:sctl_register_oid_ea  113 | __NDR_convert__rly, m/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/zalloc.h:1090 ig_reply_error:1:   206 |         _Static_a_ t(__unused mig_reply_err  warning: identifier '__zalloc_percpu' is reserved because it starts with '__' [-Wreserved-identifier]
1533179: 2626 |                 FDLOG(LOG_ERR, fd_cb, "failed to get the close error: %d", error);
1537464:  720 |             (typeof(func(a))(n error: %d"*)(con, errost void *))func
1553082:      ,s_log_error:21: warning: cast from 'void (*)(vm_allocation_site_t *)' (aka 'void (*)(struct vm_allocation_site *)') to 'typeof (__zone_site_register(&site)) (*)(const void *)' (aka 'void (*)(const void *)') converts to incompatible function type [-Wcast-function-type-strict]
1591876:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
1591898:  321 |                         ipse           clog((LOG_DEBUG, "esp6_output: internal error: "
1612861:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/sysctl.hein_error:1014:
1773719:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:1220/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/netinet6/nd6.h:824 3136 |                                                     "error:58: note: expanded from macro 'nd6log'
2295968: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
2295974: 3383 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
2392880:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/mcache.h:65:25: note: expanded from macro '_CASSERT'/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/skywalk/core/skywalk_sysctl.c  602 |         int __pagein_error:
2772467:Undefined symbols for architecture arm64:
```

### around them

```
51842- 1354 |                         IOLog("Failed to open corefile of size %llu MB (returned error 0x%x)\n",
51843-      |                                                                                          ~~
51844-      |                                                                                          %x
51845- 1355 |                             (corefile_fallback_size_bytes / (1024ULL * 1024ULL)), err);
51846-      |                                                                                   ^~~
51847-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1364:76: warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
51848: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
51849-      |                                                                                   ~~     ^~~
51850-      |                                                                                   %x
51851-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1447:2: warning: 'switch' missing 'default' label [-Wswitch-default]
51852- 1447 |         switch (op) {
51853-      |         ^
51854-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1530:20: warning: missing field 'total' initializer [-Wmissing-designated-field-initializers]
51855- 1530 |         c_string = (char*)kalloc_data(string_length, (zalloc_flags_t)(Z_ZERO | Z_WAITOK | Z_NOFAIL));
51856-      |                           ^
51857-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:512:2: note: expanded from macro 'kalloc_data'
51858-  512 |         kheap_alloc(KHEAP_DATA_BUFFERS, size, flags)
--
57172- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
57173-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
57174-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
57175-  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
57176-      |                 ~~               ^~~~~~~~~~~
57177-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
57178: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
57179-      |                                                                                ~~~
57180-      |                                                                                %zu
57181- 1414 |                                             path, mc_error, fatal_failure_desc_len);
57182-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
57183-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
57184: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
57185-      |                                                                                                   ~~~
57186-      |                                                                                                   %zu
57187- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
57188-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
57189-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
57190- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
57191-      |                             ^
57192-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/vfs/vfs_cache.c:73:
57193-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/param.hs/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
57194-:c 1426 |                 zfree(ZV_NAMEI, vn_path)ount_t __attribute__((unused));
--
336642-  408 |                 uint64_t   | __pqueue_overloadable exter  113 | __NDR_convert__mig      __val64[2];
336643-      |                                 ^
336644-_rep/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/skywalk/os_packet_private.hnly_error/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/bpf.c:1180:5: : p409:4: warning: identifier '__flow_id_u' is reserved because it starts with '__' [-Wreserved-identifier]
336645-  409 |         } __flow_idwarning: q__'_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
336646-tu 1180 |                         e(__unused mig_rl        os_log(OS_LOG_DEFAULT, "%s: bpfe;
336647-      %p|           ^
336648:em_t l/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/skywalk/os_packet_private.hy_error: _d ERESTARTt416:26: warning: identifier '__q_len' is reserved because it starts with '__' [-Wreserved-identifier]
336649-  416 |         uint32_t             *x)
336650-      | ^
336651-t                    o EINTR"                    \
336652-      |       __q_len;
336653-      | ,
336654-      |                                                                                 ^
336655-                                ^
336656-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/skywalk/os_packet_private.h:419:26: warning: identifier '__q_svc_class' is reserved because it starts with '__' [-Wreserved-identifier]
336657-  419 |         uint32_t                __q_svc_class;  /* PKT_SC_* values */
336658-                                      ^
--
456541-olatile *)a)
456542-        291 |         _At      | omic ui|                             ^
456543-nt64_        ^;t
456544-       /* In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSAtomic.h:273:29: note: expanded from macro 'OSCompareAndSwapPtr'
456545-  273 |         (OSCompareAndSwb/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/libkern/coreanalytics/coreanalytics_shim.cppaytepPtr(a, b, __SAF cou :32Erpr:
456546-nt or In file included from _C/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/libkern/libkern/coreanalytics/coreanalytics_shim.h:42:
456547:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/iokit/IOKit/IOService.h:399:2_error: warning: identifier '_ClaimSystemWakeEvent_Invoke' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]AS
456548-sT_tate_last_abs_tiP/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/libkern/libkern/c++/OSMetaClass.h:1891:2: note: expanded from macro 'OSDeclareDefaultStructorsWithDispatch'
456549- *me;/
456550-      |                                 ^
456551- 
456552-      |         ^
456553-TR1891 | /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/arm/_types.h(        _:98:33: warning: identifier '__darwin_time_t' is reserved because it starts with '__' [-Wreserved-identifier]
456554-   98 | typedef long                    __darwin_time_tvOSDeclare;   DefaultStoid * volar     /* tile *,c)uctors))t(
456555-      |                                    ^
456556-className, dispatch)
456557-      |         ^
--
568999-   97 | typedef long                    __darwin_ssize_t;       /* byte cIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/radix.c:69:
569000-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/systm.h:oIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kdp/output_stages/out_zlib.c:32:
569001-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/iokit/IOKit/IOTypes.h:40:
569002-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/iokit/IOKit/system.h:41:
569003-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/mach_interface.h:32:
569004-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/clock.h:13:
569005:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/mig_errors.h:113107unt or error:
569006-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/tty.h:75:
569007- */
569008-      |                                 ^
569009-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/select.h:161:9: :1: warning: identifier '__NDR_convert__mig_reply_error_t' is reserved because it starts with '__' [-Wreserved-identifier]
569010-warning: identifier '_select' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
569011-  161 | struct  _select;
569012-      |         ^
569013-  113 | __NDR_convert__mig_reply_error_t(__unused mig_reply_error_t *x)
569014-      | ^
569015-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/libkern/crypto/corecrypto_sha1.c:1:
--
624240-e r_ed));
624241-      |           ^
624242-   97 | typedef long                    __darwin_ssize_t;       /* byte cou 270
624243-      | ^
624244-n                  \
624245-      |                                                                                 ^
624246:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/priority_queue.h:677:81: note: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.ht or error:expanded from macro '\
624247-PRIORITY_QUEUE_MAKE_BASE'
624248-  677 | __pqueue_over */
624249-      loadable extern1595|                                 ^
624250-:4:  pqelem_t           /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/arm/_types.h:98:33: warning: identifier '__darwin_time_t' is reserved because it starts with '__' [-Wreserved-identifier]
624251-In file included from   warning:    98/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_hash.cidentifier '__Request__task_register_dyld_get_process_state_t' is reserved because it starts with '__' [-Wreserved-identifier]
624252- 1595 |         } __Request:               | typedef long                    __darwin_time_t;        /* time() */
624253-      |                                 ^
624254-                \
624255-      |                                                                                 ^
624256-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/priority_queue.h:720:1: warning: identifier '_priority_queue_destroy' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
--
783475-  198 |         (&__container_of(io, struct ipc_object_waitq, iowq_ob/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c:973:3: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
783476-  973 |                 NECPLOG(LOject)->iowq_waitq)
783477-      |           ^
783478-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/cdefs.h:1089d_control_t __attribute__((unused));
783479-      |           ^
783480-G_ERR, "necp_session_get_policy policy_id/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/host_priv.h:950:4: warning: identifier '__Reply__host_get_special_port_t' is reserved because it starts with '__' [-Wreserved-identifier]
```

### the tail

```
      |                      ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_param.h:442:6: warning: identifier '__ovr' is reserved because it starts with '__' [-Wreserved-identifier]
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
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Thu Nov  5 09:47:11 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
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
patch    35 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-component-load-probes.patch
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
