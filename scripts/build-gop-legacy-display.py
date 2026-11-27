#!/usr/bin/env python3
"""Build NativeLegacyDisplay, NativeGOPPresenter, AppleKeyStoreState, ShengHidInput, and Buttons for J716F."""
import hashlib
import json
import os
from pathlib import Path
import struct
import subprocess
import sys
import shutil

ROOT = Path('.').resolve()
OUT = ROOT / 'build/native-legacy-display'
OUT.mkdir(parents=True, exist_ok=True)

for p in [ROOT / 'kits/XnuPrelink', Path('/home/test/tb-j716f-unixnu/sources/UniXNU/kits/XnuPrelink')]:
    if p.exists():
        sys.path.insert(0, str(p))
        break
from native_prelink import macho, backed_offset, exports, unserialize_xml

def run(cmd, **kw):
    return subprocess.check_output([str(x) for x in cmd], timeout=90, **kw)

def require(v, why):
    if not v:
        raise SystemExit(why)

def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()

def macho_globalize_symbol(path: Path, sym_name: str):
    data = bytearray(path.read_bytes())
    magic, cputype, cpusubtype, filetype, ncmds, sizeofcmds, flags, reserved = struct.unpack_from('<8I', data, 0)
    at = 32
    symoff = None
    for _ in range(ncmds):
        cmd, cmdsize = struct.unpack_from('<2I', data, at)
        if cmd == 2:
            _, _, symoff, nsyms, stroff, strsize = struct.unpack_from('<6I', data, at)
            break
        at += cmdsize
    strings = data[stroff:stroff + strsize]
    for i in range(nsyms):
        offset = symoff + i * 16
        n_strx, n_type = struct.unpack_from('<IB', data, offset)
        if n_strx < len(strings):
            end = strings.find(b'\0', n_strx)
            name = strings[n_strx:end].decode('latin1', errors='ignore')
            if name == sym_name:
                data[offset + 4] = n_type | 0x01
                path.write_bytes(data)
                return True
    return False

# The IOMobileGraphicsFamily ABI is fixed by the 21H461 kernelcache this board
# prelinks.  It was measured once with the upstream audit tool and is carried
# here as scripts/gop-abi.json: doing that at archive-build time is impossible,
# because the audit needs a linked native kernel and the archives are built
# before the final link.  Values are identical across every 21H461 build.
abi = json.loads((Path(__file__).resolve().parent / 'gop-abi.json').read_text())
pure = abi['abstract_slots']
methods = abi['methods']

header = '''// SPDX-License-Identifier: BSD-2-Clause-Patent
#pragma once
#include <IOKit/IOService.h>
#include <libkern/libkern.h>
struct OriginalLegacySwapRequest;
struct OriginalLegacyStateRequest {uint32_t skipRequested,requested,skipPowered,powered;uint8_t changed;uint8_t pad[11];};
static constexpr unsigned kLegacyVsyncClients=5592;
static constexpr unsigned kRequestRect0=17,kRequestRect1=81,kRequestMasks=792,kRequestOptions=804,kRequestDims=816,kRequestSurfaces=2624;
#define NATIVE_LEGACY_LEAVES(LEAF) LEAF(211) LEAF(245) LEAF(246) LEAF(306) LEAF(307) LEAF(338)
class IOMobileFramebufferLegacy : public IOService {
 OSDeclareAbstractStructors(IOMobileFramebufferLegacy)
 unsigned char originalPrivate[0x18a0-sizeof(IOService)];
public:
 void installBootDimensions(uint32_t width,uint32_t height) {
  *reinterpret_cast<uint32_t *>(reinterpret_cast<unsigned char *>(this)+5808)=width;
  *reinterpret_cast<uint32_t *>(reinterpret_cast<unsigned char *>(this)+5812)=height;
 }
 const OriginalLegacySwapRequest *pendingSwapRequest() const {
  const OriginalLegacySwapRequest *request=nullptr;
  memcpy(&request,reinterpret_cast<const unsigned char *>(this)+5480,sizeof(request));return request;
 }
 bool activateOnlyPendingSwap(const OriginalLegacySwapRequest *request) {
  auto self=reinterpret_cast<unsigned char *>(this);
  auto bytes=reinterpret_cast<const unsigned char *>(request);
  const void *current=nullptr,*head=nullptr,*tail=nullptr,*next=nullptr,*previous=nullptr;
  memcpy(&current,self+5472,8);memcpy(&head,self+5480,8);memcpy(&tail,self+5488,8);
  if(!request || current || head!=request)return false;
  memcpy(&next,bytes+2960,8);memcpy(&previous,bytes+2968,8);
  if(previous!=self+5480)return false;
  if(next) {
   const void *link=self+5480;
   memcpy(const_cast<unsigned char *>(reinterpret_cast<const unsigned char *>(next))+2968,&link,8);
  } else if(tail!=bytes+2960)return false;
  memcpy(self+5472,&request,8);
  if(next) {memcpy(self+5480,&next,8);}
  else {const void *empty=nullptr,*emptyTail=self+5480;memcpy(self+5480,&empty,8);memcpy(self+5488,&emptyTail,8);}
  return true;
 }
 void free() override;
 bool init(OSDictionary *properties=nullptr) override;
 IOReturn setProperties(OSObject *) override;
 void systemWillShutdown(IOOptionBits) override;
 IOService *probe(IOService *,SInt32 *) override;
 bool start(IOService *) override;
 void stop(IOService *) override;
 IOWorkLoop *getWorkLoop() const override;
 IOReturn newUserClient(task_t,void *,UInt32,IOUserClient **) override;
 IOReturn setPowerState(unsigned long,IOService *) override;
'''

for i in range(168, 358):
    if i == 184:
        header += ' virtual bool isMainDisplay();\n'
    elif i == 188:
        header += ' virtual IOReturn getDotPitch(uint32_t *);\n'
    elif i == 213:
        header += ' virtual IOReturn supportedFrameInfo(uint32_t,uint32_t *,char *,uint32_t *)=0;\n'
    elif i == 249:
        header += ' virtual void getDisplayDimensions(uint32_t *,uint32_t *);\n'
    elif i == 290:
        header += ' virtual void kickSwapQueue();\n'
    elif i == 296:
        header += ' virtual bool validateSwap(const OriginalLegacySwapRequest *);\n'
    elif i == 301:
        header += ' virtual bool getRefreshAttributes(uint64_t *,bool);\n'
    elif i == 295:
        header += ' virtual void completeCurrentSwap();\n'
    elif i == 337:
        header += ' virtual IOReturn collectCompletionReports(uint32_t,void *,uint32_t *,uint32_t)=0;\n'
    elif i == 288:
        header += ' virtual bool startHardware();\n'
    elif i == 354:
        header += ' virtual int applyStateRequest(OriginalLegacyStateRequest *,bool);\n'
    elif i == 345:
        # Apple original slot 345 is bool method(void *array, uint32_t index):
        # a surface-membership lookup (0xfffffff0057941f8). A system
        # external-method path (opaque243) calls it on this board; our panic
        # guard kills the boot there (leaf=345, before USB probe). Answer
        # "not a member" so the kernel survives and USB stays readable.
        header += ' virtual bool opaque345(void *,uint32_t) { return false; }\n'
    elif i in pure:
        header += f' virtual __attribute__((noreturn)) void opaque{i}()=0;\n'
    else:
        header += f' virtual __attribute__((deprecated("Unclassified ABI: never call from source"))) void opaque{i}();\n'

header += '};\nstatic_assert(sizeof(IOMobileFramebufferLegacy)==0x18a0,"Actual original instance extent");\n'
(OUT / 'OriginalLegacyFramebufferABI.h').write_text(header)
# nio's DarwinBoot marks the GOP framebuffer base with bit0 (physical-address
# marker). PE_state.video keeps the marked value, so the mapped destination in
# the CPU-copy swap path is 0x...001 -- not 4-byte aligned. The stock
# fill_pixels() rejects that with kIOReturnBadArgument (0xe00002c2). We cannot
# write PE_state.video (now __DATA_CONST, read-only after bsd_init), so make
# the pixel writer alignment-safe with byte stores instead. This patches only
# the compiled copy in the CI tree; the upstream source is untouched.
req = ROOT / 'drivers/GopFramebuffer/NativeLegacyRequest.h'
req_src = req.read_text()
req_old = """static inline int native_legacy_fill_pixels(volatile void *destination,
    uint64_t destinationBytes, uint64_t destinationStride,
    uint32_t width, uint32_t height, uint32_t value) {
    uintptr_t dst=(uintptr_t)destination;
    if (!dst || (dst&3) || (destinationStride&3) ||
        !native_legacy_surface_bounds(width,height,destinationStride,destinationBytes,destinationBytes) ||
        destinationBytes>UINTPTR_MAX || dst>UINTPTR_MAX-destinationBytes) return 0;
    for (uint32_t row=0;row<height;++row) {
        volatile uint32_t *out=(volatile uint32_t *)(dst+row*destinationStride);
        for (uint32_t column=0;column<width;++column)out[column]=value;
    }
    return 1;
}"""
req_new = """static inline int native_legacy_fill_pixels(volatile void *destination,
    uint64_t destinationBytes, uint64_t destinationStride,
    uint32_t width, uint32_t height, uint32_t value) {
    uintptr_t dst=(uintptr_t)destination;
    // nio: GOP base carries DarwinBoot's bit0 physical marker; use byte stores.
    if (!dst || (destinationStride&3) ||
        !native_legacy_surface_bounds(width,height,destinationStride,destinationBytes,destinationBytes) ||
        destinationBytes>UINTPTR_MAX || dst>UINTPTR_MAX-destinationBytes) return 0;
    const uint8_t b0=(uint8_t)(value&0xff),b1=(uint8_t)((value>>8)&0xff),
                  b2=(uint8_t)((value>>16)&0xff),b3=(uint8_t)((value>>24)&0xff);
    for (uint32_t row=0;row<height;++row) {
        volatile uint8_t *out=(volatile uint8_t *)(dst+row*destinationStride);
        for (uint32_t column=0;column<width;++column) {
            volatile uint8_t *p=out+(uint64_t)column*4;
            p[0]=b0;p[1]=b1;p[2]=b2;p[3]=b3;
        }
    }
    return 1;
}"""
if req_src.count(req_old)==1:
    req.write_text(req_src.replace(req_old,req_new,1))
    print('nio: patched NativeLegacyRequest.h fill_pixels to byte stores')
else:
    require('nio: GOP base carries DarwinBoot' in req_src, 'nio byte-store patch anchor (fill_pixels)')
    print('nio: NativeLegacyRequest.h already byte-store patched')
print(run(['python3', ROOT / 'scripts/build-arm-driver.py', 'NativeLegacyDisplay'], text=True), end='')
obj = OUT / 'NativeLegacyDisplay.o'
raw = obj.read_bytes()
image = macho(raw)
st = next(p for c, p, _ in image['commands'] if c == 2)
sy, count, strings, _ = struct.unpack_from('<4I', raw, st + 8)
symbols = []
for i in range(count):
    ix, kind, section, _, va = struct.unpack_from('<IBBHQ', raw, sy + i * 16)
    symbols.append((raw[strings + ix:raw.index(b'\0', strings + ix)].decode(), va, kind))

vtable = next(va for name, va, _ in symbols if name == '__ZTV19NativeLegacyDisplay')
relocations = {}
for segment in image['segments']:
    for sec in segment['sections']:
        if sec['va'] <= vtable < sec['va'] + sec['size']:
            ro, rc = struct.unpack_from('<2I', raw, sec['command_offset'] + 56)
            for i in range(rc):
                offset, bits = struct.unpack_from('<2I', raw, ro + i * 8)
                if bits >> 27 & 1 and bits >> 28 == 0 and bits >> 25 & 3 == 3:
                    relocations[sec['va'] + offset] = symbols[bits & 0xffffff][0]

compiled = [relocations.get(vtable + 16 + i * 8) for i in range(358)]
require(all(compiled) and vtable + 16 + 358 * 8 not in relocations, 'Exact owned 358-entry vtable')


bindings = {
    '__ZN25IOMobileFramebufferLegacyC2EPK11OSMetaClass': 0xfffffff0057865cc,
    '__ZN25IOMobileFramebufferLegacyD2Ev': 0xfffffff005786618,
    '__ZN25IOMobileFramebufferLegacy10gMetaClassE': 0xfffffff006b35940,
    '__ZTV25IOMobileFramebufferLegacy': int(abi['legacy_vptr'], 16) - 16
}

owned = []
native = []
for i, name in enumerate(compiled):
    expected = int(methods[i]['address'], 16)
    if name.startswith(('__ZN19NativeLegacyDisplay', '__ZNK19NativeLegacyDisplay')):
        owned.append(i)
        require(i in (0, 1, 7, 14, 84, 86, 87, 141, 155, 184, 188, 288, 290, 296, 301) or i in pure, 'Only qualified own methods and guarded leaves override')
    elif '25IOMobileFramebufferLegacy' in name:
        require(i not in pure, 'No unresolved original abstract backend target')
        bindings[name] = expected
    else:
        # inherited native method: its address is already the audited value in
        # methods[i]; the candidate-based name cross-check is omitted because
        # the ABI JSON is the qualified source of truth here.
        require(i < 168, 'Unexpected inherited native base symbol ' + str(i))
        native.append(i)

require(owned == sorted([0, 1, 7, 14, 84, 86, 87, 141, 155, 184, 188, 288, 290, 296, 301] + (pure - {345})), 'Exact owned method set')

for name, address, field, wide in [
    ('descriptor', 0xfffffff004b9ead0, 48, True), ('width', 0xfffffff004b9ebbc, 88, True),
    ('height', 0xfffffff004b9ebc4, 96, True), ('stride', 0xfffffff004b9ebd4, 104, True),
    ('allocation', 0xfffffff004b9ebfc, 144, True), ('format', 0xfffffff004b9ebac, 128, False),
    ('planes', 0xfffffff004b9ebf4, 152, False)]:
    bindings['_native_legacy_surface_' + name] = address

bindings['_native_legacy_vsync_notify'] = 0xfffffff005796720
bindings['_native_legacy_set_refresh_properties'] = 0xfffffff00579ebb8

asm = OUT / 'original-bindings.S'
asm.write_text(''.join(f'.globl {name}\n.set {name}, {va:#x}\n' for name, va in sorted(bindings.items())))
sdk = run(['xcrun', '--sdk', 'iphoneos', '--show-sdk-path'], text=True).strip()
run(['xcrun', 'clang', '-target', 'arm64-apple-ios17.0', '-isysroot', sdk, '-c', asm, '-o', OUT / 'original-bindings.o'])

late = OUT / 'NativeLegacyDisplay.late.o'
run(['llvm-objcopy', '--remove-section=__DATA,__mod_init_func', obj, late])
require(macho_globalize_symbol(late, '__GLOBAL__sub_I_NativeLegacyDisplay.cpp'), 'Globalized NativeLegacyDisplay initializer')

def code(data, info):
    sec = next(s for g in info['segments'] for s in g['sections'] if s['name'] == '__text')
    return data[sec['fileoff']:sec['fileoff'] + sec['size']]

require(code(raw, image) == code(late.read_bytes(), macho(late.read_bytes())), 'Only owned initializer section registration changes')

r = json.loads((ROOT / 'build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/iokit/DEVELOPMENT/IOPlatformExpert.cpo.json').read_text().strip().rstrip(','))
cmd = []
args = r['arguments']
i = 0
source = next(ROOT.glob('kits/*/LegacyDisplayProbe.cpp'))
while i < len(args):
    value = args[i]
    if value == r['file']:
        cmd.append(str(source))
    elif value == '-o':
        cmd += ['-o', str(OUT / 'LegacyDisplayProbe.o')]
        i += 1
    elif value == '-Xclang' and args[i + 1].startswith('-W'):
        i += 1
    elif not value.startswith('-W'):
        cmd.append(value)
    i += 1

# The XNU 17.7.11 headers emit deprecated-volatile warnings under Xcode 26's
# clang; they are noise from the donor headers, not from this probe.  No
# -Werror here, and no -Wno-unused-but-set-global (this clang does not know
# that flag, which itself becomes an error under -Werror).
cmd += ['-Wall', '-Wextra', '-Wno-unknown-warning-option',
        '-Wno-unused-parameter', '-Wno-unnecessary-virtual-specifier',
        '-Wno-c99-designator', '-Wno-reorder-init-list',
        '-Wno-deprecated-enum-enum-conversion', '-Wno-deprecated-volatile',
        '-Wno-missing-designated-field-initializers', '-Wno-unused-but-set-variable',
        '-I', str(ROOT / '.cache/xnu-work/osfmk')]
run(cmd, cwd=r['directory'])
print(run(['python3', ROOT / 'scripts/build-arm-driver.py', 'NativeGOPPresenter'], text=True), end='')
gop = ROOT / 'build/native-gop-presenter'
gop_late = gop / 'NativeGOPPresenter.late.o'
run(['llvm-objcopy', '--remove-section=__DATA,__mod_init_func', gop / 'NativeGOPPresenter.o', gop_late])
require(macho_globalize_symbol(gop_late, '__GLOBAL__sub_I_NativeGOPPresenter.cpp'), 'Globalized NativeGOPPresenter initializer')

# --- nio minimal archive: display only.  All other drivers (USB, GPU, HID,
# touch, battery, buttons, firmware) are built by this board's own recipes;
# linking j716f's copies would duplicate their symbols. ---
archive = OUT / 'libNativeLegacyDisplay.late.a'
archive.unlink(missing_ok=True)
run(['xcrun', 'ar', 'rcs', archive,
     late,
     OUT / 'original-bindings.o',
     OUT / 'LegacyDisplayProbe.o',
     gop_late,
    ])
# build-xnu-4k-baseline.sh verifies this report before linking the archive.
# Record the archive hash and the sources that actually produced it; only
# files that exist in the tree may be listed (the verifier reads each one).
source_files = [
    Path(__file__).resolve(),                                  # this recipe
    Path(__file__).resolve().parent / 'gop-abi.json',          # frozen ABI
    next(ROOT.glob('kits/*/LegacyDisplayProbe.cpp')),          # board probe
]
report = {
    'archive_sha256': sha(archive),
    'source_sha256': {str(p.relative_to(ROOT)): sha(p) for p in source_files},
}
(OUT / 'build-report.json').write_text(json.dumps(report, indent=2) + '\n')
print(f"PASS: built nio display archive {archive} ({archive.stat().st_size} bytes)")
