#_NOT_WORKING_USE_FD_ABSTRACTION
exec 4>/tmp/redir_heredoc_test_file
cat << EOF >&4
AAA
BBB
EOF
echo "==========1"
cat /tmp/redir_heredoc_test_file
echo "==========2"
