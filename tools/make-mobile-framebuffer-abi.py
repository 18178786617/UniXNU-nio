#!/usr/bin/env python3
"""Generate the iOS 16.5 display ABI mirror header from the donor kernelcache.

The port replaces the original IOMobileFramebuffer family with its own class.
To do that in C++ the class has to have the original's vtable, slot for slot:
a method that the port overrides has to land in the slot the original put it
in, or the original's callers reach the wrong function.

The original's slot names are not recoverable from the binary -- the prelinked
kext carries no symbol table -- so the mirror names the slots it cannot
identify and names the ones it can. That is the same contract sheng's port
used on the 17.7.11 family (refs/GopFramebuffer/OriginalMobileFramebufferABI.h):
every unidentified slot is a pure virtual that must not return, and a port that
advertises such a slot as supported is lying.

The slot numbers come from the donor kernelcache: the dispatch table is the
array of function pointers the class's constructor installs, and the tool that
reads it is tools/dispatch-layout.py. The three bindings the port needs -- the
class's constructor, its destructor and its metaclass -- come from
tools/find-mobile-framebuffer-bindings.py.

Usage:
    python tools/make-mobile-framebuffer-abi.py <kernel image> [output header]

The image is the decompressed 16.5 kernelcache (donor/kernelcache.decompressed.gz
unpacked). The header defaults to package/OriginalMobileFramebufferABI16_5.h.
"""
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent

# The three classes the port needs, in the order they inherit from each other.
CHAIN = ['IOMobileFramebuffer', 'IOMobileFramebufferService', 'IOMobileFramebufferLegacy']

# The sizes the 16.5 kext reports: the size of a class is its data, not its
# vtable, and the mirror has to agree with the original's own layout.
SIZES = {'IOMobileFramebuffer': 144, 'IOMobileFramebufferService': 144,
         'IOMobileFramebufferLegacy': 5728}

# The methods the port calls on the base class. Empty on purpose: the prelinked
# kext carries no symbol table, so the name of a slot the kext implements cannot
# be read off the binary. The 17.7.11 family names are listed below as the
# table a structural match is made against -- the two kexts are builds of the
# same sources, so a method's body in the 16.5 kext matches the 17.7.11 one it
# came from. Until that match is made, every slot stays unnamed: a port that
# calls a slot under a guessed name calls a function whose signature it does
# not know.
NAMED = {}

# The 17.7.11 family's names, by slot, as sheng's mirror header records them.
# This is the table the structural match is made against; it is not used to
# generate anything.
I17_SLOTS = {
    182: 'beforeExternalMethod()',
    193: 'releaseClientState(IOUserClient *)',
    249: 'getDisplayDimensions(uint32_t *, uint32_t *)',
}


def load_tool():
    import importlib.util
    spec = importlib.util.spec_from_file_location('dispatch_layout', HERE / 'dispatch-layout.py')
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def slots_of(dispatch_layout, np, blob, image, class_name, image_path):
    """The class's dispatch table: (metaclass, table address, [slot values])."""
    found = dispatch_layout.bindings_of(class_name, image_path)
    if not found:
        raise SystemExit('%s: the bindings could not be read' % class_name)
    metaclass, table = found
    segs = image['segments']

    def read(address, length):
        offset = np.backed_offset(segs, address, length, len(blob))
        return blob[offset:offset + length]

    entries = []
    for index in range(0, 8192, 8):
        raw = read(table + index, 8)
        if raw is None:
            break
        value = struct.unpack('<Q', raw)[0]
        if value in (0, 0xffffffffffffffff):
            break
        entries.append(value)
    return metaclass, table, entries


def own_slots(np, blob, image):
    """The slots each class implements itself, by the kext's own code."""
    info = next(s for s in image['segments'] if s['name'] == '__PRELINK_INFO')
    at = np.backed_offset(image['segments'], info['va'], info['filesize'], len(blob))
    metadata = np.unserialize_xml(blob[at:at + info['filesize']])
    extents = []
    for entry in metadata['_PrelinkInfoDictionary']:
        if entry.get('OSKernelResource') is True:
            continue
        va = entry.get('_PrelinkExecutableLoadAddr')
        if va is None or not entry.get('_PrelinkExecutableSize'):
            continue
        header = np.backed_offset(image['segments'], va, 32, len(blob))
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

    return owner


def main():
    if len(sys.argv) < 2:
        raise SystemExit(__doc__)
    image_path = Path(sys.argv[1])
    output = Path(sys.argv[2]) if len(sys.argv) > 2 else ROOT / 'package' / 'OriginalMobileFramebufferABI16_5.h'

    dispatch_layout = load_tool()
    np = dispatch_layout.load_native_prelink()
    blob = image_path.read_bytes()
    image = np.macho(blob)
    owner = own_slots(np, blob, image)

    pure = None
    exports = np.exports(blob, image)
    for address, exported in exports.items():
        if '___cxa_pure_virtual' in exported:
            pure = address
            break

    # The base of the chain: the first class that adds a slot of its own is
    # the first class the port has to mirror past the kernel's own IOService.
    tables = {}
    for name in CHAIN:
        metaclass, table, entries = slots_of(dispatch_layout, np, blob, image, name, image_path)
        tables[name] = (metaclass, table, entries)

    lines = []
    lines.append('// SPDX-License-Identifier: BSD-2-Clause-Patent')
    lines.append('#pragma once')
    lines.append('// The iOS 16.5 display ABI, mirrored from the donor kernelcache.')
    lines.append('//')
    lines.append('// Generated by tools/make-mobile-framebuffer-abi.py from the 16.5 donor; do not')
    lines.append('// edit by hand, regenerate instead. Every slot the port does not identify is a')
    lines.append('// pure virtual that must not return: the original kext carries no symbol table,')
    lines.append('// so the names of the slots it does not implement cannot be recovered, and a')
    lines.append('// port that calls one of them is calling a function whose signature it does not')
    lines.append('// know.')
    lines.append('//')
    lines.append('// The chain mirrors the original one exactly, and each class declares only the')
    lines.append('// slots it adds: the kernel\'s own IOService holds the first 168 slots,')
    lines.append('// IOMobileFramebuffer adds 168..251, IOMobileFramebufferService adds none, and')
    lines.append('// IOMobileFramebufferLegacy adds 252..337. That is what puts a port\'s override')
    lines.append('// in the slot the original put it in.')
    lines.append('#include <IOKit/IOService.h>')
    lines.append('#include <IOKit/IOUserClient.h>')
    lines.append('')

    # The parent's own table length: a class declares the slots past its parent's.
    parent_length = {'IOMobileFramebuffer': 168,   # the kernel's IOService
                     'IOMobileFramebufferService': len(tables['IOMobileFramebuffer'][2]),
                     'IOMobileFramebufferLegacy': len(tables['IOMobileFramebufferService'][2])}
    parent_class = {'IOMobileFramebuffer': 'IOService',
                    'IOMobileFramebufferService': 'IOMobileFramebuffer',
                    'IOMobileFramebufferLegacy': 'IOMobileFramebufferService'}

    for name in CHAIN:
        metaclass, table, entries = tables[name]
        first = parent_length[name]
        lines.append('// %s: %d slots in total, %d of them its own.'
                     % (name, len(entries), len(entries) - first))
        lines.append('class %s : public %s {' % (name, parent_class[name]))
        lines.append('    OSDeclareAbstractStructors(%s)' % name)
        if name == 'IOMobileFramebuffer':
            lines.append('    uint64_t familyPrivate;')
        lines.append('public:')
        named = NAMED.get(name, {})
        for slot in range(first, len(entries)):
            if slot in named:
                lines.append('    virtual IOReturn %s = 0;' % named[slot])
            else:
                lines.append('    virtual __attribute__((noreturn)) void unclassified%d() = 0;' % slot)
        lines.append('};')
        lines.append('')

    lines.append('static_assert(sizeof(IOService)==%d && sizeof(IOMobileFramebuffer)==%d'
                 ' && sizeof(IOMobileFramebufferService)==%d);'
                 % (136, SIZES['IOMobileFramebuffer'], SIZES['IOMobileFramebufferService']))
    lines.append('')

    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text('\n'.join(lines))
    print('wrote %s' % output)
    for name in CHAIN:
        metaclass, table, entries = tables[name]
        print('  %-30s %3d slots, table %s, metaclass %s'
              % (name, len(entries), hex(table), hex(metaclass)))


if __name__ == '__main__':
    main()
