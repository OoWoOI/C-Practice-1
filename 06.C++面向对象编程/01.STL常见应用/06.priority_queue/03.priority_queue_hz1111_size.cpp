/*************************************************************************
	> File Name: 03.priority_queue_hz1111_size.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 06:15:24 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	priority_queue<int> q;
	for (int i = 0; i  < n; i++) {
		int x;
		cin >> x;
		q.push(x);
	}
	
	//出堆
	for (int i = 0; i < k; i++) {
		q.pop();
	}
	cout << q.size() << endl;
	return 0;
}
