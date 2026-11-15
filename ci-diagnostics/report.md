# Why the build failed

run: 343, commit 1828f2b573dc682964e01655c030898eea7d5547

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
13971:  265 |                     DTRACE_MACF3(mac__call__ ## /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.hcheck:2311:1, void *, mpc, int, error: warning: identifier '__zone_flags_mix_tag' is reserved because it starts with '__' [-Wreserved-identifier]
45918:   62 |         strwiuct name { typeth_t volatil error: e __smr_pt0xr; }
59138: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
59144: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
60771:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/thread_status.h:38c, int, error:
63200:k, void *,_sized mp_byc, int, /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:1581:4error: warning: identifier '__Reply__mach_port_allocate_full_t' is reserved because it starts with '__' [-Wreserved-identifier]
111341:, /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_statistics.h:455mpc, int, error:nion , int__Re, MAC7: warning: identifier '__unused_bit_15' is reserved because it starts with '__' [-Wreserved-identifier]
343955:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:1956:2: error: use of undeclared identifier 'nio_u_mark'
344047:   78 | __startup_ZALLOC_entry/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:1958:3:___ error: use of undeclared identifier 'nio_u_mark'
344154:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/init.c3: error: use of undeclared identifier 'nio_u_mark'
346437:make[7]: *** [IOService.cpo] Error 1
346438:make[6]: *** [build_all] Error 2
346455:make[5]: *** [do_all] Error 2
346456:make[4]: *** [build_all] Error 2
346457:make[3]: *** [build_all_recurse_into_conf] Error 2
346473:make[2]: *** [build_all_recurse_into_iokit] Error 2
510163:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic.h:81:43 os_log_error: note: (neexpanded from macro 'os_cast_to_nonatomic_pointer'
519245:_log_error:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/host_priv.h:1012:4 note: expanded from macro '_KALLOC_TYPE_DEFINE'
550606: 1049 |         os_log/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_object.h:205_error:48:(ne note: expanded from macro 'io_lock_held'cp_
566493:og_ 1152 | In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kdp/kdp_core.c:55        u_int32_t   error:
591375: <pid=%d Applocate memoricay. tion %d Real/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/priority_queue.h:720:1Error 0x%x\n" Appl, retication : warning: identifier '_priority_queue_destroy' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
635508:  272 |                 printf("zlib_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
643052:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:  143 |                 printf("%s failed to allocate memory. Error 0x%x\n", __func__, ret);
794367: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
794378: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
794389: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
794400: 1413 |                     "| error: latency %d too big (> 1 sec)",
794411: 1420 |                     "| error: jitter %dms too big (latency %dms)",
794422: 1420 |                     "| error: jitter %dms too big (latency %dms)",
794436:"| error:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/processor.h:610:7: lo warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
794471: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
794490: 1463 |                     "| error:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/turnstile.h:350:2: ou warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]tpu
1038614: 2626 |                 FDLOG(LOG_ERR, fd_cb, "failed to get the close error: %d", error);
1042926: 4398 |                                 FDLOG(LOG_DEBUG, &nil_pcb, "ctl_enqueuembuf returned an error: %d", error);
1115832:In file included from rnal error: "/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_port.h:90
1201947:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/locks.he count or error:40:
1400698:  602 |         int __pagein_error:38;
1950979: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
1950988: 3383 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/smr.h:1092:1: warning: identifier '__smrq_serialized_append' is reserved because it starts with '__' [-Wreserved-identifier]
2234611:      __darwin_ssize_t;       /* byte count or error:303:
```

### around them

```
13965-      |                         ^
13966-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:2297:13: warning: identifier '__zone_site_register' is reserved because it starts with '__' [-Wreserved-identifier]
13967- 2297 | extern void __zone_site_regist/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_base.c:1546:2: warning: identifier '__dtrace_a0' is reserved because it starts with '__' [-Wreserved-identifier]
13968-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:er(265:14
13969-      | : note: expanded from macro 'MAC_CHECK'
13970-            ^
13971:  265 |                     DTRACE_MACF3(mac__call__ ## /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.hcheck:2311:1, void *, mpc, int, error: warning: identifier '__zone_flags_mix_tag' is reserved because it starts with '__' [-Wreserved-identifier]
13972-, 2311 | _ int, MAC_ITERAT_zone_flags_mix_tag(zalloE_CHECK); \
13973-      |                     ^
13974-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:c_flags165:2: note: expanded from macro 'DTRACE_MACF3'
13975-  165 |         DTRACE_PROBE3(__sdt_, name, arg1, arg2,_t flags, vm_tag_t tag arg3);
13976-      |         ^
13977-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h)
13978-      :139:| ^
13979-29: note: expanded from macro 'DTRACE_PROBE3'
13980-  139 |                 register uintptr_t __dtrace_a0 asm("x0") = (uintptr_t) arg/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:2352:20: warning: identifier '__pgz_decode' is reserved because it starts with '__' [-Wreserved-identifier]
13981- 23520;                | extern vm_offset_t __pgz_deco     \de(
--
45912-  300 |         SMR_OLogPOINT("IOPollER(struct plimiedt *) p_limFiit;/* Process limilets (PLPoll) */
45913-      |         ^
45914-ersSet/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/smr_types.h:71:2: note: expanded from macro 'SMR_POINTER'
45915-   71 |         upSMR_POINTE for corefiR_DECL(, tleype_t)
45916-      |         ^ failed 
45917-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/smr_types.h:62:32: note: expanded from macro 'SMR_POINTER_DECL'
45918:   62 |         strwiuct name { typeth_t volatil error: e __smr_pt0xr; }
45919-      |                                       ^
45920-%x\n", In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:77:
45921-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/mount_internal.h:85:
45922-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/vfs_context.h:9:
45923-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/user.h:84:
45924-erIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/sysctl.h:1014:
45925-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/proc_internal.h:301:2r): warning: identifier '__smr_ptr' is reserved because it starts with '__' [-Wreserved-identifier]
45926-  301 | ;
45927-        SMR_POINT      | ER(struct                                                                                   ~~     ^~~
45928-pgrp *XNU_      |                                                                                   %x
--
59132- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
59133-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
59134-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
59135-  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
59136-      |                 ~~               ^~~~~~~~~~~
59137-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
59138: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
59139-      |                                                                                ~~~
59140-      |                                                                                %zu
59141- 1414 |                                             path, mc_error, fatal_failure_desc_len);
59142-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
59143-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
59144: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
59145-      |                                                                                                   ~~~
59146-      |                                                                                                   %zu
59147- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
59148-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
59149-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
59150- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
59151-      |                             ^
59152-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
59153- 1426 |                 zfree(ZV_NAMEI, vn_path);
59154-      |                 ^
--
60765-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/system.h:36:
60766-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/thread.h:88:
60767-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_types.h:87:
60768-In file included from  mp/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/exception_types.h:193:
60769-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/thread_status.h:76:
60770-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/thread_status.h:35:
60771:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/thread_status.h:38c, int, error:
60772-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/_structs.h:35:
60773-, int, MAC_IT/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/_structs.h:600ERATE_CHECK);:1: \
60774- warning: identifier '__arm_pagein_state' is reserved because it starts with '__' [-Wreserved-identifier]
60775-        |                     ^600 | _
60776-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:165:2STR: note: UCTexpanded from macro 'DTRACE_MACF3'
60777-  165 |         DTRA_ARCE_M_PPROAGEBE3IN_(__STATE
60778-      | ^sdt
60779-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/_structs.h_, :599:nam41: note: expanded from macro '_STRUCT_ARM_PAGEIN_STATE'
60780-  599e,  | #dargefine _ST1, RUCT_AargRM_2, arg3);
60781-      |         ^
--
63194-  265 |                  tribute__ /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/san/san/memintrinsics.h:((unused  DTR));
63195-      |           ^
63196-ACE57:1: warning: identifier '__nosan_bcopy' is reserved because it starts with '__' [-Wreserved-identifier]
63197-_MAC/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h   57 | _:1567:4:_nosa warning: identifier '__Reply__mach_port_allocate_qos_t' is reserved because it starts with '__' [-Wreserved-identifier]
63198-n_bco 1567 |         } __ReplyF3(ma__mach_ppy(coort_anst vllocate_qos_tc__ca __atll__ ##tribute_oid *_((unsrc _used));
63199- chec      |           ^
63200:k, void *,_sized mp_byc, int, /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:1581:4error: warning: identifier '__Reply__mach_port_allocate_full_t' is reserved because it starts with '__' [-Wreserved-identifier]
63201-, 1581 |         } __Reply__(sz), void *d imastntch __si_portzed_by(sz), , MAC_I_asiTERATE_llocatezeC__t szfull_)
63202-      | ^t __a
63203-HECK); \
63204-      |                     ^
63205-ttribute__((u/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/san/san/memintrinsics.h/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:165nused:2: note: ));
63206-      expanded from macro 'DTRACE_MACF3'
63207-:62:|           ^
63208-1: warning: identifier '__nosan_memcmp' is reserved because it starts with '__' [-Wreserved-identifier]
63209-  165 |         DTRACE_PROBE/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h   62 | __:1593:4: warning: identifier '__Reply__task_set_port_space_t' is reserved because it starts with '__' [-Wreserved-identifier]
63210- 1593 |         } __Reply__ta3(__sdt_, name,sk_set_port_spnosanace_t_memcmp(co __atnst vtribuoid *te__((unused) aa );
--
111335-            _  265 |         _unus    ed_bi    t_11:    1,
111336-      | DTRA                    ^
111337-: warning: CE_MACF3(identifier '__ReplyUnion__clock_subsystem' is reserved because it starts with '__' [-Wreserved-identifier]
111338-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_statistics.h:453:7: warning: mac_identifier '__unused_bit_13' is reserved because it starts with '__' [-Wreserved-identifier]
111339-  231 | u  453_cal |                   l__   __u## cnusedheck_bit_, vo13:1,id *
111340-      |                     ^
111341:, /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_statistics.h:455mpc, int, error:nion , int__Re, MAC7: warning: identifier '__unused_bit_15' is reserved because it starts with '__' [-Wreserved-identifier]
111342-p_I  455lTERATE_CyUniHECKon__); \cloc
111343-      |                     ^k_su
111344- |                 bsys    _tem _unus{
111345-      | ed_bi      ^
111346-t_15:1,/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:165:2: note: expanded from macro 'DTRACE_MACF3'
111347-  165 |         DTRACE_PROBE3(__sdt_, name, arg1, arg2, arg3);
111348-      |         ^
111349-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:140:29: note: expanded from macro 'DTRACE_PROBE3'
111350-  140 |                 register uIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/skywalk/IOSkywalkSupport.cpp:32:
111351-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOBufferMemoryDescriptor.h:32:
--
343949-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.h:727:2: note: expanded from macro '__STARTUP1'
343950-  727 |         __startup_ ## subsystem ## _entry_ ## name ## _ ## line = { \
343951-      |         ^
343952-<scratch space>:63:1: note: expanded from here
343953-   63 | __startup_ZALLOC_entry___zone_site_register_127
343954-      | ^
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
