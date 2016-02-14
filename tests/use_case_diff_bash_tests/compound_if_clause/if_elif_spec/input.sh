if true ; then
	echo A_if_text
elif true ; then
	echo A_elif_text
fi

if false ; then
	echo B_if_text
elif true ; then
	echo B_elif_text
fi

if false ; then
	echo C_if_text
elif false ; then
	echo C_elif_1_text
elif true ; then
	echo C_elif_2_text
fi
