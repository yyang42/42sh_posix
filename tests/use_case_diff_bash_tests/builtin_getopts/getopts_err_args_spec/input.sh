echo "=============1"
getopts
echo "=============2"
getopts a
echo "=============3"
getopts -a aa
echo "=============4"
getopts -b aa
echo "=============5"
getopts -- aa
echo "=============6"
getopts - aa
