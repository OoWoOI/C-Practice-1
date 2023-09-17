/*************************************************************************
	> File Name: 02.数组与地址.c
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 09:17:15 PM CST
 ************************************************************************/

#include<stdio.h>

void funcA(int *a) {
    (*a) = 123;
    return ;
}

void funcB(int *arr) {
    printf("funcB = %lu\n", sizeof(arr));
    return ;
}

void funcC(int (*arr)[100]) {
    printf("funcC = %p funcC + 1 = %p\n", arr, arr + 1);
    return ;
}

int main() {
    int a = 0;
    int arr[100];
    printf("a = %d\n", a);
    printf("arr = %p arr + 1 = %p\n", arr, (arr + 1));
    funcB(arr);
    printf("arr = %lu\n", sizeof(arr));
    int nums[100][100];
    funcC(nums);
    printf("nums = %p nums + 1 = %p\n", nums, nums + 1);
    return 0;
}
