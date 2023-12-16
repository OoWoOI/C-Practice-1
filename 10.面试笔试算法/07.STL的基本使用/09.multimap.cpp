/*************************************************************************
	> File Name: 09.multimap.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Dec 2023 07:39:59 PM CST
 ************************************************************************/

#include<iostream>
#include<map>
#include<string>
#include<utility>

using namespace std;
int main() {
    multimap<string, int> m;
    m.insert(make_pair("abc", 123));
    m.insert(make_pair("abc", 321));
    m.insert(make_pair("abc", 456));
    
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
