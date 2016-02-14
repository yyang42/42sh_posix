{ echo 123 ; echo abc; ls xxxxxx ; } > /tmp/test_redir_stdout 2> /tmp/test_redir_stderr
echo --- stdout
cat /tmp/test_redir_stdout
echo --- stderr
cat /tmp/test_redir_stderr
echo ---
