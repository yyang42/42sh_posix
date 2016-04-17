x=lol
echo ${x:-pouet}
echo "${x:-pouet}"
echo "${x:-"pouet"}"
echo ${x:-"pouet"}
unset x
echo ${x:-pouet}
echo "${x:-pouet}"
echo "${x:-"pouet"}"
echo ${x:-"pouet"}
