/*************************************************************************
	> File Name: 06.ep08.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 08 Nov 2023 08:03:20 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    char s[1005];

    cin >> s;

    long long ans = 0, now = 1, zero_cnt = 0;

    for (int i = 0; i < 1000; i++) {
        if (i < 13) {
            now *= s[i] - '0';
        } else {
            if (s[i] == '0') {
                zero_cnt++;
            } else {
                now *= (s[i] - '0');
            }

            if (s[i - 13] == '0') {
                zero_cnt -= 1;
            } else {
                now /= (s[i - 13] - '0');
            }

        }

        if (zero_cnt == 0) ans = max(ans, now);
    }

    cout << ans << endl;
    
    return 0;
}
