# #!/bin/sh

# for x in *.sh
# do
# 	echo x=$x
# 	echo -------------
# 	cat $x 
# 	sleep 1
# done

####################################################
# for i in 10 20 30 40 50
# do

# echo $i
# sleep 1

# done


####################################################
# for i in Hello 1 * 2 Bye
# do

# echo $i
# sleep 1

# done

###################################################
str="empty"
while [ "$str" != "bye" ]
do

	echo -n "Please, enter a string(bye to quit): "
	read str
	echo "You typed: $str"

done
