# Why the build failed

run: 254, commit 5fa56cceabebb35035e70182887d19ced61e99f1

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
52713: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);rg2, arg3);
53257: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
53263: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
60548:d *, mp/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1441:4c, int, error: warning: , iidentifier '__Request__task_resume2_t' is reserved because it starts with '__' [-Wreserved-identifier]
364858:A_REQUIRE_ALIGNED_64(ifi 1090_iIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOServicePM.cpp:35error:
652442:r.s  268 |                 printf("(%s) Faiiled to handle n.savailability of LZ4.i Error 0x%x\n", __func__, rn_pet);
711642:  143 |                 printf("%s failed to allocate memory. Error 0x%x\n", __func__, ret);
773633:_ 1813 |         } __Request_error:659:4: warning: identifier '__Request__vm_copy_t' is reserved because it starts with '__' [-Wreserved-identifier]
1176390: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
1176401: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
1176412: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
1176423: 1413 |                     "| error: latency %d too big (> 1 sec)",
1176434: 1420 |                     "| error: jitter %dms too big (latency %dms)",
1176445: 1420 |                     "| error: jitter %dms too big (latency %dms)",
1176456: 1438 |                     "| error: loss recovery %dms too big",
1176467: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
1176478: 1463 |                     "| error: output interval %dms too big",
1377955:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.c:754:9: error: expected expression
1378001:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.c:1067:2: error: expected '}'
1378008:make[7]: *** [startup.o] Error 1
1378009:make[6]: *** [build_all] Error 2
1378010:make[5]: *** [do_all] Error 2
1378011:make[4]: *** [build_all] Error 2
1378012:make[3]: *** [build_all_recurse_into_conf] Error 2
1378013:make[2]: *** [build_all_recurse_into_osfmk] Error 2
1431509:   25 | typed get the clef unsigned longose error: %d", error);
1435162: 4176 |                 FDLOG(LOG_ERR, fd_cb, "failed to allocate the header mbuf: %/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:2297:13: warning: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/smr.hd", error:identifier '__zone_site_register' is reserved because it starts with '__' [-Wreserved-identifier]828);
1436171:uembuf returned an error: %d", error);
1455931:  466 |                 ipseclog 1389 |             (void((L *)OG_os_DEBptrUG,_lo "aad_h6_andout_erputase: i(elnteem)rnal error: ", _
1499547:_LOG("Returned with error: %d", err);
1696523:  819 |                 int error:1227:2: = cop warning: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/host_priv.h:'_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]yout(arg788
1708635:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/startup.h_log_error:736:("Inva2: lidnote: expanded from macro '__STARTUP_ARG'
1873637: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
1873643: 3383 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
1965463:str/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic.h:uct S79:69__nx_stats_channel_error: note: expanded from macro 'os_cast_to_atomic_pointer'
2354706:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
2354707:make: *** [build] Error 2
```

### around them

```
52707-      |                                                                                          %x
52708-BE3(__sen 1355 | dt_                        , name, arg1, a d(
52709-   (corefile_fallback_size_bytes / (1024ULL * 1024ULL)), err);
52710-      |       | ^
52711-                                                                                  ^~~
52712-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1364:76: warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
52713: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);rg2, arg3);
52714-      |         ^
52715-      | 
52716-                                                                                  ~~     ^~~
52717-      |                                                                                   %x
52718-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:139:29: note: expanded from macro 'DTRACE_PROBE3'
52719-  139 |                 register uintptr_t __dtrac/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/smr.h:1092:1:e_a0 asm("x0" warning: identifier '__smrq_serialized_append' is reserved because it starts with '__' [-Wreserved-identifier]
52720-) = ( 1092uintptr_t) arg0 | __smrq_serialize;                d_append(
52721-      | ^
52722-    \
52723-      |                                    ^
--
53251- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
53252-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
53253-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
53254-  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
53255-      |                 ~~               ^~~~~~~~~~~
53256-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
53257: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
53258-      |                                                                                ~~~
53259-      |                                                                                %zu
53260- 1414 |                                             path, mc_error, fatal_failure_desc_len);
53261-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
53262-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
53263: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
53264-      |                                                                                                   ~~~
53265-      |                                                                                                   %zu
53266- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
53267-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
53268-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
53269- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
53270-      |                             ^
53271-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
53272- 1426 |                 zfree(ZV_NAMEI, vn_path);
53273-      |                 ^
--
60542-p), cnp)/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1431:4: warning: identifier '__Request__task_suspend2_t' is reserved because it starts with '__' [-Wreserved-identifier]
60543-;
60544-      |         ^
60545- 1431 |         } _/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:265_Re:14: note: expanded from macro 'MAC_CHECK'que
60546-  265 |            st_   _task_   sus   pend2_DTRt _ACE_at_MAtriCF3(mac__call__bute__((unused));
60547-      |           ^ ## check, voi
60548:d *, mp/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1441:4c, int, error: warning: , iidentifier '__Request__task_resume2_t' is reserved because it starts with '__' [-Wreserved-identifier]
60549-nt, 1441 |         }  MA__RC_IequTERestATE_CH__tECKask); _re\
60550-      sum|                     ^
60551-e/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:165:2: note: expanded from macro 'DTRACE_MACF3'2_t
60552-   __165 |         attDTRribACEute_PR__(OBE(un3(_use_sdd))t_,;
60553-       na|           ^
60554-me, arg1, arg2, ar/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1451:4: warning: g3)identifier '__Request__task_purgable_info_t' is reserved because it starts with '__' [-Wreserved-identifier]
60555- 1451 |         } __Re;
60556-      que|         ^
60557-st__/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:139tas:29:k_p note: expanded from macro 'DTRACE_PROBE3'urg
60558-able_info_t __attribute__((unus  139 |          ed)   );
--
364852-  198 | __Exter        nalMetho(&__container_of(io, struct ipc_object_waitq, iowq_object)->iowq_waitq)
364853-      |           ^
364854-d/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/dlil.c/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/cdefs.h::2427:2: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
364855-1090: 2427 |         IFNET_12: note: expanded from macro '__container_of'
364856-_IF_DATArgs);\
364857-      |                             ^
364858:A_REQUIRE_ALIGNED_64(ifi 1090_iIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOServicePM.cpp:35error:
364859-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOUserServer.h:101:
364860-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOUserClient.h:208:2: warning: identifier '_ExternalMethod_Invoke' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]
364861- | /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.h:1923:s);
364862-      |         ^        uintptr_t __2
364863-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/dlil.c:169:2: note: expanded from macro 'IFNET_IF_DATA_REQUIRE_ALIGNED_64'
364864-result = (uintp  169 |         _tr_t)__ptrCASSERT(!(offsetof(s - offsetof(typtruct ifnet, ife_t, field_data.f) %);        \
364865-      |                   ^ size
364866-: note: expanded from macro 'OSDeclareAbstractStructorsWithDispatch'
364867-of (u 1923 |         _OSDeclareA_ibstrant6ctStructor4_t))s(className)
364868-, dispatch)           |              ^
--
773627-      |           ^
773628-
773629-       |                                                                                                                    ^~
773630-       |                                                                                                                    %u
773631-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1033:43: note: expanded from macro 'NECPLOG'
773632- 1033 |             os_log/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_map.h./device/device_server.h:1813:4: warning: identifier '__Request__io_connect_method_scalarI_structureI_t' is reserved because it starts with '__' [-Wreserved-identifier]
773633:_ 1813 |         } __Request_error:659:4: warning: identifier '__Request__vm_copy_t' is reserved because it starts with '__' [-Wreserved-identifier]
773634-_io_(necconnecp_  659 |         } __Requeslog_handtt__vm__mele,thod_scalarI_structureI_t __acop "%s:y " f_t __ttribute_att_(oribute__((unused));(unus
773635-      |           ^
773636-red));
773637-      |           ^
773638-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_map.h:673:4: warning: identifier '__Request__vm_read_overwrite_t' is reserved because it starts with '__' [-Wreserved-identifier]
773639-  673 |         } __Request__vm_read_overwrite_t __attribute__((unused));
773640-      |           ^
773641-./device/device_server.h:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_map.h:687:4: warning: identifier '__Request__vm_msync_t' is reserved because it starts with '__' [-Wreserved-identifier]
773642-  687 |         } __Request__vm_msymat "\n"nc_t __attribute1828:4: warning: , __((unused));
773643-      |           ^
--
1176384- 1284 |         kfree_type_impl(kt_view_var, os_ptr_load_and_erase(elem));             \
1176385-      |                                      ^
1176386-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h:67:14: note: expanded from macro 'os_ptr_load_and_erase'
1176387-   67 |         __auto_type __elem = *__eptr;                             \
1176388-      |                     ^
1176389-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1387:7: warning: format specifies type 'int' but the argument has underlying type 'unsigned int' [-Wformat]
1176390: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
1176391-      |                                                                      ~~
1176392-      |                                                                      %u
1176393- 1387 |                     p->ifnetem_model);
1176394-      |                     ^~~~~~~~~~~~~~~~
1176395-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
1176396-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
1176397-      |                                                    ~~~~
1176398-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
1176399-      |                                             ^~~~~~~~~~~
1176400-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1393:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
1176401: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
1176402-      |                                                           ~~
1176403-      |                                                           %u
1176404- 1393 |                     p->ifnetem_corruption_p, NETEM_PSCALE);
1176405-      |                     ^~~~~~~~~~~~~~~~~~~~~~~
1176406-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
1176407-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
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
patch    84 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-stack-rw.patch
patch    85 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kernel-window-rw.patch
patch    86 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-register-boot-stack.patch
patch    87 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-no-pinst-spsel.patch
patch    88 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-ast-no-thread.patch
patch    89 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-get-threadtask-null.patch
patch    90 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-check-stack-zero.patch
patch    91 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-thread-ro-null-safe.patch
patch    92 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-intstack-larger.patch
patch    93 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-null-task-derefs.patch
patch    94 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-vm-page-pageins-null.patch
patch    95 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-heartbeat-wait-for-kernel-task.patch
patch    96 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-null-parent-task.patch
patch    97 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-first-thread-kernel-stack.patch
patch    98 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-bsd-init-trace.patch
patch    99 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-ionvram-missing-partition.patch
patch    100 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-locate-space-guard.patch
patch    101 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-space-walk-count.patch
patch    102 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kmem-locate-guard.patch
patch    103 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-meta-budget.patch
patch    104 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-range-sizes.patch
patch    105 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-chunk-hwm-retry.patch
patch    106 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-chunk-coalesce-trace.patch
patch    107 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-console-to-ramoops.patch
patch    108 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-counter-storage-in-data.patch
patch    109 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-phase-done-trace.patch
patch    110 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-counter-count-trace.patch
patch    111 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-fleh-early-fault.patch
patch    112 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-nested-abort-report.patch
patch    113 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-step-marks.patch
patch    114 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-post-earlyboot-marks.patch
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
