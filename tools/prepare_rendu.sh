set -e

if [[ -z $1 ]] || [[ -z $2 ]] || [[ -z $3 ]]
	then
	echo "usage : sh prepare_rendu.sh 'src_path' 'dst_path' 'git vogo url'";
	exit;
fi

	export LC_CTYPE=C
	export LANG=C

	export src=$1
	export dst=$2
	export vogo_url=$3
	export username=`whoami`
	export clone_folder=$dst"_clone"

	rm -rf $dst
	rm -rf $clone_folder
	git clone $vogo_url $clone_folder

	mkdir -p $dst
	cp -r $clone_folder/.git $dst/

	cp -RL $src/ $dst
	cp $src/.gitignore $dst
	find $dst | grep "libtowel/tests$" | xargs rm -rf
	find $dst | grep "libtowel/.git$" | xargs rm -rf

if [ ! -f $dst/auteur ]; then
	echo "$username" > $dst/auteur
fi
cat -e $dst/auteur
echo "\033[32;1mRendu successfully prepared: $dst\033[0m"
