# Why the build failed

run: 156, commit 4b14be9ecb6d33681c26c6ea6d762f3079270439

## kernel-bootstrap.log

### the errors

```
51134: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
57936: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
57942: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
213755:  __darwin_ssize_t;       /* =/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/host_priv.hbyte count or error:840:4:  */( 
498612:  158 |                 printf("buffer_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
515094:  268 |                 printf("(%s) Failed to handle availability of LZ4. Error 0x%x\n", __func__, ret);
541549:  102 |                 printf("progress_notify_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
561039:  272 |                 printf("zlib_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
574287:  143 |                 printf("%s failed to allocate memory. Error 0x%x\n", __func__, ret);
625134::3787:44: error: expected ')'_ports_info_t __attrib  235 | union __RequestUnion__do_not
625181:__task_map_kcdata_obj/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_importance.c:3790:29: error: extraneous ')' before ';'
625474:make[7]: *** [ipc_importance.o] Error 1
625482:  886 |         }         } __Reply__Request__thread__processor_set_i*** [build_all] Error 2
625488:_get_make[5]: *** [do_all] Error 2
625489:make[4]: *** [build_all] Error 2
625496:  555 | union _*** [build_all_recurse_into_conf] Error 2
625503:_make[2]: *** [build_all_recurse_into_osfmk] Error 2
821097:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h log_error: (340:6necp_log_han: note: dle, "%s: %s\n", __FUNCTION__, msg);        expanded from macro 'IOFreeType'       
934264:                      1049 |         os_log_error:75:
973874: 1049 |         os_log_error:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Tests/TestIOMemoryDescriptor.cpp(necp_da: note: expanded from macro 'IOFreeType'
1051916:   97 | typedef long                    __darwin_ssize_t;       /* byte count or error:31:
1059342: 1386 |                 NETEM_LOG(LOG_ERR, "| error: inva  671 | __pqueue_overloadable extern void                                    /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.hIn file included from            \/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStateReporter.cpp:33lid scheduler model %d",
1059374:_ERR, "| error: corruption_p %d > %d",
1059404:NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
1059435: 1413 |                     "| error: latency %d too bi/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1585:4: warning: identifier '__Request__task_register_dyld_set_dyld_state_t' is reserved because it starts with '__' [-Wreserved-identifier]:7: g (> 1 sec)"
1059466: 1420 |                     "| error: ji^
1059509:s_in  283 | typedef struct __SC 1420 |                     "| error: jitter %dms note: _GenericBlob {
1059540: 1438 |                     "| error: loss recovery %dms too big",
1059566: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
1059596: 1771 |         } __HIS_PROCESS_HAS_TOO_ 1463Request__task_map_kcdata_object_64_t __attribute__((unused)); |                     "| error: output interval %
1185795:        FDLOG(LOG_ERR, fd_cb, "failed to get the close error: %d", error);
1192082: 4398 |                                 FDLOG(LOG_DEBUG, &nil_pcb, "ctl_enqueuembuf returned an error: %d", error);
1206920:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
1213820:In file included from error:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if_var.h:272:
1213885:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
1248249:  275 |         SASEL_LOG("Returned with error: %d", err);
1412005:=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/arm/_types.h:21:33:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_statistics.honvert__mig_re sizeof(*(type)NULL), "size mismatch"); ((ply_error:509:7: warning: _t(__unut warning: identifier '__vmkf_unused' is reserved because it starts with '__' [-Wreserved-identifier]sidentifier '__uint16_t' is reserved because it starts with '__' [-Wreserved-identifier]
1627822: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
1627830:error: %d, kcdata error: %d, length: %ld)\n",
2104802:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
```

### around them

```
51128- 1354 |                         IOLog("Failed to open corefile of size %llu MB (returned error 0x%x)\n",
51129-      |                                                                                          ~~
51130-      |                                                                                          %x
51131- 1355 |                             (corefile_fallback_size_bytes / (1024ULL * 1024ULL)), err);
51132-      |                                                                                   ^~~
51133-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1364:76: warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
51134: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
51135-      |                                                                                   ~~     ^~~
51136-      |                                                                                   %x
51137-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1447:2: warning: 'switch' missing 'default' label [-Wswitch-default]
51138- 1447 |         switch (op) {
51139-      |         ^
51140-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1530:20: warning: missing field 'total' initializer [-Wmissing-designated-field-initializers]
51141- 1530 |         c_string = (char*)kalloc_data(string_length, (zalloc_flags_t)(Z_ZERO | Z_WAITOK | Z_NOFAIL));
51142-      |                           ^
51143-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:512:2: note: expanded from macro 'kalloc_data'
51144-  512 |         kheap_alloc(KHEAP_DATA_BUFFERS, size, flags)
--
57930- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
57931-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
57932-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
57933-  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
57934-      |                 ~~               ^~~~~~~~~~~
57935-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
57936: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
57937-      |                                                                                ~~~
57938-      |                                                                                %zu
57939- 1414 |                                             path, mc_error, fatal_failure_desc_len);
57940-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
57941-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
57942: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
57943-      |                                                                                                   ~~~
57944-      |                                                                                                   %zu
57945- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
57946-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
57947-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
57948- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
57949-      |                             ^
57950-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
57951- 1426 |                 zfree(ZV_NAMEI, vn_path);
57952-      |                 ^
--
213749-      |         ^
213750-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/processor.h:302:2: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:127warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
213751-  :29: note: expanded from macro 'DTRACE_PROBE2'
213752-h302 |         _Ato  :m127 | 33o                sr: te_dic pwarning: identifier '__darwin_ssize_t' is reserved because it starts with '__' [-Wreserved-identifier]
213753-   97 | typedef long           sgister uintpeet_tfmap_r_t  t  __au  dtrace_l  a0  past_mems oet_idle_m p("rix0m "ary )_map;ry_manager_t __attribute__(  (unused));
213754-      |           ^
213755:  __darwin_ssize_t;       /* =/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/host_priv.hbyte count or error:840:4:  */( 
213756-      |                                 ^
213757-uintptr_t) a warning: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/arm/_types.hridentifier '__Reply__vm_wire_t' is reserved because it starts with '__' [-Wreserved-identifier]:98:33
213758-g0;              : warning:       \
213759-      |                                    ^
213760-  840 |         } __Reply__vm_wi /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_mach.c:204:2: warning: re_t __attributidentifier '__dtrace_a1' is reserved because it starts with '__' [-Wreserved-identifier]
213761-e__((unused)/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:267:14: note: expanded from macro 'MAC_CHECK');
213762-
213763-identifier '__darwin_time_t' is reserved because it starts with '__' [-Wreserved-identifier]
213764-  267 |          |           ^
213765-              98/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/host_priv.h:852:4: warning: / | identifier '__Reply__thread_wire_t' is reserved because it starts with '__' [-Wreserved-identifier] t
--
625128-      |           ^
625129-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:2654:4: warning: identifier '__Reply__task_get_exception_ports_info_t' is reserved because it starts with '__' [-Wreserved-identifier]
625130- 2654 |         }/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/notify_server.h:224:4: warning: identifier '__Request__mach_notify_dead_name_t' is reserved because it starts with '__' [-Wreserved-identifier]
625131-  224 |         } __Request__mach_notify_dead_name_t __attribute__((unused));
625132-      |           ^
625133- __Reply__task_get_exception/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_importance.c/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/notify_server.h:235:7: warning: identifier '__RequestUnion__do_notify_subsystem' is reserved because it starts with '__' [-Wreserved-identifier]
625134::3787:44: error: expected ')'_ports_info_t __attrib  235 | union __RequestUnion__do_not
625135-ute__((unused));
625136-      |           ^
625137-ify_subsystem {
625138-      |       ^
625139-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:2666:4: warning: identifier '__Reply__task_test_sync_upcall_t' is reserved because it starts with '__' [-Wreserved-identifier]
625140- 3787 |         printf("nio: ipc_importance 2666 |         } __Reply_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/notify_server.h__:it255na:isk_test_sync_upcall_t 4t enter\n");
625141-      : warning: identifier '__Reply__mach_notify_port_deleted_t' is reserved because it starts with '__' [-Wreserved-identifier]
625142-  255 |         } __R|                                                   ^
625143-eply__mach__/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_importance.c:3786:51: note: _attribute__((unused));
625144-      |           ^
--
625175-d));
625176-      |           ^
625177-fine MACH_VOUCHER_ATTR_KEY_IMPORTANCE       /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/notify_server.h/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:2704:4: warning: identifier '__Reply__task_map_kcdata_object_64_t' is reserved because it starts with '__' [-Wreserved-identifier]
625178- ((mach_voucher_attr_k:291:4: warning: identifier '__Reply__mach_notify_send_once_t' is reserved because it starts with '__' [-Wreserved-identifier]
625179-  291 |         } __Re 2704 |         } __Replyey_t)2)
625180-      |                                                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~
625181:__task_map_kcdata_obj/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_importance.c:3790:29: error: extraneous ')' before ';'
625182- 3790 |             &ipc_importance_control);
625183-      |                                    ^
625184-ect_64_t __attri/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_importance.c:3788:6pbute__((unused));
625185-      |           ^
625186-: warning: left operand of comma operator has no effect [-Wunused-value]
625187-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:2714:7: warning: ly__mach_notify_send_once_t __attribute__((unused));
625188-      |           ^
625189-identifier '__ReplyUnion__task_subsystem' is reserved because it starts with '__' [-Wreserved-identifier]
625190- 2714 | union __ReplyUn/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/notify_server.h: 3788 |             (mach_voucher_attr_value_handle_t)ion__tas303:4: warning: identifier '__Reply__mach_notify_dead_name_t' is reserved because it starts with '__' [-Wreserved-identifier]0,
625191-      |             ^                                 ~k_subsystem {
--
821091-: warning: identifier '__kalloc_array_base' is reserved because it starts with '__' [-Wreserved-identifier]
821092- 1041 |             os:
821093- _In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOSubMemoryDescriptor.h:32:
821094-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOMemoryDescriptor.h:36:
821095-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSContainers.h:46:
821096-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSValueObject.h:487:2: warning: char _os_log_fmt[] = format;   identifier '__elem' is reserved because it starts with '__' [-Wreserved-identifier]
821097:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h log_error: (340:6necp_log_han: note: dle, "%s: %s\n", __FUNCTION__, msg);        expanded from macro 'IOFreeType'       
821098-1220 | __kalloc_arra  340 |             os_ptr_load_and_erase(elem));                   \
821099-      |             ^
821100-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h:67:14: note: expanded from macro 'os_ptr_load_and_erase'
821101-   67 |         __auto_type __ely_base(vm_address_t   \
821102-      |             ^
821103-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396:5: note: expanded from macro 'os_log_error'
821104-  \
821105-      |                                                                                   ^~~~~~
821106-  396 |     _Static_assert(__builtin_constant_p(format), "format st/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.cem = *__eptr;                ring must be constant");                     \
821107-      |                     ^
--
934258-regis% td1548e  | r_dyld_set_dyld_state_t __a        /In file included from ttrib /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pf_pbuf.c}0x%X)>"u:, 25 \
934259-      |                                                                                       ^~
934260-te__((unused));/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:
934261-};        In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/systm.h:107:
934262-: In file included from 1049
934263-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/tty.h:50: note: expanded from macro 'NECPDATATRACELOG'
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
patch    86 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kernel-window-rw.patch
patch    87 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-register-boot-stack.patch
patch    88 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-no-pinst-spsel.patch
patch    89 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-ast-no-thread.patch
patch    90 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-get-threadtask-null.patch
patch    91 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-check-stack-zero.patch
patch    92 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-thread-ro-null-safe.patch
patch    93 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-intstack-larger.patch
patch    94 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-null-task-derefs.patch
patch    95 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-vm-page-pageins-null.patch
patch    96 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-heartbeat-wait-for-kernel-task.patch
patch    97 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-null-parent-task.patch
patch    98 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-first-thread-kernel-stack.patch
patch    99 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-bsd-init-trace.patch
patch    100 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-ipc-startup-landmarks.patch
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
