pushd /
pushd /bin
pushd /usr
pushd /tmp

dirs -c
dirs

pwd
echo $PWD
echo $OLDPWD

pushd /tmp
pushd /usr
pushd /bin
pushd /

dirs -l -p -v -c
dirs

pwd
echo $PWD
echo $OLDPWD
