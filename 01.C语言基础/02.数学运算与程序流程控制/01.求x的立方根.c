/*************************************************************************
	> File Name: 01.求x的立方根.c
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Sep 2023 07:26:01 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main() {
    int x;
    scanf("%d", &x);
    printf("ans = %.2lf\n", pow(x, 1.0 / 3));
    return 0;
}
