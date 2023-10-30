/*************************************************************************
	> File Name: 916.二进制转十进制.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 26 Oct 2023 09:39:39 PM CST
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

int digites(int x) {
    return floor(log10(x));
}

int main() {
    int x;
    cin >> x;
    int tmp = 0;
    int d = digites(x);
    while (x) {
        tmp += (x % 10) * pow(2, d - digites(x));
        x /= 10;
    }
    cout << tmp << endl;
    return 0;
}
