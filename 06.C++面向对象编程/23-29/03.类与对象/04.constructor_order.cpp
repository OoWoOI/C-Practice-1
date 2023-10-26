/*************************************************************************
	> File Name: 04.constructor_order.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 26 Oct 2023 10:16:53 AM CST
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

class MyMap : public map<void *, string> {
public :
    void output(void *p, string s) {
        if (find(p) == end()) {
            cout << "unknown name " << p;
        } else {
            cout << operator[](p);
        }
        cout << s << endl;
        return ;
    }
} name;

class A {
public :
    A(string n) {
        name[this] = n;
        name.output(this, " class A construtor");
    }
    ~A() {
        name.output(this, " class A destructor");
    }
    int *p;
};

class B {
public :
    B(string n, A &a) : a(a) {
        name[this] = n;
        name.output(this, " class B constructor");
        a.p = new int;
    }
    A &a;
    ~B() {
        name.output(this, " class B destructor");
        delete a.p;
    }
};

class C {
public :
    C(string n) : b(n + ".b"), a(n + ".a") {
        name[this] = n;
        name.output(this, " class C constructor");
    }
    char ch;
    A a, b;
    ~C() {
        name.output(this, " class C destructor");
    }
};

class Point {
public :
    Point() : y(3), x(y + 2) {}
    void output() {
        cout << "(" << x << ", "<< y << ")" << endl;
    }
private:
    int y, x;
};

int main() {
    A a("a");
    B b("b", a);
    C c("c");
    Point p;
    p.output();
    return 0;
}

