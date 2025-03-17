#!/bin/bash
word=$1
file=$2
if  [ -e $file ] && [ $word ] && [ $file ]
then
cat $2 | tr -c [:alnum:] "\n" | grep $1 -i | sort | uniq -c | sort -t " " -k1nr -k2
fi
