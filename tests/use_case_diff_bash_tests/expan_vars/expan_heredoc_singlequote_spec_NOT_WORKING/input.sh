echo '=============1'
export myvar=123
cat << EOF
'aaa$myvar'
EOF
