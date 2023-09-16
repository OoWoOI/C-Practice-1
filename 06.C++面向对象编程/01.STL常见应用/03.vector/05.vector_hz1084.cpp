/*************************************************************************
	> File Name: 04.vector_hz.1084.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 03:41:03 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	int x, k1, k2;
	cin >> x >> k1 >> k2;
	v.insert(v.begin() + k1, x);
	v.erase(v.begin() + k2);
	for (int i = 0; i < v.size(); i++) {
		i && cout << " ";
		cout << v[i];
	}
	cout << endl;
	return 0;
}
