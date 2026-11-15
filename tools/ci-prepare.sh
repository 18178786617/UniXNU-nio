#!/usr/bin/env bash
# ci-prepare.sh -- make the CI build compile this round's sources and link them.
#
# The tree arrives with a kernel and objects already built, and make takes them
# for current: run-344's fingerprint showed the patched startup.c carrying
# "nio: HB " while the startup.o the linker reads did not.  Everything here
# exists to break that, and nothing here may fail the round: the caller runs
# this with "|| true" as well.
#
# Run it locally the same way to test it:
#   bash device/tools/ci-prepare.sh <workspace-root>
#
# What it does, in order, and why:
#   1. reports the artifacts the tree carries (kernel, link.filelist, the two
#      objects this round's patches change);
#   2. deletes ONLY those objects (never the kernel, never link.filelist:
#      run-342/343 lost a round to removing the kernel, which the LDFILELIST
#      step reads);
#   3. ages the prebuilt kernel to 2000-01-01 so make links this round's objects,
#      in every copy of the build script that exists.
set -u

root=${1:-.}
cd "$root" 2>/dev/null || exit 0

base=$(ls -d out/nio/*/nio 2>/dev/null | head -1)
dest=${base:-out}/logs
mkdir -p "$dest" 2>/dev/null || true
log="$dest/ci-steps.log"
mkdir -p "$dest" 2>/dev/null || true
: >"$log" 2>/dev/null || true

note() { printf '%s %s\n' "$(date -u '+%H:%M:%S')" "$*" 2>/dev/null | tee -a "$log" 2>/dev/null; }

note "prepare: started in $(pwd)"

OBJ=out/nio/ios-16.5-20F66/nio/tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837
KERNEL=$OBJ/mach.development.bcm2837.unstripped
FILELIST=$OBJ/link.filelist

for f in "$KERNEL" "$FILELIST" "$OBJ/osfmk/DEVELOPMENT/startup.o" "$OBJ/iokit/DEVELOPMENT/IOService.o"; do
    if [ -f "$f" ]; then
        note "present: $f ($(wc -c <"$f" 2>/dev/null | tr -d ' ') bytes)"
    else
        note "absent : $f"
    fi
done

# 2. Only the objects this round's patches change.  Deleting them costs two
#    compiles and cannot break the filelist step.
for o in "$OBJ/osfmk/DEVELOPMENT/startup.o" "$OBJ/iokit/DEVELOPMENT/IOService.o" \
         "$OBJ/osfmk/DEVELOPMENT/startup.o.json"; do
    if [ -f "$o" ]; then
        rm -f "$o" 2>/dev/null && note "removed: $o" || note "could not remove: $o"
    fi
done

# 3. Age the prebuilt kernel in every copy of the build script.
for s in scripts/build-xnu-4k-baseline.sh out/nio/ios-16.5-20F66/nio/tree/scripts/build-xnu-4k-baseline.sh; do
    [ -f "$s" ] || { note "script absent: $s"; continue; }
    if grep -q 'nio: age the prebuilt kernel' "$s" 2>/dev/null; then
        note "already aged: $s"
        continue
    fi
    python3 - "$s" <<'PY' 2>&1 | tee -a "$log" 2>/dev/null
import pathlib, sys
path = pathlib.Path(sys.argv[1])
text = path.read_text()
anchor = 'make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 \\\n'
if text.count(anchor) != 1:
    print('anchor count %d in %s -- left alone' % (text.count(anchor), path))
else:
    age = (
        '# nio: age the prebuilt kernel so make links this round\'s objects\n'
        'touch -t 200001010000 "$ROOT/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/mach.development.bcm2837.unstripped" 2>/dev/null || true\n'
    )
    path.write_text(text.replace(anchor, age + anchor))
    print('aged:', path)
PY
done

note "prepare: done"
exit 0
