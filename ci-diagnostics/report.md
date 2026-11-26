# Why the build failed

run: 783, commit b4267434ec2d41cd0c99d318b25725cc5643ad1c

## replay.log

### the tail

```
base=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio
record=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o.json exists=True
tree object=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o exists=True
recorded file=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/osfmk/kern/startup.c output=startup.o
replaying 452 arguments in /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT
replay rc=0
preprocess rc=0
preprocessed bytes=1410883 has HB=False
preprocessed bytes=1410883 has hb-started=False
replay bytes=113304 tree bytes=113304 identical=True
replay has HB=False tree has HB=False
object magic=cffaedfe
object nio contexts (12): [b'work/UniXNU-nio/UniXNU-nio/out/nio/i', b'-nio/UniXNU-nio/out/nio/ipados-17.7.', b'XNU-nio/out/nio/ipados-17.7.11-21H46', b'7.11-21H461/nio/tree/.cache/xnu-work', b'work/UniXNU-nio/UniXNU-nio/out/nio/i', b'-nio/UniXNU-nio/out/nio/ipados-17.7.', b'XNU-nio/out/nio/ipados-17.7.11-21H46', b'7.11-21H461/nio/tree/build/xnu/ios-o', b'work/UniXNU-nio/UniXNU-nio/out/nio/i', b'-nio/UniXNU-nio/out/nio/ipados-17.7.', b'XNU-nio/out/nio/ipados-17.7.11-21H46', b'7.11-21H461/nio/tree/build/xnu/ios-o']
object has leading-newline form=False
replay sha=df3530a2a04917b4 tree sha=df3530a2a04917b4
assembly rc=0
assembly lines=28499 has HB=False
assembly calls to nio_dc_puts=0
  asm: no _nio_heartbeat_thread label
```

## ci-steps.log

### the tail

```
16:07:21 prepare: started in /Users/runner/work/UniXNU-nio/UniXNU-nio
16:07:21 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/mach.development.bcm2837.unstripped
16:07:21 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/link.filelist
16:07:21 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o
16:07:21 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/iokit/DEVELOPMENT/IOService.o
16:07:21 no build tree yet: out/nio/*/nio/tree/scripts/build-xnu-4k-baseline.sh absent
traced script start: scripts/build-xnu-4k-baseline.sh
traced before/after make: scripts/build-xnu-4k-baseline.sh
16:07:21 syntax ok: scripts/build-xnu-4k-baseline.sh
16:07:21 prepare: done
base=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio
record=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o.json exists=True
tree object=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o exists=True
recorded file=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/osfmk/kern/startup.c output=startup.o
replaying 452 arguments in /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT
replay rc=0
preprocess rc=0
preprocessed bytes=1410883 has HB=False
preprocessed bytes=1410883 has hb-started=False
replay bytes=113304 tree bytes=113304 identical=True
replay has HB=False tree has HB=False
object magic=cffaedfe
object nio contexts (12): [b'work/UniXNU-nio/UniXNU-nio/out/nio/i', b'-nio/UniXNU-nio/out/nio/ipados-17.7.', b'XNU-nio/out/nio/ipados-17.7.11-21H46', b'7.11-21H461/nio/tree/.cache/xnu-work', b'work/UniXNU-nio/UniXNU-nio/out/nio/i', b'-nio/UniXNU-nio/out/nio/ipados-17.7.', b'XNU-nio/out/nio/ipados-17.7.11-21H46', b'7.11-21H461/nio/tree/build/xnu/ios-o', b'work/UniXNU-nio/UniXNU-nio/out/nio/i', b'-nio/UniXNU-nio/out/nio/ipados-17.7.', b'XNU-nio/out/nio/ipados-17.7.11-21H46', b'7.11-21H461/nio/tree/build/xnu/ios-o']
object has leading-newline form=False
replay sha=df3530a2a04917b4 tree sha=df3530a2a04917b4
assembly rc=0
assembly lines=28499 has HB=False
assembly calls to nio_dc_puts=0
  asm: no _nio_heartbeat_thread label
```

## kernel.log

### the errors

```
3233: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
3239: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
3896: 1384 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
54442:  158 |                 printf("buffer_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
56020:  268 |                 printf("(%s) Failed to handle availability of LZ4. Error 0x%x\n", __func__, ret);
57538:  102 |                 printf("progress_notify_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
59203:  272 |                 printf("zlib_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
59474:  143 |                 printf("%s failed to allocate memory. Error 0x%x\n", __func__, ret);
221578: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
221589: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
221600: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
221611: 1413 |                     "| error: latency %d too big (> 1 sec)",
221622: 1420 |                     "| error: jitter %dms too big (latency %dms)",
221633: 1420 |                     "| error: jitter %dms too big (latency %dms)",
221644: 1438 |                     "| error: loss recovery %dms too big",
221655: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
221666: 1463 |                     "| error: output interval %dms too big",
317210: 3406 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
317216: 3411 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
342814:Undefined symbols for architecture arm64:
342888:ld: symbol(s) not found for architecture arm64
342889:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
342890:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped.noctf] Error 1
342891:make[2]: *** [build_all] Error 2
342892:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
342893:make: *** [build] Error 2
```

### around them

```
3227- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
3228-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
3229-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:597:27: note: expanded from macro 'panic'
3230-  597 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
3231-      |                 ~~               ^~~~~~~~~~~
3232-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
3233: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
3234-      |                                                                                ~~~
3235-      |                                                                                %zu
3236- 1414 |                                             path, mc_error, fatal_failure_desc_len);
3237-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
3238-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
3239: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
3240-      |                                                                                                   ~~~
3241-      |                                                                                                   %zu
3242- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
3243-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
3244-109 warnings generated.
3245-            C++ KernelConfigTables.cpo
3246-clang++: warning: no such include directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa' [-Wmissing-include-dirs]
3247-             CC ctrr_test_sysctl.o
3248-clang: warning: no such include directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa' [-Wmissing-include-dirs]
3249-            C++ IOKitBSDInit.cpo
--
3890- 1374 |                         IOLog("Failed to open corefile of size %llu MB (returned error 0x%x)\n",
3891-      |                                                                                          ~~
3892-      |                                                                                          %x
3893- 1375 |                             (corefile_fallback_size_bytes / (1024ULL * 1024ULL)), err);
3894-      |                                                                                   ^~~
3895-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1384:76: warning: format specifies type 'unsigned int' but the argument has type 'IOReturn' (aka 'int') [-Wformat]
3896: 1384 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
3897-      |                                                                                   ~~     ^~~
3898-      |                                                                                   %x
3899-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1467:2: warning: 'switch' missing 'default' label [-Wswitch-default]
3900- 1467 |         switch (op) {
3901-      |         ^
3902-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/iokit/bsddev/IOKitBSDInit.cpp:1550:20: warning: cast from 'void (*)(vm_allocation_site_t *)' (aka 'void (*)(vm_allocation_site *)') to 'void (*)(const void *)' converts to incompatible function type [-Wcast-function-type-strict]
3903- 1550 |         c_string = (char*)kalloc_data(string_length, (zalloc_flags_t)(Z_ZERO | Z_WAITOK | Z_NOFAIL));
3904-      |                           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
3905-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/kalloc.h:512:2: note: expanded from macro 'kalloc_data'
3906-  512 |         kheap_alloc(KHEAP_DATA_BUFFERS, size, flags)
--
221572-      |                  ~~~~~~~~~~~~~~~~~~~ ^  ~~~~~~~~~~~~~~~~
221573-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1303:30: warning: comparison of different enumeration types ('if_netem_model_t' and 'netem_model_t') [-Wenum-compare]
221574- 1303 |         _CASSERT(IF_NETEM_MODEL_NLC == NETEM_MODEL_NLC);
221575-      |                  ~~~~~~~~~~~~~~~~~~ ^  ~~~~~~~~~~~~~~~
221576-             CC vfs_nspace_user.o
221577-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1387:7: warning: format specifies type 'int' but the argument has underlying type 'unsigned int' [-Wformat]
221578: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
221579-      |                                                                      ~~
221580-      |                                                                      %u
221581- 1387 |                     p->ifnetem_model);
221582-      |                     ^~~~~~~~~~~~~~~~
221583-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
221584-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
221585-      |                                                    ~~~~
221586-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
221587-      |                                             ^~~~~~~~~~~
221588-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1393:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
221589: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
221590-      |                                                           ~~
221591-      |                                                           %u
221592- 1393 |                     p->ifnetem_corruption_p, NETEM_PSCALE);
221593-      |                     ^~~~~~~~~~~~~~~~~~~~~~~
221594-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
221595-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
221596-      |                                                    ~~~~
221597-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
221598-      |                                             ^~~~~~~~~~~
221599-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1399:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
221600: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
221601-      |                                                            ~~
221602-      |                                                            %u
221603- 1399 |                     p->ifnetem_duplication_p, NETEM_PSCALE);
221604-      |                     ^~~~~~~~~~~~~~~~~~~~~~~~
221605-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
221606-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
221607-      |                                                    ~~~~
221608-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
221609-      |                                             ^~~~~~~~~~~
221610-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1414:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
221611: 1413 |                     "| error: latency %d too big (> 1 sec)",
221612-      |                                       ~~
221613-      |                                       %u
221614- 1414 |                     p->ifnetem_latency_ms);
221615-      |                     ^~~~~~~~~~~~~~~~~~~~~
221616-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
221617-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
221618-      |                                                    ~~~~
221619-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
221620-      |                                             ^~~~~~~~~~~
221621-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1421:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
221622: 1420 |                     "| error: jitter %dms too big (latency %dms)",
221623-      |                                      ~~
221624-      |                                      %u
221625- 1421 |                     p->ifnetem_jitter_ms, p->ifnetem_latency_ms);
221626-      |                     ^~~~~~~~~~~~~~~~~~~~
221627-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
221628-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
221629-      |                                                    ~~~~
221630-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
221631-      |                                             ^~~~~~~~~~~
221632-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1421:29: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
221633: 1420 |                     "| error: jitter %dms too big (latency %dms)",
221634-      |                                                            ~~
221635-      |                                                            %u
221636- 1421 |                     p->ifnetem_jitter_ms, p->ifnetem_latency_ms);
221637-      |                                           ^~~~~~~~~~~~~~~~~~~~~
221638-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
221639-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
221640-      |                                                    ~~~~
221641-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
221642-      |                                             ^~~~~~~~~~~
221643-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1439:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
221644: 1438 |                     "| error: loss recovery %dms too big",
221645-      |                                             ~~
221646-      |                                             %u
221647- 1439 |                     p->ifnetem_loss_recovery_ms);
221648-      |                     ^~~~~~~~~~~~~~~~~~~~~~~~~~~
221649-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
```

### the tail

```
  "_native_touch_pin_want", referenced from:
      _native_legacy_display_late_probe in libNativeLegacyDisplay.late.a[4](LegacyDisplayProbe.o)
  "_native_touch_ready", referenced from:
      _native_legacy_display_late_probe in libNativeLegacyDisplay.late.a[4](LegacyDisplayProbe.o)
  "_native_touch_ready_ms", referenced from:
      _native_legacy_display_late_probe in libNativeLegacyDisplay.late.a[4](LegacyDisplayProbe.o)
  "_native_touch_stage_name", referenced from:
      _native_legacy_display_late_probe in libNativeLegacyDisplay.late.a[4](LegacyDisplayProbe.o)
  "_native_touch_stage_result", referenced from:
      _native_legacy_display_late_probe in libNativeLegacyDisplay.late.a[4](LegacyDisplayProbe.o)
  "_native_touch_stage_total", referenced from:
      _native_legacy_display_late_probe in libNativeLegacyDisplay.late.a[4](LegacyDisplayProbe.o)
  "_native_touch_stage_value", referenced from:
      _native_legacy_display_late_probe in libNativeLegacyDisplay.late.a[4](LegacyDisplayProbe.o)
  "_native_touch_tlmm_probe", referenced from:
      _native_legacy_display_late_probe in libNativeLegacyDisplay.late.a[4](LegacyDisplayProbe.o)
  "_native_ufs_dpu_map", referenced from:
      NativeLegacyDisplay::start(IOService*) in libNativeLegacyDisplay.late.a[2](NativeLegacyDisplay.late.o)
      NativeLegacyDisplay::directSlot(OSObject*, IOMemoryDescriptor*) in libNativeLegacyDisplay.late.a[2](NativeLegacyDisplay.late.o)
  "_native_ufs_dpu_state", referenced from:
      NativeLegacyDisplay::start(IOService*) in libNativeLegacyDisplay.late.a[2](NativeLegacyDisplay.late.o)
  "_native_ufs_dpu_window_build", referenced from:
      _native_legacy_display_late_probe in libNativeLegacyDisplay.late.a[4](LegacyDisplayProbe.o)
      _native_legacy_display_late_probe in libNativeLegacyDisplay.late.a[4](LegacyDisplayProbe.o)
  "_native_ufs_smmu_base", referenced from:
      _native_legacy_display_late_probe in libNativeLegacyDisplay.late.a[4](LegacyDisplayProbe.o)
      _native_legacy_display_late_probe in libNativeLegacyDisplay.late.a[4](LegacyDisplayProbe.o)
  "_qcom_usb_debug_register_framebuffer", referenced from:
      _native_legacy_gop_mapping_observed in libNativeLegacyDisplay.late.a[4](LegacyDisplayProbe.o)
      _native_legacy_gop_mapping_observed in libNativeLegacyDisplay.late.a[4](LegacyDisplayProbe.o)
  "_sheng_cpufreq_probe", referenced from:
      _native_legacy_display_late_probe in libNativeLegacyDisplay.late.a[4](LegacyDisplayProbe.o)
      _native_legacy_display_late_probe in libNativeLegacyDisplay.late.a[4](LegacyDisplayProbe.o)
ld: symbol(s) not found for architecture arm64
clang++: error: linker command failed with exit code 1 (use -v to see invocation)
make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped.noctf] Error 1
make[2]: *** [build_all] Error 2
make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
make: *** [build] Error 2
build-xnu-4k-baseline.sh: line 887: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

## xnu-trace.log

### the tail

```
[16:07:34] script start (bootstrap=1 jobs=3)
  object MISSING
  source sha 80c4cc3b5db23f09
[16:09:42] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha 80c4cc3b5db23f09
[16:17:57] script start (bootstrap=0 jobs=3)
  object MISSING
  source sha 80c4cc3b5db23f09
[16:17:58] before make (bootstrap=0 jobs=3)
  object MISSING
  source sha 80c4cc3b5db23f09
[16:21:50] script start (bootstrap=0 jobs=3)
  object MISSING
  source sha 80c4cc3b5db23f09
[16:21:51] before make (bootstrap=0 jobs=3)
  object MISSING
  source sha 80c4cc3b5db23f09
[16:25:55] script start (bootstrap=0 jobs=3)
  object MISSING
  source sha 80c4cc3b5db23f09
[16:25:56] before make (bootstrap=0 jobs=3)
  object MISSING
  source sha 80c4cc3b5db23f09
```

## archive-21-build-usb-debug.log

### the tail

```
PASS: 2 USB debug objects archived at /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/usbdebug/libUsbDebug.a
PASS: libUsbDebug.a symbols resolved
```

## archive-20-build-verified-root.log

### the tail

```
PASS: real VerifiedRoot crypto + empty policy table -> libVerifiedRoot.a
      root verification is disabled: no signed policy bundle exists for this board
PASS: DEVELOPMENT_ARM64_BCM2837 holds 888 .o, 123 .cpo, 0 archives, 9 file lists, core absent
PASS: DEVELOPMENT_ARM64_BCM2837 holds 0 .o, 0 .cpo, 0 archives, 0 file lists, core absent
PASS: removed the core image, the file lists and 1021 build products
PASS: 86 patched sources carry a fresh mtime (1 named by git but not on disk)
  bsd/kern/bsd_init.c: mtime 16:25:54, does NOT carry 'nio: bsd_init:'
  iokit/Kernel/IOService.cpp: mtime 16:25:54, does NOT carry 'nio: S1'
  bsd/kern/kern_exec.c: mtime 16:25:54, does NOT carry 'nio: exec: load_init_program enter'
```

## archive-19-build-storage-bindings.log

### the tail

```
0000000000002bc4 T _native_ram_block_gpu_addon
0000000000041728 S _native_ram_block_reads
0000000000041718 S _native_ram_block_ready
0000000000041740 S _native_ram_block_resident_bytes
000000000004174c S _native_ram_block_seed_sha256
0000000000041748 S _native_ram_block_sparse
00000000000026a8 T _native_ram_block_volume_device
0000000000002d2c T _native_ram_block_volume_seed
0000000000041730 S _native_ram_block_writes
                 U _native_ufs_store_gpt_check
                 U _native_ufs_store_mode
                 U _native_ufs_store_open
                 U _native_ufs_store_read
                 U _native_ufs_store_sync
                 U _native_ufs_store_write
                 U _snprintf
                 U _strcmp
                 U _strlcpy
                 U _strlen

original-bindings.o:
fffffff006add1d0 A __ZN20IOBlockStorageDevice10gMetaClassE
fffffff00496f050 A __ZN20IOBlockStorageDevice11requestIdleEv
fffffff00496f068 A __ZN20IOBlockStorageDevice13doSetPriorityEP26IOBlockStorageDeviceExtentjh
fffffff00496f080 A __ZN20IOBlockStorageDevice13doSynchronizeEyyj
fffffff00496ef38 A __ZN20IOBlockStorageDevice13setPropertiesEP8OSObject
fffffff00496f074 A __ZN20IOBlockStorageDevice18doSynchronizeCacheEv
fffffff00496f038 A __ZN20IOBlockStorageDevice18getWriteCacheStateEPb
fffffff00496f044 A __ZN20IOBlockStorageDevice18setWriteCacheStateEb
fffffff00496f08c A __ZN20IOBlockStorageDevice20doGetProvisionStatusEyyPjP35IOBlockStorageProvisionDeviceExtenty
fffffff00496ee30 A __ZN20IOBlockStorageDevice4initEP12OSDictionary
fffffff00496f05c A __ZN20IOBlockStorageDevice7doUnmapEP26IOBlockStorageDeviceExtentjj
fffffff005cb44b0 A __ZN20IOBlockStorageDevice9metaClassE
fffffff00496ed98 A __ZN20IOBlockStorageDeviceC1EPK11OSMetaClass
fffffff00496ed98 A __ZN20IOBlockStorageDeviceC2EPK11OSMetaClass
fffffff00496edb8 A __ZN20IOBlockStorageDeviceD2Ev
fffffff00496ee88 A __ZNK20IOBlockStorageDevice11getPropertyEPK8OSSymbol
fffffff00496edc4 A __ZNK20IOBlockStorageDevice12getMetaClassEv
fffffff005cb44c0 A __ZTV20IOBlockStorageDevice

```

## component-RamBlock.log

### the tail

```
RamBlock: -Werror build and arm64-apple-ios17.0 object audit passed
```

## archive-17-build-storage-bindings.log

### the tail

```
                 U __ZNK9IOService9getClientEv
00000000000010b8 S __ZTV17NativeVirtioBlock
                 U __ZTV20IOBlockStorageDevice
00000000000016c0 S __ZTVN17NativeVirtioBlock9MetaClassE
                 U _bzero
                 U _clock_interval_to_deadline
                 U _kernel_task
                 U _lck_mtx_lock
                 U _lck_mtx_unlock
                 U _mach_absolute_time
                 U _memcmp
000000000002cdb8 S _native_virtio_first_sector_sha256
000000000002cdb0 S _native_virtio_mmio_physical
0000000000000000 T _native_virtio_read_checkpoint
000000000002cda0 S _native_virtio_read_failures
000000000002cd9c S _native_virtio_read_requests
000000000002cd98 S _native_virtio_ready
000000000002cda8 S _native_virtio_sectors
                 U _panic

original-bindings.o:
fffffff006add1d0 A __ZN20IOBlockStorageDevice10gMetaClassE
fffffff00496f050 A __ZN20IOBlockStorageDevice11requestIdleEv
fffffff00496f068 A __ZN20IOBlockStorageDevice13doSetPriorityEP26IOBlockStorageDeviceExtentjh
fffffff00496f080 A __ZN20IOBlockStorageDevice13doSynchronizeEyyj
fffffff00496ef38 A __ZN20IOBlockStorageDevice13setPropertiesEP8OSObject
fffffff00496f074 A __ZN20IOBlockStorageDevice18doSynchronizeCacheEv
fffffff00496f038 A __ZN20IOBlockStorageDevice18getWriteCacheStateEPb
fffffff00496f044 A __ZN20IOBlockStorageDevice18setWriteCacheStateEb
fffffff00496f08c A __ZN20IOBlockStorageDevice20doGetProvisionStatusEyyPjP35IOBlockStorageProvisionDeviceExtenty
fffffff00496ee30 A __ZN20IOBlockStorageDevice4initEP12OSDictionary
fffffff00496f05c A __ZN20IOBlockStorageDevice7doUnmapEP26IOBlockStorageDeviceExtentjj
fffffff005cb44b0 A __ZN20IOBlockStorageDevice9metaClassE
fffffff00496ed98 A __ZN20IOBlockStorageDeviceC1EPK11OSMetaClass
fffffff00496ed98 A __ZN20IOBlockStorageDeviceC2EPK11OSMetaClass
fffffff00496edb8 A __ZN20IOBlockStorageDeviceD2Ev
fffffff00496ee88 A __ZNK20IOBlockStorageDevice11getPropertyEPK8OSSymbol
fffffff00496edc4 A __ZNK20IOBlockStorageDevice12getMetaClassEv
fffffff005cb44c0 A __ZTV20IOBlockStorageDevice

```

## component-VirtioMmioBlock.log

### the tail

```
VirtioMmioBlock: -Werror build and arm64-apple-ios17.0 object audit passed
```

## archive-15-build-storage-bindings.log

### the tail

```
PASS: libStorageBindings.a -> 18 absolute bindings over 14 kext-owned slots (com.apple.iokit.IOStorageFamily)
    __ZN20IOBlockStorageDevice10gMetaClassE -> 0xfffffff006add1d0
    __ZN20IOBlockStorageDevice11requestIdleEv -> 0xfffffff00496f050
    __ZN20IOBlockStorageDevice13doSetPriorityEP26IOBlockStorageDeviceExtentjh -> 0xfffffff00496f068
    __ZN20IOBlockStorageDevice13doSynchronizeEyyj -> 0xfffffff00496f080
    __ZN20IOBlockStorageDevice13setPropertiesEP8OSObject -> 0xfffffff00496ef38
    __ZN20IOBlockStorageDevice18doSynchronizeCacheEv -> 0xfffffff00496f074
    __ZN20IOBlockStorageDevice18getWriteCacheStateEPb -> 0xfffffff00496f038
    __ZN20IOBlockStorageDevice18setWriteCacheStateEb -> 0xfffffff00496f044
    __ZN20IOBlockStorageDevice20doGetProvisionStatusEyyPjP35IOBlockStorageProvisionDeviceExtenty -> 0xfffffff00496f08c
    __ZN20IOBlockStorageDevice4initEP12OSDictionary -> 0xfffffff00496ee30
    __ZN20IOBlockStorageDevice7doUnmapEP26IOBlockStorageDeviceExtentjj -> 0xfffffff00496f05c
    __ZN20IOBlockStorageDevice9metaClassE -> 0xfffffff005cb44b0
    __ZN20IOBlockStorageDeviceC1EPK11OSMetaClass -> 0xfffffff00496ed98
    __ZN20IOBlockStorageDeviceC2EPK11OSMetaClass -> 0xfffffff00496ed98
    __ZN20IOBlockStorageDeviceD2Ev -> 0xfffffff00496edb8
    __ZNK20IOBlockStorageDevice11getPropertyEPK8OSSymbol -> 0xfffffff00496ee88
    __ZNK20IOBlockStorageDevice12getMetaClassEv -> 0xfffffff00496edc4
    __ZTV20IOBlockStorageDevice -> 0xfffffff005cb44c0

original-bindings.o:
fffffff006add1d0 A __ZN20IOBlockStorageDevice10gMetaClassE
fffffff00496f050 A __ZN20IOBlockStorageDevice11requestIdleEv
fffffff00496f068 A __ZN20IOBlockStorageDevice13doSetPriorityEP26IOBlockStorageDeviceExtentjh
fffffff00496f080 A __ZN20IOBlockStorageDevice13doSynchronizeEyyj
fffffff00496ef38 A __ZN20IOBlockStorageDevice13setPropertiesEP8OSObject
fffffff00496f074 A __ZN20IOBlockStorageDevice18doSynchronizeCacheEv
fffffff00496f038 A __ZN20IOBlockStorageDevice18getWriteCacheStateEPb
fffffff00496f044 A __ZN20IOBlockStorageDevice18setWriteCacheStateEb
fffffff00496f08c A __ZN20IOBlockStorageDevice20doGetProvisionStatusEyyPjP35IOBlockStorageProvisionDeviceExtenty
fffffff00496ee30 A __ZN20IOBlockStorageDevice4initEP12OSDictionary
fffffff00496f05c A __ZN20IOBlockStorageDevice7doUnmapEP26IOBlockStorageDeviceExtentjj
fffffff005cb44b0 A __ZN20IOBlockStorageDevice9metaClassE
fffffff00496ed98 A __ZN20IOBlockStorageDeviceC1EPK11OSMetaClass
fffffff00496ed98 A __ZN20IOBlockStorageDeviceC2EPK11OSMetaClass
fffffff00496edb8 A __ZN20IOBlockStorageDeviceD2Ev
fffffff00496ee88 A __ZNK20IOBlockStorageDevice11getPropertyEPK8OSSymbol
fffffff00496edc4 A __ZNK20IOBlockStorageDevice12getMetaClassEv
fffffff005cb44c0 A __ZTV20IOBlockStorageDevice

```

## archive-14-build-nio-ufs-archive.log

### the tail

```
nio-ufs: build/nio-ufs/libNioUfs.a -> build/sheng-ufs/libShengUfs.a (512352 bytes, sha256 dc4a7774b64180d20afcc49faab3fc3125e051848118f28e8eb7be3c71c7a8b5)
```

## component-NioUfs.log

### the tail

```
NioUfs: -Werror build and arm64-apple-ios17.0 object audit passed
```

## archive-12-build-link-stubs.log

### the tail

```
compiled LinkStubs.c (legacy display 1, mobile display 0, deployment 17.0)
  _boot_log_export_put         T
  _native_gpu_dcvs             D
  _native_pmap_user_mappings   T
  _qcom_usb_debug_write        T
PASS: 4 link stubs archived in /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/link-stubs/libLinkStubs.a
```

## archive-11-build-gop-legacy-display.log

### the tail

```
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/kits/nio/LegacyDisplayProbe.cpp:629:78: warning: implicit conversion loses integer precision: 'uint64_t' (aka 'unsigned long long') to 'uint32_t' (aka 'unsigned int') [-Wshorten-64-to-32]
  629 |         native_legacy_reached_geometry = ((uint64_t)rowbytes << 32) | (width << 16) | (height & 0xFFFF);
      |                                        ~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/kits/nio/LegacyDisplayProbe.cpp:1173:12: warning: declaration shadows a local variable [-Wshadow]
 1173 |                                                 bool attached = false;
      |                                                      ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/kits/nio/LegacyDisplayProbe.cpp:1094:48: note: previous declaration is here
 1094 |         bool nubAttached = false, nubStarted = false, attached = false, started = false;
      |                                                       ^
2 warnings generated.
NativeLegacyDisplay: -Werror build and arm64-apple-ios17.0 object audit passed
NativeGOPPresenter: -Werror build and arm64-apple-ios17.0 object audit passed
PASS: built nio display archive /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/native-legacy-display/libNativeLegacyDisplay.late.a (977536 bytes)
```

## component-AppleKeyStoreState.log

### the tail

```
AppleKeyStoreState: -Werror build and arm64-apple-ios17.0 object audit passed
```

## archive-09-build-adreno650.log

### the tail

```
PASS: 31 NativeAdreno a650 objects archived
PASS: archive verified with 31 objects
```

## archive-08-build-libpthread-kernel.log

### the tail

```
every callback the sources call has the name this XNU tree uses
Matching libpthread: 3 real C sources + bootstrap, ARM64/iOS 17 audit, no unavailable kernel names
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
Globals shared with kernel: 63; initialization and intact selftests are still required
```

## storage-headers.log

### the tail

```
PASS: 19 public IOStorageFamily headers prepared at e45fbe30a7879e0b16e26dddb78538f1b00e0bff
```

## kernel-bootstrap.log

### the errors

```
4835: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
4841: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
96493: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
96504: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
96515: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
96526: 1413 |                     "| error: latency %d too big (> 1 sec)",
96537: 1420 |                     "| error: jitter %dms too big (latency %dms)",
96548: 1420 |                     "| error: jitter %dms too big (latency %dms)",
96559: 1438 |                     "| error: loss recovery %dms too big",
96570: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
96581: 1463 |                     "| error: output interval %dms too big",
169733: 3406 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
169739: 3411 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
255890: 1384 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
268322:  158 |                 printf("buffer_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
268833:  268 |                 printf("(%s) Failed to handle availability of LZ4. Error 0x%x\n", __func__, ret);
269299:  102 |                 printf("progress_notify_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
269787:  272 |                 printf("zlib_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
270022:  143 |                 printf("%s failed to allocate memory. Error 0x%x\n", __func__, ret);
346962:Undefined symbols for architecture arm64:
346987:ld: symbol(s) not found for architecture arm64
346988:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
346989:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped.noctf] Error 1
346990:make[2]: *** [build_all] Error 2
346991:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
346992:make: *** [build] Error 2
```

### around them

```
4829- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
4830-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
4831-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:597:27: note: expanded from macro 'panic'
4832-  597 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
4833-      |                 ~~               ^~~~~~~~~~~
4834-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
4835: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
4836-      |                                                                                ~~~
4837-      |                                                                                %zu
4838- 1414 |                                             path, mc_error, fatal_failure_desc_len);
4839-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
4840-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
4841: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
4842-      |                                                                                                   ~~~
4843-      |                                                                                                   %zu
4844- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
4845-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
4846-4 warnings generated.
4847-             CC mac_vfs_subr.o
4848-clang: warning: no such include directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa' [-Wmissing-include-dirs]
4849-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/security/mac_vfs_subr.c:29:
4850-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/vnode.h:893:
4851-In file included from /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/bsd/sys/vnode_if.h:85:
--
96487- 1302 |         _CASSERT(IF_NETEM_MODEL_NULL == NETEM_MODEL_NULL);
96488-      |                  ~~~~~~~~~~~~~~~~~~~ ^  ~~~~~~~~~~~~~~~~
96489-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1303:30: warning: comparison of different enumeration types ('if_netem_model_t' and 'netem_model_t') [-Wenum-compare]
96490- 1303 |         _CASSERT(IF_NETEM_MODEL_NLC == NETEM_MODEL_NLC);
96491-      |                  ~~~~~~~~~~~~~~~~~~ ^  ~~~~~~~~~~~~~~~
96492-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1387:7: warning: format specifies type 'int' but the argument has underlying type 'unsigned int' [-Wformat]
96493: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
96494-      |                                                                      ~~
96495-      |                                                                      %u
96496- 1387 |                     p->ifnetem_model);
96497-      |                     ^~~~~~~~~~~~~~~~
96498-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
96499-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
96500-      |                                                    ~~~~
96501-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
96502-      |                                             ^~~~~~~~~~~
96503-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1393:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
96504: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
96505-      |                                                           ~~
96506-      |                                                           %u
96507- 1393 |                     p->ifnetem_corruption_p, NETEM_PSCALE);
96508-      |                     ^~~~~~~~~~~~~~~~~~~~~~~
96509-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
96510-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
96511-      |                                                    ~~~~
96512-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
96513-      |                                             ^~~~~~~~~~~
96514-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1399:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
96515: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
96516-      |                                                            ~~
96517-      |                                                            %u
96518- 1399 |                     p->ifnetem_duplication_p, NETEM_PSCALE);
96519-      |                     ^~~~~~~~~~~~~~~~~~~~~~~~
96520-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
96521-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
96522-      |                                                    ~~~~
96523-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
96524-      |                                             ^~~~~~~~~~~
96525-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1414:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
96526: 1413 |                     "| error: latency %d too big (> 1 sec)",
96527-      |                                       ~~
96528-      |                                       %u
96529- 1414 |                     p->ifnetem_latency_ms);
96530-      |                     ^~~~~~~~~~~~~~~~~~~~~
96531-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
96532-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
96533-      |                                                    ~~~~
96534-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
96535-      |                                             ^~~~~~~~~~~
96536-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1421:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
96537: 1420 |                     "| error: jitter %dms too big (latency %dms)",
96538-      |                                      ~~
96539-      |                                      %u
96540- 1421 |                     p->ifnetem_jitter_ms, p->ifnetem_latency_ms);
96541-      |                     ^~~~~~~~~~~~~~~~~~~~
96542-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
96543-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
96544-      |                                                    ~~~~
96545-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
96546-      |                                             ^~~~~~~~~~~
96547-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1421:29: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
96548: 1420 |                     "| error: jitter %dms too big (latency %dms)",
96549-      |                                                            ~~
96550-      |                                                            %u
96551- 1421 |                     p->ifnetem_jitter_ms, p->ifnetem_latency_ms);
96552-      |                                           ^~~~~~~~~~~~~~~~~~~~~
96553-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
96554-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
96555-      |                                                    ~~~~
96556-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
96557-      |                                             ^~~~~~~~~~~
96558-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1439:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
96559: 1438 |                     "| error: loss recovery %dms too big",
96560-      |                                             ~~
96561-      |                                             %u
96562- 1439 |                     p->ifnetem_loss_recovery_ms);
96563-      |                     ^~~~~~~~~~~~~~~~~~~~~~~~~~~
96564-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
96565-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
96566-      |                                                    ~~~~
96567-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
96568-      |                                             ^~~~~~~~~~~
96569-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1457:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
96570: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
96571-      |                                                         ~~
96572-      |                                                         %u
96573- 1457 |                     p->ifnetem_reordering_p, NETEM_PSCALE);
96574-      |                     ^~~~~~~~~~~~~~~~~~~~~~~
96575-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
96576-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
96577-      |                                                    ~~~~
96578-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
96579-      |                                             ^~~~~~~~~~~
96580-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1464:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
96581: 1463 |                     "| error: output interval %dms too big",
96582-      |                                               ~~
```

### the tail

```
1 warning generated.
             CC nonlto.o
clang: warning: no such include directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa' [-Wmissing-include-dirs]
             CC version.o
clang: warning: no such include directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa' [-Wmissing-include-dirs]
             LD mach.development.bcm2837.unstripped.noctf
ld: warning: -new_linker is obsolete
ld: warning: search path '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/.cache/fakeroot/usr/local/lib/kernel/platform' not found
Undefined symbols for architecture arm64:
  "_native_gpu_probe", referenced from:
      _bsd_init in bsd_init.o
      _bsd_autoconf in bsd_init.o
  "_native_legacy_display_late_probe", referenced from:
      _bsd_init in bsd_init.o
      _bsd_autoconf in bsd_init.o
  "_native_legacy_display_probe", referenced from:
      _bsd_init in bsd_init.o
      _native_mobile_graphics_client_probe in IOUserClient.cpo
  "_native_ram_block_gpu_addon", referenced from:
      _native_gpu_addon_prepare in kern_exec.o
      _native_gpu_addon_prepare in kern_exec.o
  "_native_ram_block_volume_seed", referenced from:
      _load_init_program in kern_exec.o
  "_native_verified_block_manifest_sha384", referenced from:
      _native_owner_publish_boot_manifest in IOKitBSDInit.cpo
      _native_owner_publish_boot_manifest in IOKitBSDInit.cpo
  "_native_verified_block_root_authorized", referenced from:
      _bsd_init in bsd_init.o
      _load_init_program in kern_exec.o
      _load_init_program in kern_exec.o
      _load_init_program in kern_exec.o
  "_native_verified_block_volume_device", referenced from:
      _load_init_program in kern_exec.o
ld: symbol(s) not found for architecture arm64
clang++: error: linker command failed with exit code 1 (use -v to see invocation)
make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ipados-17.7.11-21H461/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped.noctf] Error 1
make[2]: *** [build_all] Error 2
make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
make: *** [build] Error 2
build-xnu-4k-baseline.sh: line 887: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

## status.txt

```
patch    34 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/offline-component-load-probes.patch
patch    35 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/offline-legacy-start.patch
patch    36 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/offline-native-gpu-broker.patch
patch    37 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/offline-owner-boot-manifest.patch
patch    38 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/offline-owner-cache-carrier.patch
patch    39 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/offline-owner-root-binding-audit.patch
patch    40 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/offline-owner-root-crypto-probe.patch
patch    41 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/offline-owner-systemos-mount.patch
patch    42 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/offline-owner-z-air-init.patch
patch    43 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/offline-pgz-alignment-probe.patch
patch    44 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/pgz-aligned-validation.patch
patch    45 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/public-entitlements-header.patch
patch    46 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/published-freezer-condition.patch
patch    47 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/source-corecrypto14-bootstrap.patch
patch    48 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/source-machine-layer.patch
patch    49 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/source-pthread-bootstrap.patch
patch    50 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/zzw-native-adreno-sandbox-grant.patch
patch    51 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/zzwb-native-sandbox-grant-set-properties.patch
patch    52 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/zzx-pmap-sync-64bit-pa.patch
patch    53 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/zzy-native-gpu-addon-mount.patch
patch    54 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/zzy-staged-system-apps.patch
patch    55 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/zzyb-native-cryptex-os-view.patch
patch    56 /Users/runner/work/UniXNU-nio/UniXNU-nio/patches/xnu/zzyc-owner-skip-launch-constraints.patch
patch    57 /Users/runner/work/UniXNU-nio/UniXNU-nio/out/feeds/UniXNU-sm8250-common-e8b46722/patches/xnu/native-smp-secondary.patch
patch    58 /Users/runner/work/UniXNU-nio/UniXNU-nio/out/feeds/UniXNU-sm8250-common-e8b46722/patches/xnu/native-smp-type-clusters.patch
patch    59 /Users/runner/work/UniXNU-nio/UniXNU-nio/kits/XnuPrelink/patches/xnu-10063.141.1-security-init.patch
patch    60 /Users/runner/work/UniXNU-nio/UniXNU-nio/kits/XnuPrelink/patches/xnu-10063.141.1-sparse-index.patch
patch    61 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu/gpu/gpu-probe-start.patch
driver   AppleKeyStoreState       base
driver   ArmCpu                   base
driver   ArmDTPlatform            base
driver   GopFramebuffer           base
driver   NioUfs                   device
driver   RamBlock                 base
driver   SoftwareAES              base
driver   VirtioMmioBlock          base
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
patch    xnu-prelink              device
refer    AvailabilityVersions     git pinned 933f9360f1b7
refer    IOStorageFamily          git pinned e45fbe30a787
refer    corecrypto-2023          git pinned 11fba65b12d8
refer    edk2                     git pinned cfb93724a06f
refer    libdispatch              git pinned 30fe6a7d9453
refer    libplatform              git pinned a00a4cc36da2
refer    libpthread               git pinned c0e60fb5ecfc
refer    xnu                      git pinned d8b80295118e
refer    xnu-driverkit            git pinned 2c2f96dc2b9a
refer    xnu-trustcache           git pinned aca3beaa3dfb
soc      sm8250                   git pinned a6e7e36caab5
```

## patch scope

```
```
