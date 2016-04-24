export myvar=456
env myvar=123 bash -c 'echo 111$myvar; bash -c "echo 222$myvar"'
