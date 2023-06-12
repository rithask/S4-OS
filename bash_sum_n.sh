#!/bin/bash

echo "=== SUM OF N NUMBERS==="
echo -n "Enter the number of numbers: "
read num

sum=0

echo "Enter the numbers..."
for (( i = 0; i < num; i++ ))
do
	read a
	sum=`echo $sum + $a | bc`
done

echo "Sum = $sum"
