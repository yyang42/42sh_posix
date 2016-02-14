if find . | grep 123 && grep /; then
    echo 123
    ls /
elif cond2; then
    cat /tmp/bla
else
	echo fromelse
	echo fromelse1
fi
