/*************************************************************************
	> File Name: 01.命名空间.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Sep 2023 12:06:15 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
int main() {
    double x;
    std::cout << "ENTER value : ";
    if (!(std::cin >> x)) {
        std::cout << "Bad value!" << std::endl;
    } else {
        std::cout << "Value = " << x << std::endl;
    }
    return 0;
}
