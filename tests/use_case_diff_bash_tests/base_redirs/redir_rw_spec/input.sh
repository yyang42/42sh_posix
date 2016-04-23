echo "abc" > /tmp/redir_test_file
{
	cat <&42
	echo aabb >&42
} 42<>/tmp/redir_test_file
cat /tmp/redir_test_file
