# Why the build failed

run: 325, commit 3fad21653bfcfdc9ce29c3eda57dcd1504281cdb

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

## kernel-bootstrap.log

### the errors

```
48833: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
57638: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
57644: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
68334:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/startup.h/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.hRACE_MACF3(mac__call__ ## :2163:4: warning: identifier '__Reply__task_sample_t' is reserved because it starts with '__' [-Wreserved-identifier]check, void *, mpc, int, error:720:6: note: expanded from macro '__STARTUP_FUNC_CAST'
332054:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:4015:55:  215 | _ error: member reference type 'OSPtr<const OSSymbol>' (aka 'const OSSymbol *') is a pointer; did you mean to use '->'?
332128:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:4015:56: error: no member named 'get' in 'OSSymbol'
334022:make[7]: *** [IOService.cpo] Error 1
334023:make[6]: *** [build_all] Error 2
334024:make[5]: *** [do_all] Error 2
334025:make[4]: *** [build_all] Error 2
334026:make[3]: *** [build_all_recurse_into_conf] Error 2
334040:make[2]: *** [build_all_recurse_into_iokit] Error 2
502465: error:9   :
558675: 1033 |             os_l:98: note: og_error:50: note: (necp_log_hanexpanded from macro 'static_assert'
581354:  662 |     NECPDATATRACELOG(  268 | LOG_ERR, "DATA-TRACE <%s>: ---                p--- %smatching <%s> <value (rintf("(%s) Failed to handle availability of%d / 0x%X) (%d / 0x%X)  LZ4. Error 0x%x\n", __func__, ret);
604089: memory.onsta Error 0x%x\n/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.c:74:6", re: note: expanded from macro 'NETAGENTLOG0'
828183: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
828194: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
828205: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
828216: 1413 |                     "| error: latency %d too big (> 1 sec)",
828227: 1420 |                     "| error: jitter %dms too big (latency %dms)",
828238: 1420 |                     "| error: jitter %dms too big (latency %dms)",
828249: 1438 |                     "| error: loss recovery %dms too big",
828260: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
828271: 1463 |                     "| error: output interval %dms too big",
1019800:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_port.h:305 /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/bits.h:270:to get the close error: %d", error);
1076307:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
1104501:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
1104513:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
1944051: 1430 | #defi 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
1944062:      _buffer error: %d, kcdata error: %d, length: %ld| ^)\n",
2433564:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
2433565:make: *** [build] Error 2
```

### around them

```
48827-egister uin/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_param.h:126tptr_t __dtrace_a1 asm(" 1355 |                          :15: note: expanded from macro 'round_page_overflow'x1") =    (uintptr_t) arg1;    
48828-  126 |                            \
48829-      |                                    ^
48830-(corefile_fallback_size_bytes / (1024ULL * 1024ULL)), err);
48831-      |                                                                                   ^~~
48832-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1364:76: warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
48833: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
48834-      |                                                                                   ~~     ^~~
48835-      |                                                                                   %x
48836-     bool __ovr = os_add_overflow(in, (__typeof__(*out))PAGE_MASK, out); \
48837-      |                      ^
48838-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_param.h:424:6: warning: identifier '__ovr' is reserved because it starts with '__' [-Wreserved-identifier]
48839-  424 |         if (round_page_overflow(x, &x)) {
48840-      |             ^
48841-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_param.h:126:15: note: expanded from macro 'round_page_overflow'
48842-  126 |                 bool __ovr = os_add_overflow(in, (__typeof__(*out))PAGE_MASK, out); \
48843-      |                      ^
--
57632- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
57633-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
57634-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
57635-  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
57636-      |                 ~~               ^~~~~~~~~~~
57637-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
57638: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
57639-      |                                                                                ~~~
57640-      |                                                                                %zu
57641- 1414 |                                             path, mc_error, fatal_failure_desc_len);
57642-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
57643-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
57644: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
57645-      |                                                                                                   ~~~
57646-      |                                                                                                   %zu
57647- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
57648-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
57649-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
57650- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
57651-      |                             ^
57652-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
57653- 1426 |                 zfree(ZV_NAMEI, vn_path);
57654-      |                 ^
--
68328-      |         ^
68329- /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:265:14: note: expanded from macro 'MAC_CHECK'
68330-   rank, _g_  265 | _STAR            eTUP_FUNC_CAST(func, a), b, \
68331-      t_t _        DT_attribute__((unused));
68332-      |           ^
68333-|                   ^~~~~~~~~~~~~~~~~~~~~~~~~~~~
68334:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/startup.h/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.hRACE_MACF3(mac__call__ ## :2163:4: warning: identifier '__Reply__task_sample_t' is reserved because it starts with '__' [-Wreserved-identifier]check, void *, mpc, int, error:720:6: note: expanded from macro '__STARTUP_FUNC_CAST'
68335-  720 |             (typeof(func(a))(*)(const void *))func
68336-      |             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
68337-
68338- 2163 |         } __Reply__task_sample_t __attribute__((unused));
68339-      |           ^
68340-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:2175:4: warning: identifier '__Reply__task_policy_t' is reserved because it starts with '__' [-Wreserved-identifier]
68341- 2175 |         } __Reply__task_policy_t __attribute__((unused));
68342-      |           ^
68343-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:2187:4: warning: identifier '__Reply__task_set_emulation_t' is reserved because it starts with '__' [-Wreserved-identifier]
68344- 2187 |         } __Reply__task_set_emulation_t __attribute__((unused));
--
332048-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/pmap.h:43:
332049-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/pmap/pmap.h:224:
332050-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/thread.h:117:
332051-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/sched_prim.h:85:
332052-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/waitq.h:49:
332053-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/mpsc_queue.h:215:1: warning: identifier '__mpsc_queue_append_update_tail' is reserved because it starts with '__' [-Wreserved-identifier]
332054:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:4015:55:  215 | _ error: member reference type 'OSPtr<const OSSymbol>' (aka 'const OSSymbol *') is a pointer; did you mean to use '->'?
332055-_mps 4015 |                                          c_q   match-ueu>gee_atObppejecnd_t(gupdIOMateodu_tail(leIdenmpsc_qtifierKernelKeyueue_h.get()ead_t ));
332056-      | q, mps                                                             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~^
332057-      |                                                                                          ->
332058-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.h:413:46: note: expanded from macro 'OSDynamicCast'
332059-  413 |     (c_q(type ueue_c*) OSMhain_tetaCl elm)assBase::safeMeta
332060-      | ^
332061-Cast((inst), OSTy/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/mpsc_queue.h:217:2: warning: peI'_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
332062-D(type)))
332063-      |                                              ^~~~
332064-  217 |         os_atomic_store(&elm->mpqc_next, (struct mpsc_queue_chain *__single)NULL, relaxed);
--
332122-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic.h:80:65: note: expanded from macro 'os_atomic_basetypeof'
332123-   80 | #define os_atomic_basetypeof(p)          __typeof__(atomic_load(os_cast_to_atomic_pointer(p)))
332124-      |                                                                 ^
332125-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic.h:79:69: note: expanded from macro 'os_cast_to_atomic_pointer'
332126-   79 | #define os_cast_to_atomic_pointer(p)     (__typeof__(*(p)) volatile _Atomic *)(uintptr_t)(p)
332127-      |                                                                     ^
332128:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:4015:56: error: no member named 'get' in 'OSSymbol'
332129- 4015 |                                             match->getObject(gIOModuleIdentifierKernelKey.get()));
332130-      |                                                              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ^
332131-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.h:413:46: note: expanded from macro 'OSDynamicCast'
332132-  413 |     ((type *) OSMetaClassBase::safeMetaCast((inst), OSTypeID(type)))
332133-      |                                              ^~~~
332134-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm64/copyio.c:29:
332135-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/cpu_data_internal.h:46:
332136-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/pmap.h:43:
332137-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/pmap/pmap.h:224:
332138-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/thread.h:117:
--
502459-      |     ^
502460-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if_utun.c:902:3: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
502461-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if_ipsec.c:1268:8:   902warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
502462-In file included from  |                 o 1268 |                                                         os_log_error(OS_LOG_DEFAULT, "ipsec_netif_sync_tx %s - ipsec_outpulockd/lockd_mach.cst_log_error(OS_LOG_DEFAULT, "%s: kern_nexus_attr_create failed: %d\n",
502463-      |                 ^
502464-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396:5: note: expanded from macro 'os_log_error'
502465: error:9   :
502466-396 |    %d\n", pc _Sb->ipsec_tatic_asIn file included from lockd/lockd_mach.h:7:
502467-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/ndr.h:35:
502468-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdint.h:14:
502469-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/machine/types.h:37:
502470-In file included from ser/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/arm/types.h:49t(_:
502471-ifp->i/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/arm/_types.h:15f_x:33:nam warning: identifier '__int8_t' is reserved because it starts with '__' [-Wreserved-identifier]
502472-_builtin_const   15 | anttyp_p(edeforf _mat_si), gne"fod crmahart s   tring must be conse, terroant"r);
502473-      |                                                         ^
502474-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:);      396:5: note: expanded from macro 'os_log_error'
502475-  396 |     _Static_asser      t(__builtin_constant_  p(format), "format string must b__int8_t;
--
558669-      |                                                                                                   ^~
558670-ce_index/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049_);
558671-CPU_PERFORMANCE) ==
558672-      | ^
558673-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/assert.h:176      |                 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~
558674-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1033:70: note: expanded from macro 'NECPLOG'
```

### the tail

```
      |                        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
init_sysent.c:3481:4: warning: cast from 'void (*)(void)' to 'sy_call_t *' (aka 'int (*)(struct proc *, void *, int *)') converts to incompatible function type [-Wcast-function-type-strict]
 3481 |         { (sy_call_t *)(void (*)(void))map_with_linking_np, munge_wwww, _SYSCALL_RET_INT_T, AC(map_with_linking_np_args), 16}, /* 550 = map_with_linking_np */
      |           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
init_sysent.c:3486:17: warning: cast from 'int (*)(struct proc *, struct freadlink_args *, int *)' to 'void (*)(void)' converts to incompatible function type [-Wcast-function-type-strict]
 3486 |         { (sy_call_t *)(void (*)(void))freadlink, munge_www, _SYSCALL_RET_INT_T, AC(freadlink_args), 12},     /* 551 = freadlink */
      |                        ^~~~~~~~~~~~~~~~~~~~~~~~~
init_sysent.c:3486:4: warning: cast from 'void (*)(void)' to 'sy_call_t *' (aka 'int (*)(struct proc *, void *, int *)') converts to incompatible function type [-Wcast-function-type-strict]
 3486 |         { (sy_call_t *)(void (*)(void))freadlink, munge_www, _SYSCALL_RET_INT_T, AC(freadlink_args), 12},     /* 551 = freadlink */
      |           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
init_sysent.c:3491:17: warning: cast from 'int (*)(struct proc *, struct record_system_event_args *, int *)' to 'void (*)(void)' converts to incompatible function type [-Wcast-function-type-strict]
 3491 |         { (sy_call_t *)(void (*)(void))sys_record_system_event, munge_wwww, _SYSCALL_RET_INT_T, AC(record_system_event_args), 16}, /* 552 = sys_record_system_event */
      |                        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
init_sysent.c:3491:4: warning: cast from 'void (*)(void)' to 'sy_call_t *' (aka 'int (*)(struct proc *, void *, int *)') converts to incompatible function type [-Wcast-function-type-strict]
 3491 |         { (sy_call_t *)(void (*)(void))sys_record_system_event, munge_wwww, _SYSCALL_RET_INT_T, AC(record_system_event_args), 16}, /* 552 = sys_record_system_event */
      |           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
init_sysent.c:3496:17: warning: cast from 'int (*)(struct proc *, struct mkfifoat_args *, int *)' to 'void (*)(void)' converts to incompatible function type [-Wcast-function-type-strict]
 3496 |         { (sy_call_t *)(void (*)(void))mkfifoat, munge_www, _SYSCALL_RET_INT_T, AC(mkfifoat_args), 12},       /* 553 = mkfifoat */
      |                        ^~~~~~~~~~~~~~~~~~~~~~~~
init_sysent.c:3496:4: warning: cast from 'void (*)(void)' to 'sy_call_t *' (aka 'int (*)(struct proc *, void *, int *)') converts to incompatible function type [-Wcast-function-type-strict]
 3496 |         { (sy_call_t *)(void (*)(void))mkfifoat, munge_www, _SYSCALL_RET_INT_T, AC(mkfifoat_args), 12},       /* 553 = mkfifoat */
      |           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
init_sysent.c:3501:17: warning: cast from 'int (*)(struct proc *, struct mknodat_args *, int *)' to 'void (*)(void)' converts to incompatible function type [-Wcast-function-type-strict]
 3501 |         { (sy_call_t *)(void (*)(void))mknodat, munge_wwww, _SYSCALL_RET_INT_T, AC(mknodat_args), 16},        /* 554 = mknodat */
      |                        ^~~~~~~~~~~~~~~~~~~~~~~
init_sysent.c:3501:4: warning: cast from 'void (*)(void)' to 'sy_call_t *' (aka 'int (*)(struct proc *, void *, int *)') converts to incompatible function type [-Wcast-function-type-strict]
 3501 |         { (sy_call_t *)(void (*)(void))mknodat, munge_wwww, _SYSCALL_RET_INT_T, AC(mknodat_args), 16},        /* 554 = mknodat */
      |           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
init_sysent.c:3506:17: warning: cast from 'int (*)(struct proc *, struct ungraftdmg_args *, int *)' to 'void (*)(void)' converts to incompatible function type [-Wcast-function-type-strict]
 3506 |         { (sy_call_t *)(void (*)(void))ungraftdmg, munge_wl, _SYSCALL_RET_INT_T, AC(ungraftdmg_args), 12},    /* 555 = ungraftdmg */
      |                        ^~~~~~~~~~~~~~~~~~~~~~~~~~
init_sysent.c:3506:4: warning: cast from 'void (*)(void)' to 'sy_call_t *' (aka 'int (*)(struct proc *, void *, int *)') converts to incompatible function type [-Wcast-function-type-strict]
 3506 |         { (sy_call_t *)(void (*)(void))ungraftdmg, munge_wl, _SYSCALL_RET_INT_T, AC(ungraftdmg_args), 12},    /* 555 = ungraftdmg */
      |           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1540 warnings generated.
423 warnings generated.
     LDFILELIST bsd
make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
make: *** [build] Error 2
build-xnu-4k-baseline.sh: line 829: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

## status.txt

```
patch    110 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-counter-storage-in-data.patch
patch    111 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-phase-done-trace.patch
patch    112 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-counter-count-trace.patch
patch    113 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-fleh-early-fault.patch
patch    114 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-nested-abort-report.patch
patch    115 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-step-marks.patch
patch    116 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-post-earlyboot-marks.patch
patch    117 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-screen-init-null.patch
patch    118 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-dlil-wait-bounded.patch
patch    119 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kext-start-done.patch
patch    120 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kext-start-enter.patch
patch    121 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kext-load-enter.patch
patch    122 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-probe-candidates-count.patch
patch    123 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kext-load-exit.patch
patch    124 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kext-load-executable.patch
patch    125 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kext-loaded-label.patch
patch    126 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-no-personality-for-skipped.patch
patch    127 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-candidate-done.patch
patch    128 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-bsdinit-narrates.patch
patch    129 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-manifest-properties-shim.patch
patch    130 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-probe-candidates-exit.patch
patch    131 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-startmatching-probe.patch
patch    132 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-doservicematch-probe.patch
patch    133 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-startmatching-steps.patch
patch    134 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-arbitration-recursive.patch
patch    135 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-probe-result.patch
patch    136 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-no-class-candidate.patch
patch    137 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-cpuic-matching.patch
patch    138 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-async-match-name.patch
patch    139 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-drop-reasons.patch
patch    140 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-loop-driver.patch
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
