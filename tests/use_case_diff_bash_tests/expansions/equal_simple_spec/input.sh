foobar=baz
echo ${foobar=lel}
echo $foobar

foobar=
echo ${foobar=lel}
echo $foobar

unset foobar
echo ${foobar=lel}
echo $foobar
