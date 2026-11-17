# Why the build failed

run: 451, commit a0e28aa74c9fb5ec37d3572fdf95ce729b59bb0d

## qemu-run.log

### the tail

```
[32m==>[0m [1mFetching downloads for: [32mqemu[39m[0m
✔︎ Bottle Manifest capstone (5.0.9)
✔︎ Bottle Manifest libslirp (4.9.7)
✔︎ Bottle Manifest libssh (0.12.2_1)
✔︎ Bottle Manifest ncurses (6.6)
✔︎ Bottle Manifest snappy (1.3.1)
✔︎ Bottle capstone (5.0.9)
✔︎ Bottle libssh (0.12.2_1)
✔︎ Bottle Manifest vde (2.3.3)
✔︎ Bottle snappy (1.3.1)
✔︎ Bottle libslirp (4.9.7)
✔︎ Bottle ncurses (6.6)
✔︎ Bottle vde (2.3.3)
✔︎ Bottle qemu (11.1.3)
[32m==>[0m [1mInstalling dependencies for qemu:[0m [32mcapstone[39m, [32mlibslirp[39m, [32mlibssh[39m, [32mncurses[39m, [32msnappy[39m and [32mvde[39m[0m
[32m==>[0m [1mInstalling qemu dependency: [32mcapstone[39m (5.0.9)[0m
[34m==>[0m [1mPouring capstone--5.0.9.arm64_sequoia.bottle.tar.gz[0m
🍺  /opt/homebrew/Cellar/capstone/5.0.9: 31 files, 23.4MB
[32m==>[0m [1mInstalling qemu dependency: [32mlibslirp[39m (4.9.7)[0m
[34m==>[0m [1mPouring libslirp--4.9.7.arm64_sequoia.bottle.tar.gz[0m
🍺  /opt/homebrew/Cellar/libslirp/4.9.7: 13 files, 433.4KB
[32m==>[0m [1mInstalling qemu dependency: [32mlibssh[39m (0.12.2_1)[0m
[34m==>[0m [1mPouring libssh--0.12.2_1.arm64_sequoia.bottle.tar.gz[0m
🍺  /opt/homebrew/Cellar/libssh/0.12.2_1: 25 files, 1.7MB
[32m==>[0m [1mInstalling qemu dependency: [32mncurses[39m (6.6)[0m
[34m==>[0m [1mPouring ncurses--6.6.arm64_sequoia.bottle.tar.gz[0m
🍺  /opt/homebrew/Cellar/ncurses/6.6: 4,086 files, 10.3MB
[32m==>[0m [1mInstalling qemu dependency: [32msnappy[39m (1.3.1)[0m
[34m==>[0m [1mPouring snappy--1.3.1.arm64_sequoia.bottle.tar.gz[0m
🍺  /opt/homebrew/Cellar/snappy/1.3.1: 20 files, 171.6KB
[32m==>[0m [1mInstalling qemu dependency: [32mvde[39m (2.3.3)[0m
[34m==>[0m [1mPouring vde--2.3.3.arm64_sequoia.bottle.tar.gz[0m
🍺  /opt/homebrew/Cellar/vde/2.3.3: 67 files, 1.2MB
[32m==>[0m [1mInstalling [32mqemu[39m[0m
[34m==>[0m [1mPouring qemu--11.1.3.arm64_sequoia.bottle.tar.gz[0m
🍺  /opt/homebrew/Cellar/qemu/11.1.3: 170 files, 729MB
QEMU emulator version 11.1.3
wrote out/qemu/kernel.adt (12384 bytes) from nio-qemu-hardware.json
cmdline: -v keepsyms=1 kt_fixed_zones=120 nio-gpu=8 native-ufs-root=1 native-ufs-probe=12 native-ufs-diagnostics=1 nio_skip_security_extensions=1 unentitled_ios_sim_launch=1 ignition_level=1 launchd_unsecure_cache=1 -wdt_no_pmu wdt=-1 wdt_test=no_user_checkin amfi_get_out_of_my_way=1 amfi_allow_any_signature=1
no kernel.macho to boot in QEMU
```

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
03:46:49 prepare: started in /Users/runner/work/UniXNU-nio/UniXNU-nio
03:46:49 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/mach.development.bcm2837.unstripped
03:46:49 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/link.filelist
03:46:49 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o
03:46:49 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/iokit/DEVELOPMENT/IOService.o
traced script start: scripts/build-xnu-4k-baseline.sh
traced before/after make: scripts/build-xnu-4k-baseline.sh
03:46:49 syntax ok: scripts/build-xnu-4k-baseline.sh
03:46:49 script absent: out/nio/ios-16.5-20F66/nio/tree/scripts/build-xnu-4k-baseline.sh
03:46:49 prepare: done
base=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio
record=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o.json exists=False
tree object=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o exists=False
no decodable compile record; nothing to replay
replay object missing=True
```

## kernel-bootstrap.log

### the errors

```
24524: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
24530: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
492620: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
492631: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
492642: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
492653: 1413 |                     "| error: latency %d too big (> 1 sec)",
492664: 1420 |                     "| error: jitter %dms too big (latency %dms)",
492675: 1420 |                     "| error: jitter %dms too big (latency %dms)",
492686: 1438 |                     "| error: loss recovery %dms too big",
492697: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
492708: 1463 |                     "| error: output interval %dms too big",
602577: 2626 |                 FDLOG(LOG_ERR, fd_cb, "failed to get the close error: %d", error);
604309: 4398 |                                 FDLOG(LOG_DEBUG, &nil_pcb, "ctl_enqueuembuf returned an error: %d", error);
630788:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
630896:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
637802:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
637814:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
675174:  275 |         SASEL_LOG("Returned with error: %d", err);
1047133: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
1047139: 3383 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
1531198:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:256:5: error: unknown type name 'DTEntry'
1531201:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:257:21: error: use of undeclared identifier 'kSuccess'
1531204:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:258:21: error: use of undeclared identifier 'kSuccess'
1531207:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:259:21: error: use of undeclared identifier 'kSuccess'
1531211:make[7]: *** [IOStartIOKit.cpo] Error 1
1531212:make[6]: *** [build_all] Error 2
1531213:make[5]: *** [do_all] Error 2
1531214:make[4]: *** [build_all] Error 2
1531215:make[3]: *** [build_all_recurse_into_conf] Error 2
1531216:make[2]: *** [build_all_recurse_into_iokit] Error 2
1531217:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
1531218:make: *** [build] Error 2
```

### around them

```
24518- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
24519-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
24520-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
24521-  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
24522-      |                 ~~               ^~~~~~~~~~~
24523-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
24524: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
24525-      |                                                                                ~~~
24526-      |                                                                                %zu
24527- 1414 |                                             path, mc_error, fatal_failure_desc_len);
24528-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
24529-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
24530: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
24531-      |                                                                                                   ~~~
24532-      |                                                                                                   %zu
24533- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
24534-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
24535-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
24536- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
24537-      |                             ^
24538-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
24539- 1426 |                 zfree(ZV_NAMEI, vn_path);
24540-      |                 ^
--
492614- 1284 |         kfree_type_impl(kt_view_var, os_ptr_load_and_erase(elem));             \
492615-      |                                      ^
492616-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h:67:14: note: expanded from macro 'os_ptr_load_and_erase'
492617-   67 |         __auto_type __elem = *__eptr;                             \
492618-      |                     ^
492619-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1387:7: warning: format specifies type 'int' but the argument has underlying type 'unsigned int' [-Wformat]
492620: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
492621-      |                                                                      ~~
492622-      |                                                                      %u
492623- 1387 |                     p->ifnetem_model);
492624-      |                     ^~~~~~~~~~~~~~~~
492625-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
492626-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
492627-      |                                                    ~~~~
492628-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
492629-      |                                             ^~~~~~~~~~~
492630-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1393:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
492631: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
492632-      |                                                           ~~
492633-      |                                                           %u
492634- 1393 |                     p->ifnetem_corruption_p, NETEM_PSCALE);
492635-      |                     ^~~~~~~~~~~~~~~~~~~~~~~
492636-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
492637-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
492638-      |                                                    ~~~~
492639-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
492640-      |                                             ^~~~~~~~~~~
492641-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1399:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
492642: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
492643-      |                                                            ~~
492644-      |                                                            %u
492645- 1399 |                     p->ifnetem_duplication_p, NETEM_PSCALE);
492646-      |                     ^~~~~~~~~~~~~~~~~~~~~~~~
492647-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
492648-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
492649-      |                                                    ~~~~
492650-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
492651-      |                                             ^~~~~~~~~~~
492652-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1414:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
492653: 1413 |                     "| error: latency %d too big (> 1 sec)",
492654-      |                                       ~~
492655-      |                                       %u
492656- 1414 |                     p->ifnetem_latency_ms);
492657-      |                     ^~~~~~~~~~~~~~~~~~~~~
492658-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
492659-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
492660-      |                                                    ~~~~
492661-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
492662-      |                                             ^~~~~~~~~~~
492663-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1421:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
492664: 1420 |                     "| error: jitter %dms too big (latency %dms)",
492665-      |                                      ~~
492666-      |                                      %u
492667- 1421 |                     p->ifnetem_jitter_ms, p->ifnetem_latency_ms);
492668-      |                     ^~~~~~~~~~~~~~~~~~~~
492669-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
492670-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
492671-      |                                                    ~~~~
492672-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
492673-      |                                             ^~~~~~~~~~~
492674-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1421:29: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
492675: 1420 |                     "| error: jitter %dms too big (latency %dms)",
492676-      |                                                            ~~
492677-      |                                                            %u
492678- 1421 |                     p->ifnetem_jitter_ms, p->ifnetem_latency_ms);
492679-      |                                           ^~~~~~~~~~~~~~~~~~~~~
492680-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
492681-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
492682-      |                                                    ~~~~
492683-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
492684-      |                                             ^~~~~~~~~~~
492685-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1439:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
492686: 1438 |                     "| error: loss recovery %dms too big",
492687-      |                                             ~~
492688-      |                                             %u
492689- 1439 |                     p->ifnetem_loss_recovery_ms);
492690-      |                     ^~~~~~~~~~~~~~~~~~~~~~~~~~~
492691-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
492692-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
492693-      |                                                    ~~~~
492694-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
492695-      |                                             ^~~~~~~~~~~
492696-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1457:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
492697: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
492698-      |                                                         ~~
492699-      |                                                         %u
492700- 1457 |                     p->ifnetem_reordering_p, NETEM_PSCALE);
492701-      |                     ^~~~~~~~~~~~~~~~~~~~~~~
492702-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
492703-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
492704-      |                                                    ~~~~
492705-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
492706-      |                                             ^~~~~~~~~~~
492707-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1464:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
492708: 1463 |                     "| error: output interval %dms too big",
492709-      |                                               ~~
```

### the tail

```
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:220:3: warning: use of OSPtr outside of a return type [-Wossharedptr-misuse]
  220 |                 OSPtr<OSString>     providerExpert = OSString::withCString("IOPlatformExpertDevice");
      |                 ^~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:221:3: warning: use of OSPtr outside of a return type [-Wossharedptr-misuse]
  221 |                 OSPtr<OSString>     providerDevice = OSString::withCString("IOPlatformDevice");
      |                 ^~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:222:3: warning: use of OSPtr outside of a return type [-Wossharedptr-misuse]
  222 |                 OSPtr<OSString>     nameMatch      = OSString::withCString("device-tree");
      |                 ^~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:223:3: warning: use of OSPtr outside of a return type [-Wossharedptr-misuse]
  223 |                 OSPtr<OSNumber>     scorePlatform  = OSNumber::withNumber(5000, 32);
      |                 ^~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:224:3: warning: use of OSPtr outside of a return type [-Wossharedptr-misuse]
  224 |                 OSPtr<OSNumber>     scoreStorage   = OSNumber::withNumber(1000, 32);
      |                 ^~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:225:3: warning: use of OSPtr outside of a return type [-Wossharedptr-misuse]
  225 |                 OSPtr<OSNumber>     scoreRoot      = OSNumber::withNumber(500, 32);
      |                 ^~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:256:5: error: unknown type name 'DTEntry'
  256 |                                 DTEntry found;
      |                                 ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:257:21: error: use of undeclared identifier 'kSuccess'
  257 |                                 int hasArmIo = (kSuccess == SecureDTLookupEntry(NULL, "/arm-io", &found));
      |                                                 ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:258:21: error: use of undeclared identifier 'kSuccess'
  258 |                                 int hasIntc  = (kSuccess == SecureDTLookupEntry(NULL, "/arm-io/intc", &found));
      |                                                 ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:259:21: error: use of undeclared identifier 'kSuccess'
  259 |                                 int hasUfs   = (kSuccess == SecureDTLookupEntry(NULL, "/arm-io/ufs", &found));
      |                                                 ^
899 warnings and 4 errors generated.
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
[03:47:28] script start (bootstrap=1 jobs=3)
  object MISSING
  source sha d48af909f338b58d
[03:48:58] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha d48af909f338b58d
[03:54:37] script start (bootstrap=1 jobs=3)
  object MISSING
  source sha d48af909f338b58d
[03:54:38] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha d48af909f338b58d
[03:58:50] script start (bootstrap=1 jobs=3)
  object MISSING
  source sha d48af909f338b58d
[03:58:51] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha d48af909f338b58d
```

## build-console.log

### the errors

```
15:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:256:5: error: unknown type name 'DTEntry'
18:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:257:21: error: use of undeclared identifier 'kSuccess'
21:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:258:21: error: use of undeclared identifier 'kSuccess'
24:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:259:21: error: use of undeclared identifier 'kSuccess'
```

### around them

```
7-  223 |                 OSPtr<OSNumber>     scorePlatform  = OSNumber::withNumber(5000, 32);
8-      |                 ^~~~~~~~~~~~~~~
9-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:224:3: warning: use of OSPtr outside of a return type [-Wossharedptr-misuse]
10-  224 |                 OSPtr<OSNumber>     scoreStorage   = OSNumber::withNumber(1000, 32);
11-      |                 ^~~~~~~~~~~~~~~
12-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:225:3: warning: use of OSPtr outside of a return type [-Wossharedptr-misuse]
13-  225 |                 OSPtr<OSNumber>     scoreRoot      = OSNumber::withNumber(500, 32);
14-      |                 ^~~~~~~~~~~~~~~
15:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:256:5: error: unknown type name 'DTEntry'
16-  256 |                                 DTEntry found;
17-      |                                 ^
18:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:257:21: error: use of undeclared identifier 'kSuccess'
19-  257 |                                 int hasArmIo = (kSuccess == SecureDTLookupEntry(NULL, "/arm-io", &found));
20-      |                                                 ^
21:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:258:21: error: use of undeclared identifier 'kSuccess'
22-  258 |                                 int hasIntc  = (kSuccess == SecureDTLookupEntry(NULL, "/arm-io/intc", &found));
23-      |                                                 ^
24:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:259:21: error: use of undeclared identifier 'kSuccess'
25-  259 |                                 int hasUfs   = (kSuccess == SecureDTLookupEntry(NULL, "/arm-io/ufs", &found));
26-      |                                                 ^
27-899 warnings and 4 errors generated.
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
patch    151 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-heartbeat-noinline.patch
patch    152 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-arbitration-probe-decl.patch
patch    153 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-arbitration-unlock-probe.patch
patch    154 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-arbitration-probe-u3.patch
patch    155 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-start-name-direct.patch
patch    156 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-arbitration-lock-probe.patch
patch    157 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-mark-service-seq.patch
patch    158 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-name-six-and-match-rounds.patch
patch    159 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-arbitration-out-of-path.patch
patch    160 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-probe-entry-marks.patch
patch    161 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-skip-unmatched-classes.patch
patch    162 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-busy-beacon.patch
patch    163 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-static-kext-personalities.patch
patch    164 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-root-nub-name.patch
patch    165 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-device-tree-physical.patch
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
