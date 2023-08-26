/*************************************************************************
	> File Name: EP02.c
	> Author: 
	> Mail: 
	> Created Time: Sat 26 Aug 2023 08:43:30 PM CST
 ************************************************************************/

#include<stdio.h>

#define MAX_N 50
#define MAX_NUM 4000000

/*
欧拉计划02:
    求斐波那契数列中值小于400万的偶数项和
* */


//思路1.暴力解法
/**
long long fnum[MAX_N + 5] = {1, 1, 2};

int main() {
    int n = 3;
    long long sum = 2;
    while (fnum[n - 1] + fnum[n - 2] <=  MAX_NUM) {
        fnum[n] = fnum[n - 1] + fnum[n - 2];
        (fnum[n] % 2 == 0) && (sum += fnum[n]);
        n++;
    }
    printf("sum = %lld, n = %d\n", sum, n);
    return 0;
}
**/

//思路2.滚动数组
int fnum[2] = {1, 1};
int main() {
    int n = 2;
    int sum = 0;
    while (fnum[(n - 1) % 2] + fnum[(n - 2) % 2] <= MAX_NUM) {
        fnum[(n) % 2] = fnum[(n - 1) % 2] + fnum[(n - 2) % 2];
        sum += (fnum[(n) % 2] % 2 == 0) ? fnum[(n) % 2] : 0;
        n++;
    } 
    printf("sum = %d\n", sum);
    return 0;
}
