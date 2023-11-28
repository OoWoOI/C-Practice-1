#!/bin/bash
for ((i = 10; $i > 0; i--));do
    echo $i
done

for i in `seq 1 10`;do
    echo $i
done

for i in a b c;do
    echo $i
done
