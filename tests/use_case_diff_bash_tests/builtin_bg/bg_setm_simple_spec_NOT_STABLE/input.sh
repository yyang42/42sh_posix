set -m
sleep 0.1 && echo abc &
sleep 0.1 && echo abc &
sleep 0.1 && echo abc &
sleep 0.1 && echo abc &
kill -TSTP %1
kill -TSTP %2
kill -TSTP %3
bg %1
bg %2
bg %3
wait
