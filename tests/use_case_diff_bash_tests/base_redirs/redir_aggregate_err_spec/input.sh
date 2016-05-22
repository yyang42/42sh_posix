touch /tmp/dummy_file
(echo abc 5< /tmp/dummy_file; cat /tmp/dummy_file)
(echo abc 5<& /tmp/dummy_file; cat /tmp/dummy_file)
(echo abc 5&> /tmp/dummy_file; cat /tmp/dummy_file)
(echo abc 5> /tmp/dummy_file; cat /tmp/dummy_file)
(echo abc 5>& /tmp/dummy_file; cat /tmp/dummy_file)
(echo abc 5>> /tmp/dummy_file; cat /tmp/dummy_file)
(echo abc 5<> /tmp/dummy_file; cat /tmp/dummy_file)
(echo abc 5>| /tmp/dummy_file; cat /tmp/dummy_file)
