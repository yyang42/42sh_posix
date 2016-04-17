echo abc > /tmp/builtin_read_file
cat /tmp/builtin_read_file
read myvar < /tmp/builtin_read_file
echo $myvar
