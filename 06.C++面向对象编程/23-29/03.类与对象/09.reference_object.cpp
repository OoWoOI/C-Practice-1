/*************************************************************************
	> File Name: 09.reference_object.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 26 Oct 2023 10:20:38 AM CST
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
    A() = default;
    A(const A &) = default;
private:
};

class B {
public :
    B(A &a) : a(a) {}
private:
    A &a;
};

class C {
public :
    C() = default;
    C(const C &) = default;
    static void destroy(C *c) {
        delete c;
        return ;
    }

private:
    ~C() {}
};

int main() {
    A a;
    B b(a);
    C *c = new C();
    C::destroy(c);
    return 0;
}
