#!/usr/bin/env python3
"""Check that every patch in patches/xnu-8796/series is structurally intact.

The failure this catches is the cheap one and also the expensive one: a hunk
whose @@ header claims a different number of lines than the body carries makes
git apply reject the patch, and the build stops in the patch step ~two minutes
in -- but only on a paid CI cycle, never locally, because nothing local applies
the series. Editing the content of an added line is safe; adding or removing a
line without touching the header is not, and that is a one-character mistake.

    python scripts/check-series.py [--dir patches/xnu-8796]

Exits non-zero and names the hunk when a count does not add up.
"""
import argparse
import pathlib
import re
import sys

HUNK = re.compile(r'^@@ -(\d+)(?:,(\d+))? \+(\d+)(?:,(\d+))? @@')


def check(path):
    """Return (hunks, problems) for one patch file."""
    lines = path.read_text(errors='replace').split('\n')
    last = len(lines) - 1
    problems, hunks, current, i = [], 0, None, 0

    def close(state):
        # A hunk body that ran out before its header said it would is the
        # defect; a hunk left with counts on both sides means the same thing.
        if state and (state[0] or state[1]):
            problems.append('hunk at line %d is short by old=%d new=%d'
                            % (state[2], state[0], state[1]))

    while i < len(lines):
        line = lines[i]
        match = HUNK.match(line)
        if match:
            close(current)
            current = [int(match.group(2) or 1), int(match.group(4) or 1), i + 1]
            hunks += 1
        elif current is not None:
            if line.startswith('+'):
                current[1] -= 1
            elif line.startswith('-'):
                current[0] -= 1
            elif line.startswith(' ') or (line == '' and i < last):
                # A context line whose single leading space was stripped by an
                # editor shows up as an empty line; the final '' of a trailing
                # newline is not one of those, hence the last-element test.
                current[0] -= 1
                current[1] -= 1
            else:
                close(current)
                current = None
        i += 1
    close(current)
    return hunks, problems


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--dir', default=str(pathlib.Path(__file__).resolve().parent.parent
                                        / 'patches' / 'xnu-8796'))
    args = ap.parse_args()
    base = pathlib.Path(args.dir)
    series = base / 'series'
    if not series.is_file():
        raise SystemExit('no series file at %s' % series)

    names = [line.strip() for line in series.read_text().splitlines() if line.strip()]
    total_hunks = total_problems = 0
    for name in names:
        path = base / name
        if not path.is_file():
            print('%-58s MISSING' % name)
            total_problems += 1
            continue
        hunks, problems = check(path)
        total_hunks += hunks
        if problems:
            total_problems += len(problems)
            print('%-58s hunks=%d %s' % (name, hunks, '; '.join(problems)))
    print('files=%d hunks=%d problems=%d' % (len(names), total_hunks, total_problems))
    return 1 if total_problems else 0


if __name__ == '__main__':
    sys.exit(main())
