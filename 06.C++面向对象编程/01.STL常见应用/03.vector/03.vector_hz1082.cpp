/*************************************************************************
	> File Name: 03.vector_hz1082.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 03:20:44 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	while (k--) v.pop_back();
	cout << (int)v.size() << endl;
	return 0;
}
