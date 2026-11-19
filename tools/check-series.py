#!/usr/bin/env python3
"""Check the XNU patch series the way the CI applies it, before the CI does.

Run 544 failed to build because a patch that replaced one line of C
with two lines of C also replaced the line after it: the slice was
written as lines[i:i+n] with n the number of the new lines instead of
the number of the old ones.  Six lines of IOService.cpp went with it,
one of them the brace that closed the candidate loop.  The compile said
"3 errors generated" and the log had been cut before the lines that
named them, so the round was lost.

This script is the local answer to that.  It does what the CI does --
copies the pristine xnu tree, applies the whole series with the same
command the CI uses -- and then it measures the result: the braces and
the parentheses of every file the series touched have to balance, and
the files have to hold what the last patch says they should hold.

usage:
  check-series.py [--src DIR] [--series FILE] [--expect FILE=STRING]...

  --src DIR     the pristine tree to start from (default: refs/xnu-xnu-8796.121.2)
  --series FILE the series to apply (default: device/UniXNU-nio/patches/xnu-8796/series)
  --expect      a STRING that must appear in FILE after the series is applied.
                May be given more than once.
"""
import os
import pathlib
import re
import shutil
import subprocess
import sys

DEFAULT_SRC = "refs/xnu-xnu-8796.121.2"
DEFAULT_SERIES = "device/UniXNU-nio/patches/xnu-8796/series"
SCRATCH = pathlib.Path("out/series-check")


def strip_code(src: str) -> str:
    """Remove comments, strings and character constants.

    The braces inside them are not braces, and a comment that talks
    about a brace is the oldest way to make a balance check lie.
    """
    out = []
    i = 0
    n = len(src)
    while i < n:
        c = src[i]
        if c == '"':
            i += 1
            while i < n and src[i] != '"':
                if src[i] == '\\':
                    i += 1
                i += 1
            i += 1
            continue
        if c == "'":
            i += 1
            while i < n and src[i] != "'":
                if src[i] == '\\':
                    i += 1
                i += 1
            i += 1
            continue
        if c == '/' and i + 1 < n and src[i + 1] == '/':
            while i < n and src[i] != '\n':
                i += 1
            continue
        if c == '/' and i + 1 < n and src[i + 1] == '*':
            i += 2
            while i + 1 < n and not (src[i] == '*' and src[i + 1] == '/'):
                i += 1
            i += 2
            continue
        out.append(c)
        i += 1
    return "".join(out)


def read_series(path: pathlib.Path):
    names = []
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        line = line.strip()
        if not line or line.startswith("#"):
            continue
        names.append(line)
    return names


def main(argv):
    args = argv[1:]
    src = DEFAULT_SRC
    series = DEFAULT_SERIES
    expects = []
    i = 0
    while i < len(args):
        if args[i] == "--src":
            src = args[i + 1]; i += 2
        elif args[i] == "--series":
            series = args[i + 1]; i += 2
        elif args[i] == "--expect":
            expects.append(args[i + 1]); i += 2
        else:
            print(__doc__)
            return 2

    srcp = pathlib.Path(src)
    seriesp = pathlib.Path(series)
    if not srcp.is_dir():
        print("no such tree: %s" % src)
        return 2
    if not seriesp.is_file():
        print("no such series: %s" % series)
        return 2

    names = read_series(seriesp)
    patchdir = seriesp.parent

    # A patch that is listed twice is applied twice: the first time it works
    # and the second time it says "reversed or previously applied", which
    # reads like the patch is already in the tree and hides the real state.
    # It happened twice in one afternoon, so it is checked here.
    duplicates = sorted({n for n in names if names.count(n) > 1})
    if duplicates:
        print("the series lists a patch more than once:")
        for d in duplicates:
            print("  " + d)
        return 1

    if SCRATCH.exists():
        shutil.rmtree(SCRATCH)
    SCRATCH.mkdir(parents=True)

    # every file the series touches, so that the scratch tree has them all
    wanted = set()
    for name in names:
        p = patchdir / name
        if not p.is_file():
            continue
        for m in re.finditer(r"^--- a/(\S+)", p.read_text(encoding="utf-8", errors="replace"), re.M):
            wanted.add(m.group(1))

    copied = 0
    for rel in sorted(wanted):
        s = srcp / rel
        if not s.is_file():
            continue
        d = SCRATCH / rel
        d.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(s, d)
        copied += 1

    failures = 0
    applied = 0
    for name in names:
        p = patchdir / name
        if not p.is_file():
            print("[missing] %s" % name)
            failures += 1
            continue
        # The CI applies the series with `git apply` (scripts/unixnu/patches.py),
        # so the checker does the same.  `patch` was used here until run 554,
        # and the two tools place a hunk differently when the context can be
        # found at more than one offset: `patch` takes the first match it
        # finds, `git apply` takes the one at the recorded position.  That is
        # not cosmetic -- the bsd_init phase marks landed inside bsd_init()
        # under `patch` and at file scope under `git apply`, and under
        # `git apply` they come *before* XNU's own definition of
        # bsd_init_kprintf, which then overrides them.  A tree that does not
        # match the CI's tree cannot tell a patch that works from one that
        # lands somewhere else.
        r = subprocess.run(
            ["git", "-c", "core.autocrlf=false", "-c", "core.eol=lf",
             "apply", "--verbose", "--whitespace=nowarn", "-p1",
             str(p.resolve()).replace("\\", "/")],
            cwd=str(SCRATCH), capture_output=True, text=True,
        )
        if r.returncode == 0:
            applied += 1
        else:
            text = r.stdout + r.stderr
            if "previously applied" in text or "Reversed (or" in text:
                print("[%s] already applied" % name)
                continue
            # a patch that only partly applied leaves hunks out: that is a
            # failure, and the hunks it could not place are printed by patch
            failures += 1
            print("[FAIL] %s" % name)
            for line in text.splitlines():
                if "FAILED" in line or "Hunk" in line:
                    print("        " + line.strip())

    print("patches=%d applied=%d failed=%d" % (len(names), applied, failures))

    # The balance of every file the series touched.  A file need not balance
    # on its own -- a macro may open a brace the preprocessor closes, and a
    # string may hold one -- so what has to hold is that the series did not
    # change the balance.  The tree the series starts from is the measure.
    problems = []
    for rel in sorted(wanted):
        f = SCRATCH / rel
        if not f.is_file():
            continue
        try:
            text = f.read_text(encoding="utf-8", errors="replace")
        except OSError:
            continue
        code = strip_code(text)
        braces = code.count("{") - code.count("}")
        parens = code.count("(") - code.count(")")
        before = None
        s = srcp / rel
        if s.is_file():
            bcode = strip_code(s.read_text(encoding="utf-8", errors="replace"))
            before = (bcode.count("{") - bcode.count("}"),
                      bcode.count("(") - bcode.count(")"))
        if before is None:
            if braces or parens:
                problems.append("%s: braces %+d, parentheses %+d" % (rel, braces, parens))
        elif (braces, parens) != before:
            problems.append("%s: the series moved the balance: braces %+d -> %+d, "
                            "parentheses %+d -> %+d" % (rel, before[0], braces, before[1], parens))

    for item in expects:
        rel, _, needle = item.partition("=")
        f = SCRATCH / rel
        if not f.is_file():
            problems.append("%s: no such file after the series" % rel)
            continue
        if needle not in f.read_text(encoding="utf-8", errors="replace"):
            problems.append("%s: does not hold %r" % (rel, needle))

    # A function definition inside a function.  C does not allow it, and the
    # compiler says so where the braces still balance, so the balance check
    # above does not catch it: run 547 put a helper inside exec_mach_imgact
    # and the build said "function definition is not allowed here".
    #
    # The tree is read, not the patch: a header line that ends in ) and is
    # followed by a brace is a function definition, and a function
    # definition at a brace depth above zero is inside another function.
    KEYWORDS = ("if", "for", "while", "switch", "else", "do", "return",
                "case", "default", "sizeof", "defined")

    def nested_definitions(text):
        """The lines of a text that hold a function definition inside a function."""
        found = []
        code = strip_code(text).split("\n")
        depth = 0
        for i, line in enumerate(code):
            stripped = line.strip()
            if depth > 0 and stripped.endswith(")") and i + 1 < len(code) \
                    and code[i + 1].strip() == "{":
                head = stripped[:-1].strip()
                word = head.split()[-1] if head.split() else ""
                if word and not any(word.startswith(k) for k in KEYWORDS) \
                        and not head.startswith(("}", "extern", "static inline")) \
                        and "=" not in head and "(" in head:
                    found.append(head[-60:])
            depth += line.count("{") - line.count("}")
        return found

    for rel in sorted(wanted):
        # C++ allows a function definition inside a function; C does not.
        if not rel.endswith(".c"):
            continue
        f = SCRATCH / rel
        if not f.is_file():
            continue
        try:
            text = f.read_text(encoding="utf-8", errors="replace")
        except OSError:
            continue
        after = nested_definitions(text)
        before = set()
        s = srcp / rel
        if s.is_file():
            before = set(nested_definitions(s.read_text(encoding="utf-8", errors="replace")))
        # only the ones the series brought are a problem: a nested definition
        # that was already in the tree is the tree's own business
        for h in after:
            if h not in before:
                problems.append("%s: a function definition inside a function (%s)"
                                % (rel, h))

    if problems:
        print("problems:")
        for p in problems:
            print("  " + p)
        return 1
    print("the series applies and the tree it makes balances")
    return 1 if failures else 0

if __name__ == "__main__":
    sys.exit(main(sys.argv))
