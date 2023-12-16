/*************************************************************************
	> File Name: 01.hzoj240.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 13 Dec 2023 07:52:38 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int t, num[10] = {0, 1, 3, 9, 27, 81, 243, 729}, ans[1005][1005];

void func(int x, int y, int n) {
    if (n == 1) {
        ans[x][y] = 1;
        return ;
    }
    func(x, y, n - 1);
    func(x, y + num[n] / 3 * 2, n - 1);
    func(x + num[n] / 3 * 2, y, n - 1);
    func(x + num[n] / 3, y + num[n] / 3, n - 1);
    func(x + num[n] / 3 * 2, y + num[n] / 3 * 2, n - 1);
    return ;
}

int main() {
    while (cin >> t) {
        if (t == -1) break;
        func(1, 1, t);
        for (int i = 1; i <= num[t]; i++) {
            for (int j = 1; j <= num[t]; j++) {
                if (ans[i][j] == 1) {
                    cout << "X";
                } else {
                    cout << " ";
                }
            }
            cout << endl;
        }
        cout << '-' << endl;
    }
    
    return 0;
}
