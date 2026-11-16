#!/usr/bin/env python3
"""Render the nio port progress board.

Reads progress/state.json and writes a self-contained HTML page (and a
markdown mirror) so the state of the port can be read at a glance instead of
dug out of the handoff diary.

    render-progress.py [--state progress/state.json]
                       [--html ~/Desktop/nio-进度看板.html]
                       [--md   ~/Desktop/nio-进度看板.md]
"""

import argparse
import html
import json
import pathlib

STATUS = {
    "done": ("已完成", "done"),
    "current": ("进行中", "current"),
    "todo": ("未开始", "todo"),
    "blocked": ("受阻", "blocked"),
}

CSS = """
:root { color-scheme: light dark; }
* { box-sizing: border-box; }
body { margin: 0; padding: 32px 28px 56px;
       font: 15px/1.65 "PingFang SC", "Microsoft YaHei", "Noto Sans CJK SC", system-ui, sans-serif;
       background: #f6f7f9; color: #16181d; }
h1 { font-size: 22px; margin: 0 0 4px; letter-spacing: .2px; }
.updated { color: #6b7280; font-size: 13px; margin-bottom: 22px; }
.headline { background: #fff; border: 1px solid #e3e6ea; border-left: 4px solid #d97706;
            border-radius: 8px; padding: 14px 16px; margin-bottom: 14px; font-size: 15px; }
.distance { background: #eef4ff; border: 1px solid #cfdcff; border-radius: 8px;
            padding: 11px 16px; margin-bottom: 26px; font-size: 14px; }
h2 { font-size: 15px; margin: 30px 0 10px; color: #3f4652; font-weight: 600; }
.rail { display: flex; gap: 8px; flex-wrap: wrap; margin-bottom: 18px; }
.step { flex: 1 1 150px; min-width: 150px; background: #fff; border: 1px solid #e3e6ea;
        border-radius: 8px; padding: 12px 13px; }
.step .id { font-weight: 700; font-size: 13px; color: #6b7280; }
.step .name { font-size: 14px; margin: 3px 0 8px; }
.step.current { border-color: #d97706; box-shadow: 0 0 0 2px rgba(217,119,6,.12); }
.badge { display: inline-block; font-size: 12px; padding: 1px 8px; border-radius: 999px; }
.badge.done { background: #e7f6ec; color: #157347; }
.badge.current { background: #fdf0dc; color: #a35b06; }
.badge.todo { background: #eef0f3; color: #5b6472; }
.badge.blocked { background: #fdeaea; color: #b02a2a; }
table { width: 100%; border-collapse: collapse; background: #fff;
        border: 1px solid #e3e6ea; border-radius: 8px; overflow: hidden; font-size: 13.5px; }
th, td { text-align: left; padding: 9px 12px; border-bottom: 1px solid #eceef1; vertical-align: top; }
th { background: #f2f4f7; font-weight: 600; color: #3f4652; }
tr:last-child td { border-bottom: none; }
code { background: #eef0f3; padding: 1px 5px; border-radius: 4px; font-size: 12.5px;
       font-family: "Cascadia Mono", Consolas, monospace; }
.phase { background: #fff; border: 1px solid #e3e6ea; border-radius: 8px;
         padding: 13px 15px; margin-bottom: 10px; }
.phase .head { display: flex; align-items: center; gap: 10px; margin-bottom: 6px; }
.phase .pid { font-weight: 700; }
.phase .pname { font-size: 15px; }
.kv { font-size: 13.5px; color: #444b57; margin: 3px 0; }
.kv b { color: #16181d; font-weight: 600; }
ul { margin: 6px 0 0; padding-left: 20px; }
li { margin: 3px 0; }
.notes li { color: #4b5361; font-size: 13.5px; }
@media (prefers-color-scheme: dark) {
  body { background: #14161a; color: #e6e8ec; }
  .headline, .step, table, .phase { background: #1c1f24; border-color: #2c3138; }
  .distance { background: #1b2432; border-color: #2b3a52; }
  th { background: #22262c; color: #c7ccd4; }
  th, td { border-color: #2a2e35; }
  code, .badge.todo { background: #262a31; color: #c9ced6; }
  .kv b, .phase .pid { color: #e6e8ec; }
  .kv, .notes li { color: #b6bcc6; }
  h2 { color: #aeb4be; }
}
"""


def render(state):
    phases = state.get("phases", [])
    rounds = state.get("rounds", [])

    rail = []
    for p in phases:
        label, cls = STATUS.get(p.get("status"), ("未开始", "todo"))
        rail.append(
            '<div class="step %s"><div class="id">%s</div><div class="name">%s</div>'
            '<span class="badge %s">%s</span></div>'
            % (cls, html.escape(p["id"]), html.escape(p["name"]), cls, label))

    phase_rows = []
    for p in phases:
        label, cls = STATUS.get(p.get("status"), ("未开始", "todo"))
        phase_rows.append(
            '<div class="phase"><div class="head"><span class="pid">%s</span>'
            '<span class="pname">%s</span><span class="badge %s">%s</span></div>'
            '<div class="kv"><b>判据：</b>%s</div>'
            '<div class="kv"><b>证据：</b>%s</div>'
            '<div class="kv"><b>下一步：</b>%s</div></div>'
            % (html.escape(p["id"]), html.escape(p["name"]), cls, label,
               html.escape(p.get("criteria", "")), html.escape(p.get("evidence", "")),
               html.escape(p.get("next", ""))))

    round_rows = []
    for r in rounds:
        round_rows.append(
            "<tr><td><code>run-%s</code></td><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>"
            % (html.escape(str(r.get("run", ""))), html.escape(str(r.get("time", ""))),
               html.escape(str(r.get("marker", ""))), html.escape(str(r.get("qemu", ""))),
               html.escape(str(r.get("result", "")))))

    actions = "".join("<li>%s</li>" % html.escape(a) for a in state.get("next_actions", []))
    notes = "".join("<li>%s</li>" % html.escape(n) for n in state.get("notes", []))

    return """<!doctype html>
<html lang="zh-CN"><head><meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>nio 移植进度看板</title><style>%s</style></head><body>
<h1>nio iOS 移植 · 进度看板</h1>
<div class="updated">%s · 更新于 %s</div>
<div class="headline"><b>当前：</b>%s</div>
<div class="distance">%s</div>
<h2>阶段总览</h2>
<div class="rail">%s</div>
<h2>各阶段详情</h2>
%s
<h2>最近的 CI 轮次</h2>
<table><tr><th>轮次</th><th>时间</th><th>标记</th><th>QEMU</th><th>结果</th></tr>%s</table>
<h2>接下来的动作</h2>
<ul>%s</ul>
<h2>纪律与备注</h2>
<ul class="notes">%s</ul>
</body></html>
""" % (CSS, html.escape(state.get("device", "nio")), html.escape(state.get("updated", "")),
       html.escape(state.get("headline", "")),
       html.escape(state.get("distance", "")), "".join(rail), "".join(phase_rows),
       "".join(round_rows), actions, notes)


def render_md(state):
    out = ["# nio 移植进度看板", "", "设备：%s" % state.get("device", "nio"),
           "更新于 %s" % state.get("updated", ""), "",
           "**当前：** %s" % state.get("headline", ""), "",
           "%s" % state.get("distance", ""), "", "## 阶段", ""]
    for p in state.get("phases", []):
        label, _ = STATUS.get(p.get("status"), ("未开始", "todo"))
        out += ["### %s %s — %s" % (p["id"], p["name"], label),
                "", "- 判据：%s" % p.get("criteria", ""),
                "- 证据：%s" % p.get("evidence", ""),
                "- 下一步：%s" % p.get("next", ""), ""]
    out += ["## 最近的 CI 轮次", "", "| 轮次 | 时间 | 标记 | QEMU | 结果 |",
            "|---|---|---|---|---|"]
    for r in state.get("rounds", []):
        out.append("| run-%s | %s | %s | %s | %s |" % (
            r.get("run", ""), r.get("time", ""), r.get("marker", ""),
            r.get("qemu", ""), r.get("result", "")))
    out += ["", "## 接下来的动作", ""]
    out += ["- %s" % a for a in state.get("next_actions", [])]
    out += ["", "## 纪律与备注", ""]
    out += ["- %s" % n for n in state.get("notes", [])]
    return "\n".join(out) + "\n"


def main(argv=None):
    here = pathlib.Path(__file__).resolve().parent
    root = here.parent
    ap = argparse.ArgumentParser()
    ap.add_argument("--state", type=pathlib.Path, default=root / "progress" / "state.json")
    ap.add_argument("--html", type=pathlib.Path,
                    default=pathlib.Path.home() / "Desktop" / "nio-进度看板.html")
    ap.add_argument("--md", type=pathlib.Path,
                    default=pathlib.Path.home() / "Desktop" / "nio-进度看板.md")
    args = ap.parse_args(argv)

    state = json.loads(args.state.read_text(encoding="utf-8"))
    args.html.parent.mkdir(parents=True, exist_ok=True)
    args.html.write_text(render(state), encoding="utf-8")
    args.md.write_text(render_md(state), encoding="utf-8")
    print("wrote %s and %s" % (args.html, args.md))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
