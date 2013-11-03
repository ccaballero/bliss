#!/bin/sh

#ulimit -t $1
#ulimit -m $2

#$1 < $2 > $3 2> $4 &
$3 < $4 &

#sleep $1
#kill $! 2> /dev/null

