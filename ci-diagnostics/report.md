# Why the build failed

run: 55, commit 90c51843082d555455ff3bf7c1834a608f647888

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
48625: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
55361: 1413 |                                         /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.hbject_    spec img"(kc4_odata_me:1527:mcpbjey error: %d,4: warning: identifier '__Reply__mach_port_set_seqno_t' is reserved because it starts with '__' [-Wreserved-identifier]
55377: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
66068:, error:753:4: warning: identifier '__Request__mach_port_destroy_t' is reserved because it starts with '__' [-Wreserved-identifier]
588645:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h2588 |                         os:985_log_error:2(OS_LOG_DE: FAULT, "utun_stwarning: identifier '__eptr' is reserved because it starts with '__' [-Wreserved-identifier]
653056:  158 |                 printf("buffer_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
696087:s  209 |         } __Rprogress_notify_stage_initialize fag, iled to allocate memeply__clock_get_ory. Error 0attributes_t __attribute__((unused));
863762:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:503:44error: note: (OS_L_scexpanded from macro 'kheap_alloc'
873914:   64 |             o/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.hnc, __LINE__, subs_lsysog_error:1881:2: note: tem, rank, func, arg)
1014209:  129 |         } __Request__memory_error:
1155856: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
1155867: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
1155878: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
1155889: 1413 |                     "| error: latency %d too big (> 1 sec)",
1155900: 1420 |                     "| error: jitter %dms too big (latency %dms)",
1155911: 1420 |                     "| error: jitter %dms too big (latency %dms)",
1155922: 1438 |                     "| error: loss recovery %dms too big",
1155933: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
1155944: 1463 |                     "| error: output interval %dms too big",
1326675:   20 | typedef short     /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/libkern/c++/OSKext.cpp:5975:10: error: expected unqualified-id
1326743:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/libkern/c++/OSKext.cpp:5982:7: error: use of undeclared identifier 'PE_boot_args_raw'; did you mean 'PE_boot_args'?
1329471:      | make[7]: *** [OSKext.cpo] Error 1
1329476:make[6]: *** [build_all] Error 2
1329509:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic.h*** [do_all] Error 2
1329513:   make[4]:       | *** [build_all] Error 2
1329519:      *** [build_all_recurse_into_conf] Error 2
1329528:   27 | tymake[2]: pedef long        *** [build_all_recurse_into_libkern] Error 2
1467477: 4398 |                                 FDLOG(LOG_DEBUG, &nil_pcb, "ctl_enqueuembuf returned an error: %d", error);
1538982:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
1539126:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
1547894:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
1613334:  275 |         SASEL_LOG("Returned with error: %d", err);
1889816: __paIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/string.hgein_error:44;
2279748:1430:40: r error: %d, kcdatanote: expanded from macro 'KALLOC_DISPATCH1'
2311002: , size, flags,  os_loVM_ALLOC_SI/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/signal.hgT:385_error:22: warning: identifier '__sigaction_u' is reserved because it starts with '__' [-Wreserved-identifier]
2702055: 4047 |         nfsm_chain_get_32(error: note: expanded from macro '_os_atomic_c11_op_orig'
2760457:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
2760458:make: *** [build] Error 2
```

### around them

```
48619- 1354 |                         IOLog("Failed to open corefile of size %llu MB (returned error 0x%x)\n",
48620-      |                                                                                          ~~
48621-      |                                                                                          %x
48622- 1355 |                             (corefile_fallback_size_bytes / (1024ULL * 1024ULL)), err);
48623-      |                                                                                   ^~~
48624-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1364:76: warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
48625: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
48626-      |                                                                                   ~~     ^~~
48627-      |                                                                                   %x
48628-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:533:2: warning: identifier '__dtrace_a0' is reserved because it starts with '__' [-Wreserved-identifier]
48629-  533 |         MAC_PERFORM(vnode_notify_open, cred, vp, mac_vnode_label(vp), acc_flags);
48630-      |         ^
48631-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:313:10: note: expanded from macro 'MAC_PERFORM'
48632-  313 |                 MAC_PERFORM_CALL(operation, mpc);           \
48633-      |                 ^
48634-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:303:42: note: expanded from macro 'MAC_PERFORM_CALL'
48635-  303 | #define MAC_PERFORM_CALL(operation, mpc) DTRACE_MACF3(mac__call__ ## operation, void *, mpc, int, 0, int, MAC_ITERATE_PERFORM)
--
55355-ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
55356-      |                 ~~               ^~~~~~~~~~~
55357-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:1515:4: warning: identifier '__Reply__mach_port_extract_right_t' is reserved because it starts with '__' [-Wreserved-identifier]
55358- 1515 |         } __Reply__mach_port_extract_right_t __attribute__((_o/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:unused));
55359-1414:26      |           ^
55360-: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
55361: 1413 |                                         /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.hbject_    spec img"(kc4_odata_me:1527:mcpbjey error: %d,4: warning: identifier '__Reply__mach_port_set_seqno_t' is reserved because it starts with '__' [-Wreserved-identifier]
55362-ct_ 1527 | spec_t;
55363-      |                ^
55364- length: %ld)\n",
55365-      |                                                                                ~~~
55366-      |                                                                                %zu
55367- 1414 |                                             path, mc_error, fatal_failure_desc_len);
55368-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
55369-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/vfs/vfs_bio.c:111:
55370-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/ubc_internal.h:48:
55371-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/code_signing.h:50:
55372-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/img4/firmware.h:204:
55373-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/img4/chip.h:199:16: warning: identifier '_img4_chip_instance' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
55374-  199 | typedef struct _img4_chip_instance {
55375-      |                ^
55376-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
55377: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
55378-      |                                                                                                   ~~~
55379-      |                                                                                                   %zu
55380- 1419 |                                     path, reIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/vfs/vfs_bio.c:111:
55381-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/ubc_internal.h:48        } __a:
55382-In file included from Rsoneply__mac_errh_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/code_signing.h:50port_seor,t_seq kno_tcda __attribute_:
55383-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/img4/firmware.h:212ta_e:
55384-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/img4/runtime.h:rror,273:_((u2: fatal_nused))f warning: ;
55385-      |           ^
55386-ailure_desc_len);
55387-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:1541:4: warning: identifier '__Reply__mach_port_get_attributes_t' is reserved because it starts with '__' [-Wreserved-identifier]
--
66062-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/arm/OSByteOrder.h:15:741:4: warning: identifier '__Request__mach_port_allocate_t' is reserved because it starts with '__' [-Wreserved-identifier]  265 |          
66063-  741 |              } __     Request__m DTRAach_port_aCE_MAllocaCF3(mte_t ac__c__attall__ribut ## e__ch:(1: warning: identifier '_OSSwapInt16' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier](unused)ec
66064-);
66065-      |           ^
66066-k, void *,   15 | _OSSwapInt16(
66067- /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.hmpc, int      | ^
66068:, error:753:4: warning: identifier '__Request__mach_port_destroy_t' is reserved because it starts with '__' [-Wreserved-identifier]
66069-  753 |         } __Req, int, MAuesC_It__TERmacATEh_p_CHECKort); _de\
66070-      str|                     ^
66071-oy_t /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:165:2: note: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/arm/OSByteOrder.h:expanded from macro 'DTRACE_MACF3'
66072-__attr  165 |         DTRACEibute_PROB__((uE3(__nusedsdt_,));
66073-       name|           ^
66074-, a25:1: warning: identifier '_OSSwapInt32' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]
66075-rg1,/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h   25 | _:765 aOS:4rgSw: warning: identifier '__Request__mach_port_deallocate_t' is reserved because it starts with '__' [-Wreserved-identifier]
66076-apInt32(
66077-      |   765 |         }^
66078-2,  __Requesargt__3);mac
--
588639-  327 |     _Stati         c_assert(__      builtin_constan \
588640-      | t_p(        ^
588641-format), "format string must be constant");         \
588642-      |     ^
588643-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if_utun.c:2588:4: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
588644- In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOMapper.cpp:31:
588645:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h2588 |                         os:985_log_error:2(OS_LOG_DE: FAULT, "utun_stwarning: identifier '__eptr' is reserved because it starts with '__' [-Wreserved-identifier]
588646-art: ctl_get/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:enqueuepac950:2: note: expanded from macro 'IOOverrideTypedOperatorsSupportingArrayOperators'
588647-k  950 |         _etcount re_IOOturned error %d\ven", error_pc);
588648-      rrideTyped|                         ^
588649-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396:5: note: expanded from macro 'os_log_error'
588650-  396 |     _Static_aOpessert(__builtin_raconstant_p(format), "format string mutorsst be constant")(type);             \
588651-
588652-            |     ^
588653-|         ^
588654-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:869:10: note: expanded from macro '__IOOverrideTypedOperators'
588655-  869/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if_utun.c:2606:5: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
--
863756-  105 |         sp_label->ispl_service_name = kalloc_data(sp_string_name_len + 1, Z_WAITOK);
863757-      |                                       ^
863758-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:512:2: note: expanded from macro 'kalloc_data'
863759-  512 |         kheap_alloc/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/priority_queue.h:720:1: warning: identifier '_priority_queue_destroy' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
863760-s(KHEAP_DATA_BUFFER_log_S, size, flags)
863761-      |   720 | PRIORITY_QUEUE_MAKE(struct priority_queue        ^
863762:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:503:44error: note: (OS_L_scexpanded from macro 'kheap_alloc'
863763-hed_stOG_DEFAULT, "%s  503 | : %s\nable_m",         kh__Feap_Uaalloc_tag(kalloc_heap, size, flags, VM_ALLOC_SITE_TAG()NCTION__, msg);  x *)
863764-      , p|                                                   ^
863765-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/zalloc.h:2303:2: note: expanded from macro 'VM_ALLOC_SITE_TAG'
863766-r        iority_queu       \
863767-      |             ^
863768-e_entry_stable 2303 |         STARTUP_ARG/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396:5: note: expanded from macro 'os_log_error'
863769-(ZALLOC, S  396 |     _Static__t);
863770-      | ^
863771-TARTUP_RANK_assert(__bui/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/priority_queue.h:696:81: note: expanded from macro 'PRIORITY_QUEUE_MAKE'
863772-LAST, __zo  696 |        ne_site_register,            ltin_co &site);   \
--
873908-r))atch)
873909-      |         ^
873910-
873911-      |         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
873912-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.h:204:2: note: expanded from macro 'STARTUP_ARG'
873913-  204 |         __STARTUP_ARG(fu/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.c:64:6: note: expanded from macro 'NETAGENTLOG'
873914:   64 |             o/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.hnc, __LINE__, subs_lsysog_error:1881:2: note: tem, rank, func, arg)
873915-      |         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
873916-(OS_LOG_DEexpanded from macro '_OSDeclareDefaultStructors'
873917-FAULT, "%s: " f 1881 |         OSDeclarormateCommonStructors(className, dispatch);              \
873918-      |         ^
873919-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.h:1856:5: note: expanded from macro 'OSDeclareCommonStructors'
873920-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.h:736:2: note: expanded from macro '__STARTUP_ARG'
873921- "\n  736 |  "1856 |     _        __STARTUP1(name, line, subsOS_ADD_METHODS(classNaystem,, _me, rank, func, arg, ar_FUNCTION__, __ dispatchVA_ARGS__); \
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
