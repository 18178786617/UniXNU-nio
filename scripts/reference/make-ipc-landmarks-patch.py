#!/usr/bin/env python3
"""Generate nio-ipc-startup-landmarks.patch from the real source tree.

The landmarks are the MACH_IPC phase's startup functions.  The patch is
generated rather than hand-written because the hunks need exact line counts:
a hand-written hunk with a wrong count is rejected by git apply before it
ever reaches the compiler, and the CI would fail on the patch instead of on
the thing the patch is about.

The generator edits a copy of the tree and lets git diff write the patch, so
every hunk count is right by construction.

Usage:
    python3 tools/make-ipc-landmarks-patch.py <xnu-source-tree> <out.patch>
"""
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

# (relative path, marker text) -- the marker is printed right *before* the
# line the anchor names.  The order is the order the markers go into the
# file, so the printed sequence follows the execution order.
#
# The anchor must be a line that stands on its own: inserting a statement
# between the two lines of a multi-line call splits the call's arguments and
# the file no longer compiles.
EDITS = [
    # osfmk/ipc/ipc_init.c -- the phase's last startup function
    ('osfmk/ipc/ipc_init.c', [
        ('\t/* create special spaces */\n',
         '\tprintf("nio: ipc_init enter\\n");\n'),
        ('\t/* initialize modules with hidden data structures */\n',
         '\tprintf("nio: ipc_init spaces done\\n");\n'),
        ('\tipc_kernel_map = kmem_suballoc(kernel_map, &ipc_kernel_range.min_address,\n',
         '\tprintf("nio: ipc_init before kernel_map\\n");\n'),
        ('\tipc_kernel_copy_map = kmem_suballoc(kernel_map, &ipc_kernel_copy_range.min_address,\n',
         '\tprintf("nio: ipc_init before copy_map\\n");\n'),
        ('\tipc_host_init();\n',
         '\tprintf("nio: ipc_init before ipc_host_init\\n");\n'),
        ('\tux_handler_init();\n',
         '\tprintf("nio: ipc_init after ux_handler_init\\n");\n', 'after'),
    ]),
]


def apply_edits(tree, edits):
    """Insert the marker lines next to the block the anchor names.

    The anchor has to be a block that stands on its own.  Inserting between
    the two lines of a multi-line call splits the call's arguments, and the
    file no longer compiles -- which is exactly what happened the first time
    this patch was made.

    Each item is (anchor, insert) or (anchor, insert, 'after').  The marker
    goes before the anchor by default, so the printed order is the order the
    code runs in; 'after' puts it behind the anchor, which is what a marker
    that reports "this call is done" needs.
    """
    touched = []
    for relpath, items in edits:
        path = tree / relpath
        text = path.read_text()
        original = text
        for item in items:
            anchor, insert = item[0], item[1]
            where = item[2] if len(item) > 2 else 'before'
            if insert is None:
                continue
            if anchor not in text:
                raise SystemExit('anchor not found in %s: %r' % (relpath, anchor[:60]))
            if where == 'after':
                text = text.replace(anchor, anchor + insert, 1)
            else:
                text = text.replace(anchor, insert + anchor, 1)
        if text != original:
            # newline='' keeps the tree's LF endings; the default would write
            # CRLF and turn every line of the file into a diff.
            with open(path, 'w', newline='') as fh:
                fh.write(text)
            touched.append(relpath)
    return touched


def wrap_functions(tree, specs):
    """Print a marker at the top and at the bottom of each function body.

    A spec is (relpath, func, enter_text, done_text) or
    (relpath, func, None, done_text) when the enter marker is already in
    place and only the closing one is missing.
    """
    for relpath, func, enter_text, done_text in specs:
        path = tree / relpath
        lines = path.read_text().splitlines(keepends=True)

        start = None
        for i, line in enumerate(lines):
            stripped = line.strip()
            # the definition, not the comment that documents it
            if stripped.startswith('*') or stripped.startswith('/*'):
                continue
            if line.startswith(func + '('):
                # the body opens on the next '{' after the signature
                for j in range(i, len(lines)):
                    if lines[j].rstrip() == '{':
                        start = j
                        break
                break
        if start is None:
            raise SystemExit('function %s not found in %s' % (func, relpath))

        depth = 0
        end = None
        for i in range(start, len(lines)):
            depth += lines[i].count('{') - lines[i].count('}')
            if depth == 0 and i > start:
                end = i
                break
        if end is None:
            raise SystemExit('no end of body for %s in %s' % (func, relpath))

        # the done marker goes right before the closing brace, so it is
        # inside the body; inserting it after the brace would put a
        # statement where the next function starts
        lines.insert(end, '\tprintf("%s\\n");\n' % done_text)
        if enter_text is not None:
            # the enter marker goes right after the opening brace
            lines.insert(start + 1, '\tprintf("%s\\n");\n' % enter_text)
        with open(path, 'w', newline='') as fh:
            fh.write(''.join(lines))


def add_console_include(tree, files):
    """Make sure the files that print have printf's declaration.

    osfmk/kern/misc_protos.h declares printf.  A file that does not include
    it (directly or through another header) calls printf without a
    declaration, which is an error in C99 and later, and the build stops
    with a message that does not point at the landmark that caused it.
    """
    for relpath in files:
        path = tree / relpath
        lines = path.read_text().splitlines(keepends=True)
        if any('misc_protos.h' in ln for ln in lines):
            continue
        # after the last #include in the first block of includes
        last = None
        for i, line in enumerate(lines[:120]):
            if line.startswith('#include'):
                last = i
        if last is None:
            raise SystemExit('no include found in %s' % relpath)
        lines.insert(last + 1, '#include <kern/misc_protos.h>\n')
        with open(path, 'w', newline='') as fh:
            fh.write(''.join(lines))


def check_syntax(tree, files, clang):
    """Compile every patched file on its own, to catch a broken edit.

    The full kernel build takes half an hour on a CI runner, and a landmark
    patch that splits a call's arguments costs that half hour before anyone
    learns why.  A single file compile is a second, and it catches the same
    class of mistake.
    """
    if not clang:
        print('no clang found, skipping the syntax check')
        return True
    ok = True
    for relpath in files:
        path = tree / relpath
        cmd = [clang, '-fsyntax-only', '-x', 'c',
               '-I', str(tree), '-I', str(tree / 'osfmk'),
               '-I', str(tree / 'bsd'), '-I', str(tree / 'EXTERNAL_HEADERS'),
               '-D__KERNEL__', '-DKERNEL', '-D__APPLE__',
               str(path)]
        r = subprocess.run(cmd, capture_output=True, text=True)
        if r.returncode != 0:
            # the kernel's own headers need a lot of setup, so a file that
            # fails only because of a missing include is not a broken edit;
            # a file that fails with a syntax error is.
            err = r.stderr
            if 'expected' in err or 'error:' in err and 'undeclared' in err:
                print('syntax error in %s:' % relpath)
                for line in err.splitlines():
                    if 'error:' in line:
                        print('   ', line.strip())
                ok = False
    return ok


def main():
    if len(sys.argv) < 3:
        print(__doc__)
        return 1
    tree = Path(sys.argv[1]).resolve()
    out = Path(sys.argv[2]).resolve()
    if not tree.is_dir():
        raise SystemExit('no source tree at %s' % tree)

    work = Path(tempfile.mkdtemp(prefix='nio-landmark-'))
    tree_copy = work / 'tree'
    shutil.copytree(tree, tree_copy, symlinks=True)

    # 0. the copy becomes a git repo holding the *unmodified* tree, so the
    # diff at the end shows exactly what the landmarks changed
    subprocess.run(['git', 'init', '-q'], cwd=tree_copy, capture_output=True)
    subprocess.run(['git', 'add', '-A'], cwd=tree_copy, capture_output=True)
    subprocess.run(['git', 'commit', '-q', '-m', 'base', '--allow-empty'],
                   cwd=tree_copy, capture_output=True)

    # 1. the phase's last startup function, with the fine grained landmarks
    apply_edits(tree_copy, EDITS)

    # 2. the rest of the phase's startup functions, enter/done only
    wrap_functions(tree_copy, [
        # ipc_init's enter marker comes from EDITS, so only the closing one
        # is added here
        ('osfmk/ipc/ipc_init.c', 'ipc_init', None, 'nio: ipc_init done'),
        ('osfmk/ipc/ipc_importance.c', 'ipc_importance_init',
         'nio: ipc_importance_init enter', 'nio: ipc_importance_init done'),
        ('osfmk/bank/bank.c', 'bank_init',
         'nio: bank_init enter', 'nio: bank_init done'),
        ('osfmk/ipc/ipc_voucher.c', 'ipc_voucher_init',
         'nio: ipc_voucher_init enter', 'nio: ipc_voucher_init done'),
        ('osfmk/ipc/ipc_voucher.c', 'user_data_attr_manager_init',
         'nio: user_data_attr_manager_init enter',
         'nio: user_data_attr_manager_init done'),
        ('osfmk/kern/ipc_kobject.c', 'mig_init',
         'nio: mig_init enter', 'nio: mig_init done'),
        ('osfmk/kern/waitq.c', 'waitq_bootstrap',
         'nio: waitq_bootstrap enter', 'nio: waitq_bootstrap done'),
        ('osfmk/voucher/ipc_pthread_priority.c', 'ipc_pthread_priority_init',
         'nio: ipc_pthread_priority_init enter',
         'nio: ipc_pthread_priority_init done'),
    ])

    # 3. the files that print need printf's declaration.  Four of the eight
    # do not pull in a header that declares it, and a call without a
    # declaration is an error in C99 and later, so the header is added.
    add_console_include(tree_copy, [
        'osfmk/ipc/ipc_voucher.c',
        'osfmk/kern/waitq.c',
        'osfmk/bank/bank.c',
        'osfmk/voucher/ipc_pthread_priority.c',
    ])

    # 4. let git diff write the patch, so every hunk count is right.
    # The diff runs from inside the copy, which is a git repo holding the
    # unmodified tree: the paths in the patch are then the repo-relative ones
    # the build expects, and no path rewriting is needed.
    diff = subprocess.run(
        ['git', 'diff', '--no-color', '--no-ext-diff', '-U3'],
        cwd=tree_copy, capture_output=True)
    raw = diff.stdout
    if not raw.strip():
        raise SystemExit('git diff produced nothing')
    # git quotes paths with non-ASCII bytes; the diff is still valid, so the
    # bytes are passed through untouched.
    text = raw.decode('utf-8', 'surrogateescape')

    out.write_bytes(text.encode('utf-8', 'surrogateescape'))
    shutil.rmtree(work, ignore_errors=True)
    print('wrote %s (%d bytes)' % (out, len(text)))
    return 0


if __name__ == '__main__':
    sys.exit(main())
