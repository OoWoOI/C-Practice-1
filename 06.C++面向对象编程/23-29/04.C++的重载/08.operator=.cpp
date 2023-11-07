/*************************************************************************
	> File Name: 08.operator=.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 07 Nov 2023 11:25:57 AM CST
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
    A(const A &a) {
        cout << this << " copy cosntructor" << endl;
    }
    A(A &&a) {
        cout << this << " move constructor" << endl;
    }
    A &operator=(const A &a) {
        new(this) A(a);
        cout << this << " operator=" << endl;
        return *this;
    }
    A &operator=(A &&a) {
        new(this) A(move(a));
        cout << this << " right value operator=" << endl;
        return *this;
    }
};

int main() {
    A a, b = a;
    b = a;
    A c;
    c = move(a); // c.operator=(move(a));
    return 0;
}
