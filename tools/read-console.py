#!/usr/bin/env python3
"""Read the nio kernel console out of a guest memory dump.

The kernel mirrors every console character into the ramoops pstore console
record at 0xAF040000 (nio-console-to-ramoops.patch):

    { u32 sig = 'DBGC' (0x43474244), u32 start, u32 size } + text ring

so a dump of that page is the console as plain text -- no pixel decoding, no
photographs.  QEMU hands us the dump with pmemsave; this turns it into
readable lines.

Usage:
    read-console.py ramoops.bin [--text out.txt]
    read-console.py fb.bin --decode --font DiagFont.h
"""

import argparse
import pathlib
import re
import struct
import sys

RAMOOPS_SIG = 0x43474244
RAMOOPS_RING = 0x3F000


def read_ramoops(path):
    raw = pathlib.Path(path).read_bytes()
    if len(raw) < 12:
        raise SystemExit("dump too short: %d bytes" % len(raw))
    sig, start, size = struct.unpack_from("<III", raw, 0)
    if sig != RAMOOPS_SIG:
        raise SystemExit("signature mismatch: 0x%08x (expected 0x%08x)"
                         % (sig, RAMOOPS_SIG))
    count = size or RAMOOPS_RING
    count = min(count, RAMOOPS_RING, max(0, len(raw) - 12))
    return raw[12:12 + count].decode("latin1")


def clean(text):
    """Make the ring readable: the console wraps and pads with spaces."""
    lines = []
    for raw in text.split("\n"):
        # the ring is a byte stream, so a line can end mid-escape
        raw = raw.replace("\r", "")
        raw = re.sub(r"\x1b\[[0-9;?]*[A-Za-z]", "", raw)   # ansi colours
        raw = re.sub(r"[\x00-\x08\x0b\x0c\x0e-\x1f]", "", raw)
        lines.append(raw.rstrip())
    while lines and not lines[0].strip():
        lines.pop(0)
    while lines and not lines[-1].strip():
        lines.pop()
    return lines


def parse_font(path):
    """Read GLYPH_FONT from the DarwinBoot diag font header.

    Each glyph is one 64-bit value: the top 32 bits are the upper 8 rows of a
    5x16 cell, the low 32 bits the lower 8, five bits per row.
    """
    text = pathlib.Path(path).read_text(errors="replace")
    body = text.split("GLYPH_FONT", 1)[-1]
    values = [int(v, 16) for v in re.findall(r"0x([0-9A-Fa-f]{16})", body)]
    if not values:
        raise SystemExit("no glyph values found in %s" % path)
    return values


def decode_fb(path, font, width=1080, height=2520, pitch=4320):
    """Match glyph bitmaps in a BGRA framebuffer dump against the font."""
    raw = pathlib.Path(path).read_bytes()
    glyphs = {}
    for code in range(32, 128):
        if code - 32 >= len(font):
            break
        value = font[code - 32]
        top = (value >> 32) & 0xFFFFFFFF
        bottom = value & 0xFFFFFFFF
        rows = []
        for word in (top, bottom):
            for row in range(8):
                rows.append((word >> (row * 4)) & 0xF)
        # the cell is 5 wide; the font packs 4 bits per row, so column 4 is
        # taken from the 5th pixel of the packed layout when present
        glyphs.setdefault(tuple(rows), chr(code))
    out = []
    for y in range(0, height, 16):
        line = []
        for x in range(0, width, 8):
            rows = []
            for r in range(16):
                if y + r >= height:
                    rows.append(0)
                    continue
                base = (y + r) * pitch + x * 4
                if base + 4 > len(raw):
                    rows.append(0)
                    continue
                b, g, rr = raw[base], raw[base + 1], raw[base + 2]
                rows.append(1 if (rr + g + b) > 240 else 0)
            line.append(glyphs.get(tuple(rows), " "))
        out.append("".join(line).rstrip())
    return out


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("dump")
    ap.add_argument("--text", help="write the console text here")
    ap.add_argument("--decode", action="store_true",
                    help="the dump is a framebuffer, decode it with --font")
    ap.add_argument("--font", help="DiagFont.h with GLYPH_FONT")
    ap.add_argument("--tail", type=int, default=40, help="last N lines")
    args = ap.parse_args(argv)

    if args.decode:
        if not args.font:
            raise SystemExit("--decode needs --font")
        lines = decode_fb(args.dump, parse_font(args.font))
    else:
        lines = clean(read_ramoops(args.dump))

    text = "\n".join(lines)
    if args.text:
        pathlib.Path(args.text).write_text(text + "\n", encoding="utf-8")
        print("wrote %s (%d lines)" % (args.text, len(lines)))
    for line in lines[-args.tail:]:
        print(line)
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
