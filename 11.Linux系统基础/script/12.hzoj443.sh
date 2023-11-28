#!/bin/bash
read L M
for ((i = 0; i < ${M}; i++));do
    read start end
    for ((j = ${start}; j <= ${end}; j++));do
       tree[${j}]=1
    done
done

cnt=0
for ((i = 0; i <= ${L}; i++));do
    if [[ ${tree[${i}]}x == x ]];then
       let cnt++ 
    fi
done

echo $cnt
