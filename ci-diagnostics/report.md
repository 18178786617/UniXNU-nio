# Why the build failed

run: 261, commit 477c8e61d961598ac5839fb00442eb16eebc9b24

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
47534: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
64533:c_buffer /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1451:4error: : warning: identifier '__Request__task_purgable_info_t' is reserved because it starts with '__' [-Wreserved-identifier]
181061:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/arm/_types.h1728i::n874t, error: warning: identifier '__Request__task_test_sync_upcall_t' is reserved because it starts with '__' [-Wreserved-identifier]
645718:ocate memory   90 | typedef . Error 0x%__WINT_TYPEx\n", ret);__         
715002:allocat/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c:  836e 663: |         memory59:  .  note:   Error 0x%           __FUNCTION__,  expanded from macro 'NECP_DATA_TRACE_LOG_CONDITION3'x\n", r  
724821:  143 |                 printf("%s failed to allocate memory. Error 0x%x\n", __func__, ret);
896905:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/sched.hs                                    uid error:77:
899031:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_port.h 1033 |             os_log_error:305:41: note: expanded from macro 'ip_mq_lock_held'
934291:  /* pse /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h  ts with at :946 os_log_error:2: note: expanded from macro 'IOOverrideTypedOperators'
946178:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/sched_prim.hein_error:76/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/kernel_types.h:;
1014719:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h:66:24:ory_error:
1200485:  314 1386 |                 NET |         _Static_asseEM_LOG(LOG_rt(os_atomic_lERR, "| error:oad_is_plain(p invalid sc), "Load is wide"); \
1200507:(LOG_ERR, "|  316 |         __auto_typ error: corrupe _r = os_atomtion_p %d >ic_std(atomic_loa %d",
1200559:                    "| error: j/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/locks_internal.h:71:39: note: itter %dms tooexpanded from macro 'hw_spin_wait_until_n'
1200596:                                                                ^ 1438 |                     "| error: l
1200616:load_var = os_a 1456 |                 NETEM_tomic_load_excLOG(LOG_ERR, "lusive(ptr, re| error: reordlaxed);          ering %d > %d"            \
1562674: 2626 |                 FDLOG(LOG_ERR, fd_cb, "failed to get the close error: %d", error);
1565035: 4398 |                                 FDLOG(LOG_DEBUG, &nil_pcb, "ctl_enqueuembuf returned an error: %d", error);
1628891:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
1645882:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
1645913:al error: "
2147629::11: error: unknown type name 'u32'
2147643:error: unknown type name 'u32'
2147665:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/console/serial_console.c:in  501626:te |         __khe11: error: unknown type name 'u32'
2147688:  :626:34: error: unknown type name 'u32'
2147702:z   79 | e mismatch"); ((type)(var))/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/console/serial_console.c#define os_cast:628:2: error: ; _tuse of undeclared identifier 'u32'
2147724::3:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic_private_impl.h:224:6 error: use of undeclared identifier 'u32'
2147743:note: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/console/serial_console.c 1386 |         __auto_type:634:7: error: expanded from macro 'os_cast_to_nonatomic_pointer'
2147756:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/console/serial_console.c:635:4: error: use of undeclared identifier 'prev'
2147766:tomic_poin/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/console/serial_console.c:641:12: error: use of undeclared identifier 'prev'
2147784:  522 |         khatomic_xchgeap_free(KHEAP(p, v, m)  _D/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/console/serial_console.c:AT   _os_atA_BUFFE643:2: error: use of undeclared identifier 'off'omic_c1RS
2147798:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h:666: error: use of undeclared identifier 'off'
2147818:        637 | #defin/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/console/serial_console.c| :645:3: error: use of undeclared identifier 'off'
2147831:auto_type/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/console/serial_console.c:647:7: error: use of undeclared identifier 'off'
2147846:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/console/serial_console.c:648:11: error: use of undeclared identifier 'off'
2147856:  342 |         _Static_assert(os_atomic_store_is_plain(p), "Store is /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/console/serial_console.c:649:11: error: use of undeclared identifier 'off'
2148166: 1389 |             (void *)os_ptr_load_and_erase(elem), __kfree_size);    make[7]: *** [serial_console.o] Error 1
2148176:make[6]: *** [build_all] Error 2
2148181:   66 |         __auto_type *__single __eptmake[5]: *** [do_all] Error 2
2148188:make[4]: *** [build_all] Error 2
```

### around them

```
47528- 1354 |                         IOLog("Failed to open corefile of size %llu MB (returned error 0x%x)\n",
47529-      |                                                                                          ~~
47530-      |                                                                                          %x
47531- 1355 |                             (corefile_fallback_size_bytes / (1024ULL * 1024ULL)), err);
47532-      |                                                                                   ^~~
47533-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1364:76: warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
47534: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
47535-      |                                                                                   ~~     ^~~
47536-      |                                                                                   %x
47537-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1447:2: warning: 'switch' missing 'default' label [-Wswitch-default]
47538- 1447 |         switch (op) {
47539-      |         ^
47540-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1530:20: warning: missing field 'total' initializer [-Wmissing-designated-field-initializers]
47541- 1530 |         c_string = (char*)kalloc_data(string_length, (zalloc_flags_t)(Z_ZERO | Z_WAITOK | Z_NOFAIL));
47542-      |                           ^
47543-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:512:2: note: expanded from macro 'kalloc_data'
47544-  512 |         kheap_alloc(KHEAP_DATA_BUFFERS, size, flags)
--
64527-e_des/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1441:c_len);
64528-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~4: warning: identifier '__Request__task_resume2_t' is reserved because it starts with '__' [-Wreserved-identifier]
64529- 1441 |         
64530-} __Request__task_resu/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:me2_t _43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
64531-_attribute_ 1418 |                                  _((unuse   "(os_reason_allod));
64532-      |           ^
64533:c_buffer /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1451:4error: : warning: identifier '__Request__task_purgable_info_t' is reserved because it starts with '__' [-Wreserved-identifier]
64534-%d, kc 1451 |         } __data errRequest_or: %d, _task_purgable_info_t __attriblengtute__((uh: %lnusedd)\n",
64535-      ));
64536-      |           ^
64537-|                                                                                                   ~~~
64538-      |                                                                                                   %zu
64539-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1463:4: warning: identifier '__Request__task_get_mach_voucher_t' is reserved because it starts with '__' [-Wreserved-identifier]
64540- 1419 |                                      1463 |         } __path,Reque reason_error, kst__task_gcdata_erroet_mach_voucr, fatal_failure_her_t __atdesc_lentri);
64541-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
64542-bute__((unused));
64543-      /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
--
181055-   82 | typed :e1714 f | warning:          identifier '__dtrace_a1' is reserved because it starts with '__' [-Wreserved-identifier]_}
181056-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:265:14: note: expanded from macro 'MAC_CHECK'
181057-_  265 |                 __RequestWCHAR_TYPE_ __tas_    DTRAk C_ Eg _e Mt A_excepti Co Fn 3_ (p mo_ar_ctd_sa__rciwanilfnlo___w_tc  h#_a#_r a_cttributeth_;e_ c( k( ,u  n vu os ie/dd* ) *)w,;c 
181058-hm      ap| rc          ^_,
181059-t */
181060-      |                                 ^
181061:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/arm/_types.h1728i::n874t, error: warning: identifier '__Request__task_test_sync_upcall_t' is reserved because it starts with '__' [-Wreserved-identifier]
181062-, int,  :M172833A | :C         _}warning: I identifier '__darwin_rune_t' is reserved because it starts with '__' [-Wreserved-identifier]T_
181063-E   87 | typedRATE_CHECK);_e Rf\e 
181064-q_      u_| ed                    ^sa
181065-t__tas/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:165:2: note: k_test_sexpanded from macro 'DTRACE_MACF3'
181066-ync  165 |         DTRA_upcall_CE_PROBEt __attr3(__sdt_ibute__((r,uw ninunas_mewedc,)h )aa;rr
181067-_g      t1|  ,          ^  
181068-      __darwin_rune_t; arg2, a /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.hr :g 17403 :) 4; :
181069-        /warning: | *identifier '__Request__task_set_corpse_forking_behavior_t' is reserved because it starts with '__' [-Wreserved-identifier]        ^ 
181070-
181071-rune_t/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h  :1740*140 | /:        
--
896899-In file included from  1835 |  /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_space.h:90:
896900-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/task.h:122:
896901-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/cpu_data.h:42t_copy_ag   classN:
896902-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/machine/cpu_data.h:34:
896903-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/cpu_data.h:ent copyiame ## _Methodn agent_u41:
896904-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/processor.h:82:
896905:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/sched.hs                                    uid error:77:
896906-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/bits.h:277:2: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
896907-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:522:2: note: expanded from macro 'kfree_data'
896908-  522 |         kh   \eap_
896909-      |     ^free
896910-<scratch space>:133: (%d1: note: expanded from here
896911-)",   133 | IOServ(KHEAP_DATA_BUFFERS, elem, size);
896912-      |         ^
896913-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:error);1389:14: note: expanded from macro 'kheap_free'
896914- 1389 |            ice_Metho
896915-      |                 ^
--
899025- __typeof__(((type_t *)NULL)->field) *__ptr = (ptr);               \
899026-      |                                                    ^
899027-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1033:6: note: expanded from macro 'NECPLOG'
899028-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/mach_msg.c:83:
899029-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/ipc_kobject.h:77:
899030-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_port.h:543:2: warning: identifier '__result' is reserved because it starts with '__' [-Wreserved-identifier]
899031:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_port.h 1033 |             os_log_error:305:41: note: expanded from macro 'ip_mq_lock_held'
899032-(necp_log_handle, "%s: " fo  305 | #define ip_mq_lock_held(port)           io_lock_held(ip_to_object(port))
899033-      |                                         ^
899034-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_object.h:205:48: note: expanded from macro 'io_lock_held'
899035-  205 | #define io_lock_held(io)     assert(waitq_held(io_waitq(io)))
899036-      |                                                ^
899037-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_object.h:198:4: note: expanded from macro 'io_waitq'
899038-  rmat "\n", __FUNCTION__, __VA_198 |         (&__container_of(io, struct ipc_object_waitq, iowq_object)->iowq_waitq)
899039-      |           ^
899040-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/cdefs.h:1090:12: note: expanded from macro '__container_of'
899041-ARGS__); \
--
934285-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:980:2: warning: nested designators are a C99 extension [-Wc99-designator]
934286-p  980 1772 |                 NETAGENTLOG(LOG_ERR, "Cl |         IseienOOt_mt group assignment failed: %d", ap_rverriesponse_errt deTypedO     psorpeet);
934287-      |                 ^
934288-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.c:64:6_idle_mra: aptonote: expanded from macro 'NETAGENTLOG'; rs
934289-        64(T);
934290-      |    |                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~
934291:  /* pse /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h  ts with at :946 os_log_error:2: note: expanded from macro 'IOOverrideTypedOperators'
934292-(least one IDLE CPU */
934293-      |         ^
934294-OS_LOG_DEFAULT, "%s: " format "\n", __FUNCTION__, __VA_ARGS__); \
934295-      |             ^
934296-  946 |         __IOOverrideTypedOperato/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/processor.h:302r/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396:s(type)
934297-      |         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
934298-:2:5/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h: note: expanded from macro 'os_log_error'
934299- warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
934300-  396:869  302 |  :10 |            _Sta: note: expanded from macro '__IOOverrideTypedOperators'
934301-_Atom  869 |            tiic  c_ p  asse Iset_OFrtmare(_p_eT_bt ypui  e(ltin_constan   pset_imt_p(format)em, typdle_primar, e)y_map; "f;  /or      * psets with at least   maon  t e IDLE   stpr  riimary C  ngPU   m *  us/
--
946172-et;
946173-      |        ^
946174-  /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/kernel_types.h:96:8: warning: identifier '__sockopt' is reserved because it starts with '__' [-Wreserved-identifier]
946175-   96 | struct __soc602 |         int __pakopt;
946176-      |        ^
946177-gIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/clock.c:68:
946178:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/sched_prim.hein_error:76/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/kernel_types.h:;
946179-      |             ^
946180-:
946181-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/thread.h:122:
946182-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/task.h:127:
946183-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_port.h:86:
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
1542 warnings generated.
425 warnings generated.
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
