/*************************************************************************
	> File Name: 1133.algorithm头文件之upper_bound函数.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Oct 2023 05:18:31 PM CST
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
    vector<int> v;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    auto ans = upper_bound(v.begin(), v.end(), k);//第一个大于等于K
    cout << distance(v.begin(), ans) + 1 << endl;
    return 0;
}
