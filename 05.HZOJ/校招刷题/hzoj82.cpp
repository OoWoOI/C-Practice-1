/*************************************************************************
	> File Name: hzoj82.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 27 Nov 2023 07:58:13 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 1000000
long long N, M, tree[MAX_N + 5], tr;

long long func(long long x) {
    long long t = 0;
    for (int i = 0; i < N; i++) {
        if (tree[i] - x <= 0) continue;
        t += (tree[i] - x);
    }
    return t;
}

int bs() {
    long long l = 0, r = tr, mid;
    while ( l != r ) {
        mid = (l + r + 1) >> 1;
        long long s = func(mid);
        if (s >= M) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    return l;
}

int main() {
    scanf("%lld%lld", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &tree[i]);
        tr += tree[i];
    }
    printf("%d\n", bs());
    return 0;
}
