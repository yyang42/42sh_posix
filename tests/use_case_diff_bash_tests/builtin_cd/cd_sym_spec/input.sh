rm -rf /tmp/test_cd_builtin

mkdir -p /tmp/test_cd_builtin/mydir
ln -s /tmp/test_cd_builtin/mydir /tmp/test_cd_builtin/mydir_sym1
ln -s /tmp/test_cd_builtin/mydir_sym1 /tmp/test_cd_builtin/mydir_sym2

foo () {
	opt=$1
	path=$2
	echo
	echo "cd" $opt $path
	cd /tmp/test_cd_builtin && cd $opt $path
	pwd
}

foo "--" /tmp/test_cd_builtin/mydir_sym1
foo "-P" /tmp/test_cd_builtin/mydir_sym1
foo "-L" /tmp/test_cd_builtin/mydir_sym1

foo "--" /tmp/test_cd_builtin/mydir_sym2
foo "-P" /tmp/test_cd_builtin/mydir_sym2
foo "-L" /tmp/test_cd_builtin/mydir_sym2
