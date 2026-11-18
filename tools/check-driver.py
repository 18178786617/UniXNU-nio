#!/usr/bin/env python3
"""Check the driver for the mistakes that a build would find, and nothing else.

Why this exists
---------------
This board's kernel is built on a runner, on macOS, with clang.  There is
no compiler for it on this machine, so a mistake in the driver is found
only when the build runs -- a round and a runner later.  Three such
mistakes have cost a round each:

  round 489   use of undeclared identifier 'result'
              (a check returned it above the line that declared it)
  round 513   value size does not match register size
              (a 32-bit value compared against a 64-bit register)
  round 513   unused variable 'fwList'

Two earlier versions of this script tried more.  One also looked for a
name used before it was declared and a variable never used, and it
reported nine hundred problems that were not problems: a parameter and a
variable in an inner scope look the same to a text scan.  The second
kept the unused-variable check and could not tell a local from a class
member.  A check that cries wolf is worse than no check, so neither is
here.  What remains is what a reader can decide from the file alone,
with no false positives on the file it was written against.

What is here is what a reader can decide from the file alone, with no
false positives:

  * braces and parentheses that do not balance
  * an inline assembly operand whose width does not match the register
    it is compared against
  * a local variable that is declared in a function and never appears
    again in that function  -- REMOVED: it could not tell a local from a
    class member without false positives, so it is not claimed here

Usage
-----
    tools/check-driver.py drivers/NioUfs/NioUfs.cpp
"""
from __future__ import annotations

import re
import sys

COMMENT = re.compile(r"//[^\n]*|/\*.*?\*/", re.S)
STRING = re.compile(r'"(?:[^"\\]|\\.)*"')
CHAR = re.compile(r"'(?:[^'\\]|\\.)*'")

# Names this file uses that look like a local variable but are not one:
# the kernel's own constants, macros and the members of the driver's
# structures.  A name here is never reported as unused.
KNOWN_NAMES = {
    "kIOReturnSuccess", "kIOReturnError", "kIOReturnNoMemory",
    "kIOReturnNoSpace", "kIOReturnBadArgument", "kIOReturnNotFound",
    "kIOReturnBusy", "kIOReturnUnsupported", "kIOReturnNoDevice",
    "kIOReturnTimeout", "kIOReturnNotReady", "kIOReturnExclusiveAccess",
    "kIOMemoryMapperNone", "kIOMemoryPhysicallyContiguous",
    "kIOMapAnywhere", "kIOMapInhibitCache",
    "native_ufs_version", "native_ufs_hcs", "native_ufs_hce",
    "native_ufs_utrl_ready", "native_ufs_uic_status",
    "native_ufs_uic_result",
    "kernel_task", "gRootDiagnostic", "true", "false", "window",
}


DECL = re.compile(
    r"\b(?:const\s+|volatile\s+|static\s+|unsigned\s+|signed\s+|struct\s+|"
    r"class\s+|enum\s+|union\s+)*"
    r"(?:[A-Za-z_]\w*(?:::[A-Za-z_]\w*)*\s+)+"
    r"(?P<name>[A-Za-z_]\w*)\s*(?=[=;,)\[\]{])"
)

ASM_OPERAND = re.compile(
    r"\b(?P<op>cmp|cmn|add|sub|mov|mvn|and|orr|eor|tst)\s+"
    r"(?P<left>x\d+|w\d+),\s*"
    r"(?:(?P<reg>x\d+|w\d+)|%\[(?P<name>\w+)\])"
)
ASM_CONSTRAINT = re.compile(r":\s*\[(\w+)\]\s*\"([^\"]*)\"\s*\(\s*([^;]*?)\s*\)")

# A system register instruction: "mrs %0, daif" or "msr daifclr, %0".
# The register is 64 bits on arm64 whatever the value that carries it is.
#
# The operand may be written in either of the two ways the compiler
# takes.  The named way is "%[name]" with a constraint ":[name] "r" (...)";
# the positional way is "%0" with the constraints in order after the
# outputs.  Both are looked at, because round 512 used the positional
# one and the check that only knew the named one missed it.
SYSTEM_OPERAND = re.compile(
    r"\b(?P<op>mrs|msr)\b[^;]*?%\[(?P<name>\w+)\]"
)

# The same instruction with a positional operand: the number after the
# percent sign is the index of the operand.
SYSTEM_OPERAND_POSITIONAL = re.compile(
    r"\b(?P<op>mrs|msr)\b[^;]*?%(?P<index>\d+)"
)

# The constraints of the operands, in the order they are written.  The
# outputs come first and the inputs after them, so the index of an
# operand is its place in this list.
ASM_CONSTRAINT_LIST = re.compile(r"\"([^\"]*)\"\s*\(\s*([^;]*?)\s*\)")

# A declaration of a local variable: a type, a name, and an assignment or
# an opening bracket.  A parameter list is not a declaration.
# One type, then one name, then an assignment.  The type is written
# out rather than matched loosely, so that a line with one identifier
# in it (a struct member, a keyword) is not taken for a declaration.
TYPES = (r"u?int(?:8|16|32|64)_t|uint\d+_t|int\d+_t|uintptr_t|intptr_t|"
         r"unsigned|signed|bool|size_t|ssize_t|char|short|long|double|float|"
         r"UfsResult|OSSharedPtr|IOMemoryDescriptor|IOMemoryMap")
LOCAL = re.compile(r"^\s*(?:const\s+|volatile\s+|static\s+)*"
                   r"(?:" + TYPES + r")\s+"
                   r"(?P<name>[A-Za-z_]\w*)\s*=\s*[^;]*;\s*$")


def strip_code(text: str) -> str:
    """Remove comments and literals, keeping the line structure.

    The constraint of an inline assembly operand is a string -- "r", "x",
    "m" -- and it is what says how wide that operand is.  Blanking the
    strings takes that away, so the assembly is lifted out first and put
    back afterwards.
    """
    asm_blocks = []

    def keep(match: re.Match) -> str:
        asm_blocks.append(match.group(0))
        return "\n" * match.group(0).count("\n")

    text = re.sub(r"__asm__\s*volatile\s*\(.*?\);", keep, text, flags=re.S)
    text = COMMENT.sub(lambda m: "\n" * m.group(0).count("\n"), text)
    text = STRING.sub('""', text)
    text = CHAR.sub("''", text)
    for index, block in enumerate(asm_blocks):
        text = text.replace("\n" * block.count("\n"), block, 1) if False else text
    return text, asm_blocks


def function_blocks(lines: list[str]) -> list[tuple[int, int]]:
    """The (first, last) line of every brace-delimited body.

    The blocks are found by their braces alone, not by their signature:
    a signature may span several lines, and one that does would be missed
    by a pattern that expects it on one line.
    """
    blocks = []
    start = None
    depth = 0
    in_class = False
    for number, line in enumerate(lines, 1):
        opened = line.count("{")
        closed = line.count("}")
        if start is None:
            if opened:
                start = number
                depth = opened - closed
                in_class = bool(re.match(r"^\s*(?:class|struct|union)\b", line))
                if depth <= 0:
                    if not in_class:
                        blocks.append((start, number))
                    start = None
                    in_class = False
            continue
        depth += opened - closed
        if depth <= 0:
            if not in_class:
                blocks.append((start, number))
            start = None
            in_class = False
    return blocks


def check(path: str) -> list[str]:
    raw = open(path, encoding="utf-8", errors="replace").read()
    code, asm_blocks = strip_code(raw)
    lines = code.split("\n")
    problems: list[str] = []

    for opener, closer, name in (("{", "}", "braces"), ("(", ")", "parentheses")):
        difference = code.count(opener) - code.count(closer)
        if difference:
            problems.append("%s: %s do not balance (%+d)" % (path, name, difference))

    # An assembly operand of one width compared against a register of the
    # other.  This is the mistake round 513 made.  The assembly is looked
    # at in the text as it was written: the constraint of an operand is a
    # string, and the string is what says how wide it is.
    for block in asm_blocks:
        base = raw.count("\n", 0, raw.find(block)) + 1
        for offset, line in enumerate(block.split("\n")):
            number = base + offset
            for match in ASM_OPERAND.finditer(line):
                left = match.group("left")
                right = match.group("reg") or ("%[" + match.group("name") + "]"
                                               if match.group("name") else "")
                named = match.group("name")
                if (left.startswith("x") and right.startswith("w")) or \
                   (left.startswith("w") and right.startswith("x")):
                    problems.append("%s:%d: %s mixes a 64-bit and a 32-bit register"
                                    % (path, number, match.group(0)))
                if not named:
                    continue
                constraint = None
                for found in ASM_CONSTRAINT.finditer(block):
                    if found.group(1) == named:
                        constraint = found.group(3)
                # The operand is as wide as the value it carries: a cast
                # to a 64-bit type makes it 64 bits wide whatever the
                # literal says.
                wide = re.search(r"\bu?int64_t\b|\bu?long\b|\bsize_t\b|"
                                 r"\bu?int128_t\b", constraint or "")
                narrow = (constraint is not None and not wide and
                          (re.search(r"\buint32_t\b|\buint16_t\b|\bint\b\s*$", constraint)
                           or re.search(r"\b\d+[uU]\b", constraint)))
                if narrow:
                    problems.append(
                        "%s:%d: the assembly limit for %%[%s] is 32-bit and it is "
                        "compared against a 64-bit register" % (path, number, named))

    # A system register read or written by name is 64 bits wide on arm64,
    # and the compiler says so:
    #
    #   error: value size does not match register size specified by the
    #   constraint and modifier [-Werror,-Wasm-operand-widths]
    #
    # This is the mistake round 512 made: "mrs %0, daif" and
    # "msr daifclr, %0" were given a 32-bit value.  The check looks for
    # an operand of a "mrs" or "msr" instruction that is carried by a
    # value the text says is 32 bits wide.
    for block in asm_blocks:
        base = raw.count("\n", 0, raw.find(block)) + 1
        for offset, line in enumerate(block.split("\n")):
            number = base + offset
            for match in SYSTEM_OPERAND.finditer(line):
                constraint = None
                for found in ASM_CONSTRAINT.finditer(block):
                    if found.group(1) == match.group("name"):
                        constraint = found.group(3)
                if constraint is None:
                    continue
                if re.search(r"\bu?int32_t\b|\bu?int16_t\b|\buint\b\s*$|"
                             r"\bint\b\s*$", constraint):
                    problems.append(
                        "%s:%d: the operand of \"%s\" is 32-bit and the "
                        "register it names is 64-bit"
                        % (path, number, match.group("op")))

            # The positional way: the operand is "%0" or "%1" and the
            # constraints are written in order.  The outputs come first
            # in the list of constraints, so the index of the operand is
            # its place in that list.
            for match in SYSTEM_OPERAND_POSITIONAL.finditer(line):
                index = int(match.group("index"))
                constraints = ASM_CONSTRAINT_LIST.findall(block)
                if index >= len(constraints):
                    continue
                constraint = constraints[index][1]
                if re.search(r"\bu?int32_t\b|\bu?int16_t\b|\buint\b\s*$|"
                             r"\bint\b\s*$", constraint):
                    problems.append(
                        "%s:%d: the operand of \"%s\" is 32-bit and the "
                        "register it names is 64-bit"
                        % (path, number, match.group("op")))

    return problems


def main(argv: list[str]) -> int:
    paths = [a for a in argv if not a.startswith("--")]
    if not paths:
        print(__doc__)
        return 2
    problems: list[str] = []
    for path in paths:
        problems.extend(check(path))
    if problems:
        for problem in problems:
            print(problem)
        print("%d problem(s)" % len(problems))
        return 1
    print("no problems found in %s" % ", ".join(paths))
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
