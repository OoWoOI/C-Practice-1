/*************************************************************************
	> File Name: 03.求因子个数.c
	> Author: 
	> Mail: 
	> Created Time: Tue 03 Oct 2023 09:57:25 PM CST
 ************************************************************************/

#include<stdio.h>

#define max 100

int prime[max + 5];

int F[max + 5];

int cnt[max + 5];

void init() {
    for (int i = 2; i <= max; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            F[i] = 2;
            cnt[i] = 1;
        }
        for (int j = 1; j <= prime[0] && prime[j] * i <= max; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                F[i * prime[j]] = F[i] / (cnt[i] + 1) * (cnt[i] + 2);
                cnt[i * prime[j]] = cnt[i] + 1;
                break;
            } else {
                F[i * prime[j]] = F[prime[j]] * F[i];
                cnt[i * prime[j]] = 1;
            }
        }

    }

    return ;
}

int main() {
    init();
    for (int i = 2; i <= max; i++) {
        printf("%d = %d\n", i, F[i]);
    }
    return 0;
}
