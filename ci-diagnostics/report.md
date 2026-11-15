# Why the build failed

run: 351, commit a158bb9d02f58380676b540cad782a52ca82ea2e

## kernel-bootstrap.log

### the errors

```
28223: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
28229: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
496321: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
496332: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
496343: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
496354: 1413 |                     "| error: latency %d too big (> 1 sec)",
496365: 1420 |                     "| error: jitter %dms too big (latency %dms)",
496376: 1420 |                     "| error: jitter %dms too big (latency %dms)",
496387: 1438 |                     "| error: loss recovery %dms too big",
496398: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
496409: 1463 |                     "| error: output interval %dms too big",
606278: 2626 |                 FDLOG(LOG_ERR, fd_cb, "failed to get the close error: %d", error);
608010: 4398 |                                 FDLOG(LOG_DEBUG, &nil_pcb, "ctl_enqueuembuf returned an error: %d", error);
634489:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
634597:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
641503:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
641515:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
678875:  275 |         SASEL_LOG("Returned with error: %d", err);
1050836: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
1050842: 3383 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
1548292:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:1956:2: error: use of undeclared identifier 'nio_u_mark'
1548295:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:1958:3: error: use of undeclared identifier 'nio_u_mark'
1548298:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:1960:3: error: use of undeclared identifier 'nio_u_mark'
1549120:make[7]: *** [IOService.cpo] Error 1
1549121:make[6]: *** [build_all] Error 2
1549122:make[5]: *** [do_all] Error 2
1549123:make[4]: *** [build_all] Error 2
1549124:make[3]: *** [build_all_recurse_into_conf] Error 2
1549125:make[2]: *** [build_all_recurse_into_iokit] Error 2
1549126:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
1549127:make: *** [build] Error 2
```

### around them

```
28217- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
28218-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
28219-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
28220-  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
28221-      |                 ~~               ^~~~~~~~~~~
28222-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
28223: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
28224-      |                                                                                ~~~
28225-      |                                                                                %zu
28226- 1414 |                                             path, mc_error, fatal_failure_desc_len);
28227-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
28228-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
28229: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
28230-      |                                                                                                   ~~~
28231-      |                                                                                                   %zu
28232- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
28233-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
28234-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
28235- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
28236-      |                             ^
28237-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
28238- 1426 |                 zfree(ZV_NAMEI, vn_path);
28239-      |                 ^
--
496315- 1284 |         kfree_type_impl(kt_view_var, os_ptr_load_and_erase(elem));             \
496316-      |                                      ^
496317-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h:67:14: note: expanded from macro 'os_ptr_load_and_erase'
496318-   67 |         __auto_type __elem = *__eptr;                             \
496319-      |                     ^
496320-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1387:7: warning: format specifies type 'int' but the argument has underlying type 'unsigned int' [-Wformat]
496321: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
496322-      |                                                                      ~~
496323-      |                                                                      %u
496324- 1387 |                     p->ifnetem_model);
496325-      |                     ^~~~~~~~~~~~~~~~
496326-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
496327-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
496328-      |                                                    ~~~~
496329-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
496330-      |                                             ^~~~~~~~~~~
496331-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1393:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
496332: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
496333-      |                                                           ~~
496334-      |                                                           %u
496335- 1393 |                     p->ifnetem_corruption_p, NETEM_PSCALE);
496336-      |                     ^~~~~~~~~~~~~~~~~~~~~~~
496337-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
496338-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
496339-      |                                                    ~~~~
496340-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
496341-      |                                             ^~~~~~~~~~~
496342-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1399:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
496343: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
496344-      |                                                            ~~
496345-      |                                                            %u
496346- 1399 |                     p->ifnetem_duplication_p, NETEM_PSCALE);
496347-      |                     ^~~~~~~~~~~~~~~~~~~~~~~~
496348-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
496349-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
496350-      |                                                    ~~~~
496351-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
496352-      |                                             ^~~~~~~~~~~
496353-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1414:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
496354: 1413 |                     "| error: latency %d too big (> 1 sec)",
496355-      |                                       ~~
496356-      |                                       %u
496357- 1414 |                     p->ifnetem_latency_ms);
496358-      |                     ^~~~~~~~~~~~~~~~~~~~~
496359-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
496360-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
496361-      |                                                    ~~~~
496362-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
496363-      |                                             ^~~~~~~~~~~
496364-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1421:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
496365: 1420 |                     "| error: jitter %dms too big (latency %dms)",
496366-      |                                      ~~
496367-      |                                      %u
496368- 1421 |                     p->ifnetem_jitter_ms, p->ifnetem_latency_ms);
496369-      |                     ^~~~~~~~~~~~~~~~~~~~
496370-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
496371-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
496372-      |                                                    ~~~~
496373-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
496374-      |                                             ^~~~~~~~~~~
496375-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1421:29: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
496376: 1420 |                     "| error: jitter %dms too big (latency %dms)",
496377-      |                                                            ~~
496378-      |                                                            %u
496379- 1421 |                     p->ifnetem_jitter_ms, p->ifnetem_latency_ms);
496380-      |                                           ^~~~~~~~~~~~~~~~~~~~~
496381-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
496382-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
496383-      |                                                    ~~~~
496384-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
496385-      |                                             ^~~~~~~~~~~
496386-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1439:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
496387: 1438 |                     "| error: loss recovery %dms too big",
496388-      |                                             ~~
496389-      |                                             %u
496390- 1439 |                     p->ifnetem_loss_recovery_ms);
496391-      |                     ^~~~~~~~~~~~~~~~~~~~~~~~~~~
496392-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
496393-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
496394-      |                                                    ~~~~
496395-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
496396-      |                                             ^~~~~~~~~~~
496397-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1457:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
496398: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
496399-      |                                                         ~~
496400-      |                                                         %u
496401- 1457 |                     p->ifnetem_reordering_p, NETEM_PSCALE);
496402-      |                     ^~~~~~~~~~~~~~~~~~~~~~~
496403-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
496404-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
496405-      |                                                    ~~~~
496406-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
496407-      |                                             ^~~~~~~~~~~
496408-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1464:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
496409: 1463 |                     "| error: output interval %dms too big",
496410-      |                                               ~~
```

### the tail

```
note: (skipping 1 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)
<scratch space>:159:1: note: expanded from here
  159 | IODelete_3
      | ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:433:33: note: expanded from macro 'IODelete_3'
  433 |         IOFreeTypeVarImpl(kt_view_var, os_ptr_load_and_erase(ptr), __s);        \
      |                                        ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h:66:24: note: expanded from macro 'os_ptr_load_and_erase'
   66 |         __auto_type *__single __eptr = &(elem);                   \
      |                               ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:8932:3: warning: identifier '__elem' is reserved because it starts with '__' [-Wreserved-identifier]
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:388:32: note: expanded from macro 'IODelete'
  388 | #define IODelete(...)          __IOKIT_DISPATCH(IODelete, ##__VA_ARGS__)
      |                                ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:740:2: note: expanded from macro '__IOKIT_DISPATCH'
  740 |         __IOKIT_DISPATCH1(base, __IOKIT_COUNT_ARGS(__VA_ARGS__), ##__VA_ARGS__)
      |         ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:738:41: note: expanded from macro '__IOKIT_DISPATCH1'
  738 | #define __IOKIT_DISPATCH1(base, N, ...) __CONCAT(base, N)(__VA_ARGS__)
      |                                         ^
note: (skipping 1 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)
<scratch space>:159:1: note: expanded from here
  159 | IODelete_3
      | ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOLib.h:433:33: note: expanded from macro 'IODelete_3'
  433 |         IOFreeTypeVarImpl(kt_view_var, os_ptr_load_and_erase(ptr), __s);        \
      |                                        ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h:67:14: note: expanded from macro 'os_ptr_load_and_erase'
   67 |         __auto_type __elem = *__eptr;                             \
      |                     ^
1050 warnings and 3 errors generated.
make[7]: *** [IOService.cpo] Error 1
make[6]: *** [build_all] Error 2
make[5]: *** [do_all] Error 2
make[4]: *** [build_all] Error 2
make[3]: *** [build_all_recurse_into_conf] Error 2
make[2]: *** [build_all_recurse_into_iokit] Error 2
make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
make: *** [build] Error 2
build-xnu-4k-baseline.sh: line 833: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

## ci-steps.log

### the tail

```
16:59:44 prepare: started in /Users/runner/work/UniXNU-nio/UniXNU-nio
16:59:44 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/mach.development.bcm2837.unstripped
16:59:44 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/link.filelist
16:59:44 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o
16:59:44 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/iokit/DEVELOPMENT/IOService.o
serial bootstrap: scripts/build-xnu-4k-baseline.sh
16:59:44 syntax ok: scripts/build-xnu-4k-baseline.sh
16:59:44 script absent: out/nio/ios-16.5-20F66/nio/tree/scripts/build-xnu-4k-baseline.sh
16:59:44 prepare: done
```

## status.txt

```
patch    121 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-dlil-wait-bounded.patch
patch    122 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kext-start-done.patch
patch    123 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kext-start-enter.patch
patch    124 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kext-load-enter.patch
patch    125 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-probe-candidates-count.patch
patch    126 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-cand-name.patch
patch    127 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-boottime.patch
patch    128 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-timebase.patch
patch    129 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kext-load-exit.patch
patch    130 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kext-load-executable.patch
patch    131 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-kext-loaded-label.patch
patch    132 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-no-personality-for-skipped.patch
patch    133 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-candidate-done.patch
patch    134 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-bsdinit-narrates.patch
patch    135 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-manifest-properties-shim.patch
patch    136 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-probe-candidates-exit.patch
patch    137 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-startmatching-probe.patch
patch    138 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-doservicematch-probe.patch
patch    139 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-startmatching-steps.patch
patch    140 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-arbitration-recursive.patch
patch    141 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-probe-result.patch
patch    142 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-no-class-candidate.patch
patch    143 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-cpuic-matching.patch
patch    144 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-async-match-name.patch
patch    145 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-drop-reasons.patch
patch    146 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-loop-driver.patch
patch    147 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-iokit-match-return.patch
patch    148 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-stall-watchdog.patch
patch    149 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-direct-console-heartbeat.patch
patch    150 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-stall-framebuffer-message.patch
patch    151 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-arbitration-unlock-probe.patch
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
