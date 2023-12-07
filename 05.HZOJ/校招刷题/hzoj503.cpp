/*************************************************************************
	> File Name: hzoj503.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 04 Dec 2023 07:31:16 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int leval, n, num[30005];

int main() {
    cin >> leval >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    sort(num, num + n);

    int l = 0, r = n - 1, ans = 0;

    while ( l <= r) {
        if (num[l] + num[r] <= leval) {
            l++;
            r--;
        } else {
            r--;
        }
        ans++;
    }

    
    cout << ans << endl;;
    
    return 0;
}
