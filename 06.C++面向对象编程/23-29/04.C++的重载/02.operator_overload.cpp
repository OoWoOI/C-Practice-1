/*************************************************************************
	> File Name: 02.operator_overload.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 03 Nov 2023 10:14:22 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
class Point{
public:
    Point(){}
    Point(double  x, double  y):__x(x), __y(y){}
    friend ostream &operator<<(ostream &out, const Point &p);
    friend double operator*(const Point &a, const Point &b);
    friend Point operator*(Point &a, double v);
    friend Point operator+(Point &a, int offset);
private:
    double __x;
    double __y;
};

ostream &operator<<(ostream &out, const Point &p) {
    out << "(" << p.__x << "," << p.__y << ")";
    return out;
}

double operator*(const Point &a, const Point &b) {
    double ans = a.__x * b.__x + a.__y * b.__y;
    return ans;
}

Point operator*(Point &a,  double v) {
    a.__x *= v;
    a.__y *= v;
    return a;
} 

Point operator*(int v,Point &a) {
    return a * v;
}

Point operator+(Point &a, int offset) {
    a.__x += offset;
    a.__y += offset;
    return a;
}

int main() {
    Point x(1, 2), y(2, 3); 
    cout << x << endl;
    cout << x * y << endl;
    cout << x * 2.5 << endl;
    cout << 2.5 * x << endl;
    cout << x + 5 << endl;
    return 0;
}
