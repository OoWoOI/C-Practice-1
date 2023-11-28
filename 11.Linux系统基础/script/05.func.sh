#!/bin/bash
function __printf__() {
    echo "$1"
    return 123
}

__printf__ $3 $1 $2

echo $?
