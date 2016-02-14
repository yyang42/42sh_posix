setenv hello=pouet ahah=hehe
env | grep hello | cat -e
env | grep ahah | cat -e
unsetenv hello
env | grep hello | cat -e
temporary=hello env | grep temporary | cat -e
env | grep temporary | cat -e
setenv PATH=""
ls
setenv HOME=""
cd
