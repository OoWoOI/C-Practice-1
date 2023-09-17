/*************************************************************************
	> File Name: 01.binary_search.c
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 09:30:59 PM CST
 ************************************************************************/

#include<stdio.h>

//查找数组中的x
int binary_search(int *arr, int len, int x) {
    int l = 0, r =len - 1, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}


//求解平方
int arrs(int x) {
    return x * x;
}

int binary_search1(int (*f1)(int), int x) {
    int l = 0, r = x, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (f1(mid) == x) return mid;
        if (f1(mid) < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

//求第一个1
int binary_search2(int *arr, int n, int x) {
    int l = 0, r = n, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (arr[mid] >= x) r = mid;
        else l = mid + 1;
    } 
    return l == n ? -1 : l;
}
//求最后一个1
int binary_search3(int *arr, int n, int x) {
    int l = -1, r = n - 1, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (arr[mid] >= x) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}


int main() {
    int arr[100];
    int n;
    printf("请输入数组长度: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", arr + i);
    int x;
    printf("请输入带查找的X:");
    scanf("%d", &x);
    int ret = binary_search(arr, n, x);
    printf("%d\n", ret);
    
    printf("请输入平方数:");
    //求解平方:简易版
    scanf("%d", &x);
    ret = binary_search1(arrs, x);
    printf("%d * %d = %d\n", ret, ret, x);
    //求第一个1
    int nums[10] = {1,1,1,1,1,1, 0, 0, 0}; 
    ret = binary_search2(nums, 10, 1);
    printf("求第一个1: %d\n", ret);

    //求最后一个1
     ret = binary_search3(nums, 10, 1);
    printf("求最后一个1: %d\n", ret);
    return 0;
}
