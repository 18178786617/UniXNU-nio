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
import json, os, re, shutil, struct, subprocess, sys
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

# nio (819): the GMU icache backing is 0x160000 (~1.375 MiB, 352 pages), not the 16 MiB default.
# nio's fragmented DRAM cannot serve a 16 MiB physically contiguous run (cpm_allocate succeeds only
# at small runs here). The region must cover not just the icache DATA blocks (0x4000+0x55d0 main
# code, 0x157000+0x398) but also the CM3's runtime zero-fill/stack regions, which the firmware
# encodes as len=0 type=1 descriptor blocks {address,size}: 0x144000+0x13000 -> 0x157000 (BSS) and
# 0x157000+0x9000 -> 0x160000 (stack/data top). The CM3 stack pointer starts at 0x160000 and the
# first push writes 0x15fffc; 818's 0x154000 region only reached IOVA 0x158000, leaving
# 0x158000..0x160000 unmapped, so the CM3 faulted on its first stack access and never wrote
# FW_INIT_RESULT=0x100 (LOAD status 6 phase 6, init 0). 0x160000 reaches IOVA 0x164000, covering the
# stack top with a page of margin. 352 contiguous pages allocate where 4096 never could; A650Gmu
# validate() needs only >= 0x10000. IOVA layout unchanged. j716f's 16 MiB works because it covers
# this whole map; 0x160000 is the minimum that does so on nio's fragmented DRAM.
# Idempotent in-place patch of the pinned submodule so CI picks it up without a submodule push
# (FFT-infra/Adreno650 is read-only to this board).
_gmu_mem = driver / 'NativeAdrenoGmuMemory.cpp'
_gmu_txt = _gmu_mem.read_text()
_gmu_old = 'return {0xffc000,0x4000,0x7000,0x4000,0x4000};'
_gmu_new = 'return {0x160000,0x4000,0x7000,0x4000,0x4000};'
if _gmu_old in _gmu_txt:
    _gmu_mem.write_text(_gmu_txt.replace(_gmu_old, _gmu_new))
    print('nio: GMU icache backing patched 16MiB->0x160000 (covers CM3 stack top 0x160000)')
elif _gmu_new not in _gmu_txt:
    sys.exit('GMU icache anchor not found in %s' % _gmu_mem)

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
# nio 828/829: the staged Metal accelerator is built separately below (late-bind), not in the
# plain source loop: its static initializer must be staged out of __mod_init_func and globalized
# so the board probe can run it after IOGPUFamily loads (j716f-verified mechanism).

objects = []

# The warning options this recipe passes next to -Werror, minus the ones this
# clang does not know.
#
# The CI's "Match the warning flags to this clang" step trims the main
# repository's scripts, but it does not reach the device repository's, so this
# recipe has to trim itself: one unknown option next to -Werror is a hard
# error ("unknown warning option '-Wno-unnecessary-virtual-specifier'"), and
# the option list has grown with the compilers -- macOS 15's clang does not
# know the virtual-specifier one at all.
#
# Dropping an option is safe here. A -Wno- option and the warning it names
# were introduced together, so a clang that does not know the option does not
# have the warning either and nothing needs suppressing.
CANDIDATE_FLAGS = [
    '-Wno-unused-parameter', '-Wno-incompatible-sysroot', '-Wno-c99-designator',
    # The fork's kalloc_type_view initializers predate the upstream field additions, and
    # the remaining designators are the ones that matter.
    '-Wno-missing-field-initializers',
    '-Wno-missing-designated-field-initializers',
    '-Wno-reorder-init-list', '-Wno-deprecated-enum-enum-conversion',
    '-Wno-unnecessary-virtual-specifier',
]


def known_warning_flags():
    """The -Wno- options this clang accepts, probed one at a time."""
    probe = out / 'flagprobe.c'
    probe.write_text('int main(void) { return 0; }\n')
    flags = []
    for flag in CANDIDATE_FLAGS:
        result = subprocess.run(['xcrun', 'clang', '-Werror', flag, '-c', str(probe),
                                 '-o', str(out / 'flagprobe.o')], capture_output=True, text=True)
        if result.returncode == 0:
            flags.append(flag)
        else:
            print('note: %s is not known to this clang, not passing it' % flag)
    return flags


warning_flags = known_warning_flags()

failures = []

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
                '-I', str(driver), '-I', str(PACKAGE), '-Wall', '-Wextra', '-Werror'] + warning_flags
    # nio 828: mode 12 enabled. The prelinked IOGPUFamily supplies IOAcceleratorES (136 B),
    # verified at runtime by the 827 `metal` probe, so the staged accelerator can link and run.
    if source.name == 'GpuProbe.cpp':
        command.append('-DPIPA_GPU_ACCELERATOR=1')
    result = subprocess.run(command, cwd=recipe['directory'], capture_output=True, text=True)
    # Every source is compiled, and every failure is kept: one CI round then reports the
    # whole set instead of only the first one, which is what a single -Werror in one
    # translation unit used to cost. The per-source log is written next to the object so
    # that the diagnostics branch carries it too.
    (out / (source.stem + '.log')).write_text(result.stdout + result.stderr)
    if result.returncode:
        failures.append((source.name, result.stderr))
        continue
    objects.append(obj)

if failures:
    # One report for all of them, each block capped so the summary stays readable.
    report = []
    for name, stderr in failures:
        errors = [line for line in stderr.splitlines() if re.search(r'\berror\b:', line)]
        report.append('=== %s ===' % name)
        report.append(errors[0] if errors else stderr.strip().splitlines()[-1] if stderr.strip() else '(no output)')
        if len(errors) > 1:
            report.append('  (%d errors in this file, first ones below)' % len(errors))
            report.extend('  ' + line for line in errors[1:9])
        report.append('')
    summary = ('%d of %d sources failed to compile:\n' % (len(failures), len(sources))) + '\n'.join(report)
    (out / 'compile-errors.log').write_text(summary)
    print(summary)
    sys.exit(1)

# --- nio 829: staged AGXAccelerator late-bind (j716f-verified mechanism) ---
def macho_globalize_symbol(path, sym_name):
    data = bytearray(path.read_bytes())
    _, _, _, _, ncmds, _, _, _ = struct.unpack_from('<8I', data, 0)
    at = 32
    symoff = None
    for _ in range(ncmds):
        cmd, cmdsize = struct.unpack_from('<2I', data, at)
        if cmd == 2:
            _, _, symoff, nsyms, stroff, strsize = struct.unpack_from('<6I', data, at)
            break
        at += cmdsize
    if symoff is None:
        return False
    strings = data[stroff:stroff + strsize]
    for i in range(nsyms):
        offset = symoff + i * 16
        n_strx, n_type = struct.unpack_from('<IB', data, offset)
        if n_strx < len(strings):
            end = strings.find(b'\0', n_strx)
            name = strings[n_strx:end].decode('latin1', errors='ignore')
            if name == sym_name:
                data[offset + 4] = n_type | 0x01
                path.write_bytes(data)
                return True
    return False


accel_src = driver / 'NativeAdrenoAccelerator.cpp'
accel_obj = out / 'NativeAdrenoAccelerator.o'
acmd, i = [], 0
while i < len(cxx_recipe['arguments']):
    v = cxx_recipe['arguments'][i]
    if v == cxx_recipe['file']:
        acmd.append(str(accel_src))
    elif v == '-o':
        acmd += ['-o', str(accel_obj)]; i += 1
    elif v in ('-MF', '-MJ'):
        i += 1
    elif v == '-Xclang' and cxx_recipe['arguments'][i + 1].startswith('-W'):
        i += 1
    elif not v.startswith('-W') and v not in ('-MD', '-MP'):
        acmd.append(v)
    i += 1
acmd += ['-I', str(KITS / 'AdrenoPM4'), '-I', str(KITS / 'ArmSmmu4K'), '-I', str(KITS / 'AdrenoFirmware'),
         '-I', str(PIPA.parent), '-I', str(ROOT / '.cache/xnu-work/osfmk'), '-I', str(driver), '-I', str(PACKAGE),
         '-Wall', '-Wextra', '-Werror'] + warning_flags
r = subprocess.run(acmd, cwd=cxx_recipe['directory'], capture_output=True, text=True)
(out / 'NativeAdrenoAccelerator.log').write_text(r.stdout + r.stderr)
if r.returncode:
    print('accelerator compile failed:\n' + r.stderr)
    sys.exit(1)
# Bind the original IOAcceleratorES protected ctor/dtor/metaclass to the audited 21H461 VAs.
bindings = {
    '__ZN15IOAcceleratorESC2EPK11OSMetaClass': 0xFFFFFFF004BD3B20,
    '__ZN15IOAcceleratorESD2Ev': 0xFFFFFFF004BD3B64,
    '__ZN15IOAcceleratorES10gMetaClassE': 0xFFFFFFF006AEB688,
}
asm = out / 'original-bindings.S'
asm.write_text(''.join('.globl %s\n.set %s, %#x\n' % (n, n, a) for n, a in sorted(bindings.items())))
sdk = subprocess.check_output(['xcrun', '--sdk', 'iphoneos', '--show-sdk-path'], text=True).strip()
bindings_obj = out / 'original-bindings.o'
subprocess.run(['xcrun', 'clang', '-target', 'arm64-apple-ios17.0', '-isysroot', sdk,
                '-c', str(asm), '-o', str(bindings_obj)], check=True)
accel_late = out / 'NativeAdrenoAccelerator.late.o'
_objcopy = shutil.which('llvm-objcopy')
oc = [_objcopy] if _objcopy else ['xcrun', 'llvm-objcopy']
subprocess.run(oc + ['--remove-section=__DATA,__mod_init_func', str(accel_obj), str(accel_late)], check=True)
if not macho_globalize_symbol(accel_late, '__GLOBAL__sub_I_NativeAdrenoAccelerator.cpp'):
    sys.exit('Failed to globalize __GLOBAL__sub_I_NativeAdrenoAccelerator.cpp')
objects.extend([accel_late, bindings_obj])

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
            '_A650GmuColdStart', '_A650GmuBuildStartup',
            '__GLOBAL__sub_I_NativeAdrenoAccelerator.cpp', '_native_adreno_accelerator_allocate')
absent = [s for s in required if s not in defined]
if absent:
    sys.exit('Required definitions absent: ' + ', '.join(absent))
print('PASS: archive verified with %d objects' % len(objects))
