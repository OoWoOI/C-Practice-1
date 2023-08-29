/*************************************************************************
	> File Name: EP03.c
	> Author: 
	> Mail: 
	> Created Time: Tue 29 Aug 2023 10:28:22 PM CST
 ************************************************************************/

#include<stdio.h>

//求600851475143的最大质因数

int main() {
    long long num = 600851475143, i = 2;    
    while (num > i) {
        while ( num > i && num % i == 0) num /= i;
        i++;
    }
    long long ans = i;
    if (num != 1) ans = num;
    printf("ans = %lld\n", ans);
    return 0;
}
