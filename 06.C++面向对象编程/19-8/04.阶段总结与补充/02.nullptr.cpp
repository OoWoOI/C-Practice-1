/*************************************************************************
	> File Name: 02.nullptr.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 24 Dec 2023 07:05:23 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
void func(int x) {
    cout << x << endl;
    return ;
}

void func(int *x) {
    cout << x << endl;
    return ;
}

int main() {
    int n = 123;
    func(n);
    func(&n);
    //func(NULL);
    func(nullptr);
    return 0;
}
