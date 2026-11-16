#!/usr/bin/env python3
"""Boot the nio kernel inside QEMU, without the phone.

This is the host-side half of what DarwinBoot and BootShim do on the device:
place the kernel's segments at their physical addresses, put the device tree
and a boot_args struct behind the kernel, and jump to the entry point with
x0 = boot_args (physical).

The boot_args layout is pexpert/arm64/boot.h Revision 2:

    struct boot_args {
        uint16_t Revision, Version;          /* both 2 */
        uint64_t virtBase, physBase, memSize, topOfKernelData;
        struct boot_video Video;
        uint32_t machineType;
        uint64_t deviceTreeP;                 /* the ADT's *virtual* address */
        uint32_t deviceTreeLength;
        char CommandLine[608];
        uint64_t bootFlags, memSizeActual;
    };

with Video = { v_baseAddr, v_display, v_rowBytes, v_width, v_height, v_depth }
(Video at offset 40, CommandLine at 108, sizeof(boot_args) == 736).

The register convention comes from the arm64 entry code: the MMU and caches are
off, x0 holds the physical address of boot_args, and the tree is read later
with the MMU on, so deviceTreeP is a virtual address.

Nothing here is specific to nio except the addresses: the framebuffer sits at
0x9c000000 (1080x2520, pitch 4320), which is plain RAM in a 4 GiB QEMU virt
machine, so the console blob's writes land in memory we can read back.

Usage:
    qemu-nio.py --kernel out/kernel.macho --adt out/kernel.macho.adt \\
        [--cmdline "..."] [--seconds 60] [--out out/qemu]
"""

import argparse
import json
import os
import pathlib
import shutil
import socket
import struct
import subprocess
import sys
import tempfile
import time
import zlib

MH_MAGIC_64 = 0xFEEDFACF
LC_SEGMENT_64 = 0x19
LC_UNIXTHREAD = 0x5
LC_MAIN = 0x80000028

FRAMEBUFFER_BASE = 0x9C000000
FRAMEBUFFER_WIDTH = 1080
FRAMEBUFFER_HEIGHT = 2520
FRAMEBUFFER_PITCH = 4320
FRAMEBUFFER_DEPTH = 32

KERNEL_PHYS_BASE = 0x80000000
RAM_BASE = 0x40000000
RAM_SIZE = 0x100000000

PAGE_16K = 0x4000
BOOT_LINE_LENGTH = 608
BOOT_ARGS_SIZE = 736


def parse_macho(path):
    """Return (segments, entry) for a 64-bit little-endian Mach-O."""
    data = pathlib.Path(path).read_bytes()
    magic = struct.unpack_from("<I", data, 0)[0]
    if magic != MH_MAGIC_64:
        raise SystemExit("not a 64-bit Mach-O: magic 0x%x" % magic)
    ncmds, sizeofcmds = struct.unpack_from("<II", data, 16)
    off = 32
    segments = []
    entry = None
    main_off = None
    for _ in range(ncmds):
        cmd, cmdsize = struct.unpack_from("<II", data, off)
        if cmdsize == 0:
            break
        if cmd == LC_SEGMENT_64:
            (segname, vmaddr, vmsize, fileoff, filesize, maxprot, initprot,
             nsects, flags) = struct.unpack_from("<16sQQQQiiII", data, off + 8)
            name = segname.rstrip(b"\0").decode("latin1")
            if filesize:
                segments.append({
                    "name": name,
                    "vmaddr": vmaddr,
                    "vmsize": vmsize,
                    "fileoff": fileoff,
                    "filesize": filesize,
                })
        elif cmd == LC_UNIXTHREAD and entry is None:
            # cmd, cmdsize, flavor, count, then the thread state.
            # arm64 thread_state64: __x[29], __fp, __lr, __sp, __pc, __cpsr
            # so __pc sits 256 bytes into the state.
            flavor, count = struct.unpack_from("<II", data, off + 8)
            state_off = off + 16
            if flavor == 6 and count >= 68:      # ARM_THREAD_STATE64
                entry = struct.unpack_from("<Q", data, state_off + 256)[0]
        elif cmd == LC_MAIN and entry is None:
            entry_off = struct.unpack_from("<Q", data, off + 8)[0]
            main_off = entry_off
        off += cmdsize
    if entry is None and main_off is not None:
        text = [s for s in segments if s["name"] == "__TEXT"]
        if text:
            entry = text[0]["vmaddr"] + main_off
    if entry is None:
        # fall back to the lowest __TEXT segment
        text = [s for s in segments if s["name"] == "__TEXT"]
        if not text:
            raise SystemExit("no __TEXT segment and no entry point")
        entry = text[0]["vmaddr"]
    return segments, entry, data


def build_boot_args(virt_base, phys_base, mem_size, adt_va, adt_len, cmdline):
    """Pack the boot_args struct exactly as pexpert/arm64/boot.h Revision 2."""
    cmd = cmdline.encode("latin1", "replace")[:BOOT_LINE_LENGTH - 1]
    cmd = cmd + b"\0" * (BOOT_LINE_LENGTH - len(cmd))
    ba = bytearray(BOOT_ARGS_SIZE)
    struct.pack_into("<H", ba, 0, 2)          # Revision
    struct.pack_into("<H", ba, 2, 2)          # Version
    struct.pack_into("<Q", ba, 8, virt_base)
    struct.pack_into("<Q", ba, 16, phys_base)
    struct.pack_into("<Q", ba, 24, mem_size)
    struct.pack_into("<Q", ba, 32, 0)         # topOfKernelData, patched later
    # struct boot_video at offset 40
    struct.pack_into("<Q", ba, 40, FRAMEBUFFER_BASE)
    struct.pack_into("<Q", ba, 48, 1)         # v_display
    struct.pack_into("<Q", ba, 56, FRAMEBUFFER_PITCH)
    struct.pack_into("<Q", ba, 64, FRAMEBUFFER_WIDTH)
    struct.pack_into("<Q", ba, 72, FRAMEBUFFER_HEIGHT)
    struct.pack_into("<Q", ba, 80, FRAMEBUFFER_DEPTH)
    struct.pack_into("<I", ba, 88, 0)         # machineType
    struct.pack_into("<Q", ba, 96, adt_va)    # deviceTreeP (virtual)
    struct.pack_into("<I", ba, 104, adt_len)
    ba[108:108 + BOOT_LINE_LENGTH] = cmd
    struct.pack_into("<Q", ba, 716, 0)        # bootFlags
    struct.pack_into("<Q", ba, 724, mem_size) # memSizeActual
    return bytes(ba)


class Rsp:
    """Just enough of the GDB remote protocol to set two registers."""

    def __init__(self, host, port):
        self.sock = socket.create_connection((host, port), timeout=20)
        self.sock.settimeout(20)

    def _read(self, count):
        buf = b""
        while len(buf) < count:
            chunk = self.sock.recv(count - len(buf))
            if not chunk:
                raise EOFError("gdb stub closed")
            buf += chunk
        return buf

    def _packet(self, payload):
        body = payload.encode()
        frame = b"$" + body + b"#" + ("%02x" % (sum(body) & 0xFF)).encode()
        self.sock.sendall(frame)
        # the stub acknowledges with '+', optionally after the reply
        ack = self._read(1)
        if ack not in (b"+", b"-"):
            # a '+' may arrive after the payload for some packets
            pass

    def read_registers(self):
        self._packet("g")
        reply = self._read(1)
        if reply != b"$":
            raise EOFError("unexpected gdb reply %r" % reply)
        out = b""
        while True:
            ch = self._read(1)
            if ch == b"#":
                break
            out += ch
        self._read(2)
        self.sock.sendall(b"+")
        return out

    def write_registers(self, blob):
        hexed = blob.hex()
        self._packet("M%x,%s" % (0, hexed))
        self.sock.sendall(b"+")

    def set_register(self, index, value):
        blob = bytearray(self.read_registers())
        struct.pack_into("<Q", blob, index * 8, value)
        self.write_registers(bytes(blob))

    def cont(self):
        self._packet("c")
        self.sock.sendall(b"+")


def qmp_exec(proc, command, arguments=None):
    """Send one QMP command over the monitor socket and read the reply."""
    proc.stdin.write(json.dumps({"execute": command, "arguments": arguments or {}}) + "\n")
    proc.stdin.flush()
    deadline = time.time() + 30
    while time.time() < deadline:
        line = proc.stdout.readline()
        if not line:
            break
        line = line.strip()
        if line.startswith("{"):
            try:
                reply = json.loads(line)
            except ValueError:
                continue
            if "return" in reply or "error" in reply:
                return reply
    return None


def write_png(path, width, height, rgba):
    """Minimal PNG writer: the framebuffer is BGRA on this panel."""
    rows = bytearray()
    stride = width * 4
    for y in range(height):
        rows.append(0)
        row = rgba[y * stride:(y + 1) * stride]
        rows.extend(row)
    def chunk(tag, payload):
        return (struct.pack(">I", len(payload)) + tag + payload
                + struct.pack(">I", zlib.crc32(tag + payload) & 0xFFFFFFFF))
    header = struct.pack(">IIBBBBB", width, height, 8, 6, 0, 0, 0)
    png = (b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", header)
           + chunk(b"IDAT", zlib.compress(bytes(rows), 6)) + chunk(b"IEND", b""))
    pathlib.Path(path).write_bytes(png)


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("--kernel", default="out/kernel.macho")
    ap.add_argument("--adt", default="out/kernel.macho.adt")
    ap.add_argument("--cmdline", default="")
    ap.add_argument("--seconds", type=float, default=60.0)
    ap.add_argument("--out", default="out/qemu")
    ap.add_argument("--qemu", default="qemu-system-aarch64")
    ap.add_argument("--smp", type=int, default=8)
    args = ap.parse_args(argv)

    if shutil.which(args.qemu) is None:
        raise SystemExit("%s not found (brew install qemu)" % args.qemu)

    segments, entry, data = parse_macho(args.kernel)
    virt_base = min(s["vmaddr"] for s in segments)
    pa_offset = (KERNEL_PHYS_BASE - virt_base) & 0xFFFFFFFFFFFFFFFF
    kernel_end = max(s["vmaddr"] + s["vmsize"] for s in segments)

    adt = pathlib.Path(args.adt).read_bytes()
    adt_pa = (kernel_end + pa_offset) & 0xFFFFFFFFFFFFFFFF
    ba_pa = (adt_pa + len(adt) + PAGE_16K - 1) & ~(PAGE_16K - 1)
    top_of_kernel_data = ba_pa + PAGE_16K

    # The kernel reads the tree with the MMU on, so deviceTreeP is a virtual
    # address: physical minus the phys/virt offset, taken modulo 2**64.
    adt_va = (adt_pa - pa_offset) & 0xFFFFFFFFFFFFFFFF
    entry_pa = (entry + pa_offset) & 0xFFFFFFFFFFFFFFFF

    ba = build_boot_args(virt_base, KERNEL_PHYS_BASE, RAM_SIZE,
                         adt_va, len(adt), args.cmdline)
    ba = bytearray(ba)
    struct.pack_into("<Q", ba, 32, top_of_kernel_data)
    ba = bytes(ba)

    outdir = pathlib.Path(args.out)
    outdir.mkdir(parents=True, exist_ok=True)
    work = pathlib.Path(tempfile.mkdtemp(prefix="qemu-nio-"))

    loaders = []
    for index, seg in enumerate(segments):
        phys = (seg["vmaddr"] + pa_offset) & 0xFFFFFFFFFFFFFFFF
        blob = data[seg["fileoff"]:seg["fileoff"] + seg["filesize"]]
        if seg["vmsize"] > seg["filesize"]:
            blob = blob + b"\0" * (seg["vmsize"] - seg["filesize"])
        path = work / ("seg%02d-%s.bin" % (index, seg["name"].replace("/", "_")))
        path.write_bytes(blob)
        loaders.append((str(path), phys))
        print("seg %-20s va 0x%x -> pa 0x%x (%d bytes)"
              % (seg["name"], seg["vmaddr"], phys, len(blob)))

    adt_path = work / "adt.bin"
    adt_path.write_bytes(adt)
    loaders.append((str(adt_path), adt_pa))
    ba_path = work / "bootargs.bin"
    ba_path.write_bytes(ba)
    loaders.append((str(ba_path), ba_pa))

    print("virt_base 0x%x  phys_base 0x%x  entry va 0x%x pa 0x%x"
          % (virt_base, KERNEL_PHYS_BASE, entry, entry_pa))
    print("adt pa 0x%x len %d   boot_args pa 0x%x" % (adt_pa, len(adt), ba_pa))

    qemu_log = work / "qemu-stderr.log"
    cmd = [args.qemu, "-M", "virt,gic-version=3", "-cpu", "cortex-a76",
           "-m", str(RAM_SIZE // (1024 * 1024)), "-smp", str(args.smp),
           "-nographic", "-no-reboot", "-S", "-gdb", "tcp::1234",
           "-qmp", "stdio",
           # guest_errors is what turns a data abort inside the kernel into a
           # line we can read: ESR, FAR and the faulting virtual address.
           "-d", "guest_errors", "-D", str(qemu_log)]
    for path, phys in loaders:
        cmd += ["-device", "loader,file=%s,addr=0x%x" % (path, phys)]

    print("+ " + " ".join(cmd))
    proc = subprocess.Popen(cmd, stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                            stderr=subprocess.STDOUT, text=True, bufsize=1)
    logpath = outdir / "qemu.log"
    log = open(logpath, "w", encoding="utf-8", errors="replace")

    def pump():
        for line in proc.stdout:
            log.write(line)
            log.flush()

    import threading
    t = threading.Thread(target=pump, daemon=True)
    t.start()

    time.sleep(2)
    rsp = Rsp("127.0.0.1", 1234)
    rsp.set_register(0, ba_pa)          # x0 = boot_args (physical)
    rsp.set_register(31, entry_pa)     # pc
    print("registers set: x0=0x%x pc=0x%x" % (ba_pa, entry_pa))
    rsp.cont()

    deadline = time.time() + args.seconds
    while time.time() < deadline and proc.poll() is None:
        time.sleep(1)

    try:
        qmp_exec(proc, "pmemsave", {"val": FRAMEBUFFER_BASE,
                                    "size": FRAMEBUFFER_PITCH * FRAMEBUFFER_HEIGHT,
                                    "filename": str(outdir / "fb.bin")})
    except Exception as exc:               # noqa: BLE001
        print("pmemsave failed:", exc)

    try:
        proc.terminate()
    except Exception:                      # noqa: BLE001
        pass
    time.sleep(1)
    if proc.poll() is None:
        proc.kill()
    log.close()

    if qemu_log.is_file():
        text = qemu_log.read_text(errors="replace")
        (outdir / "qemu-guest-errors.log").write_text(text)
        if text.strip():
            print("guest errors://n" + text[:2000])

    fb = outdir / "fb.bin"
    if fb.is_file() and fb.stat().st_size:
        raw = fb.read_bytes()
        write_png(outdir / "fb.png", FRAMEBUFFER_WIDTH, FRAMEBUFFER_HEIGHT, raw)
        print("framebuffer -> %s (%d bytes), png written" % (fb, len(raw)))
    print("qemu log -> %s" % logpath)
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
