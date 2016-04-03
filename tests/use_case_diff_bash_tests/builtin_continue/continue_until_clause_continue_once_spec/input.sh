counter=0
until false
do
	echo "start" $counter
	counter=`echo $counter + 1 | bc`
	if [ $counter -gt 5 ]
	then
		break
	fi
	if [ $counter -gt 3 ]
	then
		continue
	fi
	echo "end" $counter
done
