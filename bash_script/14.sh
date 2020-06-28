#!/bin/bash
#Write a shell program to check whether a given string is palindrome or not.
palindrome() {
  s=$1
  result=0
  if [[ $(rev <<<"$s") == "$s" ]]; then
    result=1
  fi
}
read -p "Enter string: " string
palindrome "$string"
if [ "$result" -eq 1 ]; then
    echo "String is palindrome"
    else
      echo "String is not palindrome"
fi
