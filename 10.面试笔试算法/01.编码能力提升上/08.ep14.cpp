/*************************************************************************
	> File Name: 08.ep14.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 08 Nov 2023 08:33:38 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int num[10000000];
int func(long long x) {
    if (x == 1) return 1;
    if (x < 10000000 && num[x]) {
        return num[x];
    }
    
    int t;
    if (x % 2 == 0) {
        t = func(x / 2) + 1;
    } else {
        t = func(3 * x + 1) + 1;
    }
    
    if (x < 10000000) {
        num[x] = t;
    }
    return t;
}

int main() {
    int ans = 1;

    for (int i = 2; i < 1000000; i++) {
        if (func(i) > func(ans)) {
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}
