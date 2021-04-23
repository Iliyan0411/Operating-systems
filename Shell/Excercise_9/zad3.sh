read msg
echo $msg >> $1

for var
do
	case $var
	in
	$users) write $var $1;;
	esac
done	
