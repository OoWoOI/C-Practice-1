/*************************************************************************
	> File Name: 1123.algorithm头文件之reverse函数.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Oct 2023 04:29:19 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    reverse(v.begin(), v.end());
    for (auto it = v.begin(); it != v.end(); it++) {
        it != v.begin() && cout << " ";
        cout << *it;
    } 
    cout << endl;
    return 0;
}
