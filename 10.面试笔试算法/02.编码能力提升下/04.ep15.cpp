/*************************************************************************
	> File Name: 04.ep15.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 08 Nov 2023 09:37:06 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

long long dp[25][25];

int main() {
    for (int i = 1; i <= 21; i++) {
        for (int j = 1; j <= 21; j++) {
            if (i == 1 && j == 1) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    cout << dp[21][21] << endl;

    long long ans = 1;

    for (int i = 40, j = 1; i > 20; i--, j++) {
        ans *= i;
        ans /= j;
    }
    
    cout << ans << endl;
    return 0;
}
