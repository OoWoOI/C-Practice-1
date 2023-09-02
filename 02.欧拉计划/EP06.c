/*************************************************************************
	> File Name: EP06.c
	> Author: 
	> Mail: 
	> Created Time: Sat 02 Sep 2023 09:01:27 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define max 100

//欧拉计划第六题

int main() {
    //和平方
    int sum1 = (max + 1) * (max) / 2;
    sum1 = (int)pow(sum1, 2);
    //平方和
    int sum2 = max * (max + 1) * (2 * max + 1) / 6;
    printf("%d\n", sum1 - sum2);
    return 0;
}
