/*************************************************************************
	> File Name: EP22.c
	> Author: 
	> Mail: 
	> Created Time: Thu 05 Oct 2023 08:20:19 PM CST
 ************************************************************************/

#include<stdio.h>
#include<input22.h>
#include<stdlib.h>
#include<string.h>

//快速排序
void msort(char (*str)[200], int l, int r) {
    if (l >= r) return ; 
    
    int x = l, y = r;
    char *mid = strdup(str[l]);
    while (x < y) {
        while (x < y && strcmp(str[y], mid) >= 0) y--;
        if (x < y) strcpy(str[x++], str[y]);
        while (x < y && strcmp(str[x], mid) <= 0) x++;
        if (x < y) strcpy(str[y--], str[x]);
    }
    strcpy(str[x], mid);
    msort(str, l, x - 1);
    msort(str, x + 1, r);
    return ;
}


int main() {
    int len = 0;
    while (strlen(nameList[len])) len++;
    msort(nameList, 0 , len - 1);
    long long  ans = 0, sum;
    for (int i = 0; i < len; i++) {
        sum = 0;
        printf("%s\n", nameList[i]);
        for (int j = 0; nameList[i][j]; j++) {
            sum += (nameList[i][j] - 'A' + 1);
        }
        sum *= (i + 1);
        ans += sum;
    }
    printf("%lld\n", ans);

    return 0;
}
