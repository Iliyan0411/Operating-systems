touch sources.txt
cd $1
echo *.c > ./../sources.txt
cd ..
cd $2
echo *.c >> ./../sources.txt
cd ..

cfiles=$(wc -w sources.txt)
if [ $cfiles -gt 20 ]
then
	chmod 0444 sources.txt
else
	echo $cfiles
	rm sources.txt
fi

