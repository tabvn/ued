#!/bin/bash
#Write a shell script to ask your name, program name and enrollment number and print it on the screen.
read -p "What is your name:" name
read -sp "What is your enrollment number:" enrollmentNumber
echo
echo "Your name is: $name your enrollment number is: $enrollmentNumber"