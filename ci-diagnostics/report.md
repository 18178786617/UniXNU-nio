# Why the build failed

run: 166, commit 1918a43807538b1ea00f196b3bd7897bfaebd5ff

## archive-08-build-libpthread-kernel.log

### the errors

```
6:  /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/source_pthread_bootstrap.c:13:2: error: call to undeclared function 'printf'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]
18:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/source_pthread_bootstrap.c:13:2: error: call to undeclared function 'printf'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]
```

### around them

```
1-Cloning into '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/libpthread-work'...
2-this XNU tree calls proc_get_pthread_jit_allowlist what the sources call proc_get_jit_entitled
3-source_pthread_bootstrap.c: the compile failed
4-command: /Applications/Xcode_26.3.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang -xc /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/source_pthread_bootstrap.c -o /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/libpthread-kernel/source_pthread_bootstrap.o -c -g -nostdinc -ferror-limit=10000 -fno-builtin -fno-common -ftrivial-auto-var-init=zero -fsigned-bitfields -fmerge-all-constants -fno-c++-static-destructors -fsanitize-minimal-runtime -fsanitize-ignorelist=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/san/kasan-blacklist-arm64 -fsanitize=signed-integer-overflow -D ARM64_BOARD_CONFIG_BCM2837 -arch arm64 -D arm64 -D ARM64 -D __ARM64__ -D LP64 -D PAGE_SIZE_FIXED -D VM_KERNEL_LINK_ADDRESS=0xfffffff007004000 -U ARM_LARGE_MEMORY -momit-leaf-frame-pointer -fno-strict-aliasing -D __API__=v4 -mkernel -O2 -mios-version-min=17.0 -D XNU_TARGET_OS_IOS -D XNU_PLATFORM_iPhoneOS -D APPLE -D KERNEL -D KERNEL_PRIVATE -D XNU_KERNEL_PRIVATE -D PRIVATE -D __MACHO__=1 -D volatile=__volatile -D XNU_KERN_EVENT_DATA_IS_VLA -D CURRENT_MACHINE_CONFIG_LC=bcm2837 -D INET -D MACH -D IF_FAKE -D IF_HEADLESS -D AH_ALL_CRYPTO -D PF -D DUMMYNET -D TRAFFIC_MGT -D MULTICAST -D MULTIPATH -D MPTCP -D PSYNCH -D FLOW_DIVERT -D NECP -D CONTENT_FILTER -D PACKET_MANGLER -D SKYWALK -D CONFIG_NEXUS_USER_PIPE -D CONFIG_NEXUS_KERNEL_PIPE -D CONFIG_NEXUS_MONITOR -D CONFIG_NEXUS_FLOWSWITCH -D CONFIG_NEXUS_NETIF -D SOCKETS -D NETWORKING -D CONFIG_FSE -D CONFIG_IMAGEBOOT -D FIFO -D FDESC -D DEVFS -D ROUTEFS -D BINDFS -D FS_COMPRESSION -D NAMEDSTREAMS -D CONFIG_MNT_ROOTSNAP -D CONFIG_UNION_MOUNTS -D NFSSERVER -D CONFIG_NETBOOT -D IPSEC -D IPSEC_ESP -D CRYPTO_SHA2 -D ZLIB -D IF_BRIDGE -D CONFIG_KN_HASHSIZE=48 -D CONFIG_NC_HASH=2048 -D CONFIG_VFS_NAMES=3072 -D CONFIG_MAX_CLUSTERS=4 -D CONFIG_MIN_NBUF=80 -D CONFIG_MIN_NIOBUF=64 -D CONFIG_NMBCLUSTERS=((1024 * 256) / MCLBYTES) -D CONFIG_TCBHASHSIZE=128 -D CONFIG_AIO_MAX=20 -D CONFIG_AIO_PROCESS_MAX=8 -D CONFIG_AIO_THREAD_COUNT=2 -D CONFIG_MAXVIFS=16 -D CONFIG_MFCTBLSIZ=128 -D CONFIG_MSG_BSIZE_REL=16384 -D CONFIG_MSG_BSIZE_DEV=131072 -D CONFIG_MSG_BSIZE=CONFIG_MSG_BSIZE_DEV -D CONFIG_IPC_TABLE_ENTRIES_SIZE_MAX=3145728 -D CONFIG_IPC_TABLE_REQUEST_SIZE_MAX=1048576 -D CONFIG_IPC_KERNEL_MAP_SIZE=32 -D CONFIG_EMBEDDED -D CONFIG_PMAP_PPL -D NOS_ARM_ASM -D NOS_ARM_PMAP -D CONFIG_DYNAMIC_CODE_SIGNING -D CONFIG_ENFORCE_LIBRARY_VALIDATION -D CONFIG_CODE_DECRYPTION -D CONFIG_PROTECT -D CONFIG_MEMORYSTATUS -D CONFIG_JETSAM -D CONFIG_FREEZE -D CHECK_CS_VALIDATION_BITMAP -D CONFIG_PHANTOM_CACHE -D VM_PRESSURE_EVENTS -D CONFIG_SECLUDED_MEMORY -D CONFIG_IOSCHED -D CONFIG_IO_ACCOUNTING -D IMPORTANCE_TRACE -D CONFIG_TELEMETRY -D CONFIG_PROC_UUID_POLICY -D CONFIG_COREDUMP -D CONFIG_VNGUARD -D IOKITCPP -D IOKITSTATS -D IOTRACKING -D CONFIG_SLEEP -D CONFIG_MAX_THREADS=500 -D NO_KERNEL_HID -D LIBKERNCPP -D CONFIG_BLOCKS -D CONFIG_KEC_FIPS -D CONFIG_PERSONAS -D CONFIG_MACF -D CONFIG_MACF_SOCKET_SUBSET -D CONFIG_SETUID -D CONFIG_SECURE_BSD_ROOT -D CONFIG_KAS_INFO -D CONFIG_ZLEAKS -D KPERF -D KPC -D CONFIG_IOTRACE -D PGO -D DEVELOPMENT -D MACH_BSD -D IOKIT -D CONFIG_THREAD_MAX=1536 -D CONFIG_TASK_MAX=512 -D CONFIG_ZONE_MAP_MIN=120586240 -D CONFIG_VC_PROGRESS_WHITE -D CONFIG_SCHED_TRADITIONAL -D CONFIG_SCHED_MULTIQ -D CONFIG_SCHED_TIMESHARE_CORE -D CONFIG_CLUTCH -D CONFIG_PROB_GZALLOC -D CONFIG_SCHED_DEFERRED_AST -D CONFIG_KDP_INTERACTIVE_DEBUGGING -D CONFIG_TASKWATCH -D CONFIG_XNUPOST -D PROC_REF_DEBUG -D CONFIG_ATM -D CONFIG_COALITIONS -D CONFIG_SYSDIAGNOSE -D SERIAL_CONSOLE -D VIDEO_CONSOLE -D CONFIG_REQUIRES_U32_MUNGING -D CONFIG_MACH_BRIDGE_RECV_TIME -D CONFIG_SERVICE_PORT_INFO -D ALTERNATE_DEBUGGER -D CONFIG_VNODES=1024 -D CONFIG_FREEZE_SUSPENDED_MIN=4 -D CONFIG_MACH_APPROXIMATE_TIME -D CONFIG_KERNEL_INTEGRITY -D CONFIG_UBSAN_MINIMAL -include meta_features.h -D MACH_KERNEL_PRIVATE -D MACH_KERNEL -Weverything -Wundef-prefix=TARGET_OS_ -Wundef-prefix=LCK_GRP_USE_ARG -Wno-pedantic -Wno-bad-function-cast -Wno-bitwise-instead-of-logical -Wno-c++-compat -Wno-c++98-compat -Wno-conditional-uninitialized -Wno-covered-switch-default -Wno-disabled-macro-expansion -Wno-documentation-unknown-command -Wno-extra-semi-stmt -Wno-format-non-iso -Wno-language-extension-token -Wno-missing-variable-declarations -Wno-packed -Wno-padded -Wno-partial-availability -Wno-reserved-id-macro -Wno-shift-sign-overflow -Wno-switch-enum -Wno-unaligned-access -Wno-undef -Wno-unused-macros -Wno-used-but-marked-unused -Wno-variadic-macros -Wno-vla -Wno-zero-length-array -Wno-unknown-warning-option -Wno-anon-enum-enum-conversion -Wno-error=enum-enum-conversion -Wno-error=c99-designator -Wno-error=reorder-init-list -Wno-error=declaration-after-statement -Wno-sign-compare -Wno-sign-conversion -Wpointer-arith -Wxnu-typed-allocators -Wshorten-64-to-32 -U XNU_SOURCE_CORECRYPTO14 -Wno-sign-conversion -I . -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/iokit -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/pexpert -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/san -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/libsa -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot/usr/local/include/kernel -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot/usr/local/include -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot//System/Library/Frameworks/Kernel.framework/Versions/A/PrivateHeaders/platform -Wno-reorder-init-list -Wno-implicit-int-float-conversion -Wno-c99-designator -Wno-final-dtor-non-final-class -Wno-extra-semi-stmt -Wno-misleading-indentation -Wno-quoted-include-in-framework-header -Wno-implicit-fallthrough -Wno-enum-enum-conversion -Wno-enum-float-conversion -Wno-elaborated-enum-base -Xclang -clang-vendor-feature=+disableNonDependentMemberExprInCurrentInstantiation -Xclang -fno-odr-hash-protocols -Xclang -clang-vendor-feature=+enableAggressiveVLAFolding -Xclang -clang-vendor-feature=+revert09abecef7bbf -Xclang -clang-vendor-feature=+thisNoAlignAttr -Xclang -clang-vendor-feature=+thisNoNullAttr -Xclang -clang-vendor-feature=+disableAtImportPrivateFrameworkInImplementationError -mlinker-version=1230.1 --target=arm64-apple-ios17.0.0
5-1 errors; the first ones:
6:  /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/source_pthread_bootstrap.c:13:2: error: call to undeclared function 'printf'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]
7-__ovr = os_add_overflow(in, (__typeof__(*out))PAGE_MASK, out); \
8-      |                      ^
9-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/vm_param.h:442:6: warning: identifier '__ovr' is reserved because it starts with '__' [-Wreserved-identifier]
10-  442 |         if (round_page_overflow(x, &x)) {
11-      |             ^
12-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/vm_param.h:126:15: note: expanded from macro 'round_page_overflow'
13-  126 |                 bool __ovr = os_add_overflow(in, (__typeof__(*out))PAGE_MASK, out); \
14-      |                      ^
15-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/vm_param.h:607:14: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
16-  607 |         vm_offset_t ptr = params.vmpp_base +
17-      |                     ^
18:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/source_pthread_bootstrap.c:13:2: error: call to undeclared function 'printf'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]
19-   13 |         printf("nio: %02u\n", 1);
20-      |         ^
21-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/source_pthread_bootstrap.c:14:21: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
22-   14 |         static kmod_info_t info = {
23-      |                            ^
24-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/source_pthread_bootstrap.c:24:1: warning: identifier '__startup_EARLY_BOOT_entry_source_pthread_bootstrap_24' is reserved because it starts with '__' [-Wreserved-identifier]
25-   24 | STARTUP(EARLY_BOOT, STARTUP_RANK_SECOND, source_pthread_bootstrap);
26-      | ^
27-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.h:195:2: note: expanded from macro 'STARTUP'
28-  195 |         __STARTUP(func, __LINE__, subsystem, rank, func)
```

### the tail

```
  607 |         vm_offset_t ptr = params.vmpp_base +
      |                     ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/source_pthread_bootstrap.c:13:2: error: call to undeclared function 'printf'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]
   13 |         printf("nio: %02u\n", 1);
      |         ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/source_pthread_bootstrap.c:14:21: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
   14 |         static kmod_info_t info = {
      |                            ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/source_pthread_bootstrap.c:24:1: warning: identifier '__startup_EARLY_BOOT_entry_source_pthread_bootstrap_24' is reserved because it starts with '__' [-Wreserved-identifier]
   24 | STARTUP(EARLY_BOOT, STARTUP_RANK_SECOND, source_pthread_bootstrap);
      | ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.h:195:2: note: expanded from macro 'STARTUP'
  195 |         __STARTUP(func, __LINE__, subsystem, rank, func)
      |         ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.h:733:2: note: expanded from macro '__STARTUP'
  733 |         __STARTUP1(name, line, subsystem, rank, func, , NULL)
      |         ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.h:727:2: note: expanded from macro '__STARTUP1'
  727 |         __startup_ ## subsystem ## _entry_ ## name ## _ ## line = { \
      |         ^
<scratch space>:589:1: note: expanded from here
  589 | __startup_EARLY_BOOT_entry_source_pthread_bootstrap_24
      | ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/source_pthread_bootstrap.c:24:1: warning: cast from 'void (*)(void)' to 'typeof (source_pthread_bootstrap()) (*)(const void *)' (aka 'void (*)(const void *)') converts to incompatible function type [-Wcast-function-type-strict]
   24 | STARTUP(EARLY_BOOT, STARTUP_RANK_SECOND, source_pthread_bootstrap);
      | ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.h:195:2: note: expanded from macro 'STARTUP'
  195 |         __STARTUP(func, __LINE__, subsystem, rank, func)
      |         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.h:733:2: note: expanded from macro '__STARTUP'
  733 |         __STARTUP1(name, line, subsystem, rank, func, , NULL)
      |         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.h:729:12: note: expanded from macro '__STARTUP1'
  729 |             rank, __STARTUP_FUNC_CAST(func, a), b, \
      |                   ^~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.h:720:6: note: expanded from macro '__STARTUP_FUNC_CAST'
  720 |             (typeof(func(a))(*)(const void *))func
      |             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
135 warnings and 1 error generated.

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
51439: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
57752: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
57758: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
492034:  116 | se(el      em), __kfree_size);           158 |                 pri_Di ntf("buffer_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
511367:  268 |                 printf("(%s) Failed to handle availability of LZ4. Error 0x%x\n", __func__, ret);
539663:  102 |                 printf("progress_notify_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
551548:  272 |                 printf("zlib_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
770878:        atomic_add_64(&ifp- 2164 |         OSDe>if_data.ifi_oerrors, error:81:43: note: expanded from macro 'os_cast_to_nonatomic_pointer'
820758: ool  _darwin_mbst c/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.hareate failed, error:te_t;     /555  *  %d\n" /, m_:* [???] Used fo_func__, err);
904319:  696 |                   /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_map.h:11581049 |         os_log_error: (necp_data_trace_log_handle, "%s: " format "\n", __FUNCTION__, __VA_ARGS__); \
927226:t)       ato/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h  os_log_error:mic( warning: _uint_fast8_t;
944297:4FILT   error:82(OS_LOG_DEFAULT, "%s: %s\n", __FUNCTION__, msg);       | typE  eRwarning: d_ identifier '__Reply__task_set_emulation_vector_t' is reserved because it starts with '__' [-Wreserved-identifier]T   
975278:  113 | __NDR_convert__mig_reply_error:4: warning: identifier '__Reply__task_get_special_port_t' is reserved because it starts with '__' [-Wreserved-identifier]
977244:  283 | typedef struct __SC_Gene/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.hlog_error:ricBlob {
982681: 1049 |         os_log_error:= 0;       38(  :
1048435:__at 1049 | /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.htribu        os_log_error:te330o(:9: fnnote: expanded from macro 'IOMallocType'
1049977:1061 |         } am 1033 |             os_log_error:e_t __R879__attrib(:2eq: warning: uuteeidentifier '_CopyState_Invoke' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]
1325158:on_port      |  s        error: co_t __i            ^
1325224:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/smr.hOG(L :9171216 |         } : __Request_ OG_E 1RR:_ta, "| error: duplicas   warning: identifier '__smrq_serialized_remove_one' is reserved because it starts with '__' [-Wreserved-identifier]tk_ipo
1325297:t 1420 |                     "| error: ask_zj/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/smr.h:1068:1: warning: identifier '__smrq_serialized_append' is reserved because it starts with '__' [-Wreserved-identifier]
1325349:nm |                     "| error: jitter %dms too big (latency %dms)",
1325364:tic_ 1438 |                     "| error: loss reattribute__((unused));
1325405: 1456zeRequest__task_s_timeeof(*(type)NULL), "size mi |                 NETEM_LOGsout_(LOuspenmatchdt;"); ((typ2G_ER_t __attR, "| error: reor
1325463: 1090 | __zalloc_  "| error: output p
1503452:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/timer_call.h:56overloadabldete ea TLV: %d", error:
1506907:LOG(LOG_ERR, fd_cb, "failed to get the close error: %e, subsystem, rank, func, arg, arg)d/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/skywalk/nexus_common.h:408:1: warning: identifier '__nexus_bind_req_prepare' is reserved because it starts with '__' [-Wreserved-identifier]
1539451:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
1539881:_DEBUG, "ah6_output: internal error: "
1554189:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
1554221:  321 |                         ipseclog((LOG_DEBU/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic_private_impl.h:224:6: note: G, "esp6_output: internal error: "
1659066: with error: %d", err);
2295417: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
2295423: 3383 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
2772533:Undefined symbols for architecture arm64:
2772542:ld: symbol(s) not found for architecture arm64
2772543:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
2772544:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
2772545:make[2]: *** [build_all] Error 2
2772546:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
2772547:make: *** [build] Error 2
```

### around them

```
51433-      |                     ^
51434-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:162:2: note: expanded from macro 'DTRACE_MACF2'
51435-  162 |         DTRACE_PROBE2(__sdt_, name, arg1, arg2);
51436-      |         ^
51437-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:128:29: note: expanded from macro 'DTRACE_PROBE2'
51438-  128 |                 register uintptr_t __dtrace_a1 asm("x1/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1364:76: warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
51439: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
51440-      |                                                                                   ~~     ^~~
51441-      |                                                                                   %x
51442-") = (uintptr_t) arg1;                    \
51443-      |                                    ^
51444-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:419:2: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
51445-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:266:18: note: expanded from macro 'MAC_CHECK'
51446-  266 |                     int __step_err = mpc->mpc_ops->mpo_ ## check (args); \
51447-      |                         ^
51448-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:419:2: warning: identifier '__dtrace_a0' is reserved because it starts with '__' [-Wreserved-identifier]
51449-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:265:14: note: expanded from macro 'MAC_CHECK'
--
57746- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
57747-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
57748-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
57749-  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
57750-      |                 ~~               ^~~~~~~~~~~
57751-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
57752: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
57753-      |                                                                                ~~~
57754-      |                                                                                %zu
57755- 1414 |                                             path, mc_error, fatal_failure_desc_len);
57756-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
57757-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
57758: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
57759-      |                                                                                                   ~~~
57760-      |                                                                                                   %zu
57761- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
57762-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
57763-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
57764- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
57765-      |                             ^
57766-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
57767- 1426 |                 zfree(ZV_NAMEI, vn_path);
57768-      |                 ^
--
770872-      |                    ^
770873- 1882 |         _e,            \
770874-      |         ^
770875-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/atomic.hserialized_replace(
770876-      | ^
770877-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.h:2164:2: note: expanded from macro 'OSDefineMetaClassAndStructorsWithInit'
770878:        atomic_add_64(&ifp- 2164 |         OSDe>if_data.ifi_oerrors, error:81:43: note: expanded from macro 'os_cast_to_nonatomic_pointer'
770879-s_fineDefaultStructors(classNam   81 | #defiout);
770880-      |                 ^
770881-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/mcache.h:86:10: note: expanded from macro 'atomic_add_64'
770882-   86 |         ((ve, superclone o/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/smr.hassNams_cast_to_nonatomic_pointer(p):1035:1: warning: identifier '__smrq_serialized_replace' is reserved because it starts with '__' [-Wreserved-identifier]
770883- i 1035 | __smrq_seriaed)  li)(os_a
770884-zed_re      atomic_add_64_ov(a, n))
770885-      |                 ^
770886-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/mcache.h:83:15: note: expanded from macro 'atomic_add_64_ov'
770887-|         ^
770888-   place(
--
820752-: 1973 |     59 | twarning:                 oyidentifier '__darwin_ino_t' is reserved because it starts with '__' [-Wreserved-identifier]
820753-   67 | tsp
820754-y_e      |                                     ^
820755-p/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.h:dle1337edef f o__uint32_t    :g_er _2 _mb__ds: warning: ratato'~OSMetaClass' overrides a destructor but is not marked 'override' [-Wsuggest-destructor-override]rwin_r
820756- 1337e( | OS_L_        ~OSMettOG_D aCE iFAULT, n  "o_ %t;sl ass(         ) _;pbufb 
820757-      |         ^
820758: ool  _darwin_mbst c/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.hareate failed, error:te_t;     /555  *  %d\n" /, m_:* [???] Used fo_func__, err);
820759-r b2inodes */
820760-      |                         ^
820761-      |                 ^
820762-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/_types.h:69:28: warning: identifier '__darwin_mach_port_name_t' is reserved because it starts with '__' [-Wreserved-identifier]
820763-: note: overridden virtual function is here
820764-  555 |         ~OSMetaClassBase();
820765-      |         ^
820766-   /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.hs69 | type/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.htate_t */
820767-      |                                 ^
820768-def __darwin_natural_t __darwin_mach_:396:5: note: expanded from macro 'os_log_error'
--
904313-      |                                                                                 ^
904314-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/priority_queue.h:720
904315-
904316-:1: warning: identifier '_priority_queue_remove_root' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
904317-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/priority_queue.h:      |           ^
904318-696:81: note: expanded from macro 'PRIORITY_QUEUE_MAKE'
904319:  696 |                   /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_map.h:11581049 |         os_log_error: (necp_data_trace_log_handle, "%s: " format "\n", __FUNCTION__, __VA_ARGS__); \
904320-      |         ^
904321-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396:5: note: expanded from macro 'os_log_error'
904322-  396 |     _Static_assert(__builtin_constant_p(format), "format string must be constant");             \
904323-      |     ^
904324-                                                              \
904325-      |                                                                                 ^
904326-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/priority_queue.h:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c4: warning: identifier '__Reply__vm_msync_t' is reserved because it starts with '__' [-Wreserved-identifier]
904327- 1158 |         } __Reply__vm_msync_t __attribute__((unused));
904328-      |           ^
904329-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_map.h:1170:4: warning: identifier '__Reply__vm_behavior_set_t' is reserved because it starts with '__' [-Wreserved-identifier]
--
927220-"DATA-TRACE <%s>: ------ %smatching <%s>/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:1061:4: warning: identifier '__Request__mach_port_get_context_t' is reserved because it starts with '__' [-Wreserved-identifier]
927221- 1061 |             :121:9: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]} __Request__mach_por
927222-<value (64 | t  121 | typedef _Atomic(uint_fast        _get_context_t %d / 0x%X) (%d / 0x%X__attribute__((unused));
927223-      |           ^
927224-) (%d / 0x%X) input (%d / 0x%X) (%d / 0x /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:1074:4% 8_X) (%d / 0x%X)>", \
927225-      |                                                                                                                                 ^~
927226:t)       ato/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h  os_log_error:mic( warning: _uint_fast8_t;
927227-      |         ^
927228-OS_L/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdatomic.h:122:9: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
927229-OG_DE:1049:50: note: expanded from macro 'NECPDATATRACELOG'
927230-Fidentifier '__Request__mach_port_set_context_t' is reserved because it starts with '__' [-Wreserved-identifier]
927231- 1074 |         } __Request__mac A  122 | typedef _Atomic(int_ULT, "%s: " formah_port_set_context_t __attribute__((unused));
927232-      |           ^
927233-1049 |         os_log_error(necp_data_trace_log_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_port.h:1086:4: warning: identifier '__Request__mach_port_kobject_t' is reserved because it starts with '__' [-Wreserved-identifier]
927234- 1086t "\nhf |         } __Request__machast16_t)       atomic_int_fas"_and, __FUNCTIOtlport_kobN__, __VA_ARGS__); \
927235-      |             ^
927236-e, "%s: " format "\n", _/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396:5: note: expanded from macro 'os_log_error'
--
944291-d));
944292-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.c:74:6: O      |           ^
944293- va_list */
944294-      |                                 ^
944295-N_PA/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/arm/_types.hCK/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:2216:note: :82:33: warning: Eexpanded from macro 'NETAGENTLOG0'
944296-   74 |             os_log_T_identifier '__darwin_wchar_t' is reserved because it starts with '__' [-Wreserved-identifier]
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
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Thu Nov 12 05:48:30 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
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

## build-libpthread-kernel_compile-errors.log

### the errors

```
4:  /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/source_pthread_bootstrap.c:13:2: error: call to undeclared function 'printf'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]
```

### around them

```
1-source_pthread_bootstrap.c: the compile failed
2-command: /Applications/Xcode_26.3.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang -xc /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/source_pthread_bootstrap.c -o /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/libpthread-kernel/source_pthread_bootstrap.o -c -g -nostdinc -ferror-limit=10000 -fno-builtin -fno-common -ftrivial-auto-var-init=zero -fsigned-bitfields -fmerge-all-constants -fno-c++-static-destructors -fsanitize-minimal-runtime -fsanitize-ignorelist=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/san/kasan-blacklist-arm64 -fsanitize=signed-integer-overflow -D ARM64_BOARD_CONFIG_BCM2837 -arch arm64 -D arm64 -D ARM64 -D __ARM64__ -D LP64 -D PAGE_SIZE_FIXED -D VM_KERNEL_LINK_ADDRESS=0xfffffff007004000 -U ARM_LARGE_MEMORY -momit-leaf-frame-pointer -fno-strict-aliasing -D __API__=v4 -mkernel -O2 -mios-version-min=17.0 -D XNU_TARGET_OS_IOS -D XNU_PLATFORM_iPhoneOS -D APPLE -D KERNEL -D KERNEL_PRIVATE -D XNU_KERNEL_PRIVATE -D PRIVATE -D __MACHO__=1 -D volatile=__volatile -D XNU_KERN_EVENT_DATA_IS_VLA -D CURRENT_MACHINE_CONFIG_LC=bcm2837 -D INET -D MACH -D IF_FAKE -D IF_HEADLESS -D AH_ALL_CRYPTO -D PF -D DUMMYNET -D TRAFFIC_MGT -D MULTICAST -D MULTIPATH -D MPTCP -D PSYNCH -D FLOW_DIVERT -D NECP -D CONTENT_FILTER -D PACKET_MANGLER -D SKYWALK -D CONFIG_NEXUS_USER_PIPE -D CONFIG_NEXUS_KERNEL_PIPE -D CONFIG_NEXUS_MONITOR -D CONFIG_NEXUS_FLOWSWITCH -D CONFIG_NEXUS_NETIF -D SOCKETS -D NETWORKING -D CONFIG_FSE -D CONFIG_IMAGEBOOT -D FIFO -D FDESC -D DEVFS -D ROUTEFS -D BINDFS -D FS_COMPRESSION -D NAMEDSTREAMS -D CONFIG_MNT_ROOTSNAP -D CONFIG_UNION_MOUNTS -D NFSSERVER -D CONFIG_NETBOOT -D IPSEC -D IPSEC_ESP -D CRYPTO_SHA2 -D ZLIB -D IF_BRIDGE -D CONFIG_KN_HASHSIZE=48 -D CONFIG_NC_HASH=2048 -D CONFIG_VFS_NAMES=3072 -D CONFIG_MAX_CLUSTERS=4 -D CONFIG_MIN_NBUF=80 -D CONFIG_MIN_NIOBUF=64 -D CONFIG_NMBCLUSTERS=((1024 * 256) / MCLBYTES) -D CONFIG_TCBHASHSIZE=128 -D CONFIG_AIO_MAX=20 -D CONFIG_AIO_PROCESS_MAX=8 -D CONFIG_AIO_THREAD_COUNT=2 -D CONFIG_MAXVIFS=16 -D CONFIG_MFCTBLSIZ=128 -D CONFIG_MSG_BSIZE_REL=16384 -D CONFIG_MSG_BSIZE_DEV=131072 -D CONFIG_MSG_BSIZE=CONFIG_MSG_BSIZE_DEV -D CONFIG_IPC_TABLE_ENTRIES_SIZE_MAX=3145728 -D CONFIG_IPC_TABLE_REQUEST_SIZE_MAX=1048576 -D CONFIG_IPC_KERNEL_MAP_SIZE=32 -D CONFIG_EMBEDDED -D CONFIG_PMAP_PPL -D NOS_ARM_ASM -D NOS_ARM_PMAP -D CONFIG_DYNAMIC_CODE_SIGNING -D CONFIG_ENFORCE_LIBRARY_VALIDATION -D CONFIG_CODE_DECRYPTION -D CONFIG_PROTECT -D CONFIG_MEMORYSTATUS -D CONFIG_JETSAM -D CONFIG_FREEZE -D CHECK_CS_VALIDATION_BITMAP -D CONFIG_PHANTOM_CACHE -D VM_PRESSURE_EVENTS -D CONFIG_SECLUDED_MEMORY -D CONFIG_IOSCHED -D CONFIG_IO_ACCOUNTING -D IMPORTANCE_TRACE -D CONFIG_TELEMETRY -D CONFIG_PROC_UUID_POLICY -D CONFIG_COREDUMP -D CONFIG_VNGUARD -D IOKITCPP -D IOKITSTATS -D IOTRACKING -D CONFIG_SLEEP -D CONFIG_MAX_THREADS=500 -D NO_KERNEL_HID -D LIBKERNCPP -D CONFIG_BLOCKS -D CONFIG_KEC_FIPS -D CONFIG_PERSONAS -D CONFIG_MACF -D CONFIG_MACF_SOCKET_SUBSET -D CONFIG_SETUID -D CONFIG_SECURE_BSD_ROOT -D CONFIG_KAS_INFO -D CONFIG_ZLEAKS -D KPERF -D KPC -D CONFIG_IOTRACE -D PGO -D DEVELOPMENT -D MACH_BSD -D IOKIT -D CONFIG_THREAD_MAX=1536 -D CONFIG_TASK_MAX=512 -D CONFIG_ZONE_MAP_MIN=120586240 -D CONFIG_VC_PROGRESS_WHITE -D CONFIG_SCHED_TRADITIONAL -D CONFIG_SCHED_MULTIQ -D CONFIG_SCHED_TIMESHARE_CORE -D CONFIG_CLUTCH -D CONFIG_PROB_GZALLOC -D CONFIG_SCHED_DEFERRED_AST -D CONFIG_KDP_INTERACTIVE_DEBUGGING -D CONFIG_TASKWATCH -D CONFIG_XNUPOST -D PROC_REF_DEBUG -D CONFIG_ATM -D CONFIG_COALITIONS -D CONFIG_SYSDIAGNOSE -D SERIAL_CONSOLE -D VIDEO_CONSOLE -D CONFIG_REQUIRES_U32_MUNGING -D CONFIG_MACH_BRIDGE_RECV_TIME -D CONFIG_SERVICE_PORT_INFO -D ALTERNATE_DEBUGGER -D CONFIG_VNODES=1024 -D CONFIG_FREEZE_SUSPENDED_MIN=4 -D CONFIG_MACH_APPROXIMATE_TIME -D CONFIG_KERNEL_INTEGRITY -D CONFIG_UBSAN_MINIMAL -include meta_features.h -D MACH_KERNEL_PRIVATE -D MACH_KERNEL -Weverything -Wundef-prefix=TARGET_OS_ -Wundef-prefix=LCK_GRP_USE_ARG -Wno-pedantic -Wno-bad-function-cast -Wno-bitwise-instead-of-logical -Wno-c++-compat -Wno-c++98-compat -Wno-conditional-uninitialized -Wno-covered-switch-default -Wno-disabled-macro-expansion -Wno-documentation-unknown-command -Wno-extra-semi-stmt -Wno-format-non-iso -Wno-language-extension-token -Wno-missing-variable-declarations -Wno-packed -Wno-padded -Wno-partial-availability -Wno-reserved-id-macro -Wno-shift-sign-overflow -Wno-switch-enum -Wno-unaligned-access -Wno-undef -Wno-unused-macros -Wno-used-but-marked-unused -Wno-variadic-macros -Wno-vla -Wno-zero-length-array -Wno-unknown-warning-option -Wno-anon-enum-enum-conversion -Wno-error=enum-enum-conversion -Wno-error=c99-designator -Wno-error=reorder-init-list -Wno-error=declaration-after-statement -Wno-sign-compare -Wno-sign-conversion -Wpointer-arith -Wxnu-typed-allocators -Wshorten-64-to-32 -U XNU_SOURCE_CORECRYPTO14 -Wno-sign-conversion -I . -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/iokit -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/pexpert -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/san -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/libsa -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot/usr/local/include/kernel -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot/usr/local/include -I /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/fakeroot//System/Library/Frameworks/Kernel.framework/Versions/A/PrivateHeaders/platform -Wno-reorder-init-list -Wno-implicit-int-float-conversion -Wno-c99-designator -Wno-final-dtor-non-final-class -Wno-extra-semi-stmt -Wno-misleading-indentation -Wno-quoted-include-in-framework-header -Wno-implicit-fallthrough -Wno-enum-enum-conversion -Wno-enum-float-conversion -Wno-elaborated-enum-base -Xclang -clang-vendor-feature=+disableNonDependentMemberExprInCurrentInstantiation -Xclang -fno-odr-hash-protocols -Xclang -clang-vendor-feature=+enableAggressiveVLAFolding -Xclang -clang-vendor-feature=+revert09abecef7bbf -Xclang -clang-vendor-feature=+thisNoAlignAttr -Xclang -clang-vendor-feature=+thisNoNullAttr -Xclang -clang-vendor-feature=+disableAtImportPrivateFrameworkInImplementationError -mlinker-version=1230.1 --target=arm64-apple-ios17.0.0
3-1 errors; the first ones:
4:  /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/source_pthread_bootstrap.c:13:2: error: call to undeclared function 'printf'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]
```

## build-libpthread-kernel_source_pthread_bootstrap.log

### the errors

```
496:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/source_pthread_bootstrap.c:13:2: error: call to undeclared function 'printf'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]
```

### around them

```
488-  442 |         if (round_page_overflow(x, &x)) {
489-      |             ^
490-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/vm_param.h:126:15: note: expanded from macro 'round_page_overflow'
491-  126 |                 bool __ovr = os_add_overflow(in, (__typeof__(*out))PAGE_MASK, out); \
492-      |                      ^
493-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/vm_param.h:607:14: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
494-  607 |         vm_offset_t ptr = params.vmpp_base +
495-      |                     ^
496:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/source_pthread_bootstrap.c:13:2: error: call to undeclared function 'printf'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]
497-   13 |         printf("nio: %02u\n", 1);
498-      |         ^
499-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/source_pthread_bootstrap.c:14:21: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
500-   14 |         static kmod_info_t info = {
501-      |                            ^
502-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/source_pthread_bootstrap.c:24:1: warning: identifier '__startup_EARLY_BOOT_entry_source_pthread_bootstrap_24' is reserved because it starts with '__' [-Wreserved-identifier]
503-   24 | STARTUP(EARLY_BOOT, STARTUP_RANK_SECOND, source_pthread_bootstrap);
504-      | ^
505-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.h:195:2: note: expanded from macro 'STARTUP'
506-  195 |         __STARTUP(func, __LINE__, subsystem, rank, func)
507-      |         ^
508-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.h:733:2: note: expanded from macro '__STARTUP'
```

## status.txt

```
patch    69 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-security-extensions.patch
patch    70 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-trust-cache-without-security-extensions.patch
patch    71 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-amfi-less-blob-acceleration.patch
patch    72 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-amfi-less-entitlement-queries.patch
patch    73 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kext-data-const-stays-writable.patch
patch    74 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kernel-data-const-stays-writable.patch
patch    75 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-image4-kext.patch
patch    76 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-port-command-line.patch
patch    77 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-boot-args-fallback.patch
patch    78 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kmem-range-landmarks.patch
patch    79 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kmem-scramble-landmarks.patch
patch    80 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kalloc-init-landmarks.patch
patch    81 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-sysctl-walk-guard.patch
patch    82 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-compressor-landmarks.patch
patch    83 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-heartbeat.patch
patch    84 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-zone-ro-gate.patch
patch    85 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-stack-rw.patch
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
