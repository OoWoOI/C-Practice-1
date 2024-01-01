/*************************************************************************
	> File Name: 06.模板的引用折叠.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 24 Dec 2023 02:23:16 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
template<typename T>
void my_swap(T &&a, T &&b) {
    typename remove_reference<T>::type c;
    c = a;
    a = b;
    b = c;
    return ; 
}

template<typename T>
void add(T &&a, T &&b) {
    a += 3;
    b += 4;
    return ;
}

void func(void (*p)(int &, int &), int &a, int &b) {
    p(a, b);
    return ;
}

int main() {
    int a = 12, b = 13; 
    cout << a << " " << b << endl;
    func(add, a, b);
    cout << a << " " << b << endl;
    my_swap(a, b);
    cout << a << " " << b << endl;
    return 0;
}
