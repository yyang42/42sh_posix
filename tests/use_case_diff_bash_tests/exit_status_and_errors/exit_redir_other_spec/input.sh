echo "before"
echo abc >&50000
echo "before1"
ls >&50000
echo "before2"
echo abc | cat >&50000
echo "after"
