/*************************************************************************
	> File Name: EP47.c
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Oct 2023 07:57:46 PM CST
 ************************************************************************/

#include<stdio.h>

#define MAX_N 1000000

int prime[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i]) continue;
        for (int j = i; j <= MAX_N; j += i) {
            prime[j] += 1;
        }
    }
}

int main() {
    init();
    int ans = 0;
    for (int i = 1; i <= MAX_N; i++) {
        int flag = 1;
        for (int j = 0; j < 4 && flag; j++) {
            flag = prime[i + j] == 4;
        }
        if (!flag) continue;
        ans = i;
        break;
    }
    printf("%d\n", ans);
    return 0;
}
