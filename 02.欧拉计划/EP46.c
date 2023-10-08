/*************************************************************************
	> File Name: EP46.c
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Oct 2023 07:17:00 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdbool.h>

#define MAX_N 10000

int prime[MAX_N + 5];
int is_prime[MAX_N + 5];

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] <= MAX_N; j++) {
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int get_num(int n) {
    return 2 * n * n;
}

bool binary_search(int (*f)(int), int l, int r, int x) {
    if (l > r) return false;
    int mid = (l + r) >> 1;
    if (f(mid) == x) return true;
    if (f(mid) < x) l = mid + 1;
    else r = mid - 1;
    return binary_search(f, l, r, x);
}

int main() {
    init();
    int ans = 0;
    for (int i = 9; i <= MAX_N; i += 2) {
        int flag = 0;
        if (!is_prime[i]) continue;
        for (int j = 1; j <= prime[0] && prime[j] < i; j++) {
            if (binary_search(get_num, 1, i - prime[j], i - prime[j])) {    
                flag = 1;
                continue;
            }
            ans = i;
        }
        if (!flag) break;
    }
    printf("%d\n", ans);
    return 0;
}
