/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 06 Oct 2023 07:22:43 PM CST
 ************************************************************************/

/*************************************************************************
	> File Name: EP24.cpp
	> Author:
	> Mail:
	> Created Time: 六 12/28 19:18:27 2019
 ************************************************************************/

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

#define max_n 10

int fac[max_n + 5];
int num[max_n + 5];

void init(int n) {
    fac[0] = 1;
    num[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = i * fac[i - 1];
        num[i] = 1;
    }
    return ;
}

int get_num(int k, int n, int &x) {
    int step = k / n;
    x = 0;
    for (int t = 0; t <= step; x += (t <= step)) {
        t += num[x];
    }
    k %= n;
    num[x] = 0;
    return k;
}

int main() {
    init(max_n);
    int k;
    cin >> k;
    for (int i = max_n; i > 0; i--) {
        int x;
        k = get_num(k, fac[i - 1], x);
        cout << x;
    }
    cout << endl;
    return 0;
}

