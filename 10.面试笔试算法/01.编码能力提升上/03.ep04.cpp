/*************************************************************************
	> File Name: 03.ep04.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 08 Nov 2023 07:49:11 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int func(int x) {
    int t = 0, raw = x;
    while (x) {
        t = t * 10 + x % 10;
        x /= 10;
    }
    return t == raw;
}

int main() {
    int ans = 0;
    for (int i = 100; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            if (func(i * j)) {
                ans = max(ans, i * j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
