ls $1 | grep .c > sources.txt
ls $2 | grep .c >> sources.txt

C_files=$(wc -l sources.txt | cut -d " " -f 1)

if [ $C_files -gt 20 ]
then
	chmod 0444 sources.txt
else
	echo $C_files
	rm sources.txt
fi
