/*************************************************************************
	> File Name: EP16.c
	> Author: 
	> Mail: 
	> Created Time: Wed 04 Oct 2023 09:18:19 PM CST
 ************************************************************************/

#include<stdio.h>
#define max 1000

int ans[max + 5];

int main() {
    ans[0] = 1, ans[1] = 1;
    for (int i = 0; i < max; i++) {
        for (int j = 1; j <= ans[0]; j++) {
            ans[j] *= 2;
        }
        for (int k = 1; k <= ans[0]; k++) {
            if (ans[k] < 10) continue;
            ans[k + 1] += ans[k] / 10;
            ans[k] %= 10;
            ans[0] += (k == ans[0]);
        }

    }
    int sum = 0;
    for (int i = 1; i <= ans[0]; i++) sum += ans[i];
    printf("%d\n", sum);
    return 0;
}
