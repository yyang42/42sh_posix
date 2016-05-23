(
	echo '======1'
	exec 43<&42 # 42 not valid
	echo '======2'
) &> /tmp/builtin_exec_stdrr
cat /tmp/builtin_exec_stdrr | sed -e 's/.*input\.sh/CMD_PATH/g'
