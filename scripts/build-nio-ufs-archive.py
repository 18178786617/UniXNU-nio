#!/usr/bin/env python3
"""Lay the board's UFS archive down under the name the kernel link expects.

scripts/build-xnu-4k-baseline.sh links the UFS transport by a fixed path:

    UFS_ARCHIVE=$ROOT/build/sheng-ufs/libShengUfs.a
    test -f "$UFS_ARCHIVE"
    KERNEL_EXTRA_ARCHIVES="$KERNEL_EXTRA_ARCHIVES -Wl,-force_load,$UFS_ARCHIVE"

That name belongs to the sheng component (build-arm-driver.py names the
archive after the component id).  This board's driver is the NioUfs port, so
build-arm-driver.py produces build/nio-ufs/libNioUfs.a and the link would
stop with "build/sheng-ufs/libShengUfs.a not found".

This recipe copies the archive to the path the link looks for.  It runs after
component:NioUfs in [kernel] archives, so the source is already built.  The
copy is a real copy, not a link: the build tree is assembled by symlinking
module directories, and a symlink inside it would not survive being read
from another working directory.
"""
import hashlib
import shutil
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / 'build' / 'nio-ufs' / 'libNioUfs.a'
TARGET = ROOT / 'build' / 'sheng-ufs' / 'libShengUfs.a'


def main():
    if not SOURCE.is_file():
        raise SystemExit('the board UFS archive is missing: %s' % SOURCE)
    TARGET.parent.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(SOURCE, TARGET)
    digest = hashlib.sha256(TARGET.read_bytes()).hexdigest()
    print('nio-ufs: %s -> %s (%d bytes, sha256 %s)'
          % (SOURCE.relative_to(ROOT), TARGET.relative_to(ROOT), TARGET.stat().st_size, digest))


if __name__ == '__main__':
    main()
