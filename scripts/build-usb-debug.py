#!/usr/bin/env python3
"""Build nio's USB CDC debug console from the J716F (same SM8250 SoC) reference.

The DWC3 USB0 gadget controller (0x0A600000), its DMA layout and the CDC-ACM
protocol are SoC-level: SM8250-AC / Kona is shared by Lenovo J716F and MOTO nio,
so the reference driver is copied here (package/usbdebug/) rather than rewritten.
Only the SMMU stream id is board data; it is declared in UsbDebugCdc.h and can
be corrected from nio's IORT if the console does not enumerate.

The driver is compiled with the kernel's own recorded command line (the same
recipe mechanism build-adreno650.py uses), archived as libUsbDebug.a, and
linked by CONFIG_XNU_EXTRA_LD_ARCHIVES. native_usb_debug_probe() is called by
the boot path; j716f-usb=1 enables it (via PE_parse_boot_argn in the driver).
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

USB = ROOT / 'package/usbdebug'
PACKAGE = ROOT / 'package'
KITS = Path(os.environ.get('ADRENO650_KITS', str(ROOT / 'kits')))

# The C source brings the RPMh rail votes; the C++ source is the whole gadget
# state machine and the probe. Headers are all in package/usbdebug.
sources = [USB / 'QcomRpmh.c', USB / 'UsbDebugCdc.cpp']


def known_warning_flags() -> list[str]:
    flags = ['-Wno-objc-root-class', '-Wno-unused-parameter', '-Wno-unused-variable']
    known = []
    for flag in flags:
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
        sys.exit('source missing: %s' % source)
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
    command += ['-I', str(USB), '-I', str(PACKAGE), '-I', str(KITS / 'ArmSmmu4K'),
                '-Wall', '-Wextra', '-Werror'] + warning_flags
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
