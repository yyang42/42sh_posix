exec 4>/tmp/redir_heredoc_test_file
cat << EOF >/tmp/redir_heredoc_test_file
AAA
BBB
EOF
echo "==========1"
cat /tmp/redir_heredoc_test_file
echo "==========2"
