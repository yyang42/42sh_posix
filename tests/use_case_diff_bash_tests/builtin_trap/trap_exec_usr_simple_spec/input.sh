trap "echo abc" HUP
trap
kill -HUP $$
