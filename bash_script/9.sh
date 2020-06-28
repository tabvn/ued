#!/bin/bash
#Write a shell program to search for a given number from the list of numbers provided using binary search method.
#https://vi.wikipedia.org/wiki/T%C3%ACm_ki%E1%BA%BFm_nh%E1%BB%8B_ph%C3%A2n
binary_search(){
  arr=$1
  t=$2
  n="${#arr[*]}"
  l=0
  r=$((n-1))
  m=-1
  found=-1
  while [ "$l" -le "$r" ]; do
      m=$((l+r))
      m=$((m/2))
      if [ "${arr[m]}" -lt "$t" ]; then
        l=$((m+1))
      elif [ "${arr[m]}" -gt "$t" ]; then
        r=$((m-1))
      else
        found="$m"
        break
      fi;
  done
}

echo "Enter numbers a b c d ..."
read -a arr
echo "Enter number to searching:"
read num

binary_search arr "$num"

if [ "$found" -ge 0 ]; then
    echo "founded number $num at index: $found"
else
  echo "Not found!"
fi;
