/*************************************************************************
	> File Name: 384.敲7-queue.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 05 Oct 2023 11:17:55 AM CST
 ************************************************************************/

#include<iostream>
#include<queue>

using namespace std;

int have7(int x) {
    if (x % 7 == 0) return 1;
    while (x) {
        if (x % 10 == 7) return 1;
        x /= 10;
    }
    return 0;
}

int main() {
    int N, X, T;
    cin >> N >> X >> T;
    queue<int> que;
    for (int i = X; i <= N; i++) que.push(i);
    for (int i = 1; i < X; i++) que.push(i);
    while (que.size() > 1) {
        if (have7(T)) {
            que.pop();
        } else {
            que.push(que.front());
            que.pop();
        }
        T++;
    }
    cout << que.front() << endl;
    return 0;
}
