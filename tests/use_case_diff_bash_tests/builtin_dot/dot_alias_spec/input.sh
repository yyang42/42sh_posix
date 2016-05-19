cat << EOF > /tmp/test_builtin_dot_script.sh
alias aaa='echo abc'
EOF
. /tmp/test_builtin_dot_script.sh
aaa
