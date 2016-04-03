cat << EOF > /tmp/test_builtin_dot_script.sh
exit 42
EOF
. /tmp/test_builtin_dot_script.sh
