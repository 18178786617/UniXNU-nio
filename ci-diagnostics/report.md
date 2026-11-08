# Why the build failed

run: 38, commit 474555889b736ed78a6f232c110b201d0a38b6c9

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
the archive defines no C++ symbols at all; 14 objects, 3042392 bytes
```

## archive-12-build-nio-ufs-archive.log

### the tail

```
nio-ufs: build/nio-ufs/libNioUfs.a -> build/sheng-ufs/libShengUfs.a (454264 bytes, sha256 ff9345c890c5683091db51ecd43b77691483b8591eea7d9970d36b348ea27b13)
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
54945: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
54978:  589 |         (paniloc_bc)(ex " @%s:%d", ## __VA_ARuffer error: %d, kcdata error: %d, length: %ld)\n",
87704:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSContainers.h:46, int, error:
343594:uu_section_start[0] __SECTION_Sn<scratch space>:155:1t oTART_SYM("__DATA", "__perr error: note: c */
636791:  268 |                 printf("(%s) Failed to handle availability of LZ4. Error 0x%x\n", __func__, ret);
657178:  102 |                 printf("progress_notify_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
680772:  272 |                 printf("zlib_stage_initialize failed to allocate memory. Error 0x%xidentifier '_T' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]
692628:  143 |                 printf("%s failed to allocate memory. Error 0x%x\n", __func__, In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOGuardPageMemoryDescriptor.cpp:29:
694967: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:8921049 |         os_log_error:4: warning: identifier '__Request__mach_port_extract_right_t' is reserved because it starts with '__' [-Wreserved-identifier]
764184:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IONVRAMCHRPHandler.cpp:711_error:2:(ne warning: format specifies type 'unsigned int' but the argument has type 'int' [-Wformat]cp_
850305: |           _/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/arm/_types.h  os_log_error:_att24:33: warning: identifier '__int64_t' is reserved because it starts with '__' [-Wreserved-identifier]
1186637: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
1186689:  224 |             _os_atomic_value_cast(p, v), "| error: corr, \
1186910: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d >/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/machine.c:266:4: warning: identifier '___v' is reserved because it starts with '__' [-Wreserved-identifier]
1186975: 1413 |                     "| error: latency %d too big (> 1 sec)",
1186998: 1420 |                     "| error: jitter %dms too big (latency %dms)",
1187009: 1420 |                     "| error: jitter %dms too big (latency %dms)",
1187021: 1438 |                     "| error: loss recovery %dms too big",
1187032: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
1187043: 1463 |                     "| error: output interval %dms too big",
1502055: error: %d", error);
1570940:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
1571230:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
1584117:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
1584142:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
1657901:  f__(*(p)) volatile275 |         SASEL_LOG("Returned _Atomic *)(uintptr_t)(p with error: %d", err);
2291477:_var, type, KT_ 3378 | SHA                        RED   _AC "(CT)kcdata_memcpy;   error: %d, l   eng   th: %ld)\n",
2291489: 3383 |                     "(os 1451 | _reason_alloc        _S_butatic_ffeassr error: %ertd, (sikcdze ata<=  erKALrorLOC: %_SAd, length: %lFE_d)\n",
2355454:a_inject_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kperf/kperfbsd.c:778:1error: warning: identifier '__startup_SYSCTL_entry_sysctl__kperf__pet_idle_rate' is reserved because it starts with '__' [-Wreserved-identifier]
2622617:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:1451error:2: note: ;
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
54939-<scratch space>:10:1: note: expanded from here
54940-   10 | 1891
54941-      | ^~~~
54942-ct _vm_map;
54943-      |        ^
54944-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
54945: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
54946-      |                                                                                ~~~
54947-      In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/DINetBootHook.cpp:91:
54948-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOService.h:44:
54949-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IORegistryEntry.h:39:
54950-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOTypes.h|                                                                                %zu
54951- 1414 |                                 :40:
54952-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/system.h:36:
54953-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/thread.h:88:
54954-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_types.h:80:
54955-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/host_info.h:66:
--
54972-      |        ^
54973-           panic("Bad link elm %p next->prev != elm @%u",     \
54974-      |                                                                ~~
54975-  512 |                          (elm), __LINE__);   1418 |                                                       "(os_reason_al          \
54976-      |                                 ^~~~~~~~
54977-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
54978:  589 |         (paniloc_bc)(ex " @%s:%d", ## __VA_ARuffer error: %d, kcdata error: %d, length: %ld)\n",
54979-      |                                                                                                   ~~~
54980-      | In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/DINetBootHook.cpp:91GS_:
54981-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOService.h:44:
54982-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IORegistryEntry.h:39:
54983-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOTypes.h:40:
54984-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/system.h:36:
54985-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/thread.h:88:
54986-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_types.h:80:
54987-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/host_info.h:66:
54988-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/message.h:824:6: warning: identifier '__ovr' is reserved because it starts with '__' [-Wreserved-identifier]
--
87698-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOService.h:44:
87699-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IORegistryEntry.h:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_skywalk.c:51:2: warning: identifier '__dtrace_a0' is reserved because it starts with '__' [-Wreserved-identifier]
87700-   51 |         MAC_CHECK(skywalk_flow_check_listen, kauth_cred_get(), flow, addr, type, protocol);
87701-      |         ^
87702-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:265:14: note: expanded from macro 'MAC_CHECK'
87703-  265 |                     DTRACE_MACF3(mac__call__ ## check, void *, mpc40:
87704:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSContainers.h:46, int, error:
87705-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSValueObject.h:472, int, MAC_ITER:10ATE_CHECK): ; \
87706-      |                     ^
87707-warning: missing field 'unused1' initializer [-Wmissing-designated-field-initializers]
87708-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:165:2  472 | : note: expanded from macro 'DTRACE_MACF3'
87709-  165 |         DTRAC                E_PROBE3(__sdt_da, name, arg1, arg2ta, arg3); = IOMa
87710-      |         ^
87711-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:139:29: note: expanded from macro 'DTRACE_PROBE3'
87712-  139 |           lloc      regiTyster uintppetr_t __dtr(T);ace_a0 asm
87713-      ("x0") = (|                        ^
87714-u/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:intp330:9:tr_t) arg0;            note:        expanded from macro 'IOMallocType'
--
343588-tart/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/arm/_types.h:97:33: warning: identifier '__darwin_ssize_t' is reserved because it starts with '__' [-Wreserved-identifier]up_
343589-   97 | typedef long    TUN      ABL   ES_   nam   e_  __darwin_In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/cpuid.c## var[] =:35:
343590-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/cpu_data_internal.h:39:
343591-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/percpu.h:284:14: warning: identifier '__percpu_section_start' is reserved because it starts with '__' [-Wreserved-identifier]
343592-s key; \  284 |         extern char __percpsize_t;       /* byte co
343593-      |                                    ^
343594:uu_section_start[0] __SECTION_Sn<scratch space>:155:1t oTART_SYM("__DATA", "__perr error: note: c */
343595-      pu"expanded from here|                                 ^
343596-
343597-  )155 | __star/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/arm/_types.h:98:33:tup_TUNABLES_name_d; warning: identifier '__darwin_time_t' is reserved because it starts with '__' [-Wreserved-identifier]
343598-
343599-   98 | typedef      |                     ^
343600- long k_powe                   __darwin_time_t;        /r_state_timeout_ms
343601-      | ^
343602-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:4578:1: warning: identifier '__startup_TUNABLES_spec_dk_power_state_timeout_ms' is reserved because it starts with '__' [-Wreserved-identifier]
343603-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/startup.h:227:2: note: expanded from macro 'TUNABLE'
343604-  227 |         __TUNABLE(type_t,* time(/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/percpu.h:291:14: warning: identifier '__percpu_section_end' is reserved because it starts with '__' [-Wreserved-identifier]
--
694961-  879 |         } __Request__mach_port_insert_right_t __attribute__( |     NECPDATATRACELOG(LOG_ERR, "DATA-TRACE <%s>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>", \/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/zalloc.h:573
694962-      |     ^
694963-:1: warning: identifier '__zalloc_id' is reserved because it starts with '__' [-Wreserved-identifier]
694964-  573 | (unused)/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049);
694965-      |           ^
694966-:2: note: expanded from macro 'NECPDATATRACELOG'
694967: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:8921049 |         os_log_error:4: warning: identifier '__Request__mach_port_extract_right_t' is reserved because it starts with '__' [-Wreserved-identifier]
694968-(__zalloc_id(
694969-      | ^
694970-  892 |         } __Request__ma/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/zalloc.h:608:1: warning: identifier '__zalloc_ro' is reserved because it starts with '__' [-Wreserved-identifier]
694971-nch_e  608 | cp__zalloc_ro(
694972-      | ^
694973-p_data_trace_log_handle, "%s: " format "\n", __FUNCTION__, __VA_ARGS__); \
694974-      |         ^
694975-ort_extract_right_t __attribute__((unused));
694976-      | /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/zalloc.h:1090:1: warning: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396identifier '__zalloc_percpu' is reserved because it starts with '__' [-Wreserved-identifier]
694977- 1090 | __zall          ^
--
764178-%sma   73 | tch        IOingLog <%("%s> s:%<vas:%u - " fmt,lue __ (%FILd /E_N 0xAME%X)__, (% __d /FUN 0xCTI%X)ON_ (%_, d /__L 0xINE%X)__, in ##putarg (%s);d / \
764179- 0x      |                             ~~~                                           ^~~~%X)
764180- (%d / 0x%X) (%d / 0x%X)>", \
764181-      |                                                                                                                                 ^~
764182-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:50: note: expanded from macro 'NECPDATATRACELOG'
764183- 1049 |         os_logIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IONVRAM.cpp:1182:
764184:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IONVRAMCHRPHandler.cpp:711_error:2:(ne warning: format specifies type 'unsigned int' but the argument has type 'int' [-Wformat]cp_
764185-  711 |         DEBUG_IFEdatRROa_tR(rracet,e_l "eog_rashaneBadle, "%s: " formnk=at %#x"\n\n"", , r__Fet)UNCTION__, __VA_;
764186-      ARG|         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
764187-S__)/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IONVRAM.cpp:73:56:; \ note: expanded from macro 'DEBUG_IFERROR'
764188-   73 |         
764189-      | IOL                                                        ^~~~~~
764190-o/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:397:83:g("%s:%s:%u - note: expanded from macro 'os_log_error' " 
764191-  397 |  fmt   , __FILE_NAME__,__a __ttrFUNibuCTIte_ON__((_, sec__LtioINEn("__,__T ##EXTarg,__s);os_ \
764192-log      |                      ~~                                       ^~~~~~~~"))
764193-<scratch space>:23:1: ) snote: expanded from here
764194-tatic const char _os_log   23 | _fm711t[] = format;   
--
850299-pyout error : warning: identifier '__uint32_t' is reserved because it starts with '__' [-Wreserved-identifier]
850300-  881(%d)"   23 | ty |         } _, error);
850301-      |                                 ^_R
850302-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1033:6: note: expanded from macro 'NECPLOG'pedef unsigned int            _eply__host_processors_t _uint
850303- 103332_t;
850304-      |                                 ^
850305: |           _/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/arm/_types.h  os_log_error:_att24:33: warning: identifier '__int64_t' is reserved because it starts with '__' [-Wreserved-identifier]
850306-(necp_log_handle, "%s:ribut    " f24 | type__((ormatedef long long       "\n"unused));
850307-, __F           |           ^
850308-UN    __int64/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/host_priv.h:895:4: warning: identifier '__Reply__host_get_clock_control_t' is reserved because it starts with '__' [-Wreserved-identifier]
850309-  895 |         } __ReplCy__host_get_clock_t;
850310-      TION__, __VA_A|                                 ^
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
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sun Nov  8 06:42:53 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
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
