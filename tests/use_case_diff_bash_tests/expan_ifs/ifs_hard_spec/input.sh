IFS='[] {}$'
a='[ll aa] pp{ qq oo } po $aze'
python -c 'import sys;print sys.argv' {$a}
python -c 'import sys;print sys.argv' "{$a}"
