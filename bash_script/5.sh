#!/bin/bash
#Find the lines containing a number in a file.
filepath="./5.txt"
cat <<EOF > "$filepath"
first line
second line
third line
line has number 10
line has number 11
EOF

i=0
while IFS= read -r line
do
  i=$((i +1))
  if [[ $line =~ [0-9] ]];then
      echo "line $i containing number"
  fi
done < "$filepath"