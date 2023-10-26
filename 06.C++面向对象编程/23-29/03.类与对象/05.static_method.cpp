/*************************************************************************
	> File Name: 05.static_method.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 26 Oct 2023 10:17:32 AM CST
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
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
    void set_x(int x) { this->x = x; }
    void set_y(int y) { this->y = y; }
    int get_x() {
        Point::get_x_cnt += 1;
        return this->x;
    }    
    int get_y() { return this->y; }
    static int x_cnt() {
        return Point::get_x_cnt;
    }

private:
    static int get_x_cnt; // declear
    int x, y;
};

int Point::get_x_cnt = 0; // define

int main() {
    Point p1(3, 4), p2(5, 6);
    cout << p1.get_x() << ", " << p1.get_y() << endl;
    cout << p2.get_x() << ", " << p2.get_y() << endl;
    p1.get_x(), p1.get_x(), p1.get_x();
    cout << "x_cnt : " << Point::x_cnt() << endl;
    return 0;
}
