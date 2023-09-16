/*************************************************************************
	> File Name: 02.函数指针.c
	> Author: 
	> Mail: 
	> Created Time: Fri 15 Sep 2023 10:13:46 PM CST
 ************************************************************************/

#include<stdio.h>

//分段函数

//求阶乘
int fac1(int n) {
    return n == 1 ? 1 : n * fac1(n - 1);
}

//求数列和
int fac2(int n) {
    return (n + 1) * n / 2;
}

//分段函数
int func(int (*f1)(int), int (*f2)(int), int x) {
    return x < 15 ? f1(x) : f2(x);
}

int main() {
    int n;
    while (~scanf("%d", &n)) {
        printf("func(%d) = %d\n", n, func(fac1, fac2, n));
    }
    return 0;
}
