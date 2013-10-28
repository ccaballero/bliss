#!/bin/sh

ulimit -t $2
ulimit -m 1024

./problems/$1 &
sleep $2
kill $! 2> /dev/null
