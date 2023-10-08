/*************************************************************************
	> File Name: 02.this关键字.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Oct 2023 11:18:26 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A{
public:
    void get_xy(int x, int y) {
        cout << this << endl;
        this->x = x;
        this->y = y;
    }
    void echo() {
        cout << this->x << " " << this->y << endl;
    }
private:
    int x, y;
};


int main() {
    A a;
    a.echo();
    a.get_xy(2, 3);
    a.echo();
    return 0;
}
