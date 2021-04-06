read f1 f2 f3
echo `expr length $f1 + length $f2 + length $f3` > len | cat len
