/*************************************************************************
	> File Name: 01.queue_hz1106_push_front_back.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 05:25:16 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n;
	queue<int> q;
    cin >> n;
    for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.push(x);
	}
	
	cout << q.front() << " "<< q.back() << endl;
	
	return 0;
}
