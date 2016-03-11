sleep 0.2 && echo AA &> /dev/null &
sleep 0.2 && echo BB &> /dev/null &
sleep 0.2 && echo CC &> /dev/null &
mypid=`jobs -p | head -1`
kill -9 $mypid
jobs
jobs
