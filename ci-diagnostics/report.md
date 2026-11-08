# Why the build failed

run: 31, commit 5e560d4b858fc5a57ad8bca192fc4c2430829e44

## storage-headers.log

### the tail

```
PASS: 19 public IOStorageFamily headers prepared at e45fbe30a7879e0b16e26dddb78538f1b00e0bff
```

## kernel-bootstrap.log

### the errors

```
49582:  111 | typedef _Atomic(wchar_t)          /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:127  atom:h error: 0x%x\n", err);
55778:ta error: %d, length:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_host.h:727:4 %ld)\n",: warning: 
576930:  779 |                 /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/pthread/priority_private.h:357errno_t error:1: =  warning: identifier '_pthread_priority_is_overcommit' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
651862:  158 |                 printf("buffer_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
716937:  272 |                 printf("zlib_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
726910:_V  143 |                 printf("%s failed t        } __Reply__task_swap_mach_vouchero allocate memory. Error 0x%x\n_t __attrA_ARGS_ibute_", __func__, ret)_((;
744279:Base: 1049 |         os_log_error:*)(void)) func))
840406:nt or error:10682:23: warning: identifier '__startup_ZALLOC_entry___zone_site_register_10682' is reserved because it starts with '__' [-Wreserved-identifier]
869189:   74 |             os_l/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/processor_set.h/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/priority_queue.h:og_error:439:4: warning: identifier '__Reply__processor_set_policy_enable_t' is reserved because it starts with '__' [-Wreserved-identifier]
873084:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_port.h:log116:1_error: warning: (OSidentifier '__startup_ZALLOC_entry___zone_site_register_116' is reserved because it starts with '__' [-Wreserved-identifier]
881870:   64 |             os      /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/processor.h:242_log_error:7: warning: (OS_Lidentifier '__RequestUnion__processor_subsystem' is reserved because it starts with '__' [-Wreserved-identifier]
1140521:__processor_set_policy_disable_ 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
1140537:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/processor_set.h 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
1140555:  512 |         } __Reply__processor_set_stack_usagNETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
1140588: 1420 |                     "| error: jitter %dms too big (latency %dms)",
1140599: 1420 |                     "| error: jitter %dms too big (latency %dms)",
1140610: 1438 |                     "| error: loss recovery %dms too big",
1140621: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
1140632: 1463 |                     "| error: output interval %dms too big",
1482004:te_t;     /   *  4398 | mbs                        tate                 FD   LOG(LOG_DEBUG, &nil_pcb, "ctl_enqueuembuf returned an error: %d   _t */
1577987:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
1577999:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
1655857:  275 |         SASEL_LOG("Returned with error: %d", err);
2292101: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
2292107: 3383 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
2772466:Undefined symbols for architecture arm64:
2772475:ld: symbol(s) not found for architecture arm64
2772476:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
2772477:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
2772478:make[2]: *** [build_all] Error 2
2772479:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
2772480:make: *** [build] Error 2
```

### around them

```
49576-  /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1364:76: warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
49577-PR110 | tOBEyped 2e1364(f _Atom | __sdt_,ic(ui name, a                IOLog("Irg1, OPollarg2edF);
49578-ile      |         ^
49579-nt_PollersSetup for corefile failedleast32_t)     atomic_char wit32_t;
49580-      |         ^
49581-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdatomic.h:111:9: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
49582:  111 | typedef _Atomic(wchar_t)          /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:127  atom:h error: 0x%x\n", err);
49583-      |                                                                                   ~~     ^~~
49584-      |                                                                                   %x
49585-ic_wchar_t;
49586-      |         ^
49587-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdatomic.h:112:9: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
49588-  112 | typedef _Atomic(int_least8_t)       atomic_int_least8_t;
49589-      |         ^
49590-29: note: expanded from macro 'DTRACE_PROBE2'
49591-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdatomic.h:113:9  127 | : warning:              '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
49592-  113 | typedef _At   omiregc(uint_least8ist_t)er uin   tpt   r_t __atodtracemic_a0_ui asnt_m("leax0"st8) =_t; (uint
--
55772-lure_desc_len);
55773-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_host.h:710:4: warning: identifier '__Request__host_register_mach_voucher_attr_manager_t' is reserved because it starts with '__' [-Wreserved-identifier]
55774-
55775-  710 |         } __Request__host_regist/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43er_: warning: mach_vformat specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
55776-ouch 1418 |                                   er_  "att(osr_m_reanaasogern_a_t llo__ac_bttribuuffte_er _((errunuor:sed %d));, k
55777-      | cda          ^
55778:ta error: %d, length:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_host.h:727:4 %ld)\n",: warning: 
55779-      | identifier '__Request__host_register_well_known_mach_voucher_attr_manager_t' is reserved because it starts with '__' [-Wreserved-identifier]
55780-                                                                                                  ~~~
55781-        727 | |                                                                                                   %zu
55782-         /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/vfs/vfs_bio.c:1711:} 14194:  |                                  warning: format specifies type 'unsigned int' but the argument has type 'int' [-Wformat]
55783-   pat__Requh, est__hos 1711 |                         LIret_STasregison_erter_wror_REMO, kcdVE(bpata_e, b_vrror,nbufs fata);
55784-      | l_fai                        ^~~~~~~~~~~~~~~~~~~~~~~~~
55785-elll/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/queue.h_known_mach_vouchure_der_atesc_ltr_maen);
55786-nager      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
55787-_t __att/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:572:2: note: ributexpanded from macro 'LIST_REMOVE'
55788-:  572 |         LIST_C1381:e_HECK__((unNEXT(used)elm, );
--
576924-  334 | _pthread_priority_sched_pri(pthread_priority_t pp)
576925-      | ^
576926-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/pthread/priority_private.h:345:1: warning: identifier '_pthread_priority_relpri' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
576927-  345 | _pthread_priority_relpri(pthread_priority_t pp)
576928-      | ^
576929-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if_utun.c:779:11: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
576930:  779 |                 /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/pthread/priority_private.h:357errno_t error:1: =  warning: identifier '_pthread_priority_is_overcommit' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
576931-  357 | _kern_ppthbufreapood_pl_ariolloritc_ny_iosls_oeepver(rxcommit_pp(pt, 1hre, &ad_rx_priph)ori;
576932-      ty_|                         ^
576933-t pp)
576934-      | ^
576935-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/pthread/priority_private.h:364:1: warning: identifier '_pthread_priority_is_cooperative' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
576936-  364 | _/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if_utun.c:629:11:pth warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]rea
576937-  d_p629 |         uint32_t ariovairitl =y_i kes_crn_oopchaerannetivl_ae(pvaithrlabeadle__prsloiort_cityoun_t t(rpp)x_ring);
576938-      |                  ^
576939-
576940-      | ^
--
744273-g  819 |         serialate ? "!":"", name, val1,izer = OSSerializer::forTarget(this, O val1, val2, val2, val3, val3, inSMput1emberFunctionCast(OSSerializerCallback, this, &IODTNVRAMDiags::serializeStats));
744274-      |                                                    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
744275-, input1, input2, input/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.h:545:20: note: expanded from macro 'OSMemberFunctionCast'
744276-  545 |           _ptmf2ptf(self, (void (OSMe2, input3, input3); \
744277-      |                                                                                                                            ^~~~~~
744278-ta/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:77Class: note: expanded from macro 'NECPDATATRACELOG'
744279:Base: 1049 |         os_log_error:*)(void)) func))
744280-      |                           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
744281-(necp_data_trace_log_handle, "%s: " format "\n", __FUNCTION__, __VA_ARGS__); \
744282-      |                                                         ~~~~~~                     ^~~~~~~~~~~
744283-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:398:41: note: expanded from macro 'os_log_error'
744284-  398 |     _os_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IONVRAM.cpp:819:45: warning: cast from '_ptf_t' (aka 'void (*)()') to 'OSSerializerCallback' (aka 'bool (*)(void *, void *, OSSerialize *)') converts to incompatible function type [-Wcast-function-type-strict]
744285-log_verify_format_str(format, ##__VA_ARGS__);     819 |         ser                        ializer = OSSerializer::forTarget(this, OSMemberFunctionCast(OSSerializerCallba                \
744286-      |                               ~~~~~~    ^~~~~~~~~~~
744287-ck, this, &IODTNVRAMDiags::serializeStats));
744288-      |                                                    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
744289-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.h:544:7: note: expanded from macro 'OSMemberFunctionCast'
--
840400-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/select.h:112:
840401-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/waitq.h:32:
840402-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_types.hize_t;   :80:
840403-   In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/host_info.h: /*66:
840404-In file included from  by/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/message.h:813te :
840405-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.hcou:40:
840406:nt or error:10682:23: warning: identifier '__startup_ZALLOC_entry___zone_site_register_10682' is reserved because it starts with '__' [-Wreserved-identifier]
840407- */
840408-      |                                 ^
840409- /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_types.h:93:8: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/arm/_types.h:98:33:warning: identifier '_vm_map' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
840410- warning: identifier '__darwin_time_t' is reserved because it starts with '__' [-Wreserved-identifier]
840411-   98   93 |  | tystrpeductef  _vlonm_map;
840412-      |        ^g  
840413-10682                  __darwin_time_t;        /* time() */
840414-      |                                 ^
840415-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Tests/Tests.cpp:183:
840416-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/sysctl.h:95:
--
869183-      |                 ^t __a
869184-        ttrib     ute__((u/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.c:74:6nused));     
869185-      |           ^
869186-  \
869187-      |                                                                                 ^
869188-: note: expanded from macro 'NETAGENTLOG0'
869189:   74 |             os_l/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/processor_set.h/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/priority_queue.h:og_error:439:4: warning: identifier '__Reply__processor_set_policy_enable_t' is reserved because it starts with '__' [-Wreserved-identifier]
869190-(OS_LOG_716:1: DEFAULT,  439 |         } "%s: %s\n", warning: identifier '_priority_queue_remove_root' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
869191-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/priority_queue.h:696:81: note: expanded from macro 'PRIORITY_QUEUE_MAKE' __Re
869192-  696 | ply__pro__FUNcessor_s         et_po     licy_     enable_tCTION__, msg)     ;             __at     tribu     te__(     (unus                                    \
869193-        ed));  \
869194-      |                                                                                 ^
869195-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/priority_queue.h
869196-      |           ^
869197-:677:81: note: expanded from macro '\
869198-PRIORITY_QUEUE_MAKE_BASE'
869199-  /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/processor_set.h      :451:4: warning: identifier '__Reply__processor_set_policy_disable_t' is reserved because it starts with '__' [-Wreserved-identifier]|             ^
--
873078-NULL session");
873079-      |                 ^
873080-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.c:74:6: note: expanded from macro 'NETAGENTLOG0'
873081-   74 |             In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/mach_debug.c:68:
873082-In file included from ./mach/mach_host_server.h:62:
873083-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/ipc_kobject.h:77os_:
873084:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_port.h:log116:1_error: warning: (OSidentifier '__startup_ZALLOC_entry___zone_site_register_116' is reserved because it starts with '__' [-Wreserved-identifier]
873085-_LOG_DEFAU/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:966LT,:2: "% note: expanded from macro 'KALLOC_ARRAY_TYPE_DECL's: 
873086-  %s\966 |         n",KAL __LOCFUNCTI_DION_SPATCH(KALLOC_, _ARmsgRAY); _TY   PE_   DEC   L,    ##_   _VA \
873087-_AR      |             ^GS_
873088-_)
873089-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396:5:      |         ^ note: expanded from macro 'os_log_error'
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
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sun Nov  8 04:10:06 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
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

## build-console.log

### the errors

```
116:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
```

### around them

```
108-      _vfstbllist in vfs_conf.o
109-  "_mockfs_vfsops", referenced from:
110-      _vfstbllist in vfs_conf.o
111-  "_mockfs_vnodeop_opv_desc", referenced from:
112-      _vfs_opv_descs in vfs_conf.o
113-  "_native_verified_block_root_authorized", referenced from:
114-      _bsd_init in bsd_init.o
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
