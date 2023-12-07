/*************************************************************************
	> File Name: hzoj515_比例简化.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Dec 2023 07:38:07 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdlib>
using namespace std;

int A, B, A1, B1, L;
double raw, now;

int gcd(int a, int  b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    cin >> A >> B >> L;
    raw = (double) A / B;
    now = 99999999;

    for (int i = 1; i <= L; i++) {
        for (int j = 1; j <= L; j++) {
            if (gcd(i, j) == 1 && (double)i / j >= raw && (double) i / j - raw < now - raw ) {
                A1 = i;
                B1 = j;
                now = (double) i / j;
            }
        }
    }

    cout << A1 << " " << B1 << endl;
    
    return 0;
}
