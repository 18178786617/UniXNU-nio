#!/usr/bin/env python3
"""Check that every hunk header in the patch series counts its own lines.

A hunk header says how many lines the hunk has:

    @@ -12,7 +12,8 @@

and patch reads exactly that many lines out of the hunk.  When the header
counts fewer lines than the hunk holds, the rest is dropped, and patch
says nothing about it.  The file that comes out is still valid: it
compiles, it links, and the code that was dropped from the end of it is
simply never there.

Run-170's kernel was built from such a patch.  One line had been added
to the file the patch creates -- an include -- without the header being
counted up, so patch wrote the file without its last line:

    STARTUP(EARLY_BOOT, STARTUP_RANK_SECOND, source_pthread_bootstrap);

The function was there and it called pthread_start(), which is what
registers libpthread's function table, and nothing ever called it.  The
boot died in bsd_init with

    pthread kernel extension not loaded (function table is NULL).

This reads every patch in the series and compares each header's counts
with the lines the hunk actually holds.  It prints what it finds and
exits nonzero when something does not add up.

    python3 device/tools/check-patch-hunks.py device/patches/xnu-8796
"""

import re
import sys
from pathlib import Path

HEADER = re.compile(r'^@@ -(\d+)(?:,(\d+))? \+(\d+)(?:,(\d+))? @@')


def check(path):
    """The problems in one patch file."""
    problems = []
    lines = path.read_text(encoding='utf-8', errors='replace').splitlines()
    i = 0
    while i < len(lines):
        line = lines[i]
        if not line.startswith('@@'):
            i += 1
            continue
        m = HEADER.match(line)
        if not m:
            problems.append('%s: cannot read the hunk header: %s'
                            % (path.name, line))
            i += 1
            continue
        old_count = int(m.group(2)) if m.group(2) is not None else 1
        new_count = int(m.group(4)) if m.group(4) is not None else 1

        # The body of the hunk: everything up to the next header or a
        # file header.
        body = []
        j = i + 1
        while j < len(lines):
            nxt = lines[j]
            if nxt.startswith('@@') or nxt.startswith('diff --git ') \
                    or nxt.startswith('---\n') or nxt.startswith('--- '):
                break
            body.append(nxt)
            j += 1

        old_held = sum(1 for b in body if b.startswith(' ') or b.startswith('-'))
        new_held = sum(1 for b in body if b.startswith(' ') or b.startswith('+'))
        # A "\ No newline at end of file" marker belongs to no side.
        body = [b for b in body if not b.startswith('\\')]

        if old_held != old_count or new_held != new_count:
            problems.append(
                '%s:%d: the header says %d old and %d new lines, the hunk '
                'holds %d and %d -- patch will drop %d of them\n'
                '    %s'
                % (path.name, i + 1, old_count, new_count,
                   old_held, new_held,
                   max(new_count - new_held, 0),
                   line))
        i = j
    return problems


def main():
    if len(sys.argv) < 2:
        raise SystemExit('usage: check-patch-hunks.py <patch-dir>')
    root = Path(sys.argv[1])
    patches = sorted(root.glob('*.patch'))
    if not patches:
        print('no patches in %s' % root)
        return 0

    problems = []
    for p in patches:
        problems.extend(check(p))

    print('checked %d patches in %s' % (len(patches), root))
    if not problems:
        print('every hunk header counts its own lines')
        return 0
    for p in problems:
        print(p)
    print('%d hunk headers do not match their hunks' % len(problems))
    return 1


if __name__ == '__main__':
    raise SystemExit(main())
