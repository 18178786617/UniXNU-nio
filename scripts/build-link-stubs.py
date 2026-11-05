#!/usr/bin/env python3
"""Archive nio's link stubs for the kernel link (CONFIG_XNU_EXTRA_LD_ARCHIVES).

The GPU archive is compiled from the A650 driver, and the driver imports six names that
no selected component on this board defines:

    _boot_log_export_put        _native_gop_handoff_call     _native_gop_handoff_memory
    _native_gpu_dcvs            _native_pmap_user_mappings   _qcom_usb_debug_write

Three of them are plain undefined symbols in the driver, and three are weak_import --
and ld64 refuses to leave a weak_import undefined in a static kernel link, so the
kernel link cannot complete without an answer for every one of them. The answers live
in package/LinkStubs.c: weak definitions whose return values are the truthful ones
for a board that has no UFS log exporter, no display hand-off yet, no DVFS table, no
pmap probe and no USB debug console.

This is UniXNU-alioth's scripts/build-link-stubs.py with the board's own file. alioth
is the sibling board on the same SoC (SM8250 / kona), and its linker asked for the same
kind of names. The archive lands at build/link-stubs/libLinkStubs.a, and
scripts/build-xnu-4k-baseline.sh appends CONFIG_XNU_EXTRA_LD_ARCHIVES to
LD_KERNEL_ARCHIVES, which is how the stub archive reaches the kernel link.

The stub file is compiled with the same display switches the kernel is built with:
when a display archive is linked it owns native_gop_handoff_call and
native_gop_handoff_memory, and the stubs in the file step aside for it.
"""
import os
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

sys.path.insert(0, str(ROOT / 'scripts'))
try:
    from kernel_target import ARCH, IOS_VERSION
except ImportError:
    # The kernel build exports UNIXNU_XNU_ARCH and UNIXNU_IOS_VERSION from the selected
    # profiles; without them the arm64 iOS 17.0 target is used (kernel_target.py says the
    # same). The fallback keeps this recipe runnable on its own.
    ARCH, IOS_VERSION = 'arm64', '17.0'

out = ROOT / 'build/link-stubs'
out.mkdir(parents=True, exist_ok=True)


def stub_source():
    """The board package's LinkStubs.c: kits/<kit>/ in the assembled tree, package/ beside it."""
    candidates = sorted((ROOT / 'kits').glob('*/LinkStubs.c')) + [ROOT / 'package' / 'LinkStubs.c']
    for candidate in candidates:
        if candidate.is_file():
            return candidate
    sys.exit('LinkStubs.c not found (looked at %s)' % ', '.join(str(c) for c in candidates))


def switch(name):
    """The defconfig's CONFIG_XNU_* switch as the 0 or 1 the baseline script requires.

    xnu_env() exports a defconfig's "=n" as the string "0" and "=y" as "1", so the two
    arrive already normalized; the extra spellings are here so the recipe also works
    when it is run by hand with a defconfig value in the environment.
    """
    value = os.environ.get(name, '0').strip().strip('"').lower()
    if value in ('1', 'y', 'yes', 'true', 'on'):
        return '1'
    if value in ('0', 'n', 'no', 'false', 'off', ''):
        return '0'
    sys.exit('%s must be 0 or 1, not %r' % (name, value))


source = stub_source()
legacy_display = switch('XNU_NATIVE_LEGACY_DISPLAY')
mobile_display = switch('XNU_NATIVE_MOBILE_DISPLAY')

if ARCH != 'arm64':
    sys.exit('this recipe builds arm64 objects, not %s' % ARCH)

obj = out / (source.stem + '.o')
# -mkernel is what makes the object a kernel object: it keeps the pointer authentication
# and the mod_init conventions the kernel's own objects use, and the deployment target is
# the kernel build's, not the host's.
command = ['xcrun', '--sdk', 'iphoneos', 'clang', '-arch', 'arm64', '-mkernel',
           '-miphoneos-version-min=%s' % IOS_VERSION,
           '-DXNU_NATIVE_LEGACY_DISPLAY=%s' % legacy_display,
           '-DXNU_NATIVE_MOBILE_DISPLAY=%s' % mobile_display,
           '-Os', '-Wall', '-Werror', '-c', str(source), '-o', str(obj)]
result = subprocess.run(command, capture_output=True, text=True)
if result.returncode:
    sys.exit(str(source) + ':\n' + result.stderr[-2500:])
print('compiled %s (legacy display %s, mobile display %s, deployment %s)'
      % (source.name, legacy_display, mobile_display, IOS_VERSION))

archive = out / 'libLinkStubs.a'
archive.unlink(missing_ok=True)
subprocess.run(['xcrun', 'ar', 'rcs', str(archive), str(obj)], check=True)

# The archive has to answer for every name the kernel link asks of it, and answer with a
# definition: an undefined symbol in here would move the failure back to the kernel link.
REQUIRED = ['_boot_log_export_put', '_native_gop_handoff_call', '_native_gop_handoff_memory',
            '_native_gpu_dcvs', '_native_pmap_user_mappings', '_qcom_usb_debug_write']
nm = subprocess.run(['xcrun', 'nm', '-gP', str(archive)], capture_output=True, text=True, check=True).stdout
table = {}
for line in nm.splitlines():
    parts = line.split()
    if len(parts) >= 2:
        table[parts[0]] = parts[1]
missing = [name for name in REQUIRED if name not in table]
undefined = [name for name in REQUIRED if table.get(name) == 'U']
if missing:
    sys.exit('link stubs do not define: ' + ', '.join(missing))
if undefined:
    sys.exit('link stubs leave undefined: ' + ', '.join(undefined))
for name in REQUIRED:
    print('  %-28s %s' % (name, table[name]))
print('PASS: %d link stubs archived in %s' % (len(REQUIRED), archive))
