#!/bin/bash
#Write a shell program to reverse the digits of five digit integer.
echo "enter number:"
read n
res=0
while [ "$n" -gt 0 ]; do
    t=$((n%10))
    res=$((res*10))
    res=$((res+t))
    n=$((n/10))
done
echo "reverse number is: $res"