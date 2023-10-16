/*************************************************************************
	> File Name: 12.运算符重载.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Oct 2023 10:17:47 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Point{
public :
    Point() {}
    Point(int __x, int __y) : x(__x), y(__y){}
    Point(const Point &obj) : x(obj.x), y(obj.y){
        cout << "copy constructor" << endl;
    }
    friend Point operator+(const Point &, const Point &);
private :
    int x, y;
};

Point operator+(const Point &a, const Point &b) {
    
    Point  ret;
    ret.x = a.x + b.y;
    ret.y = a.y + b.y;
    return ret;
}

int main() {
    Point a(2, 4), b(5, 3);
    Point c = a + b;
    Point d = a + b + c;
 //   cout << c.x << " " << c.y << endl;
 //s   cout << d.x << " " << d.y << endl;

    return 0;
}
