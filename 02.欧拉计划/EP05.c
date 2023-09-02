/*************************************************************************
	> File Name: EP05.c
	> Author: 
	> Mail: 
	> Created Time: Sat 02 Sep 2023 08:51:35 PM CST
 ************************************************************************/

#include<stdio.h>

#define max 20

//欧拉计划第五题

//欧几里得算法
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int ans = 1;
    for (int i = 1; i <= max; i++) {
        ans = ans / gcd(ans, i) * i;
    }
    printf("%d\n", ans);
    return 0;
}
