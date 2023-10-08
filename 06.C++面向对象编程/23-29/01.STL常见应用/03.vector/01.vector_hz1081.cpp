/*************************************************************************
	> File Name: 01.vector_hz1081.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 02:55:42 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n, k);
    for (int i = 0; i < v.size(); i++) {
        i && cout << " ";
        cout << v[i];
    }
    cout << endl;
    return 0;
}
