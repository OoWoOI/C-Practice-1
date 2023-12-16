/*************************************************************************
	> File Name: hzoj385.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Dec 2023 09:39:46 PM CST
 ************************************************************************/
#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;

struct person {
    int t, c;
};

int nation[100005];

int main() {
    int n, con = 0;
    cin >> n;
    queue<person> que;
    for (int i = 0; i < n; i++) {
        int t, num;
        scanf("%d%d", &t, &num);
        while (!que.empty()) {
            person p = que.front();//获取队首元素
            if (t - p.t < 86400) break;
            que.pop();
            nation[p.c]--;
            if (nation[p.c] == 0) con--;
        }

        for (int i = 0; i < num; i++) {
            int tmp;
            scanf("%d", &tmp);
            que.push({t, tmp});
            if (nation[tmp] == 0) con++;
            nation[tmp]++;
        }
        printf("%d\n", con);
    };

    return 0;
}
