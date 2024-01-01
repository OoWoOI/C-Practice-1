/*************************************************************************
	> File Name: 08.bind的使用方法.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 24 Dec 2023 04:16:28 PM CST
 ************************************************************************/

#include<iostream>
#include<functional>
using namespace std;

void func(int x, int y, int z) {
    cout << x + y << " is a num" << endl;
    cout << z << " is a num" << endl;
    return ;
}

struct A {
    void say() {
        cout << this << " : saying" << endl;
    }
    void run() {
        cout << "hello word!" << endl;
    }
};

void count_function_times(function<void()> &p, int &cnt) {
    p();
    cnt += 1;
    return ;
}

int main() {
    function<void(int , int)> f1 = bind(func, 123, std::placeholders::_1, std::placeholders::_2);
    f1(100, 200);
    f1(200, 300);
    A a;
    cout << &a << endl;
    //function<void()> f2 = bind(&A::say, a);
    function<void()> f2 = bind(&A::say, ref(a));
    f2();
    int cnt = 0;
    function<void()> f3 = bind(&A::run, ref(a));
    function<void()> f4 = bind(count_function_times, ref(f3), ref(cnt));
    for (int i = 0; i < 10; i++) f4();
    cout << cnt << endl;
    return 0;
}
