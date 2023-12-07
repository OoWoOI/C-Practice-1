/*************************************************************************
	> File Name: hzoj518_金币.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Dec 2023 08:46:16 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

long long x, money, now;

int main() {
    cin >> x;
    int day = 0;
    while (day < x) {
        now += 1;
        if (x - day >= now) {
            money += now * now;
            day += now;
        } else {
            money += now * (x - day);
            day = x;
        }
    }
    cout << money << endl;
    return 0;
}
