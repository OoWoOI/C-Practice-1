/*************************************************************************
	> File Name: EP38.c
	> Author: 
	> Mail: 
	> Created Time: Tue 03 Oct 2023 07:21:34 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int digits(int x) {
    return floor(log10(x)) + 1;
}

int calc(int x) {
    long long ans = 0, n = 1;
    while (digits(ans) < 9) {
        ans *= (int)pow(10, digits(x * n));
        ans += n * x;
        n++;
    }
    if (digits(ans) != 9) return 0;
    int nums[10] = {1, 0};
    long long tmp = ans;
    while (tmp) {
        if (nums[tmp % 10]) return 0;
        nums[tmp % 10] += 1;
        tmp /= 10;
    }
    return ans;
}


int main() {
    long long ans = 0;
    for (int i = 1; i < 10000; i++) {
        int tmp = calc(i);
        if (ans < tmp) ans = tmp;
    }
    printf("%lld\n", ans);
    return 0;
}
