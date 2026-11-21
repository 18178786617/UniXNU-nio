#!/usr/bin/env python3
"""Resolve a kernel panic pc (and backtrace frames) to symbols.

Usage:
    lookup-pc.py 0xfffffff0076dae0c [more addresses...]

Reads the published out/kernel.macho, parses its LC_SYMTAB and prints the
nearest symbol at or below each address.  The kernel keeps its full symbol
table (271990 nlist_64 entries), so a panic photo's "pc:", "lr:" and "frames"
lines can be named without guessing or reflashing.

Mach-O 64 layout used here:
    mach_header_64 (32 bytes) then load commands;
    LC_SYMTAB = 0x2 -> symoff, nsyms, stroff, strsize at cmd+8;
    nlist_64 = 16 bytes: n_strx(u32) n_type(u8) n_sect(u8) n_desc(u16) n_value(u64).
"""
import bisect
import struct
import sys
from pathlib import Path

KERNEL = Path(__file__).resolve().parents[3] / 'out' / 'kernel.macho'


def load_symbols(path):
    d = path.read_bytes()
    if struct.unpack_from('<I', d, 0)[0] != 0xfeedfacf:
        raise SystemExit('not a Mach-O 64 file: %s' % path)
    ncmds = struct.unpack_from('<I', d, 16)[0]
    off = 32
    symtab = None
    text = None
    for _ in range(ncmds):
        cmd, cmdsize = struct.unpack_from('<II', d, off)
        if cmd == 0x2:
            symtab = struct.unpack_from('<IIII', d, off + 8)
        if cmd == 0x19:
            seg = d[off + 8:off + 24].rstrip(b'\0').decode(errors='replace')
            if seg == '__TEXT':
                text = struct.unpack_from('<Q', d, off + 24)[0]
        off += cmdsize
    if not symtab:
        raise SystemExit('no LC_SYMTAB in %s' % path)
    symoff, nsyms, stroff, strsize = symtab
    syms = []
    for i in range(nsyms):
        o = symoff + i * 16
        strx, _typ, _sect, _desc, val = struct.unpack_from('<IBBHQ', d, o)
        if text is None or text <= val < text + 0x1000000:
            end = d.find(b'\0', stroff + strx)
            name = d[stroff + strx:end].decode('latin1')
            syms.append((val, name))
    syms.sort()
    return syms


def main():
    syms = load_symbols(KERNEL)
    addrs = [s[0] for s in syms]
    for arg in sys.argv[1:]:
        pc = int(arg, 16)
        i = bisect.bisect_right(addrs, pc) - 1
        while i >= 0 and not syms[i][1]:
            i -= 1
        if i < 0:
            print('%s -> no symbol' % arg)
            continue
        val, name = syms[i]
        print('%s -> %s + 0x%x' % (arg, name, pc - val))


if __name__ == '__main__':
    main()
