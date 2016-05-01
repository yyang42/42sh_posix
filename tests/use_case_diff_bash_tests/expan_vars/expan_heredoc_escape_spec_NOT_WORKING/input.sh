myvar=abc
cat << EOF
MYPID="\$myvar"
\$\!\?\@
EOF
