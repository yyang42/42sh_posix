echo "start"
for i in aa bb
do
    echo $i
    break 1 1
done
echo for status $?
echo "end"
