/*************************************************************************
	> File Name: 272.邻值查找.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Oct 2023 09:50:56 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


int main() {
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        arr.push_back(num);
        int patt = num;
        int pos = 0;
        int ans = INT32_MAX;
        for (int j = 0; j < i; j++) {
            int tmp = abs(patt - arr[j]);
            if (ans < tmp) continue;
            if (ans == tmp) {
                pos = arr[j] > arr[pos] ? pos : j;
                continue;
            }
            ans = tmp;
            pos = j;
        }
       if (i != 0) printf("%d %d\n", ans, pos + 1);
    }
    
    return 0;
}
