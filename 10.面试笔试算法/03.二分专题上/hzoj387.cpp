/*************************************************************************
	> File Name: hzoj387.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Nov 2023 08:48:10 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
using namespace std;

struct node{
    int num, ind;
};

node wm[100005];

int n, m;

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &wm[i].num);
        wm[i].ind = i;
    }
    wm[0].num = INT_MAX;
    wm[0].ind = 0;
    sort(wm, wm + n + 1, [](const node &a, const node &b){
        return a.num < b.num;
    });
    
    for (int i = 0; i < m; i++) {
        int t, l = 0, r = n;
        scanf("%d", &t);
        while (l != r) {
            int mid = (r + l) >> 1;
            if (wm[mid].num >= t) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        printf("%d\n", wm[l].ind);
    }


    return 0;
}
