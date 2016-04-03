cat << EOF > /tmp/test_builtin_dot_script.sh
export myvar_foo=hello
export myvar_bar=world
EOF

. /tmp/test_builtin_dot_script.sh
echo $myvar_foo
echo $myvar_bar
