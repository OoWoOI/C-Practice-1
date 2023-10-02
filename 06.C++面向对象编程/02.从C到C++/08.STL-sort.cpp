/*************************************************************************
	> File Name: 08.STL-sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 02 Oct 2023 10:55:03 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int sum = 0;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        sum += abs((*it) - v[v.size() /2]);
    }
    cout << sum << endl;
    return 0;
}
