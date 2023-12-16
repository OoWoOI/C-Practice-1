/*************************************************************************
	> File Name: hzoj384.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Dec 2023 09:27:13 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

int func(int x) {
    if (x % 7 == 0) return 1;
    while (x) {
        if (x % 10 == 7) return 1;
        x /= 10;
    }
    return 0;
}

int main() {
    int n, x, now;

    cin >> n >> x >> now;
    queue<int> que;
    for (int i = x; i <= n; i++) {
        que.push(i);
    }

    for (int i = 1; i < x; i++) {
        que.push(i);
    }
        
    while (que.size() != 1) {
        if (!func(now)) {
            que.push(que.front());
        }
        que.pop();
        now++;
    }
    cout << que.front() << endl;
    return 0;
}
