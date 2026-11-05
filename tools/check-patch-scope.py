#!/usr/bin/env python3
"""Check that a patched XNU tree has no C statements at file scope.

A hand-made rebase of a patch onto another XNU train can move an added block
out of the function it belongs to. The patch still applies cleanly -- git
matches the context lines, not the structure -- but the result is a ``for``
loop, a bare ``return;`` or a call sitting at file scope, which no C compiler
accepts. The kernel build then dies in the compile step with an error that
points at the patch, not at the rebase.

This tool reads the tree's own diff (the working tree against the tag it was
checked out from), takes the lines the patch series added, and reports any of
them that lands at file scope.

    tools/check-patch-scope.py <tree> [<tree> ...]

The tree must be a git checkout whose working tree carries the applied patches,
which is what the build's .cache/xnu-work is. The exit status is 1 when a
statement is found at file scope.
"""
import re
import subprocess
import sys
from pathlib import Path

# Keywords that can only start a statement, never a declaration.
STATEMENT_KEYWORDS = (
    'if', 'else', 'for', 'while', 'do', 'switch', 'return', 'goto',
    'break', 'continue', 'case', 'default',
)

# Names that look like a call but are attributes or statement expressions.
CALL = re.compile(r'^([A-Za-z_]\w*)\s*\(')
ATTRIBUTES = {'__attribute__', '__asm__', 'asm', '_Static_assert', 'static_assert', '__extension__'}


def is_macro(name):
    """A name in capitals is a macro, and a macro may expand to a declaration.

    xnu puts several of those at file scope: STARTUP() expands to a
    constructor function definition, SECURITY_READ_ONLY_LATE() to a variable
    with an attribute. Both end in a semicolon and both are legal there, so a
    name in capitals is not reported.
    """
    return name.isupper() or (name.replace('_', '').isupper() and name.strip('_') != '')


def added_lines(tree):
    """{relative path: set of line numbers} of the lines the patches added."""
    diff = subprocess.run(['git', '-C', str(tree), 'diff', '-U0', '--no-color'],
                          capture_output=True, text=True, check=True).stdout
    result, path = {}, None
    for line in diff.splitlines():
        if line.startswith('+++ b/'):
            path = line[6:]
            result.setdefault(path, set())
            continue
        if line.startswith('+++ /dev/null') or line.startswith('--- '):
            path = None
            continue
        if path is None or not line.startswith('@@'):
            continue
        match = re.search(r'\+(\d+)(?:,(\d+))?', line)
        if not match:
            continue
        start = int(match.group(1))
        count = int(match.group(2) or 1)
        result[path].update(range(start, start + count))
    return result


def depths(text):
    """Brace depth at the start of every line, and the lines that unbalance it."""
    result, depth = [], 0
    in_block, in_string, in_char = False, False, False
    in_dead = False
    for number, line in enumerate(text.splitlines(), 1):
        result.append(depth)
        stripped = line.strip()
        if in_dead:
            if re.match(r'#\s*endif', stripped):
                in_dead = False
            continue
        if re.match(r'#\s*if\s+0\b', stripped):
            in_dead = True
            continue
        index = 0
        while index < len(line):
            char = line[index]
            if in_block:
                if char == '*' and index + 1 < len(line) and line[index + 1] == '/':
                    in_block = False
                    index += 2
                    continue
                index += 1
                continue
            if in_string or in_char:
                if char == '\\':
                    index += 2
                    continue
                if (in_string and char == '"') or (in_char and char == "'"):
                    in_string = in_char = False
                index += 1
                continue
            if char == '/' and index + 1 < len(line):
                if line[index + 1] == '/':
                    break
                if line[index + 1] == '*':
                    in_block = True
                    index += 2
                    continue
            if char == '"':
                in_string = True
            elif char == "'":
                in_char = True
            elif char == '{':
                depth += 1
            elif char == '}':
                depth -= 1
                if depth < 0:
                    result[number - 1] = -1
                    depth = 0
            index += 1
    return result


def statement_at(line):
    """True when the line can only be a statement, never a declaration."""
    text = line.strip()
    if not text or text.startswith('#'):
        return False
    first = text.split(None, 1)[0].rstrip('(')
    if first in STATEMENT_KEYWORDS:
        return True
    match = CALL.match(text)
    if match and match.group(1) not in ATTRIBUTES and text.rstrip().endswith(';'):
        # A call: "name(...)" with no "=" before the argument list.
        if '=' not in text[:match.end()] and not is_macro(match.group(1)):
            return True
    return False


def check(tree):
    tree = Path(tree)
    problems = []
    for relative, lines in sorted(added_lines(tree).items()):
        if not relative.endswith(('.c', '.h')):
            continue
        path = tree / relative
        if not path.is_file():
            continue
        depth = depths(path.read_text(errors='replace'))
        for number in sorted(lines):
            if number < 1 or number > len(depth):
                continue
            if depth[number - 1] != 0:
                continue
            text = path.read_text(errors='replace').splitlines()[number - 1]
            if statement_at(text):
                problems.append((relative, number, text.strip()))
    return problems


def main(argv):
    if len(argv) < 2:
        print(__doc__)
        return 2
    failed = False
    for tree in argv[1:]:
        problems = check(tree)
        if not problems:
            print(f'{tree}: every added line is inside a function')
            continue
        failed = True
        print(f'{tree}: {len(problems)} added line(s) sit at file scope')
        for relative, number, text in problems:
            print(f'  {relative}:{number}: {text}')
        print('  A patch block landed outside the function it belongs to. '
              'The rebase moved it; the compiler will not accept it.')
    return 1 if failed else 0


if __name__ == '__main__':
    sys.exit(main(sys.argv))
