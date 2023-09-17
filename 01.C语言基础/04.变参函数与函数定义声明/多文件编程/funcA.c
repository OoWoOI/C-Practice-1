/*************************************************************************
	> File Name: funcA.c
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 07:59:44 PM CST
 ************************************************************************/

#include<stdio.h>
#include "head.h"

int funcA(int n) {
    printf("funA = %d\n", n);
    if (n == 0) return 1;
    funcB(n - 1);
    return n;
}
