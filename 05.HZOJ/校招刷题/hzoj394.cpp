/*************************************************************************
	> File Name: hzoj394.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 26 Nov 2023 09:35:47 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100000
long long len, N, M;
long long p[MAX_N + 5];

int func(long long x) {
    int t = 0, now = 0;
    for (int i = 1; i <= N + 1; i++) {
        if (i == N + 1 && p[i] - p[now] < x) t++;
        else {
            if (p[i] - p[now] < x) {
                t++;
            } else {
                now = i;
            }
        }
    }
    return t;
}

int bs() {
    long long l = 1, r = len, mid;
    while (l != r){
        mid = (l + r + 1) >> 1;
        int s = func(mid);
        if (s <= M) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    scanf("%lld%lld%lld", &len, &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &p[i]);
    }
    p[0] = 0;
    p[N + 1] = len;

    printf("%d\n", bs());
    return 0;
}
