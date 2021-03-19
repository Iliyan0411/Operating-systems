#!/bin/sh

x=1

while [ $x -le 10 ]
do
	echo "You will wait " $x "second/s."
	sleep $x
	x=$(($x+1))
done 
