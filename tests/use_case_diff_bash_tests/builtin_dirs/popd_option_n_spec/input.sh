cd /
popd -n
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
	popd -n
	pwd
	echo ${PWD}
	echo ${OLDPWD}
done

dirs -c
push_mult_file / / /usr /tmp /usr /bin /usr /tmp / / /tmp 

popd -n -0
popd -n +4
popd -n -6
popd -n +42
dirs
