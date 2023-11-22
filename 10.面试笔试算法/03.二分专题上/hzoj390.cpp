/*************************************************************************
	> File Name: hzoj390.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Nov 2023 09:18:36 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int n, m, num[100005], tr;

int func(int x) {
    int t = 1;
    for (int i = 0; i < n; i++) {
        t += num[i] / x;
    }
    return t;
}

int bs() {
    int l = 1, r = tr;
    while ( l != r ) {
        int mid = (l + r + 1) >> 1;
        int s = func(mid);
        if (s >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        tr = max(tr, num[i]);
    }
    
    cout << bs() << endl;
    
    return 0;
}
