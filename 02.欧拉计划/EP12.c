/*************************************************************************
	> File Name: EP12.c
	> Author: 
	> Mail: 
	> Created Time: Tue 03 Oct 2023 09:19:21 PM CST
 ************************************************************************/

#include<stdio.h>

#define max 1000000

typedef long long lint;

lint prime[max + 5];

lint F[max + 5];

lint cnt[max + 5];

void init() {
    for (lint i = 2; i <= max; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            F[i] = 2;
            cnt[i] = 1;
        }
        for (lint j = 1; j <= prime[0] && prime[j] * i <= max; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                F[i * prime[j]] = F[i] / (cnt[i] + 1) * (cnt[i] + 2);
                cnt[i * prime[j]] = cnt[i]  + 1;
                break;
            } else {
                F[i * prime[j]] = F[prime[j]] * F[i];
                cnt[i * prime[j]] =  1;
            }
        }

    }
    
    return ;
}


int main() {
    init();
    lint n = 3;
    lint fmax;
    while(1) {
        if (n & 1) {
            fmax = F[n ] * F[(n + 1) >> 1];
        } else {
            fmax = F[n >> 1] * F[(n + 1)];
        }
        if (fmax > 500) break;
        n++;
    }
    printf("%lld\n", n * (n + 1) / 2);
    return 0;
}
