/*************************************************************************
	> File Name: EP42.c
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Oct 2023 09:28:02 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<input42.h>

int triangle_num(int n) {
    return n * (n + 1) / 2;
}

bool binary_search(int (*f)(int), int l, int r, int target) {
    if (l > r) return false;
    int mid = (l + r) >> 1;
    if (f(mid) == target) return true;

    if (f(mid) < target) l = mid + 1;
    else r = mid - 1;
    return binary_search(f, l, r, target);
}

int calc(char *str) {
    int ans = 0;
    for (int i = 0; str[i]; i++) {
        ans += (str[i] - 'A') + 1;
    }
    return ans;
}

int main() {
    int n = sizeof(str) / 100, cnt = 0;
    for (int i = 0; i < n; i++) {
        int sum = calc(str[i]);//计算数值大小
        if (binary_search(triangle_num, 1, sum, sum)) cnt += 1;
    }
    printf("%d\n", cnt);
    return 0;
}
