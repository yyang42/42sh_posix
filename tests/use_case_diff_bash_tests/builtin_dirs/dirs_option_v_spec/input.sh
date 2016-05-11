for i in $(seq 1 51)
do
	pushd /
done
pushd /tmp
pushd /bin
pushd /usr
for i in $(seq 1 51)
do
	pushd /
done

dirs -v
