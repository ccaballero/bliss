#!/bin/sh

ulimit -t $1
ulimit -m $2

/usr/bin/time -f "%E" -o $6 $3 < $4 > $5 2> $7 &

sleep $1
kill $! 2> /dev/null

