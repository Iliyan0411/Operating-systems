#!/bin/sh

mv $1 f3
mv $2 $1
mv f3 $2

echo $1
echo $2
