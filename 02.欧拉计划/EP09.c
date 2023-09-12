/*************************************************************************
	> File Name: EP09.c
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Sep 2023 10:23:01 PM CST
 ************************************************************************/

#include<stdio.h>
//欧拉计划第九题
#include<math.h>


int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int ans = 0;
    for (int n= 1; n <= 33; n++) {
         for (int m = n + 1; m < 33; m++) {
            if (gcd(m, n) != 1) continue;
            int a = 2 * n * m;
            int b = m * m - n * n;
            int c = m * m + n * n;
            if (1000 % (a + b + c) == 0) {
                int k = 1000 / (a + b + c);
                ans = a * b * c * (int)pow(k, 3);
            }
            if (ans) break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
