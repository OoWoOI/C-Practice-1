/*************************************************************************
	> File Name: 10.取位数.c
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Sep 2023 09:23:32 PM CST
 ************************************************************************/

#include<stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int digits = 0;
    do {
        n /= 10;
        digits++;
    } while (n);
    printf("%d\n", digits);
    return 0;
}
