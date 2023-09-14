/*************************************************************************
	> File Name: 05.输出分数档位.c
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Sep 2023 08:37:21 PM CST
 ************************************************************************/

#include<stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("FOOLISH\n");
    } else if (n < 60 && n > 0) {
        printf("FAIL\n");
    } else if (60 <= n && n < 75) {
        printf("MEDIUM\n");
    } else if (75 <= n && n <= 100) {
        printf("GOOD\n");
    }
    return 0;
}
