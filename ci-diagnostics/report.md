# Why the build failed

run: 342, commit 1afc7e0ec95a30c6897dedcc8db412e875167192

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
27934:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdint.hc__call__ ## check, void *, mpc, int, error:14:
49714:  304 | #def(streinefil MAC_PERFORM_RSe faileLT(operd with ation, mpc)error: 0x%x\n", DTRACE err);
56714:ta_memcpy error: %d, le/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h  589 | :703:4: warning: identifier '__Request__mach_port_type_t' is reserved because it starts with '__' [-Wreserved-identifier]
56735: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
123695:ount or error:1573:2: warning: identifier '__elem' is reserved because it starts with '__' [-Wreserved-identifier]
342950:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:1956:2: error: use of undeclared identifier 'nio_u_mark'
343033::3:re us error:    79 | #duse of undeclared identifier 'nio_u_mark'
343081:error: use of undeclared identifier 'nio_u_mark'
345700:h, const voimake[7]: *** [IOService.cpo] Error 1
345709:  128 | typedef _Atomic(intptr_t)   make[6]: *** [build_all] Error 2
345725:make[5]: *** [do_all] Error 2
345737:make[4]: *** [build_all] Error 2
345764: 1158 | __packet_set_segment_count(const uin*** [build_all_recurse_into_conf] Error 2
345828: 1189 | *** [build_all_recurse_into_iokit] Error 2
516082:<scratch space>:181:11041 |             os_log_error: (necp_log_handle, "%s: %s\n", note: expanded from here
527518:OS_LOG_T/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/mpsc_queue.h:238YPE_ERRO 1033 | R,           _os  o_los_lg_fog_error:1:(necpmt,_lo ##g_h__VandA_Ale,RGS "%s: "  warning: identifier '__mpsc_queue_append_was_empty' is reserved because it starts with '__' [-Wreserved-identifier]forma__);    
607180:  158 |                 printf("buffer_stage_initialize faillicyed_search_array[i] to allocate memory. Error 0x%x\n"->result],, re policy_search_at);
634405:  102 |                 printf("progress_notify_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
656809:  143 |                 printf("%s failed to allocate memory. Error 0x%x\n", __func__, ret);
807986:d mi/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/policy_internal.h:42g_repl/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:757y_error:
809524:error: jitter %dms too big (latency %dms)",
809596:  TEM_LO215 | __zalloc__G(LOG_ERR, "|alarm_zone error: r/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h__tyeordepe_naring me
809612:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:1432:2 1463 |                     : "| error: outpunote: expanded from macro 'KALLOC_DISPATCH'
1029789: 2626 |                 FDLOG(LOG_ERR, fd_cb, "failed to get the close error: %d", error);
1084176:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
1095925:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
1176533:  275 |         SASEL_LOG("Returned with error: %d", err);
1272182:ATS_ERROR_INJECTIONS,          "_Error 1389 |             (void Injections",     "(\t%llu errors injected)\n*)os_ptr_load_and_erase/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/_types.h:(elem), __kfree_size);                \
1754583:yte count or error:82:22: note: expanded from macro 'SHARED_REGION_TRACE_INFO'
1890269: 3378In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kpc_thread.c |                             "(kcdata_mem:31cpy error: %d, length: %ld)\n",
1890290:ks_z_reaon   e_infson_alloc_buffer eo_rror: %d, kcd79 | #deft __attribute__((uine osat_ca error: %d, lnusast_to_ated));ength: %ld)\n",
2374854:chain_get_t p32(grp *XNU_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/exc_server.h:219:4error: warning: identifier '__Request__exception_raise_state_identity_t' is reserved because it starts with '__' [-Wreserved-identifier]
2433563:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
2433564:make: *** [build] Error 2
```

### around them

```
27928-  140 |                 register u  148 | #define Dintptr_t __dtraKLOG(fmt,ce_a args..1 asm("x1") = (uintptr_t) arg1;                    \
27929-      |                                    ^
27930-.) /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_necp.c:53:2: warning: identifier '__dtrace_a2' is reserved because it starts with '__' [-Wreserved-identifier]
27931-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:265:14: note: expanded from macro 'MAC_CHECK'
27932-  265 |                   { In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/libkern/scanc.c:63:
27933-IOLog("  DTRACE_MACF3(maIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/libkern/libkern.h:73:
27934:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdint.hc__call__ ## check, void *, mpc, int, error:14:
27935-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/machine/types.hD:37:
27936-,K: " fm int, MAC_ITERATE_CHECK); \
27937-      |                     ^
27938-t/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:165:2: note: expanded from macro 'DTRACE_MACF3'
27939-, ## a  165In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/arm/types.h:49:
27940-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/arm/_types.h:15:33: warning: identifier '__int8_t' is reserved because it starts with '__' [-Wreserved-identifier]
27941-rg |         DTRACE_Ps)ROBE   15 | 3(__sdt_, name, arg1, ar; }
27942-      typed|                                            ~~~     ^~~~
27943-g2, aref __signed char  /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOUserServer.cpp:3532:43: warning:    gformat specifies type 'unsigned int' but the argument has type 'mach_msg_id_t' (aka 'int') [-Wformat]
27944-      __int8_t;
--
49708-      |                                       ^
49709-format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
49710-c);
49711-      |                                 ^
49712- 1364 |                 IOLog("I/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/smr_types.h:75:42OPoll: warning: identifier '__smrq_slink_t' is reserved because it starts with '__' [-Wreserved-identifier]
49713-edF/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h   75 | typeilePodef SlleMR_POINrsSTERetup for:304:42: co note: expanded from macro 'MAC_PERFORM_RSLT'
49714:  304 | #def(streinefil MAC_PERFORM_RSe faileLT(operd with ation, mpc)error: 0x%x\n", DTRACE err);
49715-_MACF2(      |                                                                                   ~~     ^~~
49716-      |                                                                                   %xmac__rs
49717-lt__ #ruc# ot smrqper_slatiinkon, *) vo __smrid q_s*, link_tmpc;
49718-      , i|                                          ^
49719-nt, 0)
49720-      |                                          ^/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/smr_types.h:76:9: warning: 
49721-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.hidentifier '__smr_ptr' is reserved because it starts with '__' [-Wreserved-identifier]
49722-:162:   76 | 2: typnote: expanded from macro 'DTRACE_MACF2'
49723-edef SMR_POIN  162 | TER        DT(stRACrucE_Pt sROBmrqE2(_li__snk dt_*) , n __amesmrq_link, a_t;rg1
49724-      | , a        ^
--
56708-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:691:4;  : warning:    identifier '__Request__mach_port_names_t' is reserved because it starts with '__' [-Wreserved-identifier]
56709-      691 |            } __Requ   est__mach_port_names_             t __attribute__((unused) |  \
56710-      |                                  ^~~~~~~~                        
56711-);
56712-      | /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h                 :589:   "(k27: cdanote: expanded from macro 'panic'
56713-          ^
56714:ta_memcpy error: %d, le/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h  589 | :703:4: warning: identifier '__Request__mach_port_type_t' is reserved because it starts with '__' [-Wreserved-identifier]
56715-  703 |         } __        (pReqanic)(ex " @%s:ues%d"t__, #mac# _h_p_VA_ARortGS__, _ty__Fpe_ILEt __NA_atME_tri_, __LbutINEe____)((u; \nn
56716-ug      st| ed));
56717-      |           ^
56718-h:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:716:4: warning: identifier '__Request__mach_port_rename_t' is reserved because it starts with '__' [-Wreserved-identifier]
56719-  716 |         } __Request__mach_port_rename_t __attribute__((unused));
56720-      |           ^
56721-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:729:4: warning: identifier '__Request__mach_port_allocate_name_t' is reserved because it starts with '__' [-Wreserved-identifier]                ~~               ^~~~~~~~~~~
56722-<scratch space>:173:1: note: expanded from here
56723-  173 | 4547
56724-      | ^~~~
--
56729-  741 |         } __Request__mach_port_allocate_t %ld)\n",
56730-      |                                                                                ~~~
56731-      |                                                                                %zu
56732- 1414 |                                             path, mc_error, fatal_failure_desc_len);
56733-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
56734-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
56735: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
56736-      |                                                                                                   ~~~
56737-      |                                                                                                   %zu
56738- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
56739-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
56740-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
56741- 1381 |                 os_reason_t reas __attribute__((unused));
56742-      |           ^
56743-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:753:4: warning: identifier '__Request__mach_port_destroy_t' is reserved because it starts with '__' [-Wreserved-identifier]
56744-  753 |         } __Request__mach_port_destroy_t __attribute__((unused));
56745-      |           ^
--
123689-   97 | typedef long    In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/vfs/vfs_subr.c:81 /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:2297:13:               _ warning: identifier '__zone_site_register' is reserved because it starts with '__' [-Wreserved-identifier]
123690-:
123691-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/systm.h 2297 | exter:105:
123692-_darwin_ssize_t;       /* byIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/malloc.h:80:
123693-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.hn voite cd __zone_site_register(
123694-      |             ^
123695:ount or error:1573:2: warning: identifier '__elem' is reserved because it starts with '__' [-Wreserved-identifier]
123696-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:2311:1: warning: identifier '__zone_flags_mix_tag' is reserved because it starts with '__' [-Wreserved-identifier]
123697-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:874:32: note: expanded from macro 'zfree'
123698- */
123699-      |                                 ^
123700- 2311 | __zone  874 |         (zfree/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/arm/_types.h:98_)(_:33: warning: identifier '__darwin_time_t' is reserved because it starts with '__' [-Wreserved-identifier]
123701-   98_zf | typedef flags_mixree_zone, (void *)o_tag(zalloc_flagslong               _t flas_ptr_loags, vm_tag_t tag)
123702-      | ^
123703-     __darwin_time/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:2352:20: warning: identifier '__pgz_decode' is reserved because it starts with '__' [-Wreserved-identifier]
123704- 2352 | d_extern vand_er_tm_offseta;        /* time() */
123705-      |                                 ^
--
342944-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/zalloc.h:930:26: note: expanded from macro '__ZONE_DECLARE_TYPE2'
342945-  930 |         extern type_t *__single __zalloc__##var##__type_name
342946-      |                                 ^
342947-<scratch space>:36:1: note: expanded from here
342948-   36 | __zalloc__ZONE_ID_PROC_TASK__type_name
342949-      | ^
342950:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:1956:2: error: use of undeclared identifier 'nio_u_mark'
342951- 1956 |         nio_u_mark("\nnio: U1");
342952-      |         ^
342953-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/skywalk/nexus_common.h:158:1: warning: identifier '__nexus_attr_get' is reserved because it starts with '__' [-Wreserved-identifier]
342954-  158 | __nexus_attr_get(const nexus_attr_t nxa, const nexus_attr_type_t type,
342955-      | ^
342956-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm64/dbgwrap.c:29:
342957-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/cpu_data_internal.h:46:
342958-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/pmap.h:43:
342959-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/pmap/pmap.h:224:
342960-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/thread.h:122:
--
343027-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/netinet/tcp_var.h:69:
343028-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/netinet/in_pcb.h:94:
343029-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:423:50: warning: identifier '__necp_stats_reserved' is reserved because it starts with '__' [-Wreserved-identifier]
343030-p)  423 |         u_          __typeintof_64__(at  tom             ic_   loa   d(o   s_c   ast   _to         __ne_atcp_omistac_pts_oinrestererv(p)ed; // Pad the f))
343031-iel      |                                                                 ^
343032-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic.h/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cppd :79:69: note: :1958for futuexpanded from macro 'os_cast_to_atomic_pointer'
343033::3:re us error:    79 | #duse of undeclared identifier 'nio_u_mark'
343034-e 1958 |                 nio
343035-      |                                                         ^e_u_mark(
343036-fine" U2T");
343037-      |                 ^
343038- os_cast_to_atomic_pointer(p)     (__typeof__(*(p)) volatile _Atomic *)(uintptr_t)(p)
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
patch    121 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-dlil-wait-bounded.patch
patch    122 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kext-start-done.patch
patch    123 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kext-start-enter.patch
patch    124 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kext-load-enter.patch
patch    125 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-probe-candidates-count.patch
patch    126 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-cand-name.patch
patch    127 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-boottime.patch
patch    128 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-timebase.patch
patch    129 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kext-load-exit.patch
patch    130 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kext-load-executable.patch
patch    131 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kext-loaded-label.patch
patch    132 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-no-personality-for-skipped.patch
patch    133 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-candidate-done.patch
patch    134 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-bsdinit-narrates.patch
patch    135 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-manifest-properties-shim.patch
patch    136 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-probe-candidates-exit.patch
patch    137 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-startmatching-probe.patch
patch    138 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-doservicematch-probe.patch
patch    139 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-startmatching-steps.patch
patch    140 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-arbitration-recursive.patch
patch    141 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-probe-result.patch
patch    142 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-no-class-candidate.patch
patch    143 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-cpuic-matching.patch
patch    144 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-async-match-name.patch
patch    145 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-drop-reasons.patch
patch    146 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-loop-driver.patch
patch    147 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-iokit-match-return.patch
patch    148 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-stall-watchdog.patch
patch    149 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-direct-console-heartbeat.patch
patch    150 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-stall-framebuffer-message.patch
patch    151 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-arbitration-unlock-probe.patch
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
