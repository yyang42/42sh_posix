test_fn () {
	echo "start of foo"
	cat > /tmp/test_exit_tmp
	. /tmp/test_exit_tmp
	echo "end of foo"
}

test_fn << EOF 2> /dev/null
set -w
echo "after set: should not print"
EOF
