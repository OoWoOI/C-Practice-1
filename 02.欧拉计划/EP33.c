/*************************************************************************
	> File Name: EP33.c
	> Author: 
	> Mail: 
	> Created Time: Sun 01 Oct 2023 09:07:41 PM CST
 ************************************************************************/

#include<stdio.h>

//求得最大公约数

int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}

int is_val(int a, int b) {
    int x1 = a / 10, x2 = a % 10;
    int y1 = b / 10, y2 = b % 10;

    if (!x1 || !x2 || !y1 || !y2) return 0;
    
    if (x1 == y1 && x2 * b == y2 * a && x2 != 0) return 1;
    if (x1 == y2 && x2 * b == y1 * a && x2 != 0) return 1;
    if (x2 == y1 && x1 * b == y2 * a && x1 != 0) return 1;
    if (x2 == y2 && x1 * b == y1 * a && x1 != 0) return 1;
    return 0;
}

int main() {
    int a = 1, b = 1;
    for (int n = 10; n < 100; n++) {
        for (int m = n + 1; m < 99; m++) {
            if (!is_val(n, m)) continue;
            printf("a = %d b = %d\n", n, m);
            a = a * n;
            b = b * m;
            int k = gcd(a, b);
            a /= k;
            b /= k;
        }
    }    
    printf("%d\n", b);
    return 0;
}
