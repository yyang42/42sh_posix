for file in /*;
do
	if [ -d $file ]
	then
		( pushd $file ) 2> /dev/null
	fi
done

dirs
