/*************************************************************************
	> File Name: leetcode.5_最长回文子串.c
	> Author: 
	> Mail: 
	> Created Time: Fri 15 Sep 2023 03:17:20 PM CST
 ************************************************************************/

//难度：中等

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 1000

//验证是否为回文子串
int isPalind(char *s, int start, int end) {
    char *str = strndup(s + start, end - start + 1);
    int flag = 0;
    char *temp = (char *)calloc(sizeof(char), (end - start + 1));
    for (int i = end - start, I = 0; i >= 0; i--) {
        temp[I++] = str[i];
    }

    flag = (strcmp(str, temp) == 0);
    //printf("%s %s\n", str,temp);
    free(str);
    free(temp);
    return flag;
}

/**

//暴力解法
char *longestPalindrome(char *s) {
    int n = strlen(s);
    if (n < 2) return s;
    int maxlen = 0;//最大长度
    int bigen = 0;//子串起始长度
    //暴力循环
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((j - i) > maxlen && isPalind(s, i, j)) {
                bigen = i;
                maxlen = j - i;
            }
        }

    }

    return strndup(s + bigen, maxlen + 1);
}

**/

//中心扩撒

//动态规划

//马拉车算法


int main() {
    char str[max + 5] = {0};
    scanf("%s", str);
    printf("%s\n", longestPalindrome(str));
    return 0;
}
