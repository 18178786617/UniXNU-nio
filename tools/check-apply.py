#!/usr/bin/env python3
"""Apply the whole XNU patch series to a scratch copy of the pristine tree.

The build does this on CI; doing it here means a broken patch costs a minute
instead of a paid cycle.  The failure this catches is the one that stopped
run-181 and run-182: git apply refuses the patch two minutes into the build.

    python tools/check-apply.py [--pristine DIR] [--series DIR]

Both default to the layout this repository uses.
"""
import argparse
import pathlib
import shutil
import subprocess
import sys
import tempfile

ROOT = pathlib.Path(__file__).resolve().parent.parent


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--pristine', default=str(ROOT.parents[1] / '.tmp' / 'xnu-8796.101.5'))
    ap.add_argument('--series', default=str(ROOT / 'patches' / 'xnu-8796'))
    ap.add_argument('--keep', action='store_true')
    args = ap.parse_args()

    pristine = pathlib.Path(args.pristine)
    series_dir = pathlib.Path(args.series)
    names = [l.strip() for l in (series_dir / 'series').read_text().splitlines()
             if l.strip() and not l.strip().startswith('#')]
    if not pristine.is_dir():
        sys.exit(f'pristine tree not found: {pristine}')

    scratch = pathlib.Path(tempfile.mkdtemp(prefix='applycheck-'))
    try:
        work = scratch / 'xnu'
        shutil.copytree(pristine, work, symlinks=True)
        for n, name in enumerate(names, 1):
            patch = series_dir / name
            if not patch.is_file():
                sys.exit(f'{name}: listed in series but missing ({patch})')
            r = subprocess.run(['git', 'apply', '--check', '-p1', str(patch)],
                               cwd=work, capture_output=True, text=True)
            if r.returncode != 0:
                print(f'FAIL {name} (position {n} of {len(names)})')
                print((r.stderr or r.stdout).strip()[:800])
                sys.exit(1)
            r = subprocess.run(['git', 'apply', '-p1', str(patch)],
                               cwd=work, capture_output=True, text=True)
            if r.returncode != 0:
                print(f'FAIL {name} (apply after check passed)')
                print((r.stderr or r.stdout).strip()[:800])
                sys.exit(1)
            if n % 10 == 0 or n == len(names):
                print(f'  {n}/{len(names)} applied')
        print(f'ok: {len(names)} patches apply cleanly to {pristine}')
    finally:
        if not args.keep:
            shutil.rmtree(scratch, ignore_errors=True)
        else:
            print(f'kept: {scratch}')


if __name__ == '__main__':
    main()
