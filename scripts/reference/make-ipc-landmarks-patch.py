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

# (relative path, marker text) -- the marker is printed right before the
# line the anchor names.  The order is the order the markers go into the
# file, so the printed sequence follows the execution order.
EDITS = [
    # osfmk/ipc/ipc_init.c -- the phase's last startup function
    ('osfmk/ipc/ipc_init.c', [
        ('\t/* create special spaces */\n',
         '\tprintf("nio: ipc_init enter\\n");\n'),
        ('\tkr = ipc_space_create_special(&ipc_space_kernel);\n'
         '\tassert(kr == KERN_SUCCESS);\n',
         '\tprintf("nio: ipc_init kernel space done\\n");\n'),
        ('\tkr = ipc_space_create_special(&ipc_space_reply);\n'
         '\tassert(kr == KERN_SUCCESS);\n',
         '\tprintf("nio: ipc_init reply space done\\n");\n'),
        ('\tipc_kernel_map = kmem_suballoc(kernel_map, &ipc_kernel_range.min_address,\n',
         '\tprintf("nio: ipc_init before kernel_map\\n");\n'),
        ('\tipc_kernel_copy_map = kmem_suballoc(kernel_map, &ipc_kernel_copy_range.min_address,\n',
         '\tprintf("nio: ipc_init before copy_map\\n");\n'),
        ('\tipc_host_init();\n',
         '\tprintf("nio: ipc_init before ipc_host_init\\n");\n'),
        ('\tux_handler_init();\n',
         '\tprintf("nio: ipc_init after ux_handler_init\\n");\n'),
    ]),
    ('osfmk/ipc/ipc_importance.c', [
        ('\tipc_register_well_known_mach_voucher_attr_manager(&ipc_importance_manager,\n',
         '\tprintf("nio: ipc_importance_init enter\\n");\n'),
    ]),
    ('osfmk/bank/bank.c', [
        ('\t__startup_data static void\n', None),   # placeholder, replaced below
    ]),
]


def simple_markers(relpath, func, enter_text, done_text):
    """Print enter/done around the body of `func` in `relpath`."""
    return (relpath, [
        ('__BODY__' + func, enter_text),
        ('__END__' + func, done_text),
    ])


def apply_edits(tree, edits):
    """Insert the marker lines.  Returns the list of files that changed."""
    touched = []
    for relpath, items in edits:
        path = tree / relpath
        text = path.read_text()
        original = text
        for anchor, insert in items:
            if insert is None:
                continue
            if anchor not in text:
                raise SystemExit('anchor not found in %s: %r' % (relpath, anchor[:60]))
            # insert *after* the anchor line
            text = text.replace(anchor, anchor + insert, 1)
        if text != original:
            # newline='' keeps the tree's LF endings; the default would write
            # CRLF and turn every line of the file into a diff.
            with open(path, 'w', newline='') as fh:
                fh.write(text)
            touched.append(relpath)
    return touched


def wrap_functions(tree, specs):
    """Print a marker at the top and at the bottom of each function body."""
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

        # the enter marker goes right after the opening brace
        lines.insert(start + 1, '\tprintf("%s\\n");\n' % enter_text)
        # the done marker goes right before the closing brace
        lines.insert(end + 1, '\tprintf("%s\\n");\n' % done_text)
        with open(path, 'w', newline='') as fh:
            fh.write(''.join(lines))


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

    # 3. let git diff write the patch, so every hunk count is right.
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
