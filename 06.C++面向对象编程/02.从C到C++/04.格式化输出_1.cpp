/*************************************************************************
	> File Name: 04.格式化输出_1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 24 Sep 2023 02:42:30 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int main() {
    char c = 'A';
    cout << "char = " << c << endl;
    int num = 12345;
    cout << "int = " << num << endl;
    string str = "abcdefg";
    cout << "string = " << str << endl;
    double  dnum = 1.2;
    cout << "double = " << dnum << endl;
    double d1 = 1.45e2;
    cout << "d1 = " << d1 << endl;
    double d2 = 2.3e-4;
    cout << "d2 = " << d2 << endl;
    cout << "d2 / 10 = " << d2 / 10 << endl;
    return 0;
}
