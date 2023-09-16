/*************************************************************************
	> File Name: 04.priority_queue_hz1112_size.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 06:21:02 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	priority_queue<int , vector<int>, greater<int> > q;
	
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.push(x);
	}
	
	cout << q.top() << endl;
	
	return 0;
}
