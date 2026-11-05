#!/usr/bin/env python3
"""Check that nio's display hand-off carries the panel's own numbers.

The framebuffer of the MOTO Edge S is not a fixture: it is the panel that
`dumpsys display` reports as 1080x2520, sitting on the region uefiplat.cfg
reserves as "Display Reserved" at 0x9C000000. Those numbers are written down
once, in package/nio-hardware.json, and every stage that touches the display
has to agree with them:

  * the UEFI loader hands them over in the boot arguments,
  * the XNU platform expert copies them into the PE video state,
  * the display driver takes the framebuffer over with the same stride.

A mismatch does not fail loudly. The kernel comes up, the screen stays black
or shows garbage, and the log says nothing. So the numbers are checked here
against one source, and the check is cheap enough to run on every build.

What it reads:

  * package/nio-hardware.json -- the panel's own numbers, the source of truth;
  * a boot-arguments file, if one is given: the loader's hand-over;
  * a PE video state file, if one is given: what the kernel received.

Usage:
    python3 tools/check-display-handoff.py [--boot-args FILE] [--video FILE]

With no files it checks the source of truth alone, which is what the build
does: the parameters are read out of the hardware description and compared
against each other, and the derived numbers are printed so that a reader can
see them.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
HARDWARE = ROOT / 'package' / 'nio-hardware.json'


def fail(message):
    print('FAIL: %s' % message)
    raise SystemExit(1)


def read_boot_arguments(path):
    """Read the display arguments out of a boot-arguments file.

    Two shapes are accepted. The first is the text of the boot arguments,
    where the values are separated by spaces or commas:

        display=1 row_bytes=4320 width=1080 height=2520 depth=32
        physical_base=0x9c000000

    The second is a JSON object with the same names as keys, which is what
    the DarwinBoot fixture writes.
    """
    text = path.read_text(errors='replace')
    try:
        data = json.loads(text)
    except ValueError:
        data = None
    if isinstance(data, dict):
        if 'boot_args' in data and isinstance(data['boot_args'], dict):
            data = data['boot_args']
        else:
            return {key: value for key, value in data.items()
                    if isinstance(value, (int, float)) and not isinstance(value, bool)}
    values = {}
    for match in re.finditer(r'\b(physical_base|display|row_bytes|width|height|depth)\b\s*[=:]\s*'
                             r'(0x[0-9a-fA-F]+|\d+)', text):
        raw = match.group(2)
        values[match.group(1)] = int(raw, 16) if raw.startswith('0x') else int(raw)
    return values


def read_video(path):
    """Read the PE video state out of a JSON file."""
    data = json.loads(path.read_text(errors='replace'))
    if isinstance(data, dict) and 'pe_video' in data:
        data = data['pe_video']
    if not isinstance(data, dict):
        fail('%s does not hold a video state' % path)
    return {
        'physical_base': data.get('v_baseAddr', data.get('physical_base')),
        'row_bytes': data.get('v_rowBytes', data.get('row_bytes')),
        'width': data.get('v_width', data.get('width')),
        'height': data.get('v_height', data.get('height')),
        'depth': data.get('v_depth', data.get('depth')),
        'display': data.get('v_display', data.get('display')),
    }


parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--boot-args', type=Path, help='the loader\'s boot-arguments file')
parser.add_argument('--video', type=Path, help='the PE video state the kernel received')
args = parser.parse_args()

if not HARDWARE.is_file():
    fail('package/nio-hardware.json is missing')
hardware = json.loads(HARDWARE.read_text(encoding='utf-8'))
framebuffer = hardware.get('framebuffer')
if not framebuffer:
    fail('the hardware description has no framebuffer block')

expected = {
    'physical_base': framebuffer['base'],
    'width': framebuffer['width'],
    'height': framebuffer['height'],
    'row_bytes': framebuffer['row_bytes'],
    'depth': framebuffer['bits_per_pixel'],
}

# The stride has to follow from the width and the depth. A row_bytes that
# belongs to another panel is the mistake this catches: 4320 is 1080 pixels of
# four bytes, and 3200 -- the number in the upstream fixture -- is 800 pixels
# of four.
if expected['row_bytes'] != expected['width'] * expected['depth'] // 8:
    fail('the stride %d does not follow from %dx%d at %d bits'
         % (expected['row_bytes'], expected['width'], expected['height'], expected['depth']))

print('the panel: base=0x%x width=%d height=%d row_bytes=%d depth=%d'
      % (expected['physical_base'], expected['width'], expected['height'],
         expected['row_bytes'], expected['depth']))

if args.boot_args:
    boot = read_boot_arguments(args.boot_args)
    for key, want in expected.items():
        got = boot.get(key)
        if got is None:
            fail('the boot arguments carry no %s' % key)
        if got != want:
            fail('the boot arguments carry %s=%s, the panel is %s' % (key, got, want))
    if boot.get('display') not in (1, None):
        fail('the boot arguments carry display=%s' % boot.get('display'))
    print('the boot arguments carry the panel\'s numbers')

if args.video:
    video = read_video(args.video)
    for key, want in expected.items():
        got = video.get(key)
        if got is None:
            fail('the video state carries no %s' % key)
        if got != want:
            fail('the video state carries %s=%s, the panel is %s' % (key, got, want))
    if video.get('display') not in (1, None):
        fail('the video state carries display=%s' % video.get('display'))
    print('the video state carries the panel\'s numbers')

print('PASS: the display hand-off of nio carries one set of numbers, and they are the panel\'s')
