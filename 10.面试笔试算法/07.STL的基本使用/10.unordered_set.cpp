/*************************************************************************
	> File Name: 10.unordered_set.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Dec 2023 07:48:47 PM CST
 ************************************************************************/

#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;
int main() {
    unordered_set<string> s;
    s.insert("abc");
    s.insert("bvc");
    s.insert("121221");
    s.insert("opera");
    cout << s.size() << endl;
    if (s.find("abc") != s.end()) {
        cout << "abc yes" << endl;
    } else {
        cout << "abc no" << endl;
    }
    s.erase("abc");
    if (s.count("abc") == 1) {
        cout << "next abc yes" << endl;
    } else {
        cout << "next abc no" << endl;
    }

    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}
