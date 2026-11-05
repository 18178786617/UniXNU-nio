#!/usr/bin/env python3
"""Generate nio's Apple-format ADT sidecar, without device I/O.

Implements the UniXNU payload ADT CLI. Hardware addresses come from nio's own
measured profile (package/nio-hardware.json). The OS identity -- the model,
the board name, the product table, the buttons, the defaults -- comes from the
OS profile the board names, read out of the same profile.toml the upstream
payload step reads, and the board's own adt section is laid over it. That is
the upstream merge: the profile is the base, the board wins on a conflict.

The --ipad-identity flag is the older 17.7.11 bring-up identity (iPad7,1 /
J120). The 16.5 profile carries its own identity (iPhone10,3 / D22) and does
not need it.
SPDX-License-Identifier: BSD-2-Clause-Patent
"""
import argparse
import hashlib
import json
import tomllib
from pathlib import Path

from nio_adt import (apply_platform, build_tree, decode, hardware_path,
                     load_hardware, summary)

HERE = Path(__file__).resolve().parent
REPO = HERE.parent


def merge(base, overlay):
    """The upstream merge: the overlay wins, and a table is merged key by key."""
    result = dict(base)
    for key, value in overlay.items():
        if isinstance(value, dict) and isinstance(result.get(key), dict):
            result[key] = merge(result[key], value)
        else:
            result[key] = value
    return result


def load_platform(profile):
    """The adt section of the OS profile, with the board's own adt over it."""
    board = tomllib.loads((REPO / "board.toml").read_text())
    board_adt = board.get("adt", {})
    if profile is None:
        name = board.get("board", {}).get("os_profile")
        if not name:
            raise ValueError("the board names no OS profile")
        profile = REPO / "os-profiles" / name / "profile.toml"
    profile = Path(profile)
    if not profile.is_file():
        raise ValueError("the OS profile is not there: %s" % profile)
    adt = tomllib.loads(profile.read_text()).get("adt", {})
    return merge(adt, board_adt), profile


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--dram-size", type=lambda v: int(v, 0), required=True)
    parser.add_argument("--owned-memory-size", type=lambda v: int(v, 0))
    parser.add_argument("--root-match-volume-uuid")
    parser.add_argument("--unique-chip-id", type=lambda v: int(v, 16))
    parser.add_argument("--chip-id", type=lambda v: int(v, 16))
    parser.add_argument("--cpu-regs", default=None,
                        help="the CPUs the ADT describes; default is every CPU "
                             "the hardware profile lists")
    parser.add_argument("--psci-method", choices=("smc", "hvc"), default="smc")
    parser.add_argument("--profile", type=Path,
                        help="the OS profile to read the identity from; "
                             "default is the one board.toml names")
    parser.add_argument("--no-profile", action="store_true",
                        help="do not read the OS profile; the tree keeps nio's own identity")
    data = parser.add_mutually_exclusive_group()
    data.add_argument("--data-ramdisk", action="store_true")
    data.add_argument("--packed-data-ramdisk", action="store_true")
    parser.add_argument("--trust-cache", action="store_true")
    parser.add_argument("--ipad-identity", action="store_true",
                        help="sheng's iPad7,1 / 21H461 userspace compatibility profile")
    args = parser.parse_args()
    try:
        hardware = load_hardware()
        platform = {}
        profile_name = None
        if not args.no_profile:
            platform, profile_path = load_platform(args.profile)
            profile_name = profile_path.name
        # The board runs eight cores and the ADT describes all of them: the
        # upstream payload step takes them from the hardware device tree, and
        # the hardware profile here is the same eight. One CPU is a bring-up
        # measurement, not the shape of the machine.
        if args.cpu_regs is None:
            cpu_regs = tuple(cpu["affinity"] for cpu in hardware["cpus"])
        else:
            cpu_regs = tuple(int(v, 0) for v in args.cpu_regs.split(","))
        tree = build_tree(
            hardware, dram_size=args.dram_size,
            cpu_regs=cpu_regs,
            psci_method=args.psci_method, owned_memory_size=args.owned_memory_size,
            root_match_volume_uuid=args.root_match_volume_uuid,
            unique_chip_id=args.unique_chip_id, chip_id=args.chip_id,
            data_ramdisk=args.data_ramdisk, packed_data_ramdisk=args.packed_data_ramdisk,
            trust_cache=args.trust_cache, ipad_identity=args.ipad_identity)
        if platform:
            apply_platform(tree, platform)
        blob = tree.encode()
        decoded = decode(blob)
        if decoded.encode() != blob:
            raise ValueError("ADT round-trip differs")
    except (ValueError, KeyError) as error:
        parser.error(str(error))
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(blob)
    # Private binary includes fresh entropy and an optional software identity.
    args.output.chmod(0o600)
    report = {
        "format": "Apple device tree (not FDT)", "device": "nio",
        "adt_sha256": hashlib.sha256(blob).hexdigest(), "bytes": len(blob),
        "hardware_profile_sha256": hashlib.sha256(hardware_path().read_bytes()).hexdigest(),
        "hardware_sources": hardware["sources"], **summary(decoded),
        "os_profile": profile_name,
        "roundtrip_verified": True, "hardware_tested": False,
        "memory_window_requires_firmware_validation": True,
        "limitations": [
            "No nio attempt has reached XNU yet; this ADT alone proves nothing about firmware handoff.",
            "dram-size must equal the measured bank total, not the 8 GiB soldered capacity.",
            "Framebuffer is handed over from GOP in boot_args, not initialized by this ADT.",
            "No GPU/touch hardware driver nodes; the OS identity is a userspace compatibility input.",
        ],
    }
    args.output.with_name(args.output.name + ".json").write_text(json.dumps(report, indent=2) + "\n")
    identity = tree.properties.get("model", b"").rstrip(b"\0").decode("ascii", "replace")
    print(f"nio ADT: {len(blob)} bytes; {len(tree.at('/cpus').children)} CPU(s); "
          f"GIC {report['gic_distributor']}/{report['gic_redistributor']}; "
          f"model {identity}; host-validated only")


if __name__ == "__main__":
    main()
