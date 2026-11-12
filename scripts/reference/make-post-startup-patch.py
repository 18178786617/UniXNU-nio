#!/usr/bin/env python
"""Mark the calls between the last startup phase and bsd_init.

The kernel finishes the startup phase and does not reach bsd_init: the
last startup landmark is on the screen and bsd_init's own first landmark
is not.  The stretch between the two is a list of calls in
kernel_bootstrap_thread(), and this patch puts a number on each of them.

The numbers are counted from 9000 in the order the source has the calls
in:

    9000 commpage             9006 kext_bootstrap_removed
    9001 commpage_text        9007 machine_lockdown
    9002 mac_policy           9008 pe_lockdown_iokit
    9003 dtrace_early         9009 vm_restrictions
    9004 trust_cache          9010 kperf
    9005 static_trust_cache   9011 bsd_init

They start at 9000 so they cannot be mistaken for a startup entry's
number, which is counted from 0.

One format string for all of them: the compiler merges the identical
literals, so a marker costs the instructions and nothing else.  The
console blob lives in the tail padding of __TEXT_EXEC, and the space
there is what every one of these markers has to fit into -- run-158's
kernel could not be turned into an image at all because a patch took
224 bytes of it.

The markers are placed after the call they name, so the number on the
screen is the step that just finished.  The last number is the step the
boot reached.
"""

import pathlib
import shutil
import subprocess
import sys
import tempfile

# The calls, in the order the source has them.
STEPS = [
    ('vm_commpage_init();', 'commpage'),
    ('vm_commpage_text_init();', 'commpage_text'),
    ('mac_policy_initmach();', 'mac_policy'),
    ('dtrace_early_init();', 'dtrace_early'),
    ('trust_cache_runtime_init();', 'trust_cache'),
    ('load_static_trust_cache();', 'static_trust_cache'),
    ('OSKextRemoveKextBootstrap();', 'kext_bootstrap_removed'),
    ('machine_lockdown();', 'machine_lockdown'),
    ('PE_lockdown_iokit();', 'pe_lockdown_iokit'),
    ('vm_set_restrictions(machine_info.max_cpus);', 'vm_restrictions'),
    ('kperf_init_early();', 'kperf'),
    ('bsd_init();', 'bsd_init'),
]

REL = 'osfmk/kern/startup.c'
FIRST_NUMBER = 9000

# The tree the patch is made against: the series applies
# native-trust-cache-runtime.patch before this one, and that patch
# changes the same function.
PRE = ('native-trust-cache-runtime.patch',)


def patch_tree(tree):
    """Put the markers into the tree, after each call."""
    path = tree / REL
    text = path.read_text()
    number = FIRST_NUMBER
    for call, name in STEPS:
        needle = '\t' + call + '\n'
        if needle not in text:
            raise SystemExit('call not found: %s' % call)
        marker = '\tprintf("nio: %%u\\n", %d);\n' % number
        text = text.replace(needle, needle + marker, 1)
        number += 1
    with open(path, 'w', newline='') as fh:
        fh.write(text)


def main():
    if len(sys.argv) < 3:
        raise SystemExit('usage: make-post-startup-patch.py <tree> <out.patch>')
    tree = pathlib.Path(sys.argv[1]).resolve()
    out = pathlib.Path(sys.argv[2]).resolve()
    patches = pathlib.Path(__file__).resolve().parent.parent / 'device' / \
        'UniXNU-nio' / 'patches' / 'xnu-8796'

    work = pathlib.Path(tempfile.mkdtemp(prefix='nio-post-'))
    try:
        copy = work / 'tree'
        shutil.copytree(tree, copy, symlinks=True)

        subprocess.run(['git', 'init', '-q'], cwd=copy, capture_output=True)

        # The patch is made against the tree the earlier patches leave
        # behind, so those are applied first and committed: the diff that
        # follows then carries only this patch's changes.
        for name in PRE:
            p = patches / name
            if not p.is_file():
                continue
            r = subprocess.run(['patch', '-p1', '--no-backup-if-mismatch',
                                '--forward', '-i', str(p)],
                               cwd=copy, capture_output=True, text=True)
            if r.returncode != 0:
                print(r.stdout + r.stderr, file=sys.stderr)
                raise SystemExit('%s did not apply' % name)
            subprocess.run(['git', 'add', '-A'], cwd=copy, capture_output=True)
            subprocess.run(['git', 'commit', '-q', '-m', name, '--allow-empty'],
                           cwd=copy, capture_output=True)

        patch_tree(copy)

        diff = subprocess.run(['git', 'diff', '--no-color', '--no-ext-diff', '-U3'],
                              cwd=copy, capture_output=True)
        raw = diff.stdout
        if not raw.strip():
            raise SystemExit('git diff produced nothing')
        text = raw.decode('utf-8', 'surrogateescape')
        header = (
            'Mark the calls between the last startup phase and bsd_init\n'
            '\n'
            'The kernel finishes the startup phase and does not reach\n'
            'bsd_init: the last startup landmark is on the screen and\n'
            "bsd_init's own first landmark is not.  The stretch between the\n"
            'two is a list of calls in kernel_bootstrap_thread(), and this\n'
            'patch puts a number on each of them.\n'
            '\n'
            'The numbers are counted from 9000 in the order the source has\n'
            'the calls in:\n'
            '\n'
            '    9000 commpage             9006 kext_bootstrap_removed\n'
            '    9001 commpage_text        9007 machine_lockdown\n'
            '    9002 mac_policy           9008 pe_lockdown_iokit\n'
            '    9003 dtrace_early         9009 vm_restrictions\n'
            '    9004 trust_cache          9010 kperf\n'
            '    9005 static_trust_cache   9011 bsd_init\n'
            '\n'
            'One format string for all of them: the compiler merges the\n'
            'identical literals, so a marker costs the instructions and\n'
            'nothing else.  The console blob lives in the tail padding of\n'
            '__TEXT_EXEC and the space there is what every marker has to\n'
            'fit into.\n'
            '\n'
            '---\n'
        )
        out.write_bytes((header + text).encode('utf-8', 'surrogateescape'))
        print('%s: %d bytes' % (out, out.stat().st_size))
    finally:
        shutil.rmtree(work, ignore_errors=True)


if __name__ == '__main__':
    main()
