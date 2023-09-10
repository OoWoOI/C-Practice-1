/*************************************************************************
	> File Name: 06.string_hz1097.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Sep 2023 08:48:03 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main() {
    string s, c;
    int k1, k2;
    cin >> s;
    cin >> k1 >> c;
    cin >> k2;
    s.insert(k1, c);
    s.erase(k2, 1);
    cout << s << endl;
    return 0;
}
