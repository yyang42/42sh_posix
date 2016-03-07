export aa=1
export bb=1
export cc=2

if [ $aa -eq $bb ] ; then
	echo A_if_text $aa $bb
else
	echo A_else_text $aa $bb
fi

if [ $aa -eq $cc ] ; then
	echo A_if_text $aa $cc
else
	echo A_else_text $aa $cc
fi
