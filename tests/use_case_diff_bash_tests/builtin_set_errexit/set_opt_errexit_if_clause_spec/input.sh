set -e
echo init
if false
then
	echo then body1
	(exit 21)
	echo then body2
else
	echo else body1
	(exit 42)
	echo else body2
fi
echo end
