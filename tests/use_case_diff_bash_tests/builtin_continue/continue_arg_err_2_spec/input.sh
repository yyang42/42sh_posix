test_fn () {
    continue_nbr=$1
    echo ==================== test_case $continue_nbr
    for item in aaa bbb ccc
    do
        echo item $item
        if [ $item = bbb ]
        then
            echo "condition true"
            continue $continue_nbr
            echo exit_status after continue $?
        fi
    done
    echo exit_status end $?
}
test_fn 1
test_fn 2
test_fn 99
test_fn -1
test_fn aaa
