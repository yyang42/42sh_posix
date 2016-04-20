IFS=\\\"\'
echo 'lal\lol"lel'\''pouf'
a='lal\lol"lel'\''pouf'
python -c 'import sys;print sys.argv' $a"$a"$a
