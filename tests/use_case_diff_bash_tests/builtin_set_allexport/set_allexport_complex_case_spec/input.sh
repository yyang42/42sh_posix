allexport_myvar_1=aaa
(env | grep allexport_myvar_1=)
set -a
allexport_myvar_2=aaa
(env | grep allexport_myvar_1=)
(env | grep allexport_myvar_2=)
set +a
allexport_myvar_3=aaa
(env | grep allexport_myvar_3=)
