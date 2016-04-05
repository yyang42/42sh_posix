myvar_aa=aa
myvar_bb=bb
readonly myvar_aa myvar_bb
readonly -p | grep myvar_aa
readonly -p | grep myvar_bb
readonly | grep myvar_aa
