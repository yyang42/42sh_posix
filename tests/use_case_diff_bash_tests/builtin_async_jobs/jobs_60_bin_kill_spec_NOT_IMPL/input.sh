sleep 2 &
pid=`jobs -p`
/bin/kill $pid
