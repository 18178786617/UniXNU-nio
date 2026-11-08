#!/usr/bin/env python3
"""Re-base the IOBlockStorageDevice pin onto this board's kernel image.

Why this exists
---------------
`NioUfs` subclasses `IOBlockStorageDevice`, a class that is not part of XNU: it
ships inside the prelinked `com.apple.iokit.IOStorageFamily` kext, whose segments
the kernel image carries as `__PRELINK_TEXT`, `__PLK_TEXT_EXEC`,
`__PLK_DATA_CONST` and `__PRELINK_DATA`. Compiling Apple's sources into the kernel
registers the class twice and the boot panics on the duplicate, so the driver's
inherited slots are bound to the *prelinked* code instead, with absolute symbols:

    .globl __ZN20IOBlockStorageDevice7doUnmapE...
    .set   __ZN20IOBlockStorageDevice7doUnmapE..., 0xfffffff00496f074

scripts/build-storage-bindings.py writes those bindings from
scripts/prelink-storage-bindings.json, which this script produces.

How the addresses are obtained
------------------------------
A pin measured on a board with the same donor kernelcache is the starting point:
the prelink closure is copied out of that kernelcache verbatim, so its contents
-- the dispatch table, the metaclass, the constructor and destructor the class
references -- are the same bytes on every board built from the same
kernelcache.release.iphone10b.

What is *not* the same is where the closure lands. Our link places the whole
closure 0x1000000 lower than the donor's layout, while the kernel's own text
moves independently (here 0x8c000 higher). So an address is re-based only when
it falls inside a closure segment of the donor image; addresses in the kernel's
own `__TEXT_EXEC` are left alone. Every mapped address is then checked: the
dispatch slots must all land in executable text, the metaclass pointer must
contain the metaclass, and the slots that live in the kext's own text must be the
same set as in the reference pin.

Usage
-----
    scripts/pin-prelink-storage.py --donor kernelcache.decompressed \\
        --kernel build/kernel.macho --reference-pin other-board.json
"""
from __future__ import annotations

import argparse
import hashlib
import json
import struct
from pathlib import Path

HERE = Path(__file__).resolve()
DEVICE = HERE.parents[1]
DEFAULT_OUTPUT = HERE.with_name('prelink-storage-bindings.json')

CLOSURE = ('__PRELINK_TEXT', '__PRELINK_INFO', '__PLK_TEXT_EXEC',
           '__PRELINK_DATA', '__PLK_DATA_CONST', '__PLK_LINKEDIT', '__PLK_LLVM_COV')
EXECUTABLE = ('__TEXT_EXEC', '__PLK_TEXT_EXEC')


def fail(message: str) -> None:
    raise SystemExit('pin-prelink-storage: ' + message)


def image(path: Path):
    """The arm64 mach image's bytes and its segments."""
    data = path.read_bytes()
    ncmds = struct.unpack_from('<I', data, 16)[0]
    at, segments = 32, []
    for _ in range(ncmds):
        command, size = struct.unpack_from('<II', data, at)
        if command == 0x19:
            name = data[at + 8:at + 24].rstrip(b'\0').decode()
            va, vs, fo, fs = struct.unpack_from('<QQQQ', data, at + 24)
            segments.append({'name': name, 'va': va, 'size': vs, 'file': fo, 'file_size': fs})
        at += size
    return data, segments


def containing(address: int, segments):
    for segment in segments:
        if segment['va'] <= address < segment['va'] + segment['size']:
            return segment
    return None


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--donor', type=Path, required=True, help='the decompressed donor kernelcache')
    parser.add_argument('--kernel', type=Path, required=True, help='this board\'s built kernel image')
    parser.add_argument('--reference-pin', type=Path, required=True,
                        help='a pin measured on a board built from the same donor kernelcache')
    parser.add_argument('--output', type=Path, default=DEFAULT_OUTPUT)
    args = parser.parse_args()

    pin = json.loads(args.reference_pin.read_text())
    donor_data, donor_segments = image(args.donor)
    data, segments = image(args.kernel)

    def base(segments, name):
        for segment in segments:
            if segment['name'] == name:
                return segment['va']
        fail(f'{name} is missing from an image')

    for name in ('__PLK_TEXT_EXEC', '__PLK_DATA_CONST', '__PRELINK_DATA'):
        if base(segments, name) - base(donor_segments, name) != \
                base(segments, '__PLK_TEXT_EXEC') - base(donor_segments, '__PLK_TEXT_EXEC'):
            fail(f'the closure is not a rigid shift: {name} disagrees with __PLK_TEXT_EXEC')
    delta = base(segments, '__PLK_TEXT_EXEC') - base(donor_segments, '__PLK_TEXT_EXEC')

    def mapped(address: int) -> int:
        segment = containing(address, donor_segments)
        return address + delta if segment and segment['name'] in CLOSURE else address

    slots = [mapped(int(value, 16)) for value in pin['slots']]
    if len(slots) != pin['slot_count']:
        fail('the reference pin has an unexpected slot count')
    outside = [(index, hex(value)) for index, value in enumerate(slots)
               if not (containing(value, segments) or {}).get('name') in EXECUTABLE]
    if outside:
        fail('these dispatch slots do not land in executable text: ' + str(outside[:5]))

    vtable = mapped(int(pin['vtable'], 16))
    metaclass = mapped(int(pin['metaclass'], 16))
    metaclass_pointer = mapped(int(pin['metaclass_pointer'], 16))
    if (containing(vtable, segments) or {}).get('name') != '__PLK_DATA_CONST':
        fail('the vtable did not land in __PLK_DATA_CONST')
    at = containing(metaclass_pointer, segments)
    if not at:
        fail('the metaclass pointer is outside every segment')
    if struct.unpack_from('<Q', data, at['file'] + metaclass_pointer - at['va'])[0] != metaclass:
        fail('the metaclass pointer does not contain the metaclass')
    # The vtable's own slots must match the two the pin recorded, which is what
    # makes this a re-base rather than a fresh guess.
    at = containing(vtable, segments)
    first = struct.unpack_from('<2Q', data, at['file'] + vtable - at['va'] + 16)
    if [first[0] - delta, first[1] - delta] != [int(pin['slots'][0], 16), int(pin['slots'][1], 16)]:
        fail('the vtable at the mapped address does not start with the pinned destructors')

    text_va = mapped(int(pin['kext_text']['va'], 16))
    text_size = pin['kext_text']['size']
    owned = [index for index, value in enumerate(slots) if text_va <= value < text_va + text_size]
    if owned != pin['kext_owned_slots']:
        fail('the kext-owned slot set changed: %s' % owned)
    at = containing(text_va, segments)
    text_bytes = data[at['file']:at['file'] + text_size]

    result = {
        'kext': pin['kext'],
        'source': 'prelink closure of the donor kernelcache, re-based onto this board',
        'measured_from': args.donor.name,
        'kernelcache_sha256': hashlib.sha256(donor_data).hexdigest(),
        'rebased_against': args.kernel.name,
        'closure_shift': hex(delta),
        'slot_count': pin['slot_count'],
        'pure_virtual_slots': pin['pure_virtual_slots'],
        'abstract_destructor_slots': pin['abstract_destructor_slots'],
        'kext_text': {'va': hex(text_va), 'size': text_size,
                      'sha256': hashlib.sha256(text_bytes).hexdigest()},
        'kext_const': {'va': hex(mapped(int(pin['kext_const']['va'], 16))),
                       'size': pin['kext_const']['size']},
        'vtable': hex(vtable),
        'vtable_address_point': hex(mapped(int(pin['vtable_address_point'], 16))),
        'metaclass': hex(metaclass),
        'metaclass_pointer': hex(metaclass_pointer),
        'protected_constructor': hex(mapped(int(pin['protected_constructor'], 16))),
        'base_destructor': hex(mapped(int(pin['base_destructor'], 16))),
        'kext_owned_slots': owned,
        'slots': [hex(value) for value in slots],
    }
    args.output.write_text(json.dumps(result, indent=1) + '\n')
    print('wrote %s: %d slots, %d in the kext, closure shift %s'
          % (args.output.name, len(slots), len(owned), hex(delta)))
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
