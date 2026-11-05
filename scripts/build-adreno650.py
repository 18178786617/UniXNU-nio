#!/usr/bin/env python3
"""Adreno650 for nio (MOTO Edge S, SM8250-AC): build/adreno740/libAdreno740.a, the archive that
CONFIG_XNU_NATIVE_ADRENO links (CONFIG_XNU_NATIVE_ADRENO_ARCHIVE).

This is UniXNU-alioth's scripts/build-adreno650.py with three changes, each forced by the board:

  1. The driver checkout is this board's own submodule (package/adreno650, the FFT-infra/Adreno650
     fork at 70771a71), not UniXNU's catalogue: the catalogue's Adreno740 component is the
     A740-family driver, and this board's silicon is an A650 (a6xx with a GMU). The archive
     therefore keeps the name build/adreno740/libAdreno740.a because
     scripts/build-xnu-4k-baseline.sh hard-codes that path and ignores
     CONFIG_XNU_NATIVE_ADRENO_ARCHIVE.
  2. The board package is nio's, not alioth's, and it has no PCIe half (that is the Wi-Fi radio's
     controller on alioth, a separate board job). So package/alioth_pcie.c is not in the list.
  3. The staged Metal accelerator (mode 12) is not built: NativeAdrenoAccelerator.cpp includes
     ../NativeMetal/OriginalAcceleratorABI.h, a path the build tree has no link for, and the
     accelerator needs the original IOAcceleratorES class, which this kernel does not build
     (IOAcceleratorFamily2 is absent from this XNU tree). Modes 1-11 never touch it.

What is compiled here:
  - the three upstream kits (ArmSmmu4K, AdrenoPM4, AdrenoFirmware), which are selected components
    so the tree carries their sources at kits/<name>;
  - the board's own A650 cold start, package/pipa/A650Gmu.c, and the board probe, package/GpuProbe.cpp,
    with the three firmware images in package/GpuFirmwareA650.c;
  - the driver half of NativeAdreno: the GPU context, the SMMU context and memory, the ring, the
    submission path, the timer, the user client, the publication, the CP start and the IRQ, plus the
    GMU's SMMU context and memory.

Left out on purpose: sheng's GMU platform nodes and service (NativeAdrenoGmuService/Platform/Config
are sheng-hardware) and the staged accelerator.
"""
import json, os, re, shutil, subprocess, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

# The XNU compile records. The recipe replays the exact command line the kernel's own objects were
# built with, so the archive's objects match the kernel's ABI (the same two records alioth uses).
c_recipe = json.loads((ROOT / 'build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/bsd/DEVELOPMENT/bsd_init.o.json').read_text().strip().rstrip(','))
cxx_recipe = json.loads((ROOT / 'build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/iokit/DEVELOPMENT/IOPlatformExpert.cpo.json').read_text().strip().rstrip(','))

# scripts/build-xnu-4k-baseline.sh links CONFIG_XNU_NATIVE_ADRENO from build/adreno740/libAdreno740.a
# -- the A740 name is hard-coded there, not taken from CONFIG_XNU_NATIVE_ADRENO_ARCHIVE -- so the
# A650 archive is produced under that name.
out = ROOT / 'build/adreno740'
out.mkdir(parents=True, exist_ok=True)

# The driver checkout is an input for the same reason as the kits: Adreno650 is not a component in
# UniXNU's catalogue, so the tree has no drivers/Adreno650 unless this names it. This board carries
# the driver as a git submodule of its own package (package/adreno650), which the assembled tree
# reaches at kits/<board.kit>/adreno650, so that is the first place to look. ADRENO650_DRIVER names
# it outright; drivers/Adreno650 and drivers/Adreno740 are the layouts the feeds produce for the
# catalogue's Adreno740 component.
def driver_checkout():
    named = os.environ.get('ADRENO650_DRIVER')
    candidates = []
    if named:
        candidates.append(Path(named))
    candidates += sorted((ROOT / 'kits').glob('*/adreno650'))
    candidates += [ROOT / 'drivers/Adreno650', ROOT / 'drivers/Adreno740']
    for path in candidates:
        if (path / 'NativeAdrenoGpuContext.cpp').is_file():
            return path
    sys.exit('Adreno650 driver checkout not found (tried %s)' % ', '.join(str(c) for c in candidates))

driver = driver_checkout()

# The three upstream kits this recipe compiles are not copied into the generated tree unless a
# selected component asks for them, so the directory is an input rather than an assumption:
# ADRENO650_KITS names it, and a build passes this repository's kits directory.
KITS = Path(os.environ.get('ADRENO650_KITS', str(ROOT / 'kits')))
sources = sorted(KITS.joinpath('ArmSmmu4K').glob('ArmSmmu4K*.c')) + [KITS / 'AdrenoPM4' / 'AdrenoPM4.c']
# The HFI kit and the A650 cold start that uses it.
sources += [KITS / 'AdrenoFirmware' / (name + '.c') for name in ('AdrenoFirmware', 'AdrenoHfi', 'AdrenoHfiStartup', 'AdrenoHfiVotes')]
# A650Gmu.c is board code, so it travels with the board package (package/pipa), not with the shared
# kits. In the assembled tree the device package appears at kits/<board.kit>, while tree/package is
# the base repository's own package. In the device repository itself it is package/pipa. Find
# either, so no environment variable has to name it.
BOARD = next((p.parent for p in sorted((ROOT / 'kits').glob('*/GpuProbe.cpp'))), ROOT / 'package')
PACKAGE = Path(os.environ.get('ADRENO650_PACKAGE', str(BOARD)))
PIPA = next(iter(sorted((ROOT / 'kits').glob('*/pipa/A650Gmu.c'))), PACKAGE / 'pipa' / 'A650Gmu.c')
sources += [PIPA]
# The board probe and its firmware: both are package files. The probe exports native_gpu_probe(),
# which the board's own start hook calls; the firmware object defines the three arrays it
# weak-imports.
sources += [PACKAGE / 'GpuProbe.cpp', PACKAGE / 'GpuFirmwareA650.c']
# The GPU half of NativeAdreno and the GMU's SMMU context. Left out: sheng's GMU platform nodes and
# service (NativeAdrenoService.cpp, NativeAdrenoGmuService/Platform/Config) and the accelerator.
sources += [driver / (name + '.cpp') for name in (
    'NativeAdrenoGpuContext', 'NativeAdrenoSmmuContext', 'NativeAdrenoSmmuMemory',
    'NativeAdrenoMemory', 'NativeAdrenoCpu', 'NativeAdrenoVm', 'NativeAdrenoRing', 'NativeAdrenoSubmit', 'NativeAdrenoTimer',
    'NativeAdrenoUserClient', 'NativeAdrenoPublish', 'NativeAdrenoCpInit', 'NativeAdrenoIrq',
    'NativeAdrenoGmuContext', 'NativeAdrenoGmuMemory')]

objects = []
for source in sources:
    if not source.is_file():
        sys.exit('source missing: %s' % source)
    recipe = c_recipe if source.suffix == '.c' else cxx_recipe
    obj = out / (source.stem + ('.kit.o' if source.suffix == '.c' else '.o'))
    command, i = [], 0
    while i < len(recipe['arguments']):
        value = recipe['arguments'][i]
        if value == recipe['file']:
            command.append(str(source))
        elif value == '-o':
            command += ['-o', str(obj)]
            i += 1
        elif value in ('-MF', '-MJ'):
            i += 1
        elif value == '-Xclang' and recipe['arguments'][i + 1].startswith('-W'):
            i += 1
        elif not value.startswith('-W') and value not in ('-MD', '-MP'):
            command.append(value)
        i += 1
    command += ['-I', str(KITS / 'AdrenoPM4'), '-I', str(KITS / 'ArmSmmu4K'), '-I', str(KITS / 'AdrenoFirmware'),
                '-I', str(PIPA.parent), '-I', str(ROOT / '.cache/xnu-work/osfmk'),
                '-I', str(driver), '-I', str(PACKAGE), '-Wall', '-Wextra', '-Werror',
                '-Wno-unused-parameter', '-Wno-incompatible-sysroot', '-Wno-c99-designator',
                # The fork's kalloc_type_view initializers predate the upstream field additions, and
                # the remaining designators are the ones that matter.
                '-Wno-missing-field-initializers',
                '-Wno-missing-designated-field-initializers',
                '-Wno-reorder-init-list', '-Wno-deprecated-enum-enum-conversion',
                '-Wno-unnecessary-virtual-specifier']
    # Mode 12's staged accelerator is not built on this board (see the header), so the probe's
    # accelerator path stays compiled out.
    if source.name == 'GpuProbe.cpp':
        command.append('-DPIPA_GPU_ACCELERATOR=0')
    result = subprocess.run(command, cwd=recipe['directory'], capture_output=True, text=True)
    if result.returncode:
        sys.exit(str(source) + ':\n' + result.stderr[-2500:])
    objects.append(obj)

archive = out / 'libAdreno740.a'
archive.unlink(missing_ok=True)
subprocess.run(['xcrun', 'ar', 'rcs', archive, *objects], check=True)
print('PASS: %d NativeAdreno a650 objects archived' % len(objects))

# Every NativeAdreno or kit symbol the objects use must be defined by them; the rest is the kernel's.
nm = subprocess.run(['xcrun', 'nm', '-gP', archive], capture_output=True, text=True, check=True).stdout.splitlines()
defined = {f.split()[0] for f in nm if len(f.split()) > 1 and f.split()[1] in 'TSDBC'}
undefined = {f.split()[0] for f in nm if len(f.split()) > 1 and f.split()[1] == 'U'}
missing = sorted(s for s in undefined - defined if re.search(r'NativeAdreno|native_adreno|ArmSmmu4K|AdrenoPM4|AdrenoHfi|AdrenoFirmware|A650Gmu', s))
if missing:
    sys.exit('NativeAdreno symbols used but not built here: ' + ', '.join(missing))
required = ('_NativeAdrenoGpuContextBringup', '_NativeAdrenoGpuContextBuffers', '_NativeAdrenoGpuContextVm', '_native_adreno_publish',
            '_ArmSmmu4KAttachStreams', '_AdrenoPM4Type7', '_NativeAdrenoGmuContextBringupRoutes', '_NativeAdrenoGmuContextPayloads',
            '_A650GmuColdStart', '_A650GmuBuildStartup')
absent = [s for s in required if s not in defined]
if absent:
    sys.exit('Required definitions absent: ' + ', '.join(absent))
print('PASS: archive verified with %d objects' % len(objects))
