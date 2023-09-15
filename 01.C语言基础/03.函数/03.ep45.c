/*************************************************************************
	> File Name: 03.ep45.c
	> Author: 
	> Mail: 
	> Created Time: Fri 15 Sep 2023 10:21:09 PM CST
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>

//三角型数字
int64_t Triangle(int64_t n) {
    return n * (n + 1) / 2;
}

//五角形数字
int64_t Pentagonal(int64_t n) {
    return n * (3 * n - 1) / 2;
}

//六角型数字
int64_t Hexagonal(int64_t n) {
    return n * (2 * n - 1);
}

int binary_search(int64_t (*func)(int64_t), int64_t ind, int64_t ans) {
    int64_t l = 1, r = ind, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
     //   printf("%" PRId64 "\n", func(mid));
        if (func(mid) == ans) return mid;
        if (func(mid) < ans) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}


int main() {
    int64_t x = 286;
    while (1) {
        int64_t n = Triangle(x); 
        if ((-1 != binary_search(Hexagonal, x, n)) && (-1 != binary_search(Pentagonal, x, n))) {
            printf("%" PRId64 "\n", n);
            break;
        }
        x++;
    }
    return 0;
}
