/*************************************************************************
	> File Name: 01.priority_queue_hz1109_push_top.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 06:03:30 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	priority_queue<int> q;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.push(x);
		
	}
	
	cout << q.top() << endl;
	return 0;
}
