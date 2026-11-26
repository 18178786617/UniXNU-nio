#!/usr/bin/env python3
"""Build the DWC3 USB CDC debug console from the J716F SM8250 reference.

DWC3 USB0 and the CDC-ACM protocol are SoC-level (SM8250-AC / Kona is shared
by Lenovo J716F and MOTO nio), so the reference driver is copied here rather
than rewritten. Only the SMMU stream id is board data (UsbDebugCdc.h).

Source lookup mirrors build-adreno650.py: in the assembled tree the device
package appears at kits/<board.kit> (kits/nio), while tree/package is the base
repository's own package. In the device repository itself the files are in
package/. Find either, so the recipe works both locally and in CI.
"""
from __future__ import annotations

import json
import os
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
c_recipe = json.loads((ROOT / 'build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/bsd/DEVELOPMENT/bsd_init.o.json').read_text().strip().rstrip(','))
cxx_recipe = json.loads((ROOT / 'build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/iokit/DEVELOPMENT/IOPlatformExpert.cpo.json').read_text().strip().rstrip(','))

out = ROOT / 'build/usbdebug'
out.mkdir(parents=True, exist_ok=True)

# Same trick build-adreno650.py uses for GpuProbe.cpp: the board's package
# files land in kits/<kit>/ in the assembled tree, package/ in this repo.
USB = next((p.parent for p in sorted((ROOT / 'kits').glob('*/UsbDebugCdc.cpp'))), ROOT / 'package')
KITS = Path(os.environ.get('ADRENO650_KITS', str(ROOT / 'kits')))

sources = [USB / 'QcomRpmh.c', USB / 'UsbDebugCdc.cpp']


def known_warning_flags() -> list[str]:
    known = []
    for flag in ['-Wno-unused-parameter', '-Wno-unused-variable']:
        probe = out / 'probe.c'
        probe.write_text('int x;\n')
        r = subprocess.run(['xcrun', 'clang', '-Werror', flag, '-c', str(probe), '-o', str(out / 'probe.o')], capture_output=True)
        if r.returncode == 0:
            known.append(flag)
    return known


warning_flags = known_warning_flags()
objects: list[Path] = []
failures = []

for source in sources:
    if not source.is_file():
        sys.exit('source missing: %s (looked in kits/* and package/)' % source)
    recipe = c_recipe if source.suffix == '.c' else cxx_recipe
    obj = out / (source.stem + '.o')
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
        elif value == '-Xclang' and i + 1 < len(recipe['arguments']) and recipe['arguments'][i + 1].startswith('-W'):
            i += 1
        elif not value.startswith('-W') and value not in ('-MD', '-MP'):
            command.append(value)
        i += 1
    # XNU's own exported headers emit C99-designator / enum-conversion
    # warnings under this clang; do not promote them to errors. The recipe's
    # own warning flags are already trimmed by the CI step.
    command += ['-I', str(USB), '-I', str(KITS / 'ArmSmmu4K'),
                '-Wno-deprecated-enum-enum-conversion', '-Wno-c99-designator',
                '-Wno-unnecessary-virtual-specifier', '-Wno-reorder-init-list'] + warning_flags
    result = subprocess.run(command, cwd=recipe['directory'], capture_output=True, text=True)
    (out / (source.stem + '.log')).write_text(result.stdout + result.stderr)
    if result.returncode:
        failures.append((source.name, result.stderr))
        continue
    objects.append(obj)

if failures:
    report = []
    for name, stderr in failures:
        errors = [line for line in stderr.splitlines() if re.search(r'\berror\b:', line)]
        report.append('=== %s ===' % name)
        report.extend(errors[:10] if errors else stderr.strip().splitlines()[-10:])
    summary = 'USB debug compile failures:\n' + '\n'.join(report)
    (out / 'compile-errors.log').write_text(summary)
    print(summary)
    sys.exit(1)

archive = out / 'libUsbDebug.a'
archive.unlink(missing_ok=True)
subprocess.run(['xcrun', 'ar', 'rcs', archive, *objects], check=True)
print('PASS: %d USB debug objects archived at %s' % (len(objects), archive))

nm = subprocess.run(['xcrun', 'nm', '-gP', archive], capture_output=True, text=True, check=True).stdout.splitlines()
defined = {f.split()[0] for f in nm if len(f.split()) > 1 and f.split()[1] in 'TSDBC'}
undefined = {f.split()[0] for f in nm if len(f.split()) > 1 and f.split()[1] == 'U'}
missing = sorted(s for s in undefined - defined if re.search(r'usb|Usb|USB|rpmh|RPMh|smmu|Smmu', s))
if missing:
    sys.exit('USB debug symbols used but not built here: ' + ', '.join(missing))
print('PASS: libUsbDebug.a symbols resolved')
