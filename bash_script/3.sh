#!/bin/bash
#Write a shell script to find the sum, the average and the product of the four integers entered.
n=4
i=1
sum=0
product=1
while [ $i -le $n ]; do
    echo "Enter number $i:"
    read num
    sum=$((sum +num))
    product=$((product*num))
    i=$((i+1))
done

echo "Sum=$sum"
echo "Product=$product"
avg=$(echo $sum / $n | bc -l)
printf 'Avg=%0.2f' "$avg"
echo