#!/bin/sh

square ()
{
    echo args_cnt=$# # shows number of parameters
    echo $$ # shows process ID
    echo $(($1*$1))
}

square 5
