/*************************************************************************
	> File Name: 08.vector_hz1087.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 04:18:11 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<vector<int> > v(n, vector<int>());
	//输入
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			v[i].push_back(x);
		}
	}
	
	//输出
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			j && cout << " ";
			cout << v[i][j];
		}
		cout << endl;
	}
	
	return 0;
}
