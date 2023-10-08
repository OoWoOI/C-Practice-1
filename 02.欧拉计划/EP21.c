/*************************************************************************
	> File Name: EP21.c
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Oct 2023 08:52:58 PM CST
 ************************************************************************/

#include<stdio.h>

#define MAX_N 10000

int prime[MAX_N + 5];
int f[MAX_N + 5];
int cnt[MAX_N + 5];
int d[MAX_N + 5];

void init() {
    
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            f[i] = 2;
            cnt[i] = 1;
        }

        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                f[i * prime[j]] = f[i] / (cnt[i] + 1) * (cnt[i] + 2);
                cnt[i * prime[j]] = cnt[i] + 1;
                break;
            } else {
                f[i * prime[j]] = f[i] * f[prime[j]];
                cnt[i * prime[j]] = 1;
            }

        }    
        
    }
    
}

int get_sum(int cnt, int num) {
    int sum = 0; 
    for (int i = 1; i < num && cnt; i++) {
        if (num % i) continue;
        sum += i;
        cnt--;
    }
    return sum;
}


int main() {
    init();
    int sum = 0;
    for (int i = 0; i <= MAX_N; i++) {
        d[i] = get_sum(f[i], i);
    }

    for (int i = 0; i <= MAX_N; i++) {
        if (d[d[i]] == i && d[i] != i ) {
            printf("%d %d\n", i, d[i]);
            sum += i;
        }
    }

    printf("%d\n", sum);
    return 0;
}
