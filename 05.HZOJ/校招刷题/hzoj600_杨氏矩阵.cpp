/*************************************************************************
	> File Name: hzoj600_杨氏矩阵.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 12 Dec 2023 08:31:30 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int n, m, t, num[3005][3005];
int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &num[i][j]);
        }
    }

    scanf("%d", &t);
    int x = n, y = 1;
    while (x > 0 && y <= m) {
        if (num[x][y] == t){
            printf("%d %d\n", x, y);
            return 0;
        }

        if (num[x][y] < t) {
            y++;
        } else {
            x--;
        }
    }
    
    return 0;
}
