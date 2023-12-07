/*************************************************************************
	> File Name: hzoj508_两人过河.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 04 Dec 2023 09:17:02 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 1000

int num[MAX_N + 5], n, ans;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    sort(num, num + n);

    for (int i = n - 1; i >= 0; i -= 2) {
        
        if (i == 0) {
            ans += num[i];
        } else if (i == 1) {
            ans += num[1];
        } else if (i == 2) {
            ans += (num[2] + num[1] + num[0]);
            break;
        } else {
            ans += min(num[i] + num[0] + num[i - 1] + num[0], num[1] + num[0] + num[i] + num[1]);
        }
    }

    cout << ans << endl;
    
    
    return 0;
}
