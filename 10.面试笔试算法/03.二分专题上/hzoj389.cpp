/*************************************************************************
	> File Name: hzoj389.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Nov 2023 09:39:38 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int m, n, num[100005];

int func(int x) {
    int t = 1, last = num[0];
    for (int i = 1; i < n; i++) {
        if (num[i] - last >= x) {
            t++;
            last = num[i];
        }
    }
    return t;
}


int bs() {
    int l = 1, r = num[n - 1] - num[0];

    while (l != r) {
        int mid = (l + r + 1) >> 1;
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
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    
    sort(num, num + n);

    cout << bs() << endl;

    return 0;
}
