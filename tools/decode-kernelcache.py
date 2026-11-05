#!/usr/bin/env python3
"""Decode the iOS 16.5 kernelcache into the arm64 slice the prelink step reads.

The donor this board prelinks against is the arm64 slice of the iOS 16.5
kernelcache. The kernelcache in the image is an IMG4 container whose payload
is LZFSE-compressed, and the decompressed image is a fat Mach-O with one
arm64 slice. The prelink step consumes that slice, and board.toml pins its
sha256.

Three things in this file, in the order they are needed:

  1. img4_payload() finds the LZFSE stream inside the container. An IMG4
     container is a chain of tagged structures: the outer one carries the
     magic 0x30840115, and inside it a "Kern" tag holds a build string and
     then a second IMG4 container whose magic (0x04840115) says the payload
     is LZFSE.

  2. The LZFSE stream is decoded with the "lzfse" module from PyPI, which
     wraps Apple's own implementation:

         python3 -m pip install lzfse

     Apple's compression_tool is the other decoder and only exists on macOS
     ("compression_tool -decode -a lzfse"), which is why this exists.

  3. arm64_slice() picks the one arm64 slice out of the fat Mach-O, and the
     slice's sha256 is what board.toml pins.

The result is written as "kernelcache.decompressed", the same name
scripts/unixnu/ipsw.py uses, so the two agree on the file.

    python3 tools/decode-kernelcache.py \\
        E:/nio-unixnu-port/ios165/ipsw/kernelcache.release.iphone10b \\
        out/kernelcache/kernelcache.decompressed

    sha256  e6fa75598f47b5a9460a60913e2ac8e4cd6cd60eb475bb31da65b68ffbcfdad5
"""
from __future__ import annotations

import hashlib
import struct
import sys
from pathlib import Path

# The sha256 board.toml [kernel.prelink] pins for this image.
EXPECTED = 'e6fa75598f47b5a9460a60913e2ac8e4cd6cd60eb475bb31da65b68ffbcfdad5'


def img4_payload(data: bytes) -> bytes:
    """The LZFSE stream inside an IMG4 container.

    An IMG4 container is a chain of tagged structures. The outer one has the
    magic 0x30840115 and an IM4P tag; inside that tag sits a "Kern" entry
    holding a build string and then a second IMG4 container whose magic
    (0x04840115) says the payload is LZFSE.

    The stream itself starts at its "bvx2" magic, which is what this returns;
    the bytes before it are the container's own bookkeeping and are not part
    of the compressed data.
    """
    if data[:4] != b'\x30\x84\x01\x15':
        raise SystemExit('not an IMG4 container: magic %r' % data[:4])
    # The nested container's magic precedes the LZFSE stream.
    nested = data.find(b'\x04\x84\x01\x15', 8)
    if nested < 0:
        raise SystemExit('no nested LZFSE container in the image')
    start = data.find(b'bvx2', nested)
    if start < 0:
        raise SystemExit('no LZFSE stream in the image')
    return data[start:]


def arm64_slice(fat: bytes) -> bytes:
    """The one arm64 slice of a fat Mach-O."""
    if fat[:4] != b'\xca\xfe\xba\xbe':
        raise SystemExit('the decompressed image is not a fat Mach-O')
    count = struct.unpack('>I', fat[4:8])[0]
    slices = [struct.unpack('>5I', fat[8 + 20 * i:28 + 20 * i]) for i in range(count)]
    arm64 = [s for s in slices if s[0] == 0x0100000C]
    if len(arm64) != 1:
        raise SystemExit('expected exactly one arm64 slice, found %d' % len(arm64))
    _, _, offset, size, _ = arm64[0]
    return fat[offset:offset + size]


def main() -> int:
    if len(sys.argv) < 2:
        raise SystemExit(__doc__)
    source = Path(sys.argv[1])
    destination = Path(sys.argv[2]) if len(sys.argv) > 2 else source.with_suffix('.decompressed')

    try:
        import lzfse
    except ImportError:
        raise SystemExit('the lzfse module is missing: python3 -m pip install lzfse')

    data = source.read_bytes()
    payload = img4_payload(data)
    fat = lzfse.decompress(payload)
    print('decompressed %d bytes' % len(fat), file=sys.stderr)

    arm64 = arm64_slice(fat)
    digest = hashlib.sha256(arm64).hexdigest()
    print('arm64 slice: %d bytes' % len(arm64), file=sys.stderr)
    print('sha256: %s' % digest)

    if digest != EXPECTED:
        print('::warning::this does not match the pin in board.toml (%s)' % EXPECTED,
              file=sys.stderr)

    destination.parent.mkdir(parents=True, exist_ok=True)
    destination.write_bytes(arm64)
    print('written: %s' % destination, file=sys.stderr)
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
