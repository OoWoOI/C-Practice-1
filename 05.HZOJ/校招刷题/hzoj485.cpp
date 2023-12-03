/*************************************************************************
	> File Name: hzoj485.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 03 Dec 2023 09:19:08 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int arr[105], N;

int main() {
    cin >> N;
    
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        cnt += arr[i];
    }
    
    int target  = cnt / N, ans = 0;
    
    for (int i = 0; i < N; i++) {
        if ( arr[i] == target) continue;
        ans++;
        if (arr[i] < target) {
            int s = target - arr[i];
            arr[i] += s;
            arr[i + 1] -= s;
        } else {
            int s = arr[i] - target;
            arr[i] -= s;
            arr[i + 1] += s;
        }

    }

    cout << ans << endl;
    
    return 0;
}
