cat << EOF1; echo $( cat << EOF2; echo $( cat << EOF3;
a1
a2
EOF3
) | cat -e | wc; cat <<- EOF4 | cat -e; echo `cat <<- EOF5; printf "$( cat << EOF6
BB
AA
$(cat << EOF7
$(cat << EOF8
DD
EOF8
)
EOF7
)
CC
EOF6
)" | sort
	tab eeeee1
		tab x2 eeeee2
EOF5
`
bb1
bb2
EOF2
dddd1
dddd2
EOF4
) | cat -e
ccc1
ccc2
EOF1
