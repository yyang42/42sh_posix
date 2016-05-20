cat << EOF1; echo $( cat << EOF2
hello $(cat << EOF3

EOF3
)
EOF2
)
world
EOF1X
