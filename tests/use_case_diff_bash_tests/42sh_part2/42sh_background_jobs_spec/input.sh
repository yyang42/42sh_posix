echo "sleep 0.1 && echo a1 & sleep 0.15 && echo a2 & sleep 0.2 && echo a3 & wait" | $TESTED_SHELL | sort
