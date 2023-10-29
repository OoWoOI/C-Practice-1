/*************************************************************************
	> File Name: 10.sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Oct 2023 07:31:16 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define swap(a, b) {\
    __typeof(a) __a = a; a = b; b = __a;\
}

#define TEST(arr, func, n, args...) {\
    int *num = (int*)malloc(sizeof(int) * n);\
    memcpy(num, arr, sizeof(int) * n);\
    printf("%s:%d===>", #func, n);\
    func(num, args);\
    output(num, n);\
    free(num);\
}


//冒泡排序
void buble_sort(int *num, int n) {
    for (int i = 0; i < n - 1; i++) {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (num[j] <= num[j + 1]) continue;
            swap(num[j], num[j + 1]);
            flag = 1;
        }
        if (!flag) break;
    }
    return ;
}


//插入排序
void insert_sort(int *num, int n) {
    for (int i  = 0; i < n; i++) {
        for (int j = i; j > 0 && num[j] <= num[j - 1]; j--) {
            swap(num[j], num[j - 1]);
        }
    }
    return ;
}

//归并排序
void merge_sort(int *num, int l, int r) {
    if (r - l <= 1) {
        if (r - l == 1 && num[l] > num[r]) {
            swap(num[l], num[r]);
        }
        return ;
    }
    
    int mid = (l + r) >> 1;
    
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);
    
    int *tmp = (int *)malloc(sizeof(int) * (r - l + 1));
    int k = 0, x = l, y = mid + 1;
    while (x <= mid || y <= r) {
        if ((y > r) || (x <= mid && num[x] < num[y])) {
            tmp[k++] = num[x++];
        } else {
            tmp[k++] = num[y++];
        }
    }
    memcpy(num + l, tmp, sizeof(int) * k);
    free(tmp);
    return ;
}

//选择排序
void select_sort(int *num, int n) {
    for (int i = 0; i  < n; i++) {
        int ind = i;
        for (int j = i; j < n; j++) {
            if (num[ind] <= num[j]) continue;
            ind = j;
        }
        swap(num[i], num[ind]);
    }
    return ;
}

//快速排序
void quick_sort(int *num, int l, int r) {
    if (l > r) return ;
    int x = l, y = r, tmp = num[l];

    while (x < y) {
        while (y > x && num[y] >= tmp) y--;
        if (y > x) num[x++] = num[y];
        while (x < y && num[x] <= tmp) x++;
        if (x < y) num[y--] = num[x];
    }
    
    num[x] = tmp;
    quick_sort(num, l, x - 1);
    quick_sort(num, x + 1, r);
    return ;
}

//单边递归快排
void quick_2_sort(int *num, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = num[(l + r) >> 1];
        do {
            while (num[x] < z) x++;
            while (num[y] > z) y--;
          
            if (x <= y) { 
                swap(num[x], num[y]);
                x++;
                y--;
            }   
        } while (x <= y);
        quick_2_sort(num, l, y);
        l = x;
    }
    return ;
}


//数组输出
void output(int *num, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        i && printf(", ");
        printf("%d", num[i]);
    }
    printf("]\n");
}


int main() {
    srand(time(0));
    #define max_n 19
    int arr[max_n];
    for (int i = 0; i < max_n; i++) {
        arr[i] = rand() % 100;
    }
    output(arr, max_n);
    TEST(arr, buble_sort, max_n, max_n);
    TEST(arr, insert_sort, max_n, max_n);
    TEST(arr, merge_sort, max_n, 0, max_n - 1);
    TEST(arr, insert_sort, max_n, max_n);
    TEST(arr, quick_sort, max_n, 0, max_n - 1);
    TEST(arr, quick_2_sort, max_n, 0, max_n - 1);
    #undef max_n
    return 0;
}
