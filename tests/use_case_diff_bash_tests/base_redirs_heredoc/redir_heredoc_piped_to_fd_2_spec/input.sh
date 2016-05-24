#_NOT_WORKING_USE_FD_ABSTRACTION
exec 42>/tmp/redir_heredoc_test_file
cat << EOF >&42
AAA
BBB
EOF
echo "==========1"
cat /tmp/redir_heredoc_test_file
echo "==========2"
re
