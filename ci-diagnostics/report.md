# Why the build failed

run: 117, commit 40478c89fd687fdf0d9e8401530eb2051b726dc7

## kernel-bootstrap.log

### the errors

```
53315: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
56415: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
56421: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
250831:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm64/machine_routines.c:483:38: error: member reference base type 'void' is not a structure or union
252767:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/machine/_types.hmake[7]: *** [machine_routines.o] Error 1
252778:make[6]: *** [build_all] Error 2
252789:make[5]: *** [do_all] Error 2
252794:      |                                 ^make[4]: *** [build_all] Error 2
252800:   28 | typedef unsigned int           make[3]: *** [build_all_recurse_into_conf] Error 2
252804:   48 | typedef int                     __darwin_ct_rune_t;     /* ct_rune_tmake[2]: *** [build_all_recurse_into_osfmk] Error 2
571499:   74 |             os_l/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp_client.c:664:8/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:og_error: warning: identifier '__startup_lck_attr_spec_necp_fd_mtx_attr' is reserved because it starts with '__' [-Wreserved-identifier]
582752: 2782 |                         NECPLOG(LOG_ERR, "Invalid TLV length (%u)",  863 |         } __Request__mach_port_request_notification_t /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.cos_log_error:1679:22: warning: identifier '__startup_ZALLOC_entry___zone_site_register_1679' is reserved because it starts with '__' [-Wreserved-identifier]
677044:4g_error: warning: <scratch space>:113(format specifies type 'unsigned int' but the argument has type 'int' [-Wformat]
695991:host_page_size_t __attribut/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/thread_act.h        e__((os_log_error:1005:4: warning: identifier '__Reply__thread_suspend_t' is reserved because it starts with '__' [-Wreserved-identifier]
853218: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
853229: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
853240: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
853251: 1413 |                     "| error: latency %d too big (> 1 sec)",
853262: 1420 |                     "| error: jitter %dms too big (latency %dms)",
853273: 1420 |                     "| error: jitter %dms too big (latency %dms)",
853284: 1438 |                     "| error: loss recovery %dms too big",
853295: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
853306: 1463 |                     "| error: output interval %dms too big",
882539:  532 |                                 os_log_error: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
971155:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/smr_types.h:71:2: note: expanded from macro 'SMR_POINTER'G(LOG_ERR, fd_cb, "failed to get the close error: %d", error);
977885: 4398 |                                 FDLOG(LOG_DEBUG, &nil_pcb, "ctl_enqueuembuf returned an error: %d", error);
996257:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
996680:  169 | typedef struct atomic  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
1000440:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
1001113:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
1037850:  275 |         SASEL_LOG("Returned with error: %d", err);
1415513: 3383 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
1891916:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
1891917:make: *** [build] Error 2
```

### around them

```
53309- 1354 |                         IOLog("Failed to open corefile of size %llu MB (returned error 0x%x)\n",
53310-      |                                                                                          ~~
53311-      |                                                                                          %x
53312- 1355 |                             (corefile_fallback_size_bytes / (1024ULL * 1024ULL)), err);
53313-      |                                                                                   ^~~
53314-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1364:76: warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
53315: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
53316-      |                                                                                   ~~     ^~~
53317-      |                                                                                   %x
53318-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1447:2: warning: 'switch' missing 'default' label [-Wswitch-default]
53319- 1447 |         switch (op) {
53320-      |         ^
53321-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1530:20: warning: missing field 'total' initializer [-Wmissing-designated-field-initializers]
53322- 1530 |         c_string = (char*)kalloc_data(string_length, (zalloc_flags_t)(Z_ZERO | Z_WAITOK | Z_NOFAIL));
53323-      |                           ^
53324-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:512:2: note: expanded from macro 'kalloc_data'
53325-  512 |         kheap_alloc(KHEAP_DATA_BUFFERS, size, flags)
--
56409- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
56410-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
56411-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
56412-  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
56413-      |                 ~~               ^~~~~~~~~~~
56414-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
56415: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
56416-      |                                                                                ~~~
56417-      |                                                                                %zu
56418- 1414 |                                             path, mc_error, fatal_failure_desc_len);
56419-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
56420-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
56421: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
56422-      |                                                                                                   ~~~
56423-      |                                                                                                   %zu
56424- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
56425-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
56426-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
56427- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
56428-      |                             ^
56429-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
56430- 1426 |                 zfree(ZV_NAMEI, vn_path);
56431-      |                 ^
--
250825-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/refcnt_internal.h:22:2: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
250826-   22 |         _Atomic uint64_t grp_retain_total;
250827-      |         ^
250828-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/refcnt_internal.h:23:2: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
250829-   23 |         _Atomic uint64_t grp_release_total;
250830-      |         ^
250831:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm64/machine_routines.c:483:38: error: member reference base type 'void' is not a structure or union
250832-  483 |                 nio_kdata_saved = PE_state.bootArgs->topOfKernelData;
250833-      |                                   ~~~~~~~~~~~~~~~~~^ ~~~~~~~~~~~~~~~
250834-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm64/machine_routines.c:603:3: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
250835-  603 |                 os_atomic_store(&LockTimeOut, lto_abstime, relaxed);
250836-      |                 ^
250837-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic_private.h:342:2: note: expanded from macro 'os_atomic_store'
250838-  342 |         _Static_assert(os_atomic_store_is_plain(p), "Store is wide"); \
250839-      |         ^
250840-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm64/machine_routines.c:603:3: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
250841-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic_private.h:345:39: note: expanded from macro 'os_atomic_store'
--
571493-      |         ^
571494-to srena_end reinfo_zone__type_name
571495-      | ^
571496-sponse");
571497-      |                 ^
571498-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.c:74:6: note: expanded from macro 'NETAGENTLOG0'
571499:   74 |             os_l/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp_client.c:664:8/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:og_error: warning: identifier '__startup_lck_attr_spec_necp_fd_mtx_attr' is reserved because it starts with '__' [-Wreserved-identifier]
571500-  664 | static LCK_ATTR_DECLARE(necp_f 1255 |         } __Reply_(1033:6: note: expanded from macro 'NECPLOG'
571501- 1033 |             os_log_error(necp_log_OS_LOGhandle, "%s:d_mtx_attr, 0, 0);
571502-      |        ^
571503-_DE " format "\n", __FUNCTION__, __VA_ARGSFAULT, "%s: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/locks.h__); \
571504-      |             ^
571505-%s\n"/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396:5: note: expanded from macro 'os_log_error'
571506-  396 |     _Static_ass:, __FUNCTION__, msg);            1251:2: note: expanded from macro 'LCK_ATTR_DECLARE'
571507-ert(__builtin_constan 1251 |         __stt_p(format)artup_lck, "format string must be constant");             \
571508-      |     ^
571509-_attr_spec_ ## var = { &var, set_flags, clear_fla/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c:6694:2: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
--
582746-      |     ^   845 |         } __Request_1049 | 
582747-_mach_port_move_member_t __attribute__((unused));
582748-        
582749-      |           ^
582750-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp_client.c:2782:4: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
582751-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:863:4: warning: identifier '__Request__mach_port_request_notification_t' is reserved because it starts with '__' [-Wreserved-identifier]
582752: 2782 |                         NECPLOG(LOG_ERR, "Invalid TLV length (%u)",  863 |         } __Request__mach_port_request_notification_t /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.cos_log_error:1679:22: warning: identifier '__startup_ZALLOC_entry___zone_site_register_1679' is reserved because it starts with '__' [-Wreserved-identifier]
582753-(necp_data_trace_l__ ogattribute__((unused));
582754-      |           ^
582755-_handle, "%s: " format "\n", __F/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:879:4: warning: identifier '__Request__mach_port_insert_right_t' is reserved because it starts with '__' [-Wreserved-identifier]
582756-UNCTION__, __VA_ARGS__)  879 | ; \ 1679 |                 a        
582757-ssign      | } __Request__                                                        ^~~~~~
582758-len/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:397:83: note: expanded from macro 'os_log_error'
582759-  397 |     __attmach_port_insert_rigried_results =bute__((section("__TEXT,__os_log"))) static const char _os_log_gth);
582760-      | ht_t __attribute__((unused));
582761-      |           ^
582762- kalloc_data( assigned_results_length, Z_WAITOK);
--
677038-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:1430:40: note: expanded from macro 'KALLOC_DISPATCH1'
677039- 1430 | #questUniondefine KALLOC_DISPATCH1(base, N, ...) __CONCAT _(1049_ba | host_ss        ecurity_sube,os_lo N)(__VA/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pf_norm.c:sys_ARGS__)
677040-tem       |                                        ^
677041-1013:note: (skipping 1 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)
677042-{
677043-      |       ^
677044:4g_error: warning: <scratch space>:113(format specifies type 'unsigned int' but the argument has type 'int' [-Wformat]
677045-necp_data_tra/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/host_security.h:187:4 :1: c:e_log_handle, "%s: " format "\n", __FUN warning: identifier '__Reply__host_security_create_task_token_t' is reserved because it starts with '__' [-Wreserved-identifier]C1013 | 
677046-note:         Texpanded from here
677047-    ION__, __VA_                LIS187113T |  | _        } _kfree_INSA_ERtRGS__); \
677048-      |         ^
677049-ype_2
677050-R/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396:5:       T_Benote: expanded from macro 'os_log_error'
677051-ply__host_seEFORE(fr  396 |     _| ^
677052-a, ccStauuri/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.htic_assertty_create_task_token_t __a:1284ttribute__((unused));
677053-      |           ^
677054-(__builtin_constant_p(format), "format string must be cons/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/host_security.h:199:4: warning: identifier '__Reply__host_security_set_task_token_t' is reserved because it starts with '__' [-Wreserved-identifier]
--
695985-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/thread_act.h:993:4: warning: identifier '__Reply__thread_set_state_t' is reserved because it starts with '__' [-Wreserved-identifier]
695986-1: warning: identifier '__nexus_config_req_prepare' is reserved because it starts with '__' [-Wreserved-identifier]
695987-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_host.h::1049:77: note:   499:4: 993expanded from macro 'NECPDATATRACELOG'
695988- |         } __Repl  448 | y__thread_warning: identifier '__Request__host_page_size_t' is reserved because it starts with '__' [-Wreserved-identifier]
695989-__nexus_cset_state_t __attribute__((unu  499 |         } __Request__ 1049 | sed));
695990-      |           ^
```

### the tail

```
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
811 warnings generated.
     LDFILELIST bsd
make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
make: *** [build] Error 2
build-xnu-4k-baseline.sh: line 829: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

## status.txt

```
patch    59 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/native-smp-type-clusters.patch
patch    60 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/sheng-platform-power.patch
patch    61 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/zzz-boot-progress.patch
patch    62 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/xnu-8796.101.5-security-init.patch
patch    63 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/xnu-8796.101.5-sparse-index.patch
patch    64 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/linux-clang-auto-var-init.patch
patch    65 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/linux-clang-uio-stackbuf-align.patch
patch    66 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/linux-clang-kalloc-pointee-type.patch
patch    67 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/linux-clang-iorpc-kernel-content.patch
patch    68 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/xnu-8796-arm64-kpc-backend.patch
patch    69 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-security-extensions.patch
patch    70 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-trust-cache-without-security-extensions.patch
patch    71 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-amfi-less-blob-acceleration.patch
patch    72 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-amfi-less-entitlement-queries.patch
patch    73 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kext-data-const-stays-writable.patch
patch    74 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kernel-data-const-stays-writable.patch
patch    75 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-image4-kext.patch
patch    76 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-port-command-line.patch
patch    77 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-boot-args-fallback.patch
patch    78 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kmem-range-landmarks.patch
patch    79 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kmem-scramble-landmarks.patch
patch    80 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kalloc-init-landmarks.patch
patch    81 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-sysctl-walk-guard.patch
patch    82 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-compressor-landmarks.patch
patch    83 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-heartbeat.patch
patch    84 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-zone-ro-gate.patch
patch    85 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-stack-rw.patch
patch    86 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-badstack-print.patch
patch    87 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kernel-window-rw.patch
patch    88 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-register-boot-stack.patch
patch    89 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-boot-args-print.patch
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
