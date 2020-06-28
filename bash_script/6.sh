#!/bin/bash
#Write a shell script to display the digits which are in odd position in a given 5 digit number.
n=5
i=1
inc=0
declare -a arr
while [ $i -le $n ]; do
    echo "Enter number $i:"
    read num
    if [ $((num%2)) -ne 0 ]; then
        arr[inc]="$num"
        inc=$((inc+1))
    fi
    i=$((i+1))
done
for item in ${arr[*]}
do
   echo "$item is odd number"
done