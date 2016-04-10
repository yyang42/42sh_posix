if [ $$ = `bash -c 'echo $PPID'` ]; then
	echo "OK"
else
	echo "KO"
fi
