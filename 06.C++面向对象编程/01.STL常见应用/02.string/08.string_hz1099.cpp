/*************************************************************************
	> File Name: 08.string_hz1099.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Sep 2023 09:07:46 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int pos = s1.find(s2);//默认从第0位开始找
    cout << pos << endl;
    return 0;
}
