foo='aa\
bb\n'
printf "$foo" > /tmp/builtin_read_file
cat /tmp/builtin_read_file
