foo()
{
cmd=$1
echo "=== test $cmd"

cat << EOF > /tmp/test_exit_builtin_file
echo "before"
readonly myvar
myvar=bb $cmd > /dev/null
echo "after"
EOF

$TESTED_SHELL /tmp/test_exit_builtin_file
echo
}

foo .
foo :
foo alias
# foo bg
foo break
foo cd
foo continue
foo echo
foo env
foo eval
foo export
foo false
# foo fg
foo jobs
# foo kill
# foo read
foo readonly
foo return
foo set
# foo setenv
foo shift
foo times
foo trap
foo true
foo umask
foo unset
# foo unsetenv
foo wait
