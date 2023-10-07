/*************************************************************************
	> File Name: 1127.algorithm头文件之fill函数II.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Oct 2023 04:59:45 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int nums[3][5] = {0};
    int k;
    cin >> k;
    for (int i = 0; i < 3; i++) fill( nums[i], nums[i] + 5, k);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            j && cout << " ";
            cout << nums[i][j];
        }
        cout << endl;
    }
    return 0;
}
