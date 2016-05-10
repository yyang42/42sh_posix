HOME=/tmp

mkdir -p /tmp/test_dirs01
mkdir -p /tmp/test_dirs02
mkdir -p /tmp/test_dirs03
mkdir -p /tmp/test_dirs04

pushd /tmp
pushd /tmp/test_dirs01
pushd /tmp/test_dirs02
pushd /tmp/test_dirs03
pushd /tmp/test_dirs04

dirs
dirs -l

HOME=/bin
dirs -l
HOME=/
dirs -l
unset HOME
dirs -l

rm -rf /tmp/test_dirs01
rm -rf /tmp/test_dirs02
rm -rf /tmp/test_dirs03
rm -rf /tmp/test_dirs04
