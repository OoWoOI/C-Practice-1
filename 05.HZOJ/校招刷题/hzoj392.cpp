/*************************************************************************
	> File Name: hzoj392.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 26 Nov 2023 08:48:21 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 100000
long long n, m, mmax, num[MAX_N + 5];

int func(long long x) {
    int t = 1, now = 0;
    for (int i = 1; i < n; i++) {
        if (num[i] - num[now] >= x) {
            t++;
            now = i;
        }
    }

    return t;
}

int bs() {
    long long l = 1, r = mmax, mid;
    while (l != r) {
        mid = (r + l + 1) >> 1;
        int s = func(mid);
        if (s >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    return r;
}

int main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &num[i]);
    }

    sort(num, num + n);
    mmax = num[n - 1] - num[0];
    printf("%d\n", bs());
    return 0;
}
