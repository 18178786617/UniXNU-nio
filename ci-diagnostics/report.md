# Why the build failed

run: 54, commit 97e139ba5ae7a860b159de2b91f1b9b5fd6261b5

## kernel.log

### the errors

```
57821: 1041 |             os_log_error:(necp_log_handle, "%s: %s\n",     __FUN   \
66368:   (LO74 |         G_E   RR, os "D/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp_client.c_log_ATA-TRACE <%s>: ------ %smatching <%s> <value %s %s %s input %s error:8142:3: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
90135:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/percpu.h:291 1049 |         os_log_error:14:(ne warning: identifier '__percpu_section_end' is reserved because it starts with '__' [-Wreserved-identifier]cp_
164958:   1049 |         os_log232_error:  |         note: expanded from macro '__SAFE_CAST_PTR'
360883:Undefined symbols for architecture arm64:
360887:ld: symbol(s) not found for architecture arm64
360888:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
360889:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
360890:make[2]: *** [build_all] Error 2
360891:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
360892:make: *** [build] Error 2
```

### around them

```
57815- 1735g_v/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp_client.c:3170:erify_for | mat_str(format, ##__VA_stARGS_ruct __semwait_si7: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
57816-_);    3170 |                                 gnal_                NECnocanPLOG0cel_a(LOG_rgs {ERR, 
57817-      |        ^
57818-"Resolver tag       in   val /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/sysproto.h:1743:8        id le     ngth      for b     rowse result");
57819-      |                                                 ^
57820-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1041:6: note: expanded from macro 'NECPLOG0'
57821: 1041 |             os_log_error:(necp_log_handle, "%s: %s\n",     __FUN   \
57822-CTION      |                               ~~~~~~    ^~~~~~~~~~~
57823-__, msg);     warning: identifier '__mac_mount_args' is reserved because it starts with '__' [-Wreserved-identifier]
57824-         1743 |    str  \uct
57825-      |  __            ^
57826-mac_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c:7330mo/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396unt:5:_args {:3: warning: format specifies type 'int' but the argument has type 'u_int32_t' (aka 'unsigned int') [-Wformat]
57827- note: expanded from macro 'os_log_error'
57828- 
57829-      |   3967330 |        ^
57830- |     _                NECPSta_DAticTA__asTR/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/sysproto.h:ACE_L1751:8: warning: identifier '__mac_get_mount_args' is reserved because it starts with '__' [-Wreserved-identifier]
57831- 1751 | struct __mac_get_Omount_argsG_S {OCK
--
66362- na 1079 | me, val, "n/a        NE", TAG"n/ENTa",LOG in0(LputOG_, "DEBn/aUG,",  "R"n/egia")ste
66363-      | red    ^
66364- ne/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c:668:5:w a note: expanded from macro 'NECP_DATA_TRACE_LOG_CONDITION_STR3'gen
66365-  668 |  t")   ;
66366-      NEC|         ^
66367-PDAT/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.c:74ATR:6:ACE note: expanded from macro 'NETAGENTLOG0'LOG
66368:   (LO74 |         G_E   RR, os "D/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp_client.c_log_ATA-TRACE <%s>: ------ %smatching <%s> <value %s %s %s input %s error:8142:3: warning: '_Static_assert' is incompatible with C standards before C11 [-Wpre-c11-compat]
66369-(%s %s>", \
66370-OS_LOG_DEFAULT, "%s:      |     ^
66371- % 8142 |                 NECPLOG(LOG_ERR, "nes\n", __FUNCTION__/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.hcp_,:1051:2: msclient_list buffer copyout error (%d)", note: expanded from macro 'NECPDATATRACELOG'
66372- erro 1051 |         osg);r);
66373-      |                 ^
66374-  _log(necp_data/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1033:6: note: _t               \
66375-      |             ^
66376-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396:5: note: expanded from macro 'os_log_error'
66377-expanded from macro 'NECPLOG'
66378- 1033  396 | race_log_handle, "%s: " fo |              _Staticrma   os_log_e_ast "\n", __Frrosert(__builtin_constr(necant_p(format), "formaUNCTION__, __VA_ARGS__);       \
--
90129-      |     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
90130-  663 |                 caller, negate ? "!":"", naA", "__percme, val1,pu" va);
90131-l1,      |                     ^ va
90132-l2, val2, val3, val3, input1, input1, input2, input2, input3, input3); \
90133-      |                 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~
90134-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:77: note: expanded from macro 'NECPDATATRACELOG'
90135:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/percpu.h:291 1049 |         os_log_error:14:(ne warning: identifier '__percpu_section_end' is reserved because it starts with '__' [-Wreserved-identifier]cp_
90136-  291 |         extern chdatar a_t__prace_lercog_pu_handlesec, "tio%s:n_e " format "\nd[n",0]  ____SFUNCTIECTON_ION_, _EN__VD_SA_AYM(RGS__)"__; \DAT
90137-      | A",        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~
90138- "__percpu");
90139-      | /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:399                    ^
90140-:76: note: expanded from macro 'os_log_error'
90141-  399 |     _os_log_internal(&__dso_handle, log, OS_LOG_TYPE_ERROR, _os_log_fmt, ##__VA_ARGS__);        \
90142-      |                                                             ~~~~~~~~~~~    ^~~~~~~~~~~
90143-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c:8358:3: note: format string is defined here
90144- 8358 |                 NECP_DATA_TRACE_LOG_CONDITION(debug, "SOCKET", kernel_policy->condition_negated_mask & NECP_KERNEL_CONDITION_REMOTE_EMPTY,
90145-      |                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
--
164952-ch_or, |)
164953-      A|                                     ^
164954-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049ST_PTR(vola/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic_private_impl.h:232:2: note: expanded from macro '_os_atomic_c11_op'
164955-:77:tile long*,b)))
164956-      |                             ^
164957-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/OSAtomic.h:59:5 note: expanded from macro 'NECPDATATRACELOG'
164958:   1049 |         os_log232_error:  |         note: expanded from macro '__SAFE_CAST_PTR'
164959-(_os_ato   59 |         ({ _Static_assnecp_ert(sizeof(*(mdatvic_a_trace_log_handle, c11_op_ori"%s: g(p, _v, m, o) op _v; \
164960-      |         ^
164961-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic_private_impl.h:ar)) 224:6"== : note: expanded from macro '_os_atomic_c11_op_orig'
164962-  224 |         sizeo    _f(*(type)NULL),o format "\n", __FUNCTION__, __VA_ "size mismatch"); ((typeARGS_)(var)); })
164963-      |            ^_); \
164964-      |         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~
164965-s_atomic/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:399:76: note: expanded from macro 'os_log_error'
164966-  399 |     _os_
164967-_value_castlog_i(p, v), \
164968-      |             ^
--
360877-   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sun Nov  8 14:13:12 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
360878-      |            ^
360879-1 warning generated.
360880-             LD mach.development.bcm2837.unstripped
360881-ld: warning: -new_linker is obsolete
360882-ld: warning: search path '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot/usr/local/lib/kernel/platform' not found
360883:Undefined symbols for architecture arm64:
360884-  "PE_boot_args_raw()", referenced from:
360885-      OSKext::loadKextWithIdentifier(OSString*, OSObject**, bool, bool, unsigned char, unsigned char, OSArray*) in OSKext.cpo
360886-   NOTE: found '_PE_boot_args_raw' in pe_bootargs.o, declaration possibly missing 'extern "C"'
360887-ld: symbol(s) not found for architecture arm64
360888:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
360889-make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
360890-make[2]: *** [build_all] Error 2
360891-make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
360892-make: *** [build] Error 2
360893-build-xnu-4k-baseline.sh: line 829: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

### the tail

```
  181 | void __pthread_testcancel(int presyscall);
      |      ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/systm.h:236:16: warning: identifier '__throttle_info_handle' is reserved because it starts with '__' [-Wreserved-identifier]
  236 | typedef struct __throttle_info_handle *throttle_info_handle_t;
      |                ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/arm/systemcalls.c:203:2: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
  203 |         prior __assert_only = thread_set_allocation_name(NULL);
      |         ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/arm/systemcalls.c:258:2: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
  258 |         prior __assert_only = thread_set_allocation_name(NULL);
      |         ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/arm/systemcalls.c:296:23: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
  296 |         arm_saved_state32_t *ss32 = saved_state32(regs);
      |                              ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/arm/systemcalls.c:500:23: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
  500 |         arm_saved_state64_t *ss64 = saved_state64(regs);
      |                              ^
526 warnings generated.
451 warnings generated.
     LDFILELIST bsd
             CC version.o
clang: warning: no such include directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa' [-Wmissing-include-dirs]
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/version.c:39:12: warning: identifier '__kernelVersionString' is reserved because it starts with '__' [-Wreserved-identifier]
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sun Nov  8 14:13:12 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
      |            ^
1 warning generated.
             LD mach.development.bcm2837.unstripped
ld: warning: -new_linker is obsolete
ld: warning: search path '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot/usr/local/lib/kernel/platform' not found
Undefined symbols for architecture arm64:
  "PE_boot_args_raw()", referenced from:
      OSKext::loadKextWithIdentifier(OSString*, OSObject**, bool, bool, unsigned char, unsigned char, OSArray*) in OSKext.cpo
   NOTE: found '_PE_boot_args_raw' in pe_bootargs.o, declaration possibly missing 'extern "C"'
ld: symbol(s) not found for architecture arm64
clang++: error: linker command failed with exit code 1 (use -v to see invocation)
make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
make[2]: *** [build_all] Error 2
make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
make: *** [build] Error 2
build-xnu-4k-baseline.sh: line 829: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
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
nio-ufs: build/nio-ufs/libNioUfs.a -> build/sheng-ufs/libShengUfs.a (499600 bytes, sha256 e049e98fc53677044618bf336829a5015e2aae8cfb921c79f8900f010a94f025)
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
46162:d with error: 0x%x\n", err);
59137: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
59143: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
628095:  158 |                 printf("buffer_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
666050:      |           ^__((sectioocate memory. Error 0x%x\n", ret);
690179:        caller, nega/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/processor_set.h:305t272 |                 printf("zlib_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
701643:  188 |         voiat "mory. Error 0x%x\n", __func__, ret);
729035:   _log_error:4: warning: identifier '__Request__thread_terminate_t' is reserved because it starts with '__' [-Wreserved-identifier]
798337:            /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/zalloc_internal.h:os_l941:1og_error: note: expanded from here
864220:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_entry.h:162:19    os_log_error: warning: (necp_log_hanmixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
906079:   74 |             os_log_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/vm_statistics.h:455:7error: warning: identifier '__unused_bit_15' is reserved because it starts with '__' [-Wreserved-identifier]
907461:   74 |             os_log_error:
910950:g  180 | gere        } __d netagent /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/kalloc.h:1432from kernel (error %d)", error:2);
1158182:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/task.hn,error:127:
1189738: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
1189749: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
1189760: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
1189772: 1413 |                     "| error: latency %d too big (> 1 sec)",
1189784: 1420 |                     "| error: jitter %dms too big (latency %dms)",
1189795: 1420 |                     "| error: jitter %dms too big (latency %dms)",
1189806: 1438 |                     "| error: loss recovery %dms too big",
1189817: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
1189828: 1463 |                     "| error: output interval %dms too big",
1482629:the/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/netinet6/in6.h:163 traffic class: %d", error:4: warning: identifier '__u6_addr' is reserved because it starts with '__' [-Wreserved-identifier]
1484550:o get the close error: %d", error);
1489797:      |   n error:        ^
1552649:rnal error: "
1552892:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
1568061:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
1568073:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
1675328:   28ed with error: %d", err); | typedef unsigned int         
1989408:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/kern_event.c 1224 |                     __func__,:1621:10 error: warning: , ('_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
2045410:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/machine_cpu.h:3556 |         os_log_error:
2102606:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/smr.h error:999:1: warning: identifier '__smrq_serialized_remove' is reserved because it starts with '__' [-Wreserved-identifier]
2291901: 1058c |                 kfree_type(ps error: %d, kcdata error: %d, length: %ld)\n",
2717114:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/kauth.h  189 | __add_64(error:745:
2772471:Undefined symbols for architecture arm64:
2772483:ld: symbol(s) not found for architecture arm64
2772484:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
2772485:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
```

### around them

```
46156-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/turnstile.h:350: 1024ULL)), err2: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
46157-);
46158-      |                                                                                   ^~~
46159-  350 |         _Atomic uint32_t              ts_type_gencount;      /* gen cou/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1364:76: warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
46160-nt used for 1364 |                 IO priority cLog("IOPollhaining (ILedFilePollersSe), type of tup for corturnstile (efile faileIL) */
46161-      |         ^
46162:d with error: 0x%x\n", err);
46163-      |                                                                                   ~~     ^~~
46164-      |                                                                                   %x
46165-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:77:
46166-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/mount_internal.h:85:
46167-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/vfs_context.h:9:
46168-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/user.h:89:
46169-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/eventvar.h:71:
46170-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/pthread/workqueue_internal.h:226:22: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
46171-  226 |         workq_state_flags_t _Atomic wq_flags;
46172-      |                             ^
--
59131- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
59132-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
59133-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
59134-  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
59135-      |                 ~~               ^~~~~~~~~~~
59136-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
59137: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
59138-      |                                                                                ~~~
59139-      |                                                                                %zu
59140- 1414 |                                             path, mc_error, fatal_failure_desc_len);
59141-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
59142-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
59143: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
59144-      |                                                                                                   ~~~
59145-      |                                                                                                   %zu
59146- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
59147-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
59148-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
59149- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
59150-      |                             ^
59151-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
59152- 1426 |                 zfree(ZV_NAMEI, vn_path);
59153-      |                 ^
--
729029-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/locks.h:
729030- 1049: |         o49:
729031-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/system.h:41:
729032-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_interface.h:46:
729033-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/thread_act.h:501s40:
729034-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/lock_group.h:53:16: warning: identifier '_lck_grp_' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
729035:   _log_error:4: warning: identifier '__Request__thread_terminate_t' is reserved because it starts with '__' [-Wreserved-identifier]
729036-53  501 |         } | t(ne __Request__thread_cp_daypedef struct _lck_grp_      ta_tra  lcterk_grp_t;
729037-      ce_log_hmiandle|                ^
729038-,/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/lock_group.h:67:16: warning: identifier '_lck_grp_attr_' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
729039-   67 | typnatee_t __attribdef strucute__((unu "%seds: " fo))t _lck_grp_attr_ rmat;
729040-      |   lck _grp_attr_t;"\n", __F          ^
729041-UNCTION
729042-      |                ^
729043-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/thread_act.h:514:4: warning: identifier '__Request__act_get_state_t' is reserved because it starts with '__' [-Wreserved-identifier]
729044-__, __VA_ARGS__)  514 |         } __Requ/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/lock_group.h:139:est__act_get_state_t __attribute__((unused));
729045-      |           ^
--
798331-sName
798332- ## _Methods  /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1033                      :43               \
798333-      |     ^
798334-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_object.c:82:
798335-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/zalloc_internal.h:: note: expanded from macro 'NECPLOG'
798336-<scratch space> 950:3: :130:1033 | warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
798337:            /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/zalloc_internal.h:os_l941:1og_error: note: expanded from here
798338-(  130 | 17: note: expanded from macro '__ZALLOC_RO_MUT_OP'
798339-  941 |                 reIOUsnecp_logturn os_atoer_Server_Methods
798340-      handle, "%s: mi" format "\n", _c_#_FU#op2| (NCTI(uin^
798341-ON__, __VA_ARGS__); \
798342-      |                                                  ^~~~~~
798343-t8_t./DriverKit/IOUserServer.h:108:5: note: expanded from macro 'IOUserServer_Methods'
798344-  108 |   /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:  _Dispatch(IOUserS397:erver * self, const83: IORPC rpc);\
798345-      |     ^
798346- note: expanded from macro 'os_log_error'
798347- *)dst, (uint8_t)value, seq_cst); \
--
864214-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1033:6: note: expanded from macro 'NECPLOG'
864215- In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/mach_kernelrpc.c:31:
864216-In file included from ./mach/mach_vm_server.h:62:
864217-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/ipc_kobject.h:77:
864218-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_port.h:91:
864219-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_space.h:921033 |         :
864220:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/ipc/ipc_entry.h:162:19    os_log_error: warning: (necp_log_hanmixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
864221-dle, "%s: " form  162 | at         ipc_e"\nntr", y_b__FitsUNCTION__, ___t VA_newARGgenS__ = ); IE_\
864222-      |             ^
864223-BITS/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396_GE:5:N_M note: expanded from macro 'os_log_error'ASK
864224-  396 |   +    IE__StBITatiS_Gc_assert(__buEN_iltONEin_;
864225-      con|                          ^
864226-stant_p(format), "format string must be constaIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Tests/TestIOMemoryDescriptor.cpp:55:
864227-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/sysctl.h:95:
864228-In file included from nt");     /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/proc.h:77   :
864229-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/param.h:116:
864230-   /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/ucred.h:110  \
--
906073-as/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/vm_statistics.h:453:7: warning: identifier '__unused_bit_13' is reserved because it starts with '__' [-Wreserved-identifier]
906074-  453 |          no agent");
906075-      |                 ^
906076-            __unused_b/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.c:74:6: note: expanded from macro 'NETAGENTLOG0'
906077-it_13:1,
906078-      |                     ^
906079:   74 |             os_log_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/vm_statistics.h:455:7error: warning: identifier '__unused_bit_15' is reserved because it starts with '__' [-Wreserved-identifier]
906080-(OS_LOG_DEFAULT, "  455 |         %s: %            __unused_bit_15:1,
906081-      |                     ^
906082-s\n", __/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/vm_statistics.h:458:7: FUNCTION__, msg);               warning: identifier '__unused_bit_19' is reserved because it starts with '__' [-Wreserved-identifier]
906083-  458 |                       \
906084-      |             ^
906085-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396:5: note: expanded from macro 'os_log_error'
906086-  __un396 |  used_bit_19:1,
906087-         _St|                     ^
906088-atic_assert(__builtin_constant_p(forma/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/vm_statistics.h:460:7t),: warning:  "fidentifier '__unused_bit_21' is reserved because it starts with '__' [-Wreserved-identifier]
906089-ormat string   460 | mus                    __unused_bit_21:1,
--
907455-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.c:74:_p/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStatistics.cpp:29:
907456-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/sysctl.h:95:
907457-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/proc.h:74:
907458-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/select.h:112:
907459-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/waitq.hqu:32:
907460-In file included from 6: note: eue_overloadable extern/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_types.h:80expanded from macro 'NETAGENTLOG0'
```

### the tail

```
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
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Sun Nov  8 14:11:31 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
      |            ^
1 warning generated.
             LD mach.development.bcm2837.unstripped
ld: warning: -new_linker is obsolete
ld: warning: search path '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot/usr/local/lib/kernel/platform' not found
Undefined symbols for architecture arm64:
  "PE_boot_args_raw()", referenced from:
      OSKext::loadKextWithIdentifier(OSString*, OSObject**, bool, bool, unsigned char, unsigned char, OSArray*) in OSKext.cpo
   NOTE: found '_PE_boot_args_raw' in pe_bootargs.o, declaration possibly missing 'extern "C"'
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
patch    68 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-security-extensions.patch
patch    69 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-trust-cache-without-security-extensions.patch
patch    70 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kext-data-const-stays-writable.patch
patch    71 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kernel-data-const-stays-writable.patch
patch    72 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-image4-kext.patch
patch    73 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-port-command-line.patch
patch    74 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-boot-args-fallback.patch
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
