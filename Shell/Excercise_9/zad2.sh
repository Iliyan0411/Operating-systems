num1=$(ls -l $1 | grep .out | wc -l)
num2=$(ls -l $2 | grep .out | wc -l)

if [ $num1 -gt $num2 ]
then
	read dir3
	mkdir $dir3

	cd $1
	for file in . 
	do
		if [ -r $file -a -w $file ]
		then
			echo here
			mv $file ./../$dir3
		fi
	done
fi

