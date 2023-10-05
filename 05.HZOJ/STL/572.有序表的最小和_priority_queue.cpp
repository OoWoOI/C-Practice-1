/*************************************************************************
	> File Name: 572.有序表的最小和.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 04 Oct 2023 09:39:09 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
#define max 400000

int A[max + 5], B[max + 5], ans[max + 5];

int main() {
    priority_queue<int > que;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", A + i);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", B + i);
        que.push(A[0] + B[i]);
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = A[i] + B[j];
            if (sum < que.top()) {
                que.pop();
                que.push(sum);
            } else {
                break;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        ans[i] = que.top();
        que.pop();
    }
    
    for (int i = n - 1; i >= 0; i--) printf("%d\n", ans[i]);

    return 0;
}
