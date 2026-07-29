#!/usr/bin/env bash
#
# pack_for_web.sh -- pack this mudlib into a playable static browser bundle
# (WebAssembly FluffOS + web terminal), for GitHub Pages.
#
# Usage: scripts/pack_for_web.sh <driver_dir> <out_dir>
#   <driver_dir>  dir containing fluffos.js/fluffos.wasm/telnet.js/vendor/
#                 (an extracted fluffos release *-wasm.zip)
#   <out_dir>     output dir (created), ready to publish as a Pages site root
#
# Modeled on fluffos/mudlibs' scripts/pack_lib_for_web.sh, simplified for a
# single mudlib per repo (no multi-lib site index, so the driver files sit
# directly alongside index.html instead of a shared ../_driver/).
#
# Unlike most other fluffos/* mudlib repos, this repo's mudlib root IS the
# repo root itself (config.ini: "mudlib directory : ."), so staging is just
# "every git-tracked file except scripts/ and .github/" -- no lib/ subdir
# to select, and no separate gitignored-runtime-dir recreation pass either,
# since every runtime dir here (data/user, data/login, log, backup, tmp,
# temp, adm/tmp, adm/log, log/static) already ships a tracked nested
# .gitignore placeholder that git ls-files picks up on its own.
#
# Requires: emscripten's file_packager (emsdk on PATH), python3.

set -euo pipefail
set -x   # trace every command -- see fluffos/nightmare3's pack_for_web.sh
         # for why (CI-only failures need a diagnosable trail even without
         # repo-admin log access).
note() { echo "::notice::pack_for_web: $*"; }

SELF_DIR=$(cd "$(dirname "$0")" && pwd)
REPO_ROOT=$(cd "$SELF_DIR/.." && pwd)

if [ $# -ne 2 ]; then
  echo "usage: $0 <driver_dir> <out_dir>" >&2
  exit 2
fi

DRIVER_DIR=$(cd "$1" && pwd)
OUT=$2
mkdir -p "$OUT"
OUT=$(cd "$OUT" && pwd)   # must be absolute -- see nightmare3's pack_for_web.sh:
                          # step 4 below cd's into $STAGE first, so a relative
                          # $OUT would resolve against the stage dir instead
                          # of the caller's cwd.
[ -f "$DRIVER_DIR/fluffos.js" ] && [ -f "$DRIVER_DIR/fluffos.wasm" ] || {
  echo "error: driver not found in $DRIVER_DIR (need fluffos.js + fluffos.wasm)" >&2; exit 1; }
[ -f "$DRIVER_DIR/index.html" ] || { echo "error: $DRIVER_DIR/index.html not found" >&2; exit 1; }

FILE_PACKAGER=""
if command -v file_packager >/dev/null; then
  FILE_PACKAGER="file_packager"
else
  EMCC_PATH=$(command -v emcc || true)
  for c in "${EMCC_PATH:+$(dirname "$EMCC_PATH")/tools/file_packager.py}" \
           /usr/share/emscripten/tools/file_packager.py; do
    if [ -n "$c" ] && [ -f "$c" ]; then FILE_PACKAGER="python3 $c"; break; fi
  done
fi
[ -n "$FILE_PACKAGER" ] || { echo "error: emscripten file_packager not found (emsdk on PATH?)" >&2; exit 1; }
note "using FILE_PACKAGER=[$FILE_PACKAGER]"

STAGE=$(mktemp -d "${TMPDIR:-/tmp}/xkx100pack.XXXXXX")
trap 'chmod -R u+w "$STAGE" >/dev/null 2>&1 || true; rm -rf "$STAGE" 2>/dev/null || true' EXIT
note "staging in $STAGE"

# --- 1. stage the mudlib tree (every git-tracked file except scripts/ and
#        .github/, which aren't part of the mudlib) -------------------------
# -z + read -d '' avoids git's default C-quoting of non-ASCII/special
# filenames (this repo has plenty of Chinese filenames) -- with plain
# `git ls-files` + `read -r`, those paths arrive as literal quoted/escaped
# strings (e.g. "doc/bbs\345\220\210\351\233\206/ptz.txt") instead of real
# paths, and every cp on one fails.
mkdir -p "$STAGE/mudlib"
FILE_COUNT=0
while IFS= read -r -d '' rel; do
  dst="$STAGE/mudlib/$rel"
  mkdir -p "$(dirname "$dst")"
  cp "$REPO_ROOT/$rel" "$dst"
  FILE_COUNT=$((FILE_COUNT + 1))
done < <(cd "$REPO_ROOT" && git ls-files -z -- . ':!scripts' ':!.github')
note "step 1 done: staged $FILE_COUNT tracked files"

# --- 2. rewrite the config's mudlib directory to the in-image path and pack
#        it INSIDE the mudlib tree itself (the driver chdir()s to whatever
#        "mudlib directory" says relative to ITS OWN cwd, not the config
#        file's location, so the original "." only worked by coincidence
#        when driver and config shared a cwd -- it must be an absolute
#        in-image path here) --------------------------------------------
python3 - "$REPO_ROOT/config.ini" "$STAGE/mudlib/mudlib.cfg" <<'PYEOF'
import re, sys
src, dst = sys.argv[1], sys.argv[2]
text = open(src, encoding='utf-8', errors='surrogateescape').read()
text, n1 = re.subn(r'^(\s*mudlib directory\s*:\s*).*$', r'\g<1>/mudlib', text, flags=re.M)
if n1 != 1:
    sys.exit('error: expected exactly one "mudlib directory :" line, found %d' % n1)
open(dst, 'w', encoding='utf-8', errors='surrogateescape').write(text)
PYEOF
note "step 2 done: wrote mudlib.cfg"

# --- 3. pack with file_packager ---------------------------------------------
(cd "$STAGE" && $FILE_PACKAGER "$OUT/mudlib.data" \
    --preload "mudlib@/mudlib" \
    --js-output="$OUT/mudlib.js")
note "step 3 done: file_packager produced $OUT/mudlib.data + mudlib.js"

# --- 4. boot config + driver + page -----------------------------------------
cat > "$OUT/fluffos-boot.js" <<EOF
// Generated by scripts/pack_for_web.sh -- consumed by index.html.
window.FLUFFOS_BOOT = {
  mount: "/mudlib",
  config: "mudlib.cfg",
};
EOF
cp "$DRIVER_DIR/fluffos.js" "$DRIVER_DIR/fluffos.wasm" "$DRIVER_DIR/telnet.js" "$OUT/"
cp -r "$DRIVER_DIR/vendor" "$OUT/"
cp "$DRIVER_DIR/index.html" "$OUT/index.html"
note "step 4 done: driver + page copied into $OUT"

SIZE=$(du -sh "$OUT" | cut -f1)
echo "packed xkx100 -> $OUT ($SIZE)"
