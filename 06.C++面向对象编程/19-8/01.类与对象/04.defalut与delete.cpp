/*************************************************************************
	> File Name: 04.defalut与delete.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 30 Oct 2023 12:51:47 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A{
public:
    A() =default;
    A(const A &) =delete;
    ~A() {};
private:
    int num;
};


int main() {
    A a;
    A b = a;
    
    return 0;
}
