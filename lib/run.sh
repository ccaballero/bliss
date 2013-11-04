#!/bin/sh

#ulimit -t $1
#ulimit -m $2

#/usr/bin/time -f "%E" -o $6 $3 < $4 > $5 2> $7 &

perl /var/www/bliss.local/lib/timeout/timeout -t $1 -m $2 $3

#sleep $1
#kill $! 2> /dev/null
