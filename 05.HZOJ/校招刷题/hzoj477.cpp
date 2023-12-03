/*************************************************************************
	> File Name: hzoj477.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 01 Dec 2023 07:35:28 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
string str;
int ans;
int main() {
    cin >> str;
    int len = 0, first = -1, last = -1;
    for (int i = 0; i < str.size(); i++) {
        switch (str[i]) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                if (first == -1) first = i;
                ans = max(ans, len);
                last = i;
                len = 1;
                break;
            default:
                if ( first != -1) len++;
                break;
        }
    }
   // cout << first << " "  << last << endl;
   // int tmp = len == 0 ? 0 : len + first; 
 //   ans = max(ans, tmp);
    cout << ans << endl;
    return 0;
}
