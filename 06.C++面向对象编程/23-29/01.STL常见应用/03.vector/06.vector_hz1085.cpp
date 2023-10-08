/*************************************************************************
	> File Name: 06.vector_hz1085.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 03:51:12 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v1.push_back(x);
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		v2.push_back(x);
	}
	
	if (v1 < v2) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
