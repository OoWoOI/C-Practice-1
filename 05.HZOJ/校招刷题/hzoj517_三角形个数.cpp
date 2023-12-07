/*************************************************************************
	> File Name: hzoj517_三角形个数.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Dec 2023 08:31:29 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, cnt;

int main() {
    cin >> n;
    
    //枚举最短边
    for (int i = 1; i <= n / 3; i++) {
        //枚举次短边
        for (int j = i; j <= (n - i) / 2; j++) {
            cnt += (i + j > n - i - j);
        }
    }

    cout << cnt << endl;
    
    return 0;
}
