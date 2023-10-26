/*************************************************************************
	> File Name: 07.declear_define.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 26 Oct 2023 10:18:48 AM CST
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

class Point {
public :
    Point();
    Point(int x, int y);
    void set_x(int x);
    void set_y(int y);
    int get_x() const;
    int get_y() const;
    static int x_cnt();

private:
    static int get_x_cnt; // declear
    int x, y;
};

Point::Point() : x(0), y(0) {}
Point::Point(int x, int y) : x(x), y(y) {}
void Point::set_x(int x) { this->x = x; }
void Point::set_y(int y) { this->y = y; }
int Point::get_x() const {
    Point::get_x_cnt += 1;
    return x;
}
int Point::get_y() const {
    return y;
}
int Point::x_cnt() {
    return Point::get_x_cnt;
}

int Point::get_x_cnt = 0; // define

int main() {
    Point p1(3, 4), p2(5, 6);
    cout << p1.get_x() << ", " << p1.get_y() << endl;
    cout << p2.get_x() << ", " << p2.get_y() << endl;
    p1.get_x(), p1.get_x(), p1.get_x();
    cout << "x_cnt : " << Point::x_cnt() << endl;
    return 0;
}

