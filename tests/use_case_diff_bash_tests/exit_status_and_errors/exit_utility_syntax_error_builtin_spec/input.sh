foo () {
	echo "start of foo"
	cat > /tmp/test_exit_tmp
	. /tmp/test_exit_tmp
	echo "end of foo"
}
foo << EOF
set -w
echo "after set"
EOF
