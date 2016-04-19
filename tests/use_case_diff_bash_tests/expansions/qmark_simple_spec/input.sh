foobar=posix
echo ${foobar:?}
foobar=
echo ${foobar:?}
unset foobar
echo ${posix:?}
