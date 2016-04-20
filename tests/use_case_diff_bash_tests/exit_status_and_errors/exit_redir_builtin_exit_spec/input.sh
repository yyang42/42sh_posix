foo()
{
cmd=$1
echo "=== test $cmd"
cat << EOF > /tmp/test_exit_builtin_file
echo "before"
$cmd < /tmp/blabla_not_exist
echo "after"
EOF
$TESTED_SHELL /tmp/test_exit_builtin_file
echo
}

foo exec
