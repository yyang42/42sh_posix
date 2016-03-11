sleep 10 && echo 1 &> /dev/null &
sleep 10 && echo 2 &> /dev/null &
sleep 10 && echo 3 &> /dev/null &
sleep 10 && echo 4 &> /dev/null &
jobs | sed 's/>\&\/dev/\&> \/dev/g'
