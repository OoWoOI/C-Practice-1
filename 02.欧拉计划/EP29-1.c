/*************************************************************************
	> File Name: EP29-1.c
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Oct 2023 08:20:34 PM CST
 ************************************************************************/

//暴力解法

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_N 10000
#define max_n 100
#define MAX_M 210

int *cnt[MAX_N] = {0};
int len = 0;

//计算
int *calc(int a, int b) {
    int *tmp = (int *)calloc(sizeof(int), MAX_M);
    tmp[0] = 1; tmp[1] = 1;
    
    for (int i = 0; i < b; i++) {
        for (int j = 1; j <= tmp[0]; j++) {
            tmp[j] *= a;
        }

        for (int k = 1; k <= tmp[0]; k++) {
            if (tmp[k] < 10) continue;
            tmp[k + 1] += tmp[k] / 10;
            tmp[k] %= 10;
            tmp[0] += (k == tmp[0]);
        }
    }

    return tmp;
}

int is_same(int *num) {
    
    for (int i = 0; i < len; i++) {
        if (memcmp(cnt[i], num, sizeof(int) * MAX_M)) continue;
        return i + 1;
    }
    return 0;
}

int main() {
    for (int a = 2; a <= max_n; a++) {
        for (int b = 2; b <= max_n; b++) {
            int *tmp = calc(a, b);
            if (is_same(tmp)) {
                free(tmp);
                continue;
            }
            cnt[len++] = tmp;
        }
    }
    printf("%d\n", len);
    return 0;
}
