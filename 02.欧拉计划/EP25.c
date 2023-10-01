/*************************************************************************
	> File Name: EP25.c
	> Author: 
	> Mail: 
	> Created Time: Sun 01 Oct 2023 07:00:56 PM CST
 ************************************************************************/

#include<stdio.h>

int F[3][1005];

int main() {
    int n = 2;
    F[1][0] = 1;
    F[1][1] = 1;
    F[2][0] = 1;
    F[2][1] = 1;
    while (F[n % 3][0] < 1000) {
        n++;
        int *a = F[n % 3], *b = F[(n - 1) % 3], *c = F[(n - 2) % 3];
        for (int i = 1; i <= b[0]; i++) {
            a[i] = b[i] + c[i]; 
        }
        a[0] = b[0];
        for (int i = 1; i <= a[0]; i++) {
            if (a[i] < 10) continue;
            a[i + 1] += (a[i] / 10);
            a[i] %= 10;
            a[0] += (i == a[0]);
        }

    }
    printf("%d\n", n);
    return 0;
}


