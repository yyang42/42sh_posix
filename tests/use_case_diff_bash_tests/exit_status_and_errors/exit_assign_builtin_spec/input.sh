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
foo break
foo cd
foo continue
foo echo
foo env
foo eval
foo export
foo false
foo jobs
foo readonly
foo return
foo set
foo shift
foo times
foo trap
foo true
foo umask
foo unset
foo wait

# not testable
# foo bg
# foo fg
# foo kill
# foo read
# foo setenv
# foo unsetenv
