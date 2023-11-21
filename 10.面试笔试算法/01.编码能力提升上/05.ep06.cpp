/*************************************************************************
	> File Name: 05.ep06.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 08 Nov 2023 07:58:36 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int main() {
    int psum = 0, sum = 0;

    for (int i = 1; i <= 100; i++) {
        psum += i * i;
        sum += i;
    }
    cout << sum * sum - psum << endl;
    
    return 0;
}
