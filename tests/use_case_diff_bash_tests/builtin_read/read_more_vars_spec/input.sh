echo -n "aa bb" > /tmp/builtin_read_file

read mytestvar1 mytestvar2 mytestvar3 < /tmp/builtin_read_file

export mytestvar1 mytestvar2 mytestvar3
env | grep mytestvar | sort
