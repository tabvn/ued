#!/bin/bash
#Write a shell program to exchange the values of two variables.
exchange(){
  a=$1
  b=$2
  c="$a"
  a="$b"
  b="$c"
}

echo "Enter two number a b"
read a b
exchange "$a" "$b"
echo "a=$a b=$b"