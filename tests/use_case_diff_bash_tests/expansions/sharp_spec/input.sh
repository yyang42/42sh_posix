x=foobarbaz

echo ${x#foo}
echo ${x#*ba}
echo ${x#????}
echo ${x#[a-z]*}

set foo bar baz

echo ${@#*a}
echo "${@#*a}"
echo ${*#??}
IFS=pouet
echo "${*#??}"

aze=osarabosarabose
echo ${aze#*ara}
