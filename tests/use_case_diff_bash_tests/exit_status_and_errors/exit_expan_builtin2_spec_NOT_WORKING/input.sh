foo() (
cmd=$1
echo "=== test $cmd"
: > /tmp/test_exit_builtin_file
cat << EOF > /tmp/test_exit_builtin_file
echo "before"
$cmd ${x!y}
echo "after"
EOF

$TESTED_SHELL /tmp/test_exit_builtin_file
sleep 0.1
) &>/tmp/test_exit_builtin_file_stderr
cat /tmp/test_exit_builtin_file_stderr | sed -e 's/.*input\.sh/CMD_PATH/g'

foo .
foo :
foo alias
foo echo

# foo bg
# foo break
# foo cd
# foo continue
# foo env
# foo eval
# foo export
# foo false
# foo fg
# foo jobs
# foo kill
# foo read
# foo readonly
# foo return
# foo set
# foo setenv
# foo shift
# foo times
# foo trap
# foo true
# foo umask
# foo unset
# foo unsetenv
# foo wait
