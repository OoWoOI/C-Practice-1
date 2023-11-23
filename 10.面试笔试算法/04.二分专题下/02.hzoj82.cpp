/*************************************************************************
	> File Name: 02.hzoj82.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Nov 2023 07:49:00 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int n, m, num[1000005], tr;

long long func(int x) {
    long long t = 0;
    for (int i = 0; i < n; i++) {
        if (num[i] > x) {
            t += num[i] - x;
        }
    }
    return t;
}

int bs() {
    int l = 0, r = tr;
    while (l != r) {
        int mid = ((long long)l + r + 1) / 2;
        long long s = func(mid);
        if (s >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return r;
}
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
        tr = max(tr, num[i]);
    }
    
    cout << bs() << endl;
    return 0;
}
