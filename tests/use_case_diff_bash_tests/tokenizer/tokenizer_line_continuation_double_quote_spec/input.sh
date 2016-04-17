echo '======= case 1'
echo "aa\
bb"

echo '======= case 2'
echo "complementary cases"
echo $( echo a\
b
)

echo '======= case 3'
echo "a\
b"

echo '======= case 4'
echo 'a
b'

echo '======= case 5'
echo "'a\
b'"

echo '======= case 6'
echo a\\
echo b

echo '======= case 7'
echo "$(echo a\\
echo b\
echo c\\
printf d)"
