test_fn () {
    echo "case " $1
    for a in aa bb cc
    do
        continue $1
    done
    echo "after while"
}
# test_fn 1
# test_fn 2
# test_fn 99
test_fn -1
# test_fn aaa
# test_fn bbb
