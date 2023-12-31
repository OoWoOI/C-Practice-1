/*************************************************************************
	> File Name: EP39.c
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Oct 2023 08:21:14 PM CST
 ************************************************************************/

#include<stdio.h>
#define max_n 1000

int cnt[max_n + 5] = {0};

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int main() {
    
    for (int n = 2; n <= 32; n++) {
        for (int m = n + 1; m <= 32; m++) {
            if (gcd(n, m) != 1) continue; 
            int a = m *m - n * n;
            int b = 2 * m * n;
            int c = m * m + n * n;
            for (int p = a + b + c; p <= max_n; p += (a + b + c)) {
                cnt[p] += 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= max_n; i++) {
        if (cnt[i] > cnt[ans]) ans = i;
    }
    printf("%d\n", ans);
    return 0;
}
