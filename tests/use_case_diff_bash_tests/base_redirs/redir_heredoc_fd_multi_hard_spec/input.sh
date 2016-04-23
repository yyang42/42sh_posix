foo () {
	while read var1 var2 <&$1
	do
		echo "$var1-$var2"
	done
}
(
	foo 21
	foo 42
)  21<< EOF 42<< EOF2 | cat -e > /tmp/test_redir_heredoc_result
A1 A2
B1 B2
EOF
11 12
21 22
EOF2

cat -e /tmp/test_redir_heredoc_result
