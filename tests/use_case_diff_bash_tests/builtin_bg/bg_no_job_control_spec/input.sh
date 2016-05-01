echo "======= 1" >&2
bg

echo "======= 2" >&2
bg x
bg %1
bg %+

echo "======= 3" >&2
set -m
bg

echo "======= 4" >&2
set +m
bg
