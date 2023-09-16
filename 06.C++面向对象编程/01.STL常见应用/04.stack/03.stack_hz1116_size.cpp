/*************************************************************************
	> File Name: 03.stack_hz1116_size.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 05:10:12 PM CST
 ************************************************************************/

#include<iostream>
#include<stack> 
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	stack<int> s;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s.push(x);
	}
	
	//出栈
	for (int i = 0; i < k; i++) s.pop();
	cout << s.size() << endl;
	
	return 0;
}
