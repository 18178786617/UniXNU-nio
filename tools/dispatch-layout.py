#!/usr/bin/env python3
"""Print the dispatch layout of the IOMobileGraphicsFamily classes.

A class's dispatch table is the array of function pointers its constructor
installs into `this[0]`. A derived class that overrides a method puts its
own function there; a class that does not overrides it keeps the function it
inherited. The table is therefore the class's ABI, slot by slot, and a port
that inherits from a class needs to know exactly which slots it must fill.

The own-versus-inherited question is answered by ownership, not by name: the
image's __PRELINK_INFO says where every kext's segments live, so a
function pointer that lands inside a kext's extent is that kext's code.

Usage:
    python tools/dispatch-layout.py <kernel image> [class name ...]

With no class name, every class of the kext is printed. The class names are
the plain C++ ones ("IOMobileFramebufferLegacy"), not the mangled ones.
"""
import os
import struct
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
KEXT_ID = 'com.apple.iokit.IOMobileGraphicsFamily'
CLASSES = ['IOMobileFramebuffer', 'IOMobileFramebufferLegacy',
           'IOMobileFramebufferService', 'IOMobileFramebufferUserClient']


def find_kit():
    """The XnuPrelink kit: vendored in the tree, or beside it in a checkout."""
    candidates = []
    if os.environ.get('UNIXNU_KIT'):
        candidates.append(Path(os.environ['UNIXNU_KIT']))
    candidates += [
        ROOT / 'kits/XnuPrelink',
        ROOT.parents[1] / 'refs/UniXNU/kits/XnuPrelink',
        ROOT.parent / 'UniXNU/kits/XnuPrelink',
    ]
    for candidate in candidates:
        if (candidate / 'native_prelink.py').is_file():
            return candidate
    raise SystemExit('the XnuPrelink kit is missing; set UNIXNU_KIT')


def load_native_prelink():
    import importlib.util
    kit = find_kit()
    sys.path.insert(0, str(kit))
    spec = importlib.util.spec_from_file_location('native_prelink', kit / 'native_prelink.py')
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def bindings_of(class_name, image_path):
    """(metaclass, dispatch table) of a class, from the bindings tool.

    The bindings tool already recovers the class initializer, the metaclass
    and the dispatch table from the binary; this tool asks it rather than
    doing the same work twice.
    """
    tool = HERE / 'find-mobile-framebuffer-bindings.py'
    output = subprocess.run([sys.executable, str(tool), str(image_path), class_name],
                             capture_output=True, text=True)
    if output.returncode:
        return None
    metaclass = table = None
    for line in output.stdout.splitlines():
        fields = line.split()
        if len(fields) >= 2 and fields[0] == 'metaclass' and fields[1] != 'not':
            metaclass = int(fields[1], 16)
        # "  parent dispatch table                      0x6decd70"
        if 'dispatch' in line and 'table' in line and 'entries' not in line:
            value = line.rsplit(None, 1)[-1]
            if value.startswith('0x'):
                table = int(value, 16)
    return (metaclass, table) if table else None


def main():
    if len(sys.argv) < 2:
        raise SystemExit(__doc__)
    image_path = Path(sys.argv[1])
    wanted = sys.argv[2:] or CLASSES

    np = load_native_prelink()
    blob = image_path.read_bytes()
    image = np.macho(blob)
    segs = image['segments']
    exports = np.exports(blob, image)

    def read(address, length):
        offset = np.backed_offset(segs, address, length, len(blob))
        return blob[offset:offset + length]

    # ---- where every kext's code lives ---------------------------------
    info = next(s for s in segs if s['name'] == '__PRELINK_INFO')
    at = np.backed_offset(segs, info['va'], info['filesize'], len(blob))
    metadata = np.unserialize_xml(blob[at:at + info['filesize']])
    extents = []
    for entry in metadata['_PrelinkInfoDictionary']:
        if entry.get('OSKernelResource') is True:
            continue
        va = entry.get('_PrelinkExecutableLoadAddr')
        if va is None or not entry.get('_PrelinkExecutableSize'):
            continue
        header = np.backed_offset(segs, va, 32, len(blob))
        module = np.macho(blob, header)
        for segment in module['segments']:
            if segment['size'] and segment['name'] != '__LINKEDIT':
                extents.append((segment['va'], segment['va'] + segment['size'],
                                entry['CFBundleIdentifier']))
    extents.sort()

    def owner(address):
        for low, high, identifier in extents:
            if low <= address < high:
                return identifier
        return None

    reverse = {}
    for address, exported in exports.items():
        for name in exported:
            reverse.setdefault(address, name)
    # The pure virtual stub is looked up by its name, not by what the
    # reverse map happens to hold for its address: an address can carry
    # several names, and the one that matters here is this one.
    pure = None
    for address, exported in exports.items():
        if '___cxa_pure_virtual' in exported:
            pure = address
            break

    for class_name in wanted:
        found = bindings_of(class_name, image_path)
        if not found:
            print('%s: the bindings could not be read' % class_name)
            continue
        metaclass, table = found
        entries = []
        for index in range(0, 8192, 8):
            raw = read(table + index, 8)
            if raw is None:
                break
            value = struct.unpack('<Q', raw)[0]
            if value in (0, 0xffffffffffffffff):
                break
            entries.append(value)

        own, pure_slots, inherited = [], [], []
        for index, value in enumerate(entries):
            if value == pure:
                pure_slots.append(index)
            elif owner(value) == KEXT_ID:
                own.append(index)
            else:
                inherited.append(index)

        print('=== %s ===' % class_name)
        print('  dispatch table %s, %d slots' % (hex(table), len(entries)))
        print('  metaclass %s' % hex(metaclass))
        print('  own %d, inherited %d, pure virtual %d'
              % (len(own), len(inherited), len(pure_slots)))
        print('  own slots: %s' % ', '.join(str(i) for i in own))
        if pure_slots:
            print('  pure virtual slots: %s' % ', '.join(str(i) for i in pure_slots))
        print()


if __name__ == '__main__':
    main()
