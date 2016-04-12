# alias aa='python test.py 11"22'
# aa 33"

# cat << EOF > test.sh
# alias aa='echo 11"22'
# aa 33"
# EOF
# bash --posix test.sh
# bash test.sh


alias aa='for i in aa bb;'
aa do echo $i; done
