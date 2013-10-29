#!/bin/sh

ulimit -t $5
ulimit -m $6

sh $1 < $2 > $3 2> $4 &
sleep $5
kill $! 2> /dev/null
