cat << EOF > /tmp/builtin_read_file
aa bb cc
11 22 33
44 aa bb
55 aa bb
66 aa bb
77 aa bb
88 aa bb
99 aa bb
EOF

while read -r xx yy
do
    printf "%s %s\n" "$yy" "$xx"
done < /tmp/builtin_read_file
