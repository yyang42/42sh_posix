cd /tmp
rm -rf test_builtin_dirs_symlink
mkdir -p test_builtin_dirs_symlink
cd test_builtin_dirs_symlink

mkdir dir01 dir02 dir03
ln -s dir01 ln01
mkdir dir01/inndir01
ln -s /tmp/test_builtin_dirs_symlink/dir01/inndir01 /tmp/test_builtin_dirs_symlink/dir02/ln02
mkdir dir03/inndir03
cd dir01/inndir01 && ln -s ../../dir03/inndir03 ln03 && cd -

pushd dir01
pushd ../ln01
pushd ln03
pushd //tmp/test_builtin_dirs_symlink/dir02/ln02

popd -1
popd -1
popd -1
popd -1
