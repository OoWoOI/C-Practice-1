/*************************************************************************
	> File Name: 03.union.c
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 07:32:28 PM CST
 ************************************************************************/

#include<stdio.h>

int funcA(int n) {
    printf("funcA = %d\n", n);
    if (n == 0) return 0;
    funcB(n - 1);
    return n;
}

int funcB(int n) {
    printf("funcB = %d\n", n);
    if (n == 0) return 0;
    funcA(n - 1);
    return n;
}
