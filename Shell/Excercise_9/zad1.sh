if [ -d $1 ]
then for fl in $(ls $1)
do
	temp=$(wc -c ./$1/$fl | cut -d " " -f 1)
	if [ $temp -gt $2 ]
	then
		echo $fl
	fi
done
else echo No such a directory.
fi
