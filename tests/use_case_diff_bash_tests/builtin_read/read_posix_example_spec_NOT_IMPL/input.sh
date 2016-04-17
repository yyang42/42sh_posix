echo -n "aa bb" > /tmp/builtin_read_file

while read xx yy
do
    printf "%s %s\n" "$yy" "$xx"
done < /tmp/builtin_read_file
