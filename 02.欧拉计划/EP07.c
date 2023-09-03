/*************************************************************************
	> File Name: EP07.c
	> Author: 
	> Mail: 
	> Created Time: Sun 03 Sep 2023 09:20:15 PM CST
 ************************************************************************/

#include<stdio.h>

#define max 200000

int prime[max + 5] = {0};

//线性筛
void prime_fun()  {
    for (int i = 2; i < max; i++) {
        if (prime[i] == 0) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}


//欧拉计划7题
int main() {
    prime_fun();
    printf("%d\n", prime[10001]);
    return 0;
}
