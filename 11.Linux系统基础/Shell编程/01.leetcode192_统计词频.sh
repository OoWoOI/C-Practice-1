#!/bin/bash
cat 01.words.txt | tr -s ' ' '\n' | sort | uniq -c  | sort -r | awk '{print $2, $1}'
