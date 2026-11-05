#!/usr/bin/env python3
"""Read a phone-screen recording of a boot log and cut the text out of it.

WHY THIS SCRIPT EXISTS

The only way to see what the kernel printed on the phone is the phone's own
screen, filmed. The film is 720x1280, shot by hand, out of focus: the text
is there but it is small, soft, and it moves because the hand moves. Reading
it by eye from a contact sheet does not work; three tricks do.

  1. Pick the sharpest frame, not the first one. The Laplacian variance of
     the text region is a good enough proxy for focus: the frames where the
     camera has locked on score much higher than the ones before or after.
  2. Sharpen before reading. An unsharp mask (g*2.6 - blur*1.6) recovers
     the edges that the focus threw away.
  3. Cut by text lines, not by fixed coordinates. The camera drifts, so a
     rectangle that was right in one frame is wrong in the next. A horizontal
     projection of the bright pixels finds where the lines actually are in
     THIS frame, and the lines are then cut out and enlarged one by one.

The script prints the line bands it found and writes each one as its own
file, so the reader can be asked about one line at a time -- a full screen of
blurry text is much harder to read than a single sharp line.

    python3 tools/screen-log.py recording.mp4 --out out/screen
    python3 tools/screen-log.py recording.mp4 --out out/screen --at 9.1

Note that the ffmpeg on some machines is built without the image encoders
(png, jpg, rawvideo); OpenCV is used here instead, which needs none of them.
"""

import argparse
import os
import sys

try:
    import cv2
    import numpy as np
except ImportError:
    sys.exit("this script needs opencv-python and numpy")

# The console text is bright on a dark background; this is the threshold that
# separates the glyphs from the background on the recordings taken so far.
BRIGHT = 150
# A line is a line if this many pixels in the row are above the threshold.
MIN_PIXELS = 15


def sharpen(frame, amount=2.6):
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    blur = cv2.GaussianBlur(gray, (0, 0), 2.0)
    return cv2.addWeighted(gray, amount, blur, -(amount - 1.0), 0)


def line_bands(gray, bright=BRIGHT, min_pixels=MIN_PIXELS):
    """The rows that hold text, grouped into bands, one band per line."""
    rows = (gray > bright).astype("uint8").sum(axis=1)
    ys = [y for y, n in enumerate(rows) if n > min_pixels]
    bands = []
    previous = -5
    for y in ys:
        if y - previous > 3:
            bands.append([y, y])
        else:
            bands[-1][1] = y
        previous = y
    return bands


def main():
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("video", help="the recording of the screen")
    parser.add_argument("--out", default="out/screen", help="where to write the cuts")
    parser.add_argument("--at", type=float, default=None,
                        help="the second to read (default: the sharpest frame)")
    parser.add_argument("--lines", type=int, default=12, help="how many lines to cut")
    parser.add_argument("--scale", type=float, default=6.0, help="enlargement factor")
    parser.add_argument("--x0", type=int, default=55, help="left edge of the text")
    parser.add_argument("--x1", type=int, default=660, help="right edge of the text")
    args = parser.parse_args()

    capture = cv2.VideoCapture(args.video)
    if not capture.isOpened():
        sys.exit("cannot open " + args.video)
    fps = capture.get(cv2.CAP_PROP_FPS) or 30.0

    frames = []
    while True:
        ok, frame = capture.read()
        if not ok:
            break
        frames.append(frame)
    if not frames:
        sys.exit("no frames")
    print("%d frames, %.2f fps, %.2f s" % (len(frames), fps, len(frames) / fps))

    if args.at is not None:
        index = int(args.at * fps)
    else:
        # The sharpest frame: the text region is the top of the screen.
        best = (-1.0, 0)
        for i, frame in enumerate(frames):
            region = cv2.cvtColor(frame[100:400, 50:700], cv2.COLOR_BGR2GRAY)
            variance = cv2.Laplacian(region, cv2.CV_64F).var()
            if variance > best[0]:
                best = (variance, i)
        index = best[1]
        print("sharpest frame: %d (t=%.2f, variance=%.0f)" % (index, index / fps, best[0]))

    frame = frames[index]
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    bands = line_bands(gray)
    if not bands:
        sys.exit("no text found in this frame")
    print("%d text lines, y=%d..%d" % (len(bands), bands[0][0], bands[-1][1]))

    os.makedirs(args.out, exist_ok=True)
    sharp = sharpen(frame)
    for k, (y0, y1) in enumerate(bands[:args.lines]):
        cut = sharp[max(0, y0 - 3):y1 + 3, args.x0:args.x1]
        path = os.path.join(args.out, "line_%02d.png" % k)
        cv2.imwrite(path, cv2.resize(cut, None, fx=args.scale, fy=args.scale,
                                     interpolation=cv2.INTER_LANCZOS4))
        print("  line %02d  y=%d..%d -> %s" % (k, y0, y1, path))

    # The whole text region as well, for the overall picture.
    whole = sharp[max(0, bands[0][0] - 4):bands[-1][1] + 4, args.x0:args.x1]
    cv2.imwrite(os.path.join(args.out, "all.png"),
                cv2.resize(whole, None, fx=args.scale / 2, fy=args.scale / 2,
                           interpolation=cv2.INTER_LANCZOS4))
    print("  all -> %s" % os.path.join(args.out, "all.png"))


if __name__ == "__main__":
    main()
