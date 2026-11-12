#!/usr/bin/env python
"""Mark the early boot functions, so the panel says where the boot stopped.

The kernel reaches the early boot phase and does not get past it: the
last of the phase's own prints is on the screen and bsd_init's are not.
The phase is a list of startup entries, and this patch puts a number on
each of the functions in it:

    01 source_pthread_bootstrap
    02 telemetry_init
    03 set_awl_scratch_exists_flag_and_subscribe_for_pm
    04 iotrace_init
    05 pgz_init
    06 kmem_crypto_init
    07 vm_pageout_create_gc_thread
    08 vm_deferred_reclamation_init
    09 personas_bootstrap
    10 cs_text_fixup_init
    11 kcov_init

The numbers are two digits because the panel is read from a photograph of
a phone that is held by hand: a line of fifteen characters is legible
where a line of forty is not.

They are also two digits because the space is what they are competing
for.  The console blob lives in the tail padding of __TEXT_EXEC and
needs 9518 bytes of it; a kernel with nothing in it has 9648, so every
marker has to fit in 130 bytes.  One format string for all of them --
the compiler merges the identical literals -- makes a marker cost the
instructions and nothing else, and a two digit number is one instruction
shorter than a four digit one.
"""

import pathlib
import shutil
import subprocess
import sys
import tempfile

# (relative path, function, number)
TARGETS = [
    ('bsd/kern/source_pthread_bootstrap.c', 'source_pthread_bootstrap', 1),
    ('osfmk/kern/core_analytics.c', 'telemetry_init', 2),
    ('osfmk/kern/debug.c', 'set_awl_scratch_exists_flag_and_subscribe_for_pm', 3),
    ('osfmk/kern/iotrace.c', 'iotrace_init', 4),
    ('osfmk/kern/zalloc.c', 'pgz_init', 5),
    ('osfmk/vm/vm_kern.c', 'kmem_crypto_init', 6),
]

# The header that declares printf.  A file that does not include it cannot
# print: the libpthread archive compiles source_pthread_bootstrap.c on its
# own, and that compilation does not see the header.
PRINTF_HEADER = '#include <kern/misc_protos.h>'


def mark(tree):
    """Put the markers into the tree."""
    for relpath, func, number in TARGETS:
        path = tree / relpath
        if not path.is_file():
            raise SystemExit('not found: %s' % relpath)
        text = path.read_text()
        lines = text.splitlines(keepends=True)

        # the definition, not the comment that documents it
        start = None
        for i, line in enumerate(lines):
            stripped = line.strip()
            if stripped.startswith('*') or stripped.startswith('/*'):
                continue
            if line.startswith(func + '('):
                start = i
                break
        if start is None:
            raise SystemExit('%s not found in %s' % (func, relpath))

        # the body opens on the next '{' after the signature
        brace = None
        for j in range(start, len(lines)):
            if lines[j].rstrip() == '{':
                brace = j
                break
        if brace is None:
            raise SystemExit('no body for %s in %s' % (func, relpath))

        lines.insert(brace + 1, '\tprintf("nio: %%u\\n", %d);\n' % number)

        # the file has to know printf
        if PRINTF_HEADER not in text:
            for k, line in enumerate(lines):
                if line.startswith('#include'):
                    lines.insert(k, PRINTF_HEADER + '\n')
                    break
            else:
                raise SystemExit('no include to anchor %s in %s'
                                 % (PRINTF_HEADER, relpath))

        with open(path, 'w', newline='') as fh:
            fh.write(''.join(lines))


def main():
    if len(sys.argv) < 3:
        raise SystemExit('usage: make-early-boot-patch.py <tree> <out.patch>')
    tree = pathlib.Path(sys.argv[1]).resolve()
    out = pathlib.Path(sys.argv[2]).resolve()

    work = pathlib.Path(tempfile.mkdtemp(prefix='nio-early-'))
    try:
        copy = work / 'tree'
        shutil.copytree(tree, copy, symlinks=True)
        subprocess.run(['git', 'init', '-q'], cwd=copy, capture_output=True)

        # The tree the patch is made against has to be the tree the build
        # sees: source_pthread_bootstrap.c is created by a patch of the
        # series, and the patch below edits it.
        patches = pathlib.Path(__file__).resolve().parent.parent / 'device' / \
            'UniXNU-nio' / 'patches' / 'xnu-8796'
        for name in ('source-pthread-bootstrap.patch',):
            p = patches / name
            if not p.is_file():
                continue
            # The file this patch creates is removed first: the tree this
            # runs on may already carry an older version of it, and the
            # patch has to be made against the tree the build sees.
            created = copy / 'bsd' / 'kern' / 'source_pthread_bootstrap.c'
            if created.is_file():
                created.unlink()
            r = subprocess.run(['patch', '-p1', '--no-backup-if-mismatch',
                                '--forward', '-i', str(p)],
                               cwd=copy, capture_output=True, text=True)
            if r.returncode != 0:
                print(r.stdout + r.stderr, file=sys.stderr)
                raise SystemExit('%s did not apply' % name)
            subprocess.run(['git', 'add', '-A'], cwd=copy, capture_output=True)
            subprocess.run(['git', 'commit', '-q', '-m', name, '--allow-empty'],
                           cwd=copy, capture_output=True)

        mark(copy)

        diff = subprocess.run(['git', 'diff', '--no-color', '--no-ext-diff', '-U3'],
                              cwd=copy, capture_output=True)
        raw = diff.stdout
        if not raw.strip():
            raise SystemExit('git diff produced nothing')
        text = raw.decode('utf-8', 'surrogateescape')
        header = (
            'Mark the early boot functions\n'
            '\n'
            'The kernel reaches the early boot phase and does not get past it,\n'
            'and the last of the phase\'s own prints is on the screen while\n'
            "bsd_init's are not.  The phase is a list of startup entries, and\n"
            'this patch puts a number on each of the functions in it:\n'
            '\n'
            '    01 source_pthread_bootstrap      07 vm_pageout_create_gc_thread\n'
            '    02 telemetry_init               08 vm_deferred_reclamation_init\n'
            '    03 set_awl_scratch...           09 personas_bootstrap\n'
            '    04 iotrace_init                 10 cs_text_fixup_init\n'
            '    05 pgz_init                     11 kcov_init\n'
            '    06 kmem_crypto_init\n'
            '\n'
            'The numbers are two digits because the panel is read from a\n'
            'photograph of a phone that is held by hand.  They are also two\n'
            'digits because the space is what they compete for: the console\n'
            'blob needs 9518 bytes of the tail padding of __TEXT_EXEC and a\n'
            'kernel with nothing in it has 9648, so every marker has to fit\n'
            'in 130 bytes.\n'
            '\n'
            '---\n'
        )
        out.write_bytes((header + text).encode('utf-8', 'surrogateescape'))
        print('%s: %d bytes' % (out, out.stat().st_size))
    finally:
        shutil.rmtree(work, ignore_errors=True)


if __name__ == '__main__':
    main()
