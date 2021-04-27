br=1
a=$3
br=`expr $br \* $2`
set ab bc cd de
shift
while true
do echo $*
	for j
	do if test $# -lt $br
	then br=`expr $br / 2`
		echo $br $j >> file
	else br=`expr $br + $a`
		echo $br $j >> file
	fi
done
break
done
read a1 a2
while grep $a1 file
do wc -l file
	set `tail -2l file`
	shift 2
	echo $* $#
	exit
	cat file
done
set `head -l file`
shift 3
echo $1 $#
wc -c < file

