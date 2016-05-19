echo "====== test 1"
echo abc | \
cat -e | \
wc

echo "====== test 2"
echo aa\\\\\
bb

echo "====== test 3"
echo aa\\\\\
bb \\\
cc

echo "====== test 4"
echo 'aa\
bb'

echo "====== test 5"
echo 'aa\\
bb'

echo "====== test 6"
echo 'aa\\\
bb'

echo "====== test 7"
echo \''aa\\\
bb'\'
