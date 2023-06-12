#!/bin/bash

echo "===LOYD'S TRIANGLE==="
echo -n "Enter the height: "
read h

count=1
echo ""

for (( i = 1; i <= h; i++ ))
do
	for (( j = 0; j < i; j++ ))
	do
		echo -n "$count "
		count=`echo $count + 1 | bc`
	done
	echo ""
done
