/*************************************************************************
	> File Name: ep02.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 08 Nov 2023 07:36:15 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//int fib[4000005] = {1, 2};

int main() {
  //  int ans = 2;
    int ans = 0, a = 1, b = 2;
    while (b < 4000000) {
        if (b % 2 == 0) ans += b;
        b += a;
        a = b - a;
    }
    /**
    for (int i = 2; 1; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        if (fib[i] > 4000000) break;
        if (fib[i] % 2 == 0) ans += fib[i];
    }
    */
    cout << ans << endl;
    return 0;
}
