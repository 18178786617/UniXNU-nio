#!/usr/bin/env python3
"""Build the pinned ArmCpu with j716f's implemented-range SPI IPI selection."""
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]

def adapt(source):
    marker = '// nio/j716f: choose IPIs inside the implemented GIC range.'
    if marker in source:
        return source
    old = 'static const uint32_t kIpiSpiBase = 1008;'
    if source.count(old) != 1:
        raise RuntimeError('pinned ArmCpu IPI base anchor mismatch')
    source = source.replace(old, 'static uint32_t kIpiSpiBase = 1008;', 1)
    old = '  gFramesSize = redistSize;\n  return true;'
    new = '''  gFramesSize = redistSize;
  // nio/j716f: choose IPIs inside the implemented GIC range.
  const uint32_t lines = ((read32 (dist, 0x4) & 0x1f) + 1) * 32;
  if (lines < 64) { return false; }
  kIpiSpiBase = (lines < 1020 ? lines : 1020) - 8;
  return true;'''
    if source.count(old) != 1:
        raise RuntimeError('pinned ArmCpu mapGic anchor mismatch')
    source = source.replace(old, new, 1)
    if source.count('kIpiSpiBase') != 6:
        raise RuntimeError('IPI configure/send/receive range audit changed')
    return source

if __name__ == '__main__':
    path = ROOT / 'drivers/ArmCpu/ArmCpu.cpp'
    text = adapt(path.read_text())
    path.write_bytes(text.encode())
    subprocess.run([sys.executable, str(ROOT / 'scripts/build-arm-driver.py'), 'ArmCpu'], check=True)
