/*************************************************************************
	> File Name: 02.unstable_sort.c
	> Author: 
	> Mail: 
	> Created Time: Mon 11 Sep 2023 08:49:33 PM CST
 ************************************************************************/

//非稳定排序
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
    printf("]====>%s[%d]\n", #func, n);\
    free(nums);\
}

#define swap(a, b) {\
    __typeof(a) __tmp = a; a = b; b = __tmp;\
}

//快速排序
void quick_sort(int *nums, int l, int r) {
    if (r <= l) return ;
    int x = l, y = r, temp = nums[l];
    while (x < y) {
        while (x < y && nums[y] >= temp) y--;
        if (x < y) nums[x++] = nums[y];
        while (x < y && nums[x] < temp) x++;
        if (x < y) nums[y--] = nums[x];
    }
    nums[x] = temp;
    quick_sort(nums, l, x - 1);
    quick_sort(nums, x + 1, r);
    return ;
}

//堆排序
void heap_sort(int *nums, int n) {
    //调整成大顶堆
    int *ret = (int *)malloc(sizeof(int) * (n + 5));
    for (int i = 0; i < n; i++) ret[i + 1] = nums[i];

    for (int i = 1; i <= n; i++) {
        int ind = i;
        while (ind >> 1  && ret[ind] > ret[ind >> 1]) {
            swap(ret[ind], ret[ind >> 1]);
            ind >>= 1;
        }
    }
    


    //出堆操作 + 调整
    for (int i = n; i > 0; i--) {
        //交换首尾元素
        swap(ret[i], ret[1])
        //调整;
        int ind = 1;
        while ((ind << 1) < i) {
            int tmp = ind, l = ind << 1, r = ind << 1 | 1;
            if (ret[l] > ret[tmp])  tmp = l;
            if (r < i && ret[r] > ret[tmp]) tmp = r;
            if (tmp == ind) break;
            swap(ret[ind], ret[tmp]);
            ind = tmp;
        }
    }

    //复制
    memcpy(nums, ret + 1, sizeof(int) * n);
    free(ret);//释放内存
    return;
}

//选择排序
void select_sort(int *nums, int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            min = nums[min] > nums[j] ? j : min;
        }
        if (min != i) swap(nums[i], nums[min]);
    }

    return ;
}

//希尔排序


int main () {
    srand(time(0));
    #define max_op 13
    int num[max_op];
    for (int i = 0; i < max_op; i++) {
        num[i] = rand() % 100;
    }
    
    for (int i = 0; i < max_op; i++) {
        i && printf(" ");
        printf("%d", num[i]);
    }
    printf("\n");
    TEST(num, quick_sort, max_op, nums, 0, max_op - 1);
    TEST(num, heap_sort, max_op, nums, max_op);
    TEST(num, select_sort, max_op, nums, max_op);
    #undef max_op

    return 0;
}
