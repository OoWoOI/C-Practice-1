/*************************************************************************
	> File Name: 07.upper.c
	> Author: 
	> Mail: 
	> Created Time: Sat 28 Oct 2023 06:21:15 PM CST
 ************************************************************************/

#include "./common/head.h"


int main() {
    char c;
    while (~(c = getchar())) {
        putchar(toupper(c));
    }
    
    return 0;
}

