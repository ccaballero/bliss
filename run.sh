#!/bin/sh

./problems/$1 &
sleep $2
kill $! 2> /dev/null

