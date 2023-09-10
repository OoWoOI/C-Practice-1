/*************************************************************************
	> File Name: 04.string_hz1095.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Sep 2023 08:31:14 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == s2) cout << 0 << endl;
    else if (s1 < s2) cout << -1 << endl;
    else cout << 1 << endl;
    return 0;
}
