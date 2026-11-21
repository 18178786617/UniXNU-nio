#!/usr/bin/env bash
# ci-prepare.sh -- instrument and repair the CI kernel build's first pass.
#
# What has been established, run by run:
#   * the tree ships a kernel, so make skips the link (run-337 .. 341);
#   * with make -j4 the design-failing link kills the half-written
#     link.filelist, and every archive builder stops with "No XNU symbol
#     names" (run-342 .. 350);
#   * startup.c carries the patch and the startup.o the link uses does not,
#     at 113,592 bytes in every round, and it comes back byte-identical after
#     being deleted and after the whole object tree was cleared (run-353 ..
#     355).  So the object is restored, not compiled -- but nothing so far
#     says by what.
#
# This script therefore does two things: it makes the bootstrap pass serial and
# clears the objects, and it records when the object appears, with its size and
# digest, into out/<board>/<os>/<config>/logs/xnu-trace.log.  That log is
# collected and published, so the next round can say "the object existed before
# make" or "it appeared during make" without anyone reading the Actions UI.
#
# It exits 0 on every path and the caller runs it with "|| true": preparation
# may never cost a round.  The heredoc terminator is PYIN on purpose -- a
# nested PY swallowed two rounds.
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
    if grep -q 'nio: trace startup.o' "$s" 2>/dev/null; then
        note "already instrumented: $s"
        continue
    fi
    python3 - "$s" <<'PYIN' 2>&1 | tee -a "$log" 2>/dev/null
import pathlib, sys

path = pathlib.Path(sys.argv[1])
text = path.read_text()

trace_def = (
    '\n# nio: trace startup.o -- when it exists, how big, which digest.  The object\n'
    '# comes back byte-identical after deletion (run-354, 355), so something lays\n'
    '# it down; this says whether that happens before or during make.\n'
    'NIO_TRACE=${PWD}/../logs/xnu-trace.log\n'
    'nio_sha() { if command -v shasum >/dev/null 2>&1; then shasum -a 256 "$1" | cut -c1-16; elif command -v sha256sum >/dev/null 2>&1; then sha256sum "$1" | cut -c1-16; else echo nosha; fi; }\n'
    'nio_trace() {\n'
    '  _o=${PWD}/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o\n'
    '  {\n'
    '    printf "[%s] %s (bootstrap=${XNU_BOOTSTRAP:-0} jobs=${JOBS:-unset})\\n" "$(date -u +%H:%M:%S)" "$1"\n'
    '    if [ -f "$_o" ]; then\n'
    '      printf "  object %s bytes sha %s\\n" "$(wc -c <"$_o" | tr -d " ")" "$(nio_sha "$_o")"\n'
    '    else\n'
    '      echo "  object MISSING"\n'
    '    fi\n'
    '    if [ -f .cache/xnu-work/osfmk/kern/startup.c ]; then\n'
    '      printf "  source sha %s\\n" "$(nio_sha .cache/xnu-work/osfmk/kern/startup.c)"\n'
    '    fi\n'
    '  } >> "$NIO_TRACE" 2>&1\n'
    '}\n'
    'nio_trace "script start"\n'
)

early_anchor = 'BOOTSTRAP=${XNU_BOOTSTRAP:-0}\n'
if text.count(early_anchor) == 1:
    text = text.replace(early_anchor, early_anchor + trace_def, 1)
    print('traced script start:', path)
else:
    print('early anchor count %d -- trace not installed' % text.count(early_anchor))

make_anchor = 'make -C .cache/xnu-work "${XNU_BUILD_TARGET:-build}" SDKROOT="${XNU_SDKROOT:-iphoneos}" ARCH_CONFIGS=ARM64 \\\n'
if text.count(make_anchor) != 1:
    print('make anchor count %d -- repairs not installed' % text.count(make_anchor))
    path.write_text(text)
    raise SystemExit(0)

before = (
    '# nio: serial bootstrap -- with make -j4 the design-failing link takes\n'
    '# the half-written link.filelist with it, and every archive builder\n'
    '# then stops with "No XNU symbol names" (run-350).\n'
    'if [ "${XNU_BOOTSTRAP:-0}" = 1 ]; then JOBS=1; fi\n'
    '# nio: this series changes exactly two compiler units; drop them so make\n'
    '# cannot take the seed copy for current.\n'
    'rm -f "$ROOT/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/osfmk/DEVELOPMENT/startup.o" \\\n'
    '      "$ROOT/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/iokit/DEVELOPMENT/IOService.o" \\\n'
    '      "$ROOT/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/bsd/DEVELOPMENT/bsd_init.o" \\\n'
    '      "$ROOT/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/bsd/DEVELOPMENT/kern_exec.o" \\\n'
    '      "$ROOT/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837/bsd/DEVELOPMENT/kern_fork.o" 2>/dev/null || true\n'
    '# nio: in the bootstrap pass clear every object and compile record, keeping\n'
    '# the kernel binary and link.filelist that the LDFILELIST step reads.\n'
    'if [ "${XNU_BOOTSTRAP:-0}" = 1 ]; then\n'
    '\tfind "$ROOT/build/xnu/ios-obj" -type f \\( -name "*.o" -o -name "*.cpo" -o -name "*.o.json" \\) \\\n'
    '\t    -delete 2>/dev/null || true\n'
    '\techo "nio: cleared every object for the bootstrap pass"\n'
    'fi\n'
    'nio_trace "before make"\n'
)
text = text.replace(make_anchor, before + make_anchor, 1)

after_anchor = 'if [ "${XNU_SOURCE_CORECRYPTO14:-0}" = 1 ] && [ "$CRYPTO_BOOTSTRAP_MODE" = source ]; then\n'
if text.count(after_anchor) == 1:
    text = text.replace(after_anchor, 'nio_trace "after make"\n' + after_anchor, 1)
    print('traced before/after make:', path)
else:
    print('after anchor count %d -- only the before trace installed' % text.count(after_anchor))

path.write_text(text)
PYIN
    if bash -n "$s" 2>/dev/null; then note "syntax ok: $s"; else note "syntax FAILED: $s"; fi
done

note "prepare: done"
exit 0
