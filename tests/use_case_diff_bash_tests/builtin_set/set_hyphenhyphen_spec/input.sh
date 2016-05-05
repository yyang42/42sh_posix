echo "========1"
set -- -a b c
echo $@
echo "========2"
set -e -- -a b c
echo $@
