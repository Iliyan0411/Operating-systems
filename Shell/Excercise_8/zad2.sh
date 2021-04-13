#!/bin/sh

echo $*
echo $#
set $(ls .)
shift 2
echo $*
echo $#
