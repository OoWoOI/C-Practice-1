/*************************************************************************
	> File Name: 07.string_hz1098.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Sep 2023 09:01:03 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int main() {
    string s1, s2;
    int k, len;
    cin >> s1;
    cin >> k >> len;
    s2 = s1.substr(k, len);
    cout << s2 << endl;
    return 0;
}
