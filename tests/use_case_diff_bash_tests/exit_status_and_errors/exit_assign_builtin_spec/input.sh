foo()
{
cmd=$1
echo "=== test $cmd"

cat << EOF > /tmp/test_exit_builtin_file
echo "before"
readonly myvar
myvar=bb $cmd
echo "after"
EOF

$TESTED_SHELL /tmp/test_exit_builtin_file
echo
}

foo .
foo :
foo alias
foo break
foo continue
foo env
foo eval
