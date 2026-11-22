# Why the build failed

run: 658, commit c167d9f23f7c5ae29ed5120ef1ce9e12264efa91

## replay.log

### the tail

```
  asm| Ltmp180:
  asm| ; %bb.3:                                ;   in Loop: Header=BB6_2 Depth=1
  asm| 	;DEBUG_VALUE: nio_hb_ns <- $x25
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:n <- $w21
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:nio_hb_last <- $x24
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:nio_hb_last <- $x25
  asm| 	.loc	4 709 4 is_stmt 1               ; .cache/xnu-work/osfmk/kern/startup.c:709:4
  asm| 	mov	x0, x19
  asm| 	bl	_nio_dc_puts
  asm| Ltmp181:
  asm| 	.loc	4 710 16                        ; .cache/xnu-work/osfmk/kern/startup.c:710:16
  asm| 	mov	w0, w21
  asm| 	.loc	4 710 4 is_stmt 0               ; .cache/xnu-work/osfmk/kern/startup.c:710:4
  asm| 	bl	_nio_dc_putu
  asm| Ltmp182:
  asm| 	.loc	4 711 4 is_stmt 1               ; .cache/xnu-work/osfmk/kern/startup.c:711:4
  asm| 	mov	x0, x20
  asm| 	bl	_nio_dc_puts
  asm| Ltmp183:
  asm| 	.loc	4 712 16                        ; .cache/xnu-work/osfmk/kern/startup.c:712:16
  asm| 	ldr	x8, [sp]
  asm| Ltmp184:
  asm| 	;DEBUG_VALUE: nio_hb_ns <- $x8
  asm| 	.loc	4 712 26 is_stmt 0              ; .cache/xnu-work/osfmk/kern/startup.c:712:26
  asm| 	lsr	x8, x8, #3
  asm| Ltmp185:
  asm| 	umulh	x8, x8, x23
  asm| 	lsr	x0, x8, #4
  asm| 	.loc	4 712 4                         ; .cache/xnu-work/osfmk/kern/startup.c:712:4
  asm| 	bl	_nio_dc_putu
  asm| Ltmp186:
  asm| 	.loc	4 0 4                           ; .cache/xnu-work/osfmk/kern/startup.c:0:4
  asm| 	mov	x24, x25
  asm| Ltmp187:
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:nio_hb_last <- $x24
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:nio_hb_last <- $x24
  asm| 	b	LBB6_1
  asm| Ltmp188:
  asm| 	.loh AdrpAdd	Lloh93, Lloh94
  asm| 	.loh AdrpAdd	Lloh91, Lloh92
```

## ci-steps.log

### the tail

```
  asm| Ltmp180:
  asm| ; %bb.3:                                ;   in Loop: Header=BB6_2 Depth=1
  asm| 	;DEBUG_VALUE: nio_hb_ns <- $x25
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:n <- $w21
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:nio_hb_last <- $x24
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:nio_hb_last <- $x25
  asm| 	.loc	4 709 4 is_stmt 1               ; .cache/xnu-work/osfmk/kern/startup.c:709:4
  asm| 	mov	x0, x19
  asm| 	bl	_nio_dc_puts
  asm| Ltmp181:
  asm| 	.loc	4 710 16                        ; .cache/xnu-work/osfmk/kern/startup.c:710:16
  asm| 	mov	w0, w21
  asm| 	.loc	4 710 4 is_stmt 0               ; .cache/xnu-work/osfmk/kern/startup.c:710:4
  asm| 	bl	_nio_dc_putu
  asm| Ltmp182:
  asm| 	.loc	4 711 4 is_stmt 1               ; .cache/xnu-work/osfmk/kern/startup.c:711:4
  asm| 	mov	x0, x20
  asm| 	bl	_nio_dc_puts
  asm| Ltmp183:
  asm| 	.loc	4 712 16                        ; .cache/xnu-work/osfmk/kern/startup.c:712:16
  asm| 	ldr	x8, [sp]
  asm| Ltmp184:
  asm| 	;DEBUG_VALUE: nio_hb_ns <- $x8
  asm| 	.loc	4 712 26 is_stmt 0              ; .cache/xnu-work/osfmk/kern/startup.c:712:26
  asm| 	lsr	x8, x8, #3
  asm| Ltmp185:
  asm| 	umulh	x8, x8, x23
  asm| 	lsr	x0, x8, #4
  asm| 	.loc	4 712 4                         ; .cache/xnu-work/osfmk/kern/startup.c:712:4
  asm| 	bl	_nio_dc_putu
  asm| Ltmp186:
  asm| 	.loc	4 0 4                           ; .cache/xnu-work/osfmk/kern/startup.c:0:4
  asm| 	mov	x24, x25
  asm| Ltmp187:
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:nio_hb_last <- $x24
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:nio_hb_last <- $x24
  asm| 	b	LBB6_1
  asm| Ltmp188:
  asm| 	.loh AdrpAdd	Lloh93, Lloh94
  asm| 	.loh AdrpAdd	Lloh91, Lloh92
```

## kernel.log

### the errors

```
38029: 1370 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
54235:696:81:_A  1413 |                                             "(kcdata_memcpy error: Tnote: expanded from macro 'PRIORITY_QUEUE_MAKE'
54254: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
378554:   97 | typedef long                    __darwin_ssize_t;       /* byte cou/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1273:4nt or error:  */
538350:  158 |                 printf("buffer_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
559440:epl  268 |                 y__taprintf("(%sk_res) Failed tgister_dyld_shared_o handle availabilcache_ity of LZ4image. Error 0x_info%x\n", __f_t __unc__attribut, ret);
603682:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSKextLibPrivate.h:ed to allocate memory.933: Error 0x%x\n", ret);
615590:iled to allocate memory. Error 0xtribut      |                           ^
925673:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h  129 |         } __Request__memory_error:1205:29: warning: identifier '__kalloc_array_decode' is reserved because it starts with '__' [-Wreserved-identifier]_notificat
1038146:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOTypes.h:_error:122:
1532960: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
1532971: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
1532982: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
1532993: 1413 |                     "| error: latency %d too big (> 1 sec)",
1533004: 1420 |                     "| error: jitter %dms too big (latency %dms)",
1533015: 1420 |                     "| error: jitter %dms too big (latency %dms)",
1533026: 1438 |                     "| error: loss recovery %dms too big",
1533037: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
1533048: 1463 |                     "| error: output interval %dms too big",
1799115: 2626 |                 FDLOG(LOG_ERR, fd_cb, "failed to get the close error: %d", error);
1801939: 4398 |                                 FDLOG(LOG_DEBUG, &nil_pcb, "ctl_enqueuembuf returned an error: %d", error);
1880593:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
1880759:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
1888980:G_DEBUG, "esp4_output: internal error: "
1889011:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
1982596:  275 |         SASEL_LOG("Returned with error: %d", err);
2178680:rwin_ssize_t;       /* byte cou/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdatomic.h:112:In file included from nt or/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm64/bsd_arm64.c error:9: */
2462663:    "(kcdata_me/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:1432:2: note: mcpy error: %d, length: %ld)\n",expanded from macro 'KALLOC_DISPATCH'
2462685:loc_buffer error: %d, kcdata error:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/posix_shm.c:1007:2: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
2479050:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if_var_private.hin_error::549:
2859233:Undefined symbols for architecture arm64:
2859236:ld: symbol(s) not found for architecture arm64
2859237:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
2859238:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
2859239:make[2]: *** [build_all] Error 2
2859240:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
2859241:make: *** [build] Error 2
```

### around them

```
38023- 1360 |                         IOLog("Failed to open corefile of size %llu MB (returned error 0x%x)\n",
38024-      |                                                                                          ~~
38025-      |                                                                                          %x
38026- 1361 |                             (corefile_fallback_size_bytes / (1024ULL * 1024ULL)), err);
38027-      |                                                                                   ^~~
38028-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1370:76: warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
38029: 1370 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
38030-      |                                                                                   ~~     ^~~
38031-      |                                                                                   %x
38032-nt_linkage_invalid(queue_entry_t e);
38033-      |             ^
38034-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/queue.h:221:1: warning: identifier '__QUEUE_ELT_VALIDATE' is reserved because it starts with '__' [-Wreserved-identifier]
38035-  221 | __QUEUE_ELT_VALIDATE(queue_entry_t elt)
38036-      | ^
38037-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/queue.h:229:1: warning: identifier '__DEQUEUE_ELT_CLEANUP' is reserved because it starts with '__' [-Wreserved-identifier]
38038-  229 | __DEQUEUE_ELT_CLEANUP(queue_entry_t elt)
38039-      | ^
--
54229-<scratch space>:134:1: note: expanded from here
54230-  134 | __startup_lck_mtx_spec_devsw_lock_list_mtx
54231-      | ^
54232-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/bsd_stubs.c:61:8: warning: identifier '__startup_LOCKS_entry_lck_mtx_startup_init_61' is reserved because it starts with '__' [-Wreserved-identifier]
54233-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/lock_mtx.h:192:2: note: expanded from macro 'LCK_MTX_DECLARE'
54234-  192 |         LCK_MTX_DECLARE_ATTR(var, g/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: rp, LCKwarning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
54235:696:81:_A  1413 |                                             "(kcdata_memcpy error: Tnote: expanded from macro 'PRIORITY_QUEUE_MAKE'
54236-T  696 |             R%d, lengt_NULL)
54237-      |         ^
54238- h: %ld)\n",
54239-      |                                                                                ~~~
54240-      |                                                                                %zu
54241- 1414 |                /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/lock_mtx.h:188:2: note: expanded from macro 'LCK_MTX_DECLARE_ATTR'
54242-         188 |                             STARTUP_ARG(LOCKS, STARTUP_RANK_FOURTH, lck_mtx_startup_init, \
54243-      |         ^
54244-        /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/startup.h:204:         2                    p: a  tnote:                               \
54245-      |                                                                                 ^
--
54248-PRIORITY_QUEUE_MAKE_BASE'h_
54249-, mc_eS  rT677rA | oR_rT_, fatal_failure_desc_len);
54250-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
54251-pqueue_overloadable extern pqelem_t                           UP_ARG(func, __LINE/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning:          format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
54252-       \
54253-      |                                                                                 ^
54254: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
54255-      |                                                                                                   ~~~
54256-      |                                                                                                   %zu
54257- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
54258-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
54259-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
54260- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
54261-      |                             ^/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/priority_queue.h:719:1
54262-: warning: identifier '_priority_queue_destroy' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
54263-  719 | PRIORI__, subsTY_QUEUE_MAysKE(struct prioritem,ty_ ra/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:nk, 1426:3:func warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
54264-, ar 1426 |                 zg)
--
378548-us/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/arm/_types.h:96:33: warning: identifier '__darwin_socklen_t' is reserved because it starts with '__' [-Wreserved-identifier]ed
378549-   96 | typedef __uint32_t          ))    __darwi;
378550-n_socklen_t;     /* sock      |           ^len_t (du
378551-h) */
378552-      |                                 ^
378553-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/arm/_types.h:97:33: warning: identifier '__darwin_ssize_t' is reserved because it starts with '__' [-Wreserved-identifier]
378554:   97 | typedef long                    __darwin_ssize_t;       /* byte cou/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1273:4nt or error:  */
378555-      |                                 ^
378556-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/arm/_types.h:98:33: warning: identifier '__darwin_time_t' is reserved because it starts with '__' [-Wreserved-identifier]
378557-warning: identifier '__Request__task_set_emulation_t' is reserved because it starts with '__' [-Wreserved-identifier]
378558- 1273 |         } __Req   98 | typuesedeft__task_s let_emulaong      tion_t       __attribute_    _((unused));    
378559-      |           ^
378560-__darwin_time_t;        /* time() */
378561-      |                                 ^
378562-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1283:4: warning: identifier '__Request__task_get_emulation_vector_t' is reserved because it starts with '__' [-Wreserved-identifier]
378563- 1283 |         } __Request__task_get_emulation_vector_t __attribute__((unused));
378564-      |           ^
--
925667-  175 | int     _consume_printf_args(int, ...);
925668-      |         ^
925669-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/ecc_logging.c:31:
925670-./mach/memory_error_notification.h:129:4: warning: identifier '__Request__memory_error_notification_t' is reserved because it starts with '__' [-Wreserved-identifier]
925671-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/kpi_interface.c:35:
925672-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/socket.h:88:
925673:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h  129 |         } __Request__memory_error:1205:29: warning: identifier '__kalloc_array_decode' is reserved because it starts with '__' [-Wreserved-identifier]_notificat
925674- 1205 | exion_t __attribute__((unused));tern struct
925675-      |           ^
925676- kalloc_result __k./mach/memory_error_notification.h:141:4: warning: alloc_arrayidentifier '__Request__mcc_memory_error_notification_t' is reserved because it starts with '__' [-Wreserved-identifier]
925677-  141_decode( |         } __Reque
925678-      |                             ^
925679-st__mcc_memory_error_n/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:1210:1: warning: identifier '__kalloc_array_size' is reserved because it starts with '__' [-Wreserved-identifier]
925680-otification 1210 | __kalloc_arra_t __atty_size(vm_addresribute__s_t arra((unused))y)
925681-      | ^
925682-;
925683-      |           ^
--
1038140-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/pmap.h:43:
1038141-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/pmap/pmap.h:224:
1038142-In file included from  In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Tests/TestServices/TestIOConnectMapMemoryPortLeak45265408.cpp:1049 |         os_lo/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/thread.hg1:
1038143-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Tests/TestServices/TestIOConnectMapMemoryPortLeak45265408.h:4:
1038144-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOService.h:44:
1038145-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IORegistryEntry.h:39:
1038146:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOTypes.h:_error:122:
1038147-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/task.h:127:
1038148-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_port.h:90:
1038149-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_mqueue.h:78:
1038150-(necp_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_kmsg.h:159:29: 40:
1038151-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/system.h:36:
1038152-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/thread.h:88warning: bit-field 'ikm_type' of type 'ipc_kmsg_type_t' has a different storage size than the preceding bit-field (1 vs 4 bytes) and will not be packed under the Microsoft ABI [-Wms-bitfield-padding]
1038153-:
1038154-  159 | data_trace_log_handleIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_types.h:85        ipc_kmsg_, "%type:
1038155-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/memory_object_types.h:168:8:s: " format_t            ikm_type: 2; "\n"
1038156-      , __FUN warning: CTIidentifier '__obsolete_memory_object_data_unlock' is reserved because it starts with '__' [-Wreserved-identifier]
--
1532954-mpl(kt_view_var, os_ptr_load_and_erase(elem));             \
1532955-      |                                      ^
1532956-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h:67:14: note: expanded from macro 'os_ptr_load_and_erase'
1532957-   67 |         __auto_type __elem = *__eptr;                             \
1532958-      |                     ^
1532959-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1387:7: warning: format specifies type 'int' but the argument has underlying type 'unsigned int' [-Wformat]
1532960: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
1532961-      |                                                                      ~~
1532962-      |                                                                      %u
1532963- 1387 |                     p->ifnetem_model);
1532964-      |                     ^~~~~~~~~~~~~~~~
1532965-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
```

### the tail

```
  433 |         if (round_page_overflow(x, &x)) {
      |             ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_param.h:126:15: note: expanded from macro 'round_page_overflow'
  126 |                 bool __ovr = os_add_overflow(in, (__typeof__(*out))PAGE_MASK, out); \
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
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sun Nov 22 14:03:01 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
      |            ^
1 warning generated.
             LD mach.development.bcm2837.unstripped
ld: warning: -new_linker is obsolete
ld: warning: search path '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot/usr/local/lib/kernel/platform' not found
Undefined symbols for architecture arm64:
  "_nio_usb_gadget_start", referenced from:
      _bsdinit_task in bsd_init.o
ld: symbol(s) not found for architecture arm64
clang++: error: linker command failed with exit code 1 (use -v to see invocation)
make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
make[2]: *** [build_all] Error 2
make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
make: *** [build] Error 2
build-xnu-4k-baseline.sh: line 887: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

## xnu-trace.log

### the tail

```
[13:33:32] script start (bootstrap=1 jobs=3)
  object MISSING
  source sha 7233b8ac75d6ff94
[13:35:06] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha 7233b8ac75d6ff94
[13:45:18] script start (bootstrap=0 jobs=3)
  object MISSING
  source sha 7233b8ac75d6ff94
[13:45:19] before make (bootstrap=0 jobs=3)
  object MISSING
  source sha 7233b8ac75d6ff94
[13:51:07] script start (bootstrap=0 jobs=3)
  object MISSING
  source sha 7233b8ac75d6ff94
[13:51:07] before make (bootstrap=0 jobs=3)
  object MISSING
  source sha 7233b8ac75d6ff94
[13:57:37] script start (bootstrap=0 jobs=3)
  object MISSING
  source sha 7233b8ac75d6ff94
[13:57:38] before make (bootstrap=0 jobs=3)
  object MISSING
  source sha 7233b8ac75d6ff94
```

## archive-14-build-verified-root.log

### the tail

```
PASS: real VerifiedRoot crypto + empty policy table -> libVerifiedRoot.a
      root verification is disabled: no signed policy bundle exists for this board
PASS: DEVELOPMENT_ARM64_BCM2837 holds 858 .o, 120 .cpo, 0 archives, 9 file lists, core absent
PASS: DEVELOPMENT_ARM64_BCM2837 holds 0 .o, 0 .cpo, 0 archives, 0 file lists, core absent
PASS: removed the core image, the file lists and 988 build products
PASS: 122 patched sources carry a fresh mtime
  bsd/kern/bsd_init.c: mtime 13:57:37, carries 'nio: bsd_init:'
  iokit/Kernel/IOService.cpp: mtime 13:57:37, carries 'nio: S1'
  bsd/kern/kern_exec.c: mtime 13:57:37, carries 'nio: exec: load_init_program enter'
```

## archive-13-build-storage-bindings.log

### the tail

```
PASS: libStorageBindings.a -> 18 absolute bindings over 14 kext-owned slots (com.apple.iokit.IOStorageFamily)
    __ZN20IOBlockStorageDevice10gMetaClassE -> 0xfffffff006a051d0
    __ZN20IOBlockStorageDevice11requestIdleEv -> 0xfffffff0045e2050
    __ZN20IOBlockStorageDevice13doSetPriorityEP26IOBlockStorageDeviceExtentjh -> 0xfffffff0045e2068
    __ZN20IOBlockStorageDevice13doSynchronizeEyyj -> 0xfffffff0045e2080
    __ZN20IOBlockStorageDevice13setPropertiesEP8OSObject -> 0xfffffff0045e1f38
    __ZN20IOBlockStorageDevice18doSynchronizeCacheEv -> 0xfffffff0045e2074
    __ZN20IOBlockStorageDevice18getWriteCacheStateEPb -> 0xfffffff0045e2038
    __ZN20IOBlockStorageDevice18setWriteCacheStateEb -> 0xfffffff0045e2044
    __ZN20IOBlockStorageDevice20doGetProvisionStatusEyyPjP35IOBlockStorageProvisionDeviceExtenty -> 0xfffffff0045e208c
    __ZN20IOBlockStorageDevice4initEP12OSDictionary -> 0xfffffff0045e1e30
    __ZN20IOBlockStorageDevice7doUnmapEP26IOBlockStorageDeviceExtentjj -> 0xfffffff0045e205c
    __ZN20IOBlockStorageDevice9metaClassE -> 0xfffffff005c73f40
    __ZN20IOBlockStorageDeviceC1EPK11OSMetaClass -> 0xfffffff0045e1d98
    __ZN20IOBlockStorageDeviceC2EPK11OSMetaClass -> 0xfffffff0045e1d98
    __ZN20IOBlockStorageDeviceD2Ev -> 0xfffffff0045e1db8
    __ZNK20IOBlockStorageDevice11getPropertyEPK8OSSymbol -> 0xfffffff0045e1e88
    __ZNK20IOBlockStorageDevice12getMetaClassEv -> 0xfffffff0045e1dc4
    __ZTV20IOBlockStorageDevice -> 0xfffffff005c73f50

original-bindings.o:
fffffff006a051d0 A __ZN20IOBlockStorageDevice10gMetaClassE
fffffff0045e2050 A __ZN20IOBlockStorageDevice11requestIdleEv
fffffff0045e2068 A __ZN20IOBlockStorageDevice13doSetPriorityEP26IOBlockStorageDeviceExtentjh
fffffff0045e2080 A __ZN20IOBlockStorageDevice13doSynchronizeEyyj
fffffff0045e1f38 A __ZN20IOBlockStorageDevice13setPropertiesEP8OSObject
fffffff0045e2074 A __ZN20IOBlockStorageDevice18doSynchronizeCacheEv
fffffff0045e2038 A __ZN20IOBlockStorageDevice18getWriteCacheStateEPb
fffffff0045e2044 A __ZN20IOBlockStorageDevice18setWriteCacheStateEb
fffffff0045e208c A __ZN20IOBlockStorageDevice20doGetProvisionStatusEyyPjP35IOBlockStorageProvisionDeviceExtenty
fffffff0045e1e30 A __ZN20IOBlockStorageDevice4initEP12OSDictionary
fffffff0045e205c A __ZN20IOBlockStorageDevice7doUnmapEP26IOBlockStorageDeviceExtentjj
fffffff005c73f40 A __ZN20IOBlockStorageDevice9metaClassE
fffffff0045e1d98 A __ZN20IOBlockStorageDeviceC1EPK11OSMetaClass
fffffff0045e1d98 A __ZN20IOBlockStorageDeviceC2EPK11OSMetaClass
fffffff0045e1db8 A __ZN20IOBlockStorageDeviceD2Ev
fffffff0045e1e88 A __ZNK20IOBlockStorageDevice11getPropertyEPK8OSSymbol
fffffff0045e1dc4 A __ZNK20IOBlockStorageDevice12getMetaClassEv
fffffff005c73f50 A __ZTV20IOBlockStorageDevice

```

## archive-12-build-nio-ufs-archive.log

### the tail

```
nio-ufs: build/nio-ufs/libNioUfs.a -> build/sheng-ufs/libShengUfs.a (578096 bytes, sha256 b91a135e5542e0519699fff6904497ca21778b4af1577bb74fc73a98b975f766)
```

## component-NioUfs.log

### the tail

```
NioUfs: -Werror build and arm64-apple-ios17.0 object audit passed
```

## archive-10-build-link-stubs.log

### the tail

```
compiled LinkStubs.c (legacy display 0, mobile display 0, deployment 17.0)
  _boot_log_export_put         T
  _native_gop_handoff_call     T
  _native_gop_handoff_memory   T
  _native_gpu_dcvs             D
  _native_pmap_user_mappings   T
  _qcom_usb_debug_write        T
PASS: 6 link stubs archived in /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/link-stubs/libLinkStubs.a
```

## archive-09-build-adreno650.log

### the tail

```
PASS: 31 NativeAdreno a650 objects archived
PASS: archive verified with 31 objects
```

## archive-08-build-libpthread-kernel.log

### the tail

```
every callback the sources call has the name this XNU tree uses
Matching libpthread: 3 real C sources + bootstrap, ARM64/iOS 17 audit, no unavailable kernel names
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
28517: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
28523: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
499834: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
499845: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
499856: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
499867: 1413 |                     "| error: latency %d too big (> 1 sec)",
499878: 1420 |                     "| error: jitter %dms too big (latency %dms)",
499889: 1420 |                     "| error: jitter %dms too big (latency %dms)",
499900: 1438 |                     "| error: loss recovery %dms too big",
499911: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
499922: 1463 |                     "| error: output interval %dms too big",
611016: 2626 |                 FDLOG(LOG_ERR, fd_cb, "failed to get the close error: %d", error);
612748: 4398 |                                 FDLOG(LOG_DEBUG, &nil_pcb, "ctl_enqueuembuf returned an error: %d", error);
639515:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
639623:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
646619:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
646631:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
684416:  275 |         SASEL_LOG("Returned with error: %d", err);
1059122: 3393 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
1059128: 3398 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
1848888: 1370 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
1928152:  158 |                 printf("buffer_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
1935475:  268 |                 printf("(%s) Failed to handle availability of LZ4. Error 0x%x\n", __func__, ret);
1944473:  102 |                 printf("progress_notify_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
1953505:  272 |                 printf("zlib_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
1958069:  143 |                 printf("%s failed to allocate memory. Error 0x%x\n", __func__, ret);
2863310:Undefined symbols for architecture arm64:
2863321:ld: symbol(s) not found for architecture arm64
2863322:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
2863323:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
2863324:make[2]: *** [build_all] Error 2
2863325:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
2863326:make: *** [build] Error 2
```

### around them

```
28511- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
28512-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
28513-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
28514-  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
28515-      |                 ~~               ^~~~~~~~~~~
28516-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
28517: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
28518-      |                                                                                ~~~
28519-      |                                                                                %zu
28520- 1414 |                                             path, mc_error, fatal_failure_desc_len);
28521-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
28522-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
28523: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
28524-      |                                                                                                   ~~~
28525-      |                                                                                                   %zu
28526- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
28527-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
28528-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
28529- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
28530-      |                             ^
28531-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
28532- 1426 |                 zfree(ZV_NAMEI, vn_path);
28533-      |                 ^
--
499828- 1284 |         kfree_type_impl(kt_view_var, os_ptr_load_and_erase(elem));             \
499829-      |                                      ^
499830-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h:67:14: note: expanded from macro 'os_ptr_load_and_erase'
499831-   67 |         __auto_type __elem = *__eptr;                             \
499832-      |                     ^
499833-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1387:7: warning: format specifies type 'int' but the argument has underlying type 'unsigned int' [-Wformat]
499834: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
499835-      |                                                                      ~~
499836-      |                                                                      %u
499837- 1387 |                     p->ifnetem_model);
499838-      |                     ^~~~~~~~~~~~~~~~
499839-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
499840-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
499841-      |                                                    ~~~~
499842-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
499843-      |                                             ^~~~~~~~~~~
499844-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1393:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
499845: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
499846-      |                                                           ~~
499847-      |                                                           %u
499848- 1393 |                     p->ifnetem_corruption_p, NETEM_PSCALE);
499849-      |                     ^~~~~~~~~~~~~~~~~~~~~~~
499850-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
499851-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
499852-      |                                                    ~~~~
499853-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
499854-      |                                             ^~~~~~~~~~~
499855-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1399:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
499856: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
499857-      |                                                            ~~
499858-      |                                                            %u
499859- 1399 |                     p->ifnetem_duplication_p, NETEM_PSCALE);
499860-      |                     ^~~~~~~~~~~~~~~~~~~~~~~~
499861-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
499862-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
499863-      |                                                    ~~~~
499864-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
499865-      |                                             ^~~~~~~~~~~
499866-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1414:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
499867: 1413 |                     "| error: latency %d too big (> 1 sec)",
499868-      |                                       ~~
499869-      |                                       %u
499870- 1414 |                     p->ifnetem_latency_ms);
499871-      |                     ^~~~~~~~~~~~~~~~~~~~~
499872-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
499873-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
499874-      |                                                    ~~~~
499875-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
499876-      |                                             ^~~~~~~~~~~
499877-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1421:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
499878: 1420 |                     "| error: jitter %dms too big (latency %dms)",
499879-      |                                      ~~
499880-      |                                      %u
499881- 1421 |                     p->ifnetem_jitter_ms, p->ifnetem_latency_ms);
499882-      |                     ^~~~~~~~~~~~~~~~~~~~
499883-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
499884-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
499885-      |                                                    ~~~~
499886-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
499887-      |                                             ^~~~~~~~~~~
499888-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1421:29: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
499889: 1420 |                     "| error: jitter %dms too big (latency %dms)",
499890-      |                                                            ~~
499891-      |                                                            %u
499892- 1421 |                     p->ifnetem_jitter_ms, p->ifnetem_latency_ms);
499893-      |                                           ^~~~~~~~~~~~~~~~~~~~~
499894-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
499895-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
499896-      |                                                    ~~~~
499897-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
499898-      |                                             ^~~~~~~~~~~
499899-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1439:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
499900: 1438 |                     "| error: loss recovery %dms too big",
499901-      |                                             ~~
499902-      |                                             %u
499903- 1439 |                     p->ifnetem_loss_recovery_ms);
499904-      |                     ^~~~~~~~~~~~~~~~~~~~~~~~~~~
499905-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
499906-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
499907-      |                                                    ~~~~
499908-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
499909-      |                                             ^~~~~~~~~~~
499910-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1457:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
499911: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
499912-      |                                                         ~~
499913-      |                                                         %u
499914- 1457 |                     p->ifnetem_reordering_p, NETEM_PSCALE);
499915-      |                     ^~~~~~~~~~~~~~~~~~~~~~~
499916-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
499917-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
499918-      |                                                    ~~~~
499919-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
499920-      |                                             ^~~~~~~~~~~
499921-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1464:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
499922: 1463 |                     "| error: output interval %dms too big",
499923-      |                                               ~~
```

### the tail

```
83 warnings generated.
             CC lastkernelconstructor.o
clang: warning: no such include directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa' [-Wmissing-include-dirs]
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/libsa/lastkernelconstructor.c:31:13: warning: declaration requires a global constructor [-Wglobal-constructors]
   31 | static void last_kernel_constructor(void) __attribute__ ((constructor));
      | ~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~
1 warning generated.
             CC nonlto.o
clang: warning: no such include directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa' [-Wmissing-include-dirs]
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/libsa/nonlto.c:33:33: warning: identifier '__not_used_at_all__' is reserved because it starts with '__' [-Wreserved-identifier]
   33 | int __attribute__((__unused__)) __not_used_at_all__;
      |                                 ^
1 warning generated.
             CC version.o
clang: warning: no such include directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa' [-Wmissing-include-dirs]
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/version.c:39:12: warning: identifier '__kernelVersionString' is reserved because it starts with '__' [-Wreserved-identifier]
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sun Nov 22 13:44:19 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
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
  "_native_verified_block_root_authorized", referenced from:
      _bsd_init in bsd_init.o
  "_nio_usb_gadget_start", referenced from:
      _bsdinit_task in bsd_init.o
ld: symbol(s) not found for architecture arm64
clang++: error: linker command failed with exit code 1 (use -v to see invocation)
make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
make[2]: *** [build_all] Error 2
make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
make: *** [build] Error 2
build-xnu-4k-baseline.sh: line 887: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

## status.txt

```
patch    229 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-mark-the-ast-chain.patch
patch    230 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-mark-the-exec-copyouts.patch
patch    231 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-mark-fork-thread-creation.patch
patch    232 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-mark-thread-create-waiting.patch
patch    233 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-mark-parse-machfile.patch
patch    234 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-mark-exec-back-half.patch
patch    235 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-mark-return-to-userland.patch
patch    236 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-mark-the-user-return-path.patch
patch    237 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-sticky-user-return-flags.patch
patch    238 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-flag-the-pid1-schedule.patch
patch    239 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-flag-scheduler-look.patch
patch    240 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-yield-to-pid1-after-bsdinit.patch
patch    241 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-block-boot-thread-for-pid1.patch
patch    242 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-dump-pid1-thread-state.patch
patch    243 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-dump-pid1-runqueue.patch
patch    244 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-boost-pid1-and-preempt.patch
patch    245 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-fix-pid1-boost-priority-range.patch
patch    246 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-auto-reboot-after-150s.patch
patch    247 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-auto-reboot-via-psci.patch
patch    248 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-usb-readonly-probe.patch
patch    249 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-usb-probe-map-mmio.patch
patch    250 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-usb-state-in-pid1-marks.patch
patch    251 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-usb-gadget-driver.patch
patch    252 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-usb-gadget-start.patch
patch    253 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-auto-reboot-1200s.patch
patch    254 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-usb-gadget-move-to-bsd-init.patch
patch    255 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-usb-gadget-trace.patch
patch    256 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-usb-skip-soft-reset.patch
patch    257 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-console-log-ring.patch
patch    258 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-usb-ecm-live-log.patch
patch    259 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-usb-export-gadget-start.patch
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
