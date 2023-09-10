/*************************************************************************
	> File Name: 02.sort_hz1129.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Sep 2023 03:19:46 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(const int &a, const int &b) {
    return a > b;
}
int main() {
    int n;
    cin >> n;
    int nums[n];
    //输入
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    //排序
    sort(nums, nums + n, cmp);
    //输出
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            cout << nums[i] << endl;
        } else {
            cout << nums[i] << " ";
        }
    }
    return 0;
}
