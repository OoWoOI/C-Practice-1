/*************************************************************************
	> File Name: 05.ep18.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 21 Nov 2023 07:42:47 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int dp[20][20], num[20][20], ans;

int main() {
    //最大路径和: dp[x][y] = max(dp[x - 1][y], dp[x - 1][y - 1]) + dp[x][y];
    
    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> num[i][j];
        }
    }
    /**
    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + num[i][j];
            ans = max(ans, dp[i][j]);
        }
    }**/
    
    for (int i = 15; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + num[i][j];
        }
    }

    cout << dp[1][1] << endl;
    


    return 0;
}
