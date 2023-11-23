/*************************************************************************
	> File Name: 04.hzoj394.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Nov 2023 09:13:42 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int l, r, n, m, num[50005];

int func(int x) {
    int t = 0, last = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (num[i] - last < x) {
            t++;
        } else {
            last = num[i];
        }
    }
    return t;
}

int bs() {
    while (l != r) {
        int mid = (l + r + 1) >> 1;
        int s = func(mid);
        if (s <= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    cin >> r >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        l = min(l, num[i] - num[i - 1]);
    }

    num[n + 1] = r;

    l = min(l, num[n + 1] - num[n]);

    cout << bs() << endl;
    
    return 0;
}
