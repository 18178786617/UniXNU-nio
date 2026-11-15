#!/usr/bin/env python3
"""Replay the recorded compile of one object and compare it with the tree's copy.

Why: run-362 proved the compiler reads the patched startup.c (the #error at
line 2 fired), yet every round's startup.o carries _nio_heartbeat_thread and no
"nio: HB " literal.  Either the object in the tree is overwritten after the
compile, or the recorded command is not what produced it.

Usage: replay-compile.py <device-work-dir> <log-dir> [object-relative-path]

<device-work-dir> is out/<board>/<os>/<config>; the object defaults to
osfmk/DEVELOPMENT/startup.o.
"""
import json
import pathlib
import shlex
import subprocess
import sys

OBJ_ROOT = 'tree/build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837'
DEFAULT = 'osfmk/DEVELOPMENT/startup.o'


def decode_all(raw):
    """clang -MJ writes one JSON object per target, back to back."""
    dec = json.JSONDecoder()
    idx = 0
    while idx < len(raw):
        while idx < len(raw) and raw[idx] in ' \n\r\t':
            idx += 1
        if idx >= len(raw):
            return
        try:
            entry, idx = dec.raw_decode(raw, idx)
        except ValueError:
            return
        yield entry


def main(argv):
    base = pathlib.Path(argv[1] if len(argv) > 1 else '.').resolve()
    logdir = pathlib.Path(argv[2] if len(argv) > 2 else base / 'logs')
    rel = argv[3] if len(argv) > 3 else DEFAULT
    objroot = base / OBJ_ROOT
    tree_obj = objroot / rel
    record = tree_obj.with_suffix('.o.json')
    replay = pathlib.Path('/tmp') / ('nio-replay-' + tree_obj.name)
    lines = []
    cargv = None

    def say(text):
        lines.append(str(text))
        print(text, flush=True)

    say('base=%s' % base)
    say('record=%s exists=%s' % (record, record.is_file()))
    say('tree object=%s exists=%s' % (tree_obj, tree_obj.is_file()))

    entry = next(iter(decode_all(record.read_text(errors='replace'))), None) if record.is_file() else None
    if not entry:
        say('no decodable compile record; nothing to replay')
    else:
        cmd = entry.get('command')
        cargv = entry.get('arguments')
        if cargv:
            cargv = list(cargv)
        elif cmd:
            cargv = shlex.split(cmd)
        else:
            cargv = None
        say('recorded file=%s output=%s' % (entry.get('file'), entry.get('output')))
        if not cargv:
            say('record has neither arguments nor command')
        else:
            if '-o' in cargv:
                cargv[cargv.index('-o') + 1] = str(replay)
            else:
                cargv += ['-o', str(replay)]
            say('replaying %d arguments in %s' % (len(cargv), tree_obj.parent))
            try:
                proc = subprocess.run(cargv, cwd=str(tree_obj.parent),
                                      capture_output=True, text=True, timeout=900)
                say('replay rc=%d' % proc.returncode)
                if proc.returncode != 0:
                    say('replay stderr tail: %s' % (proc.stderr or '')[-400:])
            except Exception as exc:                     # noqa: BLE001
                say('replay failed: %s' % exc)

    # Ask the preprocessor directly: if the line survives -E, the compiler must
    # emit it (and the object's silence is a codegen question); if it does not,
    # the line is commented out or behind a condition on this base commit.
    if cargv:
        pre = [a for a in cargv if a != '-c']
        if '-o' in pre:
            i = pre.index('-o')
            del pre[i:i + 2]
        pre += ['-E', '-o', '/tmp/nio-replay-startup.i']
        try:
            proc = subprocess.run(pre, cwd=str(tree_obj.parent),
                                  capture_output=True, text=True, timeout=900)
            say('preprocess rc=%d' % proc.returncode)
            ipath = pathlib.Path('/tmp/nio-replay-startup.i')
            if ipath.is_file():
                body = ipath.read_bytes()
                say('preprocessed bytes=%d has HB=%s' % (len(body), b'nio: HB ' in body))
                say('preprocessed bytes=%d has hb-started=%s'
                    % (len(body), b'nio: hb thread started' in body))
        except Exception as exc:                         # noqa: BLE001
            say('preprocess failed: %s' % exc)

    if replay.is_file() and tree_obj.is_file():
        a = replay.read_bytes()
        b = tree_obj.read_bytes()
        say('replay bytes=%d tree bytes=%d identical=%s' % (len(a), len(b), a == b))
        say('replay has HB=%s tree has HB=%s' % (b'nio: HB ' in a, b'nio: HB ' in b))
        say('replay sha=%s tree sha=%s'
            % (__import__('hashlib').sha256(a).hexdigest()[:16],
               __import__('hashlib').sha256(b).hexdigest()[:16]))
    else:
        say('replay object missing=%s' % (not replay.is_file()))

    logdir.mkdir(parents=True, exist_ok=True)
    (logdir / 'replay.log').write_text('\n'.join(lines) + '\n')
    return 0


if __name__ == '__main__':
    raise SystemExit(main(sys.argv))
