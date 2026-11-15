# Why the build failed

run: 350, commit 05f76948f35a81df82461088be8843fc115e08fd

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
66505:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/malloc.h int, :80/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1076:4error: warning: identifier '__Request__task_set_special_port_t' is reserved because it starts with '__' [-Wreserved-identifier]
117892:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOMemoryDescriptor.h:284:2 error: warning: identifier '_CopyState_Invoke' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]
345529::1956:2: error: use of undeclared identifier 'nio_u_mark'
345607:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:1958:3: error: use of undeclared identifier 'nio_u_mark'
345664:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:1960:3: error: use of undeclared identifier 'nio_u_mark'
349023:  150 | _Statiad_prioric_assert(LCK_RW_EXPECTED_MAX_NUMBER <= 127, "LCK_RW_EXPECtmake[7]: *** [IOService.cpo] Error 1Ty_th
349044:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/systm.h:107*** [build_all] Error 2
349052:riority_normake[5]: *** [do_all] Error 2
349061:make[4]: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/pthread/priority_private.h:401*** [build_all] Error 2
349072:In file included from make[3]: *** [build_all_recurse_into_conf] Error 2
349077:make[2]: *** [build_all_recurse_into_iokit] Error 2
530229: allocate memory. Error 0x%x\n", ret);
547977:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/skywalk/packet_common.h:   822  116 | osKA:1_log_error: warning: identifier '__packet_set_traffic_class' is reserved because it starts with '__' [-Wreserved-identifier](necp
589401:Error 0x%x\n", ret);
839603:ERR, "| error: du/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.h:736plication_p %d > %d":2:,
839623: 1413 |                     "| error: latency %d too big (> 1 sec)",
839634: 1420 |                     "| error: jitter %dms too big (latency %dms)",
839671: 1438 |                     "| error: loss recovery %dms too big",
839709: 1463 |                     "| error: output interval %dms too big",
951212:  602 |         int __pagein_error:
1115328:  ueu675 |         staembticuf  __retstaurnrtued an error: %d"p_d, eatarro chr);ar 
1139872:%d 1(nam/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/misc_protos.h:209:1error: warning: identifier '_doprnt_log' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
1143809:In file included from ./mach/thread_act_server.h:626843 |                 os_log_error:
1177148:ernal error: "
1177382:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
1192283:_output: internal error: "
1499527:anic("%s:   113 | Inv__NaliDR_d acontomveric t__opemigrat_reionply_error: %_t(d",__u __nusfuned c__mig, o_rep);ply
1618389:ct/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/netinet/in.h:568:8ed error: warning: identifier '__msfilterreq' is reserved because it starts with '__' [-Wreserved-identifier]
1953089:ocOUNT_ARGS_buffer error: %d, kcdata error: %d, lengt(__VA_ARGS__), ##__VA_ARGS__)
2378890:typede  761 |                 nfsm_f _Atchainomic(_get_32(error:643:18:, nmr note: ineqexpanded from macro 'NFSStatAdd64'
2433563:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
2433564:make: *** [build] Error 2
```

### around them

```
66499- 1060 |         } __Request/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:2434:2: warning: identifier '__dtrace_a1' is reserved because it starts with '__' [-Wreserved-identifier]
66500-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h__t:265:ask14: _genote: expanded from macro 'MAC_CHECK'
66501-t_sp  265 | eci          al_   por   t_t    __ DTattRACribE_MuteACF__(3(m(unac_use_In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/vfs/vfs_cache.c:74:
66502-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/systm.hcall__ ## cd));heck,
66503-      |           ^
66504- void *, mpc,:105:
66505:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/malloc.h int, :80/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1076:4error: warning: identifier '__Request__task_set_special_port_t' is reserved because it starts with '__' [-Wreserved-identifier]
66506-, int, 1076 |         } __Re MAC_questITERA__tasTE_CHk_setECK);_spec \
66507-      | ial_p                    ^
66508-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:165:2: note: expanded from macro 'DTRACE_MACF3'
66509-  165 |         DTRACE_PROBE3(_:
66510-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:_sdt_65:
66511-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:, name, arg1,or72:
66512- t_t arg2,__att arg3ribut);
66513-      | e__((        ^
66514-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:140:29: note: expanded from macro 'DTRACE_PROBE3'/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kern_types.hu:36:
66515-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_types.hnused));
--
117886-      | ^
117887-./DriverKit/IOMemoryDescriptor.h:294:29: note: expanded from macro 'IOMemoryDescriptor_Methods'
117888-_   294 |     typedef k## cern_return_t (*_CopyState_Handler)(OSMetaClassBase * target, heIOMemoryDeckscriptor__CopyS, tate_Args);\
117889-      |                             ^
117890-void *, mpc, int,In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/skywalk/IOSkywalkSupport.cpp:32:
117891-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOBufferMemoryDescriptor.h:32:
117892:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOMemoryDescriptor.h:284:2 error: warning: identifier '_CopyState_Invoke' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]
117893-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.h:1891:, int, 2: note: expanded from macro 'OSDeclareDefaultStructorsWithDispatch'
117894- 1891 |         _OSMAC_ITERADeclareDefaultSTEtructors(className, dispatch)
117895-      |         ^
117896-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.h:1881:_C2: note: expanded from macro '_OSDeclareDefaultStructors'
117897- 1881 |         OSDeclareHECK)CommonStructors(className, dispatch);              \
117898-      ; \
117899-      |                     ^
117900-|         ^
117901-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:165/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.h:1856:5: note: :2: expanded from macro 'OSDeclareCommonStructors'
117902- 1856note: expanded from macro 'DTRACE_MACF3' |     _OS_ADD_METHODS(className, dispatch)
--
345523-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/san/san/memintrinsics.h:83:1: warning: identifier '__nosan_strnlen' is reserved because it starts with '__' [-Wreserved-identifier]
345524-   83 | __nosan_strnlen(const char *__null_terminated src, size_t sz)
345525-      | ^
345526-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/san/san/memintrinsics.h:88:1: warning: identifier '__nosan_strlen' is reserved because it starts with '__' [-Wreserved-identifier]
345527-   88 | __nosan_strlen(const char *__null_terminated src)
345528-      | ^
345529::1956:2: error: use of undeclared identifier 'nio_u_mark'
345530-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/san/san/memintrinsics.h:94:1: warning: identifier '__nosan_strncpy' is reserved because it starts with '__' [-Wreserved-identifier]
345531-   94 | __nosan_strncpy(char *dst, const char *src, size_t sz)
345532-      | ^
345533-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/san/san/memintrinsics.h:106:1: warning: identifier '__nosan_strncat' is reserved because it starts with '__' [-Wreserved-identifier]
345534-  106 | __nosan_strncat(char *dst, const char *src, size_t sz)
345535-      | ^
345536-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm64/dbgwrap.c:29:
345537-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/cpu_data_internal.h:38:
345538-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kern_types.h:36:
345539-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/mach_types.h:80:
--
345601-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/_types.h:79:25: warning: identifier '__darwin_uuid_t' is reserved because it starts with '__' [-Wreserved-identifier]
345602-   79 | typedef unsigned char   __darwin_uuid_t[16];
345603-      |                         ^
345604-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/_types.h:80:17: warning: identifier '__darwin_uuid_string_t' is reserved because it starts with '__' [-Wreserved-identifier]
345605-   80 | typedef char    __darwin_uuid_string_t[37];
345606-      |                 ^
345607:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:1958:3: error: use of undeclared identifier 'nio_u_mark'
345608- 1958 |                 nio_u_mark(" U2T");
345609-      |                 ^
345610-             CC dlil.o
345611-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm64/dbgwrap.c:29:
345612-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/cpu_data_internal.h:38:
345613-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kern_types.h:36:
345614-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/mach_types.h:80:
345615-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/host_info.h:66:
345616-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/message.h:813:
345617-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/debug.h:32:
--
345658-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/message.h:824:6: warning: identifier '__ovr' is reserved because it starts with '__' [-Wreserved-identifier]
345659-  824 |         if (round_msg_overflow(x, &x)) {
345660-      |             ^
345661-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/message.h:816:15: note: expanded from macro 'round_msg_overflow'
345662-  816 |                 bool __ovr = os_add_overflow(in, (__typeof__(*out))(sizeof(natural_t) - 1), out); \
345663-      |                      ^
345664:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:1960:3: error: use of undeclared identifier 'nio_u_mark'
345665- 1960 |                 nio_u_mark(" U2B");
345666-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm64/dbgwrap.c:29:
345667-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/cpu_data_internal.h:38:
345668-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kern_types.h:36:
345669-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/mach_types.h:80:
345670-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/host_info.h:67:
345671-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/vm_statistics.h:448:7: warning: identifier '__unused_bit_8' is reserved because it starts with '__' [-Wreserved-identifier]
345672-  448 |                     __unused_bit_8:1,
345673-      |                     ^
345674-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/vm_statistics.h:449:7: warning: identifier '__unused_bit_9' is reserved because it starts with '__' [-Wreserved-identifier]
--
547971-      |                 ^
547972-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1033:6: note: expanded from macro 'NECPLOG'
547973- 1033 |          : warning: identifier '__startup_ZALLOC_entry___zone_site_register_116' is reserved because it starts with '__' [-Wreserved-identifier]
547974-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/skywalk/nexus/nexus_var.h:589:
547975-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/skywalk/nexus/nexus_adapter.h:60:
547976-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/skywalk/os_packet_private.h:948:
547977:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/skywalk/packet_common.h:   822  116 | osKA:1_log_error: warning: identifier '__packet_set_traffic_class' is reserved because it starts with '__' [-Wreserved-identifier](necp
547978-LLOC_A  822 | __packeRRAY_t_set_tr_log_handle, "%s: " format "\n",TYPE_DECL(affic __FUNCTipc_port_requesION__, __Vt_tabA_ARGle, S__); _cls\
547979-      ass(constructt uin|  ipc_port_reqt            ^
547980-uest6/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396:5: note: expanded from macro 'os_log_error'4_t ph);
547981-      | ^
547982-, const uin/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:966:2t32_t: note: 
547983- tc)
547984-      | ^
547985-expanded from macro 'KALLOC_ARRAY_TYPE_DECL'
547986-  966 |         KALLOC_DI  396 |     _Static_SPATCH(KALassert(__LOC_ARRAY_TY/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/skywalk/packet_common.h:871:1:buPE_DE warning: iltiidentifier '__packet_get_traffic_class' is reserved because it starts with '__' [-Wreserved-identifier]
547987-CL, ##__nV_constant_p(forma  871 | __pat), "format string must be constant"); A_ARGcket_   geS__)
--
839597-GS__); \
839598-      |                                             ^~~~~~~~~~~
839599-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.h:204:2: note: expanded from macro 'STARTUP_ARG'
839600-  204 |         __STARTUP_ARG(func, __L/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1399:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]INE__, subsystem, ra
839601- 1398 |                 NETEM_LOG(LOG_nk, func, arg)
839602-      |         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
839603:ERR, "| error: du/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.h:736plication_p %d > %d":2:,
839604-      |                                                            ~~
839605-      |                                                            %u
839606- 1399 |                     p->ifnet note: expanded from macro '__STARTUP_ARG'
839607-  736 |         __STARTUP1(name, lineem_duplication_p, NETEM_PS, subsystem, rank, funcCALE);
839608-      |                     ^~~~~~~~~~~~~~~~~~~~~~~~
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

## ci-steps.log

### the tail

```
16:47:24 prepare: started in /Users/runner/work/UniXNU-nio/UniXNU-nio
16:47:24 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/mach.development.bcm2837.unstripped
16:47:24 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/link.filelist
16:47:24 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o
16:47:24 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/iokit/DEVELOPMENT/IOService.o
16:47:24 script: scripts/build-xnu-4k-baseline.sh (     833 lines)
16:47:24 script absent: out/nio/ios-16.5-20F66/nio/tree/scripts/build-xnu-4k-baseline.sh
16:47:24 prepare: done
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
