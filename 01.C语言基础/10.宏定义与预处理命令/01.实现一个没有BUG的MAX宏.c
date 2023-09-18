/*************************************************************************
	> File Name: 01.实现一个没有BUG的MAX宏.c
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Sep 2023 07:39:10 PM CST
 ************************************************************************/

#include<stdio.h>

#define MAX(a, b) ({\
    __typeof(a) __a = a;\
    __typeof(b) __b = b;\
    __a > __b ? __a : __b;\
})

int main() {
    printf("MAX(2, 3) = %d\n", MAX(2, 3));
    printf("5 + MAX(2, 3) = %d\n",  5 + MAX(2, 3));
    printf("MAX(2, MAX(3, 4)) = %d\n", MAX(2, MAX(3, 4)));
    printf("MAX(2, 3 > 4 ? 3 : 4) = %d\n", MAX(2, 3 > 4 ? 3 : 4));
    int a = 7;
    printf("MAX(a++, 6) = %d\n", MAX(a++, 6));
    printf("a = %d\n", a);
    return 0;
}
