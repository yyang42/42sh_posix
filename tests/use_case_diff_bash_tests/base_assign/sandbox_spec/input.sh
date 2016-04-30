aabbccdd1=bbb0
aabbccdd1=bbb1 env | grep aaa
export aabbccdd1
env | grep aaa

echo ==========
aabbccdd1=bbb0
aabbccdd1=bbb1 bash -c 'echo $aabbccdd1'
bash -c 'echo 1-$aabbccdd1'
export aabbccdd1
bash -c 'echo 2-$aabbccdd1'
env | grep aaa
