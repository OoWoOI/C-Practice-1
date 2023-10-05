/*************************************************************************
	> File Name: EP18.c
	> Author: 
	> Mail: 
	> Created Time: Thu 05 Oct 2023 07:21:36 PM CST
 ************************************************************************/

#include<stdio.h>

#define max_n 20

int nums[max_n][max_n] = {0};
int keep[max_n][max_n] = {0};

int dfs(int i, int j, int n) {
    if (i + 1 == n) return nums[i][j];
    if (keep[i][j]) return keep[i][j]; 
    int val1 = dfs(i + 1, j, n);
    int val2 = dfs(i + 1, j + 1, n);
    return keep[i][j] = (val1 > val2 ? val1 : val2 ) + nums[i][j];
}

int main() {
    for (int i = 0; i < max_n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &nums[i][j]);
        }
    }
   int ret = dfs(0, 0, 15);
    printf("%d\n", ret);
    return 0;
}
