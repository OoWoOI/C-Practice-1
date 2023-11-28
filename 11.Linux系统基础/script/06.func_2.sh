#!/bin/bash
cnt=0
function count(){
    for i in `ls -A $1`; do
        if [[ -f $1/$i ]]; then
            let cnt++
        fi
        if [[ -d $1/$i ]]; then
            count $1/$i
        fi
    done
}
count $1
echo  "$cnt"
