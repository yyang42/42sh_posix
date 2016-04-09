cd /tmp
cd /
pwd
cd -
rm -rf test1_cd
rm -rf test2_cd
mkdir test1_cd
cd test1_cd
ls -a | cat -e
cd ..
ln -s test1_cd test2_cd
cd test2_cd
pwd | grep test1
