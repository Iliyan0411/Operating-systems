cd $1
out1=$(echo *.out | wc -w)
cd ..
cd $2
out2=$(echo *.out | wc -w)
cd ..

if [ $out1 -gt $out2 ]
then
	read dir3
	mkdir $dir3

	cd $1
	for file in $(ls .) 
	do
		if [ -f $file -a -r $file -a -w $file -a ! -x $file ]
		then
			mv $file ./../$dir3
		fi
	done
fi

