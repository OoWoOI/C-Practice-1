#!/bin/bash
read num
while [[ ${num} -gt 0 ]];do
    if [[ $[${num} % 10] -eq 0 ]];then
        let num--
        continue
    fi
    
    if [[ ${num} -eq 4 ]];then
        break;
    fi
    echo $num
    let num--
done
