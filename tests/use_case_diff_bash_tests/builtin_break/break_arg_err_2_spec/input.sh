test_fn () {
    break_nbr=$1
    echo ==================== test_case $break_nbr
    for item in aaa bbb ccc
    do
        echo item $item
        if [ $item = bbb ]
        then
            echo "condition true"
            break $break_nbr
            echo exit_status after break $?
        fi
    done
    echo exit_status end $?
}
test_fn 1
test_fn 2
test_fn 99
test_fn -1
test_fn aaa
