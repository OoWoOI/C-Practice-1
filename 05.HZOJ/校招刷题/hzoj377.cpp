/*************************************************************************
	> File Name: hzoj377.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Dec 2023 08:00:42 PM CST
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;
int main() {
    stack<char> s;
    char str[305] = {0};
    scanf("%s", str);
    for (int i = 0; str[i]; i++) {
        if (str[i] != '(' && str[i] != ')') continue;
        //cout << str[i] << endl;
        if (str[i] == '(') s.push(str[i]);
        else {
            if (!s.empty()) {
               if (s.top() == '(' ) s.pop();
               else s.push(str[i]);
            } else {
                s.push(str[i]);
            }
        }
    }

    if (s.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
