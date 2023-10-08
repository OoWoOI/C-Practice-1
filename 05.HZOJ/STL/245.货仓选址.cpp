/*************************************************************************
	> File Name: 245.货仓选址.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Oct 2023 09:09:05 AM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 100000
int main() {
    int n;
    int a[MAX_N + 5];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int p = a[(n + 1) / 2];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - p);
    }
    cout << ans << endl;
    return 0;
}
