echo "======= 1" >&2
bg

echo "======= 2" >&2
bg x

echo "======= 3" >&2
set -m
bg

echo "======= 4" >&2
set +m
bg
