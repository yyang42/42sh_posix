set -a
allexport_myvar_1=aaa bash -c 'export | grep allexport_myvar_1='
bash -c 'export | grep allexport_myvar_1='
export | grep allexport_myvar_1=
env | grep allexport_myvar_1=
