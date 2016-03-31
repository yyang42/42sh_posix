cat << EOF > /tmp/test_eval_stdout
echo aa
echo bb
echo cc
EOF
value=`cat config.txt`
eval "$value"
