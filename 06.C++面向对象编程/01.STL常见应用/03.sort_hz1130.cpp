/*************************************************************************
	> File Name: 03.sort_hz1130.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Sep 2023 03:31:50 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(const string &a, const string &b) {
    return a < b;
}
int main() {
    int n;
    cin >> n;
    string str[n];
    //输入
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    //排序
    sort(str, str + n, cmp);
    //输出
    for (int i = 0; i < n; i++) {
        cout << str[i] << endl;
    }
    return 0;
}
