/*************************************************************************
	> File Name: EP18-动态规划.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 05 Oct 2023 07:31:45 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define max_n 20

int nums[max_n + 5][max_n + 5] = {0};

int main() {
    
    for (int i = 0; i < max_n; i++) {
        for (int j = 0; j <= i; j++) cin >> nums[i][j];
    }
    
    for (int i = max_n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            nums[i][j] += max(nums[i + 1][j],nums[i + 1][j + 1]);
        }
    }
    
    cout << nums[0][0] << endl;
    return 0;
}
