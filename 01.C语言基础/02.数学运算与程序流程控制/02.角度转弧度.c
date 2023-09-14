/*************************************************************************
	> File Name: 02.角度转弧度.c
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Sep 2023 07:30:17 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main() {
    int x;
    const double pi = acos(-1);
    scanf("%d", &x);
    printf("%lf\n", (x / 180 * 1.0) * (pi));//
    return 0;
}
