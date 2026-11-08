# Why the build failed

run: 32, commit 4a0a8cf3331be5020f2758c4c339bafa555fbafa

## component-NioUfs.log

### the errors

```
1:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:24:10: fatal error: 'IOKit/storage/IOBlockStorageDevice.h' file not found
```

### around them

```
1:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:24:10: fatal error: 'IOKit/storage/IOBlockStorageDevice.h' file not found
2-   24 | #include <IOKit/storage/IOBlockStorageDevice.h>
3-      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
4-1 error generated.
5-
```

### the tail

```
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:24:10: fatal error: 'IOKit/storage/IOBlockStorageDevice.h' file not found
   24 | #include <IOKit/storage/IOBlockStorageDevice.h>
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1 error generated.

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
46570:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:315:10: note: expanded from macro 'MAC_PERFORM'ith error: 0x%x\n", err);
58396:                                            "(kcdata_memcpy error: %d, length: %ld)\n",
58402: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
445746:Fil_nonatomiePollec_prsSoinetup(%terd) (p)) /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/skywalk/packet_common.h:676:1error: warning: identifier '__packet_get_keep_alive' is reserved because it starts with '__' [-Wreserved-identifier]
640484:age_ta 1245 |         } __Retic_aquest__minitiach_palizeort_a faisseledrt_ tossert(__buiatt ltin_allocconstateributes_t  memo__attribute__((unused))antry. Error 0x%x\n", ret);
661325:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/clock_reply_server.h:        os_log_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:512:2error: note: expanded from macro 'kalloc_data'
661552:      | alue (%d Error 0          ^
670956:__ma 1049 |         os_log_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_param.h:126:15error: note: expanded from macro 'round_page_overflow'
684353:  102 |                 printf("progress_notify_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
708728:ntf("zlib_stag  293n type_t *__sie_initializnglee |     __zfa  __attribute__((section("__TEXTa,_iled to allocate memory. Error 0x%x\n", ret);
720061:  143 |                 printf("%s failed to allocate memory. Error 0x%x\n", __func__, ret);
777506: 1049 |         os_log_error:
836104:tagent_)/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:753:4error: warning: identifier '__Request__mach_port_destroy_t' is reserved because it starts with '__' [-Wreserved-identifier]
849451:uid error (%d)", error:
1173910: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
1173933: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/_types/_fd_def.h:119:1: warning: identifier '__darwin_fd_set' is reserved because it starts with '__' [-Wreserved-identifier]
1173945: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
1173958: 1413 |                     "| error: latency %d too big (> 1 sec)",
1173972: 1420 |                     "| error: jitter %dms too big (latency %dms)",
1173983: 1420 |                     "| error: jitter %dms too big (latency %dms)",
1173994: 1438 |                     "| error: loss recovery %dms too big",
1174005: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
1174016: 1463 |                     "| error: output interval %dms too big",
1462355:              __darwin_ssize_t;       /* byte count or/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdatomic.h:100 error:9: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
1499022:2626 |                 FDLOG(LOG_ERR, fd_cb, "failed to get the close error: %d", error);
1503370: 4398 |                                 FDLOG(LOG_DEBUG, &nil_pcb, "ctl_enqueuembuf returned an error: %d", error);
1593090:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
1607131:rnal  550 | #dct_inbound_packet(ipsec_if,efine os_ato error: "
1607175:icp6__asoutput: internal error: "
1948348: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.hly_error:1430_t(__CTLFLAG_RW | unusedC:40: note: expanded from macro 'KALLOC_DISPATCH1'
2102510:e    61 | __startup_SYSCTL_entry_sysctl__vm__c/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.ho_memmpressor_inject_error:1432:2
2291035: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
2291044:  201"(os_reason_alloc_ |             &buffer error:__startup_lck_grp_spec_ ## var)
2291058:a error: %d, length: %ld)\n",
2350888:a/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/sysproto.h:2241:8: :81tegicallwarning: y_error: identifier '__nexus_get_opt_args' is reserved because it starts with '__' [-Wreserved-identifier]
2712933:in_g;/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/priority_queue.h:671et_fh_ptr(error:81: note: expanded from macro '\
2772465:Undefined symbols for architecture arm64:
2772474:ld: symbol(s) not found for architecture arm64
2772475:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
2772476:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
```

### around them

```
46564-  165 |         DTRAOLoCE_g("PROIOPBE3(__sdt_, name, arg1, arg2, arog3);
46565-lled      |         ^
46566-File/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:141:29: note: expanded from macro 'DTRACE_PROBE3'
46567-  141 |                 register uinPotptr_t __dtracell_a2 asm("x2") = (uinertptr_t) arg2;       sS    etu         \
46568-      |                                    ^
46569-p for corefile failed w/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:142:3: warning: identifier '__dtrace_a0' is reserved because it starts with '__' [-Wreserved-identifier]
46570:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:315:10: note: expanded from macro 'MAC_PERFORM'ith error: 0x%x\n", err);
46571-      | 
46572-  315 |                                                                                   ~~     ^~~
46573-                      MAC_PERFORM_RSLT(opera|                                                                                   %xtion, mpc);           
46574-\
46575-      |                 ^
46576-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:304:42: note: expanded from macro 'MAC_PERFORM_RSLT'
46577-  304 | #define MAC_PERFORM_RSLT(operation, mpc) DTRACE_MACF2(mac__rslt__ ## operation, void *, mpc, int, 0)
46578-      |                                          ^
46579-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:162:2: note: expanded from macro 'DTRACE_MACF2'
46580-  162 |         DTRACE_PROBE2(__sdt_, name, arg1, arg2);
--
58390-(*(var)) == sizeof(*(type)NU/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOMemoryDescriptor.h:318:22: warning: identifier '__iomd_reserved4' is reserved because it starts with '__' [-Wreserved-identifier]
58391-LL), "s  318 |         uintptr_t         /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.cize m:1414  is:26__matchiomd_"); (reser(type)(var));: ved4;warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
58392-
58393-      |                             ^
58394- 1413 |  })
58395-      |            ^
58396:                                            "(kcdata_memcpy error: %d, length: %ld)\n",
58397-      |                                                                                ~~~
58398-      |                                                                                %zu
58399- 1414 |                                             path, mc_error, fatal_failure_desc_len);
58400-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
58401-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
58402: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
58403-      |                                                                                                   ~~~
58404-      |                                                                                                   %zu
58405- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
58406-      /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/vfs/vfs_bio.c:2475:3: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
58407-|                                                                       ^~~~~~~~~~~~~~~~~~~~~~
58408- 2475 |                 /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
58409- 1381 |         OSA        os_reddAason_ttom reicLasoongn =(1, os &n_rebdwasoritn_ce);reate(
58410-      | OS_                ^/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOMemoryDescriptor.h:879:
58411-RE2: warning: identifier '_Dispatch' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]
58412-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSAtomic.h:148:22  879 |         OSDecl: note: expanded from macro 'OSAddAtomicLong'
--
445740-t(p,  phv),, c \
445741-ons      |             ^t boolean
445742-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic_private_impl.h:218:46: note: expanded from macro '_os_atomic_value_cast'
445743-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOPolledInterface.cpp:868:55: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]_t 
445744-  868 |         is_        HIke  218 | ep_        ({BLO taliypeve)of(*os_castG("_toIOPolled
445745-      | ^
445746:Fil_nonatomiePollec_prsSoinetup(%terd) (p)) /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/skywalk/packet_common.h:676:1error: warning: identifier '__packet_get_keep_alive' is reserved because it starts with '__' [-Wreserved-identifier]
445747- 0x___v %x\n"= (v), ope; ___nStatv; })e, err);
445748-      
445749-      |                                                     ^
445750-|                                                  ~~                 ^~~~~~~~~
445751-  676 | __packet_ge      |                                                  %u
445752-t_k/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOHibernatePrivate.h:522:115:eep note: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm64/machine_routines.c:674:2_aliv: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
445753-e(const uint6expanded from macro 'HIBLOG'
445754-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic_private.h  522 |   :444:37: note: expanded from macro 'os_atomic_inc'4_t ph)
445755-      | 
445756-  { if (^
--
661319-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOTypes.hF_SIZ:40:
661320-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/system.hE, Z_:41:
661321-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_interface.hWAITOK);note: expanded from macro 'NECPDATATRACELOG'
661322-
661323-      |                         ^
661324- 1049 | :34:
661325:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/clock_reply_server.h:        os_log_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:512:2error: note: expanded from macro 'kalloc_data'
661326-(necp_  512 |         kdata_traceh130eap:4:_alloc(KHEAP_DATA_BUFFERS_log_h warning: identifier '__Request__clock_alarm_reply_t' is reserved because it starts with '__' [-Wreserved-identifier]
661327-andle, "%,   130s:si |         } _ze, f_Requlags)est__clo " forma
661328-      |         ^
661329-t/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:503: "\n", ck___FUNCTIONal44: note: expanded from macro 'kheap_alloc'
661330-__, __VAar  503_ARGS |         khe__); ap_al\
661331-      |                                                         ~~~~~~                     ^~~~~~~~~~~loc_tag(m_reply_
661332-kalt _l/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:398oc_heap,_attr sizeibute, fla__((ugs, VM_ALLOC_SITE_TAG())
661333-      |                                                   ^
661334-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/zalloc.h:2303:2nused));
661335-      : note: expanded from macro 'VM_ALLOC_SITE_TAG'
--
670950- warning: identifier '__ovr' is reserved because it starts with '__' [-Wreserved-identifier]      |           ^
670951-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049
670952-  424 |         if (round_p:77: note: age_over/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/notify_server.h:291:4flow(: warning: identifier '__Reply__mach_notify_send_once_t' is reserved because it starts with '__' [-Wreserved-identifier]
670953-x, &x)  291 |         }) {
670954-       __Replyexpanded from macro 'NECPDATATRACELOG'
670955-|             ^
670956:__ma 1049 |         os_log_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_param.h:126:15error: note: expanded from macro 'round_page_overflow'
670957-(necp_  126 |          data_trace_loch     _notify_g_handle  boo, "%sl __o: " fvr =orm os_asendd_d_oovencerfl_t ow(__ain,ttr (__typeof__(*iat "\bute__(n", __FUout))NCTION__(unus, __Ved));A_ARG
670958-      |           ^
670959-S__); \
670960-      |         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~
670961-PAGE_MA/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:399:76: note: expanded from macro 'os_log_error'
670962-SK,/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/notify_server.h  :303:4: warning: identifier '__Reply__mach_notify_dead_name_t' is reserved because it starts with '__' [-Wreserved-identifier] out)
670963-  303 | ; \
670964-      |                      ^
670965-399 |     _os_        } __Replylog_in__mach_ternotnal(&__dso_hanifydle, log, OS/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_param.h:433:6_LOG_TYP_dead_na: warning: identifier '__ovr' is reserved because it starts with '__' [-Wreserved-identifier]
670966-me_t __atE_ERRtribute_  433 |         i_((unuseOR, _os_log_ff (romt, ##__d));
--
777500-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c:657:27: note: expanded from macro 'NECP_DATA_TRACE_LOG_POLICY'
777501-  656 |     NECPDATATRACELOG(LOG_ERR, "DATA-TRACE <%s>: %s - policy id=%d session_order=%d policy_order=%d result=%s (cond_policy_id %d) (skip_session_order %d skip_order %d)", \
777502-      |     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
777503-  657 |                 caller, log_msg, policy_search_array[i]->id, policy_search_array[i]->session_order, policy_search_array[i]->order, resultString[policy_search_array[i]->result], policy_search_array[i]->condition_mask & NECP_KERNEL_CONDITION_POLICY_ID ? policy_search_array[i]->cond_policy_id : 0, skip_session_order, skip_order); \
777504-      |                 ~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
777505-In file included from pt/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_kmsg.c:86:1049:77ion_t __attr: note: expanded from macro 'NECPDATATRACELOG'
777506: 1049 |         os_log_error:
777507-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/ipc_kobject.h:77:
777508-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_port.h:91:
777509-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_space.h:90:
777510-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/task.h:122:
777511-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/cpu_data.h:48:25: warning: identifier '_disable_preemption' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
777512-   48 | extern void             _disable_preemption(void);
777513-      |                         ^
777514-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/cpu_data.h:49:25: warning: identifier '_disable_preemption_without_measurements' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
777515-   49 | e(necxtern void             _disable_preemption_p_data_trace_log_handle, "%s: " format "\n", __FUNCTION__, __VA_Aiwithout_measurementsRGS__); \
777516-      |         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~
--
836098-, "necLOC_ARRAYp_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:cl_TYPEient__DECLremov, ##_e clo_VA_Ase neRGS__xus e)
836099-      |         ^rror 
836100-741:4: warning: identifier '__Request__mach_port_allocate_t' is reserved because it starts with '__' [-Wreserved-identifier]
836101-(%d/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:1432:2) MES: note: expanded from macro 'KALLOC_DISPATCH'
836102-SAGE T 1432 |         KYPE %ALLOCu", ne_D  741 |         } __ReISPATquestCH1(b__macase, h_porKALLOt_allC_COUocateNT_AR_t __GS(__attriVA_ARbute_GS__)_((un, ##_used)_VA_A);
836103-      | RGS__          ^
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
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sun Nov  8 04:22:42 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
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

## build-nio-ufs_compile.log

### the errors

```
1:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:24:10: fatal error: 'IOKit/storage/IOBlockStorageDevice.h' file not found
```

### around them

```
1:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:24:10: fatal error: 'IOKit/storage/IOBlockStorageDevice.h' file not found
2-   24 | #include <IOKit/storage/IOBlockStorageDevice.h>
3-      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
4-1 error generated.
```

## status.txt

```
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
driver   NioUfs                   device
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
