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

//单调栈
int largestRectangleArea_1(int *heights, int heightsSize) { 
    int ans = 0;
    int stack[heightsSize + 5], top = -1;
    //1、遍历数组中的元素
    for (int i = 0; i < heightsSize; i++) {
        //1.1、采用栈的性质，当栈不为空时比较栈顶元素与第i个元素的大小
        while ( top != -1 && heights[stack[top]] > heights[i]) {
            //1.1.1、代码到这说明栈结构的单调性被破坏，栈顶元素需要进行出栈并计算面积大小。
            int length = heights[stack[top--]];
            //1.1.2、当栈结构为空了，说明当前元素是已经遍历过元素中最小的，因此它的宽度就等于它的下标
            int weight = i;
            if (top != -1) {
                weight = i - stack[top] - 1;
            }
            //1.1.3、计算比较当前面积与前面最大结果的大小
            ans = fmax(ans, length * weight);
        }
        stack[++top] = i;
    } 
    //2、防止在栈结构中还有元素存在。
    while (top != -1) {
        int length = heights[stack[top--]];
        //2.1、当栈为空时，说明栈顶元素的大小应该是整个数组最小的
        int weight = heightsSize;
        if (top != -1) {
            weight = heightsSize - stack[top] - 1;
        }
        ans = fmax(ans, length * weight);
    }
    return ans;
}


int main() {
    int arr[MAX + 5] = {0}, n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    printf("暴力解法 = %d\n", largestRectangleArea(arr, n));
    printf("单调栈解法 = %d\n", largestRectangleArea_1(arr, n));
    return 0;
}
