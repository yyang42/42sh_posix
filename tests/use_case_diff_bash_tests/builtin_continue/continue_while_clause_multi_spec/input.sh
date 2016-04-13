test_fn () {
	counter_outer=4
	continue_nbr=$1
	echo
	echo $continue_nbr "< continue_nbr ==========="
	while [ $counter_outer -gt 0 ]
	do
		counter_outer=$((counter_outer-1))
		echo "outer start" $counter_outer
		counter_inner=4
		while [ $counter_inner -gt 0 ]
		do
			counter_inner=$((counter_inner-1))
			echo "inner start" $counter_inner
			if [ $counter_inner -lt 2 ]
			then
				continue $continue_nbr
			fi
			echo "inner end  "
		done
		echo "outer end  "
	done

}
test_fn 1
test_fn 2
test_fn 3
test_fn 4
