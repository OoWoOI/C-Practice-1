/*************************************************************************
	> File Name: 01.hzoj393.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Nov 2023 07:33:02 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int n, m;
double num[100005], tr;

int func(double x) {
    int t = 0;
    for (int i = 0; i < n; i++) {
        t += num[i] / x;
    }
    return t;
}

double bs() {
    double l = 0, r = tr;
    while ((r - l) > 0.0001) {
        double mid = (l + r) / 2;
        int s = func(mid);
        if (s >= m) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        tr = max(tr, num[i]);
    }

    double t = bs();
    //cout << t << endl;//第一种思路
  //  printf("%.2f\n", (int)(t * 100) / 100.0);
    printf("%.2f\n", (t - 0.005));
    return 0;
}
