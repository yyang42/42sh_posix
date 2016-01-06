echo lol | wc -l > pouet
cat pouet
cat -e < pouet | wc -c
cat -e < pouet | wc -c > pouet2
cat pouet2
rm pouet pouet2
