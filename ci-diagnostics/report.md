# Why the build failed

run: 116, commit d08518a136d002399e7a6fcb30f53945b967b019

## kernel-bootstrap.log

### the errors

```
55847: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
55853: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
220383:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm64/sleh.c:2097:59: error: member reference base type 'void' is not a structure or union
220389:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm64/sleh.c:2098:59: error: member reference base type 'void' is not a structure or union
220400: 1527 |         } __Reply__mach_port_set_seqno_t __attribute__((unusedmake[7]: *** [sleh.o] Error 1
220401:make[6]: *** [build_all] Error 2
220402:make[5]: *** [do_all] Error 2
220403:make[4]: *** [build_all] Error 2
220404:make[3]: *** [build_all_recurse_into_conf] Error 2
220405:make[2]: *** [build_all_recurse_into_osfmk] Error 2
577521: 2916 |                 os_log_error:4: warning: identifier '__Reply__host_get_io_main_t' is reserved because it starts with '__' [-Wreserved-identifier]
597629:./DriverKit/IOService.h | guint32_t _error:66        _:L(O_vm_flaS_LOGC2_DEFAULT, "%s: kern_nexus_attr_crea: warning: te faiK_GRP_DECLARE_ATTRidentifier '_kIOPMWakeEventSource' is reserved because it starts with '_' at global scope [-Wreserved-identifier]l
597755:i/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/lock_rw.h:led, error:  190%d\n",
640339: 1049 |         os_log_error: warning: identifier '__nosan_strlcat' is reserved because it starts with '__' [-Wreserved-identifier]
669434:y__mach_port_get_context_tt 1049 | (ch        os_log_error:1: warning: a(identifier '__kheap_realloc' is reserved because it starts with '__' [-Wreserved-identifier]r 
854723: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
854734: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
854751: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
854762: 1413 |                     "| error: latency %d too big (> 1 sec)",
854774: 1420 |                     "| error: jitter %dms too big (latency %dms)",
854801: 1420 |                     "| error: jitter %dms too big (latency %dms)",
854812: 1438 |                     "| error: loss recovery %dms too big",
854823: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
854834: 1463 |                     "| error: output interval %dms too big",
908021:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/classq/classq.h/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/netinet/tcp_input.c 1303 |                 os_log_error:231:13: warning: identifier '_getq_tail' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
963555:  677 | __pqueue_overloadable eIn file included from to get the close error: %d", error);
969547: 4398 |                                 FDLOG(LOG_DEBUG, &nil_pcb, "ctl_enqueuembuf returned an error: %d", error);
984755:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
984967:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
991912:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
1028079:  275 |         SASEL_LOG("Returned with error:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/skywalk/nexus_common.h:436:1: warning: identifier '__nexus_unbind_req_prepare' is reserved because it starts with '__' [-Wreserved-identifier]
1405360: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
1405366: 3383 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
1882342:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
1882343:make: *** [build] Error 2
```

### around them

```
55841-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kern_types.h:251:8: warning: identifier '_wait_queue_link' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
55842-  251 | struct _wait_queue_link;
55843-      |        ^
55844-__FILE_NAME__, __LINE__); \
55845-      |                 ~~               ^~~~~~~~~~~
55846-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
55847: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
55848-      |                                                                                ~~~
55849-      |                                                                                %zu
55850- 1414 |                                             path, mc_error, fatal_failure_desc_len);
55851-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
55852-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
55853: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
55854-      |                                                                                                   ~~~
55855-      |                                                                                                   %zu
55856- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
55857-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
55858-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
55859- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
55860-      |                             ^
55861-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
55862- 1426 |                 zfree(ZV_NAMEI, vn_path);
55863-      |                 ^
--
220377-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm64/sleh.c:2033:2: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
220378- 2033 |         prior __assert_only = thread_get_kernel_state(thread)->allocation_name;
220379-      |         ^
220380-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm64/sleh.c:2059:11: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
220381- 2059 |         uint64_t pc = is_user ? get_saved_state_pc(state) :
220382-      |                  ^
220383:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm64/sleh.c:2097:59: error: member reference base type 'void' is not a structure or union
220384- 2097 |             (unsigned long)(PE_state.bootArgs ? PE_state.bootArgs->topOfKernelData : 0),
220385-      |                                                 ~~~~~~~~~~~~~~~~~^ ~~~~~~~~~~~~~~~
220386-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
220387-  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
220388-      |                                  ^~~~~~~~~~~
220389:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm64/sleh.c:2098:59: error: member reference base type 'void' is not a structure or union
220390- 2098 |             (unsigned long)(PE_state.bootArgs ? PE_state.bootArgs->virtBase : 0));
220391-      |                                                 ~~~~~~~~~~~~~~~~~^ ~~~~~~~~
220392-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
220393-  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
220394-      |                                  ^~~~~~~~~~~
220395-585 warnings and 2 errors generated.
220396-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:1515:4: warning: identifier '__Reply__mach_port_extract_right_t' is reserved because it starts with '__' [-Wreserved-identifier]
220397- 1515 |         } __Reply__mach_port_extract_right_t __attribute__((unused));
220398-      |           ^
220399-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:1527:4: warning: identifier '__Reply__mach_port_set_seqno_t' is reserved because it starts with '__' [-Wreserved-identifier]
--
577515-      |                     ^
577516-  919 |         } __Reply__host_processor_info_t __attribute__((unused));
577517-      |           ^
577518-(__builtin_constant_p(format), "format string must be constant");             \
577519-      |     ^
577520-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_host.h:933/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if_utun.c:2917:7: warning: format specifies type 'int' but the argument has type 'protocol_family_t' (aka 'unsigned int') [-Wformat]
577521: 2916 |                 os_log_error:4: warning: identifier '__Reply__host_get_io_main_t' is reserved because it starts with '__' [-Wreserved-identifier]
577522-  933 |         } __Repl(OS_LOG_DEFAULT, "utun_attacy__hosth_inet - ifnet_attach_protocol %d failed: %d\n",
577523-      |                                                                                        ~~
577524-      |                                                                                        %u
577525- 2917 |                     protocol, result);
577526-      |                     ^~~~~~~~
577527-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:398:41: note: expanded from macro 'os_log_error'
577528-  398 |     _os_log_verify_format_str(format, ##__VA_ARGS__);In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOPlatformExpert.cpp:29:
577529-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOCPU.h:43:
577530-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOService.h:56:
577531-./DriverKit/IOService.h:                                           \
--
597623-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_statistics.h:516:11: warning: identifier '__vm_flags' is reserved because it starts with '__' [-Wreserved-identifier]
597624-  In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/lock_group.h:204:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if_ipsec.c5162: note: expanded from macro 'LCK_GRP_DECLARE'
597625-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IONVRAM.cpp:34:
597626-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IONVRAM.h::  36:
597627-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOService.h | 1919:3: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
597628- 1919 |                 os_l        :204o56:
597629:./DriverKit/IOService.h | guint32_t _error:66        _:L(O_vm_flaS_LOGC2_DEFAULT, "%s: kern_nexus_attr_crea: warning: te faiK_GRP_DECLARE_ATTRidentifier '_kIOPMWakeEventSource' is reserved because it starts with '_' at global scope [-Wreserved-identifier]l
597630-(var, name, LCK_GRP   g_66 |         _kIOPMWakesATTR_NONE);
597631-Ee      |         ^
597632- : 24;
597633-      |                  ^/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/lock_group.hd
597634-: %d\n",vent:
597635-      |                 ^
597636-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_statistics.h:545Sourc:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.he = 0x00200:39660:2: note: expanded from macro 'LCK_GRP_DECLARE_ATTR'
597637-:5: note: expanded from macro 'os_log_error'
597638-  396 |     _Stat0: warning: identifier '__vmnekf_unused' is reserved because it starts with '__' [-Wreserved-identifier]
597639-i  c_assert(__000buil  200t |         STARTUP5451,_ | 
--
597749-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IONVRAM.cpp:34:
597750-o/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdatomic.h:102:9: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
597751-  In file included from 195 |         LCK_RW_DECLARE_g  102 | typedeA_TTR(var, grp, LCfe _Atomic(unsigned short/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IONVRAM.hK_ATTR_r:36:
597752-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOService.h:399:2: warning: )N    identifier '_ClaimSystemWakeEvent' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]r
597753-o/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.hUr(OS_LOG_DEFAULT, "%s register  :Lprovi1891adL:)
597754-e2rt       | omif        ^ca
597755:i/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/lock_rw.h:led, error:  190%d\n",
597756-note: :2expanded from macro 'OSDeclareDefaultStructorsWithDispatch'      |                 ^
597757-:
597758- 1891 |         _OSDeclareDefau _ushort;/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.hnote: l
597759-      expanded from macro 'LCK_RW_DECLARE_ATTR'tStructor|         ^:396
597760-
597761-  190 |         __starts(cup_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdatomic.h::l103:9:as 5:warning: sNa lm'_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]ck
597762-e, disnote: _expanded from macro 'os_log_error'rw  
597763-p_a  spec_ ## var = { &var, grp, attr }; \
597764-      |         ^
597765-<scratch space>:60:1t396103ch) | : note: expanded from here
--
640333-t sz)
640334-      | ^
640335-   35 | template <class _T> struct remove_pointer   /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:77: note: log_     handle, "%s: " format "\n", __FUNCTION__, __VA_ARGS__); \
640336-      |             ^
640337-expanded from macro 'NECPDATATRACELOG'
640338-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/san/san/memintrinsics.h:78:1 /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396:5: note: expanded from macro 'os_log_error'
640339: 1049 |         os_log_error: warning: identifier '__nosan_strlcat' is reserved because it starts with '__' [-Wreserved-identifier]
640340-  396 |     _Static   78 | __nosan_st_a(necp_data_trace_log_hrlcat(chassert(__builtin_constant_p(format), "format string must be constant");             \
640341-      |     ^
640342-andle, "%s: " format "\nr ", __FUNCTIO   *__sizedN__, __VA_ARGS__); \
640343-      |                                                         ~~~~~~                     ^~~~~~~~~~~
640344-_by(sz)dst, const char *__null_terminated src, size/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:398:41: note: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp_client.c:9103:82: warning: format specifies type 'int' but the argument has type 'u_int32_t' (aka 'unsigned int') [-Wformat]
640345-expanded from macro 'os_log_error'
640346-_t sz)
640347-      | ^
640348-  398 |     _os_log_verify_format_str(format, ##__VA_ARGS__);                  /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/san/san/memintrinsics.h:83:1: warning: identifier '__nosan_strnlen' is reserved because it starts with '__' [-Wreserved-identifier]
640349-                 83 | __  n9103 osan_strnlen(const char *__null_terminated src, size_t sz)
--
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
