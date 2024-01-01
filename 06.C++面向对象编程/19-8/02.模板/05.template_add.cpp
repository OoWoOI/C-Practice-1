/*************************************************************************
	> File Name: 05.template_add.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 24 Dec 2023 01:52:46 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct A {
    A() = delete;
    A(int x) : num(x) {};
    double operator+(int x) {
        return this->num + x + 0.0001;
    }
    int num;
};

template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
} 

template<typename T, typename U> 
auto add(T *a, U *b) ->decltype(add(*a, *b)) {
    return add(*a, *b);
}

int main() {
    cout << add(2, 3) << endl;
    cout << add(2.3, 5.5) << endl;
    cout << add(2.3, 5) << endl;
    A a(3);
    cout << add(a, 2) << " " << sizeof(add(a, 2)) << endl;

    return 0;
}
