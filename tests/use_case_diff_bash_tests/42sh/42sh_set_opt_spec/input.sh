cat << EOF | $TESTED_SHELL -aCeh
set -o | sort | grep -E '^(allexport|errexit|noclobber|noglob|notify|ignoreeof|monitor|noexec|nounset|verbose|vi)'
EOF
