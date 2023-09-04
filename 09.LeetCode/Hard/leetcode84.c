/*************************************************************************
	> File Name: leetcode84.c
	> Author: 
	> Mail: 
	> Created Time: Mon 04 Sep 2023 02:56:46 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 1000

int getmin(int *heights, int start, int end) {
    int min = heights[start];
    for (int i = start; i <= end; i++) {
        min = fmin(min, heights[i]);
    }
    return min;
}

//暴力循环
int largestRectangleArea(int* heights, int heightsSize){
    int left = 0, right = heightsSize - 1, ans = 0;
    for (int i = 0; i < heightsSize; i++) {
        int tmp = 0;
        for (int j = heightsSize - 1; j >= i; j--) {
            tmp = fmax(tmp, getmin(heights, i, j) * (j - i + 1));
        }
        ans = fmax(ans, tmp);
    }
    return ans;
}

int main() {
    int arr[MAX + 5] = {0}, n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    printf("ans = %d\n", largestRectangleArea(arr, n));
    return 0;
}
