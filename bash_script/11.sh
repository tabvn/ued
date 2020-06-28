#!/bin/bash
#Write a shell program to find the position of substring in given string.
echo "enter string:"
read a
echo "enter substring"
read b
rest=${a#*$b}
pos=$((${#a} - ${#rest} - ${#b}))
echo "position of substring:$pos"
