#!/bin/bash
#Write a shell program to convert all the contents into the uppercase in a particular file.
filepath="./18.txt"
cat <<EOF > "$filepath"
Roses are red
Violets are blue
I love you the best
But you said me ngu
EOF

tr "[a-z]" "[A-Z]"  < "$filepath" | tee "$filepath"