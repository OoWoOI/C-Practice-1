/*************************************************************************
	> File Name: 02.funcation.c
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 07:26:48 PM CST
 ************************************************************************/

#include<stdio.h>


int funcA(int);
int funcB(int);
/*
int funcA(int n) {
    printf("funcA = %d\n", n);
    if (n == 0) return 0;
    funcB(n - 1);
    return n;
}

int funcB(int n) {
    printf("funcB = %d\n", n);
    if(n == 0) return 0;
    funcA(n - 1);
    return n;
}
*/

int main() {
    funcA(6);
    funcB(6);
    return 0;
}
