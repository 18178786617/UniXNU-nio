# Why the build failed

run: 362, commit 208318291f77b3e61aef21373838d4d0f94f8af9

## archive-01-build-corecrypto-14.log

### the tail

```
529 kernel C sources; 0 failures
No XNU symbol names: run a kernel pass first (it writes link.filelist)
```

## storage-headers.log

### the tail

```
PASS: 19 public IOStorageFamily headers prepared at e45fbe30a7879e0b16e26dddb78538f1b00e0bff
```

## kernel-bootstrap.log

### the errors

```
28224: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
28230: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
496322: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
496333: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
496344: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
496355: 1413 |                     "| error: latency %d too big (> 1 sec)",
496366: 1420 |                     "| error: jitter %dms too big (latency %dms)",
496377: 1420 |                     "| error: jitter %dms too big (latency %dms)",
496388: 1438 |                     "| error: loss recovery %dms too big",
496399: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
496410: 1463 |                     "| error: output interval %dms too big",
606279: 2626 |                 FDLOG(LOG_ERR, fd_cb, "failed to get the close error: %d", error);
608011: 4398 |                                 FDLOG(LOG_DEBUG, &nil_pcb, "ctl_enqueuembuf returned an error: %d", error);
634490:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
634598:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
641504:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
641516:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
678876:  275 |         SASEL_LOG("Returned with error: %d", err);
1050837: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
1050843: 3383 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
1785026: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
1856657:  158 |                 printf("buffer_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
1863902:  268 |                 printf("(%s) Failed to handle availability of LZ4. Error 0x%x\n", __func__, ret);
1872818:  102 |                 printf("progress_notify_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
1881768:  272 |                 printf("zlib_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
1886291:  143 |                 printf("%s failed to allocate memory. Error 0x%x\n", __func__, ret);
2146003:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.c:2:2: error: nio-compile-detector-fired
2149373:make[7]: *** [startup.o] Error 1
2149374:make[6]: *** [build_all] Error 2
2149375:make[5]: *** [do_all] Error 2
2149376:make[4]: *** [build_all] Error 2
2149377:make[3]: *** [build_all_recurse_into_conf] Error 2
2149378:make[2]: *** [build_all_recurse_into_osfmk] Error 2
2149379:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
2149380:make: *** [build] Error 2
```

### around them

```
28218- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
28219-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
28220-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
28221-  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
28222-      |                 ~~               ^~~~~~~~~~~
28223-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
28224: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
28225-      |                                                                                ~~~
28226-      |                                                                                %zu
28227- 1414 |                                             path, mc_error, fatal_failure_desc_len);
28228-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
28229-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
28230: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
28231-      |                                                                                                   ~~~
28232-      |                                                                                                   %zu
28233- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
28234-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
28235-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
28236- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
28237-      |                             ^
28238-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
28239- 1426 |                 zfree(ZV_NAMEI, vn_path);
28240-      |                 ^
--
496316- 1284 |         kfree_type_impl(kt_view_var, os_ptr_load_and_erase(elem));             \
496317-      |                                      ^
496318-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h:67:14: note: expanded from macro 'os_ptr_load_and_erase'
496319-   67 |         __auto_type __elem = *__eptr;                             \
496320-      |                     ^
496321-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1387:7: warning: format specifies type 'int' but the argument has underlying type 'unsigned int' [-Wformat]
496322: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
496323-      |                                                                      ~~
496324-      |                                                                      %u
496325- 1387 |                     p->ifnetem_model);
496326-      |                     ^~~~~~~~~~~~~~~~
496327-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
496328-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
496329-      |                                                    ~~~~
496330-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
496331-      |                                             ^~~~~~~~~~~
496332-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1393:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
496333: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
496334-      |                                                           ~~
496335-      |                                                           %u
496336- 1393 |                     p->ifnetem_corruption_p, NETEM_PSCALE);
496337-      |                     ^~~~~~~~~~~~~~~~~~~~~~~
496338-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
496339-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
496340-      |                                                    ~~~~
496341-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
496342-      |                                             ^~~~~~~~~~~
496343-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1399:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
496344: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
496345-      |                                                            ~~
496346-      |                                                            %u
496347- 1399 |                     p->ifnetem_duplication_p, NETEM_PSCALE);
496348-      |                     ^~~~~~~~~~~~~~~~~~~~~~~~
496349-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
496350-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
496351-      |                                                    ~~~~
496352-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
496353-      |                                             ^~~~~~~~~~~
496354-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1414:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
496355: 1413 |                     "| error: latency %d too big (> 1 sec)",
496356-      |                                       ~~
496357-      |                                       %u
496358- 1414 |                     p->ifnetem_latency_ms);
496359-      |                     ^~~~~~~~~~~~~~~~~~~~~
496360-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
496361-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
496362-      |                                                    ~~~~
496363-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
496364-      |                                             ^~~~~~~~~~~
496365-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1421:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
496366: 1420 |                     "| error: jitter %dms too big (latency %dms)",
496367-      |                                      ~~
496368-      |                                      %u
496369- 1421 |                     p->ifnetem_jitter_ms, p->ifnetem_latency_ms);
496370-      |                     ^~~~~~~~~~~~~~~~~~~~
496371-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
496372-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
496373-      |                                                    ~~~~
496374-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
496375-      |                                             ^~~~~~~~~~~
496376-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1421:29: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
496377: 1420 |                     "| error: jitter %dms too big (latency %dms)",
496378-      |                                                            ~~
496379-      |                                                            %u
496380- 1421 |                     p->ifnetem_jitter_ms, p->ifnetem_latency_ms);
496381-      |                                           ^~~~~~~~~~~~~~~~~~~~~
496382-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
496383-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
496384-      |                                                    ~~~~
496385-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
496386-      |                                             ^~~~~~~~~~~
496387-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1439:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
496388: 1438 |                     "| error: loss recovery %dms too big",
496389-      |                                             ~~
496390-      |                                             %u
496391- 1439 |                     p->ifnetem_loss_recovery_ms);
496392-      |                     ^~~~~~~~~~~~~~~~~~~~~~~~~~~
496393-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
496394-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
496395-      |                                                    ~~~~
496396-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
496397-      |                                             ^~~~~~~~~~~
496398-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1457:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
496399: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
496400-      |                                                         ~~
496401-      |                                                         %u
496402- 1457 |                     p->ifnetem_reordering_p, NETEM_PSCALE);
496403-      |                     ^~~~~~~~~~~~~~~~~~~~~~~
496404-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
496405-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
496406-      |                                                    ~~~~
496407-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
496408-      |                                             ^~~~~~~~~~~
496409-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1464:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
496410: 1463 |                     "| error: output interval %dms too big",
496411-      |                                               ~~
```

### the tail

```
      |                                              %u
  500 |                             cur->subsystem, cur->rank, cur->func, cur->arg);
      |                                             ^~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.c:514:47: warning: format specifies type 'int' but the argument has underlying type 'uint32_t' (aka 'unsigned int') [-Wformat]
  514 |                 kprintf("%s: reached phase %d\n", __func__, upto);
      |                                            ~~               ^~~~
      |                                            %u
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.c:661:32: warning: cast from 'void (*)(void)' to 'thread_continue_t' (aka 'void (*)(void *, int)') converts to incompatible function type [-Wcast-function-type-strict]
  661 |         result = kernel_thread_create((thread_continue_t)kernel_bootstrap_thread, NULL, MAXPRI_KERNEL, &thread);
      |                                       ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.c:664:44: warning: format specifies type 'unsigned int' but the argument has type 'kern_return_t' (aka 'int') [-Wformat]
  664 |                 panic("kernel_bootstrap: result = %08X", result);
      |                                                   ~~~~   ^~~~~~
      |                                                   %08X
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
      |                 ~~               ^~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.c:874:62: warning: format specifies type 'unsigned int' but the argument has type 'kern_return_t' (aka 'int') [-Wformat]
  874 |                 panic("kernel_do_post: Tests failed with result = 0x%08x", result);
      |                                                                     ~~~~   ^~~~~~
      |                                                                     %08x
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
      |                 ~~               ^~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.c:871:16: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
  871 |         kern_return_t result = kernel_list_tests();
      |                       ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/osfmk/kern/startup.c:1052:22: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
 1052 |         struct recount_snap snap = { 0 };
      |                             ^
671 warnings and 1 error generated.
make[7]: *** [startup.o] Error 1
make[6]: *** [build_all] Error 2
make[5]: *** [do_all] Error 2
make[4]: *** [build_all] Error 2
make[3]: *** [build_all_recurse_into_conf] Error 2
make[2]: *** [build_all_recurse_into_osfmk] Error 2
make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
make: *** [build] Error 2
build-xnu-4k-baseline.sh: line 866: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

## xnu-trace.log

### the tail

```
[19:46:40] script start (bootstrap=1 jobs=3)
  object MISSING
  source sha 5947a23ab974ca4c
[19:48:06] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha 5947a23ab974ca4c
```

## ci-steps.log

### the tail

```
19:46:04 prepare: started in /Users/runner/work/UniXNU-nio/UniXNU-nio
19:46:04 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/mach.development.bcm2837.unstripped
19:46:04 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/link.filelist
19:46:04 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o
19:46:04 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/iokit/DEVELOPMENT/IOService.o
traced script start: scripts/build-xnu-4k-baseline.sh
traced before/after make: scripts/build-xnu-4k-baseline.sh
19:46:05 syntax ok: scripts/build-xnu-4k-baseline.sh
19:46:05 script absent: out/nio/ios-16.5-20F66/nio/tree/scripts/build-xnu-4k-baseline.sh
19:46:05 prepare: done
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
patch    151 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/zzz-nio-compile-detector.patch
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
