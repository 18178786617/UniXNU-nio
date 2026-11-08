# Why the build failed

run: 39, commit f9a9796d55f9203e2795b47909b6bf100c391f5b

## archive-13-build-storage-family.log

### the tail

```
PASS iig generated IOUserBlockStorageDevice.h (19416 bytes) and its implementation (101746 bytes)
PASS IOAppleLabelScheme (2 warnings)
PASS IOApplePartitionScheme (0 warnings)
PASS IOBlockStorageDevice (0 warnings)
PASS IOBlockStorageDriver (12 warnings)
PASS IOFDiskPartitionScheme (0 warnings)
PASS IOFilterScheme (0 warnings)
PASS IOGUIDPartitionScheme (0 warnings)
PASS IOMedia (0 warnings)
PASS IOMediaBSDClient (96 warnings)
PASS IOPartitionScheme (0 warnings)
PASS IORequest (0 warnings)
PASS IORequestsPool (0 warnings)
PASS IOStorage (1 warnings)
PASS IOUserBlockStorageDevice.iig (0 warnings)
the archive holds 16 members for 14 objects: __.SYMDEF SORTED IOAppleLabelScheme.o IOApplePartitionScheme.o IOBlockStorageDevice.o IOBlockStorageDriver.o IOFDiskPartitionScheme.o IOFilterScheme.o IOGUIDPartitionScheme.o IOMedia.o IOMediaBSDClient.o IOPartitionScheme.o IORequest.o IORequestsPool.o IOStorage.o IOUserBlockStorageDevice.o
```

## archive-12-build-nio-ufs-archive.log

### the tail

```
nio-ufs: build/nio-ufs/libNioUfs.a -> build/sheng-ufs/libShengUfs.a (454264 bytes, sha256 5339c92be1d15e04143370091ff080059f962ccbbee1b5fd0c12afa2431c5658)
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
47718:  162 |         DTRACE_lePollersPROSetBE2up for(__ cosdtref_, ile fanamilee, d wargith1,  error: 0argx%x2);\n"
71176:  381/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_map.h error:1435:, i7: warning:  | nidentifier '__ReplyUnion__vm_map_subsystem' is reserved because it starts with '__' [-Wreserved-identifier]        t
122803:t, error:66:, i24: nt,note: expanded from macro 'os_ptr_load_and_erase'
328791:byte count or/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:503 error:44: */ note: expanded from macro 'kheap_alloc'
589478:ion/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:1437s",     "(\t%ll/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdatomic.h:169:42:u error:2: warning: s injidentifier 'ZONE_ID__LAST_RO' is reserved because it contains '__' [-Wreserved-identifier]
628254:  158 |                 printf("buffer_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
647143:  268 |                 printf("(%s) Failed to handle availability of LZ4. Error 0x%x\n", __func__, ret);
707950:e  295 |     _osfault_log_intntf("%s faernal(&__dso_Struchandle, log, iled OS_LOto alG_TYPlocatE_DEFe memAULT, _os_logtors(_fmt,class ##__VA_ory. Error 0xName,%x\n", __funcARGS___, r_);  et);
770868:./device/device_server.h:2993 1049 |         os_log_error:4:(ne warning: identifier '__Reply__io_iterator_reset_t' is reserved because it starts with '__' [-Wreserved-identifier]cp_
773758:   os_log_66 | /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:947:4error: warning: identifier '__Request__mach_port_allocate_qos_t' is reserved because it starts with '__' [-Wreserved-identifier]
786370: 11927 |                 NECPLOG(LOG_ERR, "%s (process %s:%u) sysctl_io_opaque() error %d", __func__, proc_best_name(p), pid,/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:1573:2 error: warning: );
1155129:R, "equest__semaphore_create| error: invalid sch_t __attribute__((uneduler moused));del %d",
1155182:        const __typ        } __Request 1398 |                 NE__task_TEM_LOGset_emulatioeof__(((t(LOG_ERR, "|n_t __a error:ttribut duplicationype_t *)NULL)-_p %d >>field) *e__((unused));__ptr = ( %d",
1155214:) 1413 |                     "| error: latency %d too big (> 1 sec)",
1155232: 1420 |         /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1323            "| error: jitter %dms too big (latency %dms)",
1155256: 1420 |                     "| error: jitter %dms too big (latency %dms)",
1155311:RR, "| error: r((type_t *)NULL)->field) *__ptr = (ptr);            eordering %d > %d",
1155366:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/pmap.h 1463 |                     "| error: output i:43:
1494792: 4398 |                                 FDLOG(LOG_DEBUG, &nil_pcb, "ctl_enqueuembuf returned an error: %d", error);
1551088:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
1563275:  312 |                            35 | __startup_EARLY_BOOT_entipseclog((LOG_DEBUG, "ry_socd_client_set_pesp4_output: internal error:rimary_kernelcache_uuid_92
1563310:l error: c_l"
1647900:  275 |         SASEL_LOG("Returned with error: %d", err);
2020627:sso/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSBase.h:50r_injected_error:1:_co warning: identifier '__OSAbsoluteTime' is reserved because it starts with '__' [-Wreserved-identifier]unt
2291913: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
2291919: 3383 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
2298237:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSAtomic.hnd_erase(ele\t%llu error:59:5: note: expanded from macro '__SAFE_CAST_PTR'
2321298:_log_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/proc_internal.h:411:20error: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
2353035:  224 |         int error:140: = 1: 0;
2354301:(/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/sysctl.h:426:2wchar_t)_inject_error: note: expanded from macro '__SYSCTL_NODE'
2365284: byte c/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_statistics.h:458ount or error:7: */ warning: identifier '__unused_bit_19' is reserved because it starts with '__' [-Wreserved-identifier]
2772467:Undefined symbols for architecture arm64:
2772476:ld: symbol(s) not found for architecture arm64
2772477:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
2772478:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
2772479:make[2]: *** [build_all] Error 2
2772480:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
2772481:make: *** [build] Error 2
```

### around them

```
47712-PERFORM 1355 |                            _RS (cLT(orefilopee_fallbacratk_sionize, m_bypc)tes DT / (10RAC24UE_MLL ACF* 12(m024ULL)),ac_ er_rsr);
47713-      | lt_                                                                                  ^~~
47714-_ ## operation, void *, mpc, int, 0)
47715-      |                                          ^
47716-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1364:76: warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
47717- 1364 |                 IOLog("I/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:162OPo:2:lle note: expanded from macro 'DTRACE_MACF2'dFi
47718:  162 |         DTRACE_lePollersPROSetBE2up for(__ cosdtref_, ile fanamilee, d wargith1,  error: 0argx%x2);\n"
47719-      | , e        ^
47720-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:127:29: rr)note: expanded from macro 'DTRACE_PROBE2'
47721-  127;
47722-       |          |                                                                                   ~~     ^~~
47723-      |                                                                                   %x   
47724-    register uintptr_t __dtrace_a0 asm("x0") = (uintptr_t) arg0;                    \
47725-      |                                    ^
47726-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:357:2: warning: identifier '__dtrace_a1' is reserved because it starts with '__' [-Wreserved-identifier]
47727-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:315:10: note: expanded from macro 'MAC_PERFORM'
47728-  315 |                 MAC_PERFORM_RSLT(operation, mpc);           \
--
71170-  265 |                        |                                                    ^
71171-   DTRACE_MACF3/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/vfs/vfs_cache.c/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_map.h:1425:2301::4:2:  warning: identifier '__Reply__vm_remap_new_t' is reserved because it starts with '__' [-Wreserved-identifier]
71172-(mac__cawarning:  lidentifier '__result' is reserved because it starts with '__' [-Wreserved-identifier]1425l
71173- |         __ } _## _Recheplyck,__vm_r voemap_nid ew_t __attribute__*, ((umpcnused));
71174-, i      |           ^nt,
71175-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/smr.h:381:14: note: expanded from macro 'smrq_serialized_foreach'
71176:  381/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_map.h error:1435:, i7: warning:  | nidentifier '__ReplyUnion__vm_map_subsystem' is reserved because it starts with '__' [-Wreserved-identifier]        t
71177-  , MAC_  (ITERAT(itE_C) =HEC __K);con \
71178-tai      |                     ^ner_of_s 1435 | afe(__uniit,on  typeo__Rf(*(it)),epl fiyUnion__vm_map_subsyst
71179-eld))em ;  {
71180-      |       ^
71181-         \
71182-      |                     ^
71183-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/cdefs.h:1097:18: note: expanded from macro '__container_of_safe'
71184- 1097 |         __ptr_or_null ? __container_of(__ptr_or_null, type_t, field) : NULL;    \
71185-      |                         ^
71186-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/cdefs.h:1090:12: note: expanded from macro '__container_of'
--
122797-      |               ^
122798-o/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_posix_sem.c:140:2: warning: identifier '__dtrace_a0' is reserved because it starts with '__' [-Wreserved-identifier]
122799-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:265:14: note: expanded from macro 'MAC_CHECK'
122800-  265 |                     DTRACE_MACF3(mac__call__ ## ch/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/proc_internal.had_ane:dck,_er voase(elem));                   id \
122801-      |             ^
122802-239:*/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h2, mpc,: warning:  in'_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
122803:t, error:66:, i24: nt,note: expanded from macro 'os_ptr_load_and_erase'
122804-  239 |    66 |         __auto_type *__sing MAle C_I__eTERptrATE = &(e_CHlemECK); );       \
122805-         |                     ^
122806-          /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h      :165: \
122807-2:       |                               ^note: expanded from macro 'DTRACE_MACF3'
122808-_At  165 | omi        DTc uRACintE_P32_ROBt pE3(s_s__sigrdt_etu, nrn_ameval, aidarg1tio, arg2n; , a/* rg3sig);
122809-ret      |         ^urn
122810-
122811- argument validation/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/skywalk/IOSkywalkSupport.cpp/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:139:29: note: expanded from macro 'DTRACE_PROBE3'
122812- st  139 | ate            : */
122813-      |         ^
--
328785-t (duh) */Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:512:2:/
328786-      |                                 ^
328787- /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/arm/_types.h:97:33: warning: identifier '__darwin_ssize_t' is reserved because it starts with '__' [-Wreserved-identifier]note: expanded from macro 'kalloc_data'
328788-
328789-   97 | typed  512 | ef         khlong  eap   _alloc   (KH   EAP      _DATA_   __dBUFFERarwin_S, sizssize_e, flat;    gs)
328790-      |    /*         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
328791:byte count or/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:503 error:44: */ note: expanded from macro 'kheap_alloc'
328792-      |                                 ^
328793-
328794-  503 |         kheap_a/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/arm/_types.h:98:33:llo warning: identifier '__darwin_time_t' is reserved because it starts with '__' [-Wreserved-identifier]c_t
328795-   ag(98 | tkalypedefloc lo_heng    ap, si      ze, fl      ags, V    __M_ALLOdarwinC_SITE_time__TAG()t;    )
328796-      |         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~
328797- /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:2303:2:   /*  note: expanded from macro 'VM_ALLOC_SITE_TAG'
328798- time() */2303 |         STA
328799-      |                                 ^
328800-RTUP_ARG(ZALLOC, STARTUP_RANK_LAST, __zone_site_register, &site);   \
328801-      |         ^
--
589472-      edef _A|         ^
589473-to/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:1436mic(RORuin_I:2:NJE warning: identifier 'ZONE_ID__LAST_RO_EXT' is reserved because it contains '__' [-Wreserved-identifier]
589474- 1436 |         ZONE_ID__LCTIONS,AST_RO_EXT           "_Err= ZONE_ID_AMFI_OStmax_t) orInj        ENTIT atomLEMENic_uiTS,
589475-      ntmax_t;
589476-      |         ^
589477-ect|         ^
589478:ion/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:1437s",     "(\t%ll/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdatomic.h:169:42:u error:2: warning: s injidentifier 'ZONE_ID__LAST_RO' is reserved because it contains '__' [-Wreserved-identifier]
589479- warning: identifier '_Value' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]
589480- 1437 |   169 | te        ZONE_ID__cted)LAST_RO = ZONyp\n") edef struct aE_ID_tomic_fl \
589481-      |           ^
589482-_LAag { aST_tomRO_EXT,
589483-      /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/skywalk/os_stats_private.h:981:1: ic_bo|         ^
589484-ol _Value/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:1455:2:; } warning: identifier 'ZONE_ID__FIRST_DYNAMIC' is reserved because it contains '__' [-Wreserved-identifier] atowarning: identifier '__FSW_STATS_MAX' is reserved because it starts with '__' [-Wreserved-identifier]
589485-mic_fla/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/skywalk/os_stats_private.h:965:16: note: 
589486- g;
589487-      |                                          ^
589488-expanded from macro 'STATS_REGISTER'
--
770862-rface_i./device/device_server.h:2981:4: warning: identifier '__Reply__io_iterator_next_t' is reserved because it starts with '__' [-Wreserved-identifier]nde
770863- 2981 |         } __Reply_x, _iosoc_itketera_potorlic_ney_ixt_d, t _soc_atkettri_skbutip_e__pol((uicynus_ided)); );
770864-\
770865-            |           ^|                                                                                                                                                                                                                              ^~~~~~~~~~~~~~~~
770866-
770867-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:77: note: expanded from macro 'NECPDATATRACELOG'
770868:./device/device_server.h:2993 1049 |         os_log_error:4:(ne warning: identifier '__Reply__io_iterator_reset_t' is reserved because it starts with '__' [-Wreserved-identifier]cp_
770869- 2993 |         } __Reply__io_itdateraa_ttorrac_ree_log_handle, "%sets: _t " f__aormat "\n", __FUNCTttrIONibu__,te_ ___((VA_unuARGsedS__));); 
770870-      | \
770871-                ^
770872-|                                                         ~~~~~~                     ^~~~~~~~~~~
770873-./device/device_server.h:3007:4: warning: identifier '__Reply__io_service_get_matching_services_t' is reserved because it starts with '__' [-Wreserved-identifier]
770874- 3007 |         } __Reply__io_ser/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:398:41: note: expanded from macro 'os_log_error'
770875-  398 |     _os_vicloge_g_veet_rifmaty_fchiormng_at_serstrvic(foes_rmat _t, _at##_tri_VAbut_ARe__GS_((unus_);ed)   );
770876-         |           ^   
770877-                 ./device/device_server.h:3023:4: warning: identifier '__Reply__io_registry_entry_get_property_t' is reserved because it starts with '__' [-Wreserved-identifier]   
770878-    3023 |            } _   _Re   ply__io_regi  \str
--
773752-       |                                                                                                                              %u
773753-|                     ^
773754-t/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1033:70:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h:66:24: note: expanded from macro 'os_ptr_load_and_erase'
773755-   ribute__ note: expanded from macro 'NECPLOG'
773756-((unused));
773757- 1033 |                |           ^
773758:   os_log_66 | /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:947:4error: warning: identifier '__Request__mach_port_allocate_qos_t' is reserved because it starts with '__' [-Wreserved-identifier]
773759-(necp_log_h  947 |         }andle __Re, "%squest: " forma__mach_p        __auort_ato_tyllocape *_te_qos_tt "\n", __FUN_singCTIONle ____, _eptr _VA_A= &(elem __at);   tribu     te__(        RGS__); \
773760-      |                                                  ~~~~~~                     ^~~~~~~~~~~(unus
773761-   \
773762-      /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:398:41|                               ^
773763-: note: e/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_kmsg.c:1937:3: expanded from macro 'os_log_error'
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
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sun Nov  8 06:52:01 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
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
