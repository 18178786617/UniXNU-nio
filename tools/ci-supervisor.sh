#!/usr/bin/env bash
# ci-supervisor.sh -- keep the CI going without anyone watching.
#
#   tools/ci-supervisor.sh [MAX_ROUNDS]
#
# run-393 failed without running a single step: GitHub's macOS arm64 runner
# pool was out of capacity, the job waited fifteen minutes and was cancelled
# ("The job was not acquired by Runner of type hosted even after multiple
# attempts").  run-394, queued on the same image, was cancelled after eight
# minutes.  That looks like a broken tree and is not one, so a round that
# dies without leaving anything behind is not treated as a failure of the
# work: the supervisor moves to the other runner image and starts again.
#
# How a round is judged, without the REST API (api.github.com is answered
# with a 502 by the local proxy, so everything here reads git refs):
#
#   ci-kernel/run-N appears   the kernel built -- the round is done
#   ci-logs/run-N appears     the build ran and failed -- the logs are there
#   neither appears           the job never got a runner, or was cancelled
#                             before it could push anything
#
# The third case is the one this script exists for.  It re-runs the round on
# the other image, because the two images sit in different capacity pools.
#
# A cancelled round leaves no branch at all, so the next round's number
# cannot be predicted from the last one.  The supervisor therefore watches
# for any branch above the highest number it has seen, and the round it is
# waiting for is the one the next push creates.
#
# It stops after MAX_ROUNDS so it cannot spin for ever, and it writes what it
# did to the handoff diary.
set -u
cd /e/nio-unixnu-port || exit 1

MAX_ROUNDS=${1:-12}
# How long to wait for a round before deciding it never got a runner.  A
# successful round takes thirteen to sixteen minutes, and a cancelled one is
# cut off after eight to fifteen, so this has to sit above both.
WAIT_MIN=${WAIT_MIN:-26}
LOG=out/ci-supervisor.log
DIARY="C:/Users/Administrator/Desktop/nio-移植交接说明-2026-11-14.txt"
REPO=device/UniXNU-nio

# The two images that build this kernel.  macos-26 is the pair upstream
# develops against and is the fast one when it is scheduled; macos-15 is the
# same architecture and the same build in a different capacity pool.  Intel
# is deliberately not in the list: it works, but a round takes over twenty
# minutes there.
IMAGES=(macos-26 macos-15)

say() { printf '[%s] %s\n' "$(date +%H:%M:%S)" "$*" | tee -a "$LOG"; }

note() {
    {
        printf '\n  **%s ci-supervisor 自动续跑**\n' "$(date '+%H:%M')"
        printf '      %s\n' "$*"
    } >>"$DIARY"
}

refs() { ( cd "$REPO" && git ls-remote origin 2>/dev/null ); }

# The highest round number that has left a branch behind.
highest_seen() {
    refs | sed -n 's#.*refs/heads/ci-\(kernel\|logs\)/run-\([0-9][0-9]*\)$#\2#p' |
        sort -n | tail -1
}

switch_image() {
    # Put $1 in the workflow's runner default.  The value appears twice: the
    # dispatch input's default and the job's fallback expression.
    local want="$1" have
    have=$(grep -m1 "default: \"macos" "$REPO/.github/workflows/kernel.yml" |
           sed 's/.*"\(macos[^"]*\)".*/\1/')
    if [ "$have" = "$want" ]; then
        say "the runner image is already $want"
        return 0
    fi
    say "switching the runner image: $have -> $want"
    python3 - "$REPO/.github/workflows/kernel.yml" "$have" "$want" <<'PY'
import pathlib, sys
path, have, want = sys.argv[1], sys.argv[2], sys.argv[3]
p = pathlib.Path(path)
t = p.read_text(encoding="utf-8")
t = t.replace('default: "%s"' % have, 'default: "%s"' % want)
t = t.replace("|| '%s' }}" % have, "|| '%s' }}" % want)
p.write_text(t, encoding="utf-8")
print("runner default is now", want)
PY
    ( cd "$REPO" &&
      git add .github/workflows/kernel.yml &&
      git commit -q -m "ci: build on $want

The macOS arm64 pool ran out of capacity: run-393 was cancelled before it ran
a single step ('The job was not acquired by Runner of type hosted even after
multiple attempts') and run-394, queued on the same image, was cut off after
eight minutes.  $have and $want are the same architecture and the same build,
but they sit in different capacity pools, so a round that never started is a
round to re-run on the other image rather than a failure of the tree." &&
      git push origin main 2>&1 | tail -1 ) | tee -a "$LOG"
}

# Wait for a branch above $1 to appear.  Echoes "kernel <n>", "logs <n>" or
# fails when nothing turns up in time.
wait_for_round() {
    local floor="$1" limit="$2" i=0 r now
    while [ "$i" -lt $((limit * 2)) ]; do
        r=$(refs)
        now=$(printf '%s\n' "$r" |
              sed -n 's#.*refs/heads/ci-\(kernel\|logs\)/run-\([0-9][0-9]*\)$#\2#p' |
              sort -n | tail -1)
        if [ -n "$now" ] && [ "$now" -gt "$floor" ]; then
            if printf '%s\n' "$r" | grep -q "refs/heads/ci-kernel/run-$now\$"; then
                echo "kernel $now"
                return 0
            fi
            echo "logs $now"
            return 0
        fi
        i=$((i + 1))
        sleep 30
    done
    return 1
}

FLOOR=$(highest_seen)
say "the highest round with a branch is ${FLOOR:-none}"
image_index=0
rounds=0

while [ "$rounds" -lt "$MAX_ROUNDS" ]; do
    rounds=$((rounds + 1))
    current=${IMAGES[$image_index]}
    say "round $rounds of $MAX_ROUNDS on $current: waiting for anything above run-${FLOOR:-0}"

    result=$(wait_for_round "$FLOOR" "$WAIT_MIN")
    if [ -n "$result" ]; then
        kind=${result%% *}
        num=${result##* }
        FLOOR=$num
        if [ "$kind" = "kernel" ]; then
            say "run-$num produced a kernel"
            bash tools/round-image.sh "$num" >>"$LOG" 2>&1 && say "packaged run-$num"
            note "run-$num 成功产出内核并已打包（镜像 $current）；本次自动续跑 $rounds 次。"
            exit 0
        fi
        say "run-$num ran and failed; its logs are on the branch"
        note "run-$num 真正跑了并失败，日志分支已存在（镜像 $current），等人来读。"
        exit 2
    fi

    say "nothing appeared in ${WAIT_MIN}m: the job never got a runner"

    if [ "$rounds" -ge "$MAX_ROUNDS" ]; then
        note "连续 $rounds 轮都没排上 runner（在 $current 上），停止自动续跑，等人决定。"
        exit 3
    fi

    # Move to the other image: same architecture, same build, different
    # capacity pool.  The push starts the next round.
    image_index=$(( (image_index + 1) % ${#IMAGES[@]} ))
    next=${IMAGES[$image_index]}
    switch_image "$next"
    note "上一轮在 $current 上没排上 runner，已切到 $next 重推。"
done

say "giving up after $rounds rounds"
exit 3
