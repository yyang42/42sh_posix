aaa1=bbb0
aaa1=bbb1 env | grep aaa
export aaa1
env | grep aaa

echo ==========
aaa1=bbb0
aaa1=bbb1 bash -c 'echo $aaa1'
bash -c 'echo 1-$aaa1'
export aaa1
bash -c 'echo 2-$aaa1'
env | grep aaa
