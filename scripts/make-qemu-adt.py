#!/usr/bin/env python3
"""Build the device tree the QEMU harness boots with.

The real device gets its tree from DarwinBoot, which describes the nio
hardware: Qualcomm's GIC at 0x17980000, PSCI over SMC, DRAM at 0x80000000.
QEMU virt has none of that, so this script builds the same tree against
package/nio-qemu-hardware.json: the virt GIC, PSCI over HVC, and 4 GiB of RAM
at 0x40000000.

The tree format is the same AppleDT the kernel already parses on the phone;
nothing about the format changes, only the numbers.

    make-qemu-adt.py --output out/kernel.macho.adt
"""

import argparse
import json
import pathlib
import sys

HERE = pathlib.Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))

from nio_adt import build_tree  # noqa: E402

PROFILE = HERE.parent / "package" / "nio-qemu-hardware.json"


def main(argv=None):
    parser = argparse.ArgumentParser()
    parser.add_argument("--output", type=pathlib.Path, required=True)
    parser.add_argument("--dram-size", type=lambda v: int(v, 0), default=0x100000000)
    args = parser.parse_args(argv)

    hardware = json.loads(PROFILE.read_text())
    dram_size = args.dram_size
    total = sum(bank["size"] for bank in hardware["memory_banks"])
    if dram_size != total:
        raise SystemExit("--dram-size 0x%x does not match the profile's 0x%x"
                         % (dram_size, total))

    tree = build_tree(hardware, dram_size=dram_size,
                      cpu_regs=tuple(range(len(hardware["cpus"]))),
                      psci_method=hardware["psci"]["method"])
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(tree.encode())
    print("wrote %s (%d bytes) from %s"
          % (args.output, args.output.stat().st_size, PROFILE.name))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
