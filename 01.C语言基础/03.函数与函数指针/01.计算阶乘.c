/*************************************************************************
	> File Name: 01.计算阶乘.c
	> Author: 
	> Mail: 
	> Created Time: Fri 15 Sep 2023 10:03:05 PM CST
 ************************************************************************/

#include<stdio.h>

int func(int n) {
    if (n == 1) return 1;
    return n * func(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", func(n));
    return 0;
}
