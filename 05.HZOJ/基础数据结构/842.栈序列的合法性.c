/*************************************************************************
	> File Name: 842.栈序列的合法性.c
	> Author: 
	> Mail: 
	> Created Time: Mon 11 Sep 2023 04:47:09 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define max 1000
int input[max + 5];
int output[max + 5];

//输出数组
void printMy(int *nums, int len) {
    for (int i = 0; i < len; i++) {
        i && printf(" ");
        printf("%d", nums[i]);
    }
    putchar(10);
    return ;
}

int main() {
    int len1 = 0;
    int len2 = 0;
    //先读入栈顺序
    char tmp;
    while(scanf("%c", &tmp) == 1){
        if (tmp == ' ') continue;
        if (tmp == '\n') break;
        input[len1++] = tmp - '0';
    }

    //读取出栈顺序
    while (scanf("%c", &tmp) == 1){
        if (tmp == ' ') continue;
        if (tmp == '\n') break;
        output[len2++] = tmp - '0';
    }
    printMy(input, len1);
    printMy(output, len2);
    return 0;
}
