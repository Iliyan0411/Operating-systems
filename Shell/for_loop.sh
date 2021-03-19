# #!/bin/sh

for x in *.sh
do
	echo x=$x
	echo -------------
	cat $x 
	sleep 1
done