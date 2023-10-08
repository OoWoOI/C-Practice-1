/*************************************************************************
	> File Name: 09.STK-stack.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 03 Oct 2023 10:20:21 AM CST
 ************************************************************************/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main() {
    int n, m, k;
    stack<int> s;
    stack<int> max;
    vector<int> v;
    cin >> n;//操作次数
    for (int i = 0; i < n; i++) {
        cin >> m;
        switch (m) {
            case 0: {
                cin >> k;
                //入库
                s.push(k);
                if (max.empty() || max.top() < k) {
                    max.push(k);
                } else {
                    max.push(max.top());
                }
            } break;
            case 1: {
                //出库
                if (!s.empty()) {
                    s.pop();
                    max.pop();
                }
            }break;
            case 2: {
                //查询
                if (s.empty()) v.push_back(0);
                else v.push_back(max.top());
            } break;
        }
    }
    printf("=================\n");
    //输出
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        printf("%d\n", *it);
    }
    return 0;
}
