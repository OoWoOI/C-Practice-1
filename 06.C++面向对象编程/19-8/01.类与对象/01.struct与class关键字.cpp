/*************************************************************************
	> File Name: 01.struct与class关键字.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Oct 2023 11:01:51 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
struct A {
    int x, y;
    void echo() {
        cout << "hello world !, struct A" << endl;
    }
};

class B {
public:
    int x, y;
    void echo() {
        cout << "hello world !, class B" << endl;
    }
};

int main() {
    A a;
    B b;
    a.x = 1, a.y = 2;
    b.x = 3, b.y = 4;
    
    cout << a.x << " " << a.y << endl;
    cout << b.x << " " << b.y << endl;

    a.echo();
    b.echo();
    return 0;
}
