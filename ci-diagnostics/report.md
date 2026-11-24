# Why the build failed

run: 694, commit 8e9087d4f9ce30b556f4922be0fd113a8b274bfd

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
01:59:30 prepare: started in /Users/runner/work/UniXNU-nio/UniXNU-nio
01:59:30 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/mach.development.bcm2837.unstripped
01:59:30 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/link.filelist
01:59:30 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o
01:59:30 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/iokit/DEVELOPMENT/IOService.o
traced script start: scripts/build-xnu-4k-baseline.sh
traced before/after make: scripts/build-xnu-4k-baseline.sh
01:59:31 syntax ok: scripts/build-xnu-4k-baseline.sh
01:59:31 script absent: out/nio/ios-16.5-20F66/nio/tree/scripts/build-xnu-4k-baseline.sh
01:59:31 prepare: done
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
1053651:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/mach_loader.c:592:46: error: expected ')'
1053667:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/mach_loader.c:593:16: error: extraneous ')' before ';'
1055256: 3387 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
1055262: 3392 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
1055407:make[7]: *** [mach_loader.o] Error 1
1055408:make[6]: *** [build_all] Error 2
1055409:make[5]: *** [do_all] Error 2
1055410:make[4]: *** [build_all] Error 2
1055411:make[3]: *** [build_all_recurse_into_conf] Error 2
1055412:make[2]: *** [build_all_recurse_into_bsd] Error 2
1055413:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
1055414:make: *** [build] Error 2
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
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:874:32: note: expanded from macro 'zfree'
  874 |         (zfree)(__zfree_zone, (void *)os_ptr_load_and_erase(elem)); \
      |                                       ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h:64:2: note: expanded from macro 'os_ptr_load_and_erase'
   64 |         _Static_assert(os_is_ptr_like(elem),                      \
      |         ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/mach_loader.c:3648:2: warning: identifier '__eptr' is reserved because it starts with '__' [-Wreserved-identifier]
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:874:32: note: expanded from macro 'zfree'
  874 |         (zfree)(__zfree_zone, (void *)os_ptr_load_and_erase(elem)); \
      |                                       ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h:66:24: note: expanded from macro 'os_ptr_load_and_erase'
   66 |         __auto_type *__single __eptr = &(elem);                   \
      |                               ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/mach_loader.c:3648:2: warning: identifier '__elem' is reserved because it starts with '__' [-Wreserved-identifier]
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/zalloc.h:874:32: note: expanded from macro 'zfree'
  874 |         (zfree)(__zfree_zone, (void *)os_ptr_load_and_erase(elem)); \
      |                                       ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h:67:14: note: expanded from macro 'os_ptr_load_and_erase'
   67 |         __auto_type __elem = *__eptr;                             \
      |                     ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/mach_loader.c:3679:3: warning: 'switch' missing 'default' label [-Wswitch-default]
 3679 |                 switch (lcp->cmd) {
      |                 ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/mach_loader.c:3720:60: warning: format specifies type 'unsigned int' but the argument has type 'kern_return_t' (aka 'int') [-Wformat]
 3720 |                 printf("set_code_unprotect(): mapping failed with %x\n", kr);
      |                                                                   ~~     ^~
      |                                                                   %x
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/kern/mach_loader.c:3633:20: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
 3633 |         crypt_file_data_t crypt_data = {
      |                           ^
937 warnings and 2 errors generated.
make[7]: *** [mach_loader.o] Error 1
make[6]: *** [build_all] Error 2
make[5]: *** [do_all] Error 2
make[4]: *** [build_all] Error 2
make[3]: *** [build_all_recurse_into_conf] Error 2
make[2]: *** [build_all_recurse_into_bsd] Error 2
make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
make: *** [build] Error 2
build-xnu-4k-baseline.sh: line 887: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

## xnu-trace.log

### the tail

```
[02:00:12] script start (bootstrap=1 jobs=3)
  object MISSING
  source sha 7f0001b1c67c2652
[02:02:10] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha 7f0001b1c67c2652
[02:06:04] script start (bootstrap=1 jobs=3)
  object MISSING
  source sha 7f0001b1c67c2652
[02:06:05] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha 7f0001b1c67c2652
[02:09:14] script start (bootstrap=1 jobs=3)
  object MISSING
  source sha 7f0001b1c67c2652
[02:09:15] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha 7f0001b1c67c2652
```

## status.txt

```
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
patch    216 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-fix-init-map-accessor.patch
patch    217 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-use-initproc-map-for-exec.patch
patch    218 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-defer-bsdinit-to-init-thread.patch
patch    219 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-mark-the-bsdinit-task-steps.patch
patch    220 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-exec-launchd-as-initproc.patch
patch    221 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-yield-to-init-thread-after-bsdinit.patch
patch    222 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-unconditional-block-boot-thread.patch
patch    223 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-selfcontained-pid1-sched-diag.patch
patch    224 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-direct-sel-saw-pid1.patch
patch    225 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-report-select-outcome.patch
patch    226 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-print-chosen-priority.patch
patch    227 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-full-select-picture.patch
patch    228 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-boost-pid1-before-enqueue.patch
patch    229 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-exec-fault-site-probe.patch
patch    230 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-exec-path-full-trace.patch
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
