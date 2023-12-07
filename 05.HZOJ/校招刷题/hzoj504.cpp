/*************************************************************************
	> File Name: hzoj504.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 04 Dec 2023 08:09:30 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
string str;
int n;

int main() {
    cin >> str >> n;
    
    if (str.length() < n) return 0;
    while (n--) {
        int last = str.length() - 1;
        for (int i = 0; i < str.length() - 1; i++) {
            if (str[i] > str[i + 1] ) {
                last = i;
                break;
            }
        }
        str.replace(last, 1, "");
    }
    
    while (str[0] == '0') {
        str.replace(0, 1, "");
    }

    if (str.empty()) cout << 0 << endl;
    else cout << str << endl;
    return 0;
}
