#!/usr/bin/env bash
# Check that everything the packaging needs is in place, and say what is
# missing.
#
# Why this exists: on 2026-11-17 the cleanup removed two directories that
# looked like build products and were not.  out/ci-repro/unixnu/scripts/
# held the entry probe that puts the console blob in the kernel, and
# out/volsrc/ held the three files the payload volume is made of.
# Both were recovered -- the probe from this repository's own
# scripts/console directory, because the upstream copy returns three
# values where the packaging expects four, and the volume files out of
# the payload FAT that was still on disk -- but the packaging failed
# twice before it was whole again, and neither failure was obvious from
# the message.
#
# So the inputs are checked before the packaging runs, and the check says
# which file is missing and where it comes from.
#
#   bash tools/check-packaging-inputs.sh
#
# Exits 0 when everything is there, 1 otherwise.
set -u

ROOT=$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)
cd "$ROOT" || exit 1

missing=0

# path | where it comes from when it is missing
need_file() {
    if [ -f "$1" ]; then
        printf '  ok      %s\n' "$1"
    else
        printf '  MISSING %s\n           from: %s\n' "$1" "$2"
        missing=$((missing + 1))
    fi
}

need_dir() {
    if [ -d "$1" ]; then
        printf '  ok      %s/\n' "$1"
    else
        printf '  MISSING %s/\n           from: %s\n' "$1" "$2"
        missing=$((missing + 1))
    fi
}

echo "== the payload volume =="
need_file out/volsrc/UNIXNU.EFI   "out/payload-ram.fat, extracted with the FAT32 reader in tools/make-payload-vol.sh"
need_file out/volsrc/NIOHELLO.EFI "out/payload-ram.fat, same way"
need_file out/volsrc/PAYLOAD.TXT  "out/payload-ram.fat, same way"

echo
echo "== the console blob =="
need_file out/ci-repro/unixnu/scripts/patch-xnu-entry-probe.py \
    "device/UniXNU-nio/scripts/console/patch-xnu-entry-probe.py -- the four-value one; the upstream copy in refs/UniXNU returns three values and does not match"
need_file out/ci-repro/unixnu/scripts/xnu-panic-screen.c \
    "device/UniXNU-nio/scripts/console/xnu-panic-screen.c -- the 116 KB one; the copy in refs/UniXNU is 9 KB and is stale"

echo
echo "== the root volume =="
need_file out/userdata/userdata-root.img  "tools/build-userdata.py, from ios165/"
need_file out/userdata/userdata-root.json "tools/build-userdata.py, same way"

echo
echo "== the kernel and its device tree =="
need_file out/nio.adt            "tools/make-nio-adt.py"
need_file out/kernel.macho        "the round's kernel, plus the console blob"
need_file out/kernel.macho.adt    "a copy of out/nio.adt"
need_file out/payload-ram.fat     "tools/make-payload-vol.sh"

echo
echo "== the repository =="
need_file device/UniXNU-nio/rootfs/rootfs.img
need_file device/UniXNU-nio/package/unixnu.toml
need_dir  device/UniXNU-nio/patches/xnu-8796
need_file device/UniXNU-nio/patches/xnu-8796/series
need_file device/UniXNU-nio/patches/darwinboot/console-guard.patch

echo
echo "== the sources and the toolchain =="
need_dir refs/UniXNU
need_dir refs/ShengUfs
need_dir refs/UniXNU-umi
need_dir refs/UniXNU-sheng
need_dir refs/Adreno650
need_dir .tmp
need_dir toolchain
need_dir build/uefi-umi

echo
if [ "$missing" -gt 0 ]; then
    echo "$missing item(s) missing; the packaging will not run."
    exit 1
fi
echo "everything the packaging needs is in place."
