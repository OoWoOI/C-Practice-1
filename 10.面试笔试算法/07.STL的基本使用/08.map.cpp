/*************************************************************************
	> File Name: 08.map.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Dec 2023 09:40:44 PM CST
 ************************************************************************/

#include<iostream>
#include<map>
#include<string>
#include<utility>
using namespace std;
int main() {
    map<string, int> m;

    m.insert(make_pair("abc", 123));
    m.insert(make_pair("haha_1212", 123131));
    m["wangdadad"] = 9897988;
    cout << m.size() << endl;
    if (m.count("abc") == 1) {
        cout << "find abc, value is" << m["abc"] << endl;  
    } else {
        cout << "not find abs" << endl;
    }

    m.erase("abc");

    if (m.count("abc") == 1) {
        cout << "next find abc" << endl;
    } else {
        cout << "next not find abc" << endl;
    }

    m["sadadasdas"] = 90900;

    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    
    return 0;
}
