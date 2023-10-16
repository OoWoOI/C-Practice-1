/*************************************************************************
	> File Name: 13.运算符重载-类内部.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Oct 2023 10:34:59 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Point {
public :
    Point(){}
    Point(int __x, int __y) : x(__x), y(__y) {}
    Point(const Point &obj) : x(obj.x), y(obj.y) {
        cout << "copy constructor" << endl;
    }
    //类内部重载运算符
    Point operator-(const Point &a) {
        Point ret;
        ret.x = this->x - a.x;
        ret.y = this->y - a.y;
        return ret;
    }
    friend ostream &operator<<(ostream &, const Point &);
private :
    int x, y;
};

ostream &operator<<(ostream &out, const Point &a) {
    out << "<class Point>(" << a.x <<", " << a.y << ")";
    return out;
}

int main() {
    Point a(2, 4), b(3, 5);
    Point c = a - b;
    Point d = a - b - c;
    cout << a << endl;
    return 0;
}
