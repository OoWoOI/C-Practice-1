/*************************************************************************
	> File Name: hzoj509_智力大冲浪.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Dec 2023 07:30:37 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 500

struct Node{
    int time, money;
};

int total, n, flag[MAX_N + 5];
Node arr[MAX_N + 5];

int main() {
    cin >> total >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i].time;
    }

    for (int i = 0; i < n; i++) {
        cin >> arr[i].money;
    }
    
    sort(arr, arr + n, [](const Node &a, const Node &b){
        if (a.money == b.money) return a.time < b.time;
        return a.money > b.money;
    });
    

    for (int i = 0; i < n; i++) {
        for (int j = arr[i].time; j > 0; j--) {
            if (flag[j] == 0) {
                flag[j] = 1;
                break;
            }
            if (j == 1) {
                total -= arr[i].money;
            }
        }
    }

    cout << total << endl;
    
    return 0;
}
