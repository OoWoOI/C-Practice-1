/*************************************************************************
	> File Name: 1125.algorithm头文件之next_permutation函数.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Oct 2023 04:42:55 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) v.push_back(i + 1);
    
    do {
        for (int i = 0; i < v.size(); i++) {
            i && cout << " ";
            cout << v[i];
        }
        cout << endl;
    } while(next_permutation(v.begin(), v.end()));
    
    return 0;
}
