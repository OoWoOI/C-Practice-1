/*************************************************************************
	> File Name: 04.queue.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Dec 2023 08:11:54 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
int main() {
    queue<int> que;
    que.push(12);
    que.push(13);
    que.push(14);
    que.push(8);
    cout << que.size() << " " << que.front() << " " << que.back() << endl;

    while (!que.empty()) {
        cout << que.front() << " " << que.back() << endl;
        que.pop();
    }

    cout << que.size() << endl;
    
    return 0;
}
