# Why the build failed

run: 341, commit 97ce4fe1c8cd6a18666077c1f79a828fce301317

## prelink.log

### the tail

```
emit-prelink-nio: Libm literal pool 0xfffffff005b8e054+0x4cc verified and known
Experimental candidate: 56938496 bytes; executable bytes unchanged; runtime unqualified
```

## kernel.log

### the errors

```
60340:TIO 1041 |             os_lN_Bog_OU/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.c:659:3error: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
64518:ormat, ##          __V  oA_As_lRGSog___/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.c:1290:79error: warning: format specifies type 'unsigned int' but the argument has type 'int' [-Wformat]
70107: _log1389 |             (vo/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h:64_error:2:id *)o note: expanded from macro 'os_ptr_load_and_erase'(n
109615:rkq_entryinit_sysent.cs_log_error:184:17: warning: cast from 'int (*)(struct proc *, struct recvmsg_args *, int *)' to 'void (*)(void)' converts to incompatible function type [-Wcast-function-type-strict]
159600: 1049 |         os_log_error:4: warning: identifier '__Request__task_map_corpse_info_t' is reserved because it starts with '__' [-Wreserved-identifier]
161681: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic_private.h:668 os_log_error:2:(ne note: expanded from macro 'os_atomic_cmpxchg'cp_
230501:g_error:12: note:   204 | expanded from macro '__STARTUP1'
```

### around them

```
60334-      |                         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
60335-matOG 7919 |                 _ERR,            "NECP_KE), "Res "forolvermat s tag tringaddress does RNEL_not match");
60336- must      |                                                         ^
60337- be consCONDItant");      /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1041:6     : note: expanded from macro 'NECPLOG0'
60338-  \
60339-      |     ^
60340:TIO 1041 |             os_lN_Bog_OU/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.c:659:3error: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
60341-(necp_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.c:76:6log_h: note: expanded from macro 'NETAGENTLOG0'
60342-andle,   76 |           "%s: %sND_IN\n", TERFA__FUNCE", CTION__,   os msg)_log(OS_LOG_Dcond_EFAULboundT, "%_interface_indexs: %s\n", __F;    UNCTI     ON__,      msg)   \
60343-;          |             ^
60344-              , bound_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396:5interfac     e_ind\
60345-      |             ^ex);
60346-
60347-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:292:5:: note: expanded from macro 'os_log_error'
60348-   396 |           | note: expanded from macro 'os_log'_S                            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
60349-
60350-  292 |     tatic_assert(__b/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c:674:73uilti: note: expanded from macro 'NECP_DATA_TRACE_LOG_CONDITION'
--
64512-|                                                         ~~~~~~                     ^~~~~~~~~~~
64513-|   398 |     /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:398:41: note: expanded from macro 'os_log_error'
64514-_os_l  398 | og                ^
64515-_verify_fo   rmat_str/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h: _o1041:6s_log_verify_for(format, : note: ##__VA_ARGS__);                                    mat  expanded from macro 'NECPLOG0'
64516-     1041 |  \_st
64517-      | r(f                              ~~~~~~    ^~~~~~~~~~~
64518:ormat, ##          __V  oA_As_lRGSog___/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.c:1290:79error: warning: format specifies type 'unsigned int' but the argument has type 'int' [-Wformat]
64519-(ne); 1290 |                    N    cp_log_haETAGENTLOG(ndle, "%s: %s          \n",      __FUN     CTION             LO__, mG_ERRsg); , "Up     date      message si      \
64520-      |             ^
64521-   \
64522-      |                               ~~~~~~    ^~~~~~~~~~~
64523-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396ze (%zu > %u:5:) t note: expanded from macro 'os_log_error'oo 
64524-  large"/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c:7945396 | , d   ata _Stati_size, NETA:3:GEc_aNT_MAX_ warning: ssert(__buDATiltinformat specifies type 'unsigned int' but the argument has type 'int' [-Wformat]
64525-_coA_Sns 7945 | tant_p(format), "format string                 NECP_Dmust ATA_TRACE_LOGIZE);_COND
64526-      |                 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~
64527-ITIbe c/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.h:130:49: note: expanded from macro 'NETAGENT_MAX_DATA_SIZE'onsta
64528-ON(debug, "SOCKET"nt");, ker     nel_p     olicy   \
--
70101-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h1, i :1389:14: note: expanded from macro 'kheap_free'
70102-1389 |          nput2, input2, input3, input3); \
70103-      |                 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~
70104-   (void *)o/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:77: note: expanded from macro 'NECPDATATRACELOG'
70105- 1049 |         oss_ptr_load_and_erase(elem), __kfree_size);                \
70106-      |                     ^
70107: _log1389 |             (vo/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h:64_error:2:id *)o note: expanded from macro 'os_ptr_load_and_erase'(n
70108-   64ecp_s_ptr_load_and_erase(elem), __kfree_size);                \
70109-      |                     ^
70110- |         _Static_assert(os_is_pd/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h:64:2: note: expanded from macro 'os_ptr_load_and_erase'
70111-   64 |         _Static_atssert(os_iata_rs_ptr_like(elem), trace_l_like(elem),                      \
70112-      |         ^
70113-                    o/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp_client.c:8331:6: warning: identifier '__eptr' is reserved because it starts with '__' [-Wreserved-identifier]
70114- \
70115-      |         ^
70116-g/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:522:2: note: expanded from macro 'kfree_data'
70117-  _ha522 |         ndlkhee, ap_"%sfre: "e( forKHEAP_DATA_BUFFER/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.c:2308:S, el4: warning: identifier '__eptr' is reserved because it starts with '__' [-Wreserved-identifier]
--
109609-CA 8870 |                                                         NECPLOG(LOG_DEBUG,LL "Socket Policy: (Application %d Real App_RETlication %d BoundInterfac_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/pthread/pthread_workqueue.c:938:2: warning: INT_T, e %dformat specifies type 'unsigned int' but the argument has type 'int' [-Wformat]
109610- Proto %d) %s Netagent %d",
109611-      |                                                         ^
109612-  938 |         TAILQ_REMOVE(&w/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1033:6: note: expanded from macro 'NECPLOG'
109613-q AC(ptrace_args), 16},          /* 261033 |            ->wq_thrunlist, uth, uu_wo o = ptrace */
109614-      |           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
109615:rkq_entryinit_sysent.cs_log_error:184:17: warning: cast from 'int (*)(struct proc *, struct recvmsg_args *, int *)' to 'void (*)(void)' converts to incompatible function type [-Wcast-function-type-strict]
109616-(necp_l  184 | )og_ha;
109617-              { (sy_call_t *)(void (*)(void|         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
109618-))recvmsndle/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/queue.h:775:2: note: g, mu, "%s: " format "\n", expanded from macro 'TAILQ_REMOVE'
109619-  775n__FUNCTIOge_www,  |         T_SYAILSCAQ_CLL_RHECK_NEXT(N_ET_INT_T, _, elAC(rm, field);__ecvmsg_args), 12}, VA        /* 27 = recv_ARG                          S_msg */
109620-      |                        ^~~~~~~~~~~~~~~~~~~~~~~
109621-   init_sysent.c_:      \
109622-      |         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~
109623-);/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/queue.h:644:26: note: expanded from macro 'TAILQ_CHECK_NEXT'
109624- 184  643 |           :4:            panic("Bad tailq elm %p nwarning: cast from 'void (*)(void)' to 'sy_call_t *' (aka 'int (*)(struct proc *, void *, int *)') converts to incompatible function type [-Wcast-function-type-strict]
109625-e  184 |         {xt->p (s\rev != elm
--
159594- <so/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1502:4: warning: cket policidentifier '__Request__task_generate_corpse_t' is reserved because it starts with '__' [-Wreserved-identifier]
159595- 1502 |         } __Ry id %d sockequest__task_et skigeneratep i_corpse_t d %d>", \
159596-__attribute__((unused));
159597-      |           ^
159598-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1516      |     ^
159599-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:2: note: expanded from macro 'NECPDATATRACELOG'
159600: 1049 |         os_log_error:4: warning: identifier '__Request__task_map_corpse_info_t' is reserved because it starts with '__' [-Wreserved-identifier]
159601-(necp_data 1516 | _trace_log_ha        } __Requndle, "%s: " festorm__taskat _ma"\n", __p_corpse_info_FUNCTION__, __VA_ARGt _S___at); tri\
159602-      but|         ^
159603-e__/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396:5:((u note: expanded from macro 'os_log_error'nus
159604-  396 |     _Sted)atic_assert(__built);
159605-      |           ^
159606-in_constant_p(format), "format /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1532:string4:  muwarning: identifier '__Request__task_register_dyld_image_infos_t' is reserved because it starts with '__' [-Wreserved-identifier]
159607-st b 1532 | e c        } onsta__Request__task_rent");            gis \
159608-ter      |     ^_dy
159609-ld_image_infos_t __attribute__((unused));
159610-      |           ^
--
161675-      | kn->k^
161676-ule_id);
161677-       n_h|                         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
161678-ook32, state, fired_sta/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1033:70: note: expanded from macro 'NECPLOG'
161679-te, relaxed)) { 1033 | 
161680-      |                       ^
161681: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic_private.h:668 os_log_error:2:(ne note: expanded from macro 'os_atomic_cmpxchg'cp_
161682-  668 |         logos__haatondlmice, _ba"%sset: "ype foof(rmap) t "_r \n", __FUNCTI= (ON_e);_,  in__Vt _b; \
161683-      |         ^
161684-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic.h/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:1573:2: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]A_ARG
161685- 1573 |         zf:80:65:ree(k note: expanded from macro 'os_atomic_basetypeof'
161686-t_vS__);iew, ptr   80 | #d);
161687-      |         ^
161688- \
161689-      | /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:873:14            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~
161690-efi: note: expanded from macro 'zfree'
161691-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:399:76: note: expanded from macro 'os_log_error'
--
230495- note: expanded from macro '__STARTUP_ARG'
230496-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/kern_memorystatus_internal.h:257:45: note: expanded from macro 'memorystatus_log_error'
230497-  736 |   257 | #de        __STARTUP1(nfiame, linne meme, subsystem, ra/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/kern_sysctl.cnk, func, ar:3686:8g, ar: warning: og)
230498-      |         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
230499-identifier '__startup_LOCKS_entry_lck_grp_startup_init_3686' is reserved because it starts with '__' [-Wreserved-identifier]
230500-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/lock_group.h:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/startup.h:729rystatus_lo204:2: note: expanded from macro 'LCK_GRP_DECLARE'
230501:g_error:12: note:   204 | expanded from macro '__STARTUP1'
230502-  729 |             ra(form        LCKnk, at, ...) _memo_rystatus_log_with_typ__Se(OS_LOG_TYPE_ERROR,TARTUGRP_DECLAREP__ATTR(va fFUNC_CAST(ormfunc, a), bat, , \
230503-      |                   ^~~~~~~~~~~~~~~~~~~~~~~~~~~~
230504-##r, name, LC/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/startup.h:720:_6: K_note: expanded from macro '__STARTUP_FUNC_CAST'GRP_ATTR_NONE);
230505-      | 
230506-        ^
```

### the tail

```
  871 |                 thread_set_status_flags_t tssf_flags = TSSF_FLAGS_NONE;
      |                                           ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/arm/systemcalls.c:258:2: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
  258 |         prior __assert_only = thread_set_allocation_name(NULL);
      |         ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/arm/systemcalls.c:296:23: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
  296 |         arm_saved_state32_t *ss32 = saved_state32(regs);
      |                              ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/arm/unix_signal.c:940:2: warning: 'switch' missing 'default' label [-Wswitch-default]
  940 |         switch (exception) {
      |         ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/arm/systemcalls.c:500:23: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
  500 |         arm_saved_state64_t *ss64 = saved_state64(regs);
      |                              ^
526 warnings generated.
451 warnings generated.
     LDFILELIST bsd
             CC version.o
clang: warning: no such include directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa' [-Wmissing-include-dirs]
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/version.c:39:12: warning: identifier '__kernelVersionString' is reserved because it starts with '__' [-Wreserved-identifier]
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sun Nov 15 15:29:04 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
      |            ^
1 warning generated.
             LD mach.development.bcm2837.unstripped
ld: warning: -new_linker is obsolete
ld: warning: search path '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot/usr/local/lib/kernel/platform' not found
ld: warning: -segment_order should list all segments, __PRELINK_TEXT is missing
ld: warning: -segment_order should list all segments, __PRELINK_INFO is missing
ld: warning: -segment_order should list all segments, __PLK_TEXT_EXEC is missing
ld: warning: -segment_order should list all segments, __PRELINK_DATA is missing
ld: warning: -segment_order should list all segments, __PLK_DATA_CONST is missing
ld: warning: -segment_order should list all segments, __PLK_LLVM_COV is missing
ld: warning: -segment_order should list all segments, __PLK_LINKEDIT is missing
ld: warning: -segment_order should list all segments, __LINKINFO is missing
ld: warning: -segment_order of __LINKEDIT is ignored, the segment must be ordered last
        LIBTOOL mach.development.bcm2837.a
       DSYMUTIL mach.development.bcm2837.dSYM
warning: ignoring unknown option: --minimize
          STRIP mach.development.bcm2837
built kernel at /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837
```

## archive-14-build-verified-root.log

### the tail

```
PASS: real VerifiedRoot crypto + empty policy table -> libVerifiedRoot.a
      root verification is disabled: no signed policy bundle exists for this board
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
nio-ufs: build/nio-ufs/libNioUfs.a -> build/sheng-ufs/libShengUfs.a (511840 bytes, sha256 f452ae6ce4b262039c2af8e07a982040b1ec220c46d8c800092376a00d3a2618)
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
note: -Wno-unnecessary-virtual-specifier is not known to this clang, not passing it
PASS: 31 NativeAdreno a650 objects archived
PASS: archive verified with 31 objects
```

## archive-08-build-libpthread-kernel.log

### the tail

```
Cloning into '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work'...
this XNU tree calls proc_get_pthread_jit_allowlist what the sources call proc_get_jit_entitled
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
55251: int, /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:656:26error: note: expanded from macro 'kfree_type'
463661:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/zalloc.h:1549l/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.hy_error:216_:2:8: warning: identifier '_dyld_cache_image_text_info' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
610153:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1148s_log_error:4:(OS warning: identifier '__Request__task_swap_exception_ports_t' is reserved because it starts with '__' [-Wreserved-identifier]_LO
619428:  158 |                 printf("buffer_stage_initialize failed to allocate memory. Error 0x%x\n",In file included from identifier '__Reply__host_set_UNDServer_t' is reserved because it starts with '__' [-Wreserved-identifier]
639545:ndle availability of LZ4. Error 0x%x\n", __func__, ret);
683930:_  143 | mas        long       k &    NECP_KEr   int           RNE f("zlib_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
696339:allocate memory. Error 0x%x\n", __func__, r/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c:8324:3et);
766505:s_log_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IONVRAM.cpp:84:56error: note: expanded from macro 'DEBUG_ALWAYS'
1130210: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid sched/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_param.h:415:6: warning: identifier '__ovr' is reserved because it starts with '__' [-Wreserved-identifier]
1130296: 1413 |                     "| error: latency %d too big (> 1 sec)",
1130307: 1420 |                     "| error: jitter %dms too big (latency %dport_requestIn file included from ms_t/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/libkern/c++/OSUnserializeXML.cpp)",
1130327: 1420 |                     "| error: jitter %dms too big (laten/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:966:2: note: expanded from macro 'KALLOC_ARRAY_TYPE_DECL'
1130401:, "| error: r   40 | eortempladerte <clingass _T %d> usin > g remo%d"ve_,
1130430:e 1463 |                     "| error: output interval %dms too big",
1483235: 4398 |                                 FDLOG(LOG_DEBUG, &nil_pcb, "ctl_enqueuembuf returned an error: %d", error);
1551237:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
1551421:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
1562216:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
1562275:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
1659610:  275 |         SASEL_LOG("Returned with error: %d", err);
1704411:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/cdefs.h:1090log_error:12:
1729629:  727 | error: note: expanded from macro '__ZONE_DECLARE_TYPE'
2038993:  602 |         int __pagein_error:1: warning: identifier '_pthread_priority_has_qos' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
2291780:alloc_b 1521 | uffer error:         KA%d,LLO kcC_TdatYPEa e_SIrroZE_r: CHE%d,CK( length: %ld)\n"siz,
2454169:ount or error:1614:1: warning: identifier '__packet_set_tx_completion_data' is reserved because it starts with '__' [-Wreserved-identifier]
2772496:Undefined symbols for architecture arm64:
2772505:ld: symbol(s) not found for architecture arm64
2772506:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
2772507:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
2772508:make[2]: *** [build_all] Error 2
2772509:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
2772510:make: *** [build] Error 2
```

### around them

```
55245-      |                                    ^
55246- 1527 |         } = &(elem);    /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1129:2: warning: identifier '__dtrace_a1' is reserved because it starts with '__' [-Wreserved-identifier]
55247-__Reply__mach_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:265:14port_: note: expanded from macro 'MAC_CHECK'
55248-       265 |                               DTRAC\
55249-      |                               ^E_MAC
55250-setF3(mac__call__ ## check, vo/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/vfs/vfs_bio.c:453:2id *, mpc,: warning: identifier '__elem' is reserved because it starts with '__' [-Wreserved-identifier]
55251: int, /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:656:26error: note: expanded from macro 'kfree_type'
55252-, i_s  656nt, M | #defAC_ITine kfree_ERATEtype(_CHEC...)  KALLK); \OC_DI
55253-      |                     ^
55254-SPAeqno_TCH(kt __attribfree_ute__type,((unu ##__sed))VA_AR;
55255-      |           ^
55256-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:165GS__)
55257-      |                          ^
55258-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:1541:4: :2/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:1432: note: expanded from macro 'DTRACE_MACF3'
55259-  warning: identifier '__Reply__mach_port_get_attributes_t' is reserved because it starts with '__' [-Wreserved-identifier]
55260-165 | :2: note: expanded from macro 'KALLOC_DISPATCH'        DT
55261- 1432 |         KRACE_PRALL 1541 |         } _OC_DISP_Reply_ATCH1(b_mach_pase, KAort_getLLOC_CO_attribUNT_ARGOBE3(__sdutet_, nams_t __ae, arg1ttribut, arg2,e__S(_((unuse_VA_ARGd));
--
463655-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/clock.h:13:
463656-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mig_errors.hONE:113:1: warning: identifier '__NDR_convert__mig_reply_error_t' is reserved because it starts with '__' [-Wreserved-identifier]
463657-che_  113 | __N_DR_convertheader {
463658-      |        ^
463659-ID_PROC_TASK__mi, vog_repid *);
463660-      | ^
463661:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/zalloc.h:1549l/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.hy_error:216_:2:8: warning: identifier '_dyld_cache_image_text_info' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
463662-  216 | strt(: note: expanded from macro 'ZONE_DECLARE_ID'uct __unused 
463663- 1549 |         __ZON_migEdyld_cache_i_reply_error__DEmt *x)
463664-      | ^CLARE_TYPE(id, type_t)
463665-      |         ^
463666-a/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/zalloc.h:927:42ge_text_
463667-: note: expanded from macro '__ZONE_DECLARE_TYPE'
463668-  927 | #deinffine __ZONE_DECo LARE_TYPE({
463669-      |        ^var, type_t) __ZONE_DECLA
463670-RE_In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOPolledInterface.cpp:32TYPE2(var, type_:
463671-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:49:
--
610147-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.h:720:6: note: expanded from macro '__STARTUP_FUNC_CAST'
610148-ibut  720 |           e__((unus/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if_ipsec.c:928:6  (ty: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]peof(func(a))ed));(*)(c
610149-      |           ^
610150-ons
610151-t void   928 | *))                        fun                oc
610152-      |             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
610153:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1148s_log_error:4:(OS warning: identifier '__Request__task_swap_exception_ports_t' is reserved because it starts with '__' [-Wreserved-identifier]_LO
610154- 1148 |         } __RequesG_Dt__EFAULT, "ipsec_kpipe_sync_rx %s - mbuf_copyback(%zu) error %d\n", pcb->ipsec_ifp->if_xname, length, error);
610155-      |                                         ^
610156-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396:5: note: expanded from macro 'os_log_error'
610157-  396 |     _Static_assert(__builtin_constantIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kdp/user_core.c:30:
610158-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kdp/kdp_core.h:_task_s39p(f:
610159-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/thread.horm:122:
610160-at)In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/task.h:127:
610161-In file included from , "/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_port.h:91:
610162-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_space.h:92:
610163-for/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_entry.h:162mat:19: st warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
--
766499-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:1430:40: note: expanded from macro 'KALLOC_DISPATCH1'
766500-      |                                                                                                                                   ^~
766501-
766502- 1430 | #OR Dd/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.hEe:BUG_A1049:50: note: expanded from macro 'NECPDATATRACELOG'fine 
766503-LWAYS
766504- 1049 |         o      |                     ^
766505:s_log_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IONVRAM.cpp:84:56error: note: expanded from macro 'DEBUG_ALWAYS'
766506-(   84 |         IOLog(necp_data_traKALLOce_loC_DISPATCH1(b"%s:%s:%u -ase " fg_hmt,and __le, "%s:,FILE_NAME N,__, .. __.) FUN__CCTION__, ONC" fAT(ormbasat e, N)(__ __VA_ARGS_"\n_)
766507-      |                                        ^
766508-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/cdefs.h:113:", __F26:LINE note: expanded from macro '__CONCAT'
766509-__, ##arg  UNCTs); \
766510-      |                      ~~                                       ^~~~~~~~
766511-ION113 | #define__, __CON<scratch space>:41CAT(x, y) __VA_   x ## y
766512-      :1: note: expanded from here
766513-ARGS__); \
766514-      |                                                         ^~~~~~
766515-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:397:83: |                          ^
--
1130204-  134 |         return round_page_overflow(in, out);
1130205-      |                ^
1130206-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_param.h:126:15: note: expanded from macro 'round_page_overflow'
1130207-  126 |                 bool __ovr = os_add_overflow(in, (__typeof__(*out))PAGE_MASK, out); \
1130208-      |                      ^
1130209-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1387:7: warning: format specifies type 'int' but the argument has underlying type 'unsigned int' [-Wformat]
1130210: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid sched/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_param.h:415:6: warning: identifier '__ovr' is reserved because it starts with '__' [-Wreserved-identifier]
1130211-            u  415 |         ler if (moderounl %dd_pa",
1130212-      |                                                                      ~~
1130213-      |                                                                      %u
1130214-ge_over(typeof 1387 |         (func(a))(*)(flowconst(x,  void&x)) *))f {
1130215-      unc
1130216-      |             ^
1130217-|             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1130218-            p->ifnetem_m/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_param.h:126:15ode: note: expanded from macro 'round_page_overflow'
1130219-l);
1130220-      |                     ^~~~~~~~~~~~~~~~
--
1130290-      |                      ^    
1130291-PE_          log(_level, "NETEM: %-30s "_fmt "\n", \
1130292-      |                                                    ~~~~
1130293-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
1130294-      |                                             ^~~~~~~~~~~
1130295-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1414:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
1130296: 1413 |                     "| error: latency %d too big (> 1 sec)",
1130297-      |                                       ~~
1130298-      |                                       %u
1130299- 1414 |                     p->ifnetem_latency_ms);
1130300-      |                     ^~~~~~~~~~~~~~~~~~~~~
1130301-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
1130302-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
1130303-      |                                                    ~~~~
1130304-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
1130305-      |                                             ^~~~~~~~~~~
1130306-DECL(ipc_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1421:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
1130307: 1420 |                     "| error: jitter %dms too big (latency %dport_requestIn file included from ms_t/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/libkern/c++/OSUnserializeXML.cpp)",
1130308-:1:
1130309-In file included from OSUnserializeXML.y:64:
1130310-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/libkern/libkern/c++/OSMetaClass.h:37:
1130311-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:      |                                      ~~
1130312-      |                                      %u
1130313-72:
1130314-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kern_types.h:251:8able, st 1421 |         ruct ipc: warning: identifier '_wait_queue_link' is reserved because it starts with '_' at global scope [-Wreserved-identifier]_port
1130315-            p-_requ>ifnetem_jitt  251 | ster_ms, pruct->if _waneteit_qm_laueuetenc_liny_ms);
1130316-      |                     ^~~~~~~~~~~~~~~~~~~~
1130317-est);
--
1130321-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
```

### the tail

```
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
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sun Nov 15 15:27:28 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
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
ld: symbol(s) not found for architecture arm64
clang++: error: linker command failed with exit code 1 (use -v to see invocation)
make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
make[2]: *** [build_all] Error 2
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
