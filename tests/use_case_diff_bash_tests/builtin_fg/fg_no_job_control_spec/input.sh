echo "======= 1" >&2
fg

echo "======= 2" >&2
fg x
fg %1
fg %+

echo "======= 3" >&2
set -m
fg

echo "======= 4" >&2
set +m
fg
