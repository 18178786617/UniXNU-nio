#!/usr/bin/env python3
"""Generate nio-early-boot-landmarks.patch from the real source tree.

The startup phase finishes and the kernel does not reach bsd_init.  The
last startup landmark on the screen names the phase and the entry, and the
entry's number says which function it is -- but the number is four digits
and it is read off a photograph of a phone held by hand, so it is the
hardest thing on the screen to read.

Each of the twelve EARLY_BOOT functions prints a two digit number of its
own instead, so the last one on the screen is a number of two digits and
nothing else:

    01  source_pthread_bootstrap
    02  telemetry_init
    03  set_awl_scratch_exists_flag_and_subscribe_for_pm
    04  iotrace_init
    05  pgz_init
    06  kmem_crypto_init
    07  vm_pageout_create_gc_thread
    08  vm_deferred_reclamation_init
    09  personas_bootstrap
    10  kcov_init

The numbers are the order the source has the functions in, and the numbers
are in the patch's comment, so the screen and the source agree.

One format string for all of them: the compiler merges the identical
literals, so a marker costs the instructions and nothing else.  The console
blob lives in the tail padding of __TEXT_EXEC and the space there is what
every one of these markers has to fit into.

    python3 tools/make-early-boot-patch.py <xnu-source-tree> <out.patch>
"""
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

# (file, function, the line its body opens with, number)
TARGETS = [
    ('bsd/kern/source_pthread_bootstrap.c', 'source_pthread_bootstrap', 1),
    ('osfmk/kern/core_analytics.c', 'telemetry_init', 2),
    ('osfmk/kern/debug.c',
     'set_awl_scratch_exists_flag_and_subscribe_for_pm', 3),
    ('osfmk/kern/iotrace.c', 'iotrace_init', 4),
    ('osfmk/kern/zalloc.c', 'pgz_init', 5),
    ('osfmk/vm/vm_kern.c', 'kmem_crypto_init', 6),
    ('osfmk/vm/vm_pageout.c', 'vm_pageout_create_gc_thread', 7),
    ('osfmk/vm/vm_reclaim.c', 'vm_deferred_reclamation_init', 8),
    ('bsd/kern/kern_persona.c', 'personas_bootstrap', 9),
    ('san/coverage/kcov.c', 'kcov_init', 10),
]

MARK = '\tprintf("nio: %%02u\\n", %d);\n'


def body_open(lines, func):
    """The index of the line that opens the body of `func`."""
    for i, line in enumerate(lines):
        stripped = line.strip()
        if stripped.startswith('*') or stripped.startswith('/*'):
            continue
        if stripped.startswith(func + '('):
            for j in range(i, len(lines)):
                if lines[j].rstrip() == '{':
                    return j
            raise SystemExit('no body brace for %s' % func)
    raise SystemExit('function %s not found' % func)


def main():
    if len(sys.argv) < 3:
        print(__doc__)
        return 1
    tree = Path(sys.argv[1]).resolve()
    out = Path(sys.argv[2]).resolve()
    if not tree.is_dir():
        raise SystemExit('no source tree at %s' % tree)

    work = Path(tempfile.mkdtemp(prefix='nio-early-boot-'))
    copy = work / 'tree'
    shutil.copytree(tree, copy, symlinks=True)

    subprocess.run(['git', 'init', '-q'], cwd=copy, capture_output=True)
    subprocess.run(['git', 'add', '-A'], cwd=copy, capture_output=True)
    subprocess.run(['git', 'commit', '-q', '-m', 'base', '--allow-empty'],
                   cwd=copy, capture_output=True)

    # source-pthread-bootstrap.patch creates bsd/kern/source_pthread_bootstrap.c,
    # and it is applied before this one, so it is applied here first: the
    # tree this works on is the tree the build sees.
    patches = Path(__file__).resolve().parent.parent / 'device' / \
        'UniXNU-nio' / 'patches' / 'xnu-8796'
    for name in ('source-pthread-bootstrap.patch',):
        p = patches / name
        if not p.is_file():
            continue
        subprocess.run(['patch', '-p1', '--no-backup-if-mismatch',
                        '--forward', '-i', str(p)],
                       cwd=copy, capture_output=True)
        subprocess.run(['git', 'add', '-A'], cwd=copy, capture_output=True)
        subprocess.run(['git', 'commit', '-q', '-m', name, '--allow-empty'],
                       cwd=copy, capture_output=True)

    for relpath, func, number in TARGETS:
        path = copy / relpath
        if not path.is_file():
            raise SystemExit('no such file: %s' % relpath)
        lines = path.read_text().splitlines(keepends=True)
        at = body_open(lines, func)
        lines.insert(at + 1, MARK % number)
        with open(path, 'w', newline='') as fh:
            fh.write(''.join(lines))

    diff = subprocess.run(
        ['git', 'diff', '--no-color', '--no-ext-diff', '-U3'],
        cwd=copy, capture_output=True)
    raw = diff.stdout
    if not raw.strip():
        raise SystemExit('git diff produced nothing')
    header = (
        "Name the EARLY_BOOT functions by number\n"
        "\n"
        "The startup phase finishes and the kernel does not reach bsd_init.\n"
        "The last startup landmark on the screen names the phase and the\n"
        "entry, and the entry's number says which function it is -- but the\n"
        "number is four digits and it is read off a photograph of a phone\n"
        "held by hand, so it is the hardest thing on the screen to read.\n"
        "\n"
        "Each of the EARLY_BOOT functions prints a two digit number of its\n"
        "own instead, so the last one on the screen is two digits and nothing\n"
        "else:\n"
        "\n"
        "    01  source_pthread_bootstrap\n"
        "    02  telemetry_init\n"
        "    03  set_awl_scratch_exists_flag_and_subscribe_for_pm\n"
        "    04  iotrace_init\n"
        "    05  pgz_init\n"
        "    06  kmem_crypto_init\n"
        "    07  vm_pageout_create_gc_thread\n"
        "    08  vm_deferred_reclamation_init\n"
        "    09  personas_bootstrap\n"
        "    10  kcov_init\n"
        "\n"
        "One format string for all of them: the compiler merges the identical\n"
        "literals, so a marker costs the instructions and nothing else.  The\n"
        "console blob lives in the tail padding of __TEXT_EXEC and the space\n"
        "there is what every one of these markers has to fit into.\n"
        "\n"
        "---\n"
    )
    out.write_bytes(header.encode() + raw)
    shutil.rmtree(work, ignore_errors=True)
    print('wrote %s (%d bytes)' % (out, len(raw)))
    return 0


if __name__ == '__main__':
    sys.exit(main())
