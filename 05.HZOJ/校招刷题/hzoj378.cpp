/*************************************************************************
	> File Name: hzoj378.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Dec 2023 08:20:15 PM CST
 ************************************************************************/

#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()  {
    stack<char> s;
    char str[305];
    scanf("%s", str);
    for (int i = 0; str[i]; i++) {
        switch (str[i]) {
            case '(':
            case '[':
            case '{':
                s.push(str[i]);
                break;
            case ')':
                if (s.top() == '(') s.pop();
                else s.push(str[i]);
                break;
            case '}':
                if (s.top() == '{') s.pop();
                else s.push(str[i]);
                break;
            case ']':
                if (s.top() == '[') s.pop();
                else s.push(str[i]);
                break;
            default :

                break;
        }
    }
    if (s.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
