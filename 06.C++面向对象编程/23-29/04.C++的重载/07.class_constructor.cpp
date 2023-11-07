/*************************************************************************
	> File Name: 07.class_constructor.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 07 Nov 2023 11:25:17 AM CST
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
    Point(int x, int y) : x(x), y(y) {}
    
    Point operator+(const Point &a) {
        Point ret(this->x + a.x, this->y + a.y);
        return ret;
    }
    Point &operator++() {
        this->x += 1, this->y += 1;
        return *this;
    }
    Point operator++(int) {
        Point ret(*this);
        ++(*this);
        return ret;
    }
    Point &operator--() {
        this->x -= 1, this->y -= 1;
        return *this;
    }
    Point operator--(int) {
        Point ret(*this);
        --(*this);
        return ret;
    }

    friend ostream &operator<<(ostream &, const Point &);

private : 
    int x, y;
};

ostream &operator<<(ostream &out, const Point &p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

int main() {
    Point a(1, 2), b(3, 4);
    cout << "a : " << a << endl;
    cout << "b : " << b << endl;
    cout << a + b << endl;
    cout << a.operator+(b) << endl;
    ++a;
    cout << "a : " << a << endl;
    b++;
    cout << "b : " << b << endl;
    cout << "b++ : " << b++ << endl;
    cout << "b : " << b << endl;
    return 0;
}

