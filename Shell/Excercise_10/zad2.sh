dir_name=$(ls . | grep $1)
not_rw_files=`expr $(ls -l | grep -v rw-rw-rw- | wc -l) - 1`

if [ -z $dir_name ]
then
	mkdir $1
fi

for file in $(ls .)
do
	ls -l $file | grep -q rw-rw-rw-
	if [ $? -eq 0 ]
	then
		cp $file $1
	fi
done

echo $not_rw_files

