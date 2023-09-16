/*************************************************************************
	> File Name: 01.stack_hz1114_push_top.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 04:43:42 PM CST
 ************************************************************************/

 #include<iostream>
#include<stack>
using namespace std;
int main() {
	int n;
	cin >> n;
	stack<int> s;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s.push(x);
	}
	cout << s.top() << endl;
	return 0;
}
