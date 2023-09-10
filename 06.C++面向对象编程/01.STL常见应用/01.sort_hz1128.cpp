/*************************************************************************
	> File Name: 01.sort_hz1128.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Sep 2023 02:58:33 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int n;;
    cin >> n;
    int nums[n];
    //输入
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    //排序
    sort(nums,nums + n);
    //输出
    for (int i = 0; i < n; i++) {
        if (i == n - 1) 
        cout << nums[i] << endl;
        else 
        cout << nums[i] <<" ";
    }

    return 0;
}
