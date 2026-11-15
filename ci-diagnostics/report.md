# Why the build failed

run: 344, commit 40a203c47182a89dfc6334909d4ad0ca8409fc0a

## fingerprint.log

### the tail

```
kernel.macho (published): MISSING 
native (prelink input): 0 bytes, nio: STALL rounds==no, nio: HB =no, the matching path stalled=no, nio: U1=no
osfmk/DEVELOPMENT/startup.o: 113592 bytes, nio: STALL rounds==no, nio: HB =no, the matching path stalled=no, nio: U1=no
iokit/DEVELOPMENT/IOService.o: MISSING out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/iokit/DEVELOPMENT/IOService.o
startup.c source: STALL=no HB=yes
```

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
51676:PollersSetup for corefile failed with error: 0x%x\n", err);
55362:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/host_info.h 1413 |         _type __elem = *__eptr;                                               "(kcdata_memcpy error: %d, length: %ld)\n",
55373: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
324685:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:1956:2: error: use of undeclared identifier 'nio_u_mark'
324840:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSAtomic.h:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:1958:3: error: use of undeclared identifier 'nio_u_mark'
324878:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:1960:3: error: use of undeclared identifier 'nio_u_mark'
327926:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/skywalk/os_channel_private.h:510:make[7]: *** [IOService.cpo] Error 1
327930:make[6]: *** [build_all] Error 2
327931:make[5]: *** [do_all] Error 2
327938:make[4]: *** [build_all] Error 2
327950:   81 | #define os_cast_to_nonatomic_pointer(p)make[3]:   (os*** [build_all_recurse_into_conf] Error 2
328008:  110 | __nx_pkmake[2]: *** [build_all_recurse_into_iokit] Error 2
354991:        intIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/skywalk/os_stats_private.h:965:16/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/vm/vm_kern.h:74 __pagein_error:
538970:<scratch space>:166in/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSByteOrder.h:145:1: warning: identifier '_OSWriteInt32' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]t __pagein_error:
543855:s  _cast268 |                 printf("(%s) Failed to haOS_LOndl_to_atomic_pointer(pe ava)    ilabi (__typeof__(*(lity of LZ4. Error 0p)) vx%x\nolatile _Atomic", __ *)(uintptr_t)(p)
569761:  102 | T,_                printf("progre   _os_log"))) static co  nst char _os_loss_notify_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
576171:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_port.herface_i\n"nde, _x error:508:2: (%d) warning: identifier '__result' is reserved because it starts with '__' [-Wreserved-identifier]
618891:_log/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.c:64_error:6/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/mpsc_queue.h:157:2(necp: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
628192: 1049 |         os_log_error:
639449: In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_init.c:961049 |         os_log_error:
642339: 1049 |         os_log_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/libkern/copyio.h:49:1error: warning: identifier '__copyin_chk' is reserved because it starts with '__' [-Wreserved-identifier]
644146: 1033/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/pthread/priority_private.h:211 |             os_log_error:1: warning: (necp_In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_mqueue.c:79:
857089: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
857100: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
857111: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
857122: 1413 |                     "| error: latency %d too big (> 1 sec)",
857133: 1420 |                     "| error: jitter %dms too big (latency %dms)",
857144: 1420 |                     "| error: jitter %dms too big (latency %dms)",
857155: 1438 |                     "| error: loss recovery %dms too big",
857166: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
857177: 1463 |                     "| error: output interval %dms too big",
1088090: 2626 |                 FDLOG(LOG_ERR, fd_cb, "failed to get the close error: %d", error);
1093214:dan error: %/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/lock_group.h:200:d",2: note: e expanded from macro 'LCK_GRP_DECLARE_ATTR'
1141980:          202 |                 ipseclog((LOG_DEBUG, "ah4_  output: internal error: "  
1142349:internal error: "
1167834:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
1167846:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
1239798: error: %d", er/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic_private.h:r);
1951417: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
1951423: 3383 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
```

### around them

```
51670-tes/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:128 / :29: note: expanded from macro 'DTRACE_PROBE2'(10
51671-  128 |            24U   LL   r* 1egi024steULLr u)),int erptrr);_t 
51672-      | __d                                                                                  ^~~
51673-trace_a1 asm("x1") = (uintptr_t) arg1/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1364:76: warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
51674-;    1364 |                 I   OLo   g("   IOP      oll  \edF
51675-      | ile                                   ^
51676:PollersSetup for corefile failed with error: 0x%x\n", err);
51677-      |                                                                                   ~~     ^~~
51678-      |                                                                                   %x
51679-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/vfs/vfs_bio.c:81:
51680-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/vnode_internal.h:88:
51681-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/vfs_context.h:9:
51682-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/user.h:142:10: warning: identifier '_select_data' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
51683-  142 |                 struct _select_data {
51684-      |                        ^
51685-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/user.h:159:10: warning: identifier '_kauth' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
51686-  159 |                 struct _kauth {
--
55356-warning: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h:67:14: note: expanded from macro 'os_ptr_load_and_erase'
55357-format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]:40   67 |         _
55358-_:
55359-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/system.h:auto36:
55360-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/thread.h:88:
55361-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_types.h:80:
55362:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/host_info.h 1413 |         _type __elem = *__eptr;                                               "(kcdata_memcpy error: %d, length: %ld)\n",
55363-      |                                                                                ~~~
55364-      |                                                                                %zu
55365-:278:8:    1414 |                                 warning: identifier '_processor_statistics_np' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
55366-             path               \
55367-      |                     ^
55368-  278 | struct _processor_st, matistc_ics_np  {
55369-      |        ^
55370-error, fatal_failure_desc_len);
55371-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
55372-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
55373: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
55374-      |                                                                                                   ~~~
55375-      |                                                                                                   %zu
55376- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
55377-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
55378-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
55379- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
55380-      |                             ^
55381-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
55382- 1426 |                 zfree(ZV_NAMEI, vn_path);
55383-      |                 ^
--
324679-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/proc.h:107:18: warning: identifier '__p_back' is reserved because it starts with '__' [-Wreserved-identifier]
324680-  107 |                         struct  proc *__p_back;
324681-      |                                       ^
324682-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/proc.h:109:18: warning: identifier '__p_starttime' is reserved because it starts with '__' [-Wreserved-identifier]
324683-  109 |                 struct timeval __p_starttime;   /* process start time */
324684-      |                                ^
324685:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:1956:2: error: use of undeclared identifier 'nio_u_mark'
324686- 1956 |         nio_u_mark("\nnio: U1");
324687-      |         ^
324688-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if.c:75:
324689-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/systm.h:113:
324690-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/libkern/libkern.h:81:
324691-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/libkern/copyio.h:49:1: warning: identifier '__copyin_chk' is reserved because it starts with '__' [-Wreserved-identifier]
324692-   49 | __copyin_chk(const user_addr_t uaddr, void *kaddr, size_t len, size_t chk_size)
324693-      | ^
324694-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/caches.c:41:
324695-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/cpu_data_internal.h:46:
--
324834-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSAtomic.h:177:9: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
324835-  177 |         return OSAddAtomicLong(-1L, address);
324836-      |                ^
324837-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSAtomic.h:148:22: note: expanded from macro 'OSAddAtomicLong'
324838-  148 |         (OSAddAtomicLong(a, __SAFE_CAST_PTR(volatile long*,b)))
324839-      |                             ^
324840:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSAtomic.h:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:1958:3: error: use of undeclared identifier 'nio_u_mark'
324841-59:5: note: expanded from macro '__SAFE_CAST_PTR'
324842- 1958 |            59 |         ({ _S        In file included from ta/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if.c:79nio_u_:
324843-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/protosw.h:363:1: mawarning: identifier '__hack' is reserved because it starts with '__' [-Wreserved-identifier]
324844-tic_ass  363 | EVENTHANDLrk(ER_DECLA" U2T");e
324845-      | RE(protoctl_ert(siz                ^
324846-veof(*(var)) == sizeof(*(type)NULL), "size mismatch"); ((type)(ent, pvar)); rotoctl_e})vent_fn);
324847-
324848-            | ^
324849-|            ^
324850-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/eventhandler.h:158:8: note: expanded from macro 'EVENTHANDLER_DECLARE'
--
324872-  122 |         ipc_object_refs_t _Atomic io_references;
324873-      |                           ^
324874-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_object.h:161:2: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
324875-  161 |         os_atomic_store(/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/sysctl.h:965:8: warning: identifier '_pcred' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
324876-  965 | struct _pcred {
324877-      |        ^
324878:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:1960:3: error: use of undeclared identifier 'nio_u_mark'
324879-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/sysctl.h:975:8 1960 |                 ni: warning: identifier '_ucred' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
324880-  975 | stru&o_u_mark("io->i U2co_bits, it _uco_bBredits(io) | bits, rela {
324881-      |        ^
324882-xed);
324883-      | ");
324884-        ^
324885-      |                 ^
324886-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic_private.h:342:2: note: expanded from macro 'os_atomic_store'
324887-  342 |         _Static_assert(os_atomic_store_is_plain(p), "Store is wide"); \
324888-      |         ^
--
354985-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/skywalk/core/skywalk_var.h:94/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/arm_init.c6: warning: identifier '__pagein_error' is reserved because it starts with '__' [-Wreserved-identifier]
354986-  602 | :38:
354987-:
354988-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/skywalk/os_channel_private.h:65In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/thread.h:98:
354989-:
354990-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/skywalk/os_stats_private.h:976:1: warning: identifier '__IP6_STATS_MAX' is reserved because it starts with '__' [-Wreserved-identifier]
354991:        intIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/skywalk/os_stats_private.h:965:16/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/vm/vm_kern.h:74 __pagein_error:
354992-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/locks.h:36:
354993-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/machine/locks.h:34:
354994-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/locks.h:38;
354995-      |             ^:
354996-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/lock_types.h:239:9: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
354997-:   239 | note: expanded from macro 'STATS_REGISTER'
354998-  965
354999-                const _Atomic uint64_t  | en*hwsp_timeout_aum _##natomic;
355000-      |                       ^me
355001- { NAME##_TABLE(EXPAND_TO_ENUMERATION) };   \
--
538964-      _##va| ^r
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
build-xnu-4k-baseline.sh: line 833: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
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
