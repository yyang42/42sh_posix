for item in aaa bbb ccc
do
	echo ======== $item ========
	echo before $item
    if [ $item = bbb ]
    then
    	echo "condition true"
    	break && echo 111
    fi
    echo after $item
done
