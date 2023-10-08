/*************************************************************************
	> File Name: 07.STL-nth_element.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 02 Oct 2023 10:21:55 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    vector<int> v;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
   // cout << "ss" << endl;
    nth_element(v.begin(), v.begin() + k - 1, v.end());
    cout << v[k - 1] << endl;
    return 0;
}
