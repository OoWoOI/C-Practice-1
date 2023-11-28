/*************************************************************************
	> File Name: hzoj391.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 26 Nov 2023 07:54:56 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100000
int N, M;
long long num[MAX_N + 5], sum;

int func(long long x) {
    int t = 0;
    long long tmp = 0;

    for (int i = 0; i < N; i++) {
        if (tmp + num[i] <= x) {
            tmp += num[i];
        } else {
            tmp = num[i];
            t++;
        }
    }

    return ++t;
}

int bs() {
    long long l = 0, r = sum, mid;
    while (l != r) {
        mid = (l + r) >> 1;
        int s = func(mid);
        if (s <= M) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return r;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
        sum += num[i];
    }
    
    cout << bs() << endl;
    
    return 0;
}
