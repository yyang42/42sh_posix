sleep 0.50 && echo 1 &> /dev/null &
sleep 0.50 && echo 2 &> /dev/null &
sleep 0.50 && echo 3 &> /dev/null &
sleep 0.50 && echo 4 &> /dev/null &
jobs -l | sed 's/>\&\/dev/\&> \/dev/g' | sed 's/[[:digit:]]/9/g'
