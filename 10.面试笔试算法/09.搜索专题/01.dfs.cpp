/*************************************************************************
	> File Name: 01.dfs.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 13 Dec 2023 09:18:13 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, m, sx, sy;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char mmap[105][105];

int func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        
        if (mmap[xx][yy] == 'T') {
            return 1;
        }
        if (mmap[xx][yy] == 'O') {
            mmap[xx][yy] = 'X';
            if (func(xx, yy)) return 1;
        }
            
    }
    return 0;
}

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }
    if (func(sx, sy)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j != 1) cout << " ";
            cout << mmap[i][j];
        }
        cout << endl;
    }
    return 0;
}
