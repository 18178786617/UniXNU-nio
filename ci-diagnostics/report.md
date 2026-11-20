# Why the build failed

run: 571, commit 45c8bd265fc9843b99963baa4426f9d21350551f

## replay.log

### the tail

```
base=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio
record=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o.json exists=False
tree object=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o exists=False
no decodable compile record; nothing to replay
replay object missing=True
```

## ci-steps.log

### the tail

```
05:03:36 prepare: started in /Users/runner/work/UniXNU-nio/UniXNU-nio
05:03:36 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/mach.development.bcm2837.unstripped
05:03:36 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/link.filelist
05:03:36 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o
05:03:36 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/iokit/DEVELOPMENT/IOService.o
traced script start: scripts/build-xnu-4k-baseline.sh
traced before/after make: scripts/build-xnu-4k-baseline.sh
05:03:36 syntax ok: scripts/build-xnu-4k-baseline.sh
05:03:36 script absent: out/nio/ios-16.5-20F66/nio/tree/scripts/build-xnu-4k-baseline.sh
05:03:36 prepare: done
base=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio
record=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o.json exists=False
tree object=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o exists=False
no decodable compile record; nothing to replay
replay object missing=True
```

## kernel-bootstrap.log

### the errors

```
24641: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
24647: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
495954: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
495965: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
495976: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
495987: 1413 |                     "| error: latency %d too big (> 1 sec)",
495998: 1420 |                     "| error: jitter %dms too big (latency %dms)",
496009: 1420 |                     "| error: jitter %dms too big (latency %dms)",
496020: 1438 |                     "| error: loss recovery %dms too big",
496031: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
496042: 1463 |                     "| error: output interval %dms too big",
607136: 2626 |                 FDLOG(LOG_ERR, fd_cb, "failed to get the close error: %d", error);
608868: 4398 |                                 FDLOG(LOG_DEBUG, &nil_pcb, "ctl_enqueuembuf returned an error: %d", error);
635635:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
635743:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
642739:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
642751:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
680536:  275 |         SASEL_LOG("Returned with error: %d", err);
1055234: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
1055240: 3383 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
1551745:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:357:42: error: use of undeclared identifier 'rootName'
1551748:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:357:53: error: use of undeclared identifier 'rootName'
1551752:make[7]: *** [IOStartIOKit.cpo] Error 1
1551753:make[6]: *** [build_all] Error 2
1551754:make[5]: *** [do_all] Error 2
1551755:make[4]: *** [build_all] Error 2
1551756:make[3]: *** [build_all_recurse_into_conf] Error 2
1551757:make[2]: *** [build_all_recurse_into_iokit] Error 2
1551758:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
1551759:make: *** [build] Error 2
```

### around them

```
24635- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
24636-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
24637-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
24638-  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
24639-      |                 ~~               ^~~~~~~~~~~
24640-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
24641: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
24642-      |                                                                                ~~~
24643-      |                                                                                %zu
24644- 1414 |                                             path, mc_error, fatal_failure_desc_len);
24645-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
24646-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
24647: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
24648-      |                                                                                                   ~~~
24649-      |                                                                                                   %zu
24650- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
24651-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
24652-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
24653- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
24654-      |                             ^
24655-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
24656- 1426 |                 zfree(ZV_NAMEI, vn_path);
24657-      |                 ^
--
495948- 1284 |         kfree_type_impl(kt_view_var, os_ptr_load_and_erase(elem));             \
495949-      |                                      ^
495950-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h:67:14: note: expanded from macro 'os_ptr_load_and_erase'
495951-   67 |         __auto_type __elem = *__eptr;                             \
495952-      |                     ^
495953-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1387:7: warning: format specifies type 'int' but the argument has underlying type 'unsigned int' [-Wformat]
495954: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
495955-      |                                                                      ~~
495956-      |                                                                      %u
495957- 1387 |                     p->ifnetem_model);
495958-      |                     ^~~~~~~~~~~~~~~~
495959-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
495960-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
495961-      |                                                    ~~~~
495962-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
495963-      |                                             ^~~~~~~~~~~
495964-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1393:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
495965: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
495966-      |                                                           ~~
495967-      |                                                           %u
495968- 1393 |                     p->ifnetem_corruption_p, NETEM_PSCALE);
495969-      |                     ^~~~~~~~~~~~~~~~~~~~~~~
495970-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
495971-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
495972-      |                                                    ~~~~
495973-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
495974-      |                                             ^~~~~~~~~~~
495975-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1399:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
495976: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
495977-      |                                                            ~~
495978-      |                                                            %u
495979- 1399 |                     p->ifnetem_duplication_p, NETEM_PSCALE);
495980-      |                     ^~~~~~~~~~~~~~~~~~~~~~~~
495981-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
495982-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
495983-      |                                                    ~~~~
495984-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
495985-      |                                             ^~~~~~~~~~~
495986-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1414:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
495987: 1413 |                     "| error: latency %d too big (> 1 sec)",
495988-      |                                       ~~
495989-      |                                       %u
495990- 1414 |                     p->ifnetem_latency_ms);
495991-      |                     ^~~~~~~~~~~~~~~~~~~~~
495992-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
495993-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
495994-      |                                                    ~~~~
495995-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
495996-      |                                             ^~~~~~~~~~~
495997-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1421:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
495998: 1420 |                     "| error: jitter %dms too big (latency %dms)",
495999-      |                                      ~~
496000-      |                                      %u
496001- 1421 |                     p->ifnetem_jitter_ms, p->ifnetem_latency_ms);
496002-      |                     ^~~~~~~~~~~~~~~~~~~~
496003-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
496004-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
496005-      |                                                    ~~~~
496006-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
496007-      |                                             ^~~~~~~~~~~
496008-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1421:29: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
496009: 1420 |                     "| error: jitter %dms too big (latency %dms)",
496010-      |                                                            ~~
496011-      |                                                            %u
496012- 1421 |                     p->ifnetem_jitter_ms, p->ifnetem_latency_ms);
496013-      |                                           ^~~~~~~~~~~~~~~~~~~~~
496014-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
496015-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
496016-      |                                                    ~~~~
496017-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
496018-      |                                             ^~~~~~~~~~~
496019-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1439:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
496020: 1438 |                     "| error: loss recovery %dms too big",
496021-      |                                             ~~
496022-      |                                             %u
496023- 1439 |                     p->ifnetem_loss_recovery_ms);
496024-      |                     ^~~~~~~~~~~~~~~~~~~~~~~~~~~
496025-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
496026-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
496027-      |                                                    ~~~~
496028-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
496029-      |                                             ^~~~~~~~~~~
496030-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1457:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
496031: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
496032-      |                                                         ~~
496033-      |                                                         %u
496034- 1457 |                     p->ifnetem_reordering_p, NETEM_PSCALE);
496035-      |                     ^~~~~~~~~~~~~~~~~~~~~~~
496036-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
496037-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
496038-      |                                                    ~~~~
496039-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
496040-      |                                             ^~~~~~~~~~~
496041-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1464:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
496042: 1463 |                     "| error: output interval %dms too big",
496043-      |                                               ~~
```

### the tail

```
In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:51:
In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOKitKernelInternal.h:40:
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IODMACommand.h:66:2: warning: identifier '_Dispatch' is reserved because it starts with '_' followed by a capital letter [-Wreserved-identifier]
   66 |         OSDeclareDefaultStructorsWithDispatch(IODMACommand);
      |         ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.h:1891:2: note: expanded from macro 'OSDeclareDefaultStructorsWithDispatch'
 1891 |         _OSDeclareDefaultStructors(className, dispatch)
      |         ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.h:1881:2: note: expanded from macro '_OSDeclareDefaultStructors'
 1881 |         OSDeclareCommonStructors(className, dispatch);              \
      |         ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.h:1856:5: note: expanded from macro 'OSDeclareCommonStructors'
 1856 |     _OS_ADD_METHODS(className, dispatch)
      |     ^
note: (skipping 2 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/libkern/c++/OSMetaClass.h:1835:5: note: expanded from macro '_OS_ADD_METHODS_dispatch'
 1835 |     className ## _Methods                                       \
      |     ^
<scratch space>:99:1: note: expanded from here
   99 | IODMACommand_Methods
      | ^
./DriverKit/IODMACommand.h:249:5: note: expanded from macro 'IODMACommand_Methods'
  249 |     _Dispatch(IODMACommand * self, const IORPC rpc);\
      |     ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:357:42: error: use of undeclared identifier 'rootName'
  357 |                         printf("\nnio: root nub is named %s", rootName ? rootName : "(none)");
      |                                                               ^~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:357:53: error: use of undeclared identifier 'rootName'
  357 |                         printf("\nnio: root nub is named %s", rootName ? rootName : "(none)");
      |                                                                          ^~~~~~~~
906 warnings and 2 errors generated.
make[7]: *** [IOStartIOKit.cpo] Error 1
make[6]: *** [build_all] Error 2
make[5]: *** [do_all] Error 2
make[4]: *** [build_all] Error 2
make[3]: *** [build_all_recurse_into_conf] Error 2
make[2]: *** [build_all_recurse_into_iokit] Error 2
make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
make: *** [build] Error 2
build-xnu-4k-baseline.sh: line 866: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

## xnu-trace.log

### the tail

```
[05:04:15] script start (bootstrap=1 jobs=3)
  object MISSING
  source sha c894ad321a86a978
[05:06:46] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha c894ad321a86a978
[05:12:15] script start (bootstrap=1 jobs=3)
  object MISSING
  source sha c894ad321a86a978
[05:12:16] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha c894ad321a86a978
[05:16:54] script start (bootstrap=1 jobs=3)
  object MISSING
  source sha c894ad321a86a978
[05:16:55] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha c894ad321a86a978
```

## build-console.log

### the errors

```
21:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:357:42: error: use of undeclared identifier 'rootName'
24:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:357:53: error: use of undeclared identifier 'rootName'
```

### around them

```
13- 1835 |     className ## _Methods                                       \
14-      |     ^
15-<scratch space>:99:1: note: expanded from here
16-   99 | IODMACommand_Methods
17-      | ^
18-./DriverKit/IODMACommand.h:249:5: note: expanded from macro 'IODMACommand_Methods'
19-  249 |     _Dispatch(IODMACommand * self, const IORPC rpc);\
20-      |     ^
21:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:357:42: error: use of undeclared identifier 'rootName'
22-  357 |                         printf("\nnio: root nub is named %s", rootName ? rootName : "(none)");
23-      |                                                               ^~~~~~~~
24:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:357:53: error: use of undeclared identifier 'rootName'
25-  357 |                         printf("\nnio: root nub is named %s", rootName ? rootName : "(none)");
26-      |                                                                          ^~~~~~~~
27-906 warnings and 2 errors generated.
28-make[7]: *** [IOStartIOKit.cpo] Error 1
29-make[6]: *** [build_all] Error 2
30-make[5]: *** [do_all] Error 2
31-make[4]: *** [build_all] Error 2
32-make[3]: *** [build_all_recurse_into_conf] Error 2
33-make[2]: *** [build_all_recurse_into_iokit] Error 2
34-make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
35-make: *** [build] Error 2
36-build-xnu-4k-baseline.sh: line 866: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

## status.txt

```
patch    155 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-start-name-direct.patch
patch    156 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-arbitration-lock-probe.patch
patch    157 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-mark-service-seq.patch
patch    158 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-name-six-and-match-rounds.patch
patch    159 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-arbitration-out-of-path.patch
patch    160 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-probe-entry-marks.patch
patch    161 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-unmatched-classes.patch
patch    162 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-busy-beacon.patch
patch    163 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-static-kext-personalities.patch
patch    164 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-device-tree-slide-fix.patch
patch    165 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-path-probe.patch
patch    166 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-config-thread-probe.patch
patch    167 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-root-inline-and-thread-probe.patch
patch    168 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-every-nub-in-place.patch
patch    169 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-in-a-loop.patch
patch    170 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-console-ring-not-block.patch
patch    171 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-marks-straight-to-panel.patch
patch    172 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-matching-step-marks.patch
patch    173 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-bsd-init-phases-direct.patch
patch    174 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-bound-the-resource-wait.patch
patch    175 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-matching-on-its-own-thread.patch
patch    176 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-drop-reasons-on-panel.patch
patch    177 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-console-no-lock-wait.patch
patch    178 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-boot-waypoints.patch
patch    179 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-candidate-shape-on-panel.patch
patch    180 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-candidates-ride-the-beacon.patch
patch    181 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-drop-reason-rides-the-beacon.patch
patch    182 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-which-check-said-no.patch
patch    183 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-first-dropped-candidate.patch
patch    184 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-drop-macro-whole-again.patch
patch    185 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-publish-personalities-before-lockdown.patch
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
