read_while () {
	fd=$1
	while read xx yy <&$fd
	do
		echo "$xx-$yy"
	done
}

test_multi_redir () {
	for fd in 42 43 44
	do
		read_while $fd
	done
}

printf "aa 22\nbb 22\n">/tmp/redir_test_file22
printf "aa 23\nbb 23\n">/tmp/redir_test_file23
printf "aa 24\nbb 24\n">/tmp/redir_test_file24

echo "=== file content ==="
cat /tmp/redir_test_file22
cat /tmp/redir_test_file23
cat /tmp/redir_test_file24
exec 22</tmp/redir_test_file22
exec 23</tmp/redir_test_file23
exec 24</tmp/redir_test_file24

echo "=== exec foo ==="
test_multi_redir 42<&22 43<&23 44<&24
