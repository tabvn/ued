#!/bin/bash
#Write a shell program to find the sum of the series sum=1+1/2+…+1/n.
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
read -p "Enter n: " n
mau=1
for ((i = 1; i <= n; i++)); do
  mau=$((mau * i))
done
tu=0
for ((i = 1; i <= n; i++)); do
  quyDong=$((mau / i))
  tu=$((tu + quyDong))
done

gcd "$tu" "$mau"

tu=$((tu/a))
mau=$((mau/a))
echo "Ket qua: $tu/$mau"
