"""Symbol names of the XNU kernel of a build tree, for the archives that must not collide with it.

nio override: identical to the UniXNU framework copy, with one addition. When
neither the checkpoint kernel nor link.filelist exists (the bootstrap link
intentionally fails and make removes its half-written filelist — runs
771/773/777/779), fall back to the symbol-name list exported once from this
board's own green 21H461 kernel and committed as xnu-kernel-symbols.txt next to
this script. Symbol names are stable for the same kernelcache, so this is the
same set the filelist would have supplied.
"""
import subprocess
from pathlib import Path

OBJ = 'build/xnu/ios-obj/DEVELOPMENT_ARM64_BCM2837'


def defined_names(paths, global_only):
    """Defined symbol names of Mach-O files and archives."""
    names = set()
    paths = [str(path) for path in paths]
    for start in range(0, len(paths), 200):
        command = ['xcrun', 'nm', *(['-g'] if global_only else []), '-U', '-j', *paths[start:start + 200]]
        names |= {line.strip() for line in subprocess.check_output(command, text=True).splitlines() if line.startswith('_')}
    return names


def kernel_names(root, global_only=True):
    """Names of the XNU kernel alone: checkpoint, else link.filelist, else the
    committed symbol-name list for this board's kernelcache."""
    root = Path(root)
    checkpoint = root / 'build/xnu/checkpoints/native-4k-user-abi/kernel.macho'
    if checkpoint.is_file():
        return defined_names([checkpoint], global_only)
    filelist = root / OBJ / 'link.filelist'
    if filelist.is_file():
        # A pass whose compile failed leaves its filelist naming objects it did not produce; the next pass rebuilds them and its
        # link sees them, so only the objects that exist are read here.
        objects = [line.strip() for line in filelist.read_text().splitlines() if line.strip()]
        names = defined_names([path for path in objects if Path(path).is_file()], global_only)
        # The link also exports aliases (all-alias.exp: "_real _alias") that no object defines under that name.
        aliases = root / OBJ / 'all-alias.exp'
        if aliases.is_file():
            names |= {word for line in aliases.read_text().splitlines() for word in line.split() if word.startswith('_')}
        return names
    # Fallback: committed symbol names of this board's green kernel.
    fixture = Path(__file__).resolve().parent / 'xnu-kernel-symbols.txt'
    if fixture.is_file():
        return {line.strip() for line in fixture.read_text().splitlines() if line.startswith('_')}
    raise SystemExit('No XNU symbol names: run a kernel pass first (it writes link.filelist)')
