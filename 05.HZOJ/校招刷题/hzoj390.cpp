/*************************************************************************
	> File Name: hzoj390.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 26 Nov 2023 07:36:17 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100000
int N;
long long num[MAX_N + 5], tr, M;

int func(long long x) {
    int t = 0;
    for (int i = 0; i < N; i++) {
        t += num[i] / x;
    }
    return t;
}

int bs() {
    long long l = 1, r = tr, mid;
    while (l != r) {
        mid = (l + r + 1) >> 1;
        int s = func(mid);
        if (s < M) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    return r;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
        tr = max(tr, num[i]);
    }
    cout << bs() << endl;
    return 0;
}
