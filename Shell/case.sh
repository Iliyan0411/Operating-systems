#!/bin/sh

animal="none"

echo -n "Enter an animal type: "
read animal
echo -n "$animal has "

case $animal in
    dog | cat | horse | lion) echo "four legs";;
    man | kangaroo) echo "two legs";;
    *) echo "unknown number of legs";;
esac
