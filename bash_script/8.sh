#!/bin/bash
#Write a shell script to find the largest among the 3 given numbers.
echo "enter a b c:"
read a b c
max="$a"
if [ "$max" -le "$b" ]; then
    max="$b"
fi

if [ "$max" -le "$c"  ]; then
    max="$c"
fi
echo "Largest number is: $max"