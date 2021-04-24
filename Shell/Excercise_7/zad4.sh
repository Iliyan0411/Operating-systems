#!/bin/sh
ls -l | grep "rw-r--r--" > files

for fname in $(ls .)
do
	grep -q $fname files
	if [ $? -eq 0 ]
	then echo $fname
	fi
done

