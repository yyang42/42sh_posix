sleep 2 & mypid=`jobs -p`
kill -TSTP $mypid
jobs
jobs
kill -CONT $mypid
jobs
jobs
