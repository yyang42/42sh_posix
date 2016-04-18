python -c 'print "aa bb\n"*45' > /tmp/builtin_read_file

while read -r xx yy
do
    printf "%s %s\n" "$yy" "$xx"
done < /tmp/builtin_read_file
