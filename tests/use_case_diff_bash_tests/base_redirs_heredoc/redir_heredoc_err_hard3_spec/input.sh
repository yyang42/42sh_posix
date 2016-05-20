cat << EOF1; echo $( cat << EOF2
hello $(cat << EOF3

EOF3X
)
EOF2
)
world
EOF1
