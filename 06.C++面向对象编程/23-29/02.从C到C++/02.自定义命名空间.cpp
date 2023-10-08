/*************************************************************************
	> File Name: 02.自定义命名空间.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 24 Sep 2023 02:06:57 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

namespace myname {
    int printf(int a, int b) {
        return a + b;
    }
};

int main() {
    int a, b, sum;
    cin >> a >> b;
    sum = myname:: printf(a, b);
    cout << "a + b = " << sum <<endl;
    return 0;
}
