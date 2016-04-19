foobar=posix
echo ${foobar+pouet}
echo "${foobar+pouet}"

foobar=
echo ${foobar+pouet}
echo "${foobar+pouet}"

unset foobar
echo ${foobar+pouet}
echo "${foobar+pouet}"
