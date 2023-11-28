#!/bin/bash
read num
i=1
until [[ ${i} -eq ${num} ]];do
    echo  $i
    let i++;
done
