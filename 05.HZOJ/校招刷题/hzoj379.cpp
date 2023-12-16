/*************************************************************************
	> File Name: hzoj379.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Dec 2023 08:38:44 PM CST
 ************************************************************************/

#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;

int cnt, flag, X, max_num;

int main() {
    scanf("%d", &cnt);
    stack<int> s1, maxsta;
    for (int i = 0; i < cnt; i++) {
        scanf("%d",&flag);
        switch (flag) {
            case 0:
                scanf("%d", &X);
                s1.push(X);
                if (maxsta.empty()) maxsta.push(X);
                else maxsta.push(X > maxsta.top() ? X : maxsta.top());   
                break;
            case 1:
                if (!s1.empty()) {
                    s1.pop();
                    maxsta.pop();
                }
                break;
            case 2:
                printf("%d\n", maxsta.empty() ? 0 : maxsta.top());
                break;
        }
    }
    return 0;
}
