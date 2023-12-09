/*************************************************************************
	> File Name: 05.deque.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Dec 2023 08:31:08 PM CST
 ************************************************************************/

#include<iostream>
#include<deque>
using namespace std;
int main() {
    deque<int> que;
    que.push_back(5);
    que.push_back(7);
    que.push_back(99);
    que.push_back(-2);
    que.push_back(8);
    for (int i = 0; i < que.size(); i++) {
        cout << que[i] << " ";
    }
    cout << endl;

    cout << que.size() << " " << que.front() << " " << que.back() << endl;

    int t = 0;
    while (!que.empty()) {
        cout << que.front() << " " << que.back() << endl;
        if (t % 2) {
            que.pop_back();
        } else {
            que.pop_front();
        }
        t++;
    }
    
    cout << que.size() << endl;
    return 0;
}
