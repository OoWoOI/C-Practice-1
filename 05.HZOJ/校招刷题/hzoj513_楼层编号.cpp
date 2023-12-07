/*************************************************************************
	> File Name: hzoj513_楼层编号.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Dec 2023 08:01:21 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int m, t;

int is_val(int num) {
    
    while (num) {
        if (num % 10 == t) return 1;
        num /= 10;
    }
    return 0;
}

int main() {
    cin >> m >> t;
    int cnt = 0, real = 0;
    while (cnt < m) {
        cnt += 1;
        if (is_val(cnt)) continue;
        real++;
    }
    cout << real << endl;
    return 0;
}
