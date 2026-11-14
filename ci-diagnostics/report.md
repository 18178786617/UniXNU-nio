# Why the build failed

run: 260, commit 9dc9c946d49cad3638db53a287fbff78cf4563fd

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
46825:  303 | #define MAC_PERFORM_CALL(operatio 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
57082:emcpy error: %d, le/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/upl.h:181:4: warning: identifier '__Request__upl_commit_t' is reserved because it starts with '__' [-Wreserved-identifier]
57112: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
99965:l__ ## checkarra, void *, mpc, inty_b/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/priority_queue.has, error:696:81:, in note: expanded from macro 'PRIORITY_QUEUE_MAKE'
617407:  158 |                 printf("buffer_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
633181:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_interface.h:37log_error:
658229:  102 |                 printf("progress_notify_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
692633:iled to/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/thread_act.hNDI:646:4 allocate memory. Error 0x%x\n", __func__,: warning: identifier '__Request__thread_info_t' is reserved because it starts with '__' [-Wreserved-identifier]
760534:./device/device_server.h/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/priority_queue.h:717 1049 | :3007        os_log_error:1: warning: identifier '_priority_queue_remove_root' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
781118: 1049 |         os_log_error:
833317: 7425 |                 NECPLOG(LOG_ERR, "Remove flow error (%d)", error:);
1165458:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/locks.h:145:2: _ERR, "| error: invalinote: expanded from macro 'lock_disable_preemption_for_thread'
1165482:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/param.h:117NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
1165551: 1413 |                     "| error: latency %d too big (> 1 sec)",
1165570:ore(__dpft 1420 |                     "| error: jit_countp, *__dpft_cter %dms too big (latency %dms)",
1165589:      |         ^"| error: jitter
1165693: 1463 |                     "| error: output intervIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/libkern/net/inet_aton.cal %d:27:
1496119:i/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/netinet/flow_divert.c:2514n_ssize_t;       /* byte count or error:6: warning: identifier '__kfree_heap' is reserved because it starts with '__' [-Wreserved-identifier]
1496591: "failed to get the close error: %d", error);
1543318:  489 |                 oIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/task_ident.cs_log_error:31:
1562495:truct 202 |         { un  241signed long __opaq | _p        ipseclog((LOG_DEBUG, "ue_zerao;h4_output: inthternal error: } os_ato "
1573332:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
1573344:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
1655114:  ith error: %d", err);
1688832:    83 | os_l:1612                                : 11og_error: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
2052512:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/console/serial_console.c:624:11: error: unknown type name 'u32'
2052525:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/console/serial_console.c:624:34: error: unknown type name 'u32'
2052534:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/console/serial_console.c:626:11: error: unknown type name 'u32'
2052566:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/console/serial_console.c:626:34: error: unknown type name 'u32'
2052572:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/console/serial_console.c:628:2: error: use of undeclared identifier 'u32'
2052575:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/console/serial_console.c:632:3: error: use of undeclared identifier 'u32'
2052587:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/console/serial_console.c:634:7: error: use of undeclared identifier 'prev'
2052596:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/console/serial_console.c:635:4: error: use of undeclared identifier 'prev'
2052602:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/console/serial_console.c:641:12: error: use of undeclared identifier 'prev'
2052605:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/console/serial_console.c:643:2: error: use of undeclared identifier 'off'
2052611:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/console/serial_console.c:644:6: error: use of undeclared identifier 'off'
2052615: 1092 | __s/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/console/serial_console.c:645:3: error: use of undeclared identifier 'off'
2052620:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/console/serial_console.c:647:7: error: use of undeclared identifier 'off'
2052623:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/console/serial_console.c:648:11: error: use of undeclared identifier 'off'
2052626:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/console/serial_console.c:649:11: error: use of undeclared identifier 'off'
```

### around them

```
46819-      |                                    ^
46820-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:168:3: warning: identifier '__dtrace_a2' is reserved because it starts with '__' [-Wreserved-identifier]
46821-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:313:10: note: expanded from macro 'MAC_PERFORM'
46822-  313 |                 MAC_PERFORM_CALL(operation, mpc);           \
46823-      |                 ^
46824-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:303:42: note: expanded from macro 'MAC_PERFORM_CALL'
46825:  303 | #define MAC_PERFORM_CALL(operatio 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
46826-      |                                                                                   ~~     ^~~
46827-      |                                                                                   %x
46828-n, mpc) DTRACE_MACF3(mac__call__ ## operation, void *, mpc, int, 0, int, MAC_ITERATE_PERFORM)
46829-      |                                          ^
46830-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:165:2: note: expanded from macro 'DTRACE_MACF3'
46831-  165 |         DTRACE_PROBE3(__sdt_, name, arg1, arg2, arg3);
46832-      |         ^
46833-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:141:29: note: expanded from macro 'DTRACE_PROBE3'
46834-  141 |                 register uintptr_t __dtrace_a2 asm("x2") = (uintptr_t) arg2;                    \
46835-      |                                    ^
--
57076-  154 |         } __Request__upl_abort_t __attribute__((unused));
57077-      |           ^
57078-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
57079- 1413 |                                             "(kcdata_m/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/upl.h:168:4:      warning: identifier '__Request__upl_abort_range_t' is reserved because it starts with '__' [-Wreserved-identifier]
57080-  168 |         } __Request__upl_abort_range_t __attribute__((unused));
57081-      |           ^
57082:emcpy error: %d, le/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/upl.h:181:4: warning: identifier '__Request__upl_commit_t' is reserved because it starts with '__' [-Wreserved-identifier]
57083-  181 |         } __Request__upl_commit_t __attribute__((unused));
57084-      |           ^
57085-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/upl.h:197:4: warning: identifier '__Request__upl_commit_range_t' is reserved because it starts with '__' [-Wreserved-identifier]
57086-  197 |         } __Request__upl_commit_range_t __attribute__((unused));
57087-      |           ^
57088-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/upl.h:207:7: warning: identifier '__RequestUnion__upl_subsystem' is reserved because it starts with '__' [-Wreserved-identifier]
57089-  207 | union __RequestUnion__upl_subsystem {
57090-      |       ^
57091-ngth: %ld)\n/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/upl.h:226:4: warning: identifier '__Reply__upl_abort_t' is reserved because it starts with '__' [-Wreserved-identifier]
57092-  226 |         } __Reply__upl_abort_t __attribute_ (elm), __LINE__);     _((unused));
--
57106-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/upl.h:274:7: warning: identifier '__ReplyUnion__upl_subsystem' is reserved because it starts with '__' [-Wreserved-identifier]
57107-  274 | union __ReplyUnion__upl_subsystem {
57108-      |       ^
57109- 1414 |                                             path, mc_error, fatal_failure_desc_len);
57110-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
57111-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
57112: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
57113-      |                                                                                                   ~~~
57114-      |                                                                                                   %zu
57115- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/DINetBootHook.cpp:91:
57116-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOService.h:44:
57117-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IORegistryEntry.h:39:
57118-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOTypes.h:40:
57119-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/system.h:52:
57120-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/task.h:104:
57121-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/cs_blobs.h:c_len);
57122-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
--
99959-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_sysv_sem.c:160:2: warning: identifier '__dtrace_a0' is reserved because it starts with '__' [-Wreserved-identifier]
99960-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:1220:1: warning: identifier '__kalloc_array_base' is reserved because it starts with '__' [-Wreserved-identifier]
99961- 1220 | _/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:265:14: note: expanded from macro 'MAC_CHECK'
99962-  265 |                 oid                                               \
99963-      |                                                                                 ^
99964-    DTRACE_MACF3_kallo/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/priority_queue.h:716(mac__cal:1: c_warning: identifier '_priority_queue_remove_root' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
99965:l__ ## checkarra, void *, mpc, inty_b/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/priority_queue.has, error:696:81:, in note: expanded from macro 'PRIORITY_QUEUE_MAKE'
99966-t, MAC_ITERATE_CHECK);  696 |  \
99967-      |                     ^
99968-e(v/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:165:2:      note: expanded from macro 'DTRACE_MACF3'
99969-     m_add  165 |         DTRACE_PROBE3(__sdt_, name, arg1, arg2, arg3);
99970-      |         ^
99971-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:139:29: note: expanded from macro 'DTRACE_PROBE3'
99972-  139 |                 register uintptr_t __dtrace_a0 asm(ress_t a   rr"x0") = (uintptr_t) arg0;                    \
99973-      |                                    ^
99974-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_sysv_sem.c:160:2: warning: identifier '__dtrace_a1' is reserved because it starts with '__' [-Wreserved-identifier]
99975-a/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:265:14: note: expanded from macro 'MAC_CHECK'
--
633175-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/smr_types.h:62:32: note: expanded from macro 'SMR_POINTER_DECL'
633176- note: expanded from macro 'NECPLOG'
633177-   62 |         struct name { type_t volatile __smr_pIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOMemoryDescriptor.cpp:33:
633178- 1033 |             ostr; }
633179-      |                                       ^
633180-_In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/system.h:41:
633181:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_interface.h:37log_error:
633182-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/host_security.h:(necp_lo140:4:g_handle, "%s/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/smr_types.h:75:42: : warning: identifier '__smrq_slink_t' is reserved because it starts with '__' [-Wreserved-identifier]
633183-" format "\n", warning: identifier '__Request__host_security_create_task_token_t' is reserved because it starts with '__' [-Wreserved-identifier]
633184-   75 | t  140 |         } __ Request__ho__FUNCTION__, __VA_st_securityypedef SM_create_task_token_t __aR_POINTER(struct smrq_slinARGS__k *) __s); ttribute__((u\
633185-      |             ^
633186-mrq_slink_t;
633187-      |                                          ^
633188-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396:5: note: expanded from macro 'os_log_error'
633189-  396nused));
633190-      |           ^
633191- | /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/smr_types.h:76:9: warning: identifier '__smr_ptr' is reserved because it starts with '__' [-Wreserved-identifier]
--
760528-       _rray_at[i]->result]); \
760529-      |                                                                                                                                                                                                                                                                                                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~
760530-| tribute__((unused));
760531-      /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:77:                                                                                 ^
760532-|           ^
760533-note: expanded from macro 'NECPDATATRACELOG'
760534:./device/device_server.h/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/priority_queue.h:717 1049 | :3007        os_log_error:1: warning: identifier '_priority_queue_remove_root' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
760535-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/priority_queue.h:696:81::4: warning: identifier '__Reply__io_service_get_matching_services_t' is reserved because it starts with '__' [-Wreserved-identifier]
760536- 3007 |         } __Reply__io_service_get_matching_services_t __attribu note: expanded from macro 'PRIORITY_QUEUE_MAKE'
760537-te__((unu(necp_data_trace_log_handle, "%s: " format  696 | sed));
760538-      |           ^
760539- "   \n", __FUNCTION__, __VA_ARGS__); \
760540-      |                                                         ~~~~~~                     ^~~~~~~~~~~
760541-               /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:398             ./device/device_server.h::3023:  4: warning: identifier '__Reply__io_registry_entry_get_property_t' is reserved because it starts with '__' [-Wreserved-identifier]
760542- 3023 |         } __Reply__41io_registry_entry_get_property_t __attribute__((unused));
760543-: note: expanded from macro 'os_log_error'
760544-      |           ^
--
781112-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/memory_object_types.h:188:8: warning: identifier '__obsolete_memory_object_data_reclaim' is reserved because it starts with '__' [-Wreserved-identifier]
781113-  188 |         void *__obsolete_memory_object_data_reclaim;
781114-      |               ^
781115-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_notify.c:68:
781116-In file included from ./mach/mach_notify.h:11:
781117-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/mach_types.h:87 note: expanded from macro 'NECPDATATRACELOG'
781118: 1049 |         os_log_error:
781119-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/exception_types.h:193:
781120-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/thread_status.h:76:
781121-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/machine/thread_status.h:35:
781122-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/arm/thread_status.h:38:
781123-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/machine/_structs.h:35:
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
423 warnings generated.
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
patch    100 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-ionvram-missing-partition.patch
patch    101 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-locate-space-guard.patch
patch    102 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-space-walk-count.patch
patch    103 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kmem-locate-guard.patch
patch    104 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-meta-budget.patch
patch    105 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-range-sizes.patch
patch    106 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-chunk-hwm-retry.patch
patch    107 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-chunk-coalesce-trace.patch
patch    108 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-console-to-ramoops.patch
patch    109 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-counter-storage-in-data.patch
patch    110 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-phase-done-trace.patch
patch    111 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-counter-count-trace.patch
patch    112 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-fleh-early-fault.patch
patch    113 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-nested-abort-report.patch
patch    114 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-step-marks.patch
patch    115 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-post-earlyboot-marks.patch
patch    116 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-screen-init-null.patch
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
