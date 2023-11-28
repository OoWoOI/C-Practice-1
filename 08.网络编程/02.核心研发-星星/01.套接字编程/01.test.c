/*************************************************************************
	> File Name: 01.test.c
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Nov 2023 03:24:34 PM CST
 ************************************************************************/

#include<stdio.h>
//测试云主机是大端机还是小端机?
//答:小端机
int main() {
    int a = 321;
    char *p = (char *)&a;
    printf("addr = %p, val = %#x\n", p, *(p));
    printf("addr = %p, val = %#x\n", p + 1, *(p + 1));
    printf("addr = %p, val = %#x\n", p + 2, *(p + 2));
    printf("addr = %p, val = %#x\n", p + 3, *(p + 3));
    return 0;
}
