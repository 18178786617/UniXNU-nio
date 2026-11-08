# Why the build failed

run: 30, commit c2e963d7e887d12e9ad7a8952b9ef605495f419c

## storage-headers.log

### the tail

```
PASS: 19 public IOStorageFamily headers prepared at e45fbe30a7879e0b16e26dddb78538f1b00e0bff
```

## kernel-bootstrap.log

### the errors

```
61044: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
61074:a_hply__tha 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
586190:__VA_ 1872  AR |           __vmnekf_GS        oun__s_us) loed||g_error:2 \(O8;
677218:  158 |                 printf("buffer_stage_initialize failed to allocate memory. Error 0x%x\/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c:8232:8: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
681436:ca 1049 |         os_log_error:tion_t __a(necp_data_tt46race: note: expanded from macro '_os_atomic_value_cast'_log_hat
683124:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/task.h:127og_error:
719607:   8934 |                         rogress_n856 |         NECP_DATA_TRACE_LOG_SOCKET_RESULT(debug, #defotiine Dfy_stage_initialize failed to allocEBUG4K_ERROR(...)atso, "Se memory. Error 0x%x\n", ret);
737665:  272 |                 printf("zlib_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
749138:  143 |                 printf("%s failed to allocate memory. Error 0x%x\n", __func__, ret);
827027:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/skywalk/os_skywalk_private.hig_reply_error:308:
1175159: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
1175181: 1392 |                 NETEM_LOG(LOG_ERR, "| error: coM_PAGEIN_STATE struct __arm_pagein_state
1175197: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
1175208: 1413 |                     "| error: latency %d too big (> 1 sec)",
1175219: 1420 |                     "| error: jitter %dms too big (latency %dms)",
1175230: 1420 |                     "| error: jitter %dms too big (latency %dms)",
1175241: 1438 |                     "| error: loss recovery %dms too big",
1175252: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
1175266:   1463 |                     "| error: output interval %    dms too big",
1277975:g_reply_error_t(__unused m/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:1234:1ig_reply_error: warning: identifier '__kalloc_array_end' is reserved because it starts with '__' [-Wreserved-identifier]
1325007:   97 | typedef long                    __darwin_ssize_t;       /*/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/priority_queue.h:714 byte count or error:1: warning: identifier '_priority_queue_remove_root' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
1543243: 4398 |                                 FDLOG(LOG_DEBUG, &nil_pcb, "ctl_enqueuembuf returned an error: %d", error);
1635558:log((LOG_DEBUG, "esp4_output: internal error: "
1704314:  275 |         SASEL_LOG("Returned with error:      \
2291581:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/mpsc_queue.h:215:1t(__unused mig_reply_error: warning: identifier '__mpsc_queue_append_update_tail' is reserved because it starts with '__' [-Wreserved-identifier]
2378824: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
2378830: 3383 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
2644095:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/queue.hin_error:215:13: warning: identifier '__queue_element_linkage_invalid' is reserved because it starts with '__' [-Wreserved-identifier]
2862996:Undefined symbols for architecture arm64:
2863003:ld: symbol(s) not found for architecture arm64
2863004:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
2863005:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
2863006:make[2]: *** [build_all] Error 2
2863007:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
2863008:make: *** [build] Error 2
```

### around them

```
61038-      |         ^
61039-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/signal.h:375:22: warning: identifier '__sigaction_u' is reserved because it starts with '__' [-Wreserved-identifier]
61040-  375 |         union __sigaction_u __sigaction_u;  /* signal handler */
61041-      |                             ^
61042-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/signal.h:385:22: warning: identifier '__sigaction_u' is reserved because it starts with '__' [-Wreserved-identifier]
61043-  385 |         union __sigaction_u __sigaction_u;  /* signal han/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
61044: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
61045-      |                                                                                ~~~
61046-      |                                                                                %zu
61047- 1414 |                         dler */
61048-      |                             ^
61049-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/signal.h:393:7: warning: identifier '__user32_sigaction_u' is reserved because it starts with '__' [-Wreserved-identifier]
61050-  393 | union __user32_sigaction_u {
61051-      |       ^
61052-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/signal.h:394:16: warning: identifier '__sa_handler' is reserved because it starts with '__' [-Wreserved-identifier]
61053-  394 |         user32_addr_t __sa_handler;
61054-      |                       ^
--
61068-      |                                    ^
61069-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/signal.h:411:7: warning: identifier '__user64_sigaction_u' is reserved because it starts with '__' [-Wreserved-identifier]
61070-  411 | union __user64_sigaction_u {
61071-      |       ^
61072-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/signal.h:412:18: warning: identifier '__sa_handler' is reserved because it starts with '__' [-Wreserved-identifier]
61073-  412 |         user64_addr_t   __s/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
61074:a_hply__tha 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
61075-      |                                                                                                   ~~~
61076-      |                                                                                                   %zu
61077- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
61078-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
61079-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
61080- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
61081-      |                             ^
61082-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
61083- 1426 |                 zfrendler;
61084-      |                         ^
--
586184-vm_flagst" 1497 |         );             \
586185-      |     ^(KALLOC_
586186- : 24;
586187-      |                  ^
586188-TYPE_CHECK(KT_SUMMARY_MASK_DATA, si/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/vm_statistics.h:545:6:g_type warning: identifier '__vmnekf_unused' is reserved because it starts with '__' [-Wreserved-identifier]
586189-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if_utun.c:1872:3  545, : warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]## |         
586190:__VA_ 1872  AR |           __vmnekf_GS        oun__s_us) loed||g_error:2 \(O8;
586191-      S_
586192-      |             ^
586193-|         ^
586194-LOG_DEF/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:980:2: note: previous initialization for field 'kt_size' is here
586195-AULT, "utun_  980 |         cleanup_faIOOverrimily - utundeTypedOper_detach_ators(T)ip faile;
586196-      |         ^~~~~~~~~~~~~~~~~~~~~~~~~~~
586197-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:946:2:d: %d\n",  note: expanded from macro 'IOOverrideTypedOperators'result);
586198-      | 
586199-                ^
586200-  946 |         __/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396:5: note: expanded from macro 'os_log_error'
--
681430-  %d / 0x%224 | /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:X)         1489: i  4:np _ warning: ut (%d / 0x%X) (%d / os_atomic0xidentifier '__Reply__mach_port_request_notification_t' is reserved because it starts with '__' [-Wreserved-identifier]_v%X) (%d / 0
681431- 1489 |         alx%} ueX)__Reply__ma_c>"ca,hst( _port_rp\
681432-      |                                                                                                               ^~
681433-equest_notifi, v), \
681434-      |             ^
681435-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic_private_impl.h:218/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:50: note: expanded from macro 'NECPDATATRACELOG'
681436:ca 1049 |         os_log_error:tion_t __a(necp_data_tt46race: note: expanded from macro '_os_atomic_value_cast'_log_hat
681437-nribudle,te__ "%s((unuse  : " 218 |         ({ typeofformd(at "\n"));
681438-      |           ^
681439-, __FUNCTIO/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:1501:*os_N__,cast_to_nonato4: warning: identifier '__Reply__mach_port_insert_right_t' is reserved because it starts with '__' [-Wreserved-identifier]
681440- mic_pointer(p_ 1501 |         _VA_} __ARGSReply__)__); \
681441-      |                                                         ^~~~~~m)
681442-ach_port_insert_right_t __attribute__((unused ___v = (/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:));
681443-      |           ^
681444-397:83: note: expanded from macro 'os_log_error'
681445-v); ___v; })
681446-      |                                                     ^
--
683118-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kdp/output_stages/out_disk.c/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:t __att:331049:2::
683119-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kdp/kdp_core.h:39:
683120-ribute__((unused));
683121- note: expanded from macro 'NECPDATATRACELOG'
683122-In file included from        |           ^
683123-1049 |         os_l/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/thread.h:122:
683124:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/task.h:127og_error:
683125-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_port.h:91:
683126-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_space.h:149:10: warning: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:2704:4: warning: identifier '__Reply__task_map_kcdata_object_64_t' is reserved because it starts with '__' [-Wreserved-identifier]'_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
683127-(  149 |         re
683128-necp_data_trat 2704 |         }urn (os_atomic_or_orice_log_hg(&ia __Reply__tasks->is_bits, bit,nd_m rleapel, _kax"%cdeds:at)  "a_&  format "bit) == 0;
683129-      | object_\n                ^
683130-64_t __a"/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic_private.h:550:37: note: expanded from macro 'os_atomic_or_orig'
683131-ttr,   550ib__ | #utFUdee_NCfi_((unusedneTI)) oON;
683132-s___      | a,          ^t __VA_ARGS_o
683133-_); \
683134-      |         ^
--
827021-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mig_errors.h:113:1: warning: identifier '__NDR_convert__mig_reply_error_t' is reserved because it starts with '__' [-Wreserved-identifier]
827022-ontainerserti  113 | __NDR_con failonvert_ed")
827023-      |                         ^
827024-_m_of(mq, struct ipc_port, ip_messages)ig_reply_error_
827025-      |                                         ^
827026-t(__unused mIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp_client.c:71:
827027:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/skywalk/os_skywalk_private.hig_reply_error:308:
827028-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/skywalk/nexus/nexus_var.h:589_t *x)
827029-      | ^
827030-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/cdefs.h:1089:45: note: expanded from macro '__container_of'
827031-:
827032-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/skywalk/nexus/nexus_adapter.h:60:
827033-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/skywalk/os_packet_private.h:948:
827034- 1089 |         const __typeof__/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/skywalk/packet_common.h:1888:4: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
827035-( In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IONVRAM.cpp:1888 |                         _CA((type_SSERTt *)N33:
827036-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:49:
827037-(sizeULL)->foIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/system.h:41:
--
1175153-      |               ^
1175154-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/memory_object_types.h:188:8: warning: identifier '__obsolete_memory_object_data_reclaim' is reserved because it starts with '__' [-Wreserved-identifier]
1175155-  188 |         void *__obsolete_memory_object_data_reclaim;
1175156-      |               ^
1175157-2 warnings generated.
1175158-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1387:7: warning: format specifies type 'int' but the argument has underlying type 'unsigned int' [-Wformat]
1175159: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
1175160-      |                                                                      ~~
1175161-      |                                                                      %u
1175162- 1387 |                     p->ifnetem_model);
1175163-      |                     ^~~~~~~~~~~~~~~~
1175164-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
```

### the tail

```
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
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sun Nov  8 04:00:41 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
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
ld: symbol(s) not found for architecture arm64
clang++: error: linker command failed with exit code 1 (use -v to see invocation)
make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
make[2]: *** [build_all] Error 2
make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
make: *** [build] Error 2
build-xnu-4k-baseline.sh: line 829: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

## build-console.log

### the errors

```
116:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
```

### around them

```
108-Undefined symbols for architecture arm64:
109-  "_mockfs_mountroot", referenced from:
110-      _vfstbllist in vfs_conf.o
111-  "_mockfs_vfsops", referenced from:
112-      _vfstbllist in vfs_conf.o
113-  "_mockfs_vnodeop_opv_desc", referenced from:
114-      _vfs_opv_descs in vfs_conf.o
115-ld: symbol(s) not found for architecture arm64
116:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
117-make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
118-make[2]: *** [build_all] Error 2
119-make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
120-make: *** [build] Error 2
121-build-xnu-4k-baseline.sh: line 829: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
122-== kernel: prepare storage headers
123-+ python3 /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/scripts/prepare-storage-headers.py
124-unixnu: [kernel] archives: component NioUfs is not selected
```

## status.txt

```
patch    35 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-component-load-probes.patch
patch    36 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-legacy-start.patch
patch    37 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/gpu-probe-start.patch
patch    38 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-native-gpu-broker.patch
patch    39 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-owner-boot-manifest.patch
patch    40 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-owner-cache-carrier.patch
patch    41 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-owner-root-binding-audit.patch
patch    42 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-owner-root-crypto-probe.patch
patch    43 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/offline-owner-systemos-mount.patch
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
driver   ArmCpu                   base
driver   ArmDTPlatform            base
driver   SoftwareAES              base
kit      AdrenoFirmware           base
kit      AdrenoPM4                base
kit      ArmSmmu4K                base
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
