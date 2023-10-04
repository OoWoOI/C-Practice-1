/*************************************************************************
	> File Name: 02.线性筛.c
	> Author: 
	> Mail: 
	> Created Time: Tue 03 Oct 2023 09:57:07 PM CST
 ************************************************************************/

#include<stdio.h>
#define max 100

int prime[max + 5];

void init() {
    for (int i = 2; i <= max; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && prime[j] * i <= max; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int main() {
    init();
    for (int i = 1; i <= prime[0]; i++) printf("%d\n", prime[i]);
    return 0;
}
