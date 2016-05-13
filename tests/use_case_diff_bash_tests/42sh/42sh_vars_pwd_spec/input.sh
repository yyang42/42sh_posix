echo "PWD: $PWD"
PWD=ABC
echo "PWD: $PWD"
unset PWD
echo "PWD: $PWD"
export PWD=bla
echo "PWD: $PWD"
bash -c 'echo "bash pwd: $PWD"'
