/*************************************************************************
	> File Name: 01.素数筛算法.c
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 08:44:27 PM CST
 ************************************************************************/

#include<stdio.h>
#define max 100

int prime[max + 5] = {0};
/*
void init_prime() {
    prime[0] = 1, prime[1] = 1;
    for (int i = 0; i <= max; i++) {
        if (prime[i]) continue;
        for (int j = i * i; j <= max; j += i) {
            prime[j] = 1;
        }
    }
    return ;
}
*/

int prime_1(int n) {
    if (n < 2) return 1;
    for (int i = 2; i < n; i++) {
        if (n % i) continue;
        return 1;
    }
    return 0;
}

int main() {
    //init_prime();
    int n;
    while (~scanf("%d", &n)) {
//        printf("%s\n", prime[n] ? "No" : "Yes");
        printf("%s\n", prime_1(n) ? "NO" : "Yes");
    }
    return 0;
}
