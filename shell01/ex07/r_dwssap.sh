cat /etc/passwd \
| awk \
-v FS=':' \
'/^#+/ { next } { print $1 }' \
| awk \
'NR % 2 == 0' \
| rev | sort -r \
| awk \
-v ORS=', ' \
"$FT_LINE1 <= NR && NR <= $FT_LINE2" \
| sed 's/, $/./' | tr -d '\n'
