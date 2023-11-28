#!/bin/bash
read num
flag=$[ ${num} % 2 ]
case $flag in
    0)
        echo "偶数"
        ;;
    1)
        echo "奇数"
        ;;
esac

