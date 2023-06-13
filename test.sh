#!/bin/bash
for (( i=1; i<5; i++))
do
echo "program $i"
g++ Q$i.cpp
for (( j=1; j<11; j++))
do
if [ $i -ne 2 ] || [ $j -ne 10 ]
then
echo "test $j diff:"
./a.out < tests/Q$i/$j/$j.in > 1.out
diff 1.out tests/Q$i/$j/$j.out
printf "\n"
fi
done
done
printf "\n"