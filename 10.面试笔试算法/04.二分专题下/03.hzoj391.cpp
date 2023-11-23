/*************************************************************************
	> File Name: 03.hzoj391.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Nov 2023 08:51:56 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

long long n, m, num[100005], r, l;

long long func(long long x) {
    long long now = 0, t = 0;
    for (int i = 0; i < n; i++) {
        if (now + num[i] <= x) {
            now += num[i];
        } else {
            t++;
            now = num[i];
        }
    }
    t++;
    return t;
}

long long bs() {
    while (l != r) {
        long long mid = (l + r) >> 1;
        long long s = func(mid);
        if (s <= m) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    return l;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        l = max(l, num[i]);
        r += num[i];
    }
    
    cout << bs() << endl;

    return 0;
}
