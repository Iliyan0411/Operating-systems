#!/bin/sh

cp $1 a1
cp $1 a2
cp $1 a3

echo -n "Enter a name of file: "
read fname
grep $2 $1
grep $2 $1 | wc -l > fname
