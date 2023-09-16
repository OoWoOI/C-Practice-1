/*************************************************************************
	> File Name: 03.queue_hz1108_size.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 05:36:29 PM CST
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
	
	for (int i = 0; i < k; i++) q.pop();
	cout << q.size() << endl;
	
	return 0;
}
