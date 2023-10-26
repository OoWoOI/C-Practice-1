/*************************************************************************
	> File Name: 08.default_delete.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 26 Oct 2023 10:19:38 AM CST
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
        cout << "class A : default constructor" << endl;
    }
    A(int x) {
        cout << "class A : transfer constructor" << endl;
    }
    A(const A &a) {
        cout << "class A : copy constructor" << endl;
    }
};

class B {
public :
    B() = default;
    B(const B &) = default;
private:
    A a1, a2, a3;
};

class C {
public :
    C() = default;
    C(const C &) {}
private:
    A a1, a2, a3;
};

class Point {
public :
    Point() = delete;
    Point(int x, int y) : p(new int(4)), x(x), y(y), a(3) {}
    Point(const Point &a) : x(a.x + 1), y(a.y + 2), a(a.a) {
        this->p = new int;
        *(this->p) = *(a.p);
    }
    void output() {
        cout << "this object : " << this <<  endl;
        cout << "p = " << p << ", ";
        cout << "*p = " << *p << ", ";
        cout << "x = " << x << ", ";
        cout << "y = " << y << ", ";
        cout << "a = " << &a << endl << endl;
        return ;
    }
    
    ~Point() {
        delete p;
    }
private:
    int *p;
    int x, y;
    A a;
};

int main() {
    cout << "b2 = b1 : " << endl;
    B b1, b2 = b1;
    cout << "c2 = c1 : " << endl;
    C c1, c2 = c1;
    cout << "=============" << endl;
    Point p1(3, 4), p2 = p1;
    p1.output();
    p2.output();
    return 0;
}

