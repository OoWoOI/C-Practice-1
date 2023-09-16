/*************************************************************************
	> File Name: 02.queue_hz1107_pop.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 05:32:14 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.push(x);
	}
	
	//出队
	for(int i = 0; i < k; i++) q.pop();

	q.empty() ? cout << "empty queue" << endl : cout << q.front() << " " << q.back() << endl;
	
	return 0;
}
