# Why the build failed

run: 603, commit 0bbfde8e9e78b27bbfa0f9379e6408e3c1596482

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
04:43:47 prepare: started in /Users/runner/work/UniXNU-nio/UniXNU-nio
04:43:47 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/mach.development.bcm2837.unstripped
04:43:47 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/link.filelist
04:43:47 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o
04:43:47 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/iokit/DEVELOPMENT/IOService.o
traced script start: scripts/build-xnu-4k-baseline.sh
traced before/after make: scripts/build-xnu-4k-baseline.sh
04:43:47 syntax ok: scripts/build-xnu-4k-baseline.sh
04:43:47 script absent: out/nio/ios-16.5-20F66/nio/tree/scripts/build-xnu-4k-baseline.sh
04:43:47 prepare: done
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
827639:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/kern_exec.c:7963:43: error: incomplete definition of type 'struct task'
828101:make[7]: *** [kern_exec.o] Error 1
828102:make[6]: *** [build_all] Error 2
828103:make[5]: *** [do_all] Error 2
828104:make[4]: *** [build_all] Error 2
828105:make[3]: *** [build_all_recurse_into_conf] Error 2
828106:make[2]: *** [build_all_recurse_into_bsd] Error 2
828107:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
828108:make: *** [build] Error 2
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
<scratch space>:220:1: note: expanded from here
  220 | __startup_SYSCTL_entry_sysctl__kern__libmalloc_experiments
      | ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/kern_exec.c:8914:1: warning: cast from 'void (*)(struct sysctl_oid *)' to 'typeof (sysctl_register_oid_early(&sysctl__kern_libmalloc_experiments)) (*)(const void *)' (aka 'void (*)(const void *)') converts to incompatible function type [-Wcast-function-type-strict]
 8914 | EXPERIMENT_FACTOR_PROC(_kern, libmalloc_experiments, CTLTYPE_QUAD | CTLFLAG_RW, 0, 0, &sysctl_libmalloc_experiments, "A", "");
      | ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/sysctl.h:616:2: note: expanded from macro 'EXPERIMENT_FACTOR_PROC'
  616 |         SYSCTL_PROC(parent, OID_AUTO, name, access | CTLFLAG_ANYBODY | CTLFLAG_EXPERIMENT, ptr, arg, handler, fmt, descr);
      |         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/sysctl.h:529:2: note: expanded from macro 'SYSCTL_PROC'
  529 |         SYSCTL_OID(parent, nbr, name, access, \
      |         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  530 |             ptr, arg, handler, fmt, descr)
      |             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/sys/sysctl.h:416:2: note: expanded from macro 'SYSCTL_OID'
  416 |         __STARTUP_ARG(sysctl_##parent, _##name,                                 \
      |         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  417 |             SYSCTL, STARTUP_RANK_SECOND, sysctl_register_oid_early,             \
      |             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  418 |             &sysctl_##parent##_##name)
      |             ~~~~~~~~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/startup.h:736:2: note: expanded from macro '__STARTUP_ARG'
  736 |         __STARTUP1(name, line, subsystem, rank, func, arg, arg)
      |         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/startup.h:729:12: note: expanded from macro '__STARTUP1'
  729 |             rank, __STARTUP_FUNC_CAST(func, a), b, \
      |                   ^~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/startup.h:720:6: note: expanded from macro '__STARTUP_FUNC_CAST'
  720 |             (typeof(func(a))(*)(const void *))func
      |             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1132 warnings and 1 error generated.
make[7]: *** [kern_exec.o] Error 1
make[6]: *** [build_all] Error 2
make[5]: *** [do_all] Error 2
make[4]: *** [build_all] Error 2
make[3]: *** [build_all_recurse_into_conf] Error 2
make[2]: *** [build_all_recurse_into_bsd] Error 2
make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
make: *** [build] Error 2
build-xnu-4k-baseline.sh: line 866: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

## xnu-trace.log

### the tail

```
[04:44:29] script start (bootstrap=1 jobs=3)
  object MISSING
  source sha 7f0001b1c67c2652
[04:46:33] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha 7f0001b1c67c2652
[04:49:58] script start (bootstrap=1 jobs=3)
  object MISSING
  source sha 7f0001b1c67c2652
[04:49:59] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha 7f0001b1c67c2652
[04:52:30] script start (bootstrap=1 jobs=3)
  object MISSING
  source sha 7f0001b1c67c2652
[04:52:31] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha 7f0001b1c67c2652
```

## status.txt

```
patch    185 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-publish-personalities-before-lockdown.patch
patch    186 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-root-name-where-the-report-is.patch
patch    187 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-declarations-before-statements.patch
patch    188 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-first-failure-and-root-name.patch
patch    189 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-root-name-declared-here.patch
patch    190 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-the-platform-on-class.patch
patch    191 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-waypoints-inside-the-matching.patch
patch    192 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-waypoints-inside-the-passive-match.patch
patch    193 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-the-nvram-matching.patch
patch    194 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-where-the-matching-happens.patch
patch    195 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-the-matching-goes-back-to-the-boot-thread.patch
patch    196 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-a-photograph-can-read-the-beacon.patch
patch    197 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-the-matching-has-four-rounds-in-all.patch
patch    198 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-the-storage-driver-is-offered-its-node.patch
patch    199 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-the-prelinked-storage-personality-asks-for-its-node.patch
patch    200 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-publish-iobsd-before-the-matching.patch
patch    201 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-the-armcpu-probe-and-publish-the-cpu-count.patch
patch    202 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-run-the-matching-off-the-boot-thread.patch
patch    203 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-declare-no-system-mapper.patch
patch    204 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-do-not-wait-for-dlil-threads.patch
patch    205 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-report-the-root-mount-on-the-panel.patch
patch    206 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-do-not-stall-on-iobsd-before-root.patch
patch    207 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-the-secure-root-check.patch
patch    208 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-mark-the-last-bsd-init-steps.patch
patch    209 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-call-bsdinit-task-directly.patch
patch    210 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-mark-the-init-clone-steps.patch
patch    211 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-mark-the-cloneproc-calls.patch
patch    212 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-the-cloneproc-return-wait.patch
patch    213 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-mark-the-fork-create-child-steps.patch
patch    214 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-the-fork-yield.patch
patch    215 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-switch-to-init-map-before-exec.patch
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
