#!/bin/bash
#Write a shell program to find the greatest common divisor (gcd) for the 2 given numbers.
gcd(){
  a=$1
  b=$2
  while [ "$a" -ne "$b" ]; do
      if [ "$a" -gt "$b" ]; then
          a=$((a-b))
      else
        b=$((b-a))
        fi;
  done
}

echo "Enter numbers a b"
read c d
gcd "$c" "$d"
echo "gcd of $c $d is: $a"