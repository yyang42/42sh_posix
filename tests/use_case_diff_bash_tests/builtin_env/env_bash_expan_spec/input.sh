export myvar=456
env myvar=123 bash -c 'for i; do echo $i; done' aa bb cc
