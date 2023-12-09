/*************************************************************************
	> File Name: 06.priority_queue.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Dec 2023 08:51:58 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node{
    int x, y;
    //方法1
/*
    bool operator<(const node &b) const{
        return this->x > b.y;
    }
*/
};

//方法2,仿函数
struct cmp{
    bool operator() (const node &a, const node &b) {
        return a.x > b.x;
    }
};


int main() {
    /*
    priority_queue<int > que;
    que.push(5);
    que.push(-2);
    que.push(99);
    que.push(8);

    cout << que.top() << " " << que.size() << endl;

    while (!que.empty()) {
        cout << que.top() << endl;
        que.pop();
    }

    cout << que.size() << endl;
    */
    
    //自定义类型
    priority_queue<node, vector<node>, cmp> que;
    que.push((node){-1, 2});
    que.push((node){-3, 4});
    que.push((node){-5, 6});

    while (!que.empty()) {
        cout << que.top().x << " " << que.top().y << endl;
        que.pop();
    }

    cout << que.size() << endl;

    return 0;
}
