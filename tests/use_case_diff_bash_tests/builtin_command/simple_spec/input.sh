command echo 'abc'
command cd /tmp
command pwd

alias ls='echo abc'
command ls

cd () { echo 'cd'; }
command cd -
command pwd
