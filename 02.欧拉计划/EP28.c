/*************************************************************************
	> File Name: EP28.c
	> Author: 
	> Mail: 
	> Created Time: Thu 28 Sep 2023 08:34:48 PM CST
 ************************************************************************/

#include<stdio.h>
//欧拉计划28题
int main() {
    long long sum = 1;
    for (int m = 3; m <= 1001; m += 2) {
        sum += 4 * (m * m) - 6 * m + 6;
    }
    printf("%lld\n", sum);
    return 0;
}
