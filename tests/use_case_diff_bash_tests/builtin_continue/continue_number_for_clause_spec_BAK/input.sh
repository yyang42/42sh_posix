foo () {
	break_nbr=$1
	for outerloop in 1 2 3 4 5
	do
		echo -n Group $outerloop

		# --------------------------------------------------------
		for innerloop in 1 2 3 4 5
		do
			echo -n $innerloop

			if [ $innerloop -eq 3 ]
			then
				continue  $break_nbr # Try   break 2   to see what happens.
				     # ("Breaks" out of both inner and outer loops.)
			fi
		done
		# --------------------------------------------------------

		echo
	done

	echo
}
echo "========== 1"
foo 1
echo "========== 2"
foo 2
echo "========== 3"
foo 3
echo "========== 4"
foo 4
echo "========== 99"
foo 99
