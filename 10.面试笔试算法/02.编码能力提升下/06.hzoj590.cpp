/*************************************************************************
	> File Name: 06.hzoj590.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 21 Nov 2023 08:01:19 PM CST
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int num[1005][1005], utd[1005][1005], dtu[1005][1005], ans[1005][1005], n, m, fin[1005][3];

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &num[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            utd[i][j] = max(utd[i - 1][j], utd[i - 1][j - 1]) + num[i][j];
        }
    }

    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            dtu[i][j] = max(dtu[i + 1][j], dtu[i + 1][j + 1]) + num[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            ans[i][j] = utd[i][j] + dtu[i][j] - num[i][j];
        }
    }
    
    

    for (int i = 2; i <= n; i++) {
        int m1 = 0, m2 = 0, ind = 0;
        for (int j = 1; j <= i; j++) {
            if (ans[i][j] > m1) {
                m2 = m1;
                m1 = ans[i][j];
                ind = j;
            } else if (ans[i][j] > m2) {
                m2 = ans[i][j];
            }
        }
        fin[i][0] = ind;
        fin[i][1] = m1;
        fin[i][2] = m2;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == 1 && y == 1) {
            printf("-1\n");
        } else if (fin[x][0] == y) {
            printf("%d\n", fin[x][2]);
        } else {
            printf("%d\n", fin[x][1]);
        }
    }

    return 0;
}
