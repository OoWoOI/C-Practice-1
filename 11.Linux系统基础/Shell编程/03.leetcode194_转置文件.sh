#!/bin/bash

#需要获取切分的列数
colmn=$(head -n 1 ./03.file.txt | wc -w)

for i in $(seq 1 $colmn);do
    cut -d ' ' -f"$i" ./03.file.txt | paste -s -d' ' -
done
