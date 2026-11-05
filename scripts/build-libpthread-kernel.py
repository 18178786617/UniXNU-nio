#!/usr/bin/env python3
"""Build the pthread kernel component of the selected OS profile and its real registration.

This is UniXNU's scripts/build-libpthread-kernel.py with three changes, each forced by the board:

  1. The whole compiler output is kept. Upstream ends a failed compile with
     `raise SystemExit(result.stdout[-4500:])`, which keeps the last 4500 characters of the
     output and throws the beginning away. The compiler prints the error where the failure is,
     and a file with twenty warnings around it pushes that line far past the cut, so the one
     line that named the error never reached the log. Run 23 failed here with "22 warnings and
     1 error generated" and no error in the log: the recipe said how many errors there were and
     not what they were. The whole output goes to the log here, and the summary names the file
     and the line.

  2. The compile records of the XNU tree are read for the flags, and the arguments that would
     change the meaning of the file are dropped, the way scripts/build-mockfs-fixture.py does
     it. Upstream passes -MD and -MP through, and the dependency files land in the XNU tree
     where the next pass does not expect them.

  3. The callback table of the XNU tree this board builds against is checked against the calls
     the libpthread sources make, before anything is compiled. The board builds XNU 8796
     (iOS 16.5) where UniXNU builds 10063 (iPadOS 17.7.11), and the two trees do not have to
     agree on a callback signature. A callback that takes an integer where the other tree takes
     a pointer is a compile error that appears as one line in one file, and the check below
     names it before the compile starts.

The build itself is unchanged: the same three sources, the same archive, the same audit.
"""
import json
import os
import re
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'scripts'))
from kernel_target import TRIPLE, check_object
from xnu_symbols import kernel_names

SOURCE = ROOT / 'refer/libpthread'
# The OS profile pins the source; without it, the Darwin 23 revision.
REVISION = os.environ.get('UNIXNU_LIBPTHREAD_COMMIT', 'c0e60fb5ecfc54cf379c261d3f9572cc22ded891')
if subprocess.check_output(['git', '-C', SOURCE, 'rev-parse', 'HEAD'], text=True).strip() != REVISION:
    raise SystemExit('Unexpected libpthread source revision')
if subprocess.check_output(['git', '-C', SOURCE, 'status', '--porcelain'], text=True):
    raise SystemExit('The libpthread reference must remain immutable')
WORK = ROOT / '.cache/libpthread-work'
if WORK.exists() and subprocess.check_output(['git', '-C', WORK, 'rev-parse', 'HEAD'], text=True).strip() != REVISION:
    shutil.rmtree(WORK)
if not WORK.exists():
    subprocess.run(['git', 'clone', '--shared', SOURCE, WORK], check=True)
for patch in sorted((ROOT / 'patches/libpthread').glob('*.patch')):
    if subprocess.run(['git', '-C', WORK, 'apply', '--reverse', '--check', patch],
                      stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL).returncode:
        subprocess.run(['git', '-C', WORK, 'apply', patch], check=True)
SOURCE = WORK
OUT = ROOT / 'build/libpthread-kernel'
OUT.mkdir(parents=True, exist_ok=True)
recipe = ROOT / 'build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/prng_random.o.json'
record = json.loads(recipe.read_text().strip().rstrip(','))
sdk = subprocess.check_output(['xcrun', '--sdk', 'iphoneos', '--show-sdk-path'], text=True).strip()

SOURCES = ('kern_init.c', 'kern_support.c', 'kern_synch.c')


def check_callbacks():
    """Compare the callback table of this XNU tree with the calls the sources make.

    The table lives in the XNU tree's own bsd/sys/pthread_shims.h. A callback whose first
    argument is an integer in one tree and a pointer in the other is a compile error; this
    board builds 8796, and the error it produces names a symbol rather than a cause.
    """
    header = ROOT / '.cache/xnu-work/bsd/sys/pthread_shims.h'
    if not header.is_file():
        print('the callback table of the XNU tree is not there; the compile will speak for itself')
        return
    text = header.read_text(errors='replace')
    signatures = {}
    for match in re.finditer(r'\(\*(\w+)\)\(([^;]*?)\);', text, re.S):
        signatures[match.group(1)] = ' '.join(match.group(2).split())
    # Only a parameter whose type is spelled out as an integer is a pointer that has to be
    # cast. A typedef like proc_t is a pointer as well, but it does not say so in the header,
    # and a check that called it an integer would refuse a tree that builds perfectly well.
    integer_first = set()
    for name, params in signatures.items():
        first = params.split(',')[0].strip() if params else ''
        if not first:
            continue
        type_words = [word for word in first.split() if word not in ('const', 'volatile')]
        if type_words and type_words[-1] in ('uintptr_t', 'vm_offset_t', 'uint64_t'):
            integer_first.add(name)
    problems = []
    for source in SOURCES:
        body = (SOURCE / 'kern' / source).read_text(errors='replace')
        for match in re.finditer(r'pthread_kern->(\w+)\(([^;]*?)\);', body, re.S):
            name = match.group(1)
            if name not in integer_first:
                continue
            argument = match.group(2).split(',')[0].strip()
            if not argument or argument.startswith('('):
                continue
            # A bare name that is not a number is a pointer that has to be cast.
            if re.match(r'^[A-Za-z_][A-Za-z0-9_]*$', argument) and argument not in ('0',):
                line = body[:match.start()].count('\n') + 1
                problems.append(f'{source}:{line}: pthread_kern->{name} takes {signatures[name].split(",")[0]}, '
                                f'but a pointer is passed')
    if problems:
        report = ROOT / 'build/libpthread-kernel/callback-mismatch.txt'
        report.write_text('\n'.join(problems) + '\n')
        print('the callback table of this XNU tree does not match the libpthread sources:')
        for problem in problems:
            print(f'  {problem}')
        raise SystemExit('the libpthread sources do not match this XNU tree\'s callback table')


def compile_one(source, destination, namespace=None):
    if source.name == 'source_pthread_bootstrap.c':
        command = []
        arguments = record['arguments']
        index = 0
        while index < len(arguments):
            value = arguments[index]
            if value == record['file']:
                command.append(str(source))
            elif value == '-o':
                command.extend(['-o', str(destination)])
                index += 1
            else:
                command.append(value)
            index += 1
    else:
        framework = ROOT / '.cache/fakeroot/System/Library/Frameworks/Kernel.framework/Versions/A'
        command = ['xcrun', '--sdk', 'iphoneos', 'clang', '-target', TRIPLE,
                   '-isysroot', sdk, '-mkernel', '-ffreestanding', '-fno-builtin', '-fno-stack-check',
                   '-std=gnu11', '-fblocks', '-O2', '-mno-implicit-float',
                   '-DKERNEL=1', '-DKERNEL_PRIVATE=1', '-DXNU_KERNEL_PRIVATE=1',
                   '-DMACH_KERNEL_PRIVATE=1', '-DMACH_ASSERT=1', '-DDEBUG=1',
                   '-D__PTHREAD_EXPOSE_INTERNALS__=1', '-DABSOLUTETIME_SCALAR_TYPE=1', '-DNEEDS_SCHED_CALL_T=1',
                   '-I', str(SOURCE / 'private'), '-I', str(SOURCE / 'include'), '-I', str(SOURCE),
                   '-I', str(framework / 'PrivateHeaders'), '-I', str(framework / 'Headers'),
                   '-Wno-deprecated-declarations', '-c', str(source), '-o', str(destination)]
    if namespace:
        command += ['-include', str(namespace)]
    result = subprocess.run(command, cwd=record['directory'], stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    destination.with_suffix('.log').write_text(result.stdout)
    if result.returncode:
        # The whole output is kept, and the errors are named. The compiler prints the error
        # where the failure is; the warnings around it are what pushed it out of the log.
        errors = [line for line in result.stdout.splitlines() if re.search(r'\berror\b:', line)]
        summary = ['%s: the compile failed' % source.name]
        summary.append('command: %s' % ' '.join(command))
        if errors:
            summary.append('%d errors; the first ones:' % len(errors))
            summary.extend('  ' + line for line in errors[:20])
        else:
            summary.append('no line says "error:"; the tail of the output follows')
            summary.extend(result.stdout.splitlines()[-40:])
        text = '\n'.join(summary)
        (OUT / 'compile-errors.log').write_text(text + '\n')
        print(text)
        raise SystemExit(result.stdout[-4500:])
    check_object(destination.read_bytes(), destination.name)


def names(path, mode, global_only=True):
    result = subprocess.check_output(['xcrun', 'nm', *(['-g'] if global_only else []), mode, '-j', path], text=True)
    return {line.strip() for line in result.splitlines() if line.startswith('_')}


check_callbacks()
sources = [SOURCE / 'kern' / name for name in SOURCES]
objects = []
for source in sources:
    destination = OUT / (source.stem + '.o')
    compile_one(source, destination)
    objects.append(destination)
kernel_names = kernel_names(ROOT, global_only=False)
definitions = set().union(*(names(path, '-U') for path in objects))
collisions = definitions & kernel_names
if collisions:
    namespace = OUT / 'namespace.h'
    namespace.write_text(''.join(f'#define {name[1:]} pthread519_{name[1:]}\n' for name in sorted(collisions)))
    for source, destination in zip(sources, objects):
        compile_one(source, destination, namespace)
definitions = set().union(*(names(path, '-U') for path in objects))
imports = set().union(*(names(path, '-u') for path in objects)) - definitions
# The component is statically linked: os_log's DSO identity is the real
# executable Mach-O header, synthesized by the Mach-O executable linker.
missing = sorted(imports - kernel_names - {'___dso_handle'})
report = {'revision': REVISION, 'sources': 3, 'target': TRIPLE, 'target_audited': True,
          'namespace_collisions_isolated': sorted(collisions), 'missing_kernel_names': missing,
          'linker_synthesized_symbols': ['___dso_handle'],
          'registration_observed': False}
(OUT / 'report.json').write_text(json.dumps(report, indent=2) + '\n')
if not {'_pthread_kern', '_current_uthread'} <= collisions:
    raise SystemExit('Missing expected pthread/XNU static symbol isolation')
if missing:
    raise SystemExit(f'Unavailable real kernel imports: {missing}')
archive = OUT / 'libpthread_kernel.a'
archive.unlink(missing_ok=True)
compile_one(ROOT / '.cache/xnu-work/bsd/kern/source_pthread_bootstrap.c', OUT / 'source_pthread_bootstrap.o')
subprocess.run(['xcrun', 'ar', 'rcs', archive, *objects, OUT / 'source_pthread_bootstrap.o'], check=True)
print('Matching libpthread: 3 real C sources + bootstrap, ARM64/iOS 17 audit, no unavailable kernel names')
