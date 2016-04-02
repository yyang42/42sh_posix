test_fn () {
	counter_outer=4
	continue_nbr=$1
	echo
	echo $continue_nbr "< continue_nbr ==========="
	until [ $counter_outer -eq 0 ]
	do
		counter_outer=`echo " " $counter_outer - 1 | bc`
		echo "outer start" $counter_outer
		counter_inner=4
		until [ $counter_inner -eq 0 ]
		do
			counter_inner=`echo " " $counter_inner - 1 | bc`
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
