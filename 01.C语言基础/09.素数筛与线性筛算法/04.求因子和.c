/*************************************************************************
	> File Name: 04.求因子和.c
	> Author: 
	> Mail: 
	> Created Time: Tue 03 Oct 2023 09:57:39 PM CST
 ************************************************************************/

#include<stdio.h>
#define MAX_N 100

int prime[MAX_N + 5] = {1, 1};

void init() {
    //素数筛
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[i]  = 1;
            //continue;
        }
        for (int j = i; j <= MAX_N; j += i) {
            if (prime[j] == 0) prime[j] = i + 1;
            else prime[j] += i;
        }

    }
}

int main() {
    init();
    for (int i = 1; i <= MAX_N; i++) {
        printf("%d\n", prime[i]);
    }
    return 0;
}
