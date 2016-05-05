echo "==========1"
set 111 222 333
echo $@

echo "==========2"
set -e 111 -e 333
echo $@

echo "==========3"
set -
set --
set -- aaa bbb ccc
echo $@

echo "==========4"
set -- aaa -e ccc
echo $@

# echo "==========5"
# set -- -e -e mmm nnn
# echo $@

echo "==========6"
set -- aa
echo $@

echo "==========7"
set aa bb -- -e
echo $@

# echo "==========8"
# set -- -e
# echo $@
false
echo "should not print this"
