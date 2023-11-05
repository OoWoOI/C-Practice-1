/*************************************************************************
	> File Name: 265.括号画家.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 04 Nov 2023 07:44:58 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
    string str;
    cin >> str;
    stack<int> stk;

    int len = 0;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (stk.empty()) {
            stk.push(i);
            continue;
        }
        char t = str[stk.top()];
      //  cout << "c = " << c << " t = " << t << endl;
        int flag = (t == '(' && c == ')') || (t == '[' && c == ']') || (t == '{' && c == '}');
        if (flag) {
            if (!stk.empty()) stk.pop();
            int star = stk.empty() ? 0 : stk.top(); 
            len = max(len, i - star + (stk.empty()));
        } else {
            stk.push(i);
        }
    } 

    cout << len << endl;
    return 0;
}
