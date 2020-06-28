#!/bin/bash
#Write a shell program to add, subtract and multiply the 2 given numbers passed as command line arguments.
echo "Enter command eg: 2 * 4"
read a sign b
if [ "$sign" == "+" ]; then
  v=$((a + b))
  echo "=$v"
fi
if [ "$sign" == "-" ]; then
  v=$((a - b))
  echo "=$v"
fi

if [ "$sign" == "*" ]; then
  v=$((a * b))
  echo "=$v"
fi

if [ "$sign" == "/" ]; then
  v=$((a / b))
  echo "=$v"
fi
