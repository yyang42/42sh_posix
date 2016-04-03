cat << EOF > /tmp/test_builtin_dot_script.sh
myvar_foo=hello myvar_bar=world
EOF

. /tmp/test_builtin_dot_script.sh
echo $myvar_foo
echo $myvar_bar
