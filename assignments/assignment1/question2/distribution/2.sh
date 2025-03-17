#!/bin/bash
echo "Enter the number for checking:"
read number

index=0
sum=0
while [ $index -lt 16 ]; do

let "item = $number / (10 ** $index) % 10" 
if [ `expr $index % 2` -eq 1 ]
then let "item = $item * 2"
fi
if [ $item -gt 9 ] 
then let "item = $item - 9"
fi
let "sum = $sum + $item"
let "index = $index + 1"
done


if [ `expr $sum % 10` -eq 0 ]
then 
echo "The number $number is valid."
else
echo "The number $number is invalid."
fi