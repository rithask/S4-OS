#!/bin/bash

echo "===Calculator==="

while true; do

echo -n "Enter a number: "
read a
echo -n "Enter another number: "
read b

echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
echo "5. Exit"

echo -n "Enter your chioce: "
read ch

case $ch in
1)res=`echo $a + $b | bc`
;;
2)res=`echo $a - $b | bc`
;;
3)res=`echo $a \* $b | bc`
;;
4)res=`echo "scale=2; $a / $b" | bc`
;;
5)echo "Exiting...";exit
;;
*)echo "Invalid choice"
esac

echo "Result: $res"

done