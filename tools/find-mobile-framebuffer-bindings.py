#!/usr/bin/env python3
"""Find IOMobileFramebuffer's bindings inside a prelinked kernel image.

Sheng's display recipe links a native driver against three symbols of the
original IOMobileFramebuffer:

    __ZN19IOMobileFramebufferC2EPK11OSMetaClass
    __ZN19IOMobileFramebufferD2Ev
    __ZN19IOMobileFramebuffer10gMetaClassE

and reads the parent's dispatch table out of the kernel image.  A release
kernelcache carries no kext symbols at all -- the 16.5 donor's symbol table
has 5868 names and not one of them belongs to a kext -- so those addresses
have to be recovered from the binary.  This script does that for any
prelinked image, which matters because the addresses move: the donor is
rebased by the prelink slide, and the final kernel lays its own segments
out differently again.

How the three facts are established:

  1. The class initializer that mentions the exact string
     "IOMobileFramebuffer" stores a metaclass into the class' gMetaClass
     variable.  Its caller passes that variable's address in x0, so the
     variable's address is known, and the metaclass it stores is known.
  2. The C2 of a class writes its own dispatch table into this[0]; the
     kernel's own IOService::C2 shows the shape.  A dispatch table is
     recognised by an entry that returns &gMetaClass -- only the class
     that owns the metaclass can have such an entry.
  3. The D2 is the function that calls IOService::D2's veneer.

Usage:  find-mobile-framebuffer-bindings.py <kernel image> [class name]
"""
import os
import re
import struct
import sys
from pathlib import Path

import capstone

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
CLASS_NAME = 'IOMobileFramebuffer'
KEXT_ID = 'com.apple.iokit.IOMobileGraphicsFamily'
MD = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)

RE_ADRP = re.compile(r'^(x\d+)\s*,\s*#(-?0x[0-9a-f]+|\d+)$')
RE_ADD = re.compile(r'^(x\d+)\s*,\s*(x\d+)\s*,\s*#(-?0x[0-9a-f]+|\d+)$')
RE_SUB_SP = re.compile(r'^sp\s*,\s*sp\s*,\s*#(-?0x[0-9a-f]+|\d+)$')
RE_ADD_SP = re.compile(r'^sp\s*,\s*sp\s*,\s*#(-?0x[0-9a-f]+|\d+)$')
RE_SLOT = re.compile(r'^(x\d+)\s*,\s*\[(sp|x29)\s*,\s*#(-?0x[0-9a-f]+|\d+)\]$')


def find_kit():
    """The XnuPrelink kit: vendored in the tree, or beside it in a checkout."""
    candidates = []
    if os.environ.get('UNIXNU_KIT'):
        candidates.append(Path(os.environ['UNIXNU_KIT']))
    candidates += [
        ROOT / 'kits/XnuPrelink',
        ROOT.parents[1] / 'refs/UniXNU/kits/XnuPrelink',
        ROOT.parent / 'UniXNU/kits/XnuPrelink',
    ]
    for path in candidates:
        if (path / 'native_prelink.py').is_file():
            return path
    raise SystemExit('the XnuPrelink kit is missing; looked in:\n  ' +
                     '\n  '.join(str(p) for p in candidates))


KIT = find_kit()
sys.path.insert(0, str(KIT))
from native_prelink import macho, unserialize_xml  # noqa: E402


def read_factory(segments, blob):
    def read(vaddr, size):
        for s in segments:
            if s['va'] <= vaddr and vaddr + size <= s['va'] + s['filesize']:
                fo = s['fileoff'] + (vaddr - s['va'])
                return blob[fo:fo + size]
        return None
    return read


def symbols(blob, image):
    tables = [(off, length) for command, off, length in image['commands'] if command == 2]
    if len(tables) != 1:
        raise SystemExit('expected exactly one symbol table')
    symoff, count, stroff, strsize = struct.unpack_from('<4I', blob, tables[0][0] + 8)
    strings = blob[stroff:stroff + strsize]
    out = {}
    for index in range(count):
        strx, kind, sect, desc, value = struct.unpack_from('<IBBHQ', blob, symoff + index * 16)
        if strx >= strsize:
            continue
        end = strings.find(b'\0', strx)
        if end < 0:
            continue
        out.setdefault(strings[strx:end].decode('utf-8', 'replace'), value)
    return out


def veneer(read, address):
    """Resolve the three instruction import veneer at address."""
    raw = read(address, 12)
    if raw is None:
        return None
    x, y, z = struct.unpack('<3I', raw)
    if not (x & 0x9f00001f == 0x90000010 and y & 0xffc003ff == 0xf9400210 and z == 0xd61f0200):
        return None
    imm = ((x >> 5) & 0x7ffff) << 2 | ((x >> 29) & 3)
    if imm & (1 << 20):
        imm -= 1 << 21
    pointer = (address & ~4095) + (imm << 12) + ((y >> 10) & 4095) * 8
    slot = read(pointer, 8)
    return struct.unpack('<Q', slot)[0] if slot else None


def decode(read, va, size):
    raw = read(va, size)
    return list(MD.disasm(raw, va)) if raw else []


class Frame:
    """Register and stack-slot values while walking one function."""

    def __init__(self):
        self.regs = {}
        self.stack = {}
        self.sp = 0

    def step(self, ins):
        op, text = ins.mnemonic, ins.op_str
        parts = [p.strip() for p in text.split(',')]

        m = RE_ADRP.match(text)
        if m and op == 'adrp':
            self.regs[m.group(1)] = int(m.group(2), 0)
            return
        m = RE_ADD.match(text)
        if m and op == 'add':
            dst, src, imm = m.group(1), m.group(2), int(m.group(3), 0)
            if src in self.regs:
                self.regs[dst] = self.regs[src] + imm
            return
        m = RE_SUB_SP.match(text)
        if m and op == 'sub':
            self.sp -= int(m.group(1), 0)
            return
        m = RE_ADD_SP.match(text)
        if m and op == 'add':
            self.sp += int(m.group(1), 0)
            return
        if op in ('stp', 'ldp') and '[sp, #-' in text:
            self.sp -= 0x10
            return
        m = RE_SLOT.match(text)
        if m:
            reg, base, off = m.group(1), m.group(2), int(m.group(3), 0)
            key = ('sp', self.sp + off) if base == 'sp' else ('fp', off)
            if op == 'str':
                if reg in self.regs:
                    self.stack[key] = self.regs[reg]
            elif op == 'ldr':
                if key in self.stack:
                    self.regs[reg] = self.stack[key]
            return


def analyse(insns, start, end):
    """formed address per instruction, plus the register state per instruction."""
    frame = Frame()
    formed, state = {}, {}
    for ins in insns:
        if ins.address < start:
            continue
        if ins.address >= end:
            break
        frame.step(ins)
        parts = [p.strip() for p in ins.op_str.split(',')]
        if ins.mnemonic in ('adrp', 'add'):
            value = frame.regs.get(parts[0])
            if value is not None:
                formed[ins.address] = value
        state[ins.address] = dict(frame.regs)
    return formed, state


def function_starts(insns):
    return [ins.address - 4 for ins in insns
            if ins.mnemonic == 'stp' and 'x29, x30' in ins.op_str]


def main():
    if len(sys.argv) not in (2, 3):
        raise SystemExit(__doc__)
    class_name = sys.argv[2] if len(sys.argv) > 2 else CLASS_NAME
    blob = Path(sys.argv[1]).read_bytes()
    image = macho(blob)
    segs = image['segments']
    read = read_factory(segs, blob)
    syms = symbols(blob, image)
    names_by_value = {}
    for name, value in syms.items():
        names_by_value.setdefault(value, name)

    ioc2 = syms.get('__ZN9IOServiceC2EPK11OSMetaClass')
    iod2 = syms.get('__ZN9IOServiceD2Ev')
    if ioc2 is None or iod2 is None:
        raise SystemExit('this image does not export the IOService entry points')
    print('IOService::C2 = %#x' % ioc2)
    print('IOService::D2 = %#x' % iod2)

    info_seg = next((s for s in segs if s['name'] == '__PRELINK_INFO'), None)
    if info_seg is None:
        raise SystemExit('this image has no __PRELINK_INFO segment')
    metadata = unserialize_xml(read(info_seg['va'], info_seg['filesize']))
    kext = next((e for e in metadata['_PrelinkInfoDictionary']
                 if e.get('CFBundleIdentifier') == KEXT_ID), None)
    if kext is None:
        raise SystemExit('%s is not prelinked into this image' % KEXT_ID)
    load = kext['_PrelinkExecutableLoadAddr']
    print('\n%s at %#x (size %#x)' % (KEXT_ID, load, kext['_PrelinkExecutableSize']))

    module = macho(read(load, 0x40000), 0)
    sections, owner = {}, {}
    for segment in module['segments']:
        for section in segment['sections']:
            sections.setdefault(section['name'], section)
            owner[section['name']] = segment['name']
    for needed in ('__text', '__stubs', '__cstring'):
        if needed not in sections:
            raise SystemExit('the kext has no %s section' % needed)
    text, stubs = sections['__text'], sections['__stubs']
    print('  __text  %#x .. %#x' % (text['va'], text['va'] + text['size']))
    print('  __stubs %#x .. %#x' % (stubs['va'], stubs['va'] + stubs['size']))

    # ---- the kext's own veneers -----------------------------------------
    kext_veneers = {}
    address = stubs['va']
    while address + 12 <= stubs['va'] + stubs['size']:
        target = veneer(read, address)
        if target is not None:
            kext_veneers[address] = target
            address += 12
        else:
            address += 4
    c2_veneers = {a for a, t in kext_veneers.items() if t == ioc2}
    d2_veneers = {a for a, t in kext_veneers.items()
                   if names_by_value.get(t, '').endswith('D2Ev')}
    print('  %d veneers, %d call IOService::C2, %d call IOService::D2'
          % (len(kext_veneers), len(c2_veneers), len(d2_veneers)))

    # ---- the class name --------------------------------------------------
    name_pointer = None
    for address in range(sections['__cstring']['va'],
                         sections['__cstring']['va'] + sections['__cstring']['size']):
        raw = read(address, 64)
        if raw is None:
            break
        if raw.split(b'\0')[0] == class_name.encode():
            name_pointer = address
            break
    if name_pointer is None:
        raise SystemExit('the kext does not carry the class name string')
    print('  class name string at %#x (%s)' % (name_pointer, class_name))

    body = decode(read, text['va'], text['size'])
    starts = function_starts(body)
    bounds = {}
    for index, start in enumerate(starts):
        end = starts[index + 1] if index + 1 < len(starts) else text['va'] + text['size']
        bounds[start] = end
    analysed = {start: analyse(body, start, end) for start, end in bounds.items()}

    def owner_of(address):
        for start, end in bounds.items():
            if start <= address < end:
                return start
        return None

    # ---- the class initializer -------------------------------------------
    initializer = None
    for start, (formed, _) in analysed.items():
        for address, value in formed.items():
            if value != name_pointer:
                continue
            for ins in body:
                if ins.address == address and ins.mnemonic == 'add':
                    initializer = start
                    break
            if initializer:
                break
        if initializer:
            break
    if initializer is None:
        raise SystemExit('no class initializer mentions %s' % class_name)
    print('  class initializer at %#x' % initializer)

    _, state = analysed[initializer]
    metaclass = None
    for ins in body:
        if ins.address < initializer or ins.address > initializer + 0x60:
            continue
        if ins.mnemonic == 'str' and ins.op_str.startswith('x8, [x0]'):
            metaclass = state.get(ins.address, {}).get('x8')
            break
    print('  metaclass %s' % (hex(metaclass) if metaclass else 'not found'))

    # ---- the gMetaClass variable -----------------------------------------
    data = [(section['va'], section['size']) for name, section in sections.items()
            if owner.get(name) in ('__DATA', '__DATA_CONST')]

    def in_data(value):
        return value is not None and any(va <= value < va + size for va, size in data)

    def callers_of(target):
        return [ins.address for ins in body
                if ins.mnemonic == 'bl' and ins.op_str == '#%#x' % target]

    gmetaclass = None
    frontier = [initializer]
    for _ in range(4):
        following = []
        for target in frontier:
            for call in callers_of(target):
                start = owner_of(call)
                if start is None:
                    continue
                cformed, _ = analysed[start]
                for address in range(call - 4, max(call - 0x60, 0), -4):
                    value = cformed.get(address)
                    if value is not None and in_data(value):
                        for ins in body:
                            if ins.address == address:
                                if ins.mnemonic == 'add' and ins.op_str.startswith('x0, x0,'):
                                    gmetaclass = value
                                break
                    if gmetaclass:
                        break
                if gmetaclass:
                    break
                following.append(start)
            if gmetaclass:
                break
        if gmetaclass:
            break
        frontier = [f for f in following if f]
    print('  gMetaClass variable %s' % (hex(gmetaclass) if gmetaclass else 'not found'))

    # ---- the dispatch table and the C2 -----------------------------------
    def table_of(pointer):
        entries = []
        for index in range(0, 8192, 8):
            raw = read(pointer + index, 8)
            if raw is None:
                break
            value = struct.unpack('<Q', raw)[0]
            if value in (0, 0xffffffffffffffff):
                break
            entries.append(value)
        return entries

    text_range = (text['va'], text['va'] + text['size'])

    def returns_gmetaclass(function):
        if not (text_range[0] <= function < text_range[1]):
            return False
        frame = Frame()
        for ins in decode(read, function, 0x60):
            frame.step(ins)
            if ins.mnemonic == 'ret':
                return frame.regs.get('x0') == gmetaclass
        return False

    # A constructor writes its own dispatch table into this[0].  The direct
    # subclass of IOService reaches it through the import veneer; a deeper
    # subclass calls its base's constructor instead.  So the candidates are
    # every function that stores a table pointer there, and the table that
    # owns the metaclass picks the right one.
    c2 = dispatch = None
    for start, (cformed, cstate) in analysed.items():
        stored = None
        for ins in body:
            if ins.address < start or ins.address >= start + 0x100:
                continue
            if ins.mnemonic == 'str' and ins.op_str == 'x8, [x0]':
                stored = cstate.get(ins.address, {}).get('x8')
                break
        if stored is None:
            continue
        entries = table_of(stored)
        if entries and any(returns_gmetaclass(e) for e in entries):
            c2, dispatch = start, stored
            break

    # The destructor: the first function after the constructor that calls
    # the IOService::D2 veneer.  XNU lets a class skip the intermediate
    # destructors when they add nothing, so every level of the hierarchy
    # calls the veneer itself.
    d2 = None
    if c2 is not None:
        for ins in body:
            if ins.address <= c2 or ins.mnemonic != 'bl':
                continue
            if ins.address > c2 + 0x200:
                break
            if int(ins.op_str[1:], 0) in d2_veneers:
                d2 = owner_of(ins.address)
                break

    print()
    print('=== the bindings of %s ===' % class_name)
    for name, value in (
            ('__ZN19IOMobileFramebufferC2EPK11OSMetaClass', c2),
            ('__ZN19IOMobileFramebufferD2Ev', d2),
            ('__ZN19IOMobileFramebuffer10gMetaClassE', gmetaclass)):
        print('  %-44s %s' % (name, hex(value) if value else 'NOT FOUND'))
    print('  parent dispatch table                      %s'
          % (hex(dispatch) if dispatch else 'NOT FOUND'))
    if dispatch:
        print('  dispatch table entries: %d' % len(table_of(dispatch)))
    if not (c2 and d2 and gmetaclass and dispatch):
        raise SystemExit('the bindings could not be established')


if __name__ == '__main__':
    main()
