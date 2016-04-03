cat << EOF > /tmp/test_builtin_dot_script.sh
echo 123456789
EOF
. /tmp/test_builtin_dot_script.sh | wc
