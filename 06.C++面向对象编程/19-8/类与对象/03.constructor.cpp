/*************************************************************************
	> File Name: 03.constructor.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 09 Oct 2023 10:09:54 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct A{
    //无参
    A() {
        cout << this << " this non argment constructor" << endl;
    }
    //有参
    A(int n) {
        cout <<  this <<  " this is one argment constructor" << endl;
        this->x = n; this->y = n;
    }
    //拷贝构造
    A(const A &a) {
        cout << this << " this is copy constructor" << endl;
        this->x = a.x; this->y = a.y;
    }
    //成员函数
    void output() {
        cout << this->x << " " << this->y << endl;
    }
    int x, y;
    //析构函数
    ~A() {
        cout << this <<" this delet constructor" << endl;
    }
};

A aa;
A bb(aa);
A cc(bb);

int main() {
    cout << "=================" << endl;
    A a;
    A b(6);
    A c(b);
    b.output();
    c.output();
    return 0;
}
