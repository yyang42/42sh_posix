export hello=pouet ahah=hehe
env | grep hello | cat -e
env | grep ahah | cat -e
unset hello
env | grep hello | cat -e
temporary=hello env | grep temporary | cat -e
