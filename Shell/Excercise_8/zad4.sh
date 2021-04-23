#!/bin/sh

read username

while [ 0 -eq 0 ]
do
	sleep 30
	users | grep -q $username
	if [ $? -eq 0 ]
	then 
		echo "$username has started a session."
		break
	else echo "$username is not in session."
	fi
done
