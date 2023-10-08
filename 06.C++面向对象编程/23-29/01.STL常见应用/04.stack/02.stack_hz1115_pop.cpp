/*************************************************************************
	> File Name: 02.stack_hz1115_pop.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 04:59:39 PM CST
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
	for (int i = 0; i < k; i++) {
		s.pop();
	}
	s.empty() ?  cout << "empty stack" << endl : cout << s.top() << endl;
	return 0;
}
