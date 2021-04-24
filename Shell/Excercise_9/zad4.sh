#!/bin/sh

if [ $# -eq 2 ]
then
	str=$(cat file)
	set $1 $2 $str
fi

mkdir $3; touch ./$3/names
echo *.c > ./$3/names
echo *.out > ./$3/names

mv *.c $1
mv *.out $2

num=$(ls -l | wc -l)
echo $num
