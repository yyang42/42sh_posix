readonly myvar_aa=aa myvar_bb=bb
readonly -p myvar_cc=cc | grep myvar_aa
readonly -p | grep myvar_aa
readonly -p | grep myvar_cc
