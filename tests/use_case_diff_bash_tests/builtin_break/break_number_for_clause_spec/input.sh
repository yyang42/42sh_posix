foo () {
	for outerloop in 1 2 3 4 5
	do
		echo -n Group $outerloop

		# --------------------------------------------------------
		for innerloop in 1 2 3 4 5
		do
			echo -n $innerloop

			if [ $innerloop -eq 3 ]
			then
				break  $1 # Try   break 2   to see what happens.
				     # ("Breaks" out of both inner and outer loops.)
			fi
		done
		# --------------------------------------------------------

		echo
	done

	echo
}
foo 1
foo 2
foo 3
