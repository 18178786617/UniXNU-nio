#!/usr/bin/env python3
"""Generate nio-post-startup-landmarks.patch from the real source tree.

The startup phase finishes, and the kernel does not reach bsd_init.  The
run-160 screen shows the last startup landmark and then nothing, and
bsd_init's own first landmark never prints, so the stop is in the stretch
between the two.

That stretch is a list of calls in kernel_startup_initialize_upto(), each
of them announced by kernel_bootstrap_log() with the name of the step.  A
marker after each of them says which one was the last to run.

The markers are short, for the same reason the startup ones are: the panel
is read from a photograph of a phone held by hand.

    python3 tools/make-post-startup-patch.py <xnu-source-tree> <out.patch>
"""
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

REL = 'osfmk/kern/startup.c'

# The calls between the last startup phase and bsd_init(), in the order the
# source has them.  Each one gets a marker after it.  The two that sit
# behind a #if are marked on the #endif, because their own call is not
# there on every build.
STEPS = [
    ('vm_commpage_init();', 'commpage'),
    ('vm_commpage_text_init();', 'commpage_text'),
    ('trust_cache_runtime_init();', 'trust_cache'),
    ('load_static_trust_cache();', 'static_trust_cache'),
    ('OSKextRemoveKextBootstrap();', 'kext_bootstrap_removed'),
    ('machine_lockdown();', 'machine_lockdown'),
    ('PE_lockdown_iokit();', 'pe_lockdown_iokit'),
    ('vm_set_restrictions(machine_info.max_cpus);', 'vm_restrictions'),
    ('kperf_init_early();', 'kperf'),
    ('bsd_init();', 'bsd_init'),
]

# (the text that ends the block, the marker's name)
BLOCKS = [
    ('\tsdt_early_init();\n#endif\n', 'dtrace_early'),
    ('\tvnguard_policy_init();\n#endif\n#endif\n', 'mac_policy'),
]


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
    # One format string for every marker: the compiler merges the identical
    # literals, so each marker costs the instructions and nothing else.  The
    # console blob lives in the tail padding of __TEXT_EXEC and the space
    # there is what this whole thing has to fit into.
    #
    # The numbers are the step's place in the list, counted from 9000 so
    # that they cannot be mistaken for a startup entry's number, which is
    # counted from 0 and doubled.
    number = 9000
    for call, name in STEPS:
        needle = '\t' + call + '\n'
        if needle not in text:
            raise SystemExit('call not found: %s' % call)
        marker = '\tprintf("nio: %%u\\n", %d);\n' % number
        text = text.replace(needle, needle + marker, 1)
        number += 1
    for block_end, name in BLOCKS:
        if block_end not in text:
            raise SystemExit('block end not found: %r' % block_end)
        marker = '\tprintf("nio: %%u\\n", %d);\n' % number
        text = text.replace(block_end, block_end + marker, 1)
        number += 1
    with open(path, 'w', newline='') as fh:
        fh.write(text)

    diff = subprocess.run(
        ['git', 'diff', '--no-color', '--no-ext-diff', '-U3'],
        cwd=copy, capture_output=True)
    raw = diff.stdout
    if not raw.strip():
        raise SystemExit('git diff produced nothing')
    header = (
        "Mark the calls between the last startup phase and bsd_init\n"
        "\n"
        "The startup phase finishes and the kernel does not reach bsd_init:\n"
        "the last startup landmark is on the screen and bsd_init's own first\n"
        "landmark is not.  The stretch between them is a list of calls, and\n"
        "each of them is announced by kernel_bootstrap_log() with the name of\n"
        "the step, so the screen says which of them ran last.\n"
        "\n"
        "The markers are numbers counted from 9000, one per step in the order\n"
        "the source has them:\n"
        "\n"
        "    9000 commpage              9006 kext_bootstrap_removed\n"
        "    9001 commpage_text         9007 machine_lockdown\n"
        "    9002 mac_policy            9008 pe_lockdown_iokit\n"
        "    9003 dtrace_early          9009 vm_restrictions\n"
        "    9004 trust_cache          9010 kperf\n"
        "    9005 static_trust_cache   9011 bsd_init\n"
        "\n"
        "They are numbers because the panel is read from a photograph of a\n"
        "phone that is held by hand, and a short line is legible where a long\n"
        "one is not.  The numbers start at 9000 so that they cannot be\n"
        "mistaken for a startup entry's number, which is counted from 0.\n"
        "\n"
        "---\n"
    )
    out.write_bytes(header.encode() + raw)
    shutil.rmtree(work, ignore_errors=True)
    print('wrote %s (%d bytes)' % (out, len(raw)))
    return 0


if __name__ == '__main__':
    sys.exit(main())
