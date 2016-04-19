foobar=posix
echo ${foobar:?}
unset foobar
echo ${posix:?}
