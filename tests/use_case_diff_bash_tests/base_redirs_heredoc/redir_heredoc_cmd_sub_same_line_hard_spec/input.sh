cat << EOF1; echo $( cat << EOF2; echo $( cat << EOF3;
a1
a2
EOF3
) | cat -e | wc; cat -e <<- EOF4
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
