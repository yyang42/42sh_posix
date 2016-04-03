for item in aaa bbb ccc
do
    echo $item case ========================================================
    echo "outer before continue"
    if [ $item = bbb ]
    then
        echo "inner before continue"
        continue
        echo "inner after continue"
    fi
    echo "outer after continue"
done
