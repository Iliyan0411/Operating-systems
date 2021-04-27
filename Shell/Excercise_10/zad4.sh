len=`expr $(expr index "$(tail -1l $2)" l) - 1`
str=$(expr substr "$(tail -1l $2)" 1 $len)

matches=$(find ./.. -name $str | wc -l)

if [ matches -gt 0 ]
then 
  echo $matches
else
  write $1 "Nothing found"
