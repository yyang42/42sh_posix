for item in aaa bbb ccc
do
    echo item $item
    if [ $item = bbb ]
    then
        echo "condition true"
        break -1
    fi
done
