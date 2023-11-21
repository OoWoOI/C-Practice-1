/*************************************************************************
	> File Name: 01.big_sum.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 08 Nov 2023 08:58:12 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
char s1[1005], s2[1005];

int n1[1005], n2[1005], ans[1005];

int main() {
    cin >> s1 >> s2;

    n1[0] = strlen(s1), n2[0] = strlen(s2);

    for (int i = 0, j = n1[0]; i < n1[0]; i++, j--) {
        n1[j] = s1[i] - '0';
    }

    for (int i = 0, j = n2[0]; i < n2[0]; i++, j--) {
        n2[j] = s2[i] - '0';
    }

    ans[0] = max(n1[0], n2[0]);

    for (int i = 1; i<= ans[0]; i++) {
        ans[i] = n1[i] + n2[i];
    }

    for (int i = 1; i <= ans[0]; i++) {
        if (ans[i] > 9)  {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;

            if (i == ans[0]) ans[0]++;
        }
    }

    for (int i = ans[0]; i > 0; i--) {
        cout << ans[i];
    }

    cout << endl;
    
    return 0;
}
