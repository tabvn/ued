#!/bin/bash
#Write a shell program to count number of words, characters, white spaces and special symbols in a given text.
#http://www.dailyfreecode.com/Code/shell-count-number-words-characters-1654.aspx
read -r -d '' s <<EOM
This is line 1
This is line 2
Line 3 $ a
EOM
count=$(wc -w <<<"$s")
spaceCount=0
for ((i = 0; i < ${#s}; i++)); do
  v="${s:$i:1}"
  if [ "$v" == " " ]; then
    spaceCount=$((spaceCount + 1))
  fi
done
c=$(echo "$s" | wc -c)
c=$(expr $c - 1)
echo "word count: $count"
echo "white space count: $spaceCount"
echo "characters: $c"
