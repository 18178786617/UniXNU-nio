#!/usr/bin/env python3
"""Read the console text out of a ramoops console record.

The kernel mirrors every character it prints into a pstore-style console
record in memory: a header of { u32 sig='DBGC', u32 start, u32 size }
followed by a plain-text ring.  The QEMU harness saves that record out of
the guest's memory, and the build publishes it beside the kernel, so the
whole console of a round is available as text.

That is worth having on its own.  The board's console ring holds nothing
that survives, the serial port carries no output at all, and the panel
is a framebuffer that only a photograph of the phone can show.  A round
that cannot be read is a round that has to be guessed at, and a guess
costs a whole build.

  read-console.py out/qemu/ramoops.bin
  read-console.py out/qemu/ramoops.bin --tail 40

The text ring is printed as it stands.  The bytes before the ring's own
header are the rest of the record and are not text, so they are skipped.
"""

import argparse
import struct
import sys

SIGNATURE = b"DBGC"


def read_record(path):
    with open(path, "rb") as handle:
        data = handle.read()
    if len(data) < 12:
        raise SystemExit("%s: too short to hold a console record" % path)
    signature, start, size = struct.unpack_from("<4sII", data, 0)
    if signature != SIGNATURE:
        raise SystemExit(
            "%s: no console record here (the signature is %r, not %r)"
            % (path, signature, SIGNATURE))
    # The header says where the ring is and how long it is.  A record
    # written by a kernel that never printed anything has a ring of no
    # length, and one whose range falls outside the file is a record this
    # reader does not understand.  In both cases the text that follows the
    # header is the best guess available, and it costs nothing to look.
    text = b""
    if size and start + size <= len(data):
        text = data[start:start + size]
    if not text:
        text = data[12:]
    return text


def main(argv):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("record", help="the ramoops console record")
    parser.add_argument("--tail", type=int, default=0,
                        help="print only the last N lines")
    parser.add_argument("--grep", default=None,
                        help="print only the lines that match this text")
    args = parser.parse_args(argv[1:])

    text = read_record(args.record).decode("utf-8", "replace")
    lines = text.splitlines()
    if args.grep:
        lines = [l for l in lines if args.grep in l]
    if args.tail and len(lines) > args.tail:
        lines = lines[-args.tail:]
    for line in lines:
        print(line)
    print("--- %d line(s) from %s" % (len(lines), args.record), file=sys.stderr)
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv))
