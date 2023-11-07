/*************************************************************************
	> File Name: 02.如何动态申请二维数组.c
	> Author: 
	> Mail: 
	> Created Time: Tue 07 Nov 2023 08:56:56 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>



int main() {
    int arr[3][4];
    int (*brr)[4] = (int (*)[4])malloc(sizeof(int) * 3 * 4);
    arr[1][1] = 66;
    brr[2][3] = 55;
    printf("arr = %d\n", arr[1][1]);
    printf("brr = %d\n", brr[2][3]);
    return 0;
}
