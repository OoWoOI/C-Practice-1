/*************************************************************************
	> File Name: 01.string.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Dec 2023 07:44:39 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
    string str;
   // cin >> str;
    str = "abcdef";
    str[0] = 'A';
   /*
    for (int i = 0; i < str.size(); i++) {
        cout << str[i];
    }
    cout << endl;

    cout << str.size() << " " << str.length() << endl;
    cout << str.find("cd") << " " << str.find("cd", 4) << endl;
    if (str.find("cd", 4) == string::npos) {
        cout << "not find" << endl;
    }*/
    str.insert(3, "123");
    cout << str << endl;
    string t = str.substr(2);
    cout << t << endl;
    t = t.substr(2, 3);
    t = t + t;
    str.replace(2, 2, t);
    cout << str << endl;
    sort(str.begin(), str.end());
    cout << str << endl;
    reverse(str.begin(), str.end());
    cout << str << endl;

    return 0;
}
