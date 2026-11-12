#!/usr/bin/env python3
"""Generate nio-post-startup-landmarks.patch from the real source tree.

The startup phase finishes, and the kernel does not reach bsd_init.  The
run-160 screen shows the last startup landmark and then nothing, and
bsd_init's own first landmark never prints, so the stop is in the stretch
between the two.

That stretch is a list of calls in kernel_bootstrap_initialize_upto().
Most of them are announced by kernel_bootstrap_log() with the name of the
step, but that function only prints when STARTUP_DEBUG_VERBOSE is set, so
the screen says nothing about which of them ran last.

Two changes:

  * kernel_bootstrap_log() prints whenever the console is there, not only
    when the debug flag is set.  The names of the steps are already in the
    source; they were only being held back.
  * the steps that have no name get one.

The names are words, not numbers, because the space this has to fit into
is the tail padding of __TEXT_EXEC: the console blob needs 9518 bytes of
it and a kernel with no landmarks in it has 9712, so there is room for
about two short prints and nothing more.  Changing a condition costs
almost nothing; a print costs a string.
"""
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

REL = 'osfmk/kern/startup.c'

# The call whose own log is missing, and the name it gets.  The ones that
# already have a log need nothing.  There is room for four of them: the
# console blob needs 9518 bytes of the tail padding of __TEXT_EXEC and a
# kernel with nothing in it has 9712.
STEPS = [
    ('vm_commpage_init();', 'commpage'),
    ('kperf_init_early();', 'kperf'),
]

# The condition that keeps the names off the console.  zzz-boot-progress.patch
# adds a call to this function as well, and it is applied before this one,
# so the anchor carries that call with it.
OLD_COND = ("\tboot_progress_stage(message);\n"
            "\tif ((startup_debug & STARTUP_DEBUG_VERBOSE) &&\n"
            "\t    startup_phase >= STARTUP_SUB_KPRINTF) {\n")
NEW_COND = ("\tboot_progress_stage(message);\n"
            "\tif (startup_phase >= STARTUP_SUB_KPRINTF) {\n")


def main():
    if len(sys.argv) < 3:
        print(__doc__)
        return 1
    tree = Path(sys.argv[1]).resolve()
    out = Path(sys.argv[2]).resolve()
    if not tree.is_dir():
        raise SystemExit('no source tree at %s' % tree)

    work = Path(tempfile.mkdtemp(prefix='nio-post-startup-'))
    copy = work / 'tree'
    shutil.copytree(tree, copy, symlinks=True)

    subprocess.run(['git', 'init', '-q'], cwd=copy, capture_output=True)
    subprocess.run(['git', 'add', '-A'], cwd=copy, capture_output=True)
    subprocess.run(['git', 'commit', '-q', '-m', 'base', '--allow-empty'],
                   cwd=copy, capture_output=True)

    path = copy / REL
    text = path.read_text()

    # zzz-boot-progress.patch adds a call to the same function and is
    # applied before this one, so it is applied here first: the anchor has
    # to carry that call with it, and the tree this works on is the tree
    # the build sees.
    progress = Path(__file__).resolve().parent.parent / 'device' / \
        'UniXNU-nio' / 'patches' / 'xnu-8796' / 'zzz-boot-progress.patch'
    if progress.is_file():
        r = subprocess.run(['patch', '-p1', '--no-backup-if-mismatch',
                            '--forward', '-i', str(progress)],
                           cwd=copy, capture_output=True, text=True)
        # patch reports a non-zero exit when a hunk was already applied or
        # ignored; what matters is that the file it left behind is the one
        # the build will see, so the check is on the text, not the exit code
        text = path.read_text()
        if 'boot_progress_stage(message);' not in text:
            print(r.stdout + r.stderr, file=sys.stderr)
            raise SystemExit('zzz-boot-progress.patch did not apply')
        # the tree the build sees is the one with zzz applied, so the diff
        # is taken against that tree and carries only this patch's changes
        subprocess.run(['git', 'add', '-A'], cwd=copy, capture_output=True)
        subprocess.run(['git', 'commit', '-q', '-m', 'zzz', '--allow-empty'],
                       cwd=copy, capture_output=True)

    # The diff is taken against the tree with zzz-boot-progress applied,
    # because that is the tree the build sees when this patch is applied
    # right after it.  The commit of the unmodified tree happens after the
    # patch is applied, so the diff carries only this patch's changes.
    text = path.read_text()
    if OLD_COND not in text:
        raise SystemExit('the condition on kernel_bootstrap_log is not where '
                         'it was expected')
    text = text.replace(OLD_COND, NEW_COND, 1)

    for call, name in STEPS:
        needle = '\t' + call + '\n'
        if needle not in text:
            raise SystemExit('call not found: %s' % call)
        marker = '\tkernel_bootstrap_log("%s");\n' % name
        text = text.replace(needle, needle + marker, 1)

    with open(path, 'w', newline='') as fh:
        fh.write(text)

    diff = subprocess.run(
        ['git', 'diff', '--no-color', '--no-ext-diff', '-U3'],
        cwd=copy, capture_output=True)
    raw = diff.stdout
    if not raw.strip():
        raise SystemExit('git diff produced nothing')
    header = (
        "Name the steps between the last startup phase and bsd_init\n"
        "\n"
        "The startup phase finishes and the kernel does not reach bsd_init:\n"
        "the last startup landmark is on the screen and bsd_init's own first\n"
        "landmark is not.  The stretch between them is a list of calls in\n"
        "kernel_bootstrap_initialize_upto(), and most of them are already\n"
        "announced by kernel_bootstrap_log() with the name of the step.\n"
        "\n"
        "They are not on the screen because kernel_bootstrap_log() only prints\n"
        "when STARTUP_DEBUG_VERBOSE is set.  It prints now whenever the console\n"
        "is there, which is what the flag was standing in the way of.\n"
        "\n"
        "The steps that had no name get one, so that the last name on the\n"
        "screen is the step the boot reached.\n"
        "\n"
        "---\n"
    )
    out.write_bytes(header.encode() + raw)
    shutil.rmtree(work, ignore_errors=True)
    print('wrote %s (%d bytes)' % (out, len(raw)))
    return 0


if __name__ == '__main__':
    sys.exit(main())
