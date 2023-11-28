/*************************************************************************
	> File Name: hzoj389.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 24 Nov 2023 08:49:06 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 100000

int M, N;
long long num[MAX_N + 5], tr;

int func(int x) {
    int t = 1, last = num[0];
    for (int i = 1; i < M; i++) {
        if (num[i] - last >= x) {
            t++;
            last = num[i];
        } 
    }
    return t;
}

int bs() {
    int l = 1, r = num[M - 1] - num[0], mid;
    while (l != r) {
        mid = (l + r + 1) >> 1;
        int s = func(mid);
        if (s < N) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    return r;
}

int main() {
    cin >> M >> N;    
    for (int i = 0; i < M; i++) {
        cin >> num[i];
    }
    sort(num, num + M);
    cout << bs() << endl;
    return 0;
}
