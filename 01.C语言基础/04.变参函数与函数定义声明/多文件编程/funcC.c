/*************************************************************************
	> File Name: funcC.c
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 08:04:09 PM CST
 ************************************************************************/

#include<stdio.h>
#include "head.h"
int funcC(int n) {
    printf("funcC = %d\n", n);
    if (n == 0) return 0;
    funcA(n - 1);
    return n;
}
