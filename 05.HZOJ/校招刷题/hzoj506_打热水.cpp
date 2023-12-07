/*************************************************************************
	> File Name: hzoj506_打热水.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 04 Dec 2023 08:43:21 PM CST
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
#define MAX_N 30

struct Node{
    int ind, time;
};

int n;

Node total[MAX_N + 5];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> total[i].time;
        total[i].ind = i + 1;
    }

    sort(total, total + n, [](const Node &a, const Node &b){
        return a.time < b.time;
    });
    double now = 0, sum;
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            cout << " ";
        now += total[i - 1].time;
        sum += now;
        }
        cout << total[i].ind;
    }
    cout << endl;
    cout << fixed << setprecision(2) << sum / n << endl;
    
    return 0;
}
