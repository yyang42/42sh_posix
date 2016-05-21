sort_alpha() {
	grep -o . | sort | tr -d "\n"
}
set -C
set -a
echo $- | tr -d 'B' | sort_alpha
echo
