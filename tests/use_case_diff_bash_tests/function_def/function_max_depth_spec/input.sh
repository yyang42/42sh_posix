cat << EOF > /tmp/func_max_depth_file
echo this should execute
fn () {
	fn
}
fn
echo this should NOT execute
EOF

/tmp/bin/42sh /tmp/func_max_depth_file
