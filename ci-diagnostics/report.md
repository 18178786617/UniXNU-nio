# Why the build failed

run: 118, commit 75ec3ce53de2c7a39026cb3cbccddd63e00ce520

## kernel-bootstrap.log

### the errors

```
53307: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
55922: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
55928: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
255824:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm64/machine_routines.c:481:38: error: member reference base type 'void' is not a structure or union
258208: __ovr = make[7]: *** [machine_routines.o] Error 1
258209:make[6]: *** [build_all] Error 2
258219:  126 |              *** [do_all] Error 2
258225:make[4]: *** [build_all] Error 2
258230:  126 |                 bool __ovr = os_add_overflow(in, (__typeof__(*omake[3]: *** [build_all_recurse_into_conf] Error 2
258237:  126 |                 bool __ovr = os_add_overflmake[2]: *** [build_all_recurse_into_osfmk] Error 2
291131:or627 |         int __pagein_error:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_statistics.h:461:t17: warning: identifier '__unused_bit_22' is reserved because it starts with '__' [-Wreserved-identifier]
688436:g_%s: " 4error:
704622:_    otrace_log_g_ha     n/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp_client.c:8249error:3:dl  warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
822042:  67error:16: warning: identifier '_lck_grp_attr_' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
852148:  112 | typedef _Atomic(int_least8_t)       atomTEM_LOG(LOG_ERR, "| error: invali] = format;     ic_d int_least8_t;
852200:rt), ntohs 1398 |                 Nts(remote_addr.sin.sin_port), ntohs(remote_addr.sin6.sin6_port), neE6cp_drop_all_order, bound_interface_inTEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
852274:  128 | t| error: jitter %dms too big (latency %dms)",
852301:y_id, socket 1420 |                     "| error: jitte/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdatomic.h:133:9: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
852327: 1438 |                     "| error: loss recovery HIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/netinet/igmp.c:90:
852387:Pv4", "DROerror: reordering %d > %d",
980143: 4398 |                                 FDLOG(LOG_DEBUG, &nil_pcb, "ctl_enqueuembuf returned an error: %d", error);
995885:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
996273:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
1000028:ernal error: "   461 |       461 |     _Static_ass
1037409:  275 |         SASEL_LOG("Returned with error: %d", err);
1061747:  696 |                                                  error:33 , "%s: SYSCTL_IN() error %d\n",:
1245132:note: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/sysctl.hrystatus_freezer_stats.mexpanded from here:fs_error:
1262030: _os_atomic_v  257 | #defin/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/lock_mtx.hae memorystatus_log_error:188:2: lue_cast(note: expanded from macro 'LCK_MTX_DECLARE_ATTR'
1337433:ein_error:  ;80:65: note: expanded from macro 'os_atomic_basetypeof'
1415009: 3378 |                             "(kcdata_memcpy error: %t/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/kpi_socket.c:1083:3: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
1415027:       /* Reser   r,oc_buffer er os_ptved for86or: r Future Us%r_load_ |         (OSCd, kcdata error: %d, length: %ldoma)pnd_eea\ras */
1891916:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
1891917:make: *** [build] Error 2
```

### around them

```
53301- 1354 |                         IOLog("Failed to open corefile of size %llu MB (returned error 0x%x)\n",
53302-      |                                                                                          ~~
53303-      |                                                                                          %x
53304- 1355 |                             (corefile_fallback_size_bytes / (1024ULL * 1024ULL)), err);
53305-      |                                                                                   ^~~
53306-  714 |         MAC_PERFORM(vnode_notify_setutimes, cred, vp, mac_vnode_label(vp), atime, mtime/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1364:76: warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
53307: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
53308-      |                                                                                   ~~     ^~~
53309-      |                                                                                   %x
53310-);
53311-      |         ^
53312-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:313:10: note: expanded from macro 'MAC_PERFORM'
53313-  313 |                 MAC_PERFORM_CALL(operation, mpc);           \
53314-      |                 ^
53315-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:303:42: note: expanded from macro 'MAC_PERFORM_CALL'
53316-  303 | #define MAC_PERFORM_CALL(operation, mpc) DTRACE_MACF3(mac__call__ ## operation, void *, mpc, int, 0, int, MAC_ITERATE_PERFORM)
53317-      |                                          ^
--
55916- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
55917-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
55918-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
55919-  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
55920-      |                 ~~               ^~~~~~~~~~~
55921-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
55922: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
55923-      |                                                                                ~~~
55924-      |                                                                                %zu
55925- 1414 |                                             path, mc_error, fatal_failure_desc_len);
55926-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
55927-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
55928: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
55929-      |                                                                                                   ~~~
55930-      |                                                                                                   %zu
55931- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
55932-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
55933-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
55934- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
55935-      |                             ^
55936-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
55937- 1426 |                 zfree(ZV_NAMEI, vn_path);
55938-      |                 ^
--
255818-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSByteOrder.h:145:1: warning: identifier '_OSWriteInt32' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]
255819-  145 | _OSWriteInt32(
255820-      | ^
255821-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSByteOrder.h:156:1: warning: identifier '_OSWriteInt64' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]
255822-  156 | _OSWriteInt64(
255823-      | ^
255824:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm64/machine_routines.c:481:38: error: member reference base type 'void' is not a structure or union
255825-  481 |                 nio_kdata_saved = PE_state.bootArgs->topOfKernelData;
255826-      |                                   ~~~~~~~~~~~~~~~~~^ ~~~~~~~~~~~~~~~
255827-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/vfs/doc_tombstone.c:34:
255828-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/vfs_context.h:7:
255829-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/thread.h:88:
255830-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_types.h:80:
255831-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/host_info.h:66:
255832-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/message.h:813:
255833-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:32:
255834-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kcdata.h:1612:11: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
--
291125-   31 |   
291126-  460 |                     __unused_bit_ :602:2             6: warning: 1 mac\
291127-      |     ^
291128-h_ms:identifier '__pagein_error' is reserved because it starts with '__' [-Wreserved-identifier]g_<scratch space>1
291129-p  :602,
291130-      |                     ^
291131:or627 |         int __pagein_error:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_statistics.h:461:t17: warning: identifier '__unused_bit_22' is reserved because it starts with '__' [-Wreserved-identifier]
291132-  461 |                   ;_descriptor:  __unus
291133- note: expanded from here
291134-ed_bit        _627 | t| _I O            ^__object__descD2ispatchQ
291135-riptor;
291136-      |                                ^
291137-2:1,
291138-      |                     ^
291139-DriverKit/IODispatchQueue.iig.cpp:32:32: warning: identifier 'port__descriptor' is reserved because it contains '__' [-Wreserved-identifier]
291140-   32 |     mach_msg_port_descriptor_t port__descriptor;
291141-      |                                ^ueue_Methods
--
688430-      |                                                                                                   ~~   ^~~~~~~~~~~~~~~~~~~~~
688431-      |                                                                                                   %u
688432- 1033 |             oames/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.c:66:63:, val, 0, 0 In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Tests/TestServices/TestIOServiceUserNotification.cpp:1:
688433-note: , input, 0, expanded from macro 'NETAGENTLOG'In file included from 0
688434-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Tests/TestServices/TestIOServiceUserNotification.h   66 |             os_log(OS)
688435-      |     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~_LOG_:_loDEFAULT, "
688436:g_%s: " 4error:
688437-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c:663:41: note: expanded from macro 'NECP_DATA_TRACE_LOG_CONDITION3'
688438-In file included from (/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOService.hf  662 | ormat    n:44:
688439-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IORegistryEntry.h:40:
688440-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSContainers.h:33:
688441-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSObject.h:176:2: warning: identifier '_Dispatch' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]ecp" NECPD
688442-\A  nTATRACELOG(LOG_ERR176 | ,",         O"DATA-TRACE <%s> __FUNC:TIO_loN__, __VA_ARG g_handlS--e, "%s: "SDecl __);  a- --reAbs   - %smat \
688443-      |                                           ~~~~~~                     ^~~~~~~~~~~
688444-foc/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.hhrmat "\n", :294:41: note: expanded from macro 'os_log'_traci
688445-  294 |  tS   _t_rucFng <%oUsNCTION__, __VA_ARt>sor_ <sGS__); \
688446-va      Wil| ltog_v            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~ue
--
704616-:77  340 alrat stringeady ac |             os_ptr_tive :must be con");
704617-      |                 ^
704618-loa /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.c:74:6: d_stant");note: expanded from macro 'NECPDATATRACELOG'note:  and
704619-_erase  expanded from macro 'NETAGENTLOG0'
704620-         (ele  \m   74 |           1049 |         os
704621- _));   os  log_error(necp_dat_la       |     ^
704622:_    otrace_log_g_ha     n/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp_client.c:8249error:3:dl  warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
704623- e, "%(OS_s: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.hL :"  OG \1043:
704624-      | f_            ^orD6:mE
704625-at "\n"FA ,/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.hU __FUNCTION_LT,:67:14: note: expanded from macro 'os_ptr_load_and_erase'
704626-_,    67 |         __ __VA_AR"%s: %s\nnote: ", _auto_Gexpanded from macro 'NECPLOG0'
704627- _type FU1043_NCTION__, ms_egS_);    l |             os_lo_); \g       em = *__eptr;                    
704628-(             ne|           ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~ \
704629-c     \      |                     ^
704630-
704631-
704632-      /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:399:76p_log_handle, "%s:: note: |             ^
--
822036-_t;      |     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
822037-s
822038- /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c_ch:662:87       |                ^
822039-annel/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/lock_group.h \
822040-      | : note: :_expanded from macro 'NECP_DATA_TRACE_LOG_CONDITION3'
822041-                                                                                ^
```

### the tail

```
 3481 |         { (sy_call_t *)(void (*)(void))map_with_linking_np, munge_wwww, _SYSCALL_RET_INT_T, AC(map_with_linking_np_args), 16}, /* 550 = map_with_linking_np */
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
