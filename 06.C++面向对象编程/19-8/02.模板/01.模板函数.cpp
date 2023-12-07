/*************************************************************************
	> File Name: 01.模板函数.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Dec 2023 03:31:21 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
// #include<cstdlib>
using namespace std;

template<typename T>
T add(T a, T b) {
    static int i = 0;
    cout << (++i) << endl;
    cout << "总共类型的字节数" << sizeof(a) << endl;
    return a + b;
}

int a, b;

int main() {
    cin >> a >> b;
    cout << add(a, b) << endl;
    cout << add(2.5, 2.2) << endl;
    cout << add<double>(3, 2) << endl;
    return 0;
}
