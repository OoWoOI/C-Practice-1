/*************************************************************************
	> File Name: 08.find.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Oct 2023 07:30:28 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;


int mycmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}


// 二分查找算法与两种特殊的二分查找算法

int *initArr(int n) {
    int *nums = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        //nums[i] = rand() % 100;
         nums[i] = rand() % 2;
        //  nums[i] = 1;
        //nums[i] = 0;
    }
    return nums;
}


//普通二分查找算法
int binary_search(int *nums, int size, int target){
    int head = 0, tail = size - 1;

    while (head <= tail) {
        int mid = (head + tail) >> 1;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) {
            head = mid + 1;
        } else {
            tail = mid - 1;
        }
    }

    return -1;
}

//取第一个出现的1
int binary_search_first(int *nums, int size, int target) {
    int head = 0, tail = size;
    while (head < tail) {
        int mid = (head + tail) >> 1;
        if (nums[mid] == target) {
            tail = mid;
        } else {
            head = mid + 1;
        }
    }

    return head == size ? -1 : head;
}


//取最后一个出现的1
int binary_search_last(int *nums, int size, int target) {
    int head = -1, tail = size - 1; 
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (nums[mid] == target) {
            head = mid;
        } else {
            tail = mid - 1;
        }
        
    }
    return head;
}

int main() {
    #define max_op 20
    srand(time(0));
    
    int *nums = initArr(max_op);
    qsort(nums, max_op, sizeof(int), mycmp); 
    for (int i = 0; i < max_op; i++) {
        printf("%d ", nums[i]);
    }
    putchar('\n');
    int val;
    /**
    while (scanf("%d", &val) != EOF) {
        int ret = binary_search(nums, max_op, val);
        printf("search va(%d) from nums is %d\n", val, ret);
    }
    **/
    
    int ret = binary_search_first(nums, max_op, 1);
    printf("this first num(1) is ind(%d)\n", ret);
    ret = binary_search_last(nums, max_op, 1);
    printf("this last num(1) is ind(%d)\n", ret);
    #undef max_op
    return 0;
}
