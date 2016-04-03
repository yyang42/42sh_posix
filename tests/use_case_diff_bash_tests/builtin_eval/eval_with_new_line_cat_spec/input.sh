cat << EOF > /tmp/test_builtin_eval_cat_out
echo line 1
echo line 2
echo line 3
EOF
eval `cat /tmp/test_builtin_eval_cat_out`
