# Display (GopFramebuffer) port notes — nio, 2026-11-26

## Why this file
The kernel reaches a stable console + USB, but the framebuffer is not up:
`display` over USB returns `FB: stage=0 0x0 phys=0x0 ...` and `screen.snapshot`
returns `framebuffer not ready`. The symbols `native_legacy_stage` /
`native_legacy_gop_*` that the USB driver reads are `weak_import` and currently
unlinked: **no IOMobileFramebuffer / GopFramebuffer driver is compiled into the
kernel**. Getting a desktop requires compiling one in.

Reference policy (owner, 2026-11-26): only UniXNU official sources — the
verified same-SoC board `refs/UniXNU-j716f-verified/` (SM8250, 17.7.11, 60 FPS
desktop) and the Lenovo boards in `refs/UniXNU/docs/zh/devices/` (tb128fu is
Lenovo Xiaoxin Pad 2022, reaches iPadOS desktop with **no GMU**, QuartzCore on
CPU, Metal via system-memory pass). Do NOT use hakios trees as reference.

## Lenovo tb128fu's relevant finding (UniXNU official device record)
- GPU SMMU firmware ignores FAULT writes to S2CR and turns BYPASS into FAULT;
  TRANSLATE writes take effect. (Same SMMU family as nio's mode-7 work.)
- Display uses the ABL splash framebuffer; QuartzCore draws on CPU. The desktop
  does not need a working GMU cold start. This is why display is the priority.

## The ABI difference that blocks a direct copy of j716f's build script
j716f verified: iOS **17.7.11**, `IOMobileFramebufferLegacy` vtable has **358**
slots; several slots are named (`getDisplayDimensions`, `isMainDisplay`,
`startHardware`, ...). Its `scripts/build-gop-legacy-display.py` hardcodes those
addresses and asserts a 358-entry owned vtable.

nio: iOS **16.5** donor (`donor/kernelcache.decompressed.gz`). The generated
`package/OriginalMobileFramebufferABI16_5.h` has `IOMobileFramebufferLegacy`
with **338** slots and no named method slots. A direct copy of the j716f script
will fail both the slot-count assert and the compile of the named calls in
`NativeLegacyDisplay.cpp`.

## Extracted 16.5 addresses (reproduce with the commands below)
From `tools/find-mobile-framebuffer-bindings.py donor/kernelcache.decompressed IOMobileFramebufferLegacy`:
```
IOMobileFramebufferLegacy::C2          = 0xfffffff005c0dbbc
IOMobileFramebufferLegacy::D2          = 0xfffffff005c0d668
IOMobileFramebufferLegacy::gMetaClass  = 0xfffffff007a40540
parent dispatch table                  = 0xfffffff006def260
dispatch table entries                 = 338
```
Base class `IOMobileFramebuffer` (for chain completeness):
```
C2 0xfffffff005c03674, D2 0xfffffff005c036c0, gMetaClass 0xfffffff007a3bfd8,
table 0xfffffff006decd70, 252 slots
```
`IOMobileFramebufferService`: table 0xfffffff006ded600, metaclass 0xfffffff006deddf8.

Reproduce:
```
PY=C:/Users/Administrator/.workbuddy/binaries/python/versions/3.13.12/python.exe
$PY -c "import gzip; open('donor/kernelcache.decompressed','wb').write(gzip.open('donor/kernelcache.decompressed.gz','rb').read())"
$PY tools/find-mobile-framebuffer-bindings.py donor/kernelcache.decompressed IOMobileFramebufferLegacy
$PY tools/make-mobile-framebuffer-abi.py donor/kernelcache.decompressed /tmp/abi.h
```
`capstone` was pip-installed into the workbuddy python for the finder script.

## Work items before a CI round
1. Map the named methods `getDisplayDimensions`, `isMainDisplay`,
   `startHardware`, `validateSwap`, `kickSwapQueue`, `collectCompletionReports`
   etc. from the 17.7.11 vtable to their 16.5 slot numbers. Use
   `tools/dispatch-layout.py` + the 16.5 vtable dump; do not guess.
2. Produce a nio build script derived from j716f's
   `build-gop-legacy-display.py`: 168..338 header, nio bindings above, and
   **only the display objects** (`NativeLegacyDisplay.late.o`,
   `original-bindings.o`, `LegacyDisplayProbe.o`, `NativeGOPPresenter.late.o`).
   Drop j716f's gpu/hid/touch/battery/mdss/buttons objects — nio already has
   its own GpuProbe/UsbDebugCdc and duplicating them causes symbol clashes.
3. Add the resulting archive to `board.toml` components + archives, and select
   the `GopFramebuffer` component. Screen parameters must be nio's
   1080x2520 / pitch 4320 / FB 0x9C000000 (from the firmware GOP), not j716f's
   2560x1600.
4. One CI at a time; on success flash and check `display` / `screen.snapshot`
   over USB. The pass condition is `FB stage > 0` with a non-zero phys address.

## Status
Tooling that extracts 16.5 bindings works (addresses above). ABI method mapping
and the nio build script are not done yet. No CI has been run for display.
