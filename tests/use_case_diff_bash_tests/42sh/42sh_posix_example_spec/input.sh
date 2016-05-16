#
# Installation time script to install correct POSIX shell pathname
#
# Get list of paths to check
#
Sifs=$IFS
Sifs_set=${IFS+y}
IFS=:
set -- $(getconf PATH)
if [ "$Sifs_set" = y ]
then
    IFS=$Sifs
else
    unset IFS
fi
#
# Check each path for 'sh'
#
for i
do
    if [ -x "${i}"/sh ]
    then
        Pshell=${i}/sh
    fi
done
#
# This is the list of scripts to update. They should be of the
# form '${name}.source' and will be transformed to '${name}'.
# Each script should begin:
#
# #!INSTALLSHELLPATH
#
scripts="a b c"
#
# Transform each script
#
for i in ${scripts}
do
    # sed -e "s|INSTALLSHELLPATH|${Pshell}|" < ${i}.source > ${i}
    echo "${Pshell} ${i}"
done
