read us1 us2
num_terminals=$(who | wc -l)
users_1=$(who | grep $us1 | wc -l)
users_2=$(who | grep $us2 | wc -l)
sum_users=`expr $users_1 + $users_2`
result=`expr $num_terminals - $sum_users`
echo $result
