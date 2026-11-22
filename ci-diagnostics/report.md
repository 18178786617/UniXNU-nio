# Why the build failed

run: 662, commit 29cd138bc179080314b000e5e1a6c2b040ebff17

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
16:02:12 prepare: started in /Users/runner/work/UniXNU-nio/UniXNU-nio
16:02:12 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/mach.development.bcm2837.unstripped
16:02:12 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/link.filelist
16:02:12 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o
16:02:12 absent : out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/iokit/DEVELOPMENT/IOService.o
traced script start: scripts/build-xnu-4k-baseline.sh
traced before/after make: scripts/build-xnu-4k-baseline.sh
16:02:12 syntax ok: scripts/build-xnu-4k-baseline.sh
16:02:12 script absent: out/nio/ios-16.5-20F66/nio/tree/scripts/build-xnu-4k-baseline.sh
16:02:12 prepare: done
base=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio
record=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o.json exists=False
tree object=/Users/runner/work/UniXNU-nio/UniXNU-nio/out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o exists=False
no decodable compile record; nothing to replay
replay object missing=True
```

## build-console.log

### the errors

```
270:unixnu: XNU patch /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-usb-bulk-console.patch: git failed (1): error: patch failed: bsd/dev/nio_usb.c:1
271:error: bsd/dev/nio_usb.c: patch does not apply
```

### around them

```
262-== kernel: patch nio-usb-skip-soft-reset.patch
263-== kernel: patch nio-console-log-ring.patch
264-== kernel: patch nio-usb-ecm-live-log.patch
265-== kernel: patch nio-usb-export-gadget-start.patch
266-== kernel: patch nio-usb-drop-sweet-guard.patch
267-== kernel: patch nio-usb-enable-gadget-by-default.patch
268-== kernel: patch nio-usb-ecm-trace.patch
269-== kernel: patch nio-usb-bulk-console.patch
270:unixnu: XNU patch /Users/runner/work/UniXNU-nio/UniXNU-nio/device/patches/xnu-8796/nio-usb-bulk-console.patch: git failed (1): error: patch failed: bsd/dev/nio_usb.c:1
271:error: bsd/dev/nio_usb.c: patch does not apply
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
