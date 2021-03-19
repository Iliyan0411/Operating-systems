#!/bin/sh

x=15

until [ $x -lt 0 ]
do

    echo $x

    if [ $x -le 10 ]
    then
    x=$(($x-2))

    else
    x=$(($x-1))
    fi

done
