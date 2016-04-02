(
	exec 43<&42 # 42 not valid
	echo 'should not exec'
) &> /tmp/builtin_exec_stdrr
echo exit_code: $?
cat /tmp/builtin_exec_stdrr | sed -e 's/.*input\.sh/CMD_PATH/g'
