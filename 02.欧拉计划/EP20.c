/*************************************************************************
	> File Name: EP20.c
	> Author: 
	> Mail: 
	> Created Time: Thu 05 Oct 2023 07:58:35 PM CST
 ************************************************************************/

#include<stdio.h>

#define max_n 100

int ans[max_n + 5] = {0};

int main() {
    ans[0] = 1, ans[1] = 1;
    for (int i = 1; i <= max_n; i++) {
        for (int k = 1; k <= ans[0]; k++) ans[k] *= i;

        for (int t = 1; t <= ans[0]; t++) {
            if (ans[t] < 10) continue;
            ans[t + 1] += ans[t] / 10;
            ans[t] %= 10;
            ans[0] += (t == ans[0]);
        }
    
    }
    int sum = 0;
    for (int i = 1; i <= ans[0]; i++)  sum += ans[i];
    printf("%d\n", sum);
    return 0;
}
