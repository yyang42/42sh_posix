echo lol | wc -l | xargs echo > pouet
cat pouet
cat -e < pouet | wc -c | xargs echo
cat -e < pouet | wc -c | xargs echo > pouet2
cat pouet2
rm pouet pouet2
