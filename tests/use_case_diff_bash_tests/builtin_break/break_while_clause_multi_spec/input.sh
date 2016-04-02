# Same loop, but substituting 'break' for 'continue'.

test_fn () {
	counter=0
	break_nbr=$1
	echo
	echo $break_nbr "< break_nbr ==========="
	while true
	do
		marker=outer
		echo "outer start" $marker $counter
		while true
		do
			marker=inner
			echo "inner start" $marker $counter
			counter=`echo $counter + 1 | bc`
			if [ $counter -gt 3 ]
			then
				break $break_nbr # Skip entire rest of loop.
			fi
			echo "inner end" $marker $counter
		done
		if [ $counter -gt 5 ]
		then
			break  # Skip entire rest of loop.
		fi
		echo "outer end" $marker $counter
	done

}
test_fn 1
test_fn 2
test_fn 3
test_fn 99
