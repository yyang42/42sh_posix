check_pwd ()
{
	pushd $@
	pwd
	echo ${PWD}
	echo ${OLDPWD}
	dirs
}

check_pwd /
check_pwd /usr
check_pwd /bin
check_pwd /bin
check_pwd /tmp
check_pwd +7
i=0
while [ $(( i+=1 )) -lt 10 ]
do
	check_pwd -$i
done

i=0
while [ $(( i+=1 )) -lt 10 ]
do
	check_pwd +$i
done

pushd noexists
