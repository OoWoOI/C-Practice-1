/*************************************************************************
	> File Name: EP36.c
	> Author: 
	> Mail: 
	> Created Time: Thu 28 Sep 2023 09:51:17 PM CST
 ************************************************************************/

#include<stdio.h>
#define max 1000000

int is_val(int x, int base) {
    int tmp = x, ans = 0;
    while (tmp) {
        ans = ans * base + tmp % base;
        tmp /= base;
    }
    return ans == x;
}

int main() {
    int sum = 0;
    for (int i = 1; i <= max; i++) {
        if (is_val(i, 10) && is_val(i, 2)) sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
