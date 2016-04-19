cat << EOF | $TESTED_SHELL
echo abc | wc
echo 123 | cat -e | cat -e | cat -e
export MYVAR=ABC
env | grep MYVAR=
EOF
