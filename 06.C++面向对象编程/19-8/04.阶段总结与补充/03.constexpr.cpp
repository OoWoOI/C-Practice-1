/*************************************************************************
	> File Name: 03.constexpr.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 24 Dec 2023 07:16:45 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//意味着这个函数的返回值可以被当作编译期常量
constexpr int f(int x, int y) {
    return x + y;
}

struct A {
    constexpr A(int x, int y) : x(x), y(y) {};
    int x, y;
}; 

int main() {
    int n;
    cin >> n; 
    constexpr int b  = f(2, 10) + 12;
    cout << b << endl; 
    constexpr A a(2, 3); 
    A d(n, 2);
    return 0;
}
