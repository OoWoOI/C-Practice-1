/*************************************************************************
	> File Name: EP35.c
	> Author: 
	> Mail: 
	> Created Time: Sun 01 Oct 2023 09:50:21 PM CST
 ************************************************************************/

#include<stdio.h>

#define max_n 200000
#define max_m 1000000


//线性筛
int prime[max_n + 5];

void init() {
    for (int i = 2; i < max_m; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] >= max_m) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }

    }
    return 0;
}

//判断是否为圆周素数

int is_val(int num) {
    

    return 1;
}

int main() {
    for (int )

    return 0;
}
