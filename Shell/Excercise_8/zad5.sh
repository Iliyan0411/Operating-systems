#!/bin/sh

read str
for var
do
	echo -n "$var: "
	grep $str $var | wc -l
done
