/*************************************************************************
	> File Name: 166.字符串操作1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Oct 2023 09:28:32 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int main() {
    int n;
    string str1, str2;
    cin >> str1;
    cin >> n;
    cin >> str2;
    cout << min(str1.length(), (size_t)100) << endl;
    str1.insert(n - 1, str2);
    cout << str1 << endl;
    cout << str1.length() - str1.rfind('x') << endl;
    return 0;
}
