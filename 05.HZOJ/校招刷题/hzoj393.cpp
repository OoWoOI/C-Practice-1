/*************************************************************************
	> File Name: hzoj393.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 26 Nov 2023 09:07:55 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100000
int n, m;
double clen[MAX_N + 5], tr;

int func(double x) {
    int t = 0;
    
    for (int i = 0; i < n; i++) {
        t += (clen[i] / x);
    }

    return t;
}

double bs() {
    double l = 0, r = tr, mid;

    while ( (r - l) > 0.00001) {
        mid = (r + l) / 2;
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
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &clen[i]);
        tr = max(tr, clen[i]);
    }

    printf("%0.2lf\n", (bs() - 0.005));
    return 0;
}
