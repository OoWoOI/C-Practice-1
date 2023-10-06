/*************************************************************************
	> File Name: EP24.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 06 Oct 2023 09:22:52 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 10

int dnum[max_n];
int jump[max_n];

void init(int n) {
    dnum[0] = 1, jump[0] = 1;
    for (int i = 1; i <= n; i++) {
        dnum[i] = 1;
        jump[i] = i * jump[i - 1];
    }
    return ;
}

int get_num(int k, int n, int &x) {
    int step = k / n;
    x = 0;
    for ( int t = 0; t <= step; x += (t <= step) ) {
        t += dnum[x];
    }
    k %= n;
    dnum[x] = 0;
    return k;
}

int main() {
    init(max_n);
    int k;
    cin >> k;
    k -= 1;
    for (int i = max_n; i > 0; i--) {
        int x;
        k = get_num(k, jump[i - 1], x);
        cout << x;
    }
    cout << endl;
    return 0;
}
