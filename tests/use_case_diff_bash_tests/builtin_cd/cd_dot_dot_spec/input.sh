mydir=/tmp/cd_test/dir1/dir2
mkdir -p $mydir
cd $mydir
pwd
cd ..
pwd | sed 's;/private;;'
