/*************************************************************************
	> File Name: hzoj505_最大整数.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 04 Dec 2023 08:28:54 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define MAX_N 100000
string str[MAX_N + 5];
string ans;
int n;
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    
    sort(str, str + n, [](const string &a, const string &b){
        return a + b > b + a;
    });
    
    for (int i = 0; i < n; i++) ans += str[i];

    cout << ans << endl;

    return 0;
}
