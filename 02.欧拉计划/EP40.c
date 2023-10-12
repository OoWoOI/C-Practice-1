/*************************************************************************
	> File Name: EP40.c
	> Author: 
	> Mail: 
	> Created Time: Thu 12 Oct 2023 07:38:14 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define MAX_N 1000000
char num[MAX_N + 5];


void init() {
    //生成100W长度的字符串
    int i = 1;
    int len = 0;
    while ( (len = strlen(num)) < MAX_N) {
        sprintf(num + len, "%d", i);
        i++;
    }
}

int main() {
    init();
    int ans = 1;
    for (int i = 0, exp = 1; i < 7; i++, exp *= 10) {
        ans *= num[exp - 1] - '0';;
    }
    printf("%d\n", ans);
    return 0;
}
