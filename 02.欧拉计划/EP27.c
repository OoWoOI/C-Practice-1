/*************************************************************************
	> File Name: EP27.c
	> Author: 
	> Mail: 
	> Created Time: Tue 10 Oct 2023 07:15:51 PM CST
 ************************************************************************/


#include <stdio.h>
#include<stdbool.h>
#include <limits.h>
#include <inttypes.h>
#include <time.h>
#include <stdlib.h>

#define MAX_N 1000
#define MAX_M 2500
#define R_M_TEST_ROUND 30

long long prime[MAX_M + 5] = {0};

long long gcd(int32_t a, int32_t b) {
    if (!b) return a;
    return gcd(b, a % b);
}

bool R_M_TEST(long long x) {
    if (x <= 1) return false;
    long long a, m, ans;
    for (long long i = 0; i < R_M_TEST_ROUND; i++) {
        a = (rand() % (x - 1)) + 1;
        ans = 1;
        m = x - 1;
        while (m) {
            if (m % 2) ans = (ans * a) % x;
            a = (a * a) % x;
            m /= 2;
        }
        if (ans != 1) return false;
    }
    return true;
}

long long HowManyPrime(int32_t a, int32_t b) {
    long long i = 0;
    while (R_M_TEST(i * i + a * i + b)) ++i;
    return i;
}

int main() {
    srand(time(0));
    prime[1] = INT_MAX;
    for (long long i = 2; i <= MAX_M; i++)
        if (!prime[i])
            for (long long j = i; j <= MAX_M; j += i)
                if (!prime[j]) prime[j] = i;
        long long maxNum = 40, tempNum, result = 0;
        for (long long a = 1 - MAX_N; a < MAX_N; a++)
        for (long long b = (a < 0 ? -a + 1 : 2); b < MAX_N; b++) {
            if (prime[b] != b) continue;
            if (prime[b + a + 1] != b + a + 1) continue;
            if (a > 0 && b > 0 && prime[gcd(a, b)] <= maxNum) continue;
            tempNum = HowManyPrime(a, b);
            if (tempNum > maxNum) {
                result = a * b;
                maxNum = tempNum;
            }
        }
    printf("%lld\n", result);
    return 0;

}


