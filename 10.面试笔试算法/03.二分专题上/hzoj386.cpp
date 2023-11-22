/*************************************************************************
	> File Name: hzoj386.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Nov 2023 08:25:40 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
    int num, ind;
};


node wm[100005];
int n, m;

int main() {
    scanf("%d%d", &n, &m);

    for (int i= 1; i <= n; i++) {
        scanf("%d", &wm[i].num);
        wm[i].ind = i;
    }

    sort(wm + 1, wm + n + 1, [](const node &a, const node &b){
        return a.num < b.num;
    });
    
    for (int i = 0; i < m; i++) {
        int t, l = 1, r = n, mid;
        scanf("%d", &t);
        while (l <= r) {
            mid = (l + r) >> 1;
            if (wm[mid].num == t) {
                printf("%d\n", wm[mid].ind);
                break;
            }

            if (wm[mid].num < t) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        if (l > r) printf("0\n");

    }

    return 0;
}
