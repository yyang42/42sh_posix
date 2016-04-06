export myvar_aa=11
export myvar_bb=22
export myvar_cc=33
export myvar_dd=44
readonly myvar_bb
unset myvar_aa myvar_bb myvar_cc
env | grep myvar_ | sort
