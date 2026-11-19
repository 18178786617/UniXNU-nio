# Why the build failed

run: 562, commit c355691473df698972f9681f40d56cbd1569fcd9

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
17:33:55 prepare: started in /Users/runner/work/UniXNU-nio/UniXNU-nio
17:33:55 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/mach.development.bcm2837.unstripped
17:33:55 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/link.filelist
17:33:55 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o
17:33:55 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/iokit/DEVELOPMENT/IOService.o
traced script start: scripts/build-xnu-4k-baseline.sh
traced before/after make: scripts/build-xnu-4k-baseline.sh
17:33:55 syntax ok: scripts/build-xnu-4k-baseline.sh
17:33:55 script absent: out/nio/ios-16.5-20F66/nio/tree/scripts/build-xnu-4k-baseline.sh
17:33:55 prepare: done
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
1539399:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:8:4: error: expected unqualified-id
1539700:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:666:1: error: unknown type name 'kern_return_t'
1539703:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:807:1: error: unknown type name 'kern_return_t'
1539706:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:830:8: error: unknown type name 'kern_return_t'
1539709:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:860:9: error: unknown type name 'kern_return_t'
1539712:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:870:9: error: unknown type name 'kern_return_t'
1539715:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:881:8: error: unknown type name 'kern_return_t'
1539718:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:900:1: error: unknown type name 'kern_return_t'
1539732:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/message.h:1164:9: error: unknown type name 'kern_return_t'
1539740:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/vm_statistics.h:174:1: error: unknown type name 'kern_return_t'
1539786:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/host_info.h:315:8: error: unknown type name 'kern_return_t'
1539789:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/host_info.h:318:8: error: unknown type name 'kern_return_t'
1539805:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/memory_object_types.h:142:2: error: unknown type name 'kern_return_t'
1539808:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/memory_object_types.h:146:2: error: unknown type name 'kern_return_t'
1539811:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/memory_object_types.h:148:2: error: unknown type name 'kern_return_t'
1539814:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/memory_object_types.h:154:2: error: unknown type name 'kern_return_t'
1539817:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/memory_object_types.h:163:2: error: unknown type name 'kern_return_t'
1539826:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/memory_object_types.h:182:2: error: unknown type name 'kern_return_t'
1539829:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/memory_object_types.h:185:2: error: unknown type name 'kern_return_t'
1539864:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/mach/kmod.h:59:9: error: unknown type name 'kern_return_t'
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
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/Kernel/IOService.cpp:9254:3: warning: identifier '__elem' is reserved because it starts with '__' [-Wreserved-identifier]
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
1069 warnings and 1043 errors generated.
make[7]: *** [IOService.cpo] Error 1
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
[17:34:36] script start (bootstrap=1 jobs=4)
  object MISSING
  source sha 64f89e7cf469a3a6
[17:37:06] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha 64f89e7cf469a3a6
[17:43:36] script start (bootstrap=1 jobs=4)
  object MISSING
  source sha 64f89e7cf469a3a6
[17:43:37] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha 64f89e7cf469a3a6
[17:50:27] script start (bootstrap=1 jobs=4)
  object MISSING
  source sha 64f89e7cf469a3a6
[17:50:28] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha 64f89e7cf469a3a6
```

## status.txt

```
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
