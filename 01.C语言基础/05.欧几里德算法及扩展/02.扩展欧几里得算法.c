/*************************************************************************
	> File Name: 02.扩展欧几里得算法.c
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 02:03:36 PM CST
 ************************************************************************/

#include<stdio.h>

int exc_gcd(int a, int b, int *x, int *y) {
    if (!b) {
        *x = 1;
        *y = 0;
        return a;
    }
    int xx, yy, ret = exc_gcd(b, a % b, &xx, &yy);
    (*x) = yy;
    (*y) = xx - (a / b) * yy;
    return ret;
}

int main() {
    int a, b, x, y;
    while (~scanf("%d%d", &a, &b)) {
        printf("gcd(%d, %d) = %d\n", a, b, exc_gcd(a, b, &x, &y));
        printf("%d * %d + %d * %d = %d\n", a, (x), b,(y), a * (x) + b * (y));
    }
    return 0;
}
