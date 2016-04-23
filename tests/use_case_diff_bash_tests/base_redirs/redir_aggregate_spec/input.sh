{>&2 echo "error" && echo "msg";} &> /tmp/redir_test_file
cat /tmp/redir_test_file

>&2 echo "check stderr restored"
echo "check stdout restored"
