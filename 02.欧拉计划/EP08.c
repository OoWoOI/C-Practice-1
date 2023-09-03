/*************************************************************************
	> File Name: EP08.c
	> Author: 
	> Mail: 
	> Created Time: Sun 03 Sep 2023 10:07:38 PM CST
 ************************************************************************/

#include<stdio.h>

//欧拉计划第八题
//滑动窗法

int main() {
    
    int ans = 0, k = 0, ret = 0, zero = 0;
    int arr[1005];
    for (int i = 0; i < 1000; i++) scanf("%d", &arr[i]);
    
    for (int i = 0; i < 1000; i++) {
        if (arr[i] == 0) {
            zero++;
            k++;
            continue;
        }
        ret *= arr[i];
        if (k < 4) continue;
        if (arr[i - k] == 0) zero--;
        else {
            
        }

    }
    return 0;
}
