# Why the build failed

run: 326, commit a2250b6838a181175043c15058eb7976c528ba05

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
54289: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
55347: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
55354: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
126968:  265 |                     DTRACE_MACF3(mac__call__ ## check, void *, mpc, int, error:416:2:,  677 |  int__p note: expanded from macro 'SYSCTL_OID'
323690:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:4064:55: error: member reference type 'OSPtr<const OSSymbol>' (aka 'const OSSymbol *') is a pointer; did you mean to use '->'?
323697:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:4064:56: error: no member named 'get' in 'OSSymbol'
326457:make[7]: *** [IOService.cpo] Error 1
326458:make[6]: *** [build_all] Error 2
326459:make[5]: *** [do_all] Error 2
326460:make[4]: *** [build_all] Error 2
326461:make[3]: *** [build_all_recurse_into_conf] Error 2
326469:  675 |         sta*** [build_all_recurse_into_iokit] Error 2
480688:  ut error:
482473: 1882 |         /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/skywalk/os_packet_private.h:264:18        os_log_error: warning: identifier '__flag' is reserved because it starts with '__' [-Wreserved-identifier]
566533:            os_l/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:293:83og_error: note: expanded from macro 'os_log'
568639:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/task.h os_log_error:127:
571324:   64 |         /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c:8785    os_log_error:6:(OS note: format string is defined here_LO
578943:_attri/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_param.h:126error:15: note: expanded from macro 'round_page_overflow'
579924: 1033 |            /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:1435:4 os_log_error: warning: (neidentifier '__Reply__mach_port_peek_t' is reserved because it starts with '__' [-Wreserved-identifier]
597221:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/thread_act.h:787 1049 |         os_log_error:4(necp: warning: identifier '__Request__thread_assign_default_t' is reserved because it starts with '__' [-Wreserved-identifier]_data
602611:l3,ailabilit vay ol3, inf LputZ4. Error 0x%x\/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/pthread/priority_private.h1,n", __f: inu289:1put1, input2, i: warning: identifier '_pthread_priority_thread_qos_fast' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
609953:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/proc.h 1049 |         os_log_error:107:(ne18: cp_warning: identifier '__p_back' is reserved because it starts with '__' [-Wreserved-identifier]
641646:ry. ^Error 0x%
652988:  143 |                 printf("%s failed to allocate memory. Error 0x%x\n", __func__, ret);
773129: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
773140: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
773151: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
773162: 1413 |                     "| error: latency %d too biIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/mach_debug.c:65:
773183:   48 | t 1420 | ype                 d   "| error: jitter %dms too big ef __builtin_v(laa_ltenistcy  __%dmgnus)"c_v,
773196: 1420 |                     "| error: jitter %dms too big (latency %dms)",
773231: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/vm_param.h:433:6: warning: identifier '__ovr' is reserved because it starts with '__' [-Wreserved-identifier]
773251: 1463 |                     "| error:
1030281: 2626 |                 FDLOG(LOG_ERR, fd_cb, "failed to get the close error: %d", error);
1088888:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
1110621:  312 |                         ipseclog((LOG_DEB:9:UG, "esp4_output: internal warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat] error:
1110668:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
1663896:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/priority_queue.hg_error:696:81:  729 |          (format, ... note: expanded from macro 'PRIORITY_QUEUE_MAKE'
1949795:uffer error: %d, kcdata e 1432 |         Krror: %d,ALLOC length: %_Dld)\n",
1979498:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/user.h   76 |             os_log_:89error:
2433564:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
```

### around them

```
54283- 1354 |                         IOLog("Failed to open corefile of size %llu MB (returned error 0x%x)\n",
54284-      |                                                                                          ~~
54285-      |                                                                                          %x
54286- 1355 |                             (corefile_fallback_size_bytes / (1024ULL * 1024ULL)), err);
54287-      |                                                                                   ^~~
54288-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1364:76: warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
54289: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
54290-      |                                                                                   ~~     ^~~
54291-      |                                                                                   %x
54292-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1447:2: warning: 'switch' missing 'default' label [-Wswitch-default]
54293- 1447 |         switch (op) {
54294-      |         ^
54295-
54296-  165 |         DTRACE_PROBE3(__sdt_, name, arg1, arg2, arg3);
54297-      |         ^
54298-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:140:29: note: expanded from macro 'DTRACE_PROBE3'
54299-  140 |                 register uintptr_t __dtrace_a1 asm("x1") = (uintptr_t) arg1;                    \
--
55341- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
55342-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
55343-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
55344-  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
55345-      |                 ~~               ^~~~~~~~~~~
55346-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
55347: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
55348-      |                                                                                ~~~
55349-      |                                                                                %zu
55350- 1414 |                                             p warnings generated.
55351-ath, mc_error, fatal_failure_desc_len);
55352-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
55353-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
55354: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
55355-      |                                                                                                   ~~~
55356-      |                                                                                                   %zu
55357- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
55358-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
55359-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
55360- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
55361-      |                             ^
55362-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
55363- 1426 |                 zfree(ZV_NAMEI, vn_path);
55364-      |                 ^
--
126962-      |         ^
126963-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:139:29: note: expanded from macro 'DTRACE_PROBE3'
126964-  139 |                 register uintptr_t __dtrace_a0 asm("x0") = (uintptr_t) arg0;                    \
126965-      |                                    ^
126966-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_posix_sem.c:158:2: warning: identifier '__dtrace_a1' is reserved because it starts with '__' [-Wreserved-identifier]
126967-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:265:14: note: expanded from macro 'MAC_CHECK'
126968:  265 |                     DTRACE_MACF3(mac__call__ ## check, void *, mpc, int, error:416:2:,  677 |  int__p note: expanded from macro 'SYSCTL_OID'
126969-queue_overloada  416 |         __STARbl,TUP_eARG MAC_ extern pITERATE_CHECK); qelem_\
126970-      |                     ^
126971-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:165:2: note: expanded from macro 'DTRACE_MACF3'
126972-  165 |         DTRACE_Pt                                           \
126973-      |                                                                                 ^
126974-ROBE3(__sdt_, name, a(sysrg1, arg2, arg3);
126975-      |         ^
126976-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:140:29: note: expanded from macro 'DTRACE_PROBE3'
126977-  140 |                 register uintptr_t __dtrace_a1/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/priority_queue.h:719:1:c  warning: identifier '_priority_queue_destroy' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
126978-asm("x1") = (uintptr_t) arg1;    719 | t     PRIl   _##O   RITparent, _##name,           Y_QUEUE_MA K     \
--
323684-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/kpi_interface.h:1129:26: warning: identifier '___reserved' is reserved because it starts with '__' [-Wreserved-identifier]
323685- 1129 |         u_int64_t               ___reserved[2];         /* for future use */
323686-      |                                 ^
323687-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/kpi_interface.h:1152:26: warning: identifier '____reserved' is reserved because it starts with '__' [-Wreserved-identifier]
323688- 1152 |         u_int32_t               ____reserved;           /* for future use */
323689-      |                                 ^
323690:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:4064:55: error: member reference type 'OSPtr<const OSSymbol>' (aka 'const OSSymbol *') is a pointer; did you mean to use '->'?
323691- 4064 |                                             match->getObject(gIOModuleIdentifierKernelKey.get()));
323692-      |                                                              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~^
323693-      |                                                                                          ->
323694-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.h:413:46: note: expanded from macro 'OSDynamicCast'
323695-  413 |     ((type *) OSMetaClassBase::safeMetaCast((inst), OSTypeID(type)))
323696-      |                                              ^~~~
323697:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:4064:56: error: no member named 'get' in 'OSSymbol'
323698- 4064 |                                             match->getObject(gIOModuleIdentifierKernelKey.get()));
323699-      |                                                              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ^
323700-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.h:413:46: note: expanded from macro 'OSDynamicCast'
323701-  413 |     ((type *) OSMetaClassBase::safeMetaCast((inst), OSTypeID(type)))
323702-      |                                              ^~~~
323703-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:4389:1: warning: identifier '__WAITING_FOR_USER_SERVER__' is reserved because it starts with '__' [-Wreserved-identifier]
323704- 4389 | __WAITING_FOR_USER_SERVER__(IOUserServerCheckInToken * token)
323705-      | ^
323706-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if.c:94:
323707-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if.h:76:
--
480682-In file included from   ULT, "utun/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/pmap.h122 | _OSReadInt64_netif_sync_tx (
480683-      | ^%s - 
480684-:43:
480685-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/pmap/pmap.h:224:
480686-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/thread.h:116:
480687-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/sched.h:77ut/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSByteOrder.h:134:1: un_outpwarning: identifier '_OSWriteInt16' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]
480688:  ut error:
480689-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/bits.h:36 %d\n:
480690-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:1573:2: warning: identifier '__elem' is reserved because it starts with '__' [-Wreserved-identifier]", pcb->ut
480691-134 | _OSu/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/zalloc.h:874Wn_i:32: note: expanded from macro 'zfree'
480692-  874 |         (zfree)fp->i(__zff_xname, erree_zror);one, (void *)os_ptr_load_and_erase(
480693-      |                                                 ^
480694-elem));/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396:5 \
480695-      | : note: r                                      ^expanded from macro 'os_log_error'
480696-
480697-  396 |   /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h:67:14  _St: note: expanded from macro 'os_ptr_load_and_erase'
480698-at   67 |         _ic_assert(__biteInuiltin_constant_p(format), "ft16(ormat string must
--
482467-ori/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/skywalk/os_packet_private.h:263:ty_18: warning: identifier '__doff' is reserved because it starts with '__' [-Wreserved-identifier]
482468-make_f  263 |         rom_thread_qos(threaduint16_t _q     os  __doff; _/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if_utun.c:1883:30:t qos, int relpri,
482469-      | ^
482470-      warning: format specifies type 'int' but the argument has type 'u_int32_t' (aka 'unsigned int') [-Wformat]   /* 
482471-offset of data in buflet */
482472-      |                         ^
482473: 1882 |         /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/skywalk/os_packet_private.h:264:18        os_log_error: warning: identifier '__flag' is reserved because it starts with '__' [-Wreserved-identifier]
482474-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/pthread/priority_private.h(OS_LOG_D  264: |         coEFAULT, "fnet_gnst241:1:et_addre uint16_t  __fla warning: ss_lisg;t_family(%s%d, 0xb
482475-      | identifier '_pthread_priority_make_from_sched_pri' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
482476-lah,                        ^ %
482477-  241 | _ps) -/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/skywalk/os_packet_private.h:265:18thread_priority_make_from_ fai: warning: identifier '__gro_len' is reserved because it starts with '__' [-Wreserved-identifier]
482478-  265 |         const uint16_t sched_led: %d __gro_len\n"pri(int ,
482479-      sched_pri, unsigned long flags)
482480-      | ^
482481-|                                                                              ~~
482482-      |                                                                              %u
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
