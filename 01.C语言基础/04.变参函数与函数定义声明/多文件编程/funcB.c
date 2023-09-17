/*************************************************************************
	> File Name: funcB.c
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 08:02:43 PM CST
 ************************************************************************/

#include<stdio.h>
#include "head.h"

int funcB(int n) {
    printf("funcB = %d\n", n);
    if (n == 0) return 1;
    funcC(n - 1);
    return n;
}
