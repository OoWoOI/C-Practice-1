/*************************************************************************
	> File Name: 05.static_constructor.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 10 Oct 2023 10:14:50 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Point {
public :
    Point();
    Point(int x, int y);
    int x() const;
    int y() const;
    int x_cnt() const;
    void set_x(int x);
    void set_y(int y);
    static int output_cnt();
    ~Point();
private :
    static int Point_cnt;
    int __x, __y;
    mutable int __x_cnt;
};

//构造方法
Point::Point() : __x_cnt(0) {
    Point_cnt += 1;
}

Point::Point(int x, int y) :__x(x) , __y(y),__x_cnt(0) {
    Point_cnt += 1;
    this->__x = x; this->__y = y;
}

//析构方法
Point::~Point() {
    Point::Point_cnt -= 1;
}


//类属性初始化
int Point::Point_cnt = 0;

//类方法定义
int Point::output_cnt() {
    return Point::Point_cnt;
}

//成员方法
int Point::x() const {
    this->__x_cnt += 1;
    return this->__x;
}

int Point::y() const {
    return this->__y;
}

int Point::x_cnt() const {
    return this->__x_cnt;
}

void Point::set_x(int x) {
     this->__x = x;
}

void Point::set_y(int y) {
     this->__y = y;
}

void func() {
    Point a, b;
    cout << Point::output_cnt() << " func in" << endl;
    return ;
}

int main() {
    Point a(2, 3), b;
    const Point c(3, 4);
    cout << a.x() << " " <<a.y() << endl;
    cout << "__x被访问的次数" << a.x_cnt() << " " << b.x_cnt() << endl;
    cout << Point::output_cnt() << " func before" << endl;
    func();
    cout << Point::output_cnt() << " func after" << endl;
    return 0;
}
