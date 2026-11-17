#!/usr/bin/env python3
"""Merge the board's kernel_args into the menu configuration's args line.

The upstream build reads [payload] kernel_args from board.toml and writes
them into the menu configuration's args field, so that file is the only
place the kernel command line lives.  The packer here shipped the menu
file as it stood instead, and the two had drifted: board.toml carried
arguments the menu file did not name, and they never arrived at the
kernel, and nothing said so.

So they are merged.  The menu file keeps the arguments it has, because
rd=md0 and the ramdisk entry are tied to the device tree's RAMDisk
placeholder -- DarwinBoot refuses a kernel whose menu and device tree do
not agree, as Compromised Data, before the kernel runs at all -- and
board.toml's arguments are added for the ones the menu file does not
name.  The argument's name is what is compared, so a value may differ
without both being passed.

usage: merge-kernel-args.py <menu.toml> <board.toml> <out.toml>
       merge-kernel-args.py --print <menu.toml> <board.toml>
"""

import re
import sys


def merged_args(menu_path, board_path):
    """The kernel command line: the menu file's arguments, then the board's.

    Returns (merged, added).
    """
    menu = open(menu_path, encoding="utf-8").read()
    board = open(board_path, encoding="utf-8").read()

    m = re.search(r"kernel_args\s*=\s*\[(.*?)\]", board, re.S)
    board_args = re.findall(r'"([^"]*)"', m.group(1)) if m else []

    a = re.search(r'^args\s*=\s*"(.*)"\s*$', menu, re.M)
    if not a:
        raise SystemExit("the menu file has no args line")
    menu_args = a.group(1).split()

    seen = set()
    for arg in menu_args:
        seen.add(arg.split("=", 1)[0])

    merged = list(menu_args)
    added = []
    for arg in board_args:
        name = arg.split("=", 1)[0]
        if name not in seen:
            seen.add(name)
            merged.append(arg)
            added.append(arg)
    return merged, added, a, menu


def main():
    if len(sys.argv) == 4 and sys.argv[1] == "--print":
        merged, added, _, _ = merged_args(sys.argv[2], sys.argv[3])
        # The command line, on one line, for the emulator and for anything
        # else that has to hand the kernel the same arguments the phone
        # does.  Printing it here keeps that a single source: the menu
        # file and the board file, merged the same way every time.
        print(" ".join(merged))
        return 0

    if len(sys.argv) != 4:
        print(__doc__)
        return 2
    menu_path, board_path, out_path = sys.argv[1], sys.argv[2], sys.argv[3]

    merged, added, a, menu = merged_args(menu_path, board_path)

    if added:
        print("  board.toml arguments added: %s" % " ".join(added))
    else:
        print("  board.toml adds nothing the menu file does not already name")

    line = 'args = "%s"' % " ".join(merged)
    menu = menu[:a.start()] + line + menu[a.end():]
    with open(out_path, "w", encoding="utf-8", newline="\n") as f:
        f.write(menu)
    print("  %d arguments, %d bytes" % (len(merged), len(line)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
