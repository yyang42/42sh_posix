# TODO: remove comment part when yan correct this
# echo $#
echo ${#}
echo "${#}"
set a b c
echo ${#}
echo "${#}"
set 'a b c'
echo ${#}
echo "${#}"
set $(seq 1 123)
echo ${#}
echo "${#}"
