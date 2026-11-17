#!/usr/bin/env python3
"""Check that every function in the driver uses only what is declared above it.

Run 470 did not compile, and the reason was a name used before it was
declared: the spin function was written at the top of the file and read
the controller's status register, but the reader of that register and the
global that holds the controller are both further down.  A type check
does not catch that -- the fragment that checks the types is written in
the order the code should be, not in the order it is.

Run 463 did not compile either, and the reason was a format string
argument of the wrong type.

So this checks two things over the driver's own source, and it reads the
file as it is:

  1. Every static function is placed after every static symbol it uses.
     The symbols it looks for are the ones the file defines itself: the
     static functions and the file-scope variables.  A function that uses
     one of them before it is defined is a compile error, and this says
     which one and where.

  2. Every printf-shaped call has as many arguments as its format string
     has specifiers.  This is the check run 462's push got wrong by
     passing: it counted the specifiers and compared the count with the
     number of arguments, but it did not look at the types, and the two
     are different questions.  The count is what this does, because the
     types are what the separate type check does.

usage: check-driver-order.py <driver.cpp>
"""

import pathlib
import re
import sys

FUNCTION = re.compile(r"^static\s+(?:inline\s+)?[\w:<>\*&\s]+?\b(\w+)\s*\(")
DEFINITION = re.compile(r"^(?:static\s+)?(?:inline\s+)?[\w:<>\*&\s]+?\b(\w+)\s*\(")
VARIABLE = re.compile(r"^(?:static\s+)?(?:volatile\s+)?[\w:<>\*&\s]+?\b(\w+)\s*(?:=|;)")
SPECIFIER = re.compile(r"%[-+ #0-9.*']*(?:hh|h|ll|l|L|z|j|t)?[diouxXeEfgGaAcspn%]")


def strip_strings_and_comments(text):
    out = []
    i = 0
    n = len(text)
    while i < n:
        c = text[i]
        if c == '"' or c == "'":
            quote = c
            i += 1
            while i < n:
                if text[i] == "\\":
                    i += 2
                    continue
                if text[i] == quote:
                    i += 1
                    break
                i += 1
            out.append('""')
            continue
        if text.startswith("//", i):
            while i < n and text[i] != "\n":
                i += 1
            continue
        if text.startswith("/*", i):
            j = text.find("*/", i)
            i = n if j < 0 else j + 2
            out.append(" ")
            continue
        out.append(c)
        i += 1
    return "".join(out)


def main():
    if len(sys.argv) != 2:
        print(__doc__)
        return 2
    path = pathlib.Path(sys.argv[1])
    raw = path.read_text(encoding="utf-8", errors="replace")
    lines = raw.split("\n")

    # The file's own symbols and where they are defined.
    symbols = {}
    declared = set()
    forward = set()
    for i, line in enumerate(lines):
        if line[:1] in (" ", "\t"):
            continue                      # inside a function: a local
        m = FUNCTION.match(line)
        if m:
            name = m.group(1)
            if line.rstrip().endswith(";"):
                declared.add(name)          # a declaration, not a definition
                if name not in symbols:
                    forward.add(name)
            else:
                symbols.setdefault(name, i + 1)
            continue
        if not line.startswith("static"):
            continue                      # a global from a header
        m = VARIABLE.match(line)
        if m and "=" in line:
            symbols.setdefault(m.group(1), i + 1)
            declared.add(m.group(1))

    problems = 0

    # 1. A static function must come after the static symbols it uses.
    for i, line in enumerate(lines):
        m = FUNCTION.match(line)
        if not m or line.rstrip().endswith(";"):
            continue
        name = m.group(1)
        body = "\n".join(lines[i:i + 400])
        body = strip_strings_and_comments(body)
        # Only the part before the next function definition is this one.
        nxt = len(lines)
        for j in range(i + 1, min(i + 400, len(lines))):
            if FUNCTION.match(lines[j]) and not lines[j].rstrip().endswith(";"):
                nxt = j
                break
        body = "\n".join(lines[i:nxt])
        body = strip_strings_and_comments(body)
        for sym, where in symbols.items():
            if sym == name:
                continue
            if where <= i + 1:
                continue                  # defined above: fine
            if sym in forward:
                continue                  # declared before it was defined
            if not re.search(r"\b%s\b" % re.escape(sym), body):
                continue
            print("  ORDER: %s() at line %d uses %s, which is defined at line %d"
                  % (name, i + 1, sym, where))
            problems += 1

    # 2. A printf-shaped call needs one argument per specifier.
    for i, line in enumerate(lines):
        for call in re.finditer(r"\b(printf|nioUfsSay|IOLog)\s*\(", line):
            # Collect the arguments up to the closing parenthesis.  The
            # call may run over several lines, so the text is the lines
            # joined, and the call is found again in that text.
            joined = "\n".join(lines[i:i + 8])
            at = joined.find(call.group(0), call.start())
            text = joined[at + len(call.group(0)):]
            depth = 1
            args = []
            cur = ""
            for ch in text:
                if ch in "([{":
                    depth += 1
                elif ch in ")]}":
                    depth -= 1
                    if depth == 0:
                        args.append(cur)
                        break
                if ch == "," and depth == 1:
                    args.append(cur)
                    cur = ""
                else:
                    cur += ch
            fmt = ""
            for a in args:
                m = re.search(r'"((?:[^"\\]|\\.)*)"', a)
                if m:
                    fmt = m.group(1)
                    break
            if not fmt:
                continue
            specs = len([s for s in SPECIFIER.findall(fmt) if s != "%%"])
            given = len(args) - 1
            if specs != given:
                print("  COUNT: line %d, %s has %d specifiers and %d arguments"
                      % (i + 1, call.group(1), specs, given))
                problems += 1

    if problems:
        print("%d problem(s) in %s" % (problems, path.name))
        return 1
    print("%s: order and format counts are fine" % path.name)
    return 0


if __name__ == "__main__":
    sys.exit(main())
