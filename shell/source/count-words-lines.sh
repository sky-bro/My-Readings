#!/bin/bash

echo -n "Enter a filename:"
read fname

if [ ! -f "$fname" ]
then
	echo "File $fname not found!"
	exit 1
fi

terminal=`tty`

exec < $fname

nol=0
now=0

while read line
do
	nol=`expr $nol + 1`
	now=`expr $now + $(echo $line | wc -w)`	
done

echo "Number of lines: $nol"
echo "Number of words: $now"

exec < $terminal
