/*************************************************************************
	> File Name: 10.string_begin_end.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Sep 2023 09:31:15 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    cout << s << endl;
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}
