/*************************************************************************
	> File Name: 10.RVO.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 26 Oct 2023 10:21:05 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

class A {
public :
    A() {
        cout << this << " default constructor" << endl;
    }
    A(const A &) {
        cout << this << " copy constructor" << endl;
    }
    string s;
};

A func() {
    A temp;
    cout << "temp = " << &temp << endl;
    temp.s = "hello func";
    return temp;
}

int main() {
    A a = func();
    A b = func();
    cout << "a = " << &a << endl;
    cout << "b = " << &b << endl;
    return 0;
}
