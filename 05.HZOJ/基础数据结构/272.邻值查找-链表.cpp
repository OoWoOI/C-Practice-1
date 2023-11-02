/*************************************************************************
	> File Name: 272.邻值查找-链表.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Oct 2023 10:19:10 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<utility>

using namespace std;

const int N = 1e5 + 10;
pair<int, int> a[N], ans[N];
int l[N], r[N], pos[N];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }

    a[0].first = 1e9, a[n + 1].first = -1e9;
    
    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i++) {
        l[i] = i - 1;
        r[i] = i + 1;
        pos[a[i].second] = i;
    }

    for (int i = n; i >= 2; i--) {
        int p = pos[i];
        int left = l[p], right = r[p];
        int lv = abs(a[p].first - a[left].first);
        int rv = abs(a[p].first - a[right].first);
        if (lv <= rv) {
            ans[i] = {lv, a[left].second};    
        } else {
            ans[i] = {rv, a[right].second};
        }
        r[left] = right;
        l[right] = left;
    }

    for (int i = 2; i <= n; i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }

    return 0;
}
