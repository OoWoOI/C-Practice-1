/*************************************************************************
	> File Name: 01.素数筛.c
	> Author: 
	> Mail: 
	> Created Time: Tue 03 Oct 2023 09:56:56 PM CST
 ************************************************************************/

#include<stdio.h>
#define max 100

int prime[max + 5] = {1, 1};

void init() {
    for (int i = 2; i <= max; i++) {
        if (prime[i]) continue;
        for (int j = 2; j * i <= max; j++) {
            prime[i * j] = 1;
        }
    }
    return ;
}

int main() {
    init();
    for (int i = 0; i <= max; i++) {
        !prime[i] && printf("%d\n", i);
    }
    return 0;
}
