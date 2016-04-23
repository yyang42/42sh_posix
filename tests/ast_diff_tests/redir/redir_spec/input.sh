ls > /tmp/redir_test_outputA < /tmp/redir_test_inputA >> /tmp/redir_test_appendA
(echo cat) >| /tmp/redir_test_outputB < /tmp/redir_test_inputB >> /tmp/redir_test_appendB
ls pouet_not_exist 2> /tmp/redir_test_file
ls -y 2 > /tmp/redir_test_file2
