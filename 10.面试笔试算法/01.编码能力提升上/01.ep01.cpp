/*************************************************************************
	> File Name: 01.ep01.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 08 Nov 2023 07:29:40 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int main() {
    int ans = 0;
    for (int i = 0; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) ans += i;
    }
    cout << ans << endl;
    int t3 = (3 + 999) * 333 / 2;
    int t5 = (5 + 995) * 199 / 2;
    int t15 = (15 + 990) * 66 / 2;
    cout << t3 + t5 - t15 << endl;
    
    return 0;
}
