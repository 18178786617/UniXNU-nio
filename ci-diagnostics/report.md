# Why the build failed

run: 663, commit c5cb5f285f44a842f438f84314309a660e42c5a5

## ci-steps.log

### the tail

```
16:44:04 prepare: started in /Users/runner/work/UniXNU-nio/UniXNU-nio
16:44:04 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/mach.development.bcm2837.unstripped
16:44:04 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/link.filelist
16:44:04 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o
16:44:04 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/iokit/DEVELOPMENT/IOService.o
traced script start: scripts/build-xnu-4k-baseline.sh
traced before/after make: scripts/build-xnu-4k-baseline.sh
16:44:04 syntax ok: scripts/build-xnu-4k-baseline.sh
16:44:04 script absent: out/nio/ios-16.5-20F66/nio/tree/scripts/build-xnu-4k-baseline.sh
16:44:04 prepare: done
base=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio
record=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o.json exists=False
tree object=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o exists=False
no decodable compile record; nothing to replay
replay object missing=True
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

## kernel-bootstrap.log

### the errors

```
24524: 1413 |                                             "(kcdata_memcpy error: %d, length: %ld)\n",
24530: 1418 |                                     "(os_reason_alloc_buffer error: %d, kcdata error: %d, length: %ld)\n",
148495:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:435:1: error: cannot combine with previous 'static' declaration specifier
148498:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:435:8: error: variable has incomplete type 'void'
148501:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:435:16: error: expected ';' after top level declarator
148505:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:443:15: error: call to undeclared function 'nio_log_copy'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]
148511:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:469:1: error: type specifier missing, defaults to 'int'; ISO C99 and later do not support implicit int [-Wimplicit-int]
148520:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:490:1: error: static declaration of 'nio_usb_gadget_start' follows non-static declaration
148536:make[7]: *** [nio_usb.o] Error 1
148537:make[6]: *** [build_all] Error 2
148538:make[5]: *** [do_all] Error 2
148539:make[4]: *** [build_all] Error 2
148540:make[3]: *** [build_all_recurse_into_conf] Error 2
148541:make[2]: *** [build_all_recurse_into_bsd] Error 2
148542:make[1]: *** [build_all_bootstrap_DEVELOPMENT^ARM64^BCM2837] Error 2
148543:make: *** [build] Error 2
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
148489-  337 |                 printf("nio: USB: address %u\n", value & 0x7f);
148490-      |                                           ~~     ^~~~~~~~~~~~
148491-      |                                           %d
148492-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:392:11: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
148493-  392 |         unsigned ep = (ev >> 1) & 0x1f;
148494-      |                  ^
148495:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:435:1: error: cannot combine with previous 'static' declaration specifier
148496-  435 | extern uint32_t nio_log_copy(uint64_t *pos, char *out, uint32_t max);
148497-      | ^
148498:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:435:8: error: variable has incomplete type 'void'
148499-  435 | extern uint32_t nio_log_copy(uint64_t *pos, char *out, uint32_t max);
148500-      |        ^
148501:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:435:16: error: expected ';' after top level declarator
148502-  435 | extern uint32_t nio_log_copy(uint64_t *pos, char *out, uint32_t max);
148503-      |                ^
148504-      |                ;
148505:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:443:15: error: call to undeclared function 'nio_log_copy'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]
148506-  443 |         uint32_t n = nio_log_copy(&ud.log_pos, (char *)buf, UD_BULK_SIZE);
148507-      |                      ^
148508-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:447:11: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
148509-  447 |         uint64_t bpa = ud.dma_pa + UD_BULK;
148510-      |                  ^
148511:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:469:1: error: type specifier missing, defaults to 'int'; ISO C99 and later do not support implicit int [-Wimplicit-int]
148512-  469 | ud_thread(void *arg __unused, wait_result_t wr __unused)
148513-      | ^
148514-      | int
148515-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:469:1: warning: no previous prototype for function 'ud_thread' [-Wmissing-prototypes]
148516-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:469:10: note: declare 'static' if the function is not intended to be used outside of this translation unit
148517-  469 | ud_thread(void *arg __unused, wait_result_t wr __unused)
148518-      |          ^
148519-      |          static 
148520:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:490:1: error: static declaration of 'nio_usb_gadget_start' follows non-static declaration
148521-  490 | nio_usb_gadget_start(vm_offset_t dwc)
148522-      | ^
148523-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:26:6: note: previous declaration is here
148524-   26 | void nio_usb_gadget_start(vm_offset_t dwc);
148525-      |      ^
148526-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:547:26: warning: incompatible function pointer types passing 'int (void *, wait_result_t)' (aka 'int (void *, int)') to parameter of type 'thread_continue_t' (aka 'void (*)(void *, int)') [-Wincompatible-function-pointer-types-strict]
148527-  547 |         if (kernel_thread_start(ud_thread, NULL, &thread) == KERN_SUCCESS) {
148528-      |                                 ^~~~~~~~~
148529-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/thread.h:1794:26: note: passing argument to parameter 'continuation' here
148530- 1794 |         thread_continue_t       continuation,
```

### the tail

```
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:443:15: error: call to undeclared function 'nio_log_copy'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]
  443 |         uint32_t n = nio_log_copy(&ud.log_pos, (char *)buf, UD_BULK_SIZE);
      |                      ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:447:11: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
  447 |         uint64_t bpa = ud.dma_pa + UD_BULK;
      |                  ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:469:1: error: type specifier missing, defaults to 'int'; ISO C99 and later do not support implicit int [-Wimplicit-int]
  469 | ud_thread(void *arg __unused, wait_result_t wr __unused)
      | ^
      | int
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:469:1: warning: no previous prototype for function 'ud_thread' [-Wmissing-prototypes]
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:469:10: note: declare 'static' if the function is not intended to be used outside of this translation unit
  469 | ud_thread(void *arg __unused, wait_result_t wr __unused)
      |          ^
      |          static 
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:490:1: error: static declaration of 'nio_usb_gadget_start' follows non-static declaration
  490 | nio_usb_gadget_start(vm_offset_t dwc)
      | ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:26:6: note: previous declaration is here
   26 | void nio_usb_gadget_start(vm_offset_t dwc);
      |      ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:547:26: warning: incompatible function pointer types passing 'int (void *, wait_result_t)' (aka 'int (void *, int)') to parameter of type 'thread_continue_t' (aka 'void (*)(void *, int)') [-Wincompatible-function-pointer-types-strict]
  547 |         if (kernel_thread_start(ud_thread, NULL, &thread) == KERN_SUCCESS) {
      |                                 ^~~~~~~~~
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/thread.h:1794:26: note: passing argument to parameter 'continuation' here
 1794 |         thread_continue_t       continuation,
      |                                 ^
/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:500:10: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
  500 |         ppnum_t pn = pmap_find_phys(kernel_pmap, (addr64_t)ud.dma);
      |                 ^
285 warnings and 6 errors generated.
make[7]: *** [nio_usb.o] Error 1
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
[16:45:18] script start (bootstrap=1 jobs=4)
  object MISSING
  source sha 7233b8ac75d6ff94
[16:48:57] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha 7233b8ac75d6ff94
[16:52:09] script start (bootstrap=1 jobs=4)
  object MISSING
  source sha 7233b8ac75d6ff94
[16:52:10] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha 7233b8ac75d6ff94
[16:54:11] script start (bootstrap=1 jobs=4)
  object MISSING
  source sha 7233b8ac75d6ff94
[16:54:12] before make (bootstrap=1 jobs=1)
  object MISSING
  source sha 7233b8ac75d6ff94
```

## build-console.log

### the errors

```
12:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:490:1: error: static declaration of 'nio_usb_gadget_start' follows non-static declaration
```

### around them

```
4-== kernel: XNU
5-== kernel: bootstrap pass for the compile records
6-+ bash /Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/scripts/build-xnu-4k-baseline.sh
7-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:469:1: warning: no previous prototype for function 'ud_thread' [-Wmissing-prototypes]
8-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:469:10: note: declare 'static' if the function is not intended to be used outside of this translation unit
9-  469 | ud_thread(void *arg __unused, wait_result_t wr __unused)
10-      |          ^
11-      |          static 
12:/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:490:1: error: static declaration of 'nio_usb_gadget_start' follows non-static declaration
13-  490 | nio_usb_gadget_start(vm_offset_t dwc)
14-      | ^
15-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:26:6: note: previous declaration is here
16-   26 | void nio_usb_gadget_start(vm_offset_t dwc);
17-      |      ^
18-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:547:26: warning: incompatible function pointer types passing 'int (void *, wait_result_t)' (aka 'int (void *, int)') to parameter of type 'thread_continue_t' (aka 'void (*)(void *, int)') [-Wincompatible-function-pointer-types-strict]
19-  547 |         if (kernel_thread_start(ud_thread, NULL, &thread) == KERN_SUCCESS) {
20-      |                                 ^~~~~~~~~
21-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/EXPORT_HDRS/osfmk/kern/thread.h:1794:26: note: passing argument to parameter 'continuation' here
22- 1794 |         thread_continue_t       continuation,
23-      |                                 ^
24-/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/.cache/xnu-work/bsd/dev/nio_usb.c:500:10: warning: mixing declarations and code is incompatible with standards before C99 [-Wdeclaration-after-statement]
```

## status.txt

```
patch    233 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-mark-parse-machfile.patch
patch    234 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-mark-exec-back-half.patch
patch    235 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-mark-return-to-userland.patch
patch    236 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-mark-the-user-return-path.patch
patch    237 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-sticky-user-return-flags.patch
patch    238 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-flag-the-pid1-schedule.patch
patch    239 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-flag-scheduler-look.patch
patch    240 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-yield-to-pid1-after-bsdinit.patch
patch    241 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-block-boot-thread-for-pid1.patch
patch    242 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-dump-pid1-thread-state.patch
patch    243 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-dump-pid1-runqueue.patch
patch    244 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-boost-pid1-and-preempt.patch
patch    245 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-fix-pid1-boost-priority-range.patch
patch    246 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-auto-reboot-after-150s.patch
patch    247 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-auto-reboot-via-psci.patch
patch    248 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-usb-readonly-probe.patch
patch    249 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-usb-probe-map-mmio.patch
patch    250 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-usb-state-in-pid1-marks.patch
patch    251 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-usb-gadget-driver.patch
patch    252 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-usb-gadget-start.patch
patch    253 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-auto-reboot-1200s.patch
patch    254 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-usb-gadget-move-to-bsd-init.patch
patch    255 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-usb-gadget-trace.patch
patch    256 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-usb-skip-soft-reset.patch
patch    257 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-console-log-ring.patch
patch    258 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-usb-ecm-live-log.patch
patch    259 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-usb-export-gadget-start.patch
patch    260 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-usb-drop-sweet-guard.patch
patch    261 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-usb-enable-gadget-by-default.patch
patch    262 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-usb-ecm-trace.patch
patch    263 /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-usb-bulk-console.patch
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
