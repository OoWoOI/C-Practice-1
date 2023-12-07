/*************************************************************************
	> File Name: hzoj514_火柴棒等式.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Dec 2023 08:15:30 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, mask[10] = {6, 2, 5, 5, 4, 5, 6 ,3, 7, 6}, cnt;
// + 2、= 2
int cnt_num(int num) {
    if (num == 0) return 6;
    int ans = 0;
    while (num) {
        ans += mask[num % 10];
        num /= 10;
    }
    return ans;
}
int main() {
    cin >> n;
    for (int i = 0; i < 1111; i++) {
        for (int j = 0; j < 1111; j++) {
            if (cnt_num(i) + cnt_num(j) + cnt_num(i + j) == n - 4) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
