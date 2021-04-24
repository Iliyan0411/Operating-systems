#!/bin/sh

sum=0
for file in $(ls $1)
do
	temp=$(wc -c $file | cut -d " " -f 1)
	sum=`expr $sum + $temp`
done

write $2 $sum
