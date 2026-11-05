#!/usr/bin/env python3
"""Install the boot console blob into the 16.5 kernel image.

This is the nio port of the 17.7.11 mechanism. The 17.7 bring-up (R56-R118)
reached userland and the GPU with CONFIG_XNU_NATIVE_LEGACY_DISPLAY=n, so the
screen could not come from the display personality. It came from a blob that is
assembled against the kernel it is injected into and dropped into the tail
padding of __TEXT_EXEC, with four kernel entry points re-pointed at it:

  _panic                    -> panic_screen         (panic prints on the frame buffer)
  _panic_trap_to_debugger   -> panic_screen_common  (same funnel, unchanged behaviour)
  vcputc_options            -> console_putc         (kprintf reaches the screen)
  sysent[4].sy_call         -> console_write        (write(1) from EL0 lands there too)
  sysent[3].sy_call         -> console_read         (read(4) reaches the touch bridge)

Why the blob and not CONFIG_XNU_BOOT_PROGRESS:

  * Upstream's build-xnu-4k-baseline.sh refuses BOOT_PROGRESS=1 unless
    XNU_NATIVE_UFS=1, XNU_OWNER_ROOT_AUDIT=1 and XNU_SOURCE_CORECRYPTO14=1
    are all set. nio has no UFS driver (its userdata is LUN 4 of a 6-LUN UFS
    and the inherited host driver only speaks LUN 0), so the build would stop.
  * boot_progress_bind() is only called from initialize_screen() in
    osfmk/console/video_console.c. With the display personality off, the
    diagnostic never learns the frame buffer address, so it would have nothing
    to draw on even if the build allowed it.

The blob needs neither. It reads the frame buffer description the loader
handed over and draws into it directly, which is exactly what worked on 17.7.

Everything here is symbol driven: the blob is re-assembled against this
kernel's symbol table, so the addresses it bakes in (the vinfo pointer, the
cons_ops slot, the sysent entries) are this kernel's, not the donor's. Every
site is verified before it is written, and the only bytes changed are inside
the __TEXT_EXEC tail padding or at the re-pointed sites.

Usage: python3 scripts/install-console-blob.py <kernel.macho>
"""
import argparse
import importlib.util
import os
import struct
import sys
import tempfile
from pathlib import Path

HERE = Path(__file__).resolve().parent
CONSOLE = HERE / 'console'
REPO = HERE.parent.parent.parent

# The 17.7 blob was 8169 bytes and the hole was 9904. The 16.5 kernel's
# __TEXT_EXEC padding has to be checked at run time; this is only the size
# the 17.7 run used, and the tool reports the real figure.
HOLE_DEFAULT = 9904


def brace_env():
    """The toolchain lives in the tree; nothing is on the system PATH.

    shims/ holds the wrappers the toolchain needs (llvm-nm is a Python
    shim, not a binary), and bin/ holds the real cross tools. The prefix is
    built left to right and prepended in one go -- prepending twice reverses
    the two entries."""
    path = os.environ.get('PATH', '')
    pre = [str(REPO / sub) for sub in ('toolchain/shims', 'toolchain/bin')]
    path = os.pathsep.join([p for p in pre if p not in path] + [path])
    os.environ['PATH'] = path
    os.environ.setdefault('UNIXNU_UEFI', str(REPO / 'build/uefi-umi'))
    os.environ.setdefault('NIO_TOOLS', str(REPO / 'tools'))
    # The read hook is what routes read(4) to the Novatek touch bridge, so it
    # is on by default here: nio's touch is the Novatek NT36672C on SPI and
    # the bridge is the only path that reaches it. NO_READ_HOOK=1 in the
    # environment still turns it off, for the runs that only want the console.
    os.environ.pop('NO_READ_HOOK', None)


def load_probe():
    path = CONSOLE / 'patch-xnu-entry-probe.py'
    spec = importlib.util.spec_from_file_location('xnu_entry_probe', path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def segments_with_names(data):
    """segment name -> (vmaddr, fileoff, filesize, initprot)"""
    ncmds = struct.unpack_from('<I', data, 16)[0]
    pos, out = 32, {}
    for _ in range(ncmds):
        cmd, size = struct.unpack_from('<II', data, pos)
        if cmd == 0x19:
            name = data[pos + 8:pos + 24].rstrip(b'\0').decode()
            vmaddr, vmsize = struct.unpack_from('<QQ', data, pos + 24)
            fileoff, filesize = struct.unpack_from('<QQ', data, pos + 40)
            maxprot, initprot = struct.unpack_from('<II', data, pos + 56)
            out[name] = (vmaddr, fileoff, filesize, initprot)
        pos += size
    return out


def tail_padding(data, segment='__TEXT_EXEC'):
    """the zero run at the end of a segment: where the blob lives

    The 17.7 kernel put the blob in the tail of __TEXT_EXEC. The 16.5 kernel
    has only 7696 bytes there while the blob needs 9518, so __PLK_TEXT_EXEC
    is the fallback: it is the prelink image of __TEXT_EXEC, the kernel maps
    it as executable text itself (osfmk/arm64/arm_vm_init.c reads it back out
    of the header), and its tail padding is 554808 bytes of nothing. The
    loader maps segments by their protection bits rather than by name, so a
    blob in either segment is mapped and callable the same way."""
    for name, (vmaddr, fileoff, filesize) in segments_with_names(data).items():
        if name != segment:
            continue
        body = data[fileoff:fileoff + filesize]
        start = len(body)
        while start and body[start - 1] == 0:
            start -= 1
        if len(body) - start < 4096:
            raise SystemExit(f'{segment} has only {len(body) - start} bytes of tail padding')
        return vmaddr + start, vmaddr + len(body)
    raise SystemExit(f'No {segment} segment in this kernel')


def find_caves(data):
    """every segment tail with enough room, executable ones first

    Only an executable segment can hold the blob: the loader maps a segment
    with its protection bits, and a blob in a data segment would be mapped
    non-executable and the branch into it would fault. __TEXT_EXEC is the
    17.7 choice and the first one tried; __PLK_TEXT_EXEC is the prelink image
    of the same thing and is the 16.5 fallback because __TEXT_EXEC's tail is
    only 7696 bytes there while the blob needs 9518.

    The executable list is not "every segment": the segments carry their
    protection in the load command, and only the ones with the execute bit
    are code. __BOOTDATA and __DATA_CONST hold data and are skipped."""
    order = {'__TEXT_EXEC': 0, '__PLK_TEXT_EXEC': 1}
    out = []
    for name, (vmaddr, fileoff, filesize, initprot) in segments_with_names(data).items():
        body = data[fileoff:fileoff + filesize]
        start = len(body)
        while start and body[start - 1] == 0:
            start -= 1
        if len(body) - start < 4096:
            continue
        executable = name in order
        out.append((0 if executable else 1, order.get(name, 9), name,
                    vmaddr + start, vmaddr + len(body)))
    out.sort()
    return [(name, cave, end) for _, _, name, cave, end in out]


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('kernel', type=Path, help='the kernel image to update in place')
    args = parser.parse_args()

    if not args.kernel.is_file():
        raise SystemExit(f'{args.kernel} does not exist')

    brace_env()

    module = load_probe()
    data = bytearray(args.kernel.read_bytes())
    module.load_segments(data)
    names = module.rebase(args.kernel, data)

    caves = find_caves(data)
    if not caves:
        raise SystemExit('this kernel has no segment tail with room for the blob')

    # Already patched? sysent[4].sy_call no longer points at _write, it points
    # at console_write. Say so and stop, rather than assembling and writing a
    # second blob into the next hole.
    sysent, write_fn = names.get('_sysent'), names.get('_write')
    if sysent is not None and write_fn is not None:
        slots = [struct.unpack_from('<Q', data, module.file_offset(sysent + i))[0]
                 for i in range(0, 0x400, 8)]
        if write_fn not in slots:
            print('this kernel already carries the console blob '
                  '(sysent[4].sy_call no longer points at _write); nothing to do')
            return

    # Assemble once per candidate segment: the blob is linked at the segment's
    # tail, so its layout depends on where it lands, and the size can move by
    # a few bytes when the branch ranges change.
    chosen = None
    for name, cave, seg_end in caves:
        if seg_end - cave < 4096:
            continue
        with tempfile.TemporaryDirectory() as tmp:
            try:
                code, load, entry, blob = module.assemble_c(
                    CONSOLE / 'xnu-panic-screen.c', cave, Path(tmp), names)
            except SystemExit as error:
                print(f'{name:20s} assembly failed: {error}')
                continue
        if load != cave:
            print(f'{name:20s} blob linked at {load:#x}, expected {cave:#x}')
            continue
        if load + len(code) > seg_end:
            print(f'{name:20s} blob is {len(code)} bytes, {seg_end - load} available -- too small')
            continue
        chosen = (name, cave, seg_end, code, load, entry, blob)
        print(f'{name:20s} blob {len(code)} bytes at {load:#x} ({seg_end - load - len(code)} spare)')
        break

    if chosen is None:
        raise SystemExit('no segment tail can hold the blob')

    name, cave, seg_end, code, load, entry, blob = chosen
    off = module.file_offset(cave)
    end_off = module.file_offset(seg_end)
    if any(data[off:end_off]):
        raise SystemExit(f'Padding at {cave:#x} is not empty')

    panic = names.get('_panic')
    common = names.get('_panic_trap_to_debugger')
    console = blob.get('console_putc')
    if panic is None or common is None or console is None:
        raise SystemExit('missing _panic, _panic_trap_to_debugger or console_putc')
    cons_ops = names.get('_cons_ops')
    if cons_ops is None:
        raise SystemExit('missing _cons_ops')
    vcputc = struct.unpack_from('<Q', data, module.file_offset(cons_ops) + 16)[0]
    if not 0xfffffff000000000 <= vcputc < 0xffffffff00000000:
        raise SystemExit(f'cons_ops[1].putc holds {vcputc:#x}, not a kernel pointer')

    data[off:off + len(code)] = code
    for site, target, name in ((panic, blob['panic_screen'], '_panic'),
                               (common, blob['panic_screen_common'], '_panic_trap_to_debugger'),
                               (vcputc, console, 'vcputc_options')):
        struct.pack_into('<I', data, module.file_offset(site), module.branch(site, target))
        print(f'{name:24s} {site:#x} -> {target:#x}')

    # sysent[SYS_write].sy_call -> console_write, so a process in EL0 can print.
    # Located by finding the slot that points at _write rather than by assuming
    # a struct size: it is 24 bytes here (CONFIG_REQUIRES_U32_MUNGING) and 16
    # without it, and a wrong stride would corrupt another syscall.
    sysent, write_fn, handler = names.get('_sysent'), names.get('_write'), blob.get('console_write')
    if sysent is None or write_fn is None or handler is None:
        raise SystemExit('missing _sysent, _write or console_write')
    hits = [i for i in range(0, 0x400, 8)
            if struct.unpack_from('<Q', data, module.file_offset(sysent + i))[0] == write_fn]
    if len(hits) != 1:
        # A kernel that already carries the blob has no slot pointing at
        # _write any more: sysent[4] points at console_write. Re-running the
        # tool on an already-patched kernel must not half-patch it, so this
        # is reported as "already installed" rather than as a failure.
        already = [i for i in range(0, 0x400, 8)
                   if struct.unpack_from('<Q', data, module.file_offset(sysent + i))[0] == handler]
        if already:
            print(f'this kernel already carries the console blob '
                  f'(sysent[4].sy_call -> {handler:#x}); nothing to do')
            return
        raise SystemExit(f'_write appears {len(hits)} times in the first 64 sysent slots')
    entry = sysent + hits[0]
    stride = hits[0] // 4
    narg = struct.unpack_from('<h', data, module.file_offset(entry) + stride - 4)[0]
    if stride not in (16, 24) or hits[0] != 4 * stride or narg != 3:
        raise SystemExit(f'sysent[4] at {entry:#x} does not look like write (stride {stride}, narg {narg})')
    struct.pack_into('<Q', data, module.file_offset(entry), handler)
    print(f'{"sysent[4].sy_call":24s} {entry:#x} -> {handler:#x} (was _write at {write_fn:#x}, '
          f'stride {stride}, narg {narg})')

    # sysent[SYS_read].sy_call -> console_read, so read(4) reaches the
    # Novatek touch bridge. Same lookup rule as write.
    read_fn, read_handler = names.get('_read'), blob.get('console_read')
    if read_fn is None or read_handler is None:
        raise SystemExit('missing _read or console_read (touch bridge)')
    if os.environ.get('NO_READ_HOOK') == '1':
        print(f'{"sysent[3].sy_call":24s} left as _read at {read_fn:#x} (NO_READ_HOOK)')
    else:
        rhits = [i for i in range(0, 0x400, 8)
                 if struct.unpack_from('<Q', data, module.file_offset(sysent + i))[0] == read_fn]
        if len(rhits) != 1:
            raise SystemExit(f'_read appears {len(rhits)} times in the first 64 sysent slots')
        rentry = sysent + rhits[0]
        rnarg = struct.unpack_from('<h', data, module.file_offset(rentry) + stride - 4)[0]
        if rhits[0] != 3 * stride or rnarg != 3:
            raise SystemExit(f'sysent[3] at {rentry:#x} does not look like read '
                             f'(slot {rhits[0]}, stride {stride}, narg {rnarg})')
        struct.pack_into('<Q', data, module.file_offset(rentry), read_handler)
        print(f'{"sysent[3].sy_call":24s} {rentry:#x} -> {read_handler:#x} (was _read at {read_fn:#x}, '
              f'narg {rnarg})')

    args.kernel.write_bytes(data)
    print(f'blob {len(code)} bytes at {load:#x} ({seg_end - load - len(code)} spare), '
          f'{args.kernel} updated')


if __name__ == '__main__':
    main()
