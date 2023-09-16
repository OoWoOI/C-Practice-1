/*************************************************************************
	> File Name: 01.欧几里得算法.c
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 12:20:19 PM CST
 ************************************************************************/

#include<stdio.h>

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int a, b;
    while (~scanf("%d%d", &a, &b)) {
        printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
    }
    return 0;
}
