cat << EOF > /tmp/test_builtin_dot_script.sh
echo should exec
return
echo should not exec
EOF

. /tmp/test_builtin_dot_script.sh

echo pouf
