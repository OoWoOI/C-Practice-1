/*************************************************************************
	> File Name: hzoj388.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Nov 2023 07:48:46 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


long long n, m, ans;
long long M[100005], N[100005];

int binary_search(long long *arr, int size , long long val) {
    int left = 0, right = size - 1, mid;
    
    while (left <= right) {
        mid = (left + right) >> 1;
        if (arr[mid] == val) return mid;
        if (arr[mid] < val) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> M[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> N[i];
    }

    int flag = 0;
    sort(N, N + m);

    for (int i = 0; i < n; i++) {
        if (binary_search(N, m, M[i]) == -1) continue;
        ans += M[i];
        if (flag) cout << " ";
        cout << M[i];
        flag = 1;
    }

    cout << endl;
    
    cout << ans << endl;
    
    
    
    return 0;
}
