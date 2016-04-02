(
	# exec 43<&0 # valid
	echo '======1'
	exec 43<&42 # 42 not valid
	echo '======2'
	# exec 7777<&0 # 7777 not valid
	# echo '======3'
) &> /tmp/builtin_exec_stdrr
cat /tmp/builtin_exec_stdrr | sed -e 's/.*input\.sh/CMD_PATH/g'
