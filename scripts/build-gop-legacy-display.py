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
# nio: the nub range is now created from the masked GOP base (LegacyDisplayProbe
# masks DarwinBoot's bit0/bit1 physical marker, same contract as the kernel's
# video_console & ~3UL). Every physical==PE comparison in the component must
# therefore compare the masked PE value, or the transfer gate rejects the swap
# with kIOReturnNotReady. In-place patch of the compiled CI-tree copy only;
# upstream source untouched. Idempotent, anchor-checked like the byte-store patch.
disp = ROOT / 'drivers/GopFramebuffer/NativeLegacyDisplay.cpp'
disp_src = disp.read_text()
disp_pairs = [
    ('video.v_baseAddr!=bootMapping->getPhysicalAddress()',
     '(video.v_baseAddr&~3ULL)!=bootMapping->getPhysicalAddress()', 2),
    ('blank.v_baseAddr!=bootMapping->getPhysicalAddress()',
     '(blank.v_baseAddr&~3ULL)!=bootMapping->getPhysicalAddress()', 1),
    ('mapping->getPhysicalAddress()==video.v_baseAddr',
     'mapping->getPhysicalAddress()==(video.v_baseAddr&~3ULL)', 1),
]
for old, new, want in disp_pairs:
    n = disp_src.count(old)
    if n:
        require(n == want, f'nio mask anchor count {old!r}: {n} != {want}')
        disp_src = disp_src.replace(old, new)
    else:
        require(new in disp_src, f'nio mask anchor missing: {old!r}')
# 21H461 b3a8: match the exact AdrenoMetal c9ebd2fb producer's
# b3a8Planes fallback, not the top-level (alpha-sized) bytes-per-row.
# Match the producer exactly: its computed layout is used if either plane
# pitch is absent. Reject fully reported layouts until offsets are audited.
xr_helpers = r'''
// nio: bounded b3a8 linear fallback, paired with AdrenoMetal b3a8Planes.
extern "C" uint64_t native_legacy_surface_plane_stride(OSObject *,uint32_t);
static inline bool nativeXr(uint32_t format,uint32_t planes) {
    return format==0x62336138 && planes==2;
}
static bool nativeXrLayout(OSObject *surface,uint32_t width,uint32_t height,
                           uint64_t allocation,uint64_t descriptor,uint64_t &pitch,uint64_t &colorBytes) {
    const uint64_t w=native_legacy_surface_width(surface),h=native_legacy_surface_height(surface);
    if(!width || !height || !w || !h || w>16384 || h>16384 || width>w || height>h ||
       allocation>UINT32_MAX || descriptor<allocation ||
       (native_legacy_surface_plane_stride(surface,0) && native_legacy_surface_plane_stride(surface,1)))return false;
    pitch=(w*4+63)&~uint64_t(63);
    const uint64_t alphaPitch=(w+63)&~uint64_t(63);
    colorBytes=pitch*h;
    return (pitch+alphaPitch)*h<=allocation &&
           native_legacy_surface_bounds(width,height,pitch,colorBytes,colorBytes);
}
static bool nativeSourceBounds(OSObject *surface,uint32_t width,uint32_t height,
                                uint64_t allocation,uint64_t descriptor) {
    if(nativeXr(native_legacy_surface_format(surface),native_legacy_surface_planes(surface))) {
        uint64_t pitch=0,colorBytes=0;
        return nativeXrLayout(surface,width,height,allocation,descriptor,pitch,colorBytes);
    }
    return native_legacy_surface_bounds(width,height,native_legacy_surface_stride(surface),allocation,descriptor);
}
// Uke 45ff642e XR10 decoding: code 384 is black, 894 is SDR white.
// Premultiplied RGB over the already-qualified black background needs no
// alpha-plane read. Byte stores preserve nio's device-memory alignment rule.
static bool convertXrRows(volatile void *destination,uint64_t destinationBytes,uint64_t destinationStride,
                           const void *source,uint64_t sourceBytes,uint64_t sourceStride,uint32_t width,uint32_t height) {
    uintptr_t dst=reinterpret_cast<uintptr_t>(destination),src=reinterpret_cast<uintptr_t>(source);
    if(!dst || !src || !native_legacy_surface_bounds(width,height,destinationStride,destinationBytes,destinationBytes) ||
       !native_legacy_surface_bounds(width,height,sourceStride,sourceBytes,sourceBytes) ||
       destinationBytes>UINTPTR_MAX || sourceBytes>UINTPTR_MAX ||
       dst>UINTPTR_MAX-destinationBytes || src>UINTPTR_MAX-sourceBytes)return false;
    for(uint32_t y=0;y<height;++y) {
        const uint8_t *in=reinterpret_cast<const uint8_t *>(src+y*sourceStride);
        volatile uint8_t *out=reinterpret_cast<volatile uint8_t *>(dst+y*destinationStride);
        for(uint32_t x=0;x<width;++x) {
            uint32_t value;__builtin_memcpy(&value,in+uint64_t(x)*4,4);
            for(unsigned c=0;c<3;++c) {
                const unsigned code=(value>>(c*10))&1023;
                out[uint64_t(x)*4+c]=code>=894?255:(code<=384?0:(code-383)>>1);
            }
            out[uint64_t(x)*4+3]=255;
        }
    }
    return true;
}
'''
xr_state = r'''
    // CPU XR reads must wait for the producer; no timeout fabricates completion.
    IOTimerEventSource *xrTimer=nullptr;
    const OriginalLegacySwapRequest *xrRequest=nullptr;
    uint32_t xrTarget=0;bool xrTargetValid=false;
    static void xrFired(OSObject *owner,IOTimerEventSource *) {
        auto self=static_cast<NativeLegacyDisplay *>(owner);
        self->transferred=false;self->kickSwapQueue();
    }
    bool xrReady(const OriginalLegacySwapRequest *request) {
        if(!xrTimer) {
            IOWorkLoop *loop=getWorkLoop();
            xrTimer=loop?IOTimerEventSource::timerEventSource(this,&NativeLegacyDisplay::xrFired):nullptr;
            if(!xrTimer)return false;
            if(loop->addEventSource(xrTimer)!=kIOReturnSuccess){OSSafeReleaseNULL(xrTimer);return false;}
        }
        if(xrRequest!=request){xrRequest=request;xrTargetValid=false;}
        uint32_t submitted=0,retired=0;
        if(&native_adreno_fences && native_adreno_fences(&submitted,&retired)) {
            if(!xrTargetValid){xrTarget=submitted;xrTargetValid=true;}
            if(int32_t(retired-xrTarget)>=0)return true;
        }
        xrTimer->setTimeoutUS(1000);return false;
    }
'''
xr_copy = r'''
        if(xr) {
            uint64_t colorBytes=0;
            if(!nativeXrLayout(surface,width,height,allocation,source->getLength(),sourceStride,colorBytes) ||
               !native_legacy_prepare_scanout()) {
                OSSafeReleaseNULL(source);native_legacy_transfer_observed(kIOReturnBadArgument,request,0);return;
            }
            uint64_t copyStart;__asm__ volatile("isb\n\tmrs %0, cntpct_el0":"=r"(copyStart));
            if(!convertXrRows(reinterpret_cast<volatile void *>(bootMapping->getVirtualAddress()),bootMapping->getLength(),video.v_rowBytes,
                reinterpret_cast<const void *>(source->getVirtualAddress()),colorBytes,sourceStride,width,height)) {
                OSSafeReleaseNULL(source);native_legacy_transfer_observed(kIOReturnBadArgument,request,0);return;
            }
            __asm__ volatile("dsb sy" ::: "memory");
            uint64_t copyEnd;__asm__ volatile("isb\n\tmrs %0, cntpct_el0":"=r"(copyEnd));
            native_legacy_copy_timing_observed(copyEnd-copyStart,length);
            shadowValid=false;OSSafeReleaseNULL(source);transferred=true;
            xrRequest=nullptr;xrTargetValid=false;
            native_legacy_transfer_observed(kIOReturnSuccess,request,length);
            finishTransfer(request);return;
        }
'''
if '// nio: bounded b3a8 linear fallback' not in disp_src:
    xr_pairs = [
        ('static inline bool nativeScanoutFormat', xr_helpers+'\nstatic inline bool nativeScanoutFormat', 1),
        ('return nativeBgra(format,planes) || nativeHalf(format,planes);',
         'return nativeBgra(format,planes) || nativeHalf(format,planes) || nativeXr(format,planes);', 1),
        ('    bool transferred=false;', '    bool transferred=false;\n'+xr_state, 1),
        ('!native_legacy_surface_bounds(width,height,sourceStride,allocation,memory->getLength())',
         '!nativeSourceBounds(surface,width,height,allocation,memory->getLength())', 1),
        ('native_legacy_surface_bounds(width,height,native_legacy_surface_stride(surface),\n                           native_legacy_surface_allocation(surface),memory->getLength())',
         'nativeSourceBounds(surface,width,height,native_legacy_surface_allocation(surface),memory->getLength())', 1),
        ('        if(directOn && !half',
         '        if(directOn && !xr && !half', 2),
        ('        const bool half=nativeHalf(native_legacy_surface_format(surface),native_legacy_surface_planes(surface));',
         '        const bool half=nativeHalf(native_legacy_surface_format(surface),native_legacy_surface_planes(surface));\n'
         '        const bool xr=nativeXr(native_legacy_surface_format(surface),native_legacy_surface_planes(surface));\n'
         '        if(xr && !xrReady(request))return;', 1),
        ('if(!gpuBypass && native_legacy_gpu_offer(', 'if(!xr && !gpuBypass && native_legacy_gpu_offer(', 1),
        ('        if(half) {', xr_copy+'\n        if(half) {', 1),
        ('                        native_legacy_surface_rejected(',
         '                        if(nativeXr(native_legacy_surface_format(surface),native_legacy_surface_planes(surface)))\n'
         '                            reason=40+(native_legacy_surface_plane_stride(surface,0)?1:0)+(native_legacy_surface_plane_stride(surface,1)?2:0);\n'
         '                        native_legacy_surface_rejected(', 1),
        ('        if(fenceTimer){fenceTimer->cancelTimeout();',
         '        if(xrTimer){xrTimer->cancelTimeout();if(IOWorkLoop *loop=getWorkLoop())loop->removeEventSource(xrTimer);OSSafeReleaseNULL(xrTimer);}\n'
         '        if(fenceTimer){fenceTimer->cancelTimeout();', 1),
    ]
    for old,new,want in xr_pairs:
        require(disp_src.count(old)==want, f'nio XR anchor {old!r}: {disp_src.count(old)} != {want}')
        disp_src=disp_src.replace(old,new)
    print('nio: qualified b3a8 linear CPU conversion; GPU/direct paths excluded')
disp.write_text(disp_src)
print('nio: masked DarwinBoot marker in NativeLegacyDisplay.cpp comparisons')
pres = ROOT / 'drivers/GopFramebuffer/NativeGOPPresenter.cpp'
pres_src = pres.read_text()
pold = 'mapping->getPhysicalAddress()!=video.v_baseAddr'
pnew = 'mapping->getPhysicalAddress()!=(video.v_baseAddr&~3ULL)'
if pold in pres_src:
    require(pres_src.count(pold) == 1, 'nio mask anchor count (presenter)')
    pres.write_text(pres_src.replace(pold, pnew))
else:
    require(pnew in pres_src, 'nio mask anchor missing (presenter)')
print('nio: masked DarwinBoot marker in NativeGOPPresenter.cpp comparison')
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
        # nio: slot 345 is now an inline mirror override (returns false), not a
        # guarded leaf; it legitimately resolves to the mirror class symbol while
        # still listed in abi abstract_slots. Exclude it from the pure-slot gate.
        require(i not in pure or i == 345, 'No unresolved original abstract backend target')
        if i != 345:
            bindings[name] = expected
    else:
        # inherited native method: its address is already the audited value in
        # methods[i]; the candidate-based name cross-check is omitted because
        # the ABI JSON is the qualified source of truth here.
        require(i < 168, 'Unexpected inherited native base symbol ' + str(i))
        native.append(i)

require(owned == sorted([0, 1, 7, 14, 84, 86, 87, 141, 155, 184, 188, 288, 290, 296, 301] + list(set(pure) - {345})), 'Exact owned method set')

for name, address, field, wide in [
    ('descriptor', 0xfffffff004b9ead0, 48, True), ('width', 0xfffffff004b9ebbc, 88, True),
    ('height', 0xfffffff004b9ebc4, 96, True), ('stride', 0xfffffff004b9ebd4, 104, True),
    ('allocation', 0xfffffff004b9ebfc, 144, True), ('format', 0xfffffff004b9ebac, 128, False),
    ('planes', 0xfffffff004b9ebf4, 152, False)]:
    bindings['_native_legacy_surface_' + name] = address

# Audited 21H461 getter: plane table +0x180, entries 0x38 bytes,
# bytes-per-row at +0x20; nonplanar fallback is the known self+0x68.
bindings['_native_legacy_surface_plane_stride'] = 0xfffffff004b9f1fc

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
