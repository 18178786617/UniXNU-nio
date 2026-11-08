# Why the build failed

run: 33, commit 9822abb6164bbf13c8d9622e3ac446481b9d4bc0

## component-NioUfs.log

### the tail

```
               ~ ^~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:2284:71: warning: operand of ? changes signedness: 'int' to 'uint32_t' (aka 'unsigned int') [-Wsign-conversion]
 2284 |     gRootDiagnostic.result = result.phase == UfsRootPhase::Identity ? kIOReturnNotPrivileged :
      |                            ~                                          ^~~~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:146:34: note: expanded from macro 'kIOReturnNotPrivileged'
  146 | #define kIOReturnNotPrivileged   iokit_common_err(0x2c1) // privilege violation
      |                                  ^~~~~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:136:71: note: expanded from macro 'iokit_common_err'
  136 | #define iokit_common_err(return )          (sys_iokit|sub_iokit_common|return)
      |                                             ~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:2285:48: warning: operand of ? changes signedness: 'int' to 'uint32_t' (aka 'unsigned int') [-Wsign-conversion]
 2284 |     gRootDiagnostic.result = result.phase == UfsRootPhase::Identity ? kIOReturnNotPrivileged :
      |                            ~
 2285 |       result.phase == UfsRootPhase::Schedule ? kIOReturnNoResources : kIOReturnError;
      |                                                ^~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:143:34: note: expanded from macro 'kIOReturnNoResources'
  143 | #define kIOReturnNoResources     iokit_common_err(0x2be) // resource shortage
      |                                  ^~~~~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:136:71: note: expanded from macro 'iokit_common_err'
  136 | #define iokit_common_err(return )          (sys_iokit|sub_iokit_common|return)
      |                                             ~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:2285:71: warning: operand of ? changes signedness: 'int' to 'uint32_t' (aka 'unsigned int') [-Wsign-conversion]
 2284 |     gRootDiagnostic.result = result.phase == UfsRootPhase::Identity ? kIOReturnNotPrivileged :
      |                            ~
 2285 |       result.phase == UfsRootPhase::Schedule ? kIOReturnNoResources : kIOReturnError;
      |                                                                       ^~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:141:34: note: expanded from macro 'kIOReturnError'
  141 | #define kIOReturnError           iokit_common_err(0x2bc) // general error
      |                                  ^~~~~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:136:71: note: expanded from macro 'iokit_common_err'
  136 | #define iokit_common_err(return )          (sys_iokit|sub_iokit_common|return)
      |                                             ~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~
12 warnings and 3 errors generated.

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
55552:_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
62056:check, void *, /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.h:1856mpc, int, error:5, int: , MAC_ITERnote: expanded from macro 'OSDeclareCommonStructors'ATE_CHECK)
112238:   /*/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSBase.h: byte coun50:1t or error: warning: identifier '__OSAbsoluteTime' is reserved because it starts with '__' [-Wreserved-identifier]
670569:_error:61(nec  943 | :1: p_da__smrq_serializenote: expanded from hered_remove_one(
688712:  761false |         }Error 0x%x\n", ret);
717741: 1049 |         os_log_error:177:9: warning: (nec/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:980:2: warning: p'_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
724321:  143 |                 printf("%s failed to allocate memory. Error 0x%x\n", __func__, ret);
757894:      |  1049 |         os_log_error:451:7: warning: identifier '__unused_bit_11' is reserved because it starts with '__' [-Wreserved-identifier]
804943:a 1033 |             os_log_error:ch_vou(ne warning: identifier '_pthread_priority_make_from_thread_qos' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
1177459: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
1177479: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
1177498:__typeof__(*(p 1398 |                 NETEM_LOG(LOG_ERR, "| error: dupl)) volatile _Aicationtomic *)(u_p %d > %d",
1177516: 1413 |                     "| error: latency %d too big (> 1 sec)",
1177538: "| error: jitter %dms too big (latency %dms)",
1177554:mo_ 1420 |                     "| error: jitter %dms too big (latency %dms)",
1177574:14: note: expanded from macro 'os_atomic_load' 1438 |                     "| error: los
1177594:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic_private.h:342:2: note:  1456 |                 NETEM_LOG(LOG_ERR, "| error: reordeexpanded from macro 'os_atomic_store'
1495880:MAKE(struct p 2626 | rio                FritDLOy_qG(LueuOG_e_sERRche, fd_sd_ctabb, le_"famaxile *, priorid tty_o gqueue_et entthery_ clstaoseble error: %d", erro_t);
1565044:  202 |                 ipsIn file included from mach/exc_server.c:12eclog((LOG_DEBUG, "ah4_output: internal error: "
1565239:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
1573260:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
1573284:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
1650808:  275 |         SASEL_LOG("Returned with error: %d", err);
1824410: : _  113 | __NDR_convert__mig_reply637:_Panic("%s:%d Assertion failed37:_error_t(__unused mig_reply_error: %s : " fmt, __FILE_NAME__, __LINE__, # ex, ##args)) note: expanded from macro 'os_atomic_xchg'
2014338:_HOLES, s  602 |         int truct vm___/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSAtomic.h:101mpagein_error:ap_20: linnote: expanded from macro 'OSAddAtomic64'
2273684:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/host_info.h  __darwin_ssize_t;     In file included from :  /* byte count/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/queue.h o66r error:
2292017:_TYPE_ASSE 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
2292028: 3383 |                     "(os_reason_alloc_buffer error: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/posix_shm.c:1084:2: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
2292029:%d, kcdata error: %d, len/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:656:26: note: expanded from macro 'kfree_type'
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
55546-, __LINE__); \
55547-      |                 ~~               ^~~~~~~~~~~
55548-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]<scratch space>:49
55549- 1418 |                                     "(:1:os_ note: expanded from hererea
55550-   49 | 2139
55551-      | ^~~~son
55552:_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
55553-      |                                                                                                   ~~~
55554-      |                                                                                                   %zu
55555- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
55556-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
55557-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
55558- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
55559-      |                             ^
55560-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
55561- 1426 |                 zfree(ZV_NAMEI, vn_path);
55562-      /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/vfs/vfs_bio.c:2186:3: warning: format specifies type 'unsigned int' but the argument has type 'int' [-Wformat]
--
62050-  139 |                 remogister uintptr_t __dtracnStrue_a0 asm("x0") ct= (uintptr_t) arg0;                    \
62051-      |                                    ^
62052-ors(cla/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:2023:2: warning: identifier '__dtrace_a1' is reserved because it starts with '__' [-Wreserved-identifier]
62053-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:265:14: note: expanded from macro 'MAC_CHECK'
62054-  265 |              ssName, dispatch);                 DTRACE    \
62055-_MACF3(mac__cal      | l__ ##         ^
62056:check, void *, /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.h:1856mpc, int, error:5, int: , MAC_ITERnote: expanded from macro 'OSDeclareCommonStructors'ATE_CHECK)
62057- 1856; \
62058-       |     _OS_ADD_METHODS(c|                     ^
62059-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:165:2: note: expanded from macro 'DTRACE_MACF3'
62060-lassNa  165 |         DTRACE_PROBE3(__me, dispatch)
62061-      |     ^
62062-note: (skipping 2 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)
62063-sdt_, n/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.h:ame, arg1,1835:5: note:  arg2expanded from macro '_OS_ADD_METHODS_dispatch'
62064-, arg3);
62065-      |         ^
62066-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:140:29: note: expanded from macro 'DTRACE_PROBE3'
--
112232-In file included from  (duh/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/sysctl.h:) */
112233-      |                                 ^
112234-1014:
112235-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/arm/_types.h:97:33: warning: identifier '__darwin_ssize_t' is reserved because it starts with '__' [-Wreserved-identifier]
112236-   97 | typedeIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/proc_internal.hf lon:80g           :
112237-In file included from          __darwin_ss/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSAtomic.h:ize_t;    39:
112238:   /*/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSBase.h: byte coun50:1t or error: warning: identifier '__OSAbsoluteTime' is reserved because it starts with '__' [-Wreserved-identifier]
112239- */
112240-      |                                 ^
112241-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/arm/_types.h:98:33:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/vfs/vfs_lookup.c:76:
112242-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/systm.h:107:
112243-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/tty.h:75:
112244-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/select.h:112:
112245-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/waitq.h:37   50:
112246-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/queue.h:215:13: | __OSAbsoluteTime(
112247-      | ^
112248-  warning: identifier '__queue_element_linkage_invalid' is reserved because it starts with '__' [-Wreserved-identifier]
--
670563-lvaldre3, input1, i/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/smr.h:n
670564-      nput1, input2, input2, input3, input3); \
670565-      |                                                ^~~~
670566-943|                                       ^
670567-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:77: note: expanded from macro 'NECPDATATRACELOG'
670568- 1049 |         os_log:1: <scratch space>warning: identifier '__smrq_serialized_remove_one' is reserved because it starts with '__' [-Wreserved-identifier]
670569:_error:61(nec  943 | :1: p_da__smrq_serializenote: expanded from hered_remove_one(
670570-      | ^
670571-
670572-ta_trace_log_handle, "%s: " format "\n", __FUNCTION__, __VA_ARGS__); \
670573-      |                                                         ~~~~~~                     ^~~~~~~~~~~
670574-   /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/smr.h:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:398:41: note: 61 | sysctl__user_c982:1expanded from macro 'os_log_error'
670575-hi  398 |     _os_log_verify_format_str(forma: t, #ldrenwarning: identifier '__smrq_serialized_remove' is reserved because it starts with '__' [-Wreserved-identifier]
670576-  982 | __smrq_seri
670577-      alized_remove(
670578-      | ^
670579-#| ^
--
717735-      |                                                                                                                                                         ~~
717736-  663 |                 caller"); , negate ? "!":"", na((type)(var)); })
717737-      | me, val1, val1, val2, val2, val3, val3, input1, input           ^
717738-1, input2, input2, input3, input3); \
717739-      |                                                                                                                            ^~~~~~
717740-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSAtomic.h/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:77: note: expanded from macro 'NECPDATATRACELOG'
717741: 1049 |         os_log_error:177:9: warning: (nec/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:980:2: warning: p'_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
717742-  identifier '__kt_typed_operators_T' is reserved because it starts with '__' [-Wreserved-identifier]_d
717743-  980 |         IOata_t177Orace_log_handle |         return v, erOSAdd"%s: " format "\n", __FUrideTypedOperators(T);
717744-      |         ^N
717745-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:946:2AtomicLoCTION__ng(-1L,, __VA_: addr note: expanded from macro 'IOOverrideTypedOperators'
717746-A  946 | ess);
717747-      R        | GS__); \
717748-      |                                                         ~~~~~~                     ^~~~~~~~~~~
717749-               ^
717750-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSAtomic.h:148:22: __IOnote: expanded from macro 'OSAddAtomicLong'Ov/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:398:41:errid note: expanded from macro 'os_log_error'
717751-eT
--
757888-  450 |                     __in_t           pu               unused_bit_10:1,t2,     
757889-      |                     ^
757890-         input3, input3); \
757891-      |                                                                              ^~~~
757892- /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_statistics.h/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:77: note: expanded from macro 'NECPDATATRACELOG'
757893-   \
757894:      |  1049 |         os_log_error:451:7: warning: identifier '__unused_bit_11' is reserved because it starts with '__' [-Wreserved-identifier]
757895-(necp                                                                                ^
757896-  _da451 |                     __unused_ta_trabitce__11log:1,_ha
757897-      | ndl                    ^
757898-e, "%s: " format "\/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_statistics.h:453:7:n", warning: identifier '__unused_bit_13' is reserved because it starts with '__' [-Wreserved-identifier] __
757899-  FUN453 |         CTI          ON_  __, _un__VuseA_Ad_bRGSit___)13:; \1,
757900-
757901-      |       |                     ^                                                        ~~~~~~                     ^~~~~~~~~~~
757902-
757903-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_statistics.h:455/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:398:7::41: warning: identifier '__unused_bit_15' is reserved because it starts with '__' [-Wreserved-identifier] note: expanded from macro 'os_log_error'
757904-
--
804937- 2388 | :218:1: warning: identifier '_pthread_priority_has_override_qos' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
804938-        } __R  218 | _pthread_priority_has_override_qos(pthread_priority_t peply__task_get_mp)
804939-      | ^
804940-sult.policy_id,
804941-       |                                     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
804942-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/pthread/priority_private.h:228:1/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1033:70: note: expanded from macro 'NECPLOG'
804943:a 1033 |             os_log_error:ch_vou(ne warning: identifier '_pthread_priority_make_from_thread_qos' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
804944-  228 | _pthread_cp_priority_make_from_thread_qos(thread_qos_t qos, int relpri,
804945-      | ^
804946-log_handle, "%s: " format "\n", __FUNC/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/pthread/priority_private.h:241:1: warning: identifier '_pthread_priority_make_from_sched_pri' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
804947-  241 | _pthrTIeaON__, __VA_ARGd_priority_make_from_sched_pri(int sched_pri, unsigneS_d long flags)
804948-      | ^
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
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sun Nov  8 04:34:09 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
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
16:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:1802:21: error: use of undeclared identifier 'timerTicks'
19:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:1804:51: error: use of undeclared identifier 'timerTicks'
22:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:1804:28: error: use of undeclared identifier 'native_ufs_read_ticks'
```

### around them

```
8-  260 |   at[0] = value >> 24; at[1] = value >> 16; at[2] = value >> 8; at[3] = value;
9-      |                                                                       ~ ^~~~~
10-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:657:54: warning: implicit conversion changes signedness: 'int' to 'unsigned long' [-Wsign-conversion]
11-  657 |       used += snprintf (text + used, sizeof (text) - used, "%u:%s %llx-%llx%s", index, name,
12-      |                                                    ~ ^~~~
13-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:661:44: warning: implicit conversion changes signedness: 'int' to 'unsigned long' [-Wsign-conversion]
14-  661 |     snprintf (text + used, sizeof (text) - used, "\nlisted=%u", listed);
15-      |                                          ~ ^~~~
16:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:1802:21: error: use of undeclared identifier 'timerTicks'
17- 1802 |       uint64_t t0 = timerTicks ();
18-      |                     ^
19:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:1804:51: error: use of undeclared identifier 'timerTicks'
20- 1804 |       __atomic_fetch_add (&native_ufs_read_ticks, timerTicks () - t0, __ATOMIC_RELAXED);
21-      |                                                   ^
22:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:1804:28: error: use of undeclared identifier 'native_ufs_read_ticks'
23- 1804 |       __atomic_fetch_add (&native_ufs_read_ticks, timerTicks () - t0, __ATOMIC_RELAXED);
24-      |                            ^
25-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:1921:72: warning: implicit conversion changes signedness: 'int' to 'unsigned long' [-Wsign-conversion]
26- 1921 |     used += snprintf (gRootMediaText + used, sizeof (gRootMediaText) - used,
27-      |                                                                      ~ ^~~~
28-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:1976:68: warning: operand of ? changes signedness: 'int' to 'uint32_t' (aka 'unsigned int') [-Wsign-conversion]
29- 1976 |     gRootDiagnostic.result = result.phase == UfsRootPhase::Start ? kIOReturnIOError : kIOReturnTimeout;
30-      |                            ~                                       ^~~~~~~~~~~~~~~~
31-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:157:34: note: expanded from macro 'kIOReturnIOError'
32-  157 | #define kIOReturnIOError         iokit_common_err(0x2ca) // General I/O error
33-      |                                  ^~~~~~~~~~~~~~~~~~~~~~~
34-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:136:71: note: expanded from macro 'iokit_common_err'
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
