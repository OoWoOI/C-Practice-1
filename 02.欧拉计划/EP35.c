/*************************************************************************
	> File Name: EP35.c
	> Author: 
	> Mail: 
	> Created Time: Sun 01 Oct 2023 09:50:21 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>


#define max_n 1000000
#define max_m 1000000


//线性筛
int prime[max_n + 5] = {0};

void init() {
    for (int i = 2; i < max_m; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] >= max_m) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }

    }
    return ;
}

//二分查找
int binary_search(int *prime, int x) {
    int l = 1, r = prime[0], mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (prime[mid] == x) return mid;
        if (prime[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int digits(int num) {
    return floor(log10(num)) + 1;
}

int getNewNum(int num) {
    int x = num % 10;
    int y = num / 10;
    return y + x * (int)pow(10, digits(num) - 1);
}

//判断是否为圆周素数
int is_val(int num) {
    if (num < 10) return 1;
    int n = digits(num) - 1;
    while (n--) {
        num = getNewNum(num);
        int ret = binary_search(prime, num);
        if (ret == -1) return 0;
    }
    return 1;
}

int main() {
    init();
    int sum = 0;
    for (int i = 1; i <= prime[0]; i++) {
        if (!is_val(prime[i])) continue;
        printf("prime[%d] = %d\n", i, prime[i]);
        sum += 1;
    }
    printf("%d\n", sum);
    return 0;
}
