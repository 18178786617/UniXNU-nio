#!/usr/bin/env python3
"""Compile Apple's IOStorageFamily into the kernel link as a static archive.

Why this exists
---------------
drivers/NioUfs publishes the boot volumes through a class that derives from
IOBlockStorageDevice:

    class NioUfsBlock : public IOBlockStorageDevice   (NioUfs.cpp:1474)

On iOS that base class is not in the kernel.  IOStorageFamily is a kext, and
on a stock phone the kernel is a prelinked kernelcache that already carries
it.  This board builds a standalone kernel.macho out of XNU and force-loads
the board's own archives into it, so nothing on the link line defines
IOBlockStorageDevice and run 35 ended exactly there:

    "vtable for IOBlockStorageDevice", referenced from:
        vtable for NioUfsBlock in libShengUfs.a[2](NioUfs.o)
    ld: symbol(s) not found for architecture arm64

Building the family from source is the answer this repository already uses
for HID and for its own UFS transport: compile Apple's compilation units
against the kernel's own compile record, archive them, and let the kernel
link carry them.  The list below is the PBXSourcesBuildPhase of Apple's
IOStorageFamily kernel target, from the same pinned checkout
prepare-storage-headers.py takes its public headers from
(refer/IOStorageFamily, commit e45fbe30a7879e0b16e26dddb78538f1b00e0bff).

One file from upstream's target is missing from this checkout:

  IOStorageFeatures.cpp

IOUserBlockStorageDevice, the DriverKit-backed storage device class, is not
compiled at all.

  IOBlockStorageDriver.cpp is the only file in the family that refers to it:
  it casts its provider with OSDynamicCast(IOUserBlockStorageDevice, provider)
  and asks it for a perf-control client. On a phone that class is the kernel
  half of a dext -- its methods are forwarded through an iig-generated
  _Dispatch to seven _Impl functions the dext implements. A kext can be linked
  with those undefined because the dext arrives later; a kernel cannot. Run 40
  named all seven, run 41 then named the generated dispatch that the kext half
  needs in turn.

  There is no dext on this board, and nothing the family does with the class
  beyond testing it for NULL: the member is read at three places to pick which
  service to attribute work to. So the driver is compiled from a copy with the
  cast and the include removed, the member stays NULL, and the driver takes
  the path it takes for a device that is not dext-backed -- which is what
  NioUfs is. driver_source() below performs that edit against exact text.

How the objects are built
-------------------------
The command is not chosen here.  scripts/build-arm-driver.py established the
pattern this board uses: replay the kernel's own compile record
(iookit/DEVELOPMENT/IOPlatformExpert.cpo.json, added to the tree by
xnu-8796-compile-records.patch and therefore present before the archives
stage runs), swapping only the input, the output and the warning flags.  That
is what makes the objects ABI-compatible with the kernel they are linked
into -- the same -fapple-kext, the same PAC settings, the same sanitizer
runtime, the same deployment target.

Two things are added to that record:

  -I refer/IOStorageFamily          the family's own headers ("IOStorage.h"
                                    style includes, not <IOKit/storage/...>)
  -I build/storage-abi/include      the public <IOKit/storage/...> header set
                                    prepare-storage-headers.py just built

and every -W option is removed, replaced with -Wno-error.  These are Apple's
sources, not this board's: a warning that the kernel's own -Werror would turn
into a failure here is reported in the log and not acted on.  The loop
compiles every file before failing, so one run reports every error instead of
only the first.

The archive is force-loaded by the kernel link through
CONFIG_XNU_EXTRA_LD_ARCHIVES in configs/nio_defconfig.  Force-load, not a
plain archive argument: IOMedia, the partition schemes and the storage driver
are reached through the class registry at run time, not through a reference
in another object, and a plain archive would leave them out.

One consequence, and it is not obvious from here
------------------------------------------------
Every class in this archive is registered as belonging to `__kernel__`, which
is exactly what the kernel's own copy of the family has to be: OSDynamicCast
compares the meta class *pointer* (`OSTypeID(type)` is `type::metaClass`), so
the registration that happens first is the only one objects in this image can
be cast to, and it must be this one.

Apple's IOStorageFamily is also in [kernel].prelink.roots, and it cannot come
out: its Info.plist personalities (`IOClass` by bundle) are what make
IOBlockStorageDriver attach to an IOBlockStorageDevice provider, the partition
schemes attach to IOMedia, and IOMediaBSDClient publish the BSD nodes -- a
class linked into the kernel carries no personalities.  On iOS the two
registrations therefore meet in OSMetaClass::postModLoad(), which panics on
the second one; the machine was gone at that panic in run 42 (R254), before
the driver had read a block.  patches/xnu-8796/
kext-class-duplicate-keeps-kernel.patch keeps the kernel's registration and
lets the kext load without its own class table, which is the only combination
that leaves both the pointers and the personalities intact.
"""
import json
import os
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

# Apple's IOStorageFamily kernel target, in the order upstream builds it.
# IOBlockStorageDriver is compiled from a copy with the DriverKit class taken
# out -- see driver_source() below.
FAMILY = [
    'IOAppleLabelScheme',
    'IOApplePartitionScheme',
    'IOBlockStorageDevice',
    'IOBlockStorageDriver',
    'IOFDiskPartitionScheme',
    'IOFilterScheme',
    'IOGUIDPartitionScheme',
    'IOMedia',
    'IOMediaBSDClient',
    'IOPartitionScheme',
    'IORequest',
    'IORequestsPool',
    'IOStorage',
]


def switch(name):
    """A CONFIG_ value as 0 or 1 (kernel.py exports =n as "0" and =y as "1")."""
    value = os.environ.get(name, '1').strip().strip('"').lower()
    if value in ('1', 'y', 'yes', 'true', 'on'):
        return '1'
    if value in ('0', 'n', 'no', 'false', 'off', ''):
        return '0'
    sys.exit('%s must be 0 or 1, not %r' % (name, value))


if switch('XNU_NATIVE_IOSTORAGE') != '1':
    print('storage-family: CONFIG_XNU_NATIVE_IOSTORAGE is off; nothing compiled')
    raise SystemExit(0)

source_dir = (ROOT / 'refer/IOStorageFamily').resolve()
missing = [name for name in FAMILY if not (source_dir / (name + '.cpp')).is_file()]
if missing:
    sys.exit('refer/IOStorageFamily does not carry: %s\n'
             'run "unixnu tree" so the pinned checkout is present' % ', '.join(missing))

recipe = ROOT / 'build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/iokit/DEVELOPMENT/IOPlatformExpert.cpo.json'
if not recipe.is_file():
    sys.exit('the kernel compile record is missing: %s\n'
             'xnu-8796-compile-records.patch adds it, and the bootstrap pass generates it'
             % recipe)
record = json.loads(recipe.read_text().strip().rstrip(','))
arguments = record['arguments']

out = ROOT / 'build/storage-family'
out.mkdir(parents=True, exist_ok=True)
program = arguments[0]


def command_for(source, destination, extra=()):
    """The kernel's compile line with this source, this output and no -W options."""
    command = [program]
    index = 1
    # arguments[1] is the record's own input file (the -xc++ before it stays).
    consumed_input = False
    while index < len(arguments):
        value = arguments[index]
        if value == record['file']:
            command.append(str(source))
            consumed_input = True
        elif value == '-o':
            command.extend(['-o', str(destination)])
            index += 1
        elif value == '-Xclang' and index + 1 < len(arguments) and arguments[index + 1].startswith('-W'):
            index += 1
        elif not value.startswith('-W'):
            command.append(value)
        index += 1
    if not consumed_input:
        sys.exit('the compile record does not name its own input: %s' % record['file'])
    command.extend(['-Wno-error',
                    # IOMediaBSDClient.cpp still declares two locals `register`.
                    # C++17 removed the keyword and clang reports it as an error
                    # by default, so -Wno-error alone does not cover it; the two
                    # lines are Apple's, from 2015, and mean nothing on arm64.
                    '-Wno-register',
                    '-Wno-deprecated-declarations',
                    '-I', str(source_dir),
                    '-I', str(ROOT / 'build/storage-abi/include'),
                    *extra])
    return command


DEXT_INCLUDE = '#include "IOUserBlockStorageDevice_kext.h"'
DEXT_CAST = """    _userBlockStorageDevice = OSDynamicCast(IOUserBlockStorageDevice, provider);

    if (_userBlockStorageDevice) {
        _perfControlClient = _userBlockStorageDevice->getPerfControlClient();
        assert(_perfControlClient != NULL);
    }
    else {
        _perfControlClient = IOPerfControlClient::copyClient(this, 0);
"""
DEXT_CAST_REPLACEMENT = """    _userBlockStorageDevice = NULL;
    {
        _perfControlClient = IOPerfControlClient::copyClient(this, 0);
"""


def driver_source():
    """IOBlockStorageDriver.cpp without its reference to the DriverKit class.

    The class is IOUserBlockStorageDevice, and on a phone it is the kernel half
    of a dext: its methods are forwarded to a DriverKit driver through the
    generated _Dispatch, and the seven _Impl functions that dispatch calls are
    written by that dext. A kext may be linked with those undefined, because
    the dext arrives later; a kernel may not -- run 40 named all seven, and run
    41 then named the generated dispatch that the kext half needs in turn.

    There is no dext on this board and there cannot be one, so the class is not
    in the kernel at all here. Everything that refers to it is in this one file,
    and every reference is a test for NULL: line 302 decides whether the perf
    control client is the driver's own, and lines 730 and 3513 pick which
    service to attribute work to. None of them calls a method on it, so with
    the member left NULL the file compiles with a forward declaration and the
    driver takes the path it takes for a device that is not dext-backed --
    which is what NioUfs is.

    The edit is made against exact text and fails loudly if the text moves, so
    a future checkout cannot silently compile something else.
    """
    original = (source_dir / 'IOBlockStorageDriver.cpp').read_text()
    if DEXT_INCLUDE not in original:
        sys.exit('IOBlockStorageDriver.cpp no longer includes IOUserBlockStorageDevice_kext.h; '
                 'the dext removal in scripts/build-storage-family.py needs another look')
    if DEXT_CAST not in original:
        sys.exit('IOBlockStorageDriver.cpp no longer casts its provider to IOUserBlockStorageDevice '
                 'in the shape this recipe removes; see scripts/build-storage-family.py')
    patched = original.replace(DEXT_INCLUDE,
                               '// no dext on this board: IOUserBlockStorageDevice is not in this kernel.')
    patched = patched.replace(DEXT_CAST, DEXT_CAST_REPLACEMENT)
    directory = out / 'sources'
    directory.mkdir(exist_ok=True)
    destination = directory / 'IOBlockStorageDriver.cpp'
    destination.write_text(patched)
    print('patched %s: dext path removed, %d bytes'
          % (destination.name, len(patched)))
    return destination


objects = []
failures = []
work = []
for name in FAMILY:
    source = source_dir / (name + '.cpp')
    if name == 'IOBlockStorageDriver':
        source = driver_source()
    work.append((name, source))
for name, source in work:
    destination = out / (Path(name).stem + '.o')
    destination.unlink(missing_ok=True)
    command = command_for(source, destination)
    (out / (name + '.command.json')).write_text(json.dumps(command, indent=2) + '\n')
    result = subprocess.run(command, cwd=record['directory'], text=True,
                           stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    (out / (name + '.log')).write_text(result.stdout)
    if result.returncode:
        errors = [line for line in result.stdout.splitlines() if 'error:' in line]
        failures.append((name, errors or result.stdout.splitlines()[-6:]))
        print('FAIL %s (%d lines of log, %d errors)' % (name, len(result.stdout.splitlines()), len(errors)))
        continue
    objects.append(destination)
    warnings = sum('warning:' in line for line in result.stdout.splitlines())
    print('PASS %s (%d warnings)' % (name, warnings))

if failures:
    print()
    for name, lines in failures:
        print('--- %s ---' % name)
        for line in lines[:12]:
            print('   ', line.strip())
    print()
    sys.exit('%d of %d IOStorageFamily sources did not compile; full logs in %s'
             % (len(failures), len(work), out))

archive = out / 'libIOStorageFamily.a'
archive.unlink(missing_ok=True)
subprocess.run(['xcrun', 'ar', 'rcs', str(archive), *map(str, objects)], check=True)

# The kernel link force-loads this archive. The only thing asserted here is
# that ar put every object in it: an archive that lost a member links with a
# pile of undefined C++ symbols that say nothing about which step dropped it.
#
# Nothing is asserted about the symbols themselves. Runs 37 and 38 both died
# in a class-name check written over `nm -gP`, and both times the archive was
# fine -- the portable format does not lay its fields out the way the parse
# assumed, and the second attempt at the same parse found no C++ names at all
# in an archive holding fourteen of them. The kernel link is the authority on
# whether a class is defined; it names the missing vtable in one line, and it
# is the step right after this one.
if not archive.is_file() or archive.stat().st_size == 0:
    sys.exit('ar produced no archive at %s' % archive)
# ar t also prints the archive's symbol table, as "__.SYMDEF SORTED" -- two
# words that made run 39 read 16 members for 14 objects. Only the .o names
# are members.
listing = subprocess.run(['xcrun', 'ar', 't', str(archive)], text=True,
                         stdout=subprocess.PIPE, check=True).stdout
members = [line.strip() for line in listing.splitlines() if line.strip().endswith('.o')]
if len(members) != len(objects):
    sys.exit('the archive holds %d objects for %d compiled: %s'
             % (len(members), len(objects), ' '.join(members)))
print('PASS: %d members, %d bytes -> %s'
      % (len(members), archive.stat().st_size, archive.relative_to(ROOT)))
