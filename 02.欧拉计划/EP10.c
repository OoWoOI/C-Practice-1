/*************************************************************************
	> File Name: EP10.c
	> Author: 
	> Mail: 
	> Created Time: Wed 13 Sep 2023 09:02:27 PM CST
 ************************************************************************/

#include<stdio.h>
#define max 2000000

int prime[max + 5];
long long sum = 0;
//线性筛
void func_prime() {
    for (int i = 2; i <= max; i++) {
        if (prime[i] == 0) {
            prime[++prime[0]] = i;
            sum += i;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }

}

int main() {
    func_prime();
    printf("sum : %lld\n", sum);
    return 0;
}
