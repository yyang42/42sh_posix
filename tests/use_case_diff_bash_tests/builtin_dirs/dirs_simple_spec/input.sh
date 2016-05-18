for file in /*;
do
	if [ -d $file ]
	then
		pushd $file
	fi
done

dirs
