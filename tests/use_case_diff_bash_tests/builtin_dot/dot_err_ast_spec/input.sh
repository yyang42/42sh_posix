cat << EOF > /tmp/test_builtin_dot_script.sh
()
EOF

{
	. /tmp/test_builtin_dot_script.sh
} &> /tmp/test_builtin_dot_stderr

echo dot_status_code $?
cat /tmp/test_builtin_dot_stderr | sed -e 's/.*input\.sh/CMD_PATH/g'
