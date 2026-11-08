# Why the build failed

run: 36, commit ac04c989569dc3537be8eaf328dffc08d478ed4e

## archive-13-build-storage-family.log

### the errors

```
16:    /Users/runner/work/UniXNU-nio/UniXNU-nio/out/feeds/IOStorageFamily-67f9003c/IOUserBlockStorageDevice_kext.h:29:10: fatal error: 'IOUserBlockStorageDevice.h' file not found
18:    /Users/runner/work/UniXNU-nio/UniXNU-nio/out/feeds/IOStorageFamily-67f9003c/IOMediaBSDClient.cpp:2908:5: error: ISO C++17 does not allow 'register' storage class specifier [-Wregister]
19:    /Users/runner/work/UniXNU-nio/UniXNU-nio/out/feeds/IOStorageFamily-67f9003c/IOMediaBSDClient.cpp:2909:5: error: ISO C++17 does not allow 'register' storage class specifier [-Wregister]
```

### around them

```
10-PASS IOPartitionScheme (0 warnings)
11-PASS IORequest (0 warnings)
12-PASS IORequestsPool (0 warnings)
13-PASS IOStorage (1 warnings)
14-
15---- IOBlockStorageDriver ---
16:    /Users/runner/work/UniXNU-nio/UniXNU-nio/out/feeds/IOStorageFamily-67f9003c/IOUserBlockStorageDevice_kext.h:29:10: fatal error: 'IOUserBlockStorageDevice.h' file not found
17---- IOMediaBSDClient ---
18:    /Users/runner/work/UniXNU-nio/UniXNU-nio/out/feeds/IOStorageFamily-67f9003c/IOMediaBSDClient.cpp:2908:5: error: ISO C++17 does not allow 'register' storage class specifier [-Wregister]
19:    /Users/runner/work/UniXNU-nio/UniXNU-nio/out/feeds/IOStorageFamily-67f9003c/IOMediaBSDClient.cpp:2909:5: error: ISO C++17 does not allow 'register' storage class specifier [-Wregister]
20-
21-2 of 13 IOStorageFamily sources did not compile; full logs in /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/storage-family
```

### the tail

```
PASS IOAppleLabelScheme (2 warnings)
PASS IOApplePartitionScheme (0 warnings)
PASS IOBlockStorageDevice (1 warnings)
FAIL IOBlockStorageDriver (5 lines of log, 1 errors)
PASS IOFDiskPartitionScheme (0 warnings)
PASS IOFilterScheme (0 warnings)
PASS IOGUIDPartitionScheme (0 warnings)
PASS IOMedia (0 warnings)
FAIL IOMediaBSDClient (361 lines of log, 2 errors)
PASS IOPartitionScheme (0 warnings)
PASS IORequest (0 warnings)
PASS IORequestsPool (0 warnings)
PASS IOStorage (1 warnings)

--- IOBlockStorageDriver ---
    /Users/runner/work/UniXNU-nio/UniXNU-nio/out/feeds/IOStorageFamily-67f9003c/IOUserBlockStorageDevice_kext.h:29:10: fatal error: 'IOUserBlockStorageDevice.h' file not found
--- IOMediaBSDClient ---
    /Users/runner/work/UniXNU-nio/UniXNU-nio/out/feeds/IOStorageFamily-67f9003c/IOMediaBSDClient.cpp:2908:5: error: ISO C++17 does not allow 'register' storage class specifier [-Wregister]
    /Users/runner/work/UniXNU-nio/UniXNU-nio/out/feeds/IOStorageFamily-67f9003c/IOMediaBSDClient.cpp:2909:5: error: ISO C++17 does not allow 'register' storage class specifier [-Wregister]

2 of 13 IOStorageFamily sources did not compile; full logs in /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/storage-family
```

## archive-12-build-nio-ufs-archive.log

### the tail

```
nio-ufs: build/nio-ufs/libNioUfs.a -> build/sheng-ufs/libShengUfs.a (454264 bytes, sha256 b1691f5f8c96645557f5728fb9323074b7fd277cac6c671e5c1818f973313883)
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
49864: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
57194:__( 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
57203:    "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
539113:SIZE) /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:1430:40error: note: expanded from macro 'KALLOC_DISPATCH1'
645610:  633 |             caller, log_  158 |                 msg, infop.protocol, ntohs(info.lorincal_addr.sin.sin_port), ntohs(info.local_atf("buffeddr.sin6.sin6r_stage_initiali_port), ze failed to allocate memory. Error 0x%x\n", ret)ntohs(info.r/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_param.h:415;
665142:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_param.h:126:15: note: , __V4. Error 0x%x\n", _Aexpanded from macro 'round_page_overflow'_ARGS___func__,
688638:  102 |                 printf("progress_notify_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
707403: 1049 |         o/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/thread_act.h:541:4s_log_error: warning: identifier '__Request__thread_get_state_t' is reserved because it starts with '__' [-Wreserved-identifier]
711811:   className ## _Methods                    272 |                 printf("]->id, pol   icy_search_zlib_stage_initialize failed to allocate memory. Error 0array      x%x         \n", ret);
772325: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSAtomic.h:1011049 |         os_log_error:20(necp_data_tr: note: expanded from macro 'OSAddAtomic64'
774682:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/cpu_data.h:43_portog_error:
884968: ./mach/mach_host_server.h:8272428 |         } d, error:4: warning: __Rep %d dataidentifier '__Reply__host_info_t' is reserved because it starts with '__' [-Wreserved-identifier]
1001777:(typeof(func(a))(   *)(   con   st    voi   d *__darwin/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:538_ssize_t;    ))f   /* byte count uncor error:1: */ warning: identifier '__zalloc_flags' is reserved because it starts with '__' [-Wreserved-identifier]
1142346:,     "/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_param.h:415(\t%llu error:6: warning: identifier '__ovr' is reserved because it starts with '__' [-Wreserved-identifier]
1180710: 1413 |                     "| error: latency %d too big (> 1 sec)",
1180749:  522 |         kheap_free(KHEAP_DA  "| TA_BUFFerror: jitterERS, elem, si %dms too bigze);
1180768: 1438 |                     "| error: loss recovery %dms too big",
1180787:as 1456 |                 e(elem)NETEM_LOG, __kfr(LOG_ERR, "| error: ree_size);                \
1180811: 1463 |                 oad_and_e    "| error: outrase(put interelem), __val %dms too big",
1467293:(LOG_ERR, fd_cb, "failed to get the close error: %d", error);
1529951:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
1530060:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
1544111:ler : internal error: "
1634170:     275 |         SASEL_LOG("R62 | typedeetuf __urneintd w32_t   ith error: %d", e   __darwin_id_t;          /* [XSI] pid_t, uid_t, or gid_t*/
1661672:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/_types.h/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdatomic.hDR_convert__:69:mig_reply_error:104:9: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]28: warning: identifier '__darwin_mach_port_name_t' is reserved because it starts with '__' [-Wreserved-identifier]_t(__
2057500:  602 |         int __pagein_error:44:
2296957:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if.h:76               el_error:
2321887:   76 |             os_log_error:5:(tr note: expanded from macro 'os_log_error'ack
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
49858-_sm/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:165:2: note: expanded from macro 'DTRACE_MACF3'
49859-  rq_serializile_ed165 | fallback__remove_one(
49860-      | ^
49861-size_bytes / (1024ULL * 1024ULL)), err);
49862-      |                                                                                   ^~~
49863-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1364:76: warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
49864: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
49865-      |                                                                                   ~~     ^~~
49866-      |                                                                                   %x
49867-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/smr.h:982:1: warning: identifier '__smrq_serialized_remove' is reserved because it starts with '__' [-Wreserved-identifier]
49868-  982 | __smrq_serialized_remove(
49869-      | ^
49870-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/smr.h:999:1: warning: identifier '__smrq_serialized_remove' is reserved because it starts with '__' [-Wreserved-identifier]
49871-  999 | __smrq_serialized_remove(
49872-      | ^
49873-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/smr.h:1010:1: warning: identifier '__smrq_serialized_replace' is reserved because it starts with '__' [-Wreserved-identifier]
49874- 1010 | __smrq_serialized_replace(
--
57188-, __FILE_NAME__, __LINE__); \
57189-      |                 ~~               ^~~~~~~~~~~
57190- 1076 |         } __Request__task_set_special_port_t __attribute__((unused));
57191-      |           ^
57192-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1086:4: warning: identifier '__Request__thread_create_t' is reserved because it starts with '__' [-Wreserved-identifier]
57193- 1086 |         } __Request__thread_create_t __attribute/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
57194:__( 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
57195-      |                                                                                ~~~
57196-      |                                                                                %zu
57197- (un1414 |                                             path, mc_error, fatal_failure_desc_len);
57198-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
57199-used));
57200-      |           ^
57201-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
57202- 1418 |                                 /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1100:4: warning: identifier '__Request__thread_create_running_t' is reserved because it starts with '__' [-Wreserved-identifier]
57203:    "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
57204-      |                                                                                                   ~~~
57205-      |                                                                                                   %zu
57206- 1100 |  1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
57207-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
57208-        } __Request__thread_create_running_t __attribute__((unused));
57209-      |           ^
57210-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
57211- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
57212-      |                             ^
57213-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1118:4: warning: identifier '__Request__task_set_exception_ports_t' is reserved because it starts with '__' [-Wreserved-identifier]
--
539107- 2615 |         viAY_TYPE_DrtuECLal , #boo#__l sVA_eriARGaliS__ze()
539108-      OSSeri|         ^
539109-aliz/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:1432e *:2: se note: expanded from macro 'KALLOC_DISPATCH'
539110- rializ1432 | /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/if_ports_used.c:        KALLOC_DISPATCH1(base, K1289:4: ALLOCwarning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
539111- 1289 |                         os_log(OS__COUNLOG_DT_ARGEFAULS(__VT, "%A_ARGs: mbS__),uf_co ##__pydatVA_ARa(ESPGS__)_HDR_
539112-      |         ^
539113:SIZE) /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:1430:40error: note: expanded from macro 'KALLOC_DISPATCH1'
539114- %d",
539115- 1430 | #d      |                         ^
539116-efine KALLOC_DISPAer) cTCH1(onst;base,
539117-      |                      ^
539118- N, ../Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.h:673:.) __CONCAT(b/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:292:5ase, : note: expanded from macro 'os_log'
539119-N  292 |     _15)Static_assert: note: overridden virtual function is here
539120-(  673 |         virtual boo__buil serltin_ializconste(OSSant_perial(formize *at),  seri"formalizeat str) coring nst =must  0;
539121-      be co|                      ^
539122-nst(__VA_ARGS__)
539123-      |                                        ^
--
707397-olicy_search_array[i]->oridentifier '__Request__act_set_state_t' is reserved because it starts with '__' [-Wreserved-identifier]
707398-  528 |         } __Request__acder, resultString[policy_search_arrayt_set_sta[i]->resultte_t __]); \
707399-      attribu|         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
707400-te__((unused));
707401-      |           ^
707402-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:77: note: expanded from macro 'NECPDATATRACELOG'
707403: 1049 |         o/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/thread_act.h:541:4s_log_error: warning: identifier '__Request__thread_get_state_t' is reserved because it starts with '__' [-Wreserved-identifier]
707404-(nec  541 |         } __Request__threp_datad_get_state_a_trat __attrice_log_handle, bute__((unused));
707405-      "%s: |           ^
707406-" format "\n",/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/thread_act.h:555 __FUNCTI:4: warning: identifier '__Request__thread_set_state_t' is reserved because it starts with '__' [-Wreserved-identifier]
707407-ON__  555 |         } _, __VA_ARGS_RequestIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kdp/output_stages/out_zlib.c:32__thread_set_s:
707408-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/iokit/IOKit/IOTypes.h:40:
707409-tate_t __aIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/iokit/IOKit/system.h:41:
707410-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/mach_interface.h:35:
707411-In file included from _ttrib./mach/exc_server.h:70:
707412-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/vm/vm_map.h:92:
707413-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/vm/vm_object.h:130:ute___); \6: warning: identifier '__vm_object_fault_info_unused_bits' is reserved because it starts with '__' [-Wreserved-identifier]
--
772319-warning: missing field 'kmg_type_hash' initializer [-Wmissing-designated-field-initializers]
772320-  698 |         };
772321-      |         ^
772322-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:77dAtomi: note: expanded from macro 'NECPDATATRACELOG'
772323-c64(-1LL, address);
772324-      |                ^
772325: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSAtomic.h:1011049 |         os_log_error:20(necp_data_tr: note: expanded from macro 'OSAddAtomic64'
772326-ace_log_handl  101 |         (OSAddAtomic64(a, __SAFE_CAe, "%s: " forST_PTR(volIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/PassthruInterruptController.cpp:35:
772327-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOPlatformExpert.h:40:
772328-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.hatile SInt64*,b)))
772329-      |                           ^
772330-:49:
772331-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/system.h:36:
772332-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/thread.h:145/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSAtomic.h:m59:5: note: expanded from macro '__SAFE_CAST_PTR'
772333-:
772334-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/priority_queue.h:143:38: warning: identifier '__key' is reserved because it starts with '__' [-Wreserved-identifier]
772335-   59at "\n", __FUNCTION__, __VA_ARGS__); \  143 |         long                                __key: PRIORITY_QUEUE_ENTRY_
--
774676-In file included from 
774677-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_port.h:91:
774678-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_space.h:90 __:
774679-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/task.hRep:122:
774680-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/cpu_data.h:42:
774681-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/machine/cpu_data.h: 1049 |         os_lly__mach34:
774682:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/cpu_data.h:43_portog_error:
774683-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/thread.h:80:21: _extract(necp_data_trace_member_t __attribwarning: identifier '_MachineStateCount' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]
774684-_log_hanute__((u   80 | nused));dle, "%s: " f
774685-      |           ^
774686-ormat "\n", __FUNCTION__,extern unsigned int _MachineStateCount[];
774687-      |                     ^
774688- /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:1690__VA_ARGS__:4: warning: ); \
774689-      | identifier '__Reply__mach_port_get_context_t' is reserved because it starts with '__' [-Wreserved-identifier]
774690- 1690 |         } __Repl                                                        ~~~~~~                     ^~~~~~~~~~~
774691-y__mach_port_get_context_t/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:398 _:41: note: _attributexpanded from macro 'os_log_error'
774692-e__((unused)  398 | );
--
884962- 2414./mach/mach_host_server.h:785:7: warning: G_ERR, " |         } __Reidentifier '__RequestUnion__mach_host_subsystem' is reserved because it starts with '__' [-Wreserved-identifier]
884963-  785 | uply__Registernion __Reques taskmtUnion__mach_swap_maessag_hostch_voe size c_subsucher_t __attrould ibute__(ystemnot b(unus {
884964-      | e reaed));      ^
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
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sun Nov  8 05:28:08 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
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

## build-storage-family_IOBlockStorageDriver.log

### the errors

```
2:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/feeds/IOStorageFamily-67f9003c/IOUserBlockStorageDevice_kext.h:29:10: fatal error: 'IOUserBlockStorageDevice.h' file not found
```

### around them

```
1-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/feeds/IOStorageFamily-67f9003c/IOBlockStorageDriver.cpp:36:
2:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/feeds/IOStorageFamily-67f9003c/IOUserBlockStorageDevice_kext.h:29:10: fatal error: 'IOUserBlockStorageDevice.h' file not found
3-   29 | #include "IOUserBlockStorageDevice.h"
4-      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~
5-1 error generated.
```

## build-storage-family_IOMediaBSDClient.log

### the errors

```
86:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/feeds/IOStorageFamily-67f9003c/IOMediaBSDClient.cpp:2908:5: error: ISO C++17 does not allow 'register' storage class specifier [-Wregister]
89:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/feeds/IOStorageFamily-67f9003c/IOMediaBSDClient.cpp:2909:5: error: ISO C++17 does not allow 'register' storage class specifier [-Wregister]
```

### around them

```
78- 2873 |         attributes.priority = DK_TIER_TO_PRIORITY(bufattr_throttled(attributes.bufattr));
79-      |                             ~ ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
80-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/disk.h:244:74: note: expanded from macro 'DK_TIER_TO_PRIORITY'
81-  244 | #define DK_TIER_TO_PRIORITY(tier)             (((tier) << DK_TIER_SHIFT) | ~DK_TIER_MASK)
82-      |                                                ~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~
83-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/feeds/IOStorageFamily-67f9003c/IOMediaBSDClient.cpp:2881:51: warning: implicit conversion changes signedness: 'int32_t' (aka 'int') to 'UInt32' (aka 'unsigned int') [-Wsign-conversion]
84- 2881 |         minor = gIOMediaBSDClientGlobals.getMinor(getminor(dev));
85-      |                                          ~~~~~~~~ ^~~~~~~~~~~~~
86:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/feeds/IOStorageFamily-67f9003c/IOMediaBSDClient.cpp:2908:5: error: ISO C++17 does not allow 'register' storage class specifier [-Wregister]
87- 2908 |     register UInt64      byteCount;
88-      |     ^~~~~~~~
89:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/feeds/IOStorageFamily-67f9003c/IOMediaBSDClient.cpp:2909:5: error: ISO C++17 does not allow 'register' storage class specifier [-Wregister]
90- 2909 |     register UInt64      byteStart;
91-      |     ^~~~~~~~
92-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/feeds/IOStorageFamily-67f9003c/IOMediaBSDClient.cpp:2916:47: warning: implicit conversion changes signedness: 'int32_t' (aka 'int') to 'UInt32' (aka 'unsigned int') [-Wsign-conversion]
93- 2916 |     minor = gIOMediaBSDClientGlobals.getMinor(getminor(DKR_GET_DEV(dkr, dkrtype)));
94-      |                                      ~~~~~~~~ ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
95-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/feeds/IOStorageFamily-67f9003c/IOMediaBSDClient.cpp:3141:61: warning: implicit conversion changes signedness: 'int32_t' (aka 'int') to 'UInt32' (aka 'unsigned int') [-Wsign-conversion]
96- 3141 |     MinorSlot * minor   = gIOMediaBSDClientGlobals.getMinor(getminor(dev));
97-      |                                                    ~~~~~~~~ ^~~~~~~~~~~~~
98-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/feeds/IOStorageFamily-67f9003c/IOMediaBSDClient.cpp:3502:21: warning: implicit conversion changes signedness: 'UInt32' (aka 'unsigned int') to 'int' [-Wsign-conversion]
99- 3502 |         if ( _table[minorID].isAssigned )  remove(minorID);
100-      |              ~~~~~~ ^~~~~~~
101-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/feeds/IOStorageFamily-67f9003c/IOMediaBSDClient.cpp:3540:21: warning: implicit conversion changes signedness: 'UInt32' (aka 'unsigned int') to 'int' [-Wsign-conversion]
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
