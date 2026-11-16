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

# The kernel mirrors every console character into the ramoops pstore console
# record (nio-console-to-ramoops.patch): { u32 sig='DBGC', u32 start, u32 size }
# followed by a plain-text ring.  Reading that ring out of guest memory gives
# the whole console as text -- far better than decoding pixels.
RAMOOPS_CONSOLE = 0xAF040000
RAMOOPS_RING = 0x3F000
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
    """Just enough of the GDB remote protocol to set two registers.

    The packet reader buffers: the stub's acknowledgement can arrive before
    or after the reply, so a reader that expects a fixed order desynchronises
    and then sees the '#' of a checksum as if it were the start of a packet.
    """

    # aarch64 register numbers as the remote protocol numbers them:
    # 0..30 are x0..x30, 31 is sp, 32 is pc, 33 is cpsr.
    REG_PC = 32

    def __init__(self, host, port):
        self.sock = socket.create_connection((host, port), timeout=20)
        self.sock.settimeout(20)
        self.pending = bytearray()

    def _receive(self):
        while True:
            start = self.pending.find(b"$")
            if start < 0:
                # acknowledgements and noise before the reply
                self.pending.clear()
            else:
                del self.pending[:start]
                end = self.pending.find(b"#", 1)
                if end >= 0 and len(self.pending) >= end + 3:
                    data = self.pending[1:end]
                    checksum = self.pending[end + 1:end + 3]
                    del self.pending[:end + 3]
                    if int(checksum, 16) != sum(data) % 256:
                        raise RuntimeError("gdb checksum mismatch")
                    self.sock.sendall(b"+")
                    return data.decode()
            chunk = self.sock.recv(65536)
            if not chunk:
                raise RuntimeError("gdb connection closed")
            self.pending.extend(chunk)

    def request(self, payload):
        body = payload.encode()
        self.sock.sendall(b"$" + body + b"#" + ("%02x" % (sum(body) % 256)).encode())
        return self._receive()

    def read_registers(self):
        return bytes.fromhex(self.request("g"))

    def set_register(self, index, value):
        # P<regnum>=<value> writes one register; the value is in target byte
        # order, which is little endian for arm64.
        raw = struct.pack("<Q", value).hex()
        reply = self.request("P%x=%s" % (index, raw))
        if reply != "OK":
            raise RuntimeError("could not set register %d: %r" % (index, reply))

    def cont(self):
        # 'c' has no reply until the target stops; the socket is only used for
        # the reading above, so the answer is not waited for.
        body = b"c"
        self.sock.sendall(b"$" + body + b"#" + ("%02x" % (sum(body) % 256)).encode())


class Qmp:
    """The monitor, kept open for the whole run.

    QEMU's monitor speaks QMP, which only starts after the capabilities have
    been negotiated: until the qmp_capabilities command has been sent, every
    command is refused with "Expecting capabilities negotiation with
    'qmp_capabilities'".  The connection is kept open because the monitor is
    a single client, and reopening it for every command is how a second
    connection ends up talking to nobody.
    """

    def __init__(self, sock_path, wait=30):
        sock_path = str(sock_path)
        deadline = time.time() + wait
        last = None
        while time.time() < deadline:
            if os.path.exists(sock_path):
                try:
                    self.sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
                    self.sock.settimeout(30)
                    self.sock.connect(sock_path)
                    break
                except OSError as exc:
                    # the socket file appears before the monitor accepts a
                    # client, so the connect can still fail
                    last = exc
                    try:
                        self.sock.close()
                    except Exception:          # noqa: BLE001
                        pass
            time.sleep(0.2)
        else:
            raise RuntimeError("could not connect to the monitor: %s (%s)"
                               % (sock_path, last))

        self.pending = b""
        self._readline()                      # the greeting
        self.execute("qmp_capabilities")

    def _readline(self):
        while b"\n" not in self.pending:
            chunk = self.sock.recv(65536)
            if not chunk:
                raise RuntimeError("the monitor closed the connection")
            self.pending += chunk
        line, self.pending = self.pending.split(b"\n", 1)
        return line

    def execute(self, command, arguments=None):
        """Send one command and return its reply."""
        self.sock.sendall(json.dumps({"execute": command,
                                      "arguments": arguments or {}}).encode() + b"\n")
        while True:
            line = self._readline().strip()
            if not line.startswith(b"{"):
                continue
            try:
                reply = json.loads(line.decode())
            except ValueError:
                continue
            if "error" in reply:
                raise RuntimeError("qmp %s failed: %s" % (command, reply.get("error")))
            if "return" in reply:
                return reply
        return None

    def close(self):
        try:
            self.sock.close()
        except Exception:                      # noqa: BLE001
            pass


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
    serial_log = work / "serial.log"
    qmp_sock = work / "qmp.sock"
    cmd = [args.qemu, "-M", "virt,gic-version=3", "-cpu", "cortex-a76",
           "-m", str(RAM_SIZE // (1024 * 1024)), "-smp", str(args.smp),
           "-display", "none", "-no-reboot", "-S", "-gdb", "tcp::1234",
           "-serial", "file:%s" % serial_log,
           # The monitor gets its own socket; stdio is taken by the serial log
           # and QEMU will not share it.
           "-qmp", "unix:%s,server=on,wait=off" % qmp_sock,
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

    # QEMU needs a moment before the gdb port is listening; on a loaded
    # runner with fifteen loader segments that can take a while.
    rsp = None
    deadline = time.time() + 60
    while time.time() < deadline:
        if proc.poll() is not None:
            print("qemu exited before the gdb port opened (rc=%s)" % proc.returncode)
            break
        try:
            rsp = Rsp("127.0.0.1", 1234)
            break
        except OSError:
            time.sleep(1)
    if rsp is None:
        print("could not reach the qemu gdb port")
        try:
            proc.terminate()
        except Exception:                  # noqa: BLE001
            pass
        time.sleep(1)
        if proc.poll() is None:
            proc.kill()
        log.close()
        if qemu_log.is_file():
            (outdir / "qemu-guest-errors.log").write_text(
                qemu_log.read_text(errors="replace"))
        return 1
    rsp.set_register(0, ba_pa)               # x0 = boot_args (physical)
    rsp.set_register(Rsp.REG_PC, entry_pa)   # pc (register 32 on arm64)
    print("registers set: x0=0x%x pc=0x%x" % (ba_pa, entry_pa))
    rsp.cont()

    # The monitor is opened while the guest is still running: once QEMU is
    # terminated there is nobody left to talk to, and the socket file stays
    # behind on the disk.
    qmp = None
    try:
        qmp = Qmp(qmp_sock)
    except Exception as exc:                   # noqa: BLE001
        print("could not open the monitor:", exc)

    deadline = time.time() + args.seconds
    while time.time() < deadline and proc.poll() is None:
        time.sleep(1)

    try:
        if qmp is None:
            raise RuntimeError("no monitor")
        qmp.execute("pmemsave", {"val": FRAMEBUFFER_BASE,
                                  "size": FRAMEBUFFER_PITCH * FRAMEBUFFER_HEIGHT,
                                  "filename": str((outdir / "fb.bin").resolve())})
        # pmemsave writes the file from the monitor thread, so wait for it.
        for _ in range(50):
            if (outdir / "fb.bin").is_file():
                break
            time.sleep(0.2)
    except Exception as exc:               # noqa: BLE001
        print("pmemsave failed:", exc)
        # The console ring is the smaller and more valuable of the two, so it
        # is tried again on its own.  Dumping the whole four gigabytes of
        # guest memory is not an option: the remote refuses a push that
        # carries more than a hundred megabytes, and the artifact would be
        # just as unwelcome.
        try:
            if qmp is None:
                raise RuntimeError("no monitor")
            qmp.execute("pmemsave",
                        {"val": RAMOOPS_CONSOLE, "size": RAMOOPS_RING + 12,
                         "filename": str((outdir / "ramoops.bin").resolve())})
            for _ in range(50):
                if (outdir / "ramoops.bin").is_file():
                    break
                time.sleep(0.2)
            print("the console ring was saved on its own")
        except Exception as exc2:          # noqa: BLE001
            print("the console ring could not be saved:", exc2)

    # The serial port went to a file; it carries whatever the kernel printed
    # before the framebuffer console came up.
    try:
        if serial_log.is_file():
            text = serial_log.read_text(errors="replace")
            (outdir / "serial.log").write_text(text, encoding="utf-8")
            print("serial log: %d bytes" % len(text))
            for ln in [l for l in text.splitlines() if l.strip()][-8:]:
                print("  s| " + ln[:150])
    except Exception as exc:               # noqa: BLE001
        print("serial read failed:", exc)

    # The console ring: plain text, so it can be read as it is.
    try:
        if qmp is None:
            raise RuntimeError("no monitor")
        qmp.execute("pmemsave", {"val": RAMOOPS_CONSOLE,
                                  "size": RAMOOPS_RING + 12,
                                  "filename": str((outdir / "ramoops.bin").resolve())})
        for _ in range(50):
            if (outdir / "ramoops.bin").is_file():
                break
            time.sleep(0.2)
        raw = (outdir / "ramoops.bin").read_bytes()
        sig, start, size = struct.unpack_from("<III", raw, 0)
        if sig == 0x43474244:
            ring = raw[12:12 + min(size or RAMOOPS_RING, RAMOOPS_RING)]
            text = ring.decode("latin1")
            (outdir / "console.txt").write_text(text, encoding="utf-8")
            printable = sum(1 for ch in text if ch.isprintable() or ch in "\r\n\t")
            print("console ring: sig ok, %d bytes, %d printable"
                  % (len(text), printable))
            tail = [ln for ln in text.splitlines() if ln.strip()][-12:]
            for ln in tail:
                print("  | " + ln[:150])
        else:
            print("console ring: signature mismatch (0x%08x)" % sig)
    except Exception as exc:               # noqa: BLE001
        print("ramoops read failed:", exc)

    if qmp is not None:
        qmp.close()

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
