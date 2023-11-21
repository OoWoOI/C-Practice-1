/*************************************************************************
	> File Name: 04.ep36.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 08 Nov 2023 07:53:46 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int func(int x, int base) {
    int t = 0, raw = x;
    while (x) {

        t = t * base + x % base;
        x /= base;
    }
    return t == raw;
}

int main() {
    int ans = 0;
    for (int i = 1; i <= 1000000; i++) {
        if (func(i, 10) && func(i, 2)) {
            ans += i;
        }

    }
    cout << ans << endl;
    return 0;
}
