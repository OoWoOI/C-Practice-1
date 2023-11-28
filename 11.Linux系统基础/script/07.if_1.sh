#!/bin/bash
read st end
for i in `seq ${st} ${end}`;do
    if [[ $[ ${i} % 2 ] -eq 0 ]];then
        echo $i
    fi
done
