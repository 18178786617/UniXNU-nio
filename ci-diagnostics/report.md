# Why the build failed

run: 339, commit 59c15fcf806c6fdccfeb1891007d3c10882a5f3c

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
55766:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/queue.h 1413 |                                             "(kcdata_:573:2:memcpy error: %d, le _Reply__nnote: expanded from macro 'LIST_REMOVE'
55786: error: %d, kc_ARGS__, __FILE_NAMEdata e__, __rror: LINE__%d, l); \
120177:  388 | #define IOze_t;       /Del* beteyte(.. co.)          __IOKIT_DISPATuntCH( or /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.hIOerror:1573:2: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
350099:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:3929:38: error: variable 'cons_ops' is used but not defined in this translation unit, and cannot be defined in any other translation unit because its type does not have linkage
350238:make[7]: *** [IOService.cpo] Error 1/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/sysctl.h:416:2: note: expanded from macro 'SYSCTL_OID'
350250:  176 |                 #define, make[6]: sy sta*** [build_all] Error 2
350261:sctl_registe  176 |                 #define r_oid_early, smake[5]: tat        *** [do_all] Error 2
350272:  729 |             rank, __STARTUP_FUNC_CAST(fumake[4]: *** [build_all] Error 2
350288:*** [build_all_recurse_into_conf] Error 2
350294:t lemake[2]: *** [build_all_recurse_into_iokit] Error 2
588109:edef _r 1049 |         o_ui(OS_LOG_DEnt3FAULT2_t, "%s    s_log_error: %s\n", __FUNCTION__, msg);                 \
598086:38 1049 |         os_log_error:
598151:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/queue.h_error:215:13: warning: t  identifier '__queue_element_linkage_invalid' is reserved because it starts with '__' [-Wreserved-identifier]
610749:              os_log_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27error: note: expanded from macro 'panic'
623543:  102 |                 printf("progress_notify_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
650130:        printf("%s   656 | #defefaistne kfreiled to allocate memory. Error 0x%x\n", __func__entry->leve_, rl)e_type;
715839:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/turnstile.hde_t;       /*efine os_cast_to_at byte count or error:53:
788275: 1386 |                 NETEM_LOG(LOG_ERR, "| error: inIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/affinity.c:val30In file included from id sched/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/netinet/cpu_in_cksum_gen.c:59:
788394: "| error: dup/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/_types/_fd_def.h:119:1: :1430:40: note: expanded from macro 'KALLOC_DISPATCH1'
788456:error: latency %d too big (> 1 sec)",
788546:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_port.h:305                 :41: note: expanded from macro 'ip_mq_lock_held'   "| error:,
788573: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
788606: 1463 |                     "| error: output interval %dms too big",
1038103:ADED_MACRO(__VA_ARGS__, _static_a 2626 |                 FDLOG(LOG_ERR, fd_cb, "failed to get the close error: %d", error);
1043600: 4398 |                                 FDLOG(LOG_DEBUG, &nil_pcb, "ctl_enqueuembuf returned an error: %d", error);
1108838:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
1108947:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
1124796: 1551 |                         errnIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/waitq.ho_t inject_error:49 = ipsec_inject_inbou:
1223922: |         int __page/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.h:733:2in_error: note: expanded from macro '__STARTUP';
1239947:      |                     ^log(error:
1769981:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/thread.h:797error:2: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
1819622:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/malloc.h:80ount or error:
1952064: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
2149830:   80 | #define os_atomic_basetypeof(p)/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/skywalk/nexus/nexus_traffic_rule.cgein_error:1111:2: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
2433563:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
2433564:make: *** [build] Error 2
```

### around them

```
55760-      |                 ~~               ^~~~~~~~~~~
55761-: warning: identifier '__Reply__host_info_t' is reserved because it starts with '__' [-Wreserved-identifier]
55762-4: warning: format specifies type 'unsigned int' but the argument has type 'int' [-Wformat]
55763-  860 1626 |                         LIST_REMO |         VE(bp, b_v} nbufs);
55764-      | _/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414                        ^~~~~~~~~~~~~~~~~~~~~~~~~
55765-:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
55766:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/queue.h 1413 |                                             "(kcdata_:573:2:memcpy error: %d, le _Reply__nnote: expanded from macro 'LIST_REMOVE'
55767-g  573 |         Lth:hIST_CHECKost %ld)\n",
55768-      _PR_|                                                                                ~~~
55769-Einf      |                                                                                %zu
55770-o 1414 | V(elm, field);                                                  pa_t       th,_     _at mc_error,tribu fatal_failure_desc_l           \
55771-      en)t|         ^~~~~~~~~~~~~~~~~~~~~~~~~~~
55772-e__((unus;/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/queue.h:518:21: note: expanded from macro 'LIST_CHECK_PREV'
55773-      | e
55774-  517 |                 panic("Bad link elm %p prev->next                                                             ^~~~~~~~~~~~~~~~~~~~~~d))!
55775-;
55776-      |           ^
--
55780-      875 |         } __Reply__host_kernel_versio        (elm), __LINE__);                               n_    \
55781-      |                            ^~~~~~~~
55782-format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
55783-t __attri/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27: bute__( 1418 | note: (unusexpanded from macro 'panic'
55784-          589 |         (panic                        e)(e d))x   "(os_reason_allo c" @_buf;
55785-      %s:%d|           ^fer", ## __VA
55786: error: %d, kc_ARGS__, __FILE_NAMEdata e__, __rror: LINE__%d, l); \
55787-      |                 ~~               ^~~~~~~~~~~
55788-ength: <scratch space>:189:1:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_host.h:888:4%l: warning: identifier '__Reply__host_page_size_t' is reserved because it starts with '__' [-Wreserved-identifier]
55789- note: expanded from here
55790-  189 | 162d)\  888 | n",
55791-      |                                                                                                   ~~~
55792-      |                                                                                                   %zu
55793-        } __Reply__host_page_size_t __attribut 1419 |                                 6
55794-    path, reason_e      | ^~~~
55795-e__((unused));
55796-      |           ^
--
120171-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/arm/_types.h:96:33: warning: identifier '__darwin_socklen_t' is reserved because it starts with '__' [-Wreserved-identifier]
120172-   96 | typedef __uint32_t              __darwin_socklen_t;     /* socklen_t (duh) */
120173-      |                                 ^
120174-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/arm/_types.h:97:33: warning: identifier '__darwin_ssize_t' is reserved because it starts with '__' [-Wreserved-identifier]
120175-   97 | typedef long                    __darwin_s/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/skywalk/IOSkywalkSupport.cpp:961:3: warning: missing field 'kt_size_hdr' initializer [-Wmissing-designated-field-initializers]
120176-si/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:388:32: note: expanded from macro 'IODelete'
120177:  388 | #define IOze_t;       /Del* beteyte(.. co.)          __IOKIT_DISPATuntCH( or /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.hIOerror:1573:2: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
120178- 1573 |         zf Del*/
120179-      |                                 ^
120180-e/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/arm/_types.hte,ree(kt_view, ptr);
120181-      |         ^
120182-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:873:14: note: expanded from macro 'zfree'
120183-  873 |         __auto ##__V_type __zfrA_A:98:33: warning: identifier '__darwin_time_t' is reserved because it starts with '__' [-Wreserved-identifier]
120184-RGS__)
120185-      |                                ^
120186-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:740:2: note: expanded from macro '__IOKIT_DISPATCH'
120187-   98 | typedee  740ef_zone = |          l (__ong  zIOKIT_DISPATCH1one); \
--
350093-  345 |         (OSIncrementAtomic(__SAFE_CAST_PTR(volatile SInt32*,a)))
350094-      |                            ^
350095-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSAtomic.h:59:5: note: expanded from macro '__SAFE_CAST_PTR'
350096-   59 |         ({ _StaIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/cpuid.c:35:
350097-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/cpu_data_internal.h:40:
350098-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/processor.h:82:
350099:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:3929:38: error: variable 'cons_ops' is used but not defined in this translation unit, and cannot be defined in any other translation unit because its type does not have linkage
350100-tic_assert 3929 |                                 ext(sizeof(In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/sched.h:77:
350101-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/bits.h:277:2: er*(warning: identifier '__kfree_heap' is reserved because it starts with '__' [-Wreserved-identifier]
350102-  277 |         kfreen str_data(mavar))p, BI == sTMAP_izeofSIZE(nbiuct nts));io_wd
350103-      |         ^
350104-_co(*(tynsole_ops pe)NUcons_LL), "si/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:522:2ze mismatch"); (: note: expanded from macro 'kfree_data'
350105-(tyoppe  522 | )(var)); })
350106-      |            ^
350107-        kheas[];
350108-      |                                                                  ^
350109-p_free(KH/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:3936:6: note: used here
--
588103-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/_types.h:67:25: 2518:4: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
588104- 2518 |                         NETAGEwarning: identifier '__darwin_ino_t' is reserved because it starts with '__' [-Wreserved-identifier]
588105-NTLOG0(L/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:OG_ERR, "Requested netagent for nexus instance is not a nexus provider");77: note: 
588106-      |                         ^
588107-   67 | ty/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.c:74:6: note: expanded from macro 'NETAGENTLOG0'
588108-   74 | p            os_log_erroexpanded from macro 'NECPDATATRACELOG'
588109:edef _r 1049 |         o_ui(OS_LOG_DEnt3FAULT2_t, "%s    s_log_error: %s\n", __FUNCTION__, msg);                 \
588110-      |             ^
588111-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396:5: note: expanded from macro 'os_log_error'
588112-  396 |     _(necp_data  _St_traaticce_lo_assert(__builtin_cons_datant_p(forrwimat), "fon_ino_t;  rmat        /* string must be constant");             \
588113-      |     ^
588114-[???] Used for inodes */
588115-      |                         ^
588116-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/_types.h:69:28: warning: identifier '__darwin_mach_port_name_t' is reserved because it starts with '__' [-Wreserved-identifier]
588117-   69 | typedef __darwin_natural_t __darwin_mach_port_name_t; /* Used by mach */
588118-      |                            ^
588119-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/_types.h:70:35: warning: identifier '__darwin_mach_port_t' is reserved because it starts with '__' [-Wreserved-identifier]
--
598080-66:
598081-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/message.h:813:
598082-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/debug.h:32:
598083-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kcdata.h:247:
598084-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/uuid/uuid.h:note: expanded from macro 'round_page_overflow'
598085-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:77: note: expanded from macro 'NECPDATATRACELOG'
598086:38 1049 |         os_log_error:
598087-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/_types.h  126 |            (n:56:25: warning:      bidentifier '__darwin_blkcnt_t' is reserved because it starts with '__' [-Wreserved-identifier]
598088-ecp   56 | typeool __data_tde_race_fov _log_handle, "%_int64_t       __darwin_br = os: " formats_a "\n", lkcnt__FUNCTION__, __VA_ARG_t;S__); \dd_ov    
598089-      |   erf/* total blocklow(in, (__typeof__(*out))PAGE_MASK, out); \
598090-        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~s */
598091-      |                         ^
598092-
598093-      | /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/_types.h:57:25: warning: identifier '__darwin_blksize_t' is reserved because it starts with '__' [-Wreserved-identifier]                     ^
598094-
598095-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:399:76: note: expanded from macro 'os_log_error'
598096-   57  399 |    | t  _os_log_ypedinternal(&__dsoef __int32_t _ha   ndl   e, __dlogarw, OS_LOG_TYPE_ERin_RORblk, _sizos_e_tlog;  _fm   t, /* ##_pre_VA_ARferred GS__);blo   ck      \siz
--
598145-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/mbuf.h:93:
598146-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/lock.h::/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:104925: :50:warning: identifier '__darwin_ino_t' is reserved because it starts with '__' [-Wreserved-identifier]
598147-77:
598148- note: expanded from macro 'NECPDATATRACELOG'In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/locks.h:
598149-   67 | typedef  1049 | __uint3240        _:
598150-os_In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/lock_group.h:log31:
598151:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/queue.h_error:215:13: warning: t  identifier '__queue_element_linkage_invalid' is reserved because it starts with '__' [-Wreserved-identifier]
598152-    __da(necp_d  rwin_ino_215 | et;      ata   _tr/* ace_log_hanxtedlern , "voi%s:d _ " _queue_e[???] Usedformat "\n", fo __r iFUNCTIONlem__,en __VA_odeARGSns */__)
598153-      | ; \                        ^
598154-
598155-      |                                                         ^~~~~~
598156-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/_types.h:69:28: warning: identifier '__darwin_mach_port_name_t' is reserved because it starts with '__' [-Wreserved-identifier]
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
patch    120 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-screen-init-null.patch
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
