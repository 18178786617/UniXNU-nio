#!/usr/bin/env bash
# ci-prepare.sh -- make the CI build's bootstrap pass survive.
#
# Why this exists (runs 342, 343, 345, 346, 349, 350):
#   The first pass of a new tree links before the archives that define
#   _mockfs_mountroot and _native_verified_block_root_authorized exist, so that
#   link fails by design.  With make -j4 the failure also takes the half-written
#   link.filelist with it, and every archive builder afterwards stops with
#   "No XNU symbol names" -- the round ends with no kernel at all.
#
#   With JOBS=1 the LDFILELIST step finishes before the link runs, the filelist
#   is on the disk, the archives build, and the second pass links the real
#   kernel.
#
# Nothing here may fail the round: the caller runs it with "|| true", it exits 0
# on every path, and it uses a distinctive heredoc terminator so an outer
# heredoc cannot swallow it (that mistake cost two rounds).
#
#   bash device/tools/ci-prepare.sh <workspace-root>
set -u

root=${1:-.}
cd "$root" 2>/dev/null || exit 0

base=$(ls -d out/nio/*/nio 2>/dev/null | head -1)
dest=${base:-out}/logs
mkdir -p "$dest" 2>/dev/null || true
log="$dest/ci-steps.log"
: >"$log" 2>/dev/null || true

note() { printf '%s %s\n' "$(date -u '+%H:%M:%S')" "$*" 2>/dev/null | tee -a "$log" 2>/dev/null; }

note "prepare: started in $(pwd)"

OBJ=out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837
for f in "$OBJ/mach.development.bcm2837.unstripped" "$OBJ/link.filelist" \
         "$OBJ/osfmk/DEVELOPMENT/startup.o" "$OBJ/iokit/DEVELOPMENT/IOService.o"; do
    if [ -f "$f" ]; then
        note "present: $f ($(wc -c <"$f" 2>/dev/null | tr -d ' ') bytes)"
    else
        note "absent : $f"
    fi
done

for s in scripts/build-xnu-4k-baseline.sh out/nio/ios-16.5-20F66/nio/tree/scripts/build-xnu-4k-baseline.sh; do
    if [ ! -f "$s" ]; then
        note "script absent: $s"
        continue
    fi
    if grep -q 'nio: serial bootstrap' "$s" 2>/dev/null; then
        note "already serial: $s"
        continue
    fi
    python3 - "$s" <<'PYIN' 2>&1 | tee -a "$log" 2>/dev/null
import pathlib, sys
path = pathlib.Path(sys.argv[1])
text = path.read_text()
anchor = 'make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 \\\n'
if text.count(anchor) != 1:
    print('anchor count %d in %s -- left alone' % (text.count(anchor), path))
else:
    block = (
        '# nio: serial bootstrap -- with make -j4 the design-failing link takes\n'
        '# the half-written link.filelist with it, and every archive builder\n'
        '# then stops with "No XNU symbol names" (run-350).\n'
        'if [ "${XNU_BOOTSTRAP:-0}" = 1 ]; then JOBS=1; fi\n'
    )
    path.write_text(text.replace(anchor, block + anchor))
    print('serial bootstrap:', path)
PYIN
    if bash -n "$s" 2>/dev/null; then note "syntax ok: $s"; else note "syntax FAILED: $s"; fi
done

note "prepare: done"
exit 0
