/*************************************************************************
	> File Name: 01.stable_sort.c
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Sep 2023 07:12:05 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


#define TEST(arr, func, n, args...) {\
    int *nums = (int *)malloc(sizeof(int) * n);\
    memcpy(nums, arr, sizeof(int) * n);\
    func(args);\
    printf("[");\
    for (int i = 0; i < n; i++) {\
        i && printf(" ");\
        printf("%d", nums[i]);\
    }\
    printf("] <=== %s[%d]\n", #func, n);\
    free(nums);\
}

#define swap(a, b) {\
    __typeof(a) __tmp = a; a = b; b = __tmp;\
}

//稳定排序：冒泡、插入、希尔、基数

void bubble_sort(int *nums, int n) {
    //冒泡排序
    int flag = 0;
    for (int i = 1; i <= n - 1; i++) {
        flag = 0;
        for (int j = 0; j < n - i + 1; j++) {
           if (nums[j - 1] > nums[j]) {
                swap(nums[j], nums[j - 1])
                flag = 1;
            }
            
        }
        if (!flag) break;
    }
    return ;
}

//插入排序
void insert_sort(int *nums, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 1 && nums[j] < nums[j - 1]; j--) {
            swap(nums[j], nums[j - 1]);
        }

    }
    return ;
}

//归并排序
void merge_sort(int *nums, int l, int r) {
    if (r - l <= 1) {
        if (r - l == 1 && nums[l] > nums[r]) {
            swap(nums[l], nums[r])
        } 
        return ;
    }
    
    //分治
    int mid = (l + r + 1) / 2;
    merge_sort(nums, l, mid);
    merge_sort(nums, mid + 1, r);
    //归并
    int x = l, y = mid + 1, k = 0;
    int *tmp = (int *)malloc(sizeof(int) * (r - l + 1));
    while (x <= mid && y <= r) {
        if (nums[x] < nums[y]) {
            tmp[k++] = nums[x++];
        } else {
            tmp[k++] = nums[y++];
        }
    }
    
    while (x <= mid) tmp[k++] = nums[x++];
    while (y <= r) tmp[k++] = nums[y++];

    memcpy(nums + l, tmp, sizeof(int) * (r - l + 1));
    free(tmp);
    return ;
}

int main() {
    int num[1000];
    #define max_op 13
    srand(time(0));
    for (int i = 0; i < max_op; i++) {
        num[i] = rand() % 100; 
    }
    TEST(num, bubble_sort, max_op, nums, max_op);
    TEST(num, insert_sort, max_op, nums, max_op);
    TEST(num, merge_sort, max_op, nums, 0, max_op - 1);
    #undef max_op
    return 0; 
}
