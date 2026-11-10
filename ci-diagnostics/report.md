# Why the build failed

run: 107, commit 384f282606231c2db536a8b6e5b80c084c3cb2f4

## kernel-bootstrap.log

### the errors

```
49075: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
58247: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
58253: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
216697:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm64/sleh.c:2095:18: error: too many arguments to function call, expected 2, have 7
216741:lemake[7]: *** [sleh.o] Error 1
216744:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/cpp_util.h:make[6]: *** [build_all] Error 2
216745:make[5]: *** [do_all] Error 2
216746:make[4]: *** [build_all] Error 2
216747:make[3]: *** [build_all_recurse_into_conf] Error 2
216748:make[2]: *** [build_all_recurse_into_osfmk] Error 2
334784: 1156 | struct __nx_stats_channel_error:1369:4: warning: identifier '__Reply__mach_port_allocate_t' is reserved because it starts with '__' [-Wreserved-identifier]
432972:  113 | __NDR_convert__mig_reply_error: warning: identifier '__Reply__clock_get_attributes_t' is reserved because it starts with '__' [-Wreserved-identifier]
840551:LOG_ERR, "| error: invalid scheduler model %d",
840571:us_attr_t nx   94 | __nosan_G_ERR, "| error: corruption_p %d a, const nexus_ats>tr_type_ %ttd",
840627: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
840640: 1413 |                     "| error: latency %d too big (> 1 sec)",
840651: 1420 |                     "| error: jitter %dms too big (latency %dms)",
840662: 1420 |                     "| error: jitter %dms too big (latency %dms)",
840691:In file included from  1438 |                    i/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/queue.h "| error: los:63:
840729: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
840740: 1463 |                     "| error: output interval %dms too big",
952058: 2626 |                 FDLOG(LOG_ERR, fd_cb, "failed to get the close error: %d", error);
976058:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
977706:ee  602 |         /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/smr.h:846:1if,nt __pagei unsn_error: fmt, ##__VA; warning: _identifier '__smrq_lastp' is reserved because it starts with '__' [-Wreserved-identifier]
982586:tput: internal error: "
982644:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
1395503: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
1395509: 3383 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
1480580:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/signal.h:431:18/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/resource.h  602 |         int __pagein_error::;
1676118:In file included from llu int_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:368:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/skywalk/core/skywalk_var.h:80error:
1815723:In file included from chain_get_fh_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/pthread/priority_private.h/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/nfs/nfs_srvcache.cp::tr(30780error::
1872485:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
1872486:make: *** [build] Error 2
```

### around them

```
49069-  304 | #define MAC_PERFORM_RSLT(operation, mpc) DTRACE corefile of size %llu MB (returned error 0x%x)\n",
49070-      |                                                                                          ~~
49071-      |                                                                                          %x
49072- 1355 |                             (corefile_fallback_size_bytes / (1024ULL * 1024ULL)), err);
49073-      |                                                                                   ^~~
49074-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1364:76: warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
49075: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
49076-      |                                                                                   ~~     ^~~
49077-      |                                                                                   %x
49078-_MACF2(mac__rslt__ ## operation, void *, mpc, int, 0)
49079-      |                                          ^
49080-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:162:2: note: expanded from macro 'DTRACE_MACF2'
49081-  162 |         DTRACE_PROBE2(__sdt_, name, arg1, arg2);
49082-      |         ^
49083-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:128:29: note: expanded from macro 'DTRACE_PROBE2'
49084-  128 |                 register uintptr_t __dtrace_a1 asm("x1") = (uintptr_t) arg1;                    \
49085-      |                                    ^
--
58241- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
58242-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
58243-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
58244-  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
58245-      |                 ~~               ^~~~~~~~~~~
58246-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
58247: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
58248-      |                                                                                ~~~
58249-      |                                                                                %zu
58250- 1414 |                                             path, mc_error, fatal_failure_desc_len);
58251-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
58252-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
58253: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
58254-      |                                                                                                   ~~~
58255-      |                                                                                                   %zu
58256- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
58257-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
58258-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
58259- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
58260-      |                             ^
58261-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
58262- 1426 |                 zfree(ZV_NAMEI, vn_path);
58263-      |                 ^
--
216691-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/san/san/memintrinsics.h:47:1: warning: identifier '__nosan_memmove' is reserved because it starts with '__' [-Wreserved-identifier]
216692-   47 | __nosan_memmove(void *src __sized_by(sz), const void *dst __sized_by(sz), size_t sz)
216693-      | ^
216694-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/san/san/memintrinsics.h:52:1: warning: identifier '__nosan_bcmp' is reserved because it starts with '__' [-Wreserved-identifier]
216695-   52 | __nosan_bcmp(const void *a __sized_by(sz), const void *b __sized_by(sz), size_t sz)
216696-      | ^
216697:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm64/sleh.c:2095:18: error: too many arguments to function call, expected 2, have 7
216698-_T> {typedef _T t /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/san/san/memintrinsics.h:yp572094 |         pan:1: warning: identifier '__nosan_bcopy' is reserved because it starts with '__' [-Wreserved-identifier]
216699-   57 | __nosan_bcopic_with_thread_kernel_state("BadStack sp %p top %p bot %p ey(s;};
216700-      |                 ^
216701-const void *src __sized_by(sz), void *dz/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/cpp_util.hst __sized_b %#x esr %#x far %#x",
216702-      | :48:17: warning: identifier '_T' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]
216703-   48 | template <class _T> usi        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
216704- 2095 |             (y(sz), size_t sz)
216705-      | ^
216706-ng remove_const_t /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/san/san/memintrinsics.h:62:1: warning: identifier '__nosan_memcmp' is reserved because it starts with '__' [-Wreserved-identifier]
216707-void *)sp, (void *)thread->   62 | __nosan_me= typename remove_cmcmp(const void *a __sionst<_T>::type;
--
334778- 1344 |         } __Reply__mach_port_rename_t __attribute__((unused));
334779-      |           ^
334780-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:1356:4: warning: identifier '__Reply__mach_port_allocate_name_t' is reserved because it starts with '__' [-Wreserved-identifier]
334781- 1356 |         } __Reply__mach_port_allocate_name_t __attribute__((unused));
334782-      |           ^
334783-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/skywalk/os_stats_private.h:1156:8: warning: identifier '__nx_stats_channel_errors' is reserved because it starts with '__' [-Wreserved-identifier]
334784: 1156 | struct __nx_stats_channel_error:1369:4: warning: identifier '__Reply__mach_port_allocate_t' is reserved because it starts with '__' [-Wreserved-identifier]
334785- 1369 |         } __Reply__ms {
334786-      |        ^
334787-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/skywalk/os_stats_private.h:1180:8: warning: identifier '__kern_nexus_adv_metadata' is reserved because it starts with '__' [-Wreserved-identifier]
334788- 1180 | sach_port_allocate_t __attribute__((unused));
334789-      |           ^truct __kern_nexus_adv_metadata {
334790-      |        ^
334791-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/skywalk/os_stats_private.h:1182:27: warning: identifier '__reserved' is reserved because it starts with '__' [-Wreserved-identifier]
334792- 1182 |         uint16_t                 __reserved;
334793-      |                                  ^
334794-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/skywalk/os_stats_private.h:1188:8: warning: identifier '__kern_netif_intf_advisory' is reserved because it starts with '__' [-Wreserved-identifier]
--
432966-      | ^
432967-);
432968-      |           ^
432969-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSByteOrder.h:156:1: warning: identifier '_OSWriteInt64' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/clock.h:209:4
432970-  156 | _OSWriteInt64(
432971-      | ^
432972:  113 | __NDR_convert__mig_reply_error: warning: identifier '__Reply__clock_get_attributes_t' is reserved because it starts with '__' [-Wreserved-identifier]
432973-  209 |         } __Reply__clock_get_attributes_t __attribute__((unused));
432974-      |           ^
432975-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/clock.h:221:4: warning: identifier '__Reply__clock_alarm_t' is reserved because it starts with '__' [-Wreserved-identifier]
432976-  221 |         } __Reply__clock_alarm_t __attribute__((unused));
432977-      |           ^
432978-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/clock.h:231:7: warning: identifier '__ReplyUnion__clock_subsystem' is reserved because it starts with '__' [-Wreserved-identifier]
432979-  231 | union __ReplyUnion__clock_subsystem {
432980-      |       ^
432981-_t(__unused mig_reply_error_t *x)
432982-      | ^
--
840545-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/san/san/memintrinsics.h:83:1: warning: identifier '__nosan_strnlen' is reserved because it starts with '__' [-Wreserved-identifier]
840546-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/skywalk/os_nexus_private.h:259:26: warning: identifier '__cl_align' is reserved because it starts with '__' [-Wreserved-identifier]
840547-  259 |         uint32_t                __cl_align;     /* reserved */
840548-      |                                 ^
840549-   83 | __nosan_strnlen(const char *__null_terminated src, size_t sz)
840550-      | ^
840551:LOG_ERR, "| error: invalid scheduler model %d",
840552-      |                                                                      ~~
840553-      |                                                                      %u
840554- 1387 |                     p->ifnetem_model);
840555-      |                     ^~~~~~~~~~~~~~~~
840556-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
840557-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
840558-      |                                                    ~~~~
840559-  118 |           /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/san/san/memintrinsics.h:88:1: warning: identifier '__nosan_strlen' is reserved because it starts with '__' [-Wreserved-identifier]
840560-   88 | __nosan_strlen(const char *__null_teIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/netinet/igmp.c:115:
840561-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/skywalk/core/skywalk_var.hr :min88:
--
840565-   50 | __nexus_attr_set(c                 __FUNCTION__, ##__VA_ARGS__); \
840566-      |                                             ^~~~~~~~~~~
840567-src)
840568-      | ^
840569-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1393:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
840570- 1392 |                 NETEM_LOG(LOo/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/san/san/memintrinsics.h:94nst nex:1: warning: identifier '__nosan_strncpy' is reserved because it starts with '__' [-Wreserved-identifier]
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
811 warnings generated.
423 warnings generated.
     LDFILELIST bsd
make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
make: *** [build] Error 2
build-xnu-4k-baseline.sh: line 829: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

## status.txt

```
patch    56 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/zzyb-native-cryptex-os-view.patch
patch    57 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/zzyc-owner-skip-launch-constraints.patch
patch    58 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/native-smp-secondary.patch
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
