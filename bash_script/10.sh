#!/bin/bash
#Write a shell program to concatenate two strings and find the length of the resultant string.
echo "Enter first string:"
read a
echo "Enter second string:"
read b
c="$a$b"
echo "Result String:$c"
echo "Result string length:${#c}"