/*************************************************************************
	> File Name: 04.sort_hz1131.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Sep 2023 03:42:06 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Node {
    int x, y;   
};

bool cmp(const Node &a, const Node &b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

int main() {
    //定义容器
    vector <Node> v;
    //输入
    int n;
    cin >> n;
    Node node[n];
    for (int i = 0; i < n; i++) {
        cin >> node[i].x >> node[i].y;
        v.push_back(node[i]);
    }

    //排序
    sort(v.begin(), v.end(), cmp);
    
    //输出
    for (int i = 0; i < n; i++) {
        cout << v[i].x <<" "<< v[i].y<< endl; 
    }

    return 0;
}
