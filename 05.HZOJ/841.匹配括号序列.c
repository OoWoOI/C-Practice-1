/*************************************************************************
	> File Name: HZOJ.841_匹配括号序列.c
	> Author: 
	> Mail: 
	> Created Time: Mon 11 Sep 2023 04:23:14 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 1000000
char str[max + 5];

int isValid(char *str) {
    int top = -1;
    int len = (int)strlen(str);
    char *stk = (char *)malloc(sizeof(char) * len);
    for (int i = 0; str[i]; i++) {
        switch(str[i]) {
            case '}': {
                if (top != -1 && stk[top] == '{') {
                    top--;
                } else {
                    stk[++top] = str[i];
                }
            } break;
            case ')': {
                if (top != -1 && stk[top] == '(') {
                    top--;
                } else {
                    stk[++top] = str[i];
                }
            } break;
            case ']': {
                if (top != -1 && stk[top] == '[') {
                    top--;
                } else {
                    stk[++top] = str[i];
                }
            } break;
            default : {
                stk[++top] = str[i];
            } break;
        }
    }
    free(stk);
    return top == -1;
}

int main() {
    scanf("%s", str);
    int flag = isValid(str);
    printf("%s\n", flag ? "YES" : "NO");
    return 0;
}
