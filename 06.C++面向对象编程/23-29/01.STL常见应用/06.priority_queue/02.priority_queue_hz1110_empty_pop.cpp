/*************************************************************************
	> File Name: 02.priority_queue_hz1110_empty_pop.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 06:11:14 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	priority_queue<int> q;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.push(x);
		
	}
	
	//出堆
	for (int i =0 ; i < k; i++) {
		q.pop();
	}
	
	q.empty() ? cout << "empty priority queue" << endl : cout << q.top() << endl;
	
	return 0;
}
