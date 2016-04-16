echo "==== control"
cat << EOF1 ; cat << EOF2
content1
	content11
EOF1
content2
	content22
EOF2

echo "==== simple"
cat <<- EOF1 ; cat <<- EOF2
content1
	content11
EOF1
content2
	content22
EOF2

echo "==== complex"
cat <<- EOF1
content1
	content11		content11
    content11    	spaces
		content111
		content111
		content111
		content111
EOF1
