cd /
pwd
cd -
rm -rf test1_cd
rm -rf test2_cd
mkdir test1_cd
cd test1
ls -a | cat -e
cd ..
ln -s test1_cd test2_cd
cd test2_cd
pwd | grep test1
cd ..
cd -P test2_cd
pwd | grep test2
cd ..
rm -rf test1_cd
rm -rf test2_cd
