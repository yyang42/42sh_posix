set -m
sleep 0.01 && echo "sleep 1" && \
sleep 0.01 && echo "sleep 2" && \
sleep 0.01 && echo "sleep 3" && \
sleep 0.01 && echo "sleep 4" && \
sleep 0.01 && echo "sleep 5" && \
sleep 0.01 && echo "sleep 6" && \
sleep 0.01 && echo "sleep 7" && \
sleep 0.01 && echo "sleep 8" && \
sleep 0.01 && echo "sleep 9" && \
sleep 0.01 && echo "sleep 10" && \
sleep 0.01 && echo "sleep 11" && \
sleep 0.01 && echo "sleep 12" && \
sleep 0.01 && echo "sleep 13" && \
sleep 0.01 && echo "sleep 14" && \
sleep 0.01 && echo "sleep 15" && \
sleep 0.01 && echo "sleep 16" &
fg > /tmp/builtin_fg_test_file && cat -e /tmp/builtin_fg_test_file | sed 's/ &//g'
wait
