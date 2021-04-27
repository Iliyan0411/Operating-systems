len=`expr $(expr index "$(tail -1l $1)" l) - 1`
str=$(expr substr "$(tail -1l $1)" 1 $len)

find ./.. -name $str | wc -l
