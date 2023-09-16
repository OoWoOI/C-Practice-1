/*************************************************************************
	> File Name: 02.vector_hz1080.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 03:09:57 PM CST
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
	
	for (int i = 0; i < n; i++) {
		i && cout << " ";
		cout << v[i];
	}
	cout << endl;
	return 0;
}
