/*************************************************************************
	> File Name: 05.格式输出_2.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 24 Sep 2023 02:52:42 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int main() {
    int x = 255;
    cout << x << "(十进制)" << endl;
    cout << hex << x << "(十六进制)" << endl;
    cout << oct << x << "(八进制)" << endl;
    cout << dec << x << "(十进制)" << endl;
    return 0;
}
