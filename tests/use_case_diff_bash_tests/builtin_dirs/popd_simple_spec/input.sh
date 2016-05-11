cd /
popd
push_mult_file ()
{
	for dir in $@
	do
		pushd -n +0 $dir
	done
}

push_mult_file / / /usr /tmp /usr /bin /usr /tmp / / /tmp 

while [ $(( i+=1 )) -lt 15 ]
do
	popd
	pwd
	echo ${PWD}
	echo ${OLDPWD}
done

dirs -c
push_mult_file / / /usr /tmp /usr /bin /usr /tmp / / /tmp 

popd -0
popd +4
popd -6
popd +42
dirs
