echo abc > /tmp/test_builtin_colon_file
echo "=====1"
cat /tmp/test_builtin_colon_file
: > /tmp/test_builtin_colon_file
echo "=====2"
cat /tmp/test_builtin_colon_file
echo "=====3"
