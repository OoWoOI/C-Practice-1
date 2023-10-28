/*************************************************************************
	> File Name: 04.gdb_hell.c
	> Author: 
	> Mail: 
	> Created Time: Sat 28 Oct 2023 04:49:02 PM CST
 ************************************************************************/

#include<stdio.h>

int add(int a, int b) {
    return a + b;
}
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("sum = %d\n", add(a, b));
    return 0;
}
