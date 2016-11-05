python -c 'print "A"*100000' > /tmp/pip_bareme_spec_file
cat /tmp/pip_bareme_spec_file | head -c 2 | wc
python -c 'print "A"*200000' > /tmp/pip_bareme_spec_file
cat /tmp/pip_bareme_spec_file | head -c 2 | wc
# python -c 'print "A"*81920' | head -c 2 | wc
# python -c 'print "abcde"' | /bin/echo
