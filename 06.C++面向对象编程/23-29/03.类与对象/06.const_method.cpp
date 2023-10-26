/*************************************************************************
	> File Name: 06.const_method.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 26 Oct 2023 10:18:05 AM CST
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
    Point() : get_x_cnt(0), x(0), y(0) {}
    Point(int x, int y) : get_x_cnt(0), x(x), y(y) {}
    void set_x(int x) { this->x = x; }
    void set_y(int y) { this->y = y; }
    int get_x() const {
        this->get_x_cnt += 1;
        return this->x;
    }    
    int get_y() const { return this->y; }
    int x_cnt() const {
        return this->get_x_cnt;
    }

private:
    mutable int get_x_cnt;
    int x, y;
};

int main() {
    const Point p1(10, 15), p2(15, 20);
    cout << p1.get_x() << ", " << p1.get_y() << endl;
    p1.get_x();
    p2.get_x();
    cout << "p1.x_cnt() = " << p1.x_cnt() << endl;
    cout << "p2.x_cnt() = " << p2.x_cnt() << endl;
    return 0;
}

