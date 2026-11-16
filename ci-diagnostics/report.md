# Why the build failed

run: 440, commit 9ca279994ecbc3981868493db164e4e22fa8c769

## qemu-run.log

### the tail

```
[32m==>[0m [1mFetching downloads for: [32mqemu[39m[0m
✔︎ Bottle Manifest capstone (5.0.9)
✔︎ Bottle Manifest libslirp (4.9.3)
✔︎ Bottle Manifest libssh (0.12.2)
✔︎ Bottle Manifest ncurses (6.6)
✔︎ Bottle libslirp (4.9.3)
✔︎ Bottle Manifest snappy (1.2.2)
✔︎ Bottle libssh (0.12.2)
✔︎ Bottle capstone (5.0.9)
✔︎ Bottle Manifest vde (2.3.3)
✔︎ Bottle snappy (1.2.2)
✔︎ Bottle vde (2.3.3)
✔︎ Bottle ncurses (6.6)
✔︎ Bottle qemu (11.1.0)
[32m==>[0m [1mInstalling dependencies for qemu:[0m [32mcapstone[39m, [32mlibslirp[39m, [32mlibssh[39m, [32mncurses[39m, [32msnappy[39m and [32mvde[39m[0m
[32m==>[0m [1mInstalling qemu dependency: [32mcapstone[39m[0m
[34m==>[0m [1mPouring capstone--5.0.9.sonoma.bottle.tar.gz[0m
🍺  /usr/local/Cellar/capstone/5.0.9: 31 files, 23MB
[32m==>[0m [1mInstalling qemu dependency: [32mlibslirp[39m[0m
[34m==>[0m [1mPouring libslirp--4.9.3.sonoma.bottle.tar.gz[0m
🍺  /usr/local/Cellar/libslirp/4.9.3: 13 files, 354KB
[32m==>[0m [1mInstalling qemu dependency: [32mlibssh[39m[0m
[34m==>[0m [1mPouring libssh--0.12.2.sonoma.bottle.tar.gz[0m
🍺  /usr/local/Cellar/libssh/0.12.2: 25 files, 1.6MB
[32m==>[0m [1mInstalling qemu dependency: [32mncurses[39m[0m
[34m==>[0m [1mPouring ncurses--6.6.sonoma.bottle.tar.gz[0m
🍺  /usr/local/Cellar/ncurses/6.6: 4,086 files, 9.9MB
[32m==>[0m [1mInstalling qemu dependency: [32msnappy[39m[0m
[34m==>[0m [1mPouring snappy--1.2.2.sonoma.bottle.tar.gz[0m
🍺  /usr/local/Cellar/snappy/1.2.2: 19 files, 145.0KB
[32m==>[0m [1mInstalling qemu dependency: [32mvde[39m[0m
[34m==>[0m [1mPouring vde--2.3.3.sonoma.bottle.tar.gz[0m
🍺  /usr/local/Cellar/vde/2.3.3: 66 files, 1.1MB
[32m==>[0m [1mInstalling [32mqemu[39m[0m
[34m==>[0m [1mPouring qemu--11.1.0.sonoma.bottle.tar.gz[0m
🍺  /usr/local/Cellar/qemu/11.1.0: 170 files, 704.9MB
QEMU emulator version 11.1.0
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
17:58:41 prepare: started in /Users/runner/work/UniXNU-nio/UniXNU-nio
17:58:41 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/mach.development.bcm2837.unstripped
17:58:41 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/link.filelist
17:58:41 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o
17:58:41 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/iokit/DEVELOPMENT/IOService.o
traced script start: scripts/build-xnu-4k-baseline.sh
traced before/after make: scripts/build-xnu-4k-baseline.sh
17:58:42 syntax ok: scripts/build-xnu-4k-baseline.sh
17:58:42 script absent: out/nio/ios-16.5-20F66/nio/tree/scripts/build-xnu-4k-baseline.sh
17:58:42 prepare: done
base=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio
record=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o.json exists=False
tree object=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o exists=False
no decodable compile record; nothing to replay
replay object missing=True
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
1534919:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:230:54: error: member reference type 'OSPtr<OSString>' (aka 'OSString *') is a pointer; did you mean to use '->'?
1534923:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:230:55: error: no member named 'get' in 'OSString'
1534926:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:231:63: error: member reference type 'OSPtr<OSString>' (aka 'OSString *') is a pointer; did you mean to use '->'?
1534930:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:231:64: error: no member named 'get' in 'OSString'
1534933:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:232:54: error: member reference type 'OSPtr<OSString>' (aka 'OSString *') is a pointer; did you mean to use '->'?
1534937:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:232:55: error: no member named 'get' in 'OSString'
1534940:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:233:59: error: member reference type 'OSPtr<OSNumber>' (aka 'OSNumber *') is a pointer; did you mean to use '->'?
1534944:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:233:60: error: no member named 'get' in 'OSNumber'
1534947:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:234:43: error: member reference type 'OSPtr<OSDictionary>' (aka 'OSDictionary *') is a pointer; did you mean to use '->'?
1534951:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:234:44: error: no member named 'get' in 'OSDictionary'
1534954:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:236:46: error: member reference type 'OSPtr<OSString>' (aka 'OSString *') is a pointer; did you mean to use '->'?
1534958:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:236:47: error: no member named 'get' in 'OSString'
1534961:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:237:56: error: member reference type 'OSPtr<OSString>' (aka 'OSString *') is a pointer; did you mean to use '->'?
1534965:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:237:57: error: no member named 'get' in 'OSString'
1534968:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:238:51: error: member reference type 'OSPtr<OSNumber>' (aka 'OSNumber *') is a pointer; did you mean to use '->'?
1534972:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:238:52: error: no member named 'get' in 'OSNumber'
1534975:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:239:36: error: member reference type 'OSPtr<OSDictionary>' (aka 'OSDictionary *') is a pointer; did you mean to use '->'?
1534979:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:239:37: error: no member named 'get' in 'OSDictionary'
1534982:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:241:50: error: member reference type 'OSPtr<OSString>' (aka 'OSString *') is a pointer; did you mean to use '->'?
1534986:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:241:51: error: no member named 'get' in 'OSString'
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
  241 |                         storageRoot->setObject("IOClass", classStorage.get());
      |                                                           ~~~~~~~~~~~~ ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:242:60: error: member reference type 'OSPtr<OSString>' (aka 'OSString *') is a pointer; did you mean to use '->'?
  242 |                         storageRoot->setObject("IOProviderClass", providerExpert.get());
      |                                                                   ~~~~~~~~~~~~~~^
      |                                                                                 ->
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:242:61: error: no member named 'get' in 'OSString'
  242 |                         storageRoot->setObject("IOProviderClass", providerExpert.get());
      |                                                                   ~~~~~~~~~~~~~~ ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:243:52: error: member reference type 'OSPtr<OSNumber>' (aka 'OSNumber *') is a pointer; did you mean to use '->'?
  243 |                         storageRoot->setObject("IOProbeScore", scoreRoot.get());
      |                                                                ~~~~~~~~~^
      |                                                                         ->
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:243:53: error: no member named 'get' in 'OSNumber'
  243 |                         storageRoot->setObject("IOProbeScore", scoreRoot.get());
      |                                                                ~~~~~~~~~ ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:244:40: error: member reference type 'OSPtr<OSDictionary>' (aka 'OSDictionary *') is a pointer; did you mean to use '->'?
  244 |                         personalities->setObject(storageRoot.get());
      |                                                  ~~~~~~~~~~~^
      |                                                             ->
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:244:41: error: no member named 'get' in 'OSDictionary'
  244 |                         personalities->setObject(storageRoot.get());
      |                                                  ~~~~~~~~~~~ ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:248:42: error: member reference type 'OSPtr<OSArray>' (aka 'OSArray *') is a pointer; did you mean to use '->'?
  248 |                         gIOCatalogue->addDrivers(personalities.get(), false);
      |                                                  ~~~~~~~~~~~~~^
      |                                                               ->
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:248:43: error: no member named 'get' in 'OSArray'
  248 |                         gIOCatalogue->addDrivers(personalities.get(), false);
      |                                                  ~~~~~~~~~~~~~ ^
899 warnings and 28 errors generated.
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
[18:01:57] script start (bootstrap=1 jobs=4)
  object MISSING
  source sha d48af909f338b58d
[18:05:24] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha d48af909f338b58d
```

## build-console.log

### the errors

```
178:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:243:53: error: no member named 'get' in 'OSNumber'
181:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:244:40: error: member reference type 'OSPtr<OSDictionary>' (aka 'OSDictionary *') is a pointer; did you mean to use '->'?
185:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:244:41: error: no member named 'get' in 'OSDictionary'
188:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:248:42: error: member reference type 'OSPtr<OSArray>' (aka 'OSArray *') is a pointer; did you mean to use '->'?
192:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:248:43: error: no member named 'get' in 'OSArray'
```

### around them

```
170-== kernel: patch nio-static-kext-personalities.patch
171-+ python3 /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/scripts/prepare-xnu-source.py
172-Restored 0 omitted public headers from Apple; blob hashes verified
173-== kernel: bootstrap pass for the compile records
174-+ bash /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/scripts/build-xnu-4k-baseline.sh
175-  243 |                         storageRoot->setObject("IOProbeScore", scoreRoot.get());
176-      |                                                                ~~~~~~~~~^
177-      |                                                                         ->
178:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:243:53: error: no member named 'get' in 'OSNumber'
179-  243 |                         storageRoot->setObject("IOProbeScore", scoreRoot.get());
180-      |                                                                ~~~~~~~~~ ^
181:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:244:40: error: member reference type 'OSPtr<OSDictionary>' (aka 'OSDictionary *') is a pointer; did you mean to use '->'?
182-  244 |                         personalities->setObject(storageRoot.get());
183-      |                                                  ~~~~~~~~~~~^
184-      |                                                             ->
185:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:244:41: error: no member named 'get' in 'OSDictionary'
186-  244 |                         personalities->setObject(storageRoot.get());
187-      |                                                  ~~~~~~~~~~~ ^
188:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:248:42: error: member reference type 'OSPtr<OSArray>' (aka 'OSArray *') is a pointer; did you mean to use '->'?
189-  248 |                         gIOCatalogue->addDrivers(personalities.get(), false);
190-      |                                                  ~~~~~~~~~~~~~^
191-      |                                                               ->
192:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOStartIOKit.cpp:248:43: error: no member named 'get' in 'OSArray'
193-  248 |                         gIOCatalogue->addDrivers(personalities.get(), false);
194-      |                                                  ~~~~~~~~~~~~~ ^
195-899 warnings and 28 errors generated.
196-make[7]: *** [IOStartIOKit.cpo] Error 1
197-make[6]: *** [build_all] Error 2
198-make[5]: *** [do_all] Error 2
199-make[4]: *** [build_all] Error 2
200-make[3]: *** [build_all_recurse_into_conf] Error 2
201-make[2]: *** [build_all_recurse_into_iokit] Error 2
202-make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
203-make: *** [build] Error 2
204-build-xnu-4k-baseline.sh: line 866: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

## status.txt

```
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
patch    163 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-dt-head-report.patch
patch    164 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-static-kext-personalities.patch
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
