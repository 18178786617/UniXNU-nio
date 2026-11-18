#!/usr/bin/env python3
"""fix-eol.py -- put the driver's source files back the line endings they had.

Three files in this driver carry different line endings, and git's
``core.autocrlf`` rewrites them on every commit, so an edit that
touched one of them shows up as a change to every line in the file.
The repository's own copy is the truth: whatever line endings a file
has in ``HEAD`` is what it must have in the working tree.

    python tools/fix-eol.py            # report only
    python tools/fix-eol.py --fix      # rewrite the files

Run it before ``git add`` on a change that touches this driver.
"""
import argparse
import os
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
FILES = [
    "drivers/NioUfs/NioUfs.cpp",
    "drivers/NioUfs/GccUfs.h",
    "drivers/NioUfs/RootQueue.h",
    "drivers/NioUfs/RootCommands.h",
]


def head_bytes(path):
    out = subprocess.run(
        ["git", "-C", REPO, "cat-file", "-p", "HEAD:" + path],
        capture_output=True)
    return out.stdout if out.returncode == 0 else None


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--fix", action="store_true")
    args = parser.parse_args()

    bad = []
    for path in FILES:
        full = os.path.join(REPO, path)
        if not os.path.exists(full):
            continue
        head = head_bytes(path)
        if head is None:
            print("%s: not in HEAD, skipped" % path)
            continue
        want_crlf = head.count(b"\r\n") > 0
        data = open(full, "rb").read()
        have_crlf = data.count(b"\r\n") > 0
        if want_crlf == have_crlf:
            print("%s: endings match" % path)
            continue
        bad.append(path)
        if args.fix:
            if want_crlf:
                data = data.replace(b"\r\n", b"\n").replace(b"\n", b"\r\n")
            else:
                data = data.replace(b"\r\n", b"\n")
            open(full, "wb").write(data)
            print("%s: rewritten to %s" % (path, "CRLF" if want_crlf else "LF"))
        else:
            print("%s: endings differ (HEAD wants %s) -- run with --fix"
                  % (path, "CRLF" if want_crlf else "LF"))

    if bad and not args.fix:
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
