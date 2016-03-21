{
	sleep 0.2 &
	kill -31 $(jobs -p) ; sleep 0.2; sleep 0.2
} 2>&1 | sed -E 's/[0-9]+ Terminated/<PID> Terminated/g' | sed -e 's/.*input\.sh/<CMD_PATH>/g'
