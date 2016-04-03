echo "start"
for i in aa bb
do
    echo $i
    break aa
done
echo for status $?
echo "end"
