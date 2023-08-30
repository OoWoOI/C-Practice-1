/*************************************************************************
	> File Name: EP04.c
	> Author: 
	> Mail: 
	> Created Time: Wed 30 Aug 2023 10:09:47 PM CST
 ************************************************************************/

#include<stdio.h>

//EP04:
//欧拉计划第四题：找到由两个三位数相乘的最大回文乘积

int is_val(int x) {
    int tmp = 0, p = x;
    while (p) {
        tmp = (tmp * 10) + (p % 10);
        p /= 10;
    }
    return tmp == x;
}

int main() {
    int max = 0;
    for (int i = 100; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            if (is_val(i * j) == 0) continue;
            if (max < i * j) {
                printf("%d * %d = %d\n", i, j, i * j);
                max = i * j;
            }
        }
    }
    printf("ans = %d\n", max);
    return 0;
}
