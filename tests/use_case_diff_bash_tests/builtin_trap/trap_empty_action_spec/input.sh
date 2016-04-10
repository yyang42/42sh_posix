trap "" HUP
trap "   " INT
trap
kill -HUP $$
kill -INT $$
