# Why the build failed

run: 521, commit 3ea4db530ed497572bbf34d3e2bfee727e037aeb

## qemu-run.log

### the tail

```
[32m==>[0m [1mFetching downloads for: [32mqemu[39m[0m
✔︎ Bottle Manifest capstone (5.0.9)
✔︎ Bottle Manifest libslirp (4.9.7)
✔︎ Bottle Manifest libssh (0.12.2_1)
✔︎ Bottle Manifest ncurses (6.6)
✔︎ Bottle Manifest snappy (1.3.1)
✔︎ Bottle Manifest vde (2.3.3)
✔︎ Bottle libslirp (4.9.7)
✔︎ Bottle libssh (0.12.2_1)
✔︎ Bottle capstone (5.0.9)
✔︎ Bottle snappy (1.3.1)
✔︎ Bottle ncurses (6.6)
✔︎ Bottle vde (2.3.3)
✔︎ Bottle qemu (11.1.3)
[32m==>[0m [1mInstalling dependencies for qemu:[0m [32mcapstone[39m, [32mlibslirp[39m, [32mlibssh[39m, [32mncurses[39m, [32msnappy[39m and [32mvde[39m[0m
[32m==>[0m [1mInstalling qemu dependency: [32mcapstone[39m (5.0.9)[0m
[34m==>[0m [1mPouring capstone--5.0.9.arm64_tahoe.bottle.tar.gz[0m
🍺  /opt/homebrew/Cellar/capstone/5.0.9: 31 files, 23.4MB
[32m==>[0m [1mInstalling qemu dependency: [32mlibslirp[39m (4.9.7)[0m
[34m==>[0m [1mPouring libslirp--4.9.7.arm64_tahoe.bottle.tar.gz[0m
🍺  /opt/homebrew/Cellar/libslirp/4.9.7: 13 files, 434.7KB
[32m==>[0m [1mInstalling qemu dependency: [32mlibssh[39m (0.12.2_1)[0m
[34m==>[0m [1mPouring libssh--0.12.2_1.arm64_tahoe.bottle.tar.gz[0m
🍺  /opt/homebrew/Cellar/libssh/0.12.2_1: 25 files, 1.7MB
[32m==>[0m [1mInstalling qemu dependency: [32mncurses[39m (6.6)[0m
[34m==>[0m [1mPouring ncurses--6.6.arm64_tahoe.bottle.tar.gz[0m
🍺  /opt/homebrew/Cellar/ncurses/6.6: 4,086 files, 10.3MB
[32m==>[0m [1mInstalling qemu dependency: [32msnappy[39m (1.3.1)[0m
[34m==>[0m [1mPouring snappy--1.3.1.arm64_tahoe.bottle.tar.gz[0m
🍺  /opt/homebrew/Cellar/snappy/1.3.1: 20 files, 172.4KB
[32m==>[0m [1mInstalling qemu dependency: [32mvde[39m (2.3.3)[0m
[34m==>[0m [1mPouring vde--2.3.3.arm64_tahoe.bottle.tar.gz[0m
🍺  /opt/homebrew/Cellar/vde/2.3.3: 67 files, 1.2MB
[32m==>[0m [1mInstalling [32mqemu[39m[0m
[34m==>[0m [1mPouring qemu--11.1.3.arm64_tahoe.bottle.tar.gz[0m
🍺  /opt/homebrew/Cellar/qemu/11.1.3: 170 files, 729.2MB
QEMU emulator version 11.1.3
wrote out/qemu/kernel.adt (12444 bytes) from nio-qemu-hardware.json
cmdline: -v keepsyms=1 kt_fixed_zones=120 -enable_kprintf_spam native-ufs-root=1 native-ufs-probe=12 rd=md0 amfi_get_out_of_my_way=1 amfi_allow_any_signature=1 nio_skip_security_extensions=1 unentitled_ios_sim_launch=1 ignition_level=1 launchd_unsecure_cache=1 startup_debug=1 wdt=-1 debug=0x1 nio-gpu=8 native-ufs-diagnostics=1 -wdt_no_pmu wdt_test=no_user_checkin
no kernel.macho to boot in QEMU
```

## replay.log

### the tail

```
  asm| Ltmp124:
  asm| ; %bb.3:                                ;   in Loop: Header=BB6_2 Depth=1
  asm| 	;DEBUG_VALUE: nio_hb_ns <- $x25
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:n <- $w21
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:nio_hb_last <- $x24
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:nio_hb_last <- $x25
  asm| 	.loc	4 476 4 is_stmt 1               ; .cache/xnu-work/osfmk/kern/startup.c:476:4
  asm| 	mov	x0, x19
  asm| 	bl	_nio_dc_puts
  asm| Ltmp125:
  asm| 	.loc	4 477 16                        ; .cache/xnu-work/osfmk/kern/startup.c:477:16
  asm| 	mov	w0, w21
  asm| 	.loc	4 477 4 is_stmt 0               ; .cache/xnu-work/osfmk/kern/startup.c:477:4
  asm| 	bl	_nio_dc_putu
  asm| Ltmp126:
  asm| 	.loc	4 478 4 is_stmt 1               ; .cache/xnu-work/osfmk/kern/startup.c:478:4
  asm| 	mov	x0, x20
  asm| 	bl	_nio_dc_puts
  asm| Ltmp127:
  asm| 	.loc	4 479 16                        ; .cache/xnu-work/osfmk/kern/startup.c:479:16
  asm| 	ldr	x8, [sp]
  asm| Ltmp128:
  asm| 	;DEBUG_VALUE: nio_hb_ns <- $x8
  asm| 	.loc	4 479 26 is_stmt 0              ; .cache/xnu-work/osfmk/kern/startup.c:479:26
  asm| 	lsr	x8, x8, #3
  asm| Ltmp129:
  asm| 	umulh	x8, x8, x23
  asm| 	lsr	x0, x8, #4
  asm| 	.loc	4 479 4                         ; .cache/xnu-work/osfmk/kern/startup.c:479:4
  asm| 	bl	_nio_dc_putu
  asm| Ltmp130:
  asm| 	.loc	4 0 4                           ; .cache/xnu-work/osfmk/kern/startup.c:0:4
  asm| 	mov	x24, x25
  asm| Ltmp131:
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:nio_hb_last <- $x24
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:nio_hb_last <- $x24
  asm| 	b	LBB6_1
  asm| Ltmp132:
  asm| 	.loh AdrpAdd	Lloh63, Lloh64
  asm| 	.loh AdrpAdd	Lloh61, Lloh62
```

## ci-steps.log

### the tail

```
  asm| Ltmp124:
  asm| ; %bb.3:                                ;   in Loop: Header=BB6_2 Depth=1
  asm| 	;DEBUG_VALUE: nio_hb_ns <- $x25
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:n <- $w21
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:nio_hb_last <- $x24
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:nio_hb_last <- $x25
  asm| 	.loc	4 476 4 is_stmt 1               ; .cache/xnu-work/osfmk/kern/startup.c:476:4
  asm| 	mov	x0, x19
  asm| 	bl	_nio_dc_puts
  asm| Ltmp125:
  asm| 	.loc	4 477 16                        ; .cache/xnu-work/osfmk/kern/startup.c:477:16
  asm| 	mov	w0, w21
  asm| 	.loc	4 477 4 is_stmt 0               ; .cache/xnu-work/osfmk/kern/startup.c:477:4
  asm| 	bl	_nio_dc_putu
  asm| Ltmp126:
  asm| 	.loc	4 478 4 is_stmt 1               ; .cache/xnu-work/osfmk/kern/startup.c:478:4
  asm| 	mov	x0, x20
  asm| 	bl	_nio_dc_puts
  asm| Ltmp127:
  asm| 	.loc	4 479 16                        ; .cache/xnu-work/osfmk/kern/startup.c:479:16
  asm| 	ldr	x8, [sp]
  asm| Ltmp128:
  asm| 	;DEBUG_VALUE: nio_hb_ns <- $x8
  asm| 	.loc	4 479 26 is_stmt 0              ; .cache/xnu-work/osfmk/kern/startup.c:479:26
  asm| 	lsr	x8, x8, #3
  asm| Ltmp129:
  asm| 	umulh	x8, x8, x23
  asm| 	lsr	x0, x8, #4
  asm| 	.loc	4 479 4                         ; .cache/xnu-work/osfmk/kern/startup.c:479:4
  asm| 	bl	_nio_dc_putu
  asm| Ltmp130:
  asm| 	.loc	4 0 4                           ; .cache/xnu-work/osfmk/kern/startup.c:0:4
  asm| 	mov	x24, x25
  asm| Ltmp131:
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:nio_hb_last <- $x24
  asm| 	;DEBUG_VALUE: nio_heartbeat_thread:nio_hb_last <- $x24
  asm| 	b	LBB6_1
  asm| Ltmp132:
  asm| 	.loh AdrpAdd	Lloh63, Lloh64
  asm| 	.loh AdrpAdd	Lloh61, Lloh62
```

## component-NioUfs.log

### the errors

```
30:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:1287:23: error: immediate must be an integer in range [0, 15].
```

### around them

```
24-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:141:34: note: expanded from macro 'kIOReturnError'
25-  141 | #define kIOReturnError           iokit_common_err(0x2bc) // general error
26-      |                                  ^~~~~~~~~~~~~~~~~~~~~~~
27-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:136:71: note: expanded from macro 'iokit_common_err'
28-  136 | #define iokit_common_err(return )          (sys_iokit|sub_iokit_common|return)
29-      |                                             ~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~
30:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:1287:23: error: immediate must be an integer in range [0, 15].
31- 1287 |     __asm__ volatile ("msr daifclr, %0" :: "r" (daif) : "memory");
32-      |                       ^
33-<inline asm>:1:15: note: instantiated into assembly here
34-    1 |         msr daifclr, x8
35-      |                      ^
36-13 warnings and 1 error generated.
37-
```

### the tail

```
                          ^~~~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:146:34: note: expanded from macro 'kIOReturnNotPrivileged'
  146 | #define kIOReturnNotPrivileged   iokit_common_err(0x2c1) // privilege violation
      |                                  ^~~~~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:136:71: note: expanded from macro 'iokit_common_err'
  136 | #define iokit_common_err(return )          (sys_iokit|sub_iokit_common|return)
      |                                             ~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:3604:48: warning: operand of ? changes signedness: 'int' to 'uint32_t' (aka 'unsigned int') [-Wsign-conversion]
 3603 |     gRootDiagnostic.result = result.phase == UfsRootPhase::Identity ? kIOReturnNotPrivileged :
      |                            ~
 3604 |       result.phase == UfsRootPhase::Schedule ? kIOReturnNoResources : kIOReturnError;
      |                                                ^~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:143:34: note: expanded from macro 'kIOReturnNoResources'
  143 | #define kIOReturnNoResources     iokit_common_err(0x2be) // resource shortage
      |                                  ^~~~~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:136:71: note: expanded from macro 'iokit_common_err'
  136 | #define iokit_common_err(return )          (sys_iokit|sub_iokit_common|return)
      |                                             ~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:3604:71: warning: operand of ? changes signedness: 'int' to 'uint32_t' (aka 'unsigned int') [-Wsign-conversion]
 3603 |     gRootDiagnostic.result = result.phase == UfsRootPhase::Identity ? kIOReturnNotPrivileged :
      |                            ~
 3604 |       result.phase == UfsRootPhase::Schedule ? kIOReturnNoResources : kIOReturnError;
      |                                                                       ^~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:141:34: note: expanded from macro 'kIOReturnError'
  141 | #define kIOReturnError           iokit_common_err(0x2bc) // general error
      |                                  ^~~~~~~~~~~~~~~~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:136:71: note: expanded from macro 'iokit_common_err'
  136 | #define iokit_common_err(return )          (sys_iokit|sub_iokit_common|return)
      |                                             ~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:1287:23: error: immediate must be an integer in range [0, 15].
 1287 |     __asm__ volatile ("msr daifclr, %0" :: "r" (daif) : "memory");
      |                       ^
<inline asm>:1:15: note: instantiated into assembly here
    1 |         msr daifclr, x8
      |                      ^
13 warnings and 1 error generated.

```

## archive-10-build-link-stubs.log

### the tail

```
compiled LinkStubs.c (legacy display 0, mobile display 0, deployment 17.0)
  _boot_log_export_put         T
  _native_gop_handoff_call     T
  _native_gop_handoff_memory   T
  _native_gpu_dcvs             D
  _native_pmap_user_mappings   T
  _qcom_usb_debug_write        T
PASS: 6 link stubs archived in /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/link-stubs/libLinkStubs.a
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
28341: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
28347: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
499656: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
499667: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
499678: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
499689: 1413 |                     "| error: latency %d too big (> 1 sec)",
499700: 1420 |                     "| error: jitter %dms too big (latency %dms)",
499711: 1420 |                     "| error: jitter %dms too big (latency %dms)",
499722: 1438 |                     "| error: loss recovery %dms too big",
499733: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
499744: 1463 |                     "| error: output interval %dms too big",
610838: 2626 |                 FDLOG(LOG_ERR, fd_cb, "failed to get the close error: %d", error);
612570: 4398 |                                 FDLOG(LOG_DEBUG, &nil_pcb, "ctl_enqueuembuf returned an error: %d", error);
639337:  202 |                 ipseclog((LOG_DEBUG, "ah4_output: internal error: "
639445:  466 |                 ipseclog((LOG_DEBUG, "ah6_output: internal error: "
646441:  312 |                         ipseclog((LOG_DEBUG, "esp4_output: internal error: "
646453:  321 |                         ipseclog((LOG_DEBUG, "esp6_output: internal error: "
684238:  275 |         SASEL_LOG("Returned with error: %d", err);
1058938: 3378 |                             "(kcdata_memcpy error: %d, length: %ld)\n",
1058944: 3383 |                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
1848659: 1364 |                 IOLog("IOPolledFilePollersSetup for corefile failed with error: 0x%x\n", err);
1927923:  158 |                 printf("buffer_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
1935246:  268 |                 printf("(%s) Failed to handle availability of LZ4. Error 0x%x\n", __func__, ret);
1944244:  102 |                 printf("progress_notify_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
1953276:  272 |                 printf("zlib_stage_initialize failed to allocate memory. Error 0x%x\n", ret);
1957840:  143 |                 printf("%s failed to allocate memory. Error 0x%x\n", __func__, ret);
2863039:Undefined symbols for architecture arm64:
2863048:ld: symbol(s) not found for architecture arm64
2863049:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
2863050:make[3]: *** [/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837//mach.development.bcm2837.unstripped] Error 1
2863051:make[2]: *** [build_all] Error 2
2863052:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
2863053:make: *** [build] Error 2
```

### around them

```
28335- 1371 |                             path, fatal_failure_desc_len, fatal_failure_desc);
28336-      |                                   ^~~~~~~~~~~~~~~~~~~~~~
28337-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/debug.h:589:27: note: expanded from macro 'panic'
28338-  589 |         (panic)(ex " @%s:%d", ## __VA_ARGS__, __FILE_NAME__, __LINE__); \
28339-      |                 ~~               ^~~~~~~~~~~
28340-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1414:26: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
28341: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
28342-      |                                                                                ~~~
28343-      |                                                                                %zu
28344- 1414 |                                             path, mc_error, fatal_failure_desc_len);
28345-      |                                                             ^~~~~~~~~~~~~~~~~~~~~~
28346-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1419:43: warning: format specifies type 'long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
28347: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
28348-      |                                                                                                   ~~~
28349-      |                                                                                                   %zu
28350- 1419 |                                     path, reason_error, kcdata_error, fatal_failure_desc_len);
28351-      |                                                                       ^~~~~~~~~~~~~~~~~~~~~~
28352-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1381:15: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
28353- 1381 |                 os_reason_t reason = os_reason_create(OS_REASON_CODESIGNING,
28354-      |                             ^
28355-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/security/mac_vfs.c:1426:3: warning: identifier '__zfree_zone' is reserved because it starts with '__' [-Wreserved-identifier]
28356- 1426 |                 zfree(ZV_NAMEI, vn_path);
28357-      |                 ^
--
499650- 1284 |         kfree_type_impl(kt_view_var, os_ptr_load_and_erase(elem));             \
499651-      |                                      ^
499652-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libkern/os/alloc_util.h:67:14: note: expanded from macro 'os_ptr_load_and_erase'
499653-   67 |         __auto_type __elem = *__eptr;                             \
499654-      |                     ^
499655-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1387:7: warning: format specifies type 'int' but the argument has underlying type 'unsigned int' [-Wformat]
499656: 1386 |                 NETEM_LOG(LOG_ERR, "| error: invalid scheduler model %d",
499657-      |                                                                      ~~
499658-      |                                                                      %u
499659- 1387 |                     p->ifnetem_model);
499660-      |                     ^~~~~~~~~~~~~~~~
499661-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
499662-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
499663-      |                                                    ~~~~
499664-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
499665-      |                                             ^~~~~~~~~~~
499666-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1393:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
499667: 1392 |                 NETEM_LOG(LOG_ERR, "| error: corruption_p %d > %d",
499668-      |                                                           ~~
499669-      |                                                           %u
499670- 1393 |                     p->ifnetem_corruption_p, NETEM_PSCALE);
499671-      |                     ^~~~~~~~~~~~~~~~~~~~~~~
499672-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
499673-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
499674-      |                                                    ~~~~
499675-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
499676-      |                                             ^~~~~~~~~~~
499677-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1399:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
499678: 1398 |                 NETEM_LOG(LOG_ERR, "| error: duplication_p %d > %d",
499679-      |                                                            ~~
499680-      |                                                            %u
499681- 1399 |                     p->ifnetem_duplication_p, NETEM_PSCALE);
499682-      |                     ^~~~~~~~~~~~~~~~~~~~~~~~
499683-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
499684-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
499685-      |                                                    ~~~~
499686-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
499687-      |                                             ^~~~~~~~~~~
499688-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1414:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
499689: 1413 |                     "| error: latency %d too big (> 1 sec)",
499690-      |                                       ~~
499691-      |                                       %u
499692- 1414 |                     p->ifnetem_latency_ms);
499693-      |                     ^~~~~~~~~~~~~~~~~~~~~
499694-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
499695-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
499696-      |                                                    ~~~~
499697-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
499698-      |                                             ^~~~~~~~~~~
499699-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1421:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
499700: 1420 |                     "| error: jitter %dms too big (latency %dms)",
499701-      |                                      ~~
499702-      |                                      %u
499703- 1421 |                     p->ifnetem_jitter_ms, p->ifnetem_latency_ms);
499704-      |                     ^~~~~~~~~~~~~~~~~~~~
499705-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
499706-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
499707-      |                                                    ~~~~
499708-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
499709-      |                                             ^~~~~~~~~~~
499710-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1421:29: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
499711: 1420 |                     "| error: jitter %dms too big (latency %dms)",
499712-      |                                                            ~~
499713-      |                                                            %u
499714- 1421 |                     p->ifnetem_jitter_ms, p->ifnetem_latency_ms);
499715-      |                                           ^~~~~~~~~~~~~~~~~~~~~
499716-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
499717-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
499718-      |                                                    ~~~~
499719-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
499720-      |                                             ^~~~~~~~~~~
499721-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1439:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
499722: 1438 |                     "| error: loss recovery %dms too big",
499723-      |                                             ~~
499724-      |                                             %u
499725- 1439 |                     p->ifnetem_loss_recovery_ms);
499726-      |                     ^~~~~~~~~~~~~~~~~~~~~~~~~~~
499727-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
499728-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
499729-      |                                                    ~~~~
499730-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
499731-      |                                             ^~~~~~~~~~~
499732-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1457:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
499733: 1456 |                 NETEM_LOG(LOG_ERR, "| error: reordering %d > %d",
499734-      |                                                         ~~
499735-      |                                                         %u
499736- 1457 |                     p->ifnetem_reordering_p, NETEM_PSCALE);
499737-      |                     ^~~~~~~~~~~~~~~~~~~~~~~
499738-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:118:38: note: expanded from macro 'NETEM_LOG'
499739-  117 |                         log(_level, "NETEM: %-30s "_fmt "\n", \
499740-      |                                                    ~~~~
499741-  118 |                             __FUNCTION__, ##__VA_ARGS__); \
499742-      |                                             ^~~~~~~~~~~
499743-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/net/pktsched/pktsched_netem.c:1464:7: warning: format specifies type 'int' but the argument has type 'uint32_t' (aka 'unsigned int') [-Wformat]
499744: 1463 |                     "| error: output interval %dms too big",
499745-      |                                               ~~
```

### the tail

```
   50 | const vm_size_t      __attribute__((section("__DATA,__data")))  _lastkerneldataconst_padsize = sizeof(data_const_padding);
      |                                                                 ^
83 warnings generated.
             CC lastkernelconstructor.o
clang: warning: no such include directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa' [-Wmissing-include-dirs]
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/libsa/lastkernelconstructor.c:31:13: warning: declaration requires a global constructor [-Wglobal-constructors]
   31 | static void last_kernel_constructor(void) __attribute__ ((constructor));
      | ~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~
1 warning generated.
             CC nonlto.o
clang: warning: no such include directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa' [-Wmissing-include-dirs]
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/libsa/nonlto.c:33:33: warning: identifier '__not_used_at_all__' is reserved because it starts with '__' [-Wreserved-identifier]
   33 | int __attribute__((__unused__)) __not_used_at_all__;
      |                                 ^
1 warning generated.
             CC version.o
clang: warning: no such include directory: '/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/libsa' [-Wmissing-include-dirs]
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/version.c:39:12: warning: identifier '__kernelVersionString' is reserved because it starts with '__' [-Wreserved-identifier]
   39 | const char __kernelVersionString[] __attribute__((used)) = "@(#)VERSION: " OSTYPE " Kernel Version 22.4.0: Wed Nov 18 16:47:41 UTC 2026; runner:ios-obj/DEVELOPMENT_ARM64_BCM2837";
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
build-xnu-4k-baseline.sh: line 866: make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 MACHINE_CONFIGS=BCM2837 KERNEL_CONFIGS=DEVELOPMENT ARCH_STRING_FOR_CURRENT_MACHINE_CONFIG="$XNU_ARCH_STRING" LARGE_MEMORY_DEFINE=-UARM_LARGE_MEMORY ARM64_LINK_ADDR=0xfffffff007004000 ARM64_PLKSEG_ADDR=0xfffffff004004000 DEPLOYMENT_TARGET_FLAGS="-miphoneos-version-min=$IOS_VERSION -DXNU_TARGET_OS_IOS" DEPLOYMENT_LINKER_FLAGS="-Wl,-ios_version_min,$IOS_VERSION" RC_DARWIN_KERNEL_VERSION="$XNU_DARWIN" RC_ProjectSourceVersion="$XNU_VERSION" BUILD_LTO=0 BOUND_CHECKS=0 BUILD_WERROR="${XNU_BUILD_WERROR:-0}" MAKEJOBS=-j"${JOBS:-4}" CFLAGS_EXTRA="$EXTRA_CFLAGS" "${EXTRA_MAKE_ARGS[@]}" ${XNU_HOST_MAKE_ARGS[@]+"${XNU_HOST_MAKE_ARGS[@]}"} OBJROOT="$ROOT/build/xnu/ios-obj" SYMROOT="$ROOT/build/xnu/ios-sym" DSTROOT="$ROOT/build/xnu/ios-dst" failed
```

## xnu-trace.log

### the tail

```
[16:36:49] script start (bootstrap=1 jobs=3)
  object MISSING
  source sha d48af909f338b58d
[16:39:00] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha d48af909f338b58d
```

## build-nio-ufs_compile.log

### the errors

```
74:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:1287:23: error: immediate must be an integer in range [0, 15].
```

### around them

```
66- 3604 |       result.phase == UfsRootPhase::Schedule ? kIOReturnNoResources : kIOReturnError;
67-      |                                                                       ^~~~~~~~~~~~~~
68-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:141:34: note: expanded from macro 'kIOReturnError'
69-  141 | #define kIOReturnError           iokit_common_err(0x2bc) // general error
70-      |                                  ^~~~~~~~~~~~~~~~~~~~~~~
71-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/iokit/IOKit/IOReturn.h:136:71: note: expanded from macro 'iokit_common_err'
72-  136 | #define iokit_common_err(return )          (sys_iokit|sub_iokit_common|return)
73-      |                                             ~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~
74:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/drivers/NioUfs/NioUfs.cpp:1287:23: error: immediate must be an integer in range [0, 15].
75- 1287 |     __asm__ volatile ("msr daifclr, %0" :: "r" (daif) : "memory");
76-      |                       ^
77-<inline asm>:1:15: note: instantiated into assembly here
78-    1 |         msr daifclr, x8
79-      |                      ^
80-13 warnings and 1 error generated.
```

## status.txt

```
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
patch    164 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-device-tree-slide-fix.patch
patch    165 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-path-probe.patch
patch    166 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-config-thread-probe.patch
patch    167 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-root-inline-and-thread-probe.patch
patch    168 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-every-nub-in-place.patch
patch    169 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-match-in-a-loop.patch
patch    170 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-console-ring-not-block.patch
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
