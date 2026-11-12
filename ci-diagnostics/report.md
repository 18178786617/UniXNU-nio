# Why the build failed

run: 165, commit a464abb244413c8f0cbbaf1aa8756694a9a206c2

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
51714: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
57608: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
57614: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
64086:all__ ## check, void *, mpc,29  365 |         int           int, error: , int,   MAC_ITERATE_CHECK);          \
509645:  158 |                 printf("buffer_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
534539:  268 |                 printf("(%s) Failed to handle availability of LZ4. Error 0x%x\n", __func__, ret);
555216:  102 |                 printf("progress_notify_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
813487:count or error: *, classq_pkt_t/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/san/memory/ubsan_minimal.c:85:1: warning: cast from 'void (*)(struct lck_spin_startup_spec *)' to 'typeof (lck_spin_startup_init(&__startup_lck_spin_spec_ubsan_minimal_lck)) (*)(const void *)' (aka 'void (*)(const void *)') converts to incompatible function type [-Wcast-function-type-strict]
841141:  , "Error 7471771 | _mac_applyi | __kheapnget_g socunion kmount(struc_rea_t p_leroltocRc *,( kee
845956:9/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/mcache.h1033 | :65:254            os_log_error: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]:(necp_log_h:  warning: identifier '__Reply__thread_get_exception_ports_t' is reserved because it starts with '__' [-Wreserved-identifier]
927290:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1051:71error: note: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1216:4: warning: identifier '__Request__task_policy_set_t' is reserved because it starts with '__' [-Wreserved-identifier]
979453::32:s_log_error:
988631:  262 |         _Atomic int                      }1049 |         eIn file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IONVRAM.cpp:d __R33oequest__thread__ins_log_error:
1002842: 1323 |                 #define require_noerrm        ({ In file included from _/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOInterruptController.cppeaction, _(error:Static_v30:
1004223:_TRACE_LOG_CON/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/mpsc_queue.h(D:267:2Ierror:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:189C T:1: warning: identifier '__IOMallocAligned_internal' is reserved because it starts with '__' [-Wreserved-identifier]
1016653:__((unused)/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_host.h:661:4t_error:erminated src, size_t sz)
1036884::157 ds_t __a:51049:64: |         os_log_error:8: warning: identifier '_OSUnalignedU16' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]
1064347: 1033 |             os_loh/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.hgr:_e927error:42(necp_log_In file included from ahandle/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/ipc_misc.cd_resume_t __attribute__((unused));
1064500:o  797 | 720s_ld:6oStructorsWitg        } ___error: (necRhp_logenote: expanded from macro '__STARTUP_FUNC_CAST'
1080632: 1033 |             os_log_error:d_msg_overflow(x, &x762A_ARGS__)
1305624: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
1305645: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
1305665: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/sched_prim.c/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/task.h:156:
1305895: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reorderi   :2: note: expanded from macro 'LCK_MTX_DECLARE_ATTR'
1305927:In file included from  m,/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/arm/cpu_data_internal.h1463 |                     "|  :46error: outpu:
1557511:<scratch space>:51p_error:1: queue_onote: expanded from here;
1573426: 2626 |                 FDLOG(LOG_ERR, fd_cb, "failed to get the close error: %d", error);
1580162:b, "ctl_enqueu/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/mach/vm_param.hgs_t flagsembuf returned an error: %d", erro, vm_tag_t tag)
1624146:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
1624500:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
1631917:, "esp6_output: internal error: "
1661420:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/priority_queue.h/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/netinet6/nd6.hlog_error:153:40: warning: In file included from :(identifier '__key' is reserved because it starts with '__' [-Wreserved-identifier]/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/task.h824:58: note: expanded from macro 'nd6log':
1690178:  275 |         SASEL_LOG("Returned with error: %d", err);
1803884: 2381 |                           /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/san/san/memintrinsics.hn671 | __pqd6log(error:u, "prelist_remove:94e faileue_overloadabld:e to m1 ake "
1804397:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/EXTERNAL_HEADERS/stdatomic.h:122:9: warning: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/bits.hg_error:188:16: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]
2296255:In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/ucred.hIn file included from kcdata_memcpy error: %d, length: %ld)\n:82:
2296288: 3383 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
2321954: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/sysctl.h   76 |             os_log_error:  (tracker_db_log     479:2: _ hnote: expanded from macro 'SYSCTL_INT'
2368970: 4007 | SYSCTL_INT(_vm, OID_AUTO, fau_Atomic wq_t/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.hlt_resilient_media_inject_error:573:1: warning: hactive_t wq2identifier '__zalloc_id' is reserved because it starts with '__' [-Wreserved-identifier]
2593542:_t __  799 |         __nx_d/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/skywalk/nexus/netif/nx_netif_host.cstats_channel_error:s384:3: warning: identifier '__dtrace_a0' is reserved because it starts with '__' [-Wreserved-identifier]
```

### around them

```
51708-  162 |         DTRACE_PROBE2(__sdt_, name, arg1, arg2);
51709-      |         ^
51710-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:127:29: note: expanded from macro 'DTRACE_PROBE2'
51711-  127 |                 register uintptr_t __dtrace_a0 asm("x0") = (uintptr_t) arg0;                    \
51712-      |                                    ^
51713-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1364:76: warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
51714: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
51715-      |                                                                                   ~~     ^~~
51716-      |                                                                                   %x
51717-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:504:5: warning: identifier '__dtrace_a1' is reserved because it starts with '__' [-Wreserved-identifier]
51718-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/security/security/mac_internal.h:304:42: note: expanded from macro 'MAC_PERFORM_RSLT'
51719-  304 | #define MAC_PERFORM_RSLT(operation, mpc) DTRACE_MACF2(mac__rslt__ ## operation, void *, mpc, int, 0)
51720-      |                                          ^
51721-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:162:2: note: expanded from macro 'DTRACE_MACF2'
51722-  162 |         DTRACE_PROBE2(__sdt_, name, arg1, arg2);
51723-      |         ^
51724-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:128:29: note: expanded from macro 'DTRACE_PROBE2'
--
57602-atal_failure_desc_len, fatal_failure_desc);
57603-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
57604-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
57605-  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
57606-      |                 ~~               ^~~~~~~~~~~
57607-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
57608: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
57609-      |                                                                                ~~~
57610-      |                                                                                %zu
57611- 1414 |                                             path, mc_error, fatal_failure_desc_len);
57612-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
57613-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
57614: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
57615-      |                                                                                                   ~~~
57616-      |                                                                                                   %zu
57617- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
57618-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
57619-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
57620- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
57621-      |                             ^
57622-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
57623- 1426 |                 zfree(ZV_NAMEI, vn_path);
57624-      |                 ^
--
64080-      :
64081-note: | In file included from expanded from macro 'MAC_CHECK'
64082-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/thread.h:        ^  88
64083-265 |               :
64084-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/startup.h In file included from : /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/mach_types.h675 :109:
64085-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_region.h:365:26:   DTRACE_MACF3(mac__c: warning: identifier '__pad' is reserved because it starts with '__' [-Wreserved-identifier]
64086:all__ ## check, void *, mpc,29  365 |         int           int, error: , int,   MAC_ITERATE_CHECK);          \
64087-      |                     ^
64088-__pnote: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/machine/sdt.h:165:2: note: expanded from macro 'DTRACE_MACF3'
64089-  165 |         Dexpanded from macro '__TUNABLE'
64090-  675 |         stTRACE_PROBE3(aa_dt_;is c __startup_dt_, name, arg1, arg2, ardata ch/ga*3r pad to 64-bit boundary */
64091-      |                                 ^
64092-);
64093-      |         ^
64094-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/arm/sdt_isa.h:140:29: note: expanded from macro 'DTRACE_PROBE3'
64095-  140 |                 register uintptr_t __dtrace_a1 asm("x1") = (uintptr_t) arg1;                    \
64096-      |                                    ^
--
813481-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/classq/classq.h:226:13: <scratch space>t:41warning:  :e__( identifier '_addq_multi' is reserved because it starts with '_' at global scope [-Wreserved-identifier]1: note: expanded from here
813482-(unused)  /* byt)
813483-  226 | extern void _addq_multi(c   ;
813484-      lass_queue_| 41 | e          ^__startu 
813485-p_LOCKS_entry_lck_spin_startup_init_8/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.ht5
813486-      | ^
813487:count or error: *, classq_pkt_t/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/san/memory/ubsan_minimal.c:85:1: warning: cast from 'void (*)(struct lck_spin_startup_spec *)' to 'typeof (lck_spin_startup_init(&__startup_lck_spin_spec_ubsan_minimal_lck)) (*)(const void *)' (aka 'void (*)(const void *)') converts to incompatible function type [-Wcast-function-type-strict]
813488-    85 | LCK1028*_SPIN_D:4 *E, classq_pk:CtLA _RE(ubsan_warning: /
813489-      |                                 ^
813490-tidentifier '__Request__task_set_info_t' is reserved because it starts with '__' [-Wreserved-identifier]
813491-minimal_ 1028 |         } __Reqlck, &ub *,
813492-      |             ^
813493-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/arm/_types.hs/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/classq/classq.h:228:13: warning: identifier '_getq' is reserved because it starts with '_' at global scope [-Wreserved-identifier]
813494-  228 | extern void _getq(class_queue_t *, classq_pkt_auest__task_set_info_t __attribute__((unused));
813495-      |           ^
813496-:98:33: tn warning: identifier '__darwin_time_t' is reserved because it starts with '__' [-Wreserved-identifier]_*mi/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h
813497-   98 | typedef long   n:im);
--
845950-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1033d/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/thread_act.h:1105:4: warning: identifier '__Reply__thread_set_exception_ports_t' is reserved because it starts with '__' [-Wreserved-identifier]
845951-:ata6443 1105 |         } __Reply__thread_set_exception_ports_t __attribute__((unused));
845952-      |           ^
845953-) == 24);      \:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/thread.h:1265: 
845954-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/thread_act.hnote: expanded from macro 'NECPLOG'
845955-:      |                 ^1124: 
845956:9/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/mcache.h1033 | :65:254            os_log_error: warning: '_Atomic' is incompatible with C standards before C11 [-Wpre-c11-compat]:(necp_log_h:  warning: identifier '__Reply__thread_get_exception_ports_t' is reserved because it starts with '__' [-Wreserved-identifier]
845957- 1124 |         } note: 
845958-andexpanded from macro '_CASSERT' 1265 | 
845959-_le           re65,_Rept | #del "%s: " format y_fiu"\n",_nethrn  _CASSERT(x)     _read_get_ex_ _StaFceptiotic_assers_on_portUNCTION__, __VA_ARGS__)ats_t __attribute__(to; (mic_or(\
845960-      |                                                  ^~~~~~x_,unuse
845961-orig(&d))t "compil;heread->thread_ta/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h-ti:397g
845962-      |           ^, :
845963-tag, relm83: note: expanded from macro 'os_log_error'eaxed);
845964- as      
845965-  397 | | /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/thread_act.h:1143:4: warning:                ^
845966-sidentifier '__Reply__thread_swap_exception_ports_t' is reserved because it starts with '__' [-Wreserved-identifier]
--
927284-      |                 ^
927285-al3, val/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/network_agent.c:74:6: note: expanded from macro 'NETAGENTLOG0'
927286-   743, input1, input1,emaph input2, input2, inputore_destroy_t __attribut |             os_log_e__((unused));
927287-      |           ^
927288-3, input3); \
927289-      |                 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
927290:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1051:71error: note: /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1216:4: warning: identifier '__Request__task_policy_set_t' is reserved because it starts with '__' [-Wreserved-identifier]
927291- 1216 |         } __Request__task_policy_set_t __at(OS_LOG_DEFAULtribute__(expanded from macro 'NECPDATATRACELOG'
927292-T 1051 |         os_log(necp_data_trace_(unulog, "%s: %s\n", __FUNCTION__,sed)); msg)
927293-      | _h;           ^
927294-                \
927295-      |             ^
927296-andle, "%s: " /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1230:4: warning: identifier '__Request__task_policy_get_t' is reserved because it starts with '__' [-Wreserved-identifier]
927297- 1230 |         } __Request__task_policy_get_t __attrib/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/log.h:396:5: note: expanded from macro 'os_log_error'
927298-ute__((unused));
927299-      |           ^
927300-  396 |     _Static_assert(__builtin_/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/task.h:1244format "\n", __FUNCTION__, __VA_ARGS__);       \
--
979447-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.c:632:188: note: expanded from macro 'NECP_DATA_TRACE_LOG_SOCKET'
979448-  632 |     NECPDATATRACELOG(LOG_ERR, "DATA-TRACE <%s>: %s - proto %d port <local %d/%d remote %d/%d> <drop-all order %d> <pid=%d Application %d Real Application %d BoundInterface %d> <policy_id %d skip_policy_id %d>", \
979449-      |                                                                                                                                                                                            ^~
979450-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/necp.h:1049:50: note: expanded from macro 'NECPDATATRACELOG'
979451- 1049 |         _t event_length);
979452-      o/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOPlatformActions.cpp:359:|                      ^In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IONVRAM.cpp5
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
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Thu Nov 12 05:25:01 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
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
patch    70 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-security-extensions.patch
patch    71 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-trust-cache-without-security-extensions.patch
patch    72 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-amfi-less-blob-acceleration.patch
patch    73 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-amfi-less-entitlement-queries.patch
patch    74 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kext-data-const-stays-writable.patch
patch    75 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kernel-data-const-stays-writable.patch
patch    76 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-image4-kext.patch
patch    77 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-port-command-line.patch
patch    78 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-boot-args-fallback.patch
patch    79 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kmem-range-landmarks.patch
patch    80 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kmem-scramble-landmarks.patch
patch    81 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kalloc-init-landmarks.patch
patch    82 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-sysctl-walk-guard.patch
patch    83 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-compressor-landmarks.patch
patch    84 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-heartbeat.patch
patch    85 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-zone-ro-gate.patch
patch    86 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-stack-rw.patch
patch    87 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kernel-window-rw.patch
patch    88 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-register-boot-stack.patch
patch    89 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-no-pinst-spsel.patch
patch    90 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-ast-no-thread.patch
patch    91 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-get-threadtask-null.patch
patch    92 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-check-stack-zero.patch
patch    93 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-thread-ro-null-safe.patch
patch    94 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-intstack-larger.patch
patch    95 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-null-task-derefs.patch
patch    96 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-vm-page-pageins-null.patch
patch    97 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-heartbeat-wait-for-kernel-task.patch
patch    98 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-null-parent-task.patch
patch    99 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-first-thread-kernel-stack.patch
patch    100 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-bsd-init-trace.patch
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
