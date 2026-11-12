#!/usr/bin/env python3
"""Trace every startup function through kernel_startup_initialize_upto().

run-86 printed all eight kalloc_init landmarks, so both of the STARTUP_RANK_THIRD
functions complete and the stall has moved into a later startup function.
Instead of instrumenting them one at a time, print an enter/exit pair around
each call: the last "enter" without a matching "exit" names the function that
hangs, and its address symbolizes with tools/kernel-symbols.py.

The exit half was missing, and it is the half that decides the round: the
screen of run-154 ended with "nio: S6 r2147483647 n3924", which names the
phase and the entry but not the function, and the phase has eight of them.
With the pair, the last enter without its exit is the function.

The patch is written by this script rather than by hand because a hunk with
a wrong line count is rejected before it ever reaches the compiler.
"""
import os
import shutil
import subprocess
import sys

ROOT = r'E:\nio-unixnu-port'
SRC = os.path.join(ROOT, r'out\xnu-8796.101.5-full\xnu-xnu-8796.101.5\osfmk\kern\startup.c')
WORK = os.path.join(ROOT, r'tmp\sz3')
OUT = os.path.join(ROOT, r'device\UniXNU-nio\patches\xnu-8796\nio-startup-trace.patch')

OLD = "\t\tkernel_startup_log(cur->subsystem);\n\t\tcur->func(cur->arg);\n\t\tstartup_entry_cur = ++cur;\n"
# The marker is a number, and it is the entry's own number in the startup
# table.  The entry's number is even when the function is about to run
# and odd when it returned, so the last even number on the screen is the
# function the boot stopped in.
#
# Only the even number is printed.  The odd one costs a string and a call
# that the space cannot hold: the console blob needs 9518 bytes of the
# tail padding of __TEXT_EXEC, and a kernel with no landmarks in it has
# 9712.
#
# One format string for every marker: the compiler merges the identical
# literals, so a marker costs the instructions and nothing else.
NEW = ("\t\tkernel_startup_log(cur->subsystem);\n"
       "\t\tif (cur->subsystem >= 15) {\n"
       "\t\t\tprintf(\"nio: %u\\n\",\n"
       "\t\t\t    2 * (unsigned)(cur - startup_entries));\n"
       "\t\t}\n"
       "\t\tcur->func(cur->arg);\n"
       "\t\tstartup_entry_cur = ++cur;\n")


def main():
    if not os.path.isfile(SRC):
        sys.exit('no source at %s' % SRC)
    text = open(SRC, encoding='utf-8', errors='replace').read()
    if text.count(OLD) != 1:
        sys.exit(f'anchor count {text.count(OLD)}, expected 1')
    text = text.replace(OLD, NEW, 1)
    print('  anchored: startup invoke loop')

    if os.path.isdir(WORK):
        shutil.rmtree(WORK)
    for side in ('a', 'b'):
        d = os.path.join(WORK, side, 'osfmk', 'kern')
        os.makedirs(d)
        shutil.copyfile(SRC, os.path.join(d, 'startup.c'))
    open(os.path.join(WORK, 'b', 'osfmk', 'kern', 'startup.c'), 'w',
         encoding='utf-8', newline='\n').write(text)

    r = subprocess.run(['git', 'diff', '--no-index', '--no-color', 'a', 'b'],
                       cwd=WORK, capture_output=True, text=True)
    body = r.stdout
    if 'startup.c' not in body:
        sys.exit('git diff produced nothing')
    body = (body.replace('a/a/osfmk/', 'a/osfmk/')
                .replace('b/b/osfmk/', 'b/osfmk/'))
    header = (
        "Trace every startup function\n"
        "\n"
        "run-86 printed all eight kalloc_init landmarks, so both of the\n"
        "STARTUP_RANK_THIRD functions complete and the stall sits in a later\n"
        "startup function.  Print an enter/exit pair around each call: the last\n"
        "enter without a matching exit names the function that hangs, and its\n"
        "address symbolizes with tools/kernel-symbols.py.\n"
        "\n"
        "The exit half is what decides the round.  The screen of run-154 ended\n"
        "with \"nio: S6 r2147483647 n3924\", which names the phase and the\n"
        "entry but not the function, and the phase has eight of them.  With\n"
        "the pair, the last enter without its exit is the function that stopped.\n"
        "\n"
        "---\n"
    )
    open(OUT, 'w', encoding='utf-8', newline='\n').write(header + body)
    print(f'\nwrote {OUT} ({len(body.splitlines())} diff lines)')


if __name__ == '__main__':
    main()
