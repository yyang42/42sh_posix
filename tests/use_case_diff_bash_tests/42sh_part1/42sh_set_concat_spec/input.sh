sort_alpha() {
	grep -o . | sort | tr -d "\n"
}
$TESTED_SHELL -c 'echo $-' | tr -d 'B' | tr -d 'H' | sort_alpha
echo
